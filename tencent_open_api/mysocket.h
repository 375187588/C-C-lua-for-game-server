/************************************************************************/
/* 
author: liyang                                             
create date: 2013.5.21                                   
*/
/************************************************************************/
#ifndef _MYSOCKET_H_
#define _MYSOCKET_H_

//#include "stdafx.h"

#include <string>
#include <map>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/noncopyable.hpp>


using namespace std;

using namespace boost::asio;

#define CRLF "\r\n"
#define UNKNOWN_ERROR "unknown error."

namespace LY
{
	/*
	 * TCP socket�࣬���й����ܣ��������´����˶���ͨ���������־߱��շ����ݹ���
	*/
	class CMySocket: public boost::noncopyable
	{
	public:
		CMySocket();
		virtual ~CMySocket();

		//����������ַ������Ϊ������IP
		void set_host(const string& host);

		//��ȡ������ַ
		string get_host();

		//���ö˿ں�
		void set_port(int port);

		//��ȡ�˿ں�
		int get_port();

		//���ӷ�����
		bool connect();

		//������첽���ͣ�����0��ͬ�����ͷ���ʵ�ʷ��͵����ݳ���
		int send(const string& data, bool is_async = false);

		//ͬ���������ݣ��ݲ��ṩ�첽���գ����ݷ��ص�data��
		int recv(string &data);	

		//�ر�socket���رպ����ٴ�������
		void close();

		//�Ƿ�������-------------------------
		static bool is_ip_address(const string& host);

	protected:
		//�첽�������ݵĻص�����-----------------------
		void write_handler(
			const boost::system::error_code& error, // Result of operation.
			std::size_t bytes_transferred           // Number of bytes sent.
			); 

		//�첽�������ݵĻص�����-----------------------
		void read_handler(
			const boost::system::error_code& error, // Result of operation.
			std::size_t bytes_transferred           // Number of bytes received.
			); 




	private:
		io_service m_io_service;

		//�ڲ���socket����
		ip::tcp::socket m_socket;
		
		//��������
		string m_host;
		
		//����˿�
		int m_port;
	};

	typedef map<string,string> key_value_pair_map;

	/*
	 * http�ͻ����࣬�ṩ�����ܣ������ؽ�����ͬһ������Է�������ͬҳ��
	*/
	class CHttpClient: public noncopyable
	{
	public:
		explicit CHttpClient(const string& host, int port = 80);
		virtual ~CHttpClient();
		/*
		 * HTTP GET���󣬴˽ӿ���Ҫ��������С���ݣ�����������response_data��
		 * ���� uri Ϊ uri��ַ��ע�⣺uri��ַ����http://
		 * ���� request_parameterΪURI���������磺a=1&b=2����û�в��������մ�
		 * ���� other_head Ϊ����HTTPͷ�������Ϣ
		 * ���� status_code Ϊhttp���������ص�״̬�𣬳ɹ�һ����200
		 * ���� response_head �Ƿ��ص�http��Ӧͷ���ݲ���
		 * ���� response_data ���ص�ʵ�����ݲ���
		 * ����ֵ���Ϊfalse�����ʾ��������ʧ�ܣ�Ϊtrue��ʾִ��http����ɹ�
	    **/
		bool get_request_for_small_data(const string &uri, const string &request_parameter, const key_value_pair_map &other_head, 
			int& status_code, string& response_head, string& response_data);

		/*
		 * HTTP GET���������󣬲��ȴ���������
		 * �ɹ�����true
		 * �����ο�get_request_for_small_data�ӿ�
		*/
		bool get_request_for_non_blocking(const string &uri, const string &request_parameter, const key_value_pair_map &other_head);

		/*
		 * HTTP POST����
		 * ���� uri Ϊ uri��ַ��ע�⣺uri��ַ����http://
		 * ���� request_data Ϊ��������ݲ���
		 * ���� other_head Ϊ����HTTPͷ�������Ϣ
		 * ���� status_code Ϊhttp���������ص�״̬�𣬳ɹ�һ����200
		 * ���� response_head �Ƿ��ص�http��Ӧͷ���ݲ���
		 * ���� response_data ���ص�ʵ�����ݲ���
		 * ����ֵ���Ϊfalse�����ʾ��������ʧ�ܣ�Ϊtrue��ʾִ��http����ɹ�
		*/
		bool post_request(const string &uri, const string &request_data, const key_value_pair_map &other_head, 
			int& status_code, string& response_head, string& response_data);

