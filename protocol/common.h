#pragma once
#include "define.h"

enum UsersListType {kFriend=0,kFoe=1,kAlly=2,kObserver=3};
enum GetUserInfoType { kUserID=0 };

struct _User
{
	Role role;
	int16_t level;
	int16_t country;
	int32_t guild_id;
};
struct UsersList
{
	static const uint32_t kMaxPersonsCount = 50;
	int16_t type;
	int16_t len;
	_User users[kMaxPersonsCount];
};

struct Mail
{
	static const StringLength kSubjectLen = 62; //20*3+2;
	static const StringLength kContentLen = 470; //140*3+2;
	UserID	receiver_uid;	//�ռ���uid
	struct Title
	{
		StringLength	len;
		char			str[kSubjectLen];
	}subject;
	struct Content
	{
		StringLength	len;
		char			str[kContentLen];
	}content;
};

enum class CommonType : int16_t
{
	kHeartBeat = 0,
	kTypeBegin = 1000,
	kLogin = kTypeBegin+1,
	kRegister = kTypeBegin+2,
	//
	kIsUidExist = 1003,
	kIsUidExistResult,
	kIsNicknameExist,
	kIsNicknameExistResult,

	kTextTo=3, //����������Ϣ
	kTextFrom,
	kWhisperTo, //˽��
	kWhisperFrom,
	kAddFriend,
	kAddFriendResult,
	kNotifyOfAddFriend,
	kRemoveFriend,
	kRemoveFriendResult,
	kAddFoe,
	kAddFoeResult,
	kRemoveFoe,
	kRemoveFoeResult,
	kGetAssociatedUsersList,
	kAssociatedUsersListResult, //���ѡ�������������(����)��Ա
	kGetUserIDByName,
	kUserIDResult,
	kTextToResult,
	kWhisperToResult,

	kNotifyPlayerBaseInfo,

	kGetAntiAddictionInfo = kTypeBegin+186,			//��ȡ��������Ϣ
	kGetAntiAddictionInfoResult = kTypeBegin+187,	//
	kProveAntiAddictionInfo = kTypeBegin+188,		//��֤��������Ϣ
	kProveAntiAddictionInfoResult = kTypeBegin+189,	//��֤���

	kNotifyAntiAddictionShutdown = kTypeBegin+190,	//�ﵽ����ʱ��,����֪ͨ
	kNotifyAntiAddictionInfo = kTypeBegin+191,		//������Ϣ֪ͨ,֪ͨ��Ϊ����
	
	kExit = kTypeBegin+199,

//------------------------------------------------------
	kReturnStart = kTypeBegin+200,
	kLoginReturn = kReturnStart+2,
	kAnotherLoginNotify = kReturnStart+3,
	kRegisterResult = kReturnStart+4,

//-----------------------------------------------------
	kPlayerSendMail = kTypeBegin+300,
	kSystemSendMail,
	kPlayerSendMailResult,
	kNotifyOfNewMail,
	kGetMailsList,
	kMailsListResult,
	kGetMailNums,
	kMailNumsResult,
	kGetMail,
	kMailResult,
	kDeleteMail,
	kDeleteMailResult,
	kExtractAttachment,
	kExtractAttachmentResult,
	
	kMax = kTypeBegin+1000
};

