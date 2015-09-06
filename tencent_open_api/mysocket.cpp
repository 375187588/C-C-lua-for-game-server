
#include "mysocket.h"
#include "global.h"
#include "sha1.h"
#include "../system/cJSON.h"

LY::CMySocket::CMySocket(): m_socket(m_io_service), m_port(80)
{

}

LY::CMySocket::~CMySocket()
{
	close();
}

void LY::CMySocket::set_host( const string& host )
{
	m_host = host;
}

void LY::CMySocket::set_port( int port )
{
	m_port = port;
}

std::string LY::CMySocket::get_host()
{
	return m_host;
}

int LY::CMySocket::get_port()
{
	return m_port;
}

bool LY::CMySocket::connect()
{
	if (m_port == 0 || m_host == "")
	{
		return false;
	}

 
	ip::tcp::resolver resolver(m_io_service);
	char s_port[16];
	itoa(m_port, s_port, 10);
	ip::tcp::resolver::query query( m_host, s_port);
	ip::tcp::resolver::iterator iter_begin = resolver.resolve(query);
	ip::tcp::resolver::iterator iter_end; // End marker.
	while (iter_begin != iter_end)
	{
		ip::tcp::endpoint endpoint = *iter_begin++;
		boost::system::error_code err;
		m_socket.close();
		m_socket.connect(endpoint, err); 
		if (!err)
		{
			return true;
		}
	}
	return false;
 
 
}

int LY::CMySocket::send( const string& data , bool is_async)
{
	size_t ret;
	if (!is_async)
	{
		ret = m_socket.send( boost::asio::buffer(data) );
	}
	else
	{
		ret = 0;
		m_socket.async_send(boost::asio::buffer(data), 
			boost::bind(&LY::CMySocket::write_handler, this, 
			boost::asio::placeholders::error,boost::asio::placeholders::bytes_transferred));
	}

	return ret;
}

int LY::CMySocket::recv( string &data)
{
	size_t ret;
	if(data.length() == 0)
	{
		data.resize(4096);
	}

	boost::system::error_code err;
	ret = m_socket.receive(boost::asio::buffer((char*)data.c_str(), data.length()),0,err);
	if (ret > 0)
		data.resize(ret);
	else
		data.resize(0);

	return ret;
}

void LY::CMySocket::close()
{
	m_socket.close();
}

bool LY::CMySocket::is_ip_address( const string& host )
{
	int n = 0;
	for (int i = 0; i < host.length(); i++)
	{
		if ((host[i]== '.')||( '0' <= host[i] || host[i] <= '9' ))
		{
			n++;
		}
	}
	return n == host.length();
}

void LY::CMySocket::write_handler( const boost::system::error_code& error, /* Result of operation. */ std::size_t bytes_transferred /* Number of bytes sent. */ )
{

}

void LY::CMySocket::read_handler( const boost::system::error_code& error, /* Result of operation. */ std::size_t bytes_transferred /* Number of bytes received. */ )
{

}

LY::CHttpClient::CHttpClient( const string& host, int port /*= 80*/ )
{
	set_host(host);	
	set_port(port);
}

LY::CHttpClient::~CHttpClient()
{

}

bool LY::CHttpClient::get_request_for_small_data( const string &uri, const string &request_parameter, 
	const key_value_pair_map &other_head, int& status_code, string& response_head, string& response_data )
{
	m_mysocket.close();
	if(!m_mysocket.connect())
		return false;  

	string request;
	//����httpͷ
	/*
	GET /v3/user/get_info HTTP/1.1\r\n
	Host: 119.147.19.43\r\n
	Accept: * /*\r\n
	Connection: keep-alive\r\n
	Connection: close\r\n
	*/

	string parameter;
	parameter = request_parameter;
	if (request_parameter.length() > 0)
	{
		parameter = '?' + parameter;	//�в������������Ҫ��uri�Ͳ������һ��?��
	}

	request = "GET " + uri + parameter + " HTTP/1.1" + CRLF +
						"Host: " + m_mysocket.get_host() + CRLF +
						"Accept: " + "*/*" + CRLF + 
						"Connection: close" + CRLF;
	
	for (key_value_pair_map::const_iterator it = other_head.begin(); it != other_head.end(); it++)
	{
		if (other_head.find("Host") != other_head.end() ||
			other_head.find("Accept") != other_head.end() ||
			other_head.find("Connection") != other_head.end()
			)
			continue;

		request = request + it->first + ": " + it->second + CRLF;
	}
	request = request + CRLF;
	int actual_write = m_mysocket.send(request);
	if (actual_write <= 0)
	{
		return false;
	}
	//���շ���------------------
	string all_data;
	while(true)
	{
		string recv_data;
		int actual_read = m_mysocket.recv(recv_data);
		if (actual_read <= 0)
		{
			return false;
		}
		all_data = all_data + recv_data;
		response_head = g_read_string_until(all_data,0,"\r\n\r\n");
		if (response_head=="")	//û���ҵ�\r\n\r\n���������ȡ����
		{
			
		}
		else	//�ҵ����˳�
			break;
	}
	/*
	HTTP/1.1 200 OK\r\n
	Content-Length: 147\r\n	
	*/


	string::size_type n = response_head.find(0x20);
	if ( n != string::npos)
	{
		string s_status_code = response_head.substr(n+1,3);
		if(!g_is_number(s_status_code))
			return false;
		status_code = atoi(s_status_code.c_str());		
	}
	else
		return false;
	

	n = response_head.find("Content-Length: ");
	if (n != string::npos)
	{
		int len = strlen("Content-Length: ");
		string content_size_str = g_read_string_until (response_head, n + len, "\r\n");
		if (content_size_str == "")
			return false;
		content_size_str.resize(content_size_str.length()-2);
		if (!g_is_number (content_size_str))
			return false;
		INT64 content_size;
		content_size = _atoi64(content_size_str.c_str ());

		string all_content = all_data.substr( response_head.length());
		string content;
		while( m_mysocket.recv (content) > 0)
		{
			all_content = all_content + content;
		}
		if (all_content.length () != content_size)
		{
			return false;
		}
		response_data = all_content;
		return true;

	}
	else	//��û�����ݳ���
	{
		string all_content = all_data.substr( response_head.length());
		string content;
		while( m_mysocket.recv (content) > 0)
		{
			all_content = all_content + content;
		}
		response_data = all_content;
		return true;
	}

}

bool LY::CHttpClient::get_request_for_non_blocking( const string &uri, const string &request_parameter, 
												   const key_value_pair_map &other_head )
{
	m_mysocket.close();
	if(!m_mysocket.connect())
		return false;

	string request;
	//����httpͷ
	/*
	GET /v3/user/get_info HTTP/1.1\r\n
	Host: 119.147.19.43\r\n
	Accept: * /*\r\n
	Connection: keep-alive\r\n
	Connection: close\r\n
	*/

	string parameter;
	parameter = request_parameter;
	if (request_parameter.length() > 0)
	{
		parameter = '?' + parameter;	//�в������������Ҫ��uri�Ͳ������һ��?��
	}

	request = "GET " + uri + parameter + " HTTP/1.1" + CRLF +
						"Host: " + m_mysocket.get_host() + CRLF +
						"Accept: " + "*/*" + CRLF + 
						"Connection: close" + CRLF;
	
	for (key_value_pair_map::const_iterator it = other_head.begin(); it != other_head.end(); it++)
	{
		if (other_head.find("Host") != other_head.end() ||
			other_head.find("Accept") != other_head.end() ||
			other_head.find("Connection") != other_head.end()
			)
			continue;

		request = request + it->first + ": " + it->second + CRLF;
	}
	request = request + CRLF;
	m_mysocket.send(request, true);
	
	return true;
}