		/*
		 * HTTP POST����������ֻ�з��ͣ����������
		 * �ɹ�����true������false
		 * ���� uri Ϊ uri��ַ��ע�⣺uri��ַ����http://
		 * ���� request_data Ϊ��������ݲ���
		 * ���� other_head Ϊ����HTTPͷ�������Ϣ
		*/
		bool post_request_for_non_blocking(const string &uri, const string &request_data, const key_value_pair_map &other_head);


		
		//����������ַ
		void set_host(const string& host);

		//��ȡ������ַ
		string get_host();
		
		//���ö˿ں�		
		void set_port(int port);
		
		//��ȡ�˿ں�
		int get_port();


	protected:
	private:

		CMySocket m_mysocket;
 
	};

	/*
	 * CTencentOpenAPI�࣬��װ����Ѷ���Žӿڵ�API
	 * ͨ������ֱ�ӵ��ø����ӿڼ���
	*/
	class CTencentOpenAPI
	{
	public:
		CTencentOpenAPI(const string& host, int port = 80): m_host(host), m_port(port)
		{

		}
		virtual ~CTencentOpenAPI()
		{
		}

		/*
		 * �õ�ǩ����
		 * ����ֵΪǩ����
		 * ���� appkey,����Ѷ����
		 * ���� request_way������ʽ��ֵΪGET��POST
		 * ���� uri��uri��ַ��������http://���磺v3/user/get_info
		 * ���� paramter_pair��������
		**/
		static string sign(const string& appkey, const string& request_way, const string& uri, const map<string,string>& paramter_pair);
		
		//url���룬��Ѷ��url����������׼��Щ����
		static string urlencode(const string& data);

//user interface area begin-----------------

		/*
		 * �ӿڹ���Ϊ��ȡ�û���Ϣ��ע�⣺����ֵ��ʾ�Ƿ�ִ�гɹ�
		 * ����appkey ��Ϊǩ������Կ������Ѷ����
		 * ����appid��Ӧ�õ�ΨһID������Ѷ���䣬����ͨ��appid����APP������Ϣ��
		 *
		 * ����openid����APPͨ�ŵ��û�key����ƽֱ̨�Ӵ���Ӧ�ã�Ӧ��ԭ������ƽ̨����
		 * ��ƽ̨��ת��Ӧ��ʱ�����Ӧ�õ�CanvasURL��ƽ̨����CanvasURL����ϱ�����
		 * 
		 * ����openkey,session key����ƽֱ̨�Ӵ���Ӧ�ã�Ӧ��ԭ������ƽ̨����
		 * ��ƽ̨��ת��Ӧ��ʱ�����Ӧ�õ�CanvasURL��ƽ̨����CanvasURL����ϱ�������
		 *
		 * ����pf��Ӧ�õ���Դƽ̨����ƽֱ̨�Ӵ���Ӧ�ã�Ӧ��ԭ������ƽ̨����
		 * ��ƽ̨��ת��Ӧ��ʱ�����Ӧ�õ�CanvasURL��ƽ̨����CanvasURL����ϱ���������ƽֱ̨�Ӵ���Ӧ�ã�Ӧ��ԭ������ƽ̨���ɡ�
		 * ����userip���û���IP��ַ�����ÿ��Դ����ֵ
		 * ����error_message�����صĴ�����Ϣ
		 * ����is_yellow_vip�������Ƿ�Ϊ�����û�
		 * ����is_yellow_year_vip�������Ƿ�Ϊ��ѻ����û�
		 * ����yellow_vip_level�����ػ���ȼ���Ŀǰ��߼���Ϊ����8��(����ǻ����û��ŷ��ش��ֶ�)
		 * ����is_yellow_high_vip�������Ƿ�Ϊ����������û�(��pf=qzone��pengyou��qplusʱ����)
		 * ����yellow_vip_pay_way�������û��ĸ�������
		 * 0:��Ԥ�����û�(�ȿ�ͨҵ��󸶷ѣ�һ��ָͨ���ֻ���ͨ������û�)
		 * 1:Ԥ�����û�(�ȸ��Ѻ�ͨҵ��һ��ָͨ��Q��Q�㡢�Ƹ�ͨ���������ѿ�ͨ������û�)
		*/
		bool get_vip_user_info(const string& appkey, const string& appid, 
			const string& openkey, const string& openid, const string& pf,
			const string& userip,
			__out string& error_message,	
			__out bool& is_yellow_vip,		
			__out bool& is_yellow_year_vip, 
			__out int& yellow_vip_level,	
			__out bool& is_yellow_high_vip,	
			__out int& yellow_vip_pay_way
			);

