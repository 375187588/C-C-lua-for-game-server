#pragma once

#include <stdint.h>
#include <stddef.h>

typedef int16_t Type;

typedef int32_t UserID;
typedef int16_t GroupID;
typedef uint16_t StringLength;

static const uint32_t kMaxProtocolLength = 15*1024;



//Type ID ��Χ����
enum
{
	kPlayGroundBegin = 7000,
	kDataGetTypeBegin = 8000,
	kGameMainTypeBegin = 9000,
	kTownTypeBegin = 10000,
	kMapTypeBegin = 11000,
	kPVPTypeBegin = 12000,
	kMiscTypeBegin = 13000,
	kSocietyTypeBegin = 14000,



	kGameReturnBegin = 15000,
	kTownReturnBegin = kGameReturnBegin + 1000, 
	kMapResultBegin = kGameReturnBegin + 2000, 
	kPVPReturnBegin = kGameReturnBegin + 3000,
	kMiscReturnBegin = kGameReturnBegin + 4000,
	kSocietyReturnBegin = kGameReturnBegin + 5000,
	kPlayGroundReturnBegin = kGameReturnBegin + 6000,


	kDataGetTypeReturnBegin = kGameReturnBegin+13000,

	kBroadcastTypeBegin=29000,
	kBroadcastTypeEnd = 29999,

	kInternalStart = 30000,

};

enum 
{
	kMaxFightRecordLength = 11*1024,
};


struct Nickname
{
	StringLength len;
	char str[18];
};
typedef struct Nickname Nickname;

struct Role
{
	enum  Sex {kMale=0, kFemale=1};
	enum  OnlineStatus {kOnline=0, kOffline=1};

	UserID uid;
	Nickname nickname;
	int16_t sex;
	int16_t online;
};
typedef struct Role Role;

struct DragonName
{
	StringLength len;
	char		 str[22];		//7������
};
typedef struct DragonName DragonName;

typedef int32_t Result; 

enum GameResult
{
	eSucceeded=0,
	eInvalidValue=1, //�Ƿ���ֵ
	eLackResource=2, //��Դ���㣬�������Դ���������ҡ����������ߡ�װ���ȵ�
	eOccupy=3, //λ�ñ�ռ��
	eWaitCooldown=4, //CDδ��
	eInvalidOperation=5, //������Ч
	eLowLevel=6, //�ȼ�����
	eLowHeroLevel=7, //Ӣ�۵ȼ�����
	eSectionDisable=8, //�ؿ�δ����
	eSectionNotPassed=9, //�ؿ���δͨ��
	eFightFailed=10,
	eGroupFull=11, //��������
	eNotNearByRoad=12, //��ҵ����û����·��
	eBagFull=13, //��������
	eBagLeackSpace=14, //�����ռ䲻����
	eFunctionDisable=15, //����δ����
	eNotMatchDepend=16, //�����ϵ������
	eLowCityHallLevel=17, //�������ȼ�����
	eLowVipLevel=18,//VIP�ȼ�����
	eWarehouseFull=19, //�ֿ�����
	eBuildingIsUnique=20, //������Ψһ�ģ����ܶཨ

	eAddFriendNotExist=50,
	eAddFriendIsSelf,
	eAddFriendExist,
	eAddFoeNotExist,
	eAddFoeIsSelf,
	eAddFoeExist,
	eAddFriendMax,//��������
	eAddFoeMax,	//�������Ѵ�����
	eWhisperNotOnline,//˽�Ķ�������
	eNotJoinGuild,	//û�м��빤��

	eNotDoWithSelf=96,	//����Ϊ����
	eUserNotExist=97,
	eCantSpeakNow=98,	//��ǰ�����ܷ���

	eReceiverNotExist=100,
	eReceiverIsSelf,//������Ϊ����
	eGetMailNotExist,//���ʼ�������
	eGetMailsListFailed,
	eGetMailFailed,//
	eDeleteMailFailed,
	eCantSendToFoe,//���������������
	eMailsOverFlowWithAttach,//���������ʼ��Ѿ�100��
	eExtractAttachmentFailed,//��ȡ����ʧ��
	eAttachmentHadExtracted,//�����Ѿ�����ȡ����
	eAttachmentDontExist,	//�����ڸ���
	
}; 