bool LY::CHttpClient::post_request( const string &uri, const string &request_data, 
								   const key_value_pair_map &other_head, int& status_code, 
								   string& response_head, string& response_data )
{
	m_mysocket.close();
	if(!m_mysocket.connect())
		return false;


	//����HTTP POSTͷ
	/*
	POST /v3/spread/set_reminder HTTP/1.1 
	Host: 113.108.20.23 
	Content-Type: application/x-www-form-urlencoded 
	Content-Length: 352
	Connection: Keep-Alive
	Cache-Control: no-cache
	*/
	string http_head;
	http_head = http_head + 
				"POST " + uri + " HTTP/1.1" + CRLF +
				"Host: " + get_host() + CRLF +
				"Content-Type: application/x-www-form-urlencoded" + CRLF +
				"Content-Length: " + g_int_to_str((int)request_data.length()) + CRLF
				"Connection: close" + CRLF +
				"Cache-Control: no-cache" + CRLF;

	for (key_value_pair_map::const_iterator it = other_head.begin(); it != other_head.end(); it++)
	{
		if (other_head.find("Host") != other_head.end() ||
			other_head.find("Content-Type") != other_head.end() ||
			other_head.find("Cache-Control") != other_head.end() ||
			other_head.find("Content-Length") != other_head.end()
			)
		{
			continue;
		}
		http_head = http_head + it->first + ": " + it->second + CRLF;
	}
	http_head = http_head + CRLF;

	//http���������
	string http_request_data;
	http_request_data = http_head + request_data;

	int actual_write = m_mysocket.send(http_request_data);
	if (actual_write <= 0)
	{
		return false;
	}
	//���շ���------------------
	string all_data;
	while(true)
	{
		string recv_data;
		int actual_read = m_mysocket.recv(recv_data);
		if (actual_read <= 0)
		{
			return false;
		}
		all_data = all_data + recv_data;
		response_head = g_read_string_until(all_data,0,"\r\n\r\n");
		if (response_head=="")	//û���ҵ�\r\n\r\n���������ȡ����
		{
			
		}
		else	//�ҵ����˳�
			break;
	}
	/*
	HTTP/1.1 200 OK\r\n
	Content-Length: 147\r\n	
	*/

	string::size_type n = response_head.find(0x20);
	if ( n != string::npos)
	{
		string s_status_code = response_head.substr(n+1,3);
		if(!g_is_number(s_status_code))
			return false;
		status_code = atoi(s_status_code.c_str());		
	}
	else
		return false;
	

	n = response_head.find("Content-Length: ");
	if (n != string::npos)
	{
		int len = strlen("Content-Length: ");
		string content_size_str = g_read_string_until (response_head, n + len, "\r\n");
		if (content_size_str == "")
			return false;
		content_size_str.resize(content_size_str.length()-2);
		if (!g_is_number (content_size_str))
			return false;
		INT64 content_size;
		content_size = _atoi64(content_size_str.c_str ());

		string all_content = all_data.substr( response_head.length());
		string content;
		while( m_mysocket.recv (content) > 0)
		{
			all_content = all_content + content;
		}
		if (all_content.length () != content_size)
		{
			return false;
		}
		response_data = all_content;
		return true;

	}
	else	//��û�����ݳ���
	{
		string all_content = all_data.substr( response_head.length());
		string content;
		while( m_mysocket.recv (content) > 0)
		{
			all_content = all_content + content;
		}
		response_data = all_content;
		return true;
	}

	
	return false;
}

bool LY::CHttpClient::post_request_for_non_blocking( const string &uri, const string &request_data, 
											 const key_value_pair_map &other_head )
{
	m_mysocket.close();
	if(!m_mysocket.connect())
		return false;


	//����HTTP POSTͷ
	/*
	POST /v3/spread/set_reminder HTTP/1.1 
	Host: 113.108.20.23 
	Content-Type: application/x-www-form-urlencoded 
	Content-Length: 352
	Connection: Keep-Alive
	Cache-Control: no-cache
	*/
	string http_head;
	http_head = http_head + 
				"POST " + uri + " HTTP/1.1" + CRLF +
				"Host: " + get_host() + CRLF +
				"Content-Type: application/x-www-form-urlencoded" + CRLF +
				"Content-Length: " + g_int_to_str((int)request_data.length()) + CRLF
				"Connection: close" + CRLF +
				"Cache-Control: no-cache" + CRLF;

	for (key_value_pair_map::const_iterator it = other_head.begin(); it != other_head.end(); it++)
	{
		if (other_head.find("Host") != other_head.end() ||
			other_head.find("Content-Type") != other_head.end() ||
			other_head.find("Cache-Control") != other_head.end() ||
			other_head.find("Content-Length") != other_head.end()
			)
		{
			continue;
		}
		http_head = http_head + it->first + ": " + it->second + CRLF;
	}
	http_head = http_head + CRLF;

	//http���������
	string http_request_data;
	http_request_data = http_head + request_data;

	m_mysocket.send(http_request_data, true);
	
	return true;
}

void LY::CHttpClient::set_host( const string& host )
{
	m_mysocket.set_host (host);
}

void LY::CHttpClient::set_port( int port )
{
	m_mysocket.set_port (port);
}

std::string LY::CHttpClient::get_host()
{
	return m_mysocket.get_host ();
}

int LY::CHttpClient::get_port()
{
	return m_mysocket.get_port ();
}

void LY::CTencentOpenAPI::set_host( const string& host )
{
	m_host = host;
}

void LY::CTencentOpenAPI::set_port( int port )
{
	m_port = port;
}

std::string LY::CTencentOpenAPI::sign( const string& appkey, const string& request_way, 
	const string& uri, const map<string,string>& paramter_pair)
{
	string signture;

	//�ѱ����uri
	string encoded_uri = urlencode (uri);
	
	//�ѱ���Ĳ���
	string encoded_parameter;
	
	/*
	 * ������sig��������в�����key�����ֵ��������С� 
	 * ע������OpenAPI�ĵ����ر��ע��ĳ����������ǩ���������sig������в�����Ҫ����ǩ����
	**/
	string paramter;
	for (map<string,string>::const_iterator it = paramter_pair.begin ();
		it != paramter_pair.end(); it++)
	{
		//sig������ǩ��
		if(it->first == "sig")	
			continue;
		paramter = paramter + it->first + '=' + g_ascii_to_utf8(it->second) + '&';
	}
	//ȥ�����һ���ַ�
	paramter.resize(paramter.length()-1);

	encoded_parameter = urlencode (paramter);

	string upper_request_way = request_way;
	g_to_upper(upper_request_way);

	string src_data = upper_request_way + '&' + encoded_uri + '&' + encoded_parameter;
	
	//�õ���Կ
	string secret_key = appkey + '&';

	string secret_data(20,0);
	
	hmac_sha1((char*)secret_key.c_str(), secret_key.length(), (char*)src_data.c_str(), src_data.length(), (char*)secret_data.c_str());
	
	//Base64����
	g_base64_encode(secret_data, signture);

	return signture;
}