		/*
		 * ��֤��¼�û��Ƿ�װ��Ӧ�á�ע�⣺����ֵ��ʾ�Ƿ�ִ�гɹ�
		 * ����userip���û���IP��ַ�����ÿ��Դ����ֵ
		 * ����error_message�����صĴ�����Ϣ
		 * ����is_setuped����ʾ�Ƿ�װӦ��
		 * ��������ͬ��
		**/
		bool get_user_is_setup(const string& appkey, const string& appid, 
			const string& openkey, const string& openid, const string& pf,
			const string& userip,
			__out string& error_message,
			__out bool& is_setuped
			);
		/*
		 * ��֤�û��ĵ�¼̬���ж�openkey�Ƿ���ڣ�û�й������openkey��Ч�ڽ������ڣ�һ�ε�������2Сʱ����
		 * ����ֵ��ʾ�Ƿ�ִ�гɹ��͵�¼�ɹ�
		 * ���ӿڵĵ��ó�����
		 *��1�� ������֤�û���¼̬��
		 * ��֤��¼̬�ı�Ҫ�������������Ż�ԭ��#1.3 ��Ҫ���ǶԵ�¼̬��У�飻
		 * ��ע������Ƕ������Ӧ�ã������ñ��ӿڽ��е�¼̬��֤�⣬����Ҫ����v3/user/is_area_login�ӿ���֤�Ƿ��ѡ��ҳ�����Ӧ�ã���
		 * ��2�� ������openkey�������ڡ�
		 * �û���¼ƽ̨�����Ӧ��ʱ��URL�л���и��û���OpenID��openkey����openkey����2Сʱ����Ч�ڡ�
		 * ����û���Ӧ����һֱ�ڲ���������2Сʱ��û�д���OpenAPI�ĵ��ã���ᵼ��openkey���ڡ�
		 * ��˿�������Ҫ���ñ��ӿ�����openkey�������ڣ�һ�ε�������2Сʱ�����ӿ��޵��ô������ơ�
		 * ע���������ƽ̨ͳһˢ�µ�¼̬�������ڻ���ʧЧ��
		 * �����߿ɵ���fusion2.dialog.relogin�ӿڵ�����¼�������û���¼�����»��openkey�� 
		 * 
		 * ����userip���û���IP��ַ�����ÿ��Դ����ֵ
		 * ����is_login�������Ƿ��¼�ɹ�
		 * ��������ͬ��
		*/
		bool get_user_is_login(const string& appkey, const string& appid, 
			const string& openkey, const string& openid, const string& pf,
			const string& userip,
			__out string& error_message,
			__out bool& is_login
			);

		/*
	     * ���ӿڽ������ڶ������Ӧ�ã�������֤�û���¼̬������֤openkey�����Լ���֤�û��Ƿ��ѡ��ҳ�棨����֤seqid������Ӧ�á�
		 * ����ֵ��ʾ�Ƿ�ִ�гɹ�
		 * �������Ӧ������������֤�û��Ƿ��ѡ��ҳ�����Ӧ�õ��߼����������ڷ�ֹ�û�ֱ��ͨ���޸�Ӧ�õ�ַ�ķ�ʽ����Ӧ�á�
		 * ��Ҫע����ǣ�
		 *��1�����ñ��ӿں󣬿�����openkey�Լ�seqid����֤�������Ҫ��openkey������������Ҫ����v3/user/is_login�� 
		 *��2���û�ÿ�δ�ѡ��ҳ���¼�����ɵ�seqid������Ч�ڣ�ֻ��ʹ��һ�Σ���֤һ�κ�ͻ���ڡ�
		 * �����Ӧ��ʹ��ͬ����seqid�Ͳ�������2�����󣬵�һ�η��سɹ����ڶ�����ᱨ��
		 * 
		 * ����seqid��ʶ���ζ��������¼�������룬ͨ����seqid���ҵ��û���¼��Ψһ��¼����ƽֱ̨�Ӵ���Ӧ�ã�Ӧ��ԭ������ƽ̨���ɡ�
		 * ����userip���û���IP��ַ�����ÿ��Դ����ֵ
		 * ����is_area_login�����Ƿ��¼�ɹ�
		 * ��������ͬ��
		*/
		bool get_is_area_login(
			const string& appkey, const string& appid, 
			const string& openkey, const string& openid, const string& pf,
			const string& userip, const string& seqid,
			__out string& error_message,
			__out bool& is_area_login
			);

