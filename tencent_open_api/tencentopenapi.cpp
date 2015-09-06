// tencentopenapi.cpp : Defines the exported functions for the DLL application.
//

#include "tencentopenapi.h"
#include "mysocket.h"

/*
 * �ϱ��û���¼Ӧ��ʱ�������Ϣ��������
 * ����˵������ο�LY::CTencentOpenAPI::tencentlog_report_login_for_non_blocking�ӿ�
*/
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
	unsigned int level /* = 0 */
	)
{
	assert(host!=NULL);
	assert(userip!=NULL);
	assert(svrip!=NULL);
	assert(opopenid!=NULL);
	LY::CTencentOpenAPI open_api(host, port);
	return open_api.tencentlog_report_login_for_non_blocking(appid, userip, svrip, time, domain, worldid, opuid, opopenid,level);
}

/*
 * �ϱ��û�����ע��Ӧ��ʱ�������Ϣ��������
 * ����˵������ο�LY::CTencentOpenAPI::tencentlog_report_register_for_non_blocking�ӿ�
*/
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
	)
{
	assert(host!=NULL);
	assert(userip!=NULL);
	assert(svrip!=NULL);
	assert(opopenid!=NULL);
	LY::CTencentOpenAPI open_api(host, port);
	return open_api.tencentlog_report_register_for_non_blocking(appid,userip,svrip,time,domain,worldid,opuid,opopenid);
}

/*
 * �ϱ��û�ͨ��������������ȥע��Ӧ��ʱ�������Ϣ��������
 * ����˵������ο�LY::CTencentOpenAPI::tencentlog_report_accept_for_non_blocking�ӿ�
*/
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
	)
{
	assert(host!=NULL);
	assert(userip!=NULL);
	assert(svrip!=NULL);
	assert(opopenid!=NULL);
	LY::CTencentOpenAPI open_api(host, port);
	return open_api.tencentlog_report_accept_for_non_blocking(appid,userip,svrip,time,domain,worldid,opuid,opopenid);
}

/*
 * �ϱ��û���������ע��Ӧ��ʱ�������Ϣ��������
 * ����˵������ο�LY::CTencentOpenAPI::tencentlog_report_invite_for_non_blocking�ӿ�
*/
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
	int touid /* = 0 */,
	const char* toopenid /* = NULL */
	)
{
	assert(host!=NULL);
	assert(userip!=NULL);
	assert(svrip!=NULL);
	assert(opopenid!=NULL);
	string s_toopenid;
	if (toopenid != NULL)
		s_toopenid = toopenid;
	LY::CTencentOpenAPI open_api(host, port);
	return open_api.tencentlog_report_invite_for_non_blocking(appid,userip,svrip,time,domain,worldid,opuid,opopenid,touid,s_toopenid);
}

/*
 * �ϱ��û���Ӧ���н���֧�����ѵ������Ϣ��������
 * ����˵������ο�LY::CTencentOpenAPI::tencentlog_report_consume_for_non_blocking�ӿ�
*/
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
	unsigned int touid /* = 0 */,
	const char * toopenid /* = NULL */,
	const char * itemid /* = NULL */,
	const char * itemtype /* = NULL */,
	unsigned int itemcnt /* = 0 */,
	unsigned int modifyexp /* = 0 */,
	unsigned int totalexp /* = 0 */,
	int modifycoin /* = 0 */,
	unsigned int totalcoin /* = 0 */,
	unsigned int totalfee /* = 0 */,
	unsigned int level /* = 0 */
	)
{
	assert(host!=NULL);
	assert(userip!=NULL);
	assert(svrip!=NULL);
	assert(opopenid!=NULL);

	string s_toopenid,s_itemid,s_itemtype;
	if (toopenid!= NULL)
	{
		s_toopenid = toopenid;
	}
	if (itemid!= NULL)
	{
		s_itemid = itemid;
	}
	if (itemtype!= NULL)
	{
		s_itemtype = itemtype;
	}
	LY::CTencentOpenAPI open_api(host, port);
	return open_api.tencentlog_report_consume_for_non_blocking(appid,userip,svrip,time,domain,worldid,opuid,opopenid,
		modifyfee,touid,s_toopenid,s_itemid,s_itemtype,itemcnt,modifyexp,totalexp,modifycoin,totalcoin,totalfee,level);
}