std::string LY::CTencentOpenAPI::urlencode( const string& data )
{
	string ret_data;
	/*
	ǩ����֤ʱ��Ҫ����ַ����г��ˡ�-������_������.��֮������з���ĸ�����ַ����滻�ɰٷֺ�(%)�����λʮ����������
	ʮ������������ĸ����Ϊ��д��
	*/
	for (int i = 0; i < data.length (); i++)
	{
		//����ת�����ַ�
		if(('0' <= data[i] && data[i] <= '9')|| ('a' <= data[i] && data[i] <= 'z') || 
			('A' <= data[i] && data[i] <= 'Z') || data[i]== '-' || data[i]== '_' || data[i]== '.')
		{
			ret_data = ret_data + data[i];
		}
		else	//��Ҫת�����ַ�
		{
			char hex_data[8];
			sprintf_s(hex_data, sizeof(hex_data),"%%%02X", (unsigned char)data[i]);
			ret_data = ret_data + hex_data;
		}
	}
	return ret_data;
}

std::string LY::CTencentOpenAPI::encode_value_of_pair_and_join( const map<string,string>& paramter_pair )
{
	string join_parameters;	//url����
	for(map<string,string>::const_iterator it = paramter_pair.begin();
		it!= paramter_pair.end();it++)
	{		
		join_parameters = join_parameters + it->first + '=' + urlencode(g_ascii_to_utf8(it->second)) + '&';
	}
	join_parameters.resize(join_parameters.length()-1);
	return join_parameters;
}

bool LY::CTencentOpenAPI::parse_http_response_json_data( const string& response_data, __out map<string,string>& data_pair )
{
	data_pair.clear();
	cJSON* json = cJSON_Parse(response_data.c_str());
	if (json)
	{
		if(json->child)
		{
			cJSON* js = json->child;
			while(js)
			{
				switch(js->type)
				{
					case cJSON_Number:
						{
							char s[64];
							sprintf_s(s, sizeof(s),"%d",js->valueint);
							data_pair[js->string] = s;
							break;
						}
					case cJSON_String:
						{
							data_pair[js->string] = js->valuestring;
							break;
						}
				}
				js = js->next;
			}
			
		}
	}
	else
		return false;
	cJSON_Delete(json);
	return true;
}

bool LY::CTencentOpenAPI::get_vip_user_info( const string& appkey, const string& appid, 
											const string& openkey, const string& openid, const string& pf,
											const string& userip,
											__out string& error_message,	
											__out bool& is_yellow_vip,		
											__out bool& is_yellow_year_vip, 
											__out int& yellow_vip_level,	
											__out bool& is_yellow_high_vip,	
											__out int& yellow_vip_pay_way)
{
	#define URI "/v3/user/is_vip"
	//---------------

	error_message = UNKNOWN_ERROR;
	is_yellow_vip = false;
	is_yellow_year_vip = false;
	yellow_vip_level = 0;
	is_yellow_high_vip = false;
	yellow_vip_pay_way = 0;

	//---------------------
	map<string,string> paramter_pair;	//������ֵ��
	paramter_pair["openid"] = openid;
	paramter_pair["openkey"] = openkey;
	paramter_pair["appid"] = appid;
	paramter_pair["pf"] = pf;
	paramter_pair["format"] = "json";

	if(userip.length() > 0)	//useripΪ��ѡ��
		paramter_pair["userip"] = userip;

	//����ǩ��
	string signture = sign(appkey, "get", URI, paramter_pair);
	paramter_pair["sig"] = signture;


	//��������ʱ���в�����Ҫ����URL���룬ע�⣺ֻ�в�����ֵ����url����
	string url_parameter;	//url����
	url_parameter = encode_value_of_pair_and_join(paramter_pair);


	CHttpClient httpclient(m_host, m_port);
	LY::key_value_pair_map no_other_head;	//û��������չͷ
	int status_code;
	string response_head, response_data;
	bool b_ret = httpclient.get_request_for_small_data(URI, url_parameter, no_other_head, status_code, response_head, response_data);
	//http����ʧ�ܣ�����false
	if (!b_ret)
		return false;

	/*

	��ȷ����ʾ��
	JSONʾ��:
	Content-type: text/html; charset=utf-8
	{
	"ret": 0,
	"is_lost": 0,
	"is_yellow_vip": 1,
	"is_yellow_year_vip": 1,
	"yellow_vip_level": 7,
	"is_yellow_high_vip": 0,
	"yellow_vip_pay_way": 0
	}

	���󷵻�ʾ��
	Content-type: text/html; charset=utf-8
	{
	"ret":1002,
	"msg":"���ȵ�¼"
	}
	*/
	if(status_code == 200)	//��Ӧ�ɹ�
	{
		map<string,string> data_pair;
		parse_http_response_json_data(response_data,data_pair);
		if (data_pair.size() > 0)
		{
			if(data_pair["ret"] == "0")	//����ɹ�
			{
				//�����Ƿ�Ϊ�����û�-------------
				string s_value = data_pair["is_yellow_vip"];
				if (s_value!="")
					is_yellow_vip = s_value =="1";
				//�����Ƿ�Ϊ��ѻ����û�-----------------
				s_value = data_pair["is_yellow_year_vip"];
				if (s_value!="")
					is_yellow_year_vip = s_value =="1";
				//���ػ���ȼ���Ŀǰ��߼���Ϊ����8��(����ǻ����û��ŷ��ش��ֶ�)------------------
				s_value = data_pair["yellow_vip_level"];
				if (s_value!="")
				{
					if (g_is_number(s_value))
						yellow_vip_level = g_str_to_int(s_value);
				}		
				//�����Ƿ�Ϊ����������û�(��pf=qzone��pengyou��qplusʱ����)-----------------------				 
				s_value = data_pair["is_yellow_high_vip"];
				if (s_value!="")
					is_yellow_high_vip = s_value =="1";
				//�����û��ĸ�������,0:��Ԥ�����û�,1:Ԥ�����û�-------------------
				s_value = data_pair["yellow_vip_pay_way"];
				if (s_value!="")
				{
					if (g_is_number(s_value))
						yellow_vip_pay_way = g_str_to_int(s_value);
				}
				return true;
			}
			else	//������
			{
				error_message = data_pair["msg"];
			}
		}
	}
	else
	{
		char msg[128];
		sprintf_s(msg, sizeof(msg),"http server response code is %d.",status_code);
		error_message = msg;
	}


	return false;

}