//c2s = �ͻ��˷��������
//s2c = ����˷����ͻ���
namespace p
{

//����
struct Heartbeat
{
	static const int16_t kType = (int16_t)CommonType::kHeartBeat;
};

//��¼
struct Login //c2s
{
	static const int16_t kType = (int16_t)CommonType::kLogin;
	UserID uid; //user id
	StringLength key_len;
	char key[34];  //34Ϊ��󳤶�
};

struct LoginReturn //s2c
{
	static const int16_t kType = (int16_t)CommonType::kLoginReturn;
	enum Result:int32_t { kSucceeded=0, 
						  kFailed=1, 
						  kUserIDNotRegistered=2, 
						  kGetAddictionInfoFailed=3,		//��ȡ��������Ϣʧ��
						  kInAddictionTime=4,				//����ʱ����
						  kBanLogin=5						//��ֹ��¼,���类GM�߳�,һ��ʱ���ڽ�ֹ��¼
						};
	Result error; //�㶨Ϊ0
	Result result;
	int32_t now; //��������ǰʱ��
	int32_t version;
};

struct AnotherLoginNotify
{
	static const int16_t kType = (int16_t)CommonType::kAnotherLoginNotify;
}; 

struct Register //ע��
{ 
	static const Type kType = (int16_t)CommonType::kRegister;
	UserID uid;
	Nickname name;
	int8_t sex;
};
typedef struct Register Register;

struct RegisterResult
{ 
	static const Type kType = (int16_t)CommonType::kRegisterResult;
	enum Result:int32_t{kSucceeded=0, kFailed=1,kInvalidValue=2,kNicknameExist=3,kUidExist=4};
	Result error; //�㶨Ϊ0
	Result result; //ǰ�涨���ֵ
};
typedef struct RegisterResult RegisterResult;

struct IsUidExist
{
	static const Type kType = (int16_t)CommonType::kIsUidExist;
	UserID uid;
};

struct IsUidExistResult
{
	static const Type kType = (int16_t)CommonType::kIsUidExistResult;
	enum Result:int32_t { kUidNotExist=0, kUidExist=1 };
	Result error; //�㶨Ϊ0
	Result result;
};

struct IsNicknameExist
{
	static const Type kType = (int16_t)CommonType::kIsNicknameExist;
	Nickname name;
};

struct IsNicknameExistResult
{
	static const Type kType = (int16_t)CommonType::kIsNicknameExistResult;
	bool b_exist;	//true: exist
};

struct GetAntiAddictionInfo
{
	static const Type kType = (int16_t)CommonType::kGetAntiAddictionInfo;
};

struct GetAntiAddictionInfoResult
{
	static const Type kType = (int16_t)CommonType::kGetAntiAddictionInfoResult;
	int32_t online_time;		//�ۼ�����ʱ��(��)
	int32_t b_anti;				//0Ϊ��ͨ����������֤,   1δͨ��
};

struct NotifyAntiAddictionShutdown
{
	static const Type kType = (int16_t)CommonType::kNotifyAntiAddictionShutdown;
};

struct NotifyAntiAddictionInfo
{
	static const Type kType = (int16_t)CommonType::kNotifyAntiAddictionInfo;
	int32_t online_time;	//�ۼ�����ʱ��
	int32_t b_anti;			//=1,δͨ��,  =0,��ͨ����������֤
};

struct ProveAntiAddictionInfo
{
	static const Type kType = (int16_t)CommonType::kProveAntiAddictionInfo;
	UserID uid;
	StringLength name_len;
	char name[18];			//����
	StringLength id_len;
	char id[22];			//���֤����
};

struct ProveAntiAddictionInfoResult
{
	static const Type kType = (int16_t)CommonType::kProveAntiAddictionInfoResult;
	enum Result: int32_t { kSucceeded=0, kInvalidValue=1,kUidNotExist=2,kInfoError=3,kHadProved=4 };
	Result result;
};

enum class TextType:int16_t {kWorld=0, kCountry=1, kGuild=2, kSystem=3};

//
struct TextTo //c2s
{
	static const int16_t kType = (int16_t)CommonType::kTextTo;
	TextType message_type;
	StringLength msg_len;
	char msg[438];
};
struct TextToResult//s2c
{
	static const int16_t kType = (int16_t)CommonType::kTextToResult;
	Result result;
};
struct TextFrom //s2c
{
	static const int16_t kType = (int16_t)CommonType::kTextFrom;
	UserID from_uid;
	Nickname from_name;
	TextType message_type;
	StringLength msg_len;
	char msg[438];//n������
};

struct WhisperTo //c2s
{
	static const int16_t kType = (int16_t)CommonType::kWhisperTo;
	UserID to_uid;
	Nickname to_name;
	StringLength msg_len;
	char msg[438];
};
struct WhisperToResult //s2c
{
	static const int16_t kType = (int16_t)CommonType::kWhisperToResult;
	Result result;
	UserID to_uid;
	Nickname name;
	StringLength msg_len;
	char msg[438];
};
struct WhisperFrom //s2c
{
	static const int16_t kType = (int16_t)CommonType::kWhisperFrom;
	UserID from_uid;
	Nickname name;
	StringLength msg_len;
	char msg[438];
};

struct GetUserInfoByName //c2s
{
	static const int16_t kType = (int16_t)CommonType::kGetUserIDByName;
	GetUserInfoType type;//��Ҫ����Ϣ����,��uid
	Nickname name;
};

struct UserIDResult  //s2c
{
	static const int16_t kType = (int16_t)CommonType::kUserIDResult;
	UserID uid;
};

struct NotifyPlayerBaseInfo
{
	static const int16_t kType = (int16_t)CommonType::kNotifyPlayerBaseInfo;
	UserID uid;
	int8_t online;	//online =1, offline = 0
	int8_t bfriend; //friend=1, foe=0
	uint8_t level;
	uint8_t country;
	int32_t guild_id;
};

struct AddFriend
{
	static const int16_t kType = (int16_t)CommonType::kAddFriend;
	UserID friend_id;
};

struct AddFriendResult //s2c
{
	static const int16_t kType = (int16_t)CommonType::kAddFriendResult;
	Result result;
	_User  user;
};

struct NotifyOfAddFriend //s2c,����Ƿ������Ӻ��ѵ���
{
	static const int16_t kType = (int16_t)CommonType::kNotifyOfAddFriend;
	Role from; //����Ϊ���ѵ���
};

struct AddFoe 
{
	static const int16_t kType = (int16_t)CommonType::kAddFoe;
	UserID foe_id;
};

struct AddFoeResult //s2c
{
	static const int16_t kType = (int16_t)CommonType::kAddFoeResult;
	Result result;
	_User  user;
};

struct RemoveFoe //c2s
{
	static const int16_t kType = (int16_t)CommonType::kRemoveFoe;
	UserID foe_id;
};
struct RemoveFoeResult //s2c
{
	static const int16_t kType = (int16_t)CommonType::kRemoveFoeResult;
	Result result;
};
struct RemoveFriend //c2s
{
	static const int16_t kType = (int16_t)CommonType::kRemoveFriend;
	UserID friend_id;
};
struct RemoveFriendResult//s2c
{
	static const int16_t kType = (int16_t)CommonType::kRemoveFriendResult;
	Result result;
};
//���ѡ������������ɳ�Ա�б�

struct GetAssociatedUsersList //c2s
{
	static const int16_t kType = (int16_t)CommonType::kGetAssociatedUsersList;
	UsersListType type;
};

struct AssociatedUsersListResult //s2c
{
	static const int16_t kType = (int16_t)CommonType::kAssociatedUsersListResult;
	UsersList list;
};

struct Exit //c2s
{
	static const int16_t kType = (int16_t)CommonType::kExit;
};



struct PlayerSendMail	//c2s
{
	static const int16_t kType = (int16_t)CommonType::kPlayerSendMail;
	Mail mail;
};

struct PlayerSendMailResult	//s2c
{
	static const int16_t kType = (int16_t)CommonType::kPlayerSendMailResult;
	Result result;
};

struct GetMailsList	//c2s
{
	static const int16_t kType = (int16_t)CommonType::kGetMailsList;
};

struct MailsListResult	//s2c
{
	static const int16_t kType = (int16_t)CommonType::kMailsListResult;
	enum class MailType : int8_t { kPlayersMail=0, kSystemicMail=1 };
	Result result;
	int32_t len;
	struct MailInfo
	{
		uint32_t remaintime;//ʣ��ʱ��
		UserID  sender_uid;
		Nickname sender;
		Mail::Title title;
		MailType type;
		bool has_attachment; //����
		bool read;
		uint8_t mail_id;
	}mailslist[100]; 
};

struct NotifyOfNewMail //s2c
{
	static const int16_t kType = (int16_t)CommonType::kNotifyOfNewMail;
	Result	result;
};

struct GetMailNums //c2s
{
	static const int16_t kType = (int16_t)CommonType::kGetMailNums;
};

struct MailNumsResult	//s2c
{
	static const int16_t kType = (int16_t)CommonType::kMailNumsResult;
	uint8_t mailnums;
};

struct GetMail //c2s
{
	static const int16_t kType = (int16_t)CommonType::kGetMail;
	uint8_t		mail_id;
};

//����޸Ĵ˽ṹ,�ǵ�ͬʱ�޸�internal.h�����
struct MailAttachment
{
	int8_t   attach_id;	//����1,����2,...
	int8_t	 extracted;	//�Ѿ���ȡ=1
	uint16_t unuse1;
	uint16_t type;		//RewardType<Ӧ�߻�Ҫ��,��ֵǿ��ΪkPropRsc>
	uint16_t kind;		//���ֵֻ�е��ߣ�Prop���õ���
	uint32_t amount;
	int32_t  prop_id;	//����id,��prop_id!=0ʱ��Ч,ͬʱ��ȷ��дtype��kind,amount
};

struct MailAttachments
{
	int32_t amount;			//��������
	MailAttachment attach[8];
};

struct MailResult //s2c
{
	static const int16_t kType = (int16_t)CommonType::kMailResult;
	Result	result;
	MailAttachments	attachments;
	StringLength len;
	char	content[3002];	// 1000*3+2,�˳�Աֻ�ܷ��������
};

struct ExtractAttachment //c2s
{
	static const int16_t kType = (int16_t)CommonType::kExtractAttachment;
	int8_t mail_id;
	int8_t attach_id;//����id,����Ϊ1,�����-1,��ȫ����ȡ
};

struct ExtractAttachmentResult //s2c
{
	static const int16_t kType = (int16_t)CommonType::kExtractAttachmentResult;
	Result result;
};

struct DeleteMail // c2s
{
	static const int16_t kType = (int16_t)CommonType::kDeleteMail;
	uint8_t		mail_id;
};

struct DeleteMailResult //s2c
{
	static const int16_t kType = (int16_t)CommonType::kDeleteMailResult;
	Result result;
};
}; //namespace p