/*
 * �ϱ��û���Ӧ���н���֧����ֵ�������Ϣ��������
 * ����˵������ο�LY::CTencentOpenAPI::tencentlog_report_recharge_for_non_blocking�ӿ�
*/
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
	unsigned int touid /* = 0 */,
	const char * toopenid /* = NULL */,
	const char * itemid /* = NULL */,
	const char * itemtype /* = NULL */,
	unsigned int itemcnt /* = 0 */,
	unsigned int modifyexp /* = 0 */,
	unsigned int totalexp /* = 0 */,
	int modifycoin /* = 0 */,
	unsigned int totalcoin /* = 0 */,
	unsigned int totalfee /* = 0 */,
	unsigned int level /* = 0 */
	)
{
	assert(host!=NULL);
	assert(userip!=NULL);
	assert(svrip!=NULL);
	assert(opopenid!=NULL);
	string s_toopenid, s_itemid, s_itemtype;
	if (toopenid!= NULL)
	{
		s_toopenid = toopenid;
	}
	if (itemid!= NULL)
	{
		s_itemid = itemid;
	}
	if (itemtype!= NULL)
	{
		s_itemtype = itemtype;
	}
	LY::CTencentOpenAPI open_api(host, port);
	return open_api.tencentlog_report_recharge_for_non_blocking(appid, userip, svrip,time,domain,worldid,
		opuid,opopenid,modifyfee,touid,s_toopenid,s_itemid,s_itemtype,itemcnt,modifyexp,totalexp,modifycoin,
		totalcoin,totalfee,level);

}

/*
 * �ϱ��û��˳�Ӧ��ʱ�������Ϣ��������
 * ����˵������ο�LY::CTencentOpenAPI::tencentlog_report_quit_for_non_blocking�ӿ�
*/
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
	unsigned int level /* = 0 */
	)
{
	assert(host!=NULL);
	assert(userip!=NULL);
	assert(svrip!=NULL);
	assert(opopenid!=NULL);
	LY::CTencentOpenAPI open_api(host, port);
	return open_api.tencentlog_report_quit_for_non_blocking(appid, userip, svrip, time, domain, worldid, opuid,
		opopenid,onlinetime,level);

}

/*
 * Ӧ�õ��ñ��ӿڿ��ж��û��Ƿ�װ�ˡ�QQ���ѡ�Ӧ�ã��Լ��Ƿ��ڡ�QQ���ѡ��п��������ѡ�
 * ����˵������ο�LY::CTencentOpenAPI::get_is_reminder_set�ӿ�
*/
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
	)
{
	assert(host != NULL);
	assert(appkey != NULL);
	assert(appid != NULL);
	assert(openkey != NULL);
	assert(openid != NULL);
	assert(pf != NULL);	

	assert(error_message != NULL);		
	assert(is_setup != NULL);
	assert(is_enabled != NULL);

	string s_userip;	//useripΪ��ѡ��
	if (userip != NULL)
	{
		s_userip = userip;
	}
	string s_error_message;

	LY::CTencentOpenAPI open_api(host, port);
	bool ret = open_api.get_is_reminder_set(appkey, appid, openkey, openid, pf, s_userip,
		s_error_message, *is_setup, *is_enabled);

	strcpy_s(error_message,error_message_size, s_error_message.c_str());
	//printf("%s\n", error_message);

	return ret;
}

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
	)
{
	assert(host != NULL);
	assert(appkey != NULL);
	assert(appid != NULL);
	assert(openkey != NULL);
	assert(openid != NULL);
	assert(pf != NULL);	
	assert(error_message != NULL);	
	string s_userip;	//useripΪ��ѡ��
	if (userip != NULL)
	{
		s_userip = userip;
	}
	vector<LY::CTencentOpenAPI::reminder_info> v_info;

	for (int i=0; i < (info_size > 3 ? 3: info_size); i++,info++)
	{
		v_info.push_back(*info);
	}
	LY::CTencentOpenAPI open_api(host, port);
	string str_err_msg;

	bool ret = open_api.set_reminder(appkey,appid,openkey,openid,pf,s_userip,v_info,str_err_msg);
	strcpy_s(error_message, error_message_size, str_err_msg.c_str());
	return ret;
}

/*
 * ����QQ����,�˽ӿ�Ϊ������
 * ����˵������ο�LY::CTencentOpenAPI::set_reminder_for_non_blocking�ӿ�
*/
bool set_reminder_for_non_blocking_for_c(
    const char * host,
    int port,
	const char * appkey, const char * appid, 
	const char * openkey, const char * openid, const char * pf,
	const char * userip, 
	const LY::CTencentOpenAPI::reminder_info* info,
	int info_size
	)
{
	assert(host != NULL);
	assert(appkey != NULL);
	assert(appid != NULL);
	assert(openkey != NULL);
	assert(openid != NULL);
	assert(pf != NULL);	
	string s_userip;	//useripΪ��ѡ��
	if (userip != NULL)
	{
		s_userip = userip;
	}
	vector<LY::CTencentOpenAPI::reminder_info> v_info;
	
	for (int i=0; i < (info_size > 3 ? 3: info_size); i++,info++)
	{
		v_info.push_back(*info);
	}	

	LY::CTencentOpenAPI open_api(host, port);
	return open_api.set_reminder_for_non_blocking(appkey,appid,openkey,openid,pf,s_userip,v_info);

}

