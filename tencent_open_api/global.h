#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <string>
#include <vector>

using namespace std;


namespace LY
{
	//�ж��Ƿ��Ǵ�����
	bool g_is_number(const string& str);

	/*
	 * ���ַ���ֱ��until_string�ַ���������until_string�ַ���
	 * ���û�з���until_string�ַ������򷵻ؿմ�
	*/
	string g_read_string_until(const string& str, int start, const string& until_string);

	//base64����
	bool g_base64_encode(const string& src_data, __out string& out_data);

	//ת��Ϊ��д
	void g_to_upper(__inout string &data);

	//ת��ΪСд
	void g_to_lower(__inout string &data);

	//�ָ��ַ���,�����lists�У����طָ��ĸ�����
	//ע�⣺split_string���������ͬ�ָ����ÿһ���ַ���ʾһ���ָ���
	int g_extract_string(const string& src_data,  char* split_string, __out vector<string>& lists);

	//����ת�ַ���, radix��ʾ����,ֵΪ2-36
	string g_int_to_str(int value , int radix = 10);
	
	//�޷�������ת�ַ���, radix��ʾ����,ֵΪ2-36
	string g_int_to_str(unsigned int value, int radix = 10);
	
	//64λ����ת�ַ���, radix��ʾ����,ֵΪ2-36
	string g_int_to_str(__int64 value, int radix = 10);

	//�ַ���ת����
	int g_str_to_int(const string & value);

	//�ַ���ת64λ����
	__int64 g_str_to_int64(const string& value);

	//ascii�ַ�ת��Ϊutf8����
	string g_ascii_to_utf8(const string& value);

	//utf8����ת��Ϊascii�ַ�
	string g_utf8_to_ascii(const string& value);


}	//namespace LY


#endif	//_GLOBAL_H_