bool LY::CTencentOpenAPI::get_user_is_setup( const string& appkey, const string& appid, 
											const string& openkey, const string& openid, 
											const string& pf, const string& userip, 
											__out string& error_message, __out bool& is_setuped )
{
	#define URI "/v3/user/is_setup"

	error_message = UNKNOWN_ERROR;
	is_setuped = false;

	map<string,string> paramter_pair;	//������ֵ��
	paramter_pair["openid"] = openid;
	paramter_pair["openkey"] = openkey;
	paramter_pair["appid"] = appid;
	paramter_pair["pf"] = pf;
	paramter_pair["format"] = "json";

	if(userip.length() > 0)	//useripΪ��ѡ��
		paramter_pair["userip"] = userip;

	//����ǩ��
	string signture = sign(appkey, "get", URI, paramter_pair);
	paramter_pair["sig"] = signture;


	//��������ʱ���в�����Ҫ����URL���룬ע�⣺ֻ�в�����ֵ����url����
	string url_parameter;	//url����
	url_parameter = encode_value_of_pair_and_join(paramter_pair);


	CHttpClient httpclient(m_host, m_port);
	LY::key_value_pair_map no_other_head;	//û��������չͷ
	int status_code;
	string response_head, response_data;
	bool b_ret = httpclient.get_request_for_small_data(URI, url_parameter, no_other_head, status_code, response_head, response_data);
	//http����ʧ�ܣ�����false
	if (!b_ret)
		return false;
	/*
	*
	��ȷ����ʾ��
	JSONʾ��:
	Content-type: text/html; charset=utf-8
	{
	"ret":0,
	"is_lost":0,
	"setuped":1
	}
	2.9	���󷵻�ʾ��
	Content-type: text/html; charset=utf-8
	{
	"ret":1002,
	"msg":"���ȵ�¼"
	}
	**/
	if(status_code == 200)	//��Ӧ�ɹ�
	{
		map<string,string> data_pair;
		if(!parse_http_response_json_data(response_data,data_pair))
			return false;
		if (data_pair["ret"] == "0")
		{
			is_setuped = data_pair["setuped"]=="1";

			return true;
		}
		else
		{
			error_message = data_pair["msg"];
		}
	}
	else	//����������
	{
		char msg[128];
		sprintf_s(msg, sizeof(msg),"http server response code is %d.",status_code);
		error_message = msg;
		return false;
	}

	return false;
}

bool LY::CTencentOpenAPI::get_user_is_login( const string& appkey, const string& appid, 
											const string& openkey, const string& openid, 
											const string& pf, const string& userip, 
											__out string& error_message, __out bool& is_logined )
{
	#define URI "/v3/user/is_login"

	is_logined = false;
	error_message = UNKNOWN_ERROR;

	map<string,string> paramter_pair;	//������ֵ��
	paramter_pair["openid"] = openid;
	paramter_pair["openkey"] = openkey;
	paramter_pair["appid"] = appid;
	paramter_pair["pf"] = pf;
	paramter_pair["format"] = "json";

	if(userip.length() > 0)	//useripΪ��ѡ��
		paramter_pair["userip"] = userip;

	//����ǩ��
	string signture = sign(appkey, "get", URI, paramter_pair);
	paramter_pair["sig"] = signture;


	//��������ʱ���в�����Ҫ����URL���룬ע�⣺ֻ�в�����ֵ����url����
	string url_parameter;	//url����
	url_parameter = encode_value_of_pair_and_join(paramter_pair);


	CHttpClient httpclient(m_host, m_port);
	LY::key_value_pair_map no_other_head;	//û��������չͷ
	int status_code;
	string response_head, response_data;
	bool b_ret = httpclient.get_request_for_small_data(URI, url_parameter, no_other_head, status_code, response_head, response_data);
	//http����ʧ�ܣ�����false
	if (!b_ret)
		return false;
	/*
	*
	��ȷ����ʾ��
	JSONʾ��:
	Content-type: text/html; charset=utf-8
	{
	"ret":0,
	"msg":"�û��ѵ�¼"
	}
	���󷵻�ʾ��
	Content-type: text/html; charset=utf-8
	{
	"ret":1002,
	"msg":"�û�û�е�¼̬"
	}
	**/
	if(status_code == 200)	//��Ӧ�ɹ�
	{
		map<string,string> data_pair;
		if(!parse_http_response_json_data(response_data,data_pair))
			return false;
		if (data_pair["ret"] == "0")
		{
			is_logined = true;

			return true;
		}
		else
		{
			error_message = data_pair["msg"];
		}
	}
	else	//����������
	{
		char msg[128];
		sprintf_s(msg, sizeof(msg),"http server response code is %d.",status_code);
		error_message = msg;
		return false;
	}

	return false;
}

bool LY::CTencentOpenAPI::get_is_area_login( const string& appkey, const string& appid, 
											const string& openkey, const string& openid, 
											const string& pf, const string& userip, 
											const string& seqid, 
											__out string& error_message, __out bool& is_area_login )
{
	#define URI "/v3/user/is_area_login"

	is_area_login = false;
	error_message = UNKNOWN_ERROR;

	map<string,string> paramter_pair;	//������ֵ��
	paramter_pair["openid"] = openid;
	paramter_pair["openkey"] = openkey;
	paramter_pair["appid"] = appid;
	paramter_pair["pf"] = pf;
	paramter_pair["format"] = "json";
	paramter_pair["seqid"] = seqid;

	if(userip.length() > 0)	//useripΪ��ѡ��
		paramter_pair["userip"] = userip;

	//����ǩ��
	string signture = sign(appkey, "get", URI, paramter_pair);
	paramter_pair["sig"] = signture;


	//��������ʱ���в�����Ҫ����URL���룬ע�⣺ֻ�в�����ֵ����url����
	string url_parameter;	//url����
	url_parameter = encode_value_of_pair_and_join(paramter_pair);


	CHttpClient httpclient(m_host, m_port);
	LY::key_value_pair_map no_other_head;	//û��������չͷ
	int status_code;
	string response_head, response_data;
	bool b_ret = httpclient.get_request_for_small_data(URI, url_parameter, no_other_head, status_code, response_head, response_data);
	//http����ʧ�ܣ�����false
	if (!b_ret)
		return false;
	/*
	��ȷ����ʾ��
	JSONʾ��:
	Content-type: text/html; charset=utf-8
	{
	"ret":0,
	"is_lost":0
	}
	ע���ýӿ���ʱ��֧�ַ���xml�����ݸ�ʽ��
	���󷵻�ʾ��
	Content-type: text/html; charset=utf-8
	{
	"ret":1002,
	"msg":"���ȵ�¼"
	}
	*/
	if(status_code == 200)	//��Ӧ�ɹ�
	{
		map<string,string> data_pair;
		if(!parse_http_response_json_data(response_data,data_pair))
			return false;
		if (data_pair["ret"] == "0")
		{
			is_area_login = true;

			return true;
		}
		else
		{
			error_message = data_pair["msg"];
		}
	}
	else	//����������
	{
		char msg[128];
		sprintf_s(msg, sizeof(msg),"http server response code is %d.",status_code);
		error_message = msg;
		return false;
	}

 
	return false;
}