		/*
		 * ����ı����Ƿ�������дʣ���������Ӧ�Ĵ���
		 *��1������ı��к��и߶����дʻ��ʱ����ֱ�ӷ���"�ı��������д�"�������ر�*�������ı���
		 *��2������ı��к���������������дʻ㣬�����д��滻��*��Ȼ���ı����ء� 
		 *ע��
		 *��1���ı�������utf-8���룬����ᵼ�����дʲ��ܱ����ˡ�
		 *��2���ı�urlencode��ĳ��Ȳ��ܳ���9000������ᱨ��
		 * ����content��������Ƿ�������дʵ��ı���ascii����
		 *
		 * ����msgid,���Ա��ID����󳤶�64�ֽڡ���ر�֤msgid��Ψһ��Ӧһ����Ϣ�����ֶ����ڱ����ֶΣ����ں���������չ��
		 * ʾ����12bbccddeeaabbccddeeaabbccddeeaabbccddee22
		 *
		 * ����is_dirty������true��ʾ�����дʣ�false��ʾû��
		 * ����message,���ش�����Ϣ�����д������Ϣ(����Ѷ���ص�)
		 * ��������ͬ��
		*/
		bool check_word_filter(
			const string& appkey, const string& appid, 
			const string& openkey, const string& openid, const string& pf,
			const string& userip, 
			const string& content,
			const string& msgid,
			__out string& message,
			__out bool& is_dirty
			);

		/*
		 * ��������Ϊ������Ϣ���
		 * ���ӿڵ���ǰ������Ȩ�ޣ�����������˵�������Ѷ�ٷ�����
		 * ������Ϣ��������Ҫ�����webgame����Ӧ���г��ֵ���ٹ�桢���������˽�������������Ҵ��������½�����Ϣ����Ʒ����������ˢ����������Ϣ�ͷ�����Ϊ���м�⡣
		 * ϵͳ���Ӧ���ϱ������ݽ��н�ģ��������ʶ���û���Ϊ���������ö���ϵ�ȸ���ά��ʶ��������Ϣ�����������ͨ�����ӿڷ��ظ�Ӧ��Ȼ���ɿ��������д����綪�������桢���Եȡ�
		 * ������Ϣ�������Ŀ����Ϊ��������Ϸ��������Ϣ�Ĵ�����������Ϸ�е����ۻ����������ҵ���Ϸ���顣 
		 * ���ñ��ӿں󣬽�����Ӧ�����û��ķ��ԡ��ʼ���Ⱥ��������Ϣ����������Ϣ�������桢�໰������ʶ��
		 * ���������������Ϣ�����������Ľ���ʱ����Ӧ�ÿ����н�����Ӧ�Ĵ���
		 * ����ctype����ʾ�û���Ϣ�����;����		 
		 *	 1����ʾ���죻
		 *	 2����ʾ�ʼ���
		 *	 3����ʾ��Ϸ�еĽ�ɫ����
		 *	 4����ʾ�������ͣ���sns��Ϸ�е����԰�ȡ�
		 * ����content��������Ƿ����������Ϣ���ı���
		 * ����is_spiteful_message������ֵ����ʶ�û��������Ϣ�Ƿ��ж�����Ϣ��0�������� 1���ж�����Ϣ����
		 * ����advise_forbidden_time������ֵ��0����ʾ�û��������Ϣ��û�ж�����Ϣ�����ý����κδ���
		 * ����0����ʾ�û��������Ϣ�к��ж�����Ϣ������Ը��û����ԣ���ֵ��ʾ����Ľ���ʱ��������Ϊ��λ��
		 * ��������ͬ��
		*/
		bool check_spam_message(
			const string& appkey, const string& appid, 
			const string& openkey, const string& openid, const string& pf,
			const string& userip, 
			const string& ctype,
			const string& content,
			__out string& error_message,
			__out bool& is_spiteful_message,
			__out int& advise_forbidden_time
			);
		/*
		 * Ӧ�õ��ñ��ӿڿ��ж��û��Ƿ�װ�ˡ�QQ���ѡ�Ӧ�ã��Լ��Ƿ��ڡ�QQ���ѡ��п��������ѡ�
		 * Ӧ�ò�֪���û��Ƿ�����QQ���ѹ��ܣ��޷����õ������û�ʹ�����ѣ���������ѿ�չ��Ӫ���
		 * ���ڡ�QQ���ѡ��������ѹ��ܵ����˵���������QQ����������顣 
		 * ���ӿ������̨�ӿ� fusion2.dialog.authReminder �� v3/spread/set_reminder ����ʹ�ã����QQ���ѹ��ܡ�
		 * ע��
		 * ���ӿ�Ŀǰֻ֧��QQ�ռ�ƽ̨�����Ѻ�΢��ƽ̨�ݲ�֧�֡�
		 * 
		 * ����is_setup������true��ʾ�û��Ƿ�װ�ˡ�QQ���ѡ�Ӧ�á�
		 * ����is_enabled������true��ʾ�û������˸�Ӧ�õ����ѹ��ܡ�
		 * ��������ͬ��
		*/
		bool get_is_reminder_set(
			const string& appkey, const string& appid, 
			const string& openkey, const string& openid, const string& pf,
			const string& userip, 
			__out string& error_message,
			__out bool& is_setup,
			__out bool& is_enabled
			);