bool get_vip_user_info_for_c( const char * host, int port, 
							 const char *appkey, const char *appid, 
							 const char *openkey, const char *openid, 
							 const char *pf, const char *userip, 
							 char *error_message, int error_message_size, 
							 bool *is_yellow_vip, bool *is_yellow_year_vip, 
							 int *yellow_vip_level, bool *is_yellow_high_vip, 
							 int *yellow_vip_pay_way )
{
	assert(host != NULL);
	assert(appkey != NULL);
	assert(appid != NULL);
	assert(openkey != NULL);
	assert(openid != NULL);
	assert(pf != NULL);	
	assert(error_message != NULL);	
	string s_userip;	//useripΪ��ѡ��
	if (userip != NULL)
	{
		s_userip = userip;
	}
	LY::CTencentOpenAPI open_api(host, port);
	string str_err_msg;
	bool ret = open_api.get_vip_user_info(appkey,appid,openkey,openid,pf,s_userip,str_err_msg,*is_yellow_vip,
		*is_yellow_year_vip,*yellow_vip_level,*is_yellow_high_vip,*yellow_vip_pay_way);
	strcpy_s(error_message, error_message_size, str_err_msg.c_str());
	return ret;
}

bool get_user_is_setup_for_c(
							 const char * host,
							 int port,
							 const char *appkey, const char *appid, 
							 const char *openkey, const char *openid, const char *pf,
							 const char *userip,
							 char *error_message,
							 int error_message_size,
							 bool *is_setuped
							 )
{
	assert(host != NULL);
	assert(appkey != NULL);
	assert(appid != NULL);
	assert(openkey != NULL);
	assert(openid != NULL);
	assert(pf != NULL);	
	assert(error_message != NULL);	
	string s_userip;	//useripΪ��ѡ��
	if (userip != NULL)
	{
		s_userip = userip;
	}
	LY::CTencentOpenAPI open_api(host, port);
	string str_err_msg;
	bool ret = open_api.get_user_is_setup(appkey,appid,openkey,openid,pf,s_userip,str_err_msg,*is_setuped);
	strcpy_s(error_message, error_message_size, str_err_msg.c_str());
	return ret;
}

bool get_user_is_login_for_c(
							 const char * host,
							 int port,
							 const char *appkey, const char *appid, 
							 const char *openkey, const char *openid, const char *pf,
							 const char *userip,
							 char *error_message,
							 int error_message_size,
							 bool *is_login
							 )
{
	assert(host != NULL);
	assert(appkey != NULL);
	assert(appid != NULL);
	assert(openkey != NULL);
	assert(openid != NULL);
	assert(pf != NULL);	
	assert(error_message != NULL);	
	string s_userip;	//useripΪ��ѡ��
	if (userip != NULL)
	{
		s_userip = userip;
	}
	LY::CTencentOpenAPI open_api(host, port);
	string str_err_msg;
	bool ret = open_api.get_user_is_login(appkey,appid,openkey,openid,pf,s_userip,str_err_msg,*is_login);
	strcpy_s(error_message, error_message_size, str_err_msg.c_str());
	return ret;
}

bool get_is_area_login_for_c(
							 const char * host,
							 int port,
							 const char *appkey, const char *appid, 
							 const char *openkey, const char *openid, const char *pf,
							 const char *userip, const char *seqid,
							 char *error_message,
							 int error_message_size,
							 bool *is_area_login
							 )
{
	assert(host != NULL);
	assert(appkey != NULL);
	assert(appid != NULL);
	assert(openkey != NULL);
	assert(openid != NULL);
	assert(pf != NULL);	
	assert(seqid != NULL);	
	assert(error_message != NULL);
	string s_userip;	//useripΪ��ѡ��
	if (userip != NULL)
	{
		s_userip = userip;
	}
	LY::CTencentOpenAPI open_api(host, port);
	string str_err_msg;
	bool ret = open_api.get_is_area_login(appkey,appid,openkey,openid,pf,s_userip,seqid,str_err_msg,*is_area_login);
	strcpy_s(error_message, error_message_size, str_err_msg.c_str());
	return ret;
}

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
							 )
{
	assert(host != NULL);
	assert(appkey != NULL);
	assert(appid != NULL);
	assert(openkey != NULL);
	assert(openid != NULL);
	assert(pf != NULL);	
	assert(content != NULL);	
	assert(msgid != NULL);
	assert(message != NULL);
	string s_userip;	//useripΪ��ѡ��
	if (userip != NULL)
	{
		s_userip = userip;
	}
	LY::CTencentOpenAPI open_api(host, port);
	string msg;
	bool ret = open_api.check_word_filter(appkey,appid,openkey,openid,pf,s_userip,content,msgid,msg,*is_dirty);
	strcpy_s(message, message_size, msg.c_str());
	return ret;
}

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
							  )
{
	assert(host != NULL);
	assert(appkey != NULL);
	assert(appid != NULL);
	assert(openkey != NULL);
	assert(openid != NULL);
	assert(pf != NULL);	
	assert(content != NULL);	
	assert(error_message != NULL);
	string s_userip;	//useripΪ��ѡ��
	if (userip != NULL)
	{
		s_userip = userip;
	}
	LY::CTencentOpenAPI open_api(host, port);
	string str_err_msg;
	bool ret = open_api.check_spam_message(appkey,appid,openkey,openid,pf,userip,ctype,content,
		str_err_msg,*is_spiteful_message, *advise_forbidden_time);
	strcpy_s(error_message, error_message_size, str_err_msg.c_str());
	return ret;
}