bool LY::CTencentOpenAPI::check_word_filter( const string& appkey, const string& appid, 
											const string& openkey, const string& openid, 
											const string& pf, const string& userip, 
											const string& content, const string& msgid, 
											__out string& message, __out bool& is_dirty )
{
#define URI "/v3/csec/word_filter"

	is_dirty = false;
	message = UNKNOWN_ERROR;

	map<string,string> paramter_pair;	//������ֵ��
	paramter_pair["openid"] = openid;
	paramter_pair["openkey"] = openkey;
	paramter_pair["appid"] = appid;
	paramter_pair["pf"] = pf;
	paramter_pair["format"] = "json";
	paramter_pair["msgid"] = msgid;
	paramter_pair["content"] = (content);

	if(userip.length() > 0)	//useripΪ��ѡ��
		paramter_pair["userip"] = userip;

	//����ǩ��
	string signture = sign(appkey, "get", URI, paramter_pair);
	paramter_pair["sig"] = signture;


	//��������ʱ���в�����Ҫ����URL���룬ע�⣺ֻ�в�����ֵ����url����
	string url_parameter;	//url����
	url_parameter = encode_value_of_pair_and_join(paramter_pair);


	CHttpClient httpclient(m_host, m_port);
	LY::key_value_pair_map no_other_head;	//û��������չͷ
	int status_code;
	string response_head, response_data;
	bool b_ret = httpclient.get_request_for_small_data(URI, url_parameter, no_other_head, status_code, response_head, response_data);
	//http����ʧ�ܣ�����false
	if (!b_ret)
		return false;

	/*
	��ȷ����ʾ��
	JSONʾ��:
	��1���ı���û�����д�ʱ
	Content-type: text/thml;charset=utf-8
	{
	"ret": 0,
	"is_lost": 0,
	"is_dirty": 0,
	"msg": "words no dirty"
	}

	��2���ı��������д�ʱ�����дʻᱻ�滻Ϊ�� * ����
	Content-type: text/thml;charset=utf-8
	{
	"ret": 0,
	"is_lost": 0,
	"is_dirty": 1,
	"msg": "*****�Ѿ�******"
	}

	���󷵻�ʾ��
	Content-type: text/html; charset=utf-8
	{
	"ret":1002,
	"msg":"���ȵ�¼"
	}
	*/
	if(status_code == 200)	//��Ӧ�ɹ�
	{
		map<string,string> data_pair;
		if(!parse_http_response_json_data(response_data,data_pair))
			return false;
		if (data_pair["ret"] == "0")
		{
			is_dirty = data_pair["is_dirty"]=="1";
			message = data_pair["msg"];
			return true;
		}
		else
		{
			message = data_pair["msg"];
		}
	}
	else	//����������
	{
		char msg[128];
		sprintf_s(msg, sizeof(msg),"http server response code is %d.",status_code);
		message = msg;

	}

	return false;
}

bool LY::CTencentOpenAPI::check_spam_message( const string& appkey, const string& appid, 
											 const string& openkey, const string& openid, 
											 const string& pf, const string& userip, 
											 const string& ctype, const string& content, 
											 __out string& error_message, __out bool& is_spiteful_message, 
											 __out int& advise_forbidden_time )
{
#define URI "/v3/csec/check_spam"

	is_spiteful_message = false;
	advise_forbidden_time = 0;
	error_message = UNKNOWN_ERROR;

	map<string,string> paramter_pair;	//������ֵ��
	paramter_pair["openid"] = openid;
	paramter_pair["openkey"] = openkey;
	paramter_pair["appid"] = appid;
	paramter_pair["pf"] = pf;
	paramter_pair["format"] = "json";
	paramter_pair["ctype"] = ctype;
	paramter_pair["content"] = (content);

	if(userip.length() > 0)	//useripΪ��ѡ��
		paramter_pair["userip"] = userip;

	//����ǩ��
	string signture = sign(appkey, "get", URI, paramter_pair);
	paramter_pair["sig"] = signture;


	//��������ʱ���в�����Ҫ����URL���룬ע�⣺ֻ�в�����ֵ����url����
	string url_parameter;	//url����
	url_parameter = encode_value_of_pair_and_join(paramter_pair);


	CHttpClient httpclient(m_host, m_port);
	LY::key_value_pair_map no_other_head;	//û��������չͷ
	int status_code;
	string response_head, response_data;
	bool b_ret = httpclient.get_request_for_small_data(URI, url_parameter, no_other_head, status_code, response_head, response_data);
	//http����ʧ�ܣ�����false
	if (!b_ret)
		return false;
	/*
	��ȷ����ʾ��
	JSONʾ��:
	Content-Type: text/html;charset=utf-8
	{
	"ret": 0,
	"is_lost": 0,
	"result": 0,
	"forbid_time": 0
	}
	���󷵻�ʾ��
	Content-Type: text/html; charset=utf-8
	{
	"ret":1002,
	"msg":"���ȵ�¼"
	}
	*/
	if(status_code == 200)	//��Ӧ�ɹ�
	{
		map<string,string> data_pair;
		if(!parse_http_response_json_data(response_data,data_pair))
			return false;
		if (data_pair["ret"] == "0")
		{
			is_spiteful_message = data_pair["result"]=="1";
			if (g_is_number(data_pair["forbid_time"]))			//���������
			{
				advise_forbidden_time = g_str_to_int(data_pair["forbid_time"]);
			}			
			return true;
		}
		else
		{
			error_message = data_pair["msg"];
		}
	}
	else	//����������
	{
		char msg[128];
		sprintf_s(msg, sizeof(msg),"http server response code is %d.",status_code);
		error_message = msg;
	}


	return false;
}

bool LY::CTencentOpenAPI::get_is_reminder_set( const string& appkey, const string& appid, 
											  const string& openkey, const string& openid, 
											  const string& pf, const string& userip,
											  __out string& error_message, __out bool& is_setup, 
											  __out bool& is_enabled )
{
#define URI "/v3/spread/is_reminder_set"

	is_setup = false;
	is_enabled = false;
	error_message = UNKNOWN_ERROR;

	map<string,string> paramter_pair;	//������ֵ��
	paramter_pair["openid"] = openid;
	paramter_pair["openkey"] = openkey;
	paramter_pair["appid"] = appid;
	paramter_pair["pf"] = pf;
	paramter_pair["format"] = "json";
	/*
	 * ��Ҫ��ȡ�Ĳ�ͬ״̬��
	 * 0����ȡ�û��Ƿ�װ�ˡ�QQ���ѡ�Ӧ�ã�
	 * 1����ȡ�û��Ƿ��ڡ�QQ���ѡ�Ӧ���п��������ѣ�
	 * 2��ͬʱ��ȡ�û��Ƿ�װ�ˡ�QQ���ѡ�Ӧ�ã��Լ��Ƿ��ڡ�QQ���ѡ��п��������ѡ�
	*/
	paramter_pair["cmd"] = "2";	//ֱ��ʹ��2��ȡ����״̬�����ϲ�ʹ��


	if(userip.length() > 0)	//useripΪ��ѡ��
		paramter_pair["userip"] = userip;

	//����ǩ��
	string signture = sign(appkey, "get", URI, paramter_pair);
	paramter_pair["sig"] = signture;


	//��������ʱ���в�����Ҫ����URL���룬ע�⣺ֻ�в�����ֵ����url����
	string url_parameter;	//url����
	url_parameter = encode_value_of_pair_and_join(paramter_pair);


	CHttpClient httpclient(m_host, m_port);
	LY::key_value_pair_map no_other_head;	//û��������չͷ
	int status_code;
	string response_head, response_data;
	bool b_ret = httpclient.get_request_for_small_data(URI, url_parameter, no_other_head, status_code, response_head, response_data);
	//http����ʧ�ܣ�����false
	if (!b_ret)
		return false;
	/*
	��ȷ����ʾ��
	Content-type: text/html; charset=utf-8
	{
	"ret":0,   
	"is_lost":0,     
	"setup":1,
	"reg":0   
	} 
	setup
	��ʾ�û��Ƿ�װ�ˡ�QQ���ѡ�Ӧ�á�
	0���û�û�а�װ��QQ���ѡ�Ӧ�ã�
	1���û���װ�ˡ�QQ���ѡ�Ӧ�á�
	reg
	��ʾ�û��Ƿ���Ӧ���п��������ѹ��ܡ�
	-1���û�û���ڡ�QQ���ѡ��￪ͨ��Ӧ�õ����ѹ��ܣ�
	0���û�û�п�����Ӧ�õ����ѹ��ܣ�
	1���û������˸�Ӧ�õ����ѹ��ܡ�

	���󷵻�ʾ��
	Content-type: text/html; charset=utf-8
	{
	"ret":1002,
	"msg":"���ȵ�¼" 
	}
	*/
	if(status_code == 200)	//��Ӧ�ɹ�
	{
		map<string,string> data_pair;
		if(!parse_http_response_json_data(response_data,data_pair))
			return false;
		if (data_pair["ret"] == "0")
		{
			is_setup = data_pair["setup"]=="1";
			is_enabled = data_pair["reg"]=="1";
			return true;
		}
		else
		{
			error_message = data_pair["msg"];
		}
	}
	else	//����������
	{
		char msg[128];
		sprintf_s(msg, sizeof(msg),"http server response code is %d.",status_code);
		error_message = msg;
	}


	return false;
}

