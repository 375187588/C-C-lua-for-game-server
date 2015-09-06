#ifndef _TENCENTOPENAPI_H_
#define _TENCENTOPENAPI_H_


#include "mysocket.h"

//Ϊlua���ã���Ƶ�C�ӿ�

/*
 * �ϱ��û���¼Ӧ��ʱ�������Ϣ��������
 * ����˵������ο�LY::CTencentOpenAPI::tencentlog_report_login_for_non_blocking�ӿ�
*/
extern "C"
bool tencentlog_report_login_for_non_blocking_for_c(
	const char * host,
	int port,
	unsigned int appid,
	const char* userip,
	const char* svrip,
	time_t time,
	unsigned int domain,
	unsigned int worldid,
	unsigned int opuid,
	const char* opopenid,
	unsigned int level = 0
	);

/*
 * �ϱ��û�����ע��Ӧ��ʱ�������Ϣ��������
 * ����˵������ο�LY::CTencentOpenAPI::tencentlog_report_register_for_non_blocking�ӿ�
*/
extern "C"
bool tencentlog_report_register_for_non_blocking_for_c(
	const char * host,
	int port,
	unsigned int appid,
	const char* userip,
	const char* svrip,
	time_t time,
	unsigned int domain,
	unsigned int worldid,
	unsigned int opuid,
	const char* opopenid
	);

/*
 * �ϱ��û�ͨ��������������ȥע��Ӧ��ʱ�������Ϣ��������
 * ����˵������ο�LY::CTencentOpenAPI::tencentlog_report_accept_for_non_blocking�ӿ�
*/
extern "C"
bool tencentlog_report_accept_for_non_blocking_for_c(
	const char * host,
	int port,
	unsigned int appid,
	const char* userip,
	const char* svrip,
	time_t time,
	unsigned int domain,
	unsigned int worldid,
	unsigned int opuid,
	const char* opopenid
	);

/*
 * �ϱ��û���������ע��Ӧ��ʱ�������Ϣ��������
 * ����˵������ο�LY::CTencentOpenAPI::tencentlog_report_invite_for_non_blocking�ӿ�
*/
extern "C"
bool tencentlog_report_invite_for_non_blocking_for_c(
	const char * host,
	int port,
	unsigned int appid,
	const char* userip,
	const char* svrip,
	time_t time,
	unsigned int domain,
	unsigned int worldid,
	unsigned int opuid,
	const char* opopenid,
	int touid = 0,
	const char* toopenid = NULL
	);