		typedef struct _reminder_info
		{
			time_t begin_time;	//���ѿ�ʼʱ�䣨unixʱ�����ָ��UTCʱ��1970��1��1��00:00:00����ǰʱ�̵���������
			int key;			//��������ʱ��Ӧ����ĳ��Ŀ��ı�ʶ����Ӧ���Զ��壨��QQũ�������û�ĳ��صĹ�ʵ�����ˣ����ص�id��Ϊkey��ֵ����
			int type;			//��������ʱ�����ѵ����ͣ���Ӧ���Զ��壬������20000���ϵ�������
			char message[128];	//���ѵľ������ݣ�����������30���������ڣ�������չʾ�Ŀ�ȣ�������20���������ڡ�
		}reminder_info, *preminder_info;
		
		/*
		 * ����QQ���ѣ�ע�⣺Ӧ���ڽ���QQ����ʱ��Ҫ����ӿ�Ȩ�ޣ�
		 * �ɹ�����true
		 * QQ������Ϣ�ϱ��ӿڣ���һ���ϱ��������ݣ��������˵���й���X�Ĺ涨����
		 * Ӧ�û���û���Ȩ�����û��������ѣ�����������ȴʱ���淨��Ӧ�ó���������ȡ�����û��������QQ����������顣
		 * ���ӿ�����ӿ� fusion2.dialog.authReminder �� v3/spread/is_reminder_set ����ʹ�ã����QQ���ѹ��ܡ�
		 * ע��
		 * ���ӿ�Ŀǰֻ֧��QQ�ռ�ƽ̨�����Ѻ�΢��ƽ̨�ݲ�֧�֡�
		 * ����������3��������Ϣ
		*/
		bool set_reminder(
			const string& appkey, const string& appid, 
			const string& openkey, const string& openid, const string& pf,
			const string& userip, 
			const vector<reminder_info>& info,
			__out string& error_message
			);

		/*
		 * ����QQ����,����ͬset_reminderһ�����������ڴ˽ӿ�Ϊ������
		 * �����޷�����Ϣ
		*/
		bool set_reminder_for_non_blocking(
			const string& appkey, const string& appid, 
			const string& openkey, const string& openid, const string& pf,
			const string& userip, 
			const vector<reminder_info>& info
			);

//user interface area end--------------------------------

//tencent log interface begin-----------------------------
		