bool LY::CTencentOpenAPI::set_reminder( const string& appkey, const string& appid, 
									   const string& openkey, const string& openid, 
									   const string& pf, const string& userip, 
									   const vector<reminder_info>& info, __out string& error_message )
{
#define URI "/v3/spread/set_reminder"

	error_message = UNKNOWN_ERROR;

	map<string,string> paramter_pair;	//������ֵ��
	paramter_pair["openid"] = openid;
	paramter_pair["openkey"] = openkey;
	paramter_pair["appid"] = appid;
	paramter_pair["pf"] = pf;
	paramter_pair["format"] = "json";
	
	assert(info.size() > 0);
	
	for (int i=0; i < info.size();i++)
	{
		if (i > 2)	//���ֻ��������������Ϣ
		{
			break;
		}
		string key = "begin";
		key += g_int_to_str(i);
		paramter_pair[key] = g_int_to_str(info[i].begin_time);
		//-----------
		key = "key";
		key += g_int_to_str(i);
		paramter_pair[key] = g_int_to_str(info[i].key);
		//--------------------
		key = "type";
		key += g_int_to_str(i);
		assert(info[i].type > 20000);
		paramter_pair[key] = g_int_to_str(info[i].type);
		//---------------
		key = "title";
		key += g_int_to_str(i);
		paramter_pair[key] = info[i].message;
	}

	if(userip.length() > 0)	//useripΪ��ѡ��
		paramter_pair["userip"] = userip;

	//����ǩ��
	string signture = sign(appkey, "post", URI, paramter_pair);
	paramter_pair["sig"] = signture;


	//��������ʱ���в�����Ҫ����URL���룬ע�⣺ֻ�в�����ֵ����url����
	string url_parameter;	//url����
	url_parameter = encode_value_of_pair_and_join(paramter_pair);

	string request_data = url_parameter;


	CHttpClient httpclient(m_host, m_port);
	LY::key_value_pair_map no_other_head;	//û��������չͷ
	int status_code;
	string response_head, response_data;
	bool b_ret = httpclient.post_request(URI, request_data, no_other_head, status_code, response_head, response_data);
	//http����ʧ�ܣ�����false
	if (!b_ret)
		return false;

	/*
	��ȷ����ʾ��
	Content-type: text/html; charset=utf-8
	{
	"ret":0,
	"is_lost":0,
	"msg":""
	}
	���󷵻�ʾ��
	Content-type: text/html; charset=utf-8
	{
	"ret":1002,
	"msg":"���ȵ�¼"
	}
	*/
	if(status_code == 200)	//��Ӧ�ɹ�
	{
		map<string,string> data_pair;
		if(!parse_http_response_json_data(response_data,data_pair))
			return false;
		if (data_pair["ret"] == "0")
		{			
			return true;
		}
		else
		{
			error_message = data_pair["msg"];
		}
	}
	else	//����������
	{
		char msg[128];
		sprintf_s(msg, sizeof(msg),"http server response code is %d.",status_code);
		error_message = msg;
	}

	return false;
}

bool LY::CTencentOpenAPI::set_reminder_for_non_blocking( const string& appkey, const string& appid, 
														const string& openkey, const string& openid, 
														const string& pf, const string& userip, 
														const vector<reminder_info>& info )
{
#define URI "/v3/spread/set_reminder"

	map<string,string> paramter_pair;	//������ֵ��
	paramter_pair["openid"] = openid;
	paramter_pair["openkey"] = openkey;
	paramter_pair["appid"] = appid;
	paramter_pair["pf"] = pf;
	paramter_pair["format"] = "json";

	assert(info.size() > 0);  

	for (int i=0; i < info.size();i++)
	{
		if (i > 2)	//���ֻ��������������Ϣ
		{
			break;
		}
		string key = "begin";
		key += g_int_to_str(i);
		paramter_pair[key] = g_int_to_str(info[i].begin_time);
		//-----------
		key = "key";
		key += g_int_to_str(i);
		paramter_pair[key] = g_int_to_str(info[i].key);
		//--------------------
		key = "type";
		key += g_int_to_str(i);
		assert(info[i].type > 20000);
		paramter_pair[key] = g_int_to_str(info[i].type);
		//---------------
		key = "title";
		key += g_int_to_str(i);
		paramter_pair[key] = info[i].message;
	}

	if(userip.length() > 0)	//useripΪ��ѡ��
		paramter_pair["userip"] = userip;

	//����ǩ��
	string signture = sign(appkey, "post", URI, paramter_pair);
	paramter_pair["sig"] = signture;


	//��������ʱ���в�����Ҫ����URL���룬ע�⣺ֻ�в�����ֵ����url����
	string url_parameter;	//url����
	url_parameter = encode_value_of_pair_and_join(paramter_pair);

	string request_data = url_parameter;


	CHttpClient httpclient(m_host, m_port);
	LY::key_value_pair_map no_other_head;	//û��������չͷ

	bool b_ret = httpclient.post_request_for_non_blocking(URI, request_data, no_other_head);
	//http����ʧ�ܣ�����false
	if (!b_ret)
		return false;

	return true;
}

bool LY::CTencentOpenAPI::tencentlog_report_login_for_non_blocking( unsigned int appid, const string& userip, 
																   const string& svrip, time_t time, 
																   unsigned int domain, unsigned int worldid, 
																   unsigned int opuid, const string& opopenid, 
																   unsigned int level )
{
#define URI "/stat/report_login.php"

	CHttpClient httpclient(m_host, m_port);
	LY::key_value_pair_map no_other_head;	//û��������չͷ

	map<string,string> parameter_pair;	//������ֵ��
	parameter_pair["version"] = "1";
	parameter_pair["appid"] = g_int_to_str(appid);

	assert(userip!="");
	boost::asio::ip::address addr = boost::asio::ip::address::from_string(userip);
	boost::asio::ip::address_v4 addr_v4 = addr.to_v4();	
	parameter_pair["userip"] =  g_int_to_str((unsigned int)addr_v4.to_ulong());

	assert(svrip!="");
	addr = boost::asio::ip::address::from_string(svrip);
	addr_v4 = addr.to_v4();	
	parameter_pair["svrip"] =  g_int_to_str((unsigned int)addr_v4.to_ulong());

	parameter_pair["time"] = g_int_to_str((__int64)time);
	parameter_pair["domain"] = g_int_to_str(domain);
	parameter_pair["worldid"] = g_int_to_str(worldid);
	parameter_pair["opuid"] = g_int_to_str(opuid);
	
	assert(opopenid!="");
	parameter_pair["opopenid"] = opopenid;
	if(level!=0)
		parameter_pair["level"] = g_int_to_str(level);

	string request_parameter;
	request_parameter = encode_value_of_pair_and_join(parameter_pair);


	bool b_ret = httpclient.get_request_for_non_blocking(URI, request_parameter, no_other_head);
	//http����ʧ�ܣ�����false
	if (!b_ret)
		return false;

	return true;
}