/*
 * �ϱ��û���Ӧ���н���֧�����ѵ������Ϣ��������
 * ����˵������ο�LY::CTencentOpenAPI::tencentlog_report_consume_for_non_blocking�ӿ�
*/
extern "C"
bool tencentlog_report_consume_for_non_blocking_for_c(
	const char * host,
	int port,
	unsigned int appid,
	const char * userip,
	const char * svrip,
	time_t time,
	unsigned int domain,
	unsigned int worldid,
	unsigned int opuid,
	const char * opopenid,
	unsigned int modifyfee,
	unsigned int touid = 0,
	const char * toopenid = NULL,
	const char * itemid = NULL,
	const char * itemtype = NULL,
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
 * ����˵������ο�LY::CTencentOpenAPI::tencentlog_report_recharge_for_non_blocking�ӿ�
*/
extern "C"
bool tencentlog_report_recharge_for_non_blocking_for_c(
	const char * host,
	int port,
	unsigned int appid,
	const char * userip,
	const char * svrip,
	time_t time,
	unsigned int domain,
	unsigned int worldid,
	unsigned int opuid,
	const char * opopenid,
	unsigned int modifyfee,
	unsigned int touid = 0,
	const char * toopenid = NULL,
	const char * itemid = NULL,
	const char * itemtype = NULL,
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
 * ����˵������ο�LY::CTencentOpenAPI::tencentlog_report_quit_for_non_blocking�ӿ�
*/
extern "C"
bool tencentlog_report_quit_for_non_blocking_for_c(
	const char * host,
	int port,
	unsigned int appid,
	const char * userip,
	const char * svrip,
	time_t time,
	unsigned int domain,
	unsigned int worldid,
	unsigned int opuid,
	const char * opopenid,
	unsigned int onlinetime,
	unsigned int level = 0
	);

/*
 * Ӧ�õ��ñ��ӿڿ��ж��û��Ƿ�װ�ˡ�QQ���ѡ�Ӧ�ã��Լ��Ƿ��ڡ�QQ���ѡ��п��������ѡ�
 * ����˵������ο�LY::CTencentOpenAPI::get_is_reminder_set�ӿ�
*/
extern "C"
bool get_is_reminder_set_for_c(
    const char * host,
    int port,
	const char * appkey, const char * appid, 
	const char * openkey, const char * openid, const char * pf,
	const char * userip, 
	__out char * error_message,
	int error_message_size,
	__out bool* is_setup,
	__out bool* is_enabled
	);

/*
 * ����QQ���ѣ�ע�⣺Ӧ���ڽ���QQ����ʱ��Ҫ����ӿ�Ȩ�ޣ�
 * ���ͳɹ�����true��ʧ�ܷ���false
 * ����˵������ο�LY::CTencentOpenAPI::set_reminder�ӿ�
*/
extern "C"
bool set_reminder_for_c(
	const char * host,
	int port,
	const char *appkey, const char *appid, 
	const char *openkey, const char *openid, const char *pf,
	const char *userip, 
	const LY::CTencentOpenAPI::reminder_info* info,
	int info_size,
	char *error_message,
	int error_message_size
	);

/*
 * ����QQ����,�˽ӿ�Ϊ������
 * ����infoΪָ��reminder_info�ṹ��������׵�ַ
 * ����info_size��Ϊreminder_info�ṹ��ĸ��������ֵΪ3
 * ��������˵������ο�LY::CTencentOpenAPI::set_reminder_for_non_blocking�ӿ�
*/
extern "C"
bool set_reminder_for_non_blocking_for_c(
    const char * host,
    int port,
	const char * appkey, const char * appid, 
	const char * openkey, const char * openid, const char * pf,
	const char * userip, 
	const LY::CTencentOpenAPI::reminder_info* info,
	int info_size
	);

//����C�ӿڲ���Ҫlua�ӿ�---------------------------------

/*
 * �ӿڹ���Ϊ��ȡ�û���Ϣ��ע�⣺����ֵ��ʾ�Ƿ�ִ�гɹ�
 * ����˵������ο�LY::CTencentOpenAPI::get_vip_user_info�ӿ�
*/
extern "C"
bool get_vip_user_info_for_c(
	const char * host,
	int port,
	const char *appkey, const char *appid, 
	const char *openkey, const char *openid, const char *pf,
	const char *userip,
	char *error_message,
	int error_message_size,
	bool *is_yellow_vip,		
	bool *is_yellow_year_vip, 
	int *yellow_vip_level,	
	bool *is_yellow_high_vip,	
	int *yellow_vip_pay_way
	);

/*
 * ��֤��¼�û��Ƿ�װ��Ӧ�á�ע�⣺����ֵ��ʾ�Ƿ�ִ�гɹ�
 * ����˵������ο�LY::CTencentOpenAPI::get_user_is_setup�ӿ�
**/
extern "C"
bool get_user_is_setup_for_c(
	const char * host,
	int port,
	const char *appkey, const char *appid, 
	const char *openkey, const char *openid, const char *pf,
	const char *userip,
	char *error_message,
	int error_message_size,
	bool *is_setuped
	);

/*
 * ��֤�û��ĵ�¼̬���ж�openkey�Ƿ���ڣ�û�й������openkey��Ч�ڽ������ڣ�һ�ε�������2Сʱ����
 * ����˵������ο�LY::CTencentOpenAPI::get_user_is_login�ӿ�
*/
extern "C"
bool get_user_is_login_for_c(
	const char * host,
	int port,
	const char *appkey, const char *appid, 
	const char *openkey, const char *openid, const char *pf,
	const char *userip,
	char *error_message,
	int error_message_size,
	bool *is_login
	);

/*
 * ���ӿڽ������ڶ������Ӧ�ã�������֤�û���¼̬������֤openkey�����Լ���֤�û��Ƿ��ѡ��ҳ�棨����֤seqid������Ӧ�á�
 * ����˵������ο�LY::CTencentOpenAPI::get_is_area_login�ӿ�
*/
extern "C"
bool get_is_area_login_for_c(
	const char * host,
	int port,
	const char *appkey, const char *appid, 
	const char *openkey, const char *openid, const char *pf,
	const char *userip, const char *seqid,
	char *error_message,
	int error_message_size,
	bool *is_area_login
	);

/*
 * ����ı����Ƿ�������дʣ���������Ӧ�Ĵ���
 * ����˵������ο�LY::CTencentOpenAPI::check_word_filter�ӿ�
*/
extern "C"
bool check_word_filter_for_c(
	const char * host,
	int port,
	const char *appkey, const char *appid, 
	const char *openkey, const char *openid, const char *pf,
	const char *userip, 
	const char *content,
	const char *msgid,
	char *message,
	int message_size,
	bool *is_dirty
	);

/*
 * ��������Ϊ������Ϣ���
 * ����˵������ο�LY::CTencentOpenAPI::check_spam_message�ӿ�
*/
extern "C"
bool check_spam_message_for_c(
	const char * host,
	int port,
	const char *appkey, const char *appid, 
	const char *openkey, const char *openid, const char *pf,
	const char *userip, 
	const char *ctype,
	const char *content,
	char *error_message,
	int error_message_size,
	bool *is_spiteful_message,
	int *advise_forbidden_time
	);


#endif	//_TENCENTOPENAPI_H_