		/*
		 * �ϱ��û���¼Ӧ��ʱ�������Ϣ��������
		 * ����appid,Ӧ�õ�Ψһ��ʶ��AppID�ڴ���Ӧ��ʱ���䡣
		   ����ͨ��APPID����APP������Ϣ��
		   �ڵ���OpenAPI��ʱ��AppID����Ӧ����ݡ�
	     * ����userip,�û�������ip��ַ
		 * ����svrip,�����IPΪ��ǰ�����û�����Ļ���(cgi������server)IP, ��ʹ�������ֽ�������ʶ��������Դ��
		   -hostingӦ�ã��봫����IP��
		   -non-hostingӦ�ã��봫����IP��
	     * ����time,��ǰ�û��Ĳ���ʱ�䣬��ȷ���룬����UNIXʱ�����
		 * ����domain,��ʾAPP����ƽ̨�����������û����ĸ�ҵ��ƽ̨����Ӧ�ã� 
			 QQ�ռ�Ϊ1��
			 ��Ѷ����Ϊ2��
			 ��Ѷ΢��Ϊ3��
			 Q+ƽ̨Ϊ4��
			 �ֻ�QQ�ռ�Ϊ8��
			 �ֻ���Ѷ����Ϊ9��
			 QQGameΪ10��
			 3366Ϊ11��
			 QQGame����Ϊ12��
			 ����Ϊ15��
			 ��Ϸ����Ϊ16��
			 ��Ϸ����Ϊ17��
			 ���磺�û�����Ѷ���ѽ����˸�Ӧ�ã������ֵӦ��2��
		 * ����worldid,�Ƕ������Ӧ�ã�������1��
			 �������Ӧ�ã����������������ID������������ID���½�������ʱ�Զ�����������е�serverid��
			 ��¼��Ѷ����ƽ̨��open.qq.com������롰�ҵĹ������ġ����ڡ�ѡ�����á�tab�������������ɹ��󣬼���������ʽ�Զ�Ϊ�÷�����������һ��������������ʽ���£�
			 s$serverid$.app$appid$.qqopenapp.com 
			 ���磺
			 s3.app12345.qqopenapp.com
			 serverid��������������ID������s3�����3������������ID��
		 * ����opuid,�����ߵ�UID������A͵��B�Ĳˣ�������A��UID��
			 UIDΪӦ��������ʺ���ϵ���û���ID����Ϊint(32)�ͣ����������ַ�����ʽ���롣
		 * ����opopenid,�����ߵ�OpenID������A͵��B�Ĳˣ�������A��OpenID��OpenIDΪ��QQ����һһ��Ӧ���ַ�����
		 * ����level(�Ƽ���),�����û��ĵȼ�����opuid�ĵȼ���
		*/
		bool tencentlog_report_login_for_non_blocking(
			unsigned int appid,
			const string& userip,
			const string& svrip,
			time_t time,
			unsigned int domain,
			unsigned int worldid,
			unsigned int opuid,
			const string& opopenid,
			unsigned int level = 0
			);

		/*
		 * �ϱ��û�����ע��Ӧ��ʱ�������Ϣ��������
		 * ������������ͬtencentlog_report_login_for_non_blocking
		*/
		bool tencentlog_report_register_for_non_blocking(
			unsigned int appid,
			const string& userip,
			const string& svrip,
			time_t time,
			unsigned int domain,
			unsigned int worldid,
			unsigned int opuid,
			const string& opopenid
			);

		/*
		 * �ϱ��û�ͨ��������������ȥע��Ӧ��ʱ�������Ϣ��������
		 * ������������ͬtencentlog_report_login_for_non_blocking
		*/
		bool tencentlog_report_accept_for_non_blocking(
			unsigned int appid,
			const string& userip,
			const string& svrip,
			time_t time,
			unsigned int domain,
			unsigned int worldid,
			unsigned int opuid,
			const string& opopenid
			);

		/*
		 * �ϱ��û���������ע��Ӧ��ʱ�������Ϣ��������
		 * ����touid(�Ƽ���)���������ߵ�UID������B����Aȥע��ĳ��Ӧ�ã�������A��UID��
		   UIDΪӦ��������ʺ���ϵ���û���ID����Ϊint(32)�ͣ����������ַ�����ʽ���롣
		 * ����toopenid(�Ƽ���)���������ߵ�OpenID������B����Aȥע��ĳ��Ӧ�ã�������A��OpenID��
		   �ر�أ�����û�һ���������û������ϱ��������ݡ�
		   OpenIDΪ��QQ����һһ��Ӧ���ַ�����
		 * ������������ͬtencentlog_report_login_for_non_blocking
		*/
		bool tencentlog_report_invite_for_non_blocking(
			unsigned int appid,
			const string& userip,
			const string& svrip,
			time_t time,
			unsigned int domain,
			unsigned int worldid,
			unsigned int opuid,
			const string& opopenid,
			int touid = 0,
			const string& toopenid = ""
			);