bool LY::CTencentOpenAPI::tencentlog_report_register_for_non_blocking( unsigned int appid, const string& userip, 
																	  const string& svrip, time_t time, 
																	  unsigned int domain, unsigned int worldid, 
																	  unsigned int opuid, const string& opopenid )
{
#define URI "/stat/report_register.php"

	CHttpClient httpclient(m_host, m_port);
	LY::key_value_pair_map no_other_head;	//û��������չͷ

	map<string,string> parameter_pair;	//������ֵ��
	parameter_pair["version"] = "1";
	parameter_pair["appid"] = g_int_to_str(appid);

	assert(userip!="");
	boost::asio::ip::address addr = boost::asio::ip::address::from_string(userip);
	boost::asio::ip::address_v4 addr_v4 = addr.to_v4();	
	parameter_pair["userip"] =  g_int_to_str((unsigned int)addr_v4.to_ulong());

	assert(svrip!="");
	addr = boost::asio::ip::address::from_string(svrip);
	addr_v4 = addr.to_v4();	
	parameter_pair["svrip"] =  g_int_to_str((unsigned int)addr_v4.to_ulong());

	parameter_pair["time"] = g_int_to_str((__int64)time);
	parameter_pair["domain"] = g_int_to_str(domain);
	parameter_pair["worldid"] = g_int_to_str(worldid);
	parameter_pair["opuid"] = g_int_to_str(opuid);

	assert(opopenid!="");
	parameter_pair["opopenid"] = opopenid;


	string request_parameter;
	request_parameter = encode_value_of_pair_and_join(parameter_pair);


	bool b_ret = httpclient.get_request_for_non_blocking(URI, request_parameter, no_other_head);
	//http����ʧ�ܣ�����false
	if (!b_ret)
		return false;

	return true;
}

bool LY::CTencentOpenAPI::tencentlog_report_accept_for_non_blocking( unsigned int appid, const string& userip, 
																	const string& svrip, time_t time, 
																	unsigned int domain, unsigned int worldid, 
																	unsigned int opuid, const string& opopenid )
{
#define URI "/stat/report_accept.php"

	CHttpClient httpclient(m_host, m_port);
	LY::key_value_pair_map no_other_head;	//û��������չͷ

	map<string,string> parameter_pair;	//������ֵ��
	parameter_pair["version"] = "1";
	parameter_pair["appid"] = g_int_to_str(appid);

	assert(userip!="");
	boost::asio::ip::address addr = boost::asio::ip::address::from_string(userip);
	boost::asio::ip::address_v4 addr_v4 = addr.to_v4();	
	parameter_pair["userip"] =  g_int_to_str((unsigned int)addr_v4.to_ulong());

	assert(svrip!="");
	addr = boost::asio::ip::address::from_string(svrip);
	addr_v4 = addr.to_v4();	
	parameter_pair["svrip"] =  g_int_to_str((unsigned int)addr_v4.to_ulong());

	parameter_pair["time"] = g_int_to_str((__int64)time);
	parameter_pair["domain"] = g_int_to_str(domain);
	parameter_pair["worldid"] = g_int_to_str(worldid);
	parameter_pair["opuid"] = g_int_to_str(opuid);

	assert(opopenid!="");
	parameter_pair["opopenid"] = opopenid;


	string request_parameter;
	request_parameter = encode_value_of_pair_and_join(parameter_pair);


	bool b_ret = httpclient.get_request_for_non_blocking(URI, request_parameter, no_other_head);
	//http����ʧ�ܣ�����false
	if (!b_ret)
		return false;

	return true;
}

bool LY::CTencentOpenAPI::tencentlog_report_invite_for_non_blocking( unsigned int appid, const string& userip,
																	const string& svrip, time_t time, 
																	unsigned int domain, unsigned int worldid, 
																	unsigned int opuid, const string& opopenid, 
																	int touid /*= 0*/, const string& toopenid /*= "" */ )
{
#define URI "/stat/report_invite.php"

	CHttpClient httpclient(m_host, m_port);
	LY::key_value_pair_map no_other_head;	//û��������չͷ

	map<string,string> parameter_pair;	//������ֵ��
	parameter_pair["version"] = "1";
	parameter_pair["appid"] = g_int_to_str(appid);

	assert(userip!="");
	boost::asio::ip::address addr = boost::asio::ip::address::from_string(userip);
	boost::asio::ip::address_v4 addr_v4 = addr.to_v4();	
	parameter_pair["userip"] =  g_int_to_str((unsigned int)addr_v4.to_ulong());

	assert(svrip!="");
	addr = boost::asio::ip::address::from_string(svrip);
	addr_v4 = addr.to_v4();	
	parameter_pair["svrip"] =  g_int_to_str((unsigned int)addr_v4.to_ulong());

	parameter_pair["time"] = g_int_to_str((__int64)time);
	parameter_pair["domain"] = g_int_to_str(domain);
	parameter_pair["worldid"] = g_int_to_str(worldid);
	parameter_pair["opuid"] = g_int_to_str(opuid);

	assert(opopenid!="");
	parameter_pair["opopenid"] = opopenid;
	if(touid!=0)
		parameter_pair["touid"] = g_int_to_str(touid);
	if (toopenid!="")
		parameter_pair["toopenid"] = (toopenid);


	string request_parameter;
	request_parameter = encode_value_of_pair_and_join(parameter_pair);


	bool b_ret = httpclient.get_request_for_non_blocking(URI, request_parameter, no_other_head);
	//http����ʧ�ܣ�����false
	if (!b_ret)
		return false;

	return true;
}