		/*
		* �ϱ��û���Ӧ���н���֧�����ѵ������Ϣ��������
		* ֧�����ѣ�
		* �û�ͨ��Q��/Q��ֱ�ӹ�����Ϸ����Ʒ����Ϊ��
		* ���û�ͨ����Ϸ�ڵĵ�ֵ����(���硰��ȯ/���/Ԫ������)��������Ϸ����Ʒ����Ϊ��
		* 
		* ����modifyfee����Ϸ�ұ仯ֵ��
		  �û����в�������Ϸ�ҵı仯ֵ�����û�б仯������0���ϱ���λΪQ�֣�100Q�� = 10Q�� = 1Q�ң���
		  ��Ϸ��Ϊ�û�ͨ������һ���Q��/Q �Ҷһ�����Ϸ�ڵ�ֵ����(���硰��ȯ/���/Ԫ������)������Ϸ�ھ�����ʵ�ļ�ֵ�������ڹ�����Ϸ����Ʒ��
		  ���磺
		  (1)ĳ�û�ͨ��Q��ֱ����Ϸ����Ʒ������10Q�ң������1000��
		  (2)ĳ�û�ͨ����ȯ(��Ϸ��)������Ϸ����Ʒ������10��ȯ(1Q��=100��ȯ)�������100��
		  (3)ĳ�û�ͨ��Q�Ҷһ���ȯ(��Ϸ��)������10Q�ң������1000��
		* ����touid���Ƽ����������֧��ʱ�Է���UID������A��B�û�����ĳ�����ߣ�����дB�û���UID��
		  UIDΪӦ��������ʺ���ϵ���û���ID����Ϊint(32)�ͣ����������ַ�����ʽ���롣
		* ����toopenid���Ƽ����������֧��ʱ�Է���OpenID������A��B�û�����ĳ�����ߣ�����дB�û���OpenID��
		  �ر�أ�����û�һ�β����ж�����������û������ϱ��������ݡ�
		  OpenIDΪ��QQ����һһ��Ӧ���ַ�����
		* ����itemid���Ƽ�����û�������ƷID��
		  �����û�A��������ƷX��������X����ƷID��
		  �ر�أ�����û�һ�β����ж��������item�����ϱ��������ݡ�
		* ����itemtype���Ƽ�����û�������ƷID�ķ��ࡣ
		* ����itemcnt���Ƽ�����û�������Ʒ��������
		  �����û�A������a����ƷX��������a��
		* ����modifyexp���Ƽ�����û����в����󣬾���ֵ�ı仯ֵ��
		  ���繺����ߺ�������300��������300��
		* ����totalexp���Ƽ�����û����в����󣬾���ֵ��������
		  �����û�����1000��������ĳ��Ʒ������ֵ����100���˴�����1100��
		* ����modifycoin���Ƽ�����û����в�������Ϸ�����ҵı仯ֵ��
		  �����û�������ߺ������Ҽ���3000��������-3000��
		* ����totalcoin���Ƽ�����û����в����������ҵ�������
		  �����û�ӵ��������100��������ĳ��Ʒ������������10���˴�����90��
		* ����totalfee���Ƽ�����û����в�������Ϸ�ҵ�������
		  �����û�ӵ����Ϸ��100��������ĳ��Ʒ��������Ϸ��10���˴�����90��
		* ����level���Ƽ���������û��ĵȼ�����opuid�ĵȼ���
		* ��������ͬtencentlog_report_login_for_non_blocking
		*/
		 
		bool tencentlog_report_consume_for_non_blocking(
			unsigned int appid,
			const string& userip,
			const string& svrip,
			time_t time,
			unsigned int domain,
			unsigned int worldid,
			unsigned int opuid,
			const string& opopenid,
			unsigned int modifyfee,
			unsigned int touid = 0,
			const string& toopenid = "",
			const string& itemid = "",
			const string& itemtype = "",
			unsigned int itemcnt = 0,
			unsigned int modifyexp = 0,
			unsigned int totalexp = 0,
			int modifycoin = 0,
			unsigned int totalcoin = 0,
			unsigned int totalfee = 0,
			unsigned int level = 0
			);

		/*
		 * �ϱ��û���Ӧ���н���֧����ֵ�������Ϣ��������
		   ֧����ֵ��
		   �û�ͨ��Q��/Q�Ҷһ���Ϸ�ڵ�ֵ����(���硰��ȯ/���/Ԫ����)����Ϊ��
		 * ����touid���Ƽ�����ڳ�ֵʱ�Է���UID������A��B�û���ֵ������дB�û���UID��
		   UIDΪӦ��������ʺ���ϵ���û���ID����Ϊint(32)�ͣ����������ַ�����ʽ���롣
		 * ����toopenid���Ƽ�����ڳ�ֵʱ�Է���OpenID������A��B�û���ֵ������дB�û���OpenID��
		   �ر�أ�����û�һ�β����ж�����������û������ϱ��������ݡ�
		   OpenIDΪ��QQ����һһ��Ӧ���ַ�����
		 * ����itemid���Ƽ�����û�������ƷID��
		   �����û�A�һ�����Ϸ�ڵ�Ԫ����������Ԫ����ID��
		   �ر�أ�����û�һ�β����ж��������item�����ϱ��������ݡ�
		 * ����itemtype���Ƽ�����û�������ƷID�ķ��ࡣ
		 * ����itemcnt���Ƽ�����û�������Ʒ��������
		   �����û�A������a����ƷX��������a��
		 * ����modifyexp���Ƽ�����û����в����󣬾���ֵ�ı仯ֵ��
		   ����һ�Ԫ����������300��������300��
		 * ����totalexp���Ƽ�����û����в����󣬾���ֵ��������
		   �����û�����1000���һ���Ԫ���󣬾���ֵ����100���˴�����1100��
		 * ����modifycoin���Ƽ�����û����в�������Ϸ�����ҵı仯ֵ��
		   �����û��һ���Һ�����������3000��������3000��
		 * ����totalcoin���Ƽ�����û����в����������ҵ�������
		   �����û�ӵ��������100��ͨ��Q��/Q�Ҷһ���10����ң��˴�����110��
		 * ����totalfee���Ƽ�����û����в�������Ϸ�ҵ�������
		   �����û�ӵ����Ϸ��100��������ĳ��Ʒ��������Ϸ��10���˴�����90��
		 * ����level���Ƽ���������û��ĵȼ�����opuid�ĵȼ���
	     * ��������ͬtencentlog_report_consume_for_non_blocking�ӿ�
		*/
		bool tencentlog_report_recharge_for_non_blocking(
			unsigned int appid,
			const string& userip,
			const string& svrip,
			time_t time,
			unsigned int domain,
			unsigned int worldid,
			unsigned int opuid,
			const string& opopenid,
			unsigned int modifyfee,
			unsigned int touid = 0,
			const string& toopenid = "",
			const string& itemid = "",
			const string& itemtype = "",
			unsigned int itemcnt = 0,
			unsigned int modifyexp = 0,
			unsigned int totalexp = 0,
			int modifycoin = 0,
			unsigned int totalcoin = 0,
			unsigned int totalfee = 0,
			unsigned int level = 0
			);

		/*
		 * �ϱ��û��˳�Ӧ��ʱ�������Ϣ��������
		 * ����onlinetime���û����ε�¼������ʱ����
		 * ����level�������û��ĵȼ�����opuid�ĵȼ���
		 * ��������ͬtencentlog_report_login_for_non_blocking�ӿ�
		*/
		bool tencentlog_report_quit_for_non_blocking(
			unsigned int appid,
			const string& userip,
			const string& svrip,
			time_t time,
			unsigned int domain,
			unsigned int worldid,
			unsigned int opuid,
			const string& opopenid,
			unsigned int onlinetime,
			unsigned int level = 0
			);

//tencent log interface end-----------------------------

		//����������ַ
		void set_host(const string& host);

		//���ö˿ں�
		void set_port(int port);


	protected:
		/*
		 * ����http��������json�������ݣ�ֻ�������ݲ���
		 * �ɹ�����true������ֵ��data_pair��
		**/
		bool parse_http_response_json_data(const string& response_data, __out map<string,string>& data_pair);

		/*
		 * �����ֵ�Ե�ֵ�����ز������ӣ���:a=1&b=%2D��ע�⣺ֻ��ֵ���б���
		**/
		string encode_value_of_pair_and_join(const map<string,string>& paramter_pair);

	private:
		//��������
		string m_host;

		//����˿�
		int m_port;
		
		

	};





}	//namespace LY



#endif	//_MYSOCKET_H_