bool LY::CTencentOpenAPI::tencentlog_report_consume_for_non_blocking( unsigned int appid, const string& userip, 
																	 const string& svrip, time_t time, 
																	 unsigned int domain, unsigned int worldid, 
																	 unsigned int opuid, const string& opopenid,
																	 unsigned int modifyfee, unsigned int touid, 
																	 const string& toopenid, const string& itemid, 
																	 const string& itemtype, unsigned int itemcnt,
																	 unsigned int modifyexp, unsigned int totalexp,
																	 int modifycoin, unsigned int totalcoin,
																	 unsigned int totalfee, unsigned int level )
{
#define URI "/stat/report_consume.php"

	CHttpClient httpclient(m_host, m_port);
	LY::key_value_pair_map no_other_head;	//û��������չͷ

	map<string,string> parameter_pair;	//������ֵ��
	parameter_pair["version"] = "1";
	parameter_pair["appid"] = g_int_to_str(appid);

	assert(userip!="");
	boost::asio::ip::address addr = boost::asio::ip::address::from_string(userip);
	boost::asio::ip::address_v4 addr_v4 = addr.to_v4();	
	parameter_pair["userip"] =  g_int_to_str((unsigned int)addr_v4.to_ulong());

	assert(svrip!="");
	addr = boost::asio::ip::address::from_string(svrip);
	addr_v4 = addr.to_v4();	
	parameter_pair["svrip"] =  g_int_to_str((unsigned int)addr_v4.to_ulong());

	parameter_pair["time"] = g_int_to_str((__int64)time);
	parameter_pair["domain"] = g_int_to_str(domain);
	parameter_pair["worldid"] = g_int_to_str(worldid);
	parameter_pair["opuid"] = g_int_to_str(opuid);

	assert(opopenid!="");
	parameter_pair["opopenid"] = opopenid;
	parameter_pair["modifyfee"] = g_int_to_str(modifyfee);
	if(touid!=0)
		parameter_pair["touid"] = g_int_to_str(touid);	
	if(toopenid!="")
		parameter_pair["toopenid"] = (toopenid);
	if(itemid!="")
		parameter_pair["itemid"] = (itemid);
	if(itemtype!="")
		parameter_pair["itemtype"] = (itemtype);
	if(itemcnt!=0)
		parameter_pair["itemcnt"] = g_int_to_str(itemcnt);
	if(modifyexp!=0)
		parameter_pair["modifyexp"] = g_int_to_str(modifyexp);
	if(totalexp!=0)
		parameter_pair["totalexp"] = g_int_to_str(totalexp);
	if(modifycoin!=0)
		parameter_pair["modifycoin"] = g_int_to_str(modifycoin);
	if(totalcoin!=0)
		parameter_pair["totalcoin"] = g_int_to_str(totalcoin);
	if(totalfee!=0)
		parameter_pair["totalfee"] = g_int_to_str(totalfee);
	if(level!=0)
		parameter_pair["level"] = g_int_to_str(level);

	string request_parameter;
	request_parameter = encode_value_of_pair_and_join(parameter_pair);


	bool b_ret = httpclient.get_request_for_non_blocking(URI, request_parameter, no_other_head);
	//http����ʧ�ܣ�����false
	if (!b_ret)
		return false;

	return true;
}

bool LY::CTencentOpenAPI::tencentlog_report_recharge_for_non_blocking( unsigned int appid, const string& userip, 
																	  const string& svrip, time_t time,
																	  unsigned int domain, unsigned int worldid, 
																	  unsigned int opuid, const string& opopenid,
																	  unsigned int modifyfee, unsigned int touid,
																	  const string& toopenid, const string& itemid,
																	  const string& itemtype, unsigned int itemcnt, 
																	  unsigned int modifyexp, unsigned int totalexp, 
																	  int modifycoin, unsigned int totalcoin, 
																	  unsigned int totalfee, unsigned int level )
{
#define URI "/stat/report_recharge.php"

	CHttpClient httpclient(m_host, m_port);
	LY::key_value_pair_map no_other_head;	//û��������չͷ

	map<string,string> parameter_pair;	//������ֵ��
	parameter_pair["version"] = "1";
	parameter_pair["appid"] = g_int_to_str(appid);

	assert(userip!="");
	boost::asio::ip::address addr = boost::asio::ip::address::from_string(userip);
	boost::asio::ip::address_v4 addr_v4 = addr.to_v4();	
	parameter_pair["userip"] =  g_int_to_str((unsigned int)addr_v4.to_ulong());

	assert(svrip!="");
	addr = boost::asio::ip::address::from_string(svrip);
	addr_v4 = addr.to_v4();	
	parameter_pair["svrip"] =  g_int_to_str((unsigned int)addr_v4.to_ulong());

	parameter_pair["time"] = g_int_to_str((__int64)time);
	parameter_pair["domain"] = g_int_to_str(domain);
	parameter_pair["worldid"] = g_int_to_str(worldid);
	parameter_pair["opuid"] = g_int_to_str(opuid);

	assert(opopenid!="");
	parameter_pair["opopenid"] = opopenid;
	parameter_pair["modifyfee"] = g_int_to_str(modifyfee);
	if(touid!=0)
		parameter_pair["touid"] = g_int_to_str(touid);
	if(toopenid!="")
		parameter_pair["toopenid"] = (toopenid);
	if(itemid!="")
		parameter_pair["itemid"] = (itemid);
	if(itemtype!="")
		parameter_pair["itemtype"] = (itemtype);
	if(itemcnt!=0)
		parameter_pair["itemcnt"] = g_int_to_str(itemcnt);
	if(modifyexp!=0)
		parameter_pair["modifyexp"] = g_int_to_str(modifyexp);
	if(totalexp!=0)
		parameter_pair["totalexp"] = g_int_to_str(totalexp);
	if(modifycoin!=0)
		parameter_pair["modifycoin"] = g_int_to_str(modifycoin);
	if(totalcoin!=0)
		parameter_pair["totalcoin"] = g_int_to_str(totalcoin);
	if(totalfee!=0)
		parameter_pair["totalfee"] = g_int_to_str(totalfee);
	if(level!=0)
		parameter_pair["level"] = g_int_to_str(level);

	string request_parameter;
	request_parameter = encode_value_of_pair_and_join(parameter_pair);


	bool b_ret = httpclient.get_request_for_non_blocking(URI, request_parameter, no_other_head);
	//http����ʧ�ܣ�����false
	if (!b_ret)
		return false;

	return true;
}

bool LY::CTencentOpenAPI::tencentlog_report_quit_for_non_blocking( unsigned int appid, const string& userip, 
																  const string& svrip, time_t time, 
																  unsigned int domain, unsigned int worldid, 
																  unsigned int opuid, const string& opopenid, 
																  unsigned int onlinetime, unsigned int level )
{
#define URI "/stat/report_quit.php"

	CHttpClient httpclient(m_host, m_port);
	LY::key_value_pair_map no_other_head;	//û��������չͷ

	map<string,string> parameter_pair;	//������ֵ��
	parameter_pair["version"] = "1";
	parameter_pair["appid"] = g_int_to_str(appid);

	assert(userip!="");
	boost::asio::ip::address addr = boost::asio::ip::address::from_string(userip);
	boost::asio::ip::address_v4 addr_v4 = addr.to_v4();	
	parameter_pair["userip"] =  g_int_to_str((unsigned int)addr_v4.to_ulong());

	assert(svrip!="");
	addr = boost::asio::ip::address::from_string(svrip);
	addr_v4 = addr.to_v4();	
	parameter_pair["svrip"] =  g_int_to_str((unsigned int)addr_v4.to_ulong());

	parameter_pair["time"] = g_int_to_str((__int64)time);
	parameter_pair["domain"] = g_int_to_str(domain);
	parameter_pair["worldid"] = g_int_to_str(worldid);
	parameter_pair["opuid"] = g_int_to_str(opuid);

	assert(opopenid!="");
	parameter_pair["opopenid"] = opopenid;
	parameter_pair["onlinetime"] = g_int_to_str(onlinetime);
	if(level!=0)
		parameter_pair["level"] = g_int_to_str(level);

	string request_parameter;
	request_parameter = encode_value_of_pair_and_join(parameter_pair);


	bool b_ret = httpclient.get_request_for_non_blocking(URI, request_parameter, no_other_head);
	//http����ʧ�ܣ�����false
	if (!b_ret)
		return false;

	return true;


}
