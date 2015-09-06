#pragma  once
#include "game_def.h"
#include "town.h"

enum DataGetType
{

	kGetOtherPlayerBaseInfo = kDataGetTypeBegin+1,
	kGetPlayerArmy = kDataGetTypeBegin+2,
	kGetPlayerEquipment = kDataGetTypeBegin+3,
	kGetOtherPlayerOverviewInfo = kDataGetTypeBegin+4,
	kGetOtherPlayerBuildings = kDataGetTypeBegin+5,
	kGetOtherPlayerHerosInfo = kDataGetTypeBegin+6,

	kGetTop	= kDataGetTypeBegin+7,
	kGetPlayerOwnRank = kDataGetTypeBegin + 8,
	kGetPlayerRemainWorship = kDataGetTypeBegin + 9,
	kGiveOtherAddWorship = kDataGetTypeBegin + 10,
	kGetWorshipList = kDataGetTypeBegin + 11,
	kGetOtherPlayerTownInfo = kDataGetTypeBegin + 12,

	//�����Ƿ���ֵ
	kOtherPlayerBaseInfo = kDataGetTypeReturnBegin+1,
	kPlayerArmy = kDataGetTypeReturnBegin+2,
	kPlayerEquipment = kDataGetTypeReturnBegin+3,
	kOtherPlayerOverviewInfo = kDataGetTypeReturnBegin+4,
	kOtherPlayerBuildings = kDataGetTypeReturnBegin+5,
	kOtherPlayerHerosInfo = kDataGetTypeReturnBegin+6,

	kGetTopResult = kDataGetTypeReturnBegin+7,
	kGetPlayerOwnRankResult = kDataGetTypeReturnBegin + 8,
	kGetPlayerRemainWorshipResult = kDataGetTypeReturnBegin + 9,
	kGiveOtherWorshipResult = kDataGetTypeReturnBegin + 10,
	kGetWorshipListResult = kDataGetTypeReturnBegin + 11,

	kOtherPlayerTownInfo = kDataGetTypeReturnBegin + 12,
	//ֱ�ӷ���world() 8901 ~ 9000ֱ�Ӵ��� world
	kAddPrestige = kDataGetTypeBegin + 901, //������

	kDataGetTypeEnd = kDataGetTypeBegin + 999,
};

enum DataResultType
{
	DataResultType = 35000,
	TOP_PLAYER_HAS_WORSHIP_ERROR  = DataResultType + 1,            //��ͬһ���ֻ��Ĥ��һ��
	TOP_GUILD_HAS_WORSHIP_ERROR  = DataResultType + 2,            //��ͬһ����ֻ��Ĥ��һ��
	TOP_REMAIN_WORSHIP_ERROR = DataResultType + 3,                //��ʹ��Ĥ�ݴ�������
	TOP_WORSHIP_THEIR_OWN_ERROR = DataResultType + 4,             //����Ĥ���Լ�
};

enum TopData
{
	kSelectMax = 100, //��ѯǰ100������
};

struct GetOtherPlayerBaseInfo //��ȡ���˵Ļ�����Ϣ
{ 
	static const Type kType = kGetOtherPlayerBaseInfo;
	UserID player;
};
typedef struct GetOtherPlayerBaseInfo GetOtherPlayerBaseInfo;

struct OtherPlayerBaseInfo
{ 
	static const Type kType = kOtherPlayerBaseInfo;

};
typedef struct OtherPlayerBaseInfo OtherPlayerBaseInfo;

struct GetPlayerArmy //��ȡ���˵Ĳ��ӻ�����Ϣ
{ 
	static const Type kType = kGetPlayerArmy;
	UserID player;
};
typedef struct GetPlayerArmy GetPlayerArmy;

struct PlayerArmy
{ 
	static const Type kType = kPlayerArmy;
	int32_t count;
	struct HeroSimpleInfo
	{
		HeroSid sid;
		uint8_t level;
	}heros[9];
};
typedef struct PlayerArmy PlayerArmy;

struct GetPlayerEquipment //��ȡ�����ҵ�ĳ��װ������Ϣ(���Լ�)
{ 
	static const Type kType = kGetPlayerEquipment;
	UserID player;
	PropID id;
};
typedef struct GetPlayerEquipment GetPlayerEquipment;

struct PlayerEquipment
{ 
	static const Type kType = kPlayerEquipment;
	Equipment4Client equip;
};
typedef struct PlayerEquipment PlayerEquipment;


typedef struct _GetOtherPlayerOverviewInfo  //��ȡĳ���û���������Ϣ�����Լ���
{ 
	static const Type kType = kGetOtherPlayerOverviewInfo;
	UserID uid;
}GetOtherPlayerOverviewInfo;

typedef struct _OtherPlayerOverviewInfo  
{ 
	static const Type kType = kOtherPlayerOverviewInfo;
	uint8_t level;
	uint8_t cityhall_level;
	uint16_t rank;
	uint32_t town_prosperity_degree;
}OtherPlayerOverviewInfo;

typedef struct _GetOtherPlayerBuildings  //��ȡĳ���û��Ľ�����Ϣ�����Լ���
{ 
	static const Type kType = kGetOtherPlayerBuildings;
	UserID uid;
	int8_t type; //����������ͣ�������town.h�е�TownItemType
}GetOtherPlayerBuildings;

typedef struct _OtherPlayerBuildings
{ 
	static const Type kType = kOtherPlayerBuildings;
	int16_t count; //�����������
	uint8_t data[31*1024]; //����������ݣ��ṹΪ������Ϣ�����飬 �����town.h�еĶ���
}OtherPlayerBuildings;

typedef struct _GetOtherPlayerHerosInfo //��ȡ������ҵ�Ӣ����Ϣ������������ȡ�Լ��ģ�
{ 
	static const Type kType = kGetOtherPlayerHerosInfo;
	UserID uid;
}GetOtherPlayerHerosInfo;

#pragma pack(1)
typedef struct _OtherPlayerHerosInfo
{ 
	static const Type kType = kOtherPlayerHerosInfo;
	int32_t count;  //Ӣ�۸���
	struct 
	{
		HeroProperty property;
		struct
		{
			PropID id;
			PropSid sid;
		}equipments[8]; //�±���װ��λ�ã�idֵΪ0��ʾ��װ��
	}heros_info[10];
}OtherPlayerHerosInfo;

#pragma pack()


struct TopStruct
{ 
	uint32_t rank;//����
	uint32_t rank_data;//��Ӧ��������
	uint32_t worshiped_count;//��Ĥ�ݴ���
	uint32_t id;     //��Ӧ����������id
	uint16_t lenth; 
	char nickname[18];//����
	
};
typedef struct TopStruct TopStruct;

struct TopStructGuild
{ 
	uint32_t rank;//����
	uint32_t rank_data;//��Ӧ��������
	uint32_t worshiped_count;//��Ĥ�ݴ���
	uint32_t id;     //��Ӧ����������id
	uint16_t unuse; 
	uint16_t lenth; 
	char nickname[24];//����
	
};
typedef struct TopStructGuild TopStructGuild;

struct GetTop //c2s
{ 
	static const Type kType = kGetTop;
};
typedef struct GetTop GetTop;

struct  GetTopResult//s2c
{
	static const Type kType = kGetTopResult;
	Result result;

	uint32_t count_level; //�ϰ�������Ҹ���
	TopStruct top_level[kSelectMax];

	uint32_t count_silver;
	TopStruct top_silver[kSelectMax];

	uint32_t count_fightingPower;
	TopStruct top_fightingpower[kSelectMax];

	uint32_t count_degree_of_prosperity;
	TopStruct top_degree_of_prosperity[kSelectMax];//���ٶ�

	uint32_t count_guild;
	TopStructGuild top_guild[kSelectMax];
};
typedef struct GetTopResult GetTopResult;

struct GetPlayerOwnRank//c2s
{
	static const Type kType = kGetPlayerOwnRank;
};
typedef struct GetPlayerOwnRank GetPlayerOwnRank; 

struct GetPlayerOwnRankResult//s2c
{
	static const Type kType = kGetPlayerOwnRankResult;
	Result result;
	uint32_t player_own_level_rank;
	uint32_t player_own_silver_rank;
	uint32_t player_own_fightingpower_rank;
	uint32_t player_own_degree_of_prosperity_rank;//���ٶ�
	uint32_t guild_own_rank;
}; 
typedef struct GetPlayerOwnRankResult GetPlayerOwnRankResult;

struct GetPlayerRemainWorship//c2s //��ȡ����Լ��ܹ�ʹ�õ�Ĥ�ݴ���
{
	static const Type kType = kGetPlayerRemainWorship;
};
typedef struct GetPlayerRemainWorship GetPlayerRemainWorship;

struct GetPlayerRemainWorshipResult //s2c
{
	static const Type kType = kGetPlayerRemainWorshipResult ;
	Result result;
	uint32_t worshiped_level_count;        //��ҵȼ���Ĥ�ݴ���
	uint32_t worshiped_silver_count;       //������ұ�Ĥ�ݴ���
	uint32_t worshiped_fightingpower_count;//���ս������Ĥ�ݴ���
	uint32_t worshiped_degree_of_prosperity_count;//��ҷ��ٶ�Ĥ�ݴ���
	uint32_t remain_worship_count;//�ܹ�ʹ�õ�Ĥ��ʣ�����
};
typedef struct GetPlayerRemainWorshipResult GetPlayerRemainWorshipResult;


struct GiveOtherAddWorship  //�����˻��߹������Ĥ��c2s
{
	static const Type kType = kGiveOtherAddWorship;
	uint32_t id;//Ĥ���ߵ�id
	uint32_t type;//(1���ȼ����� 2:�Ƹ����� 3:ս�������� 4�����ٶ����� 5:����ȼ� )
};
typedef struct GiveOtherAddWorship GiveOtherAddWorship;

struct GiveOtherAddWorshipResult  //�����˻��߹������Ĥ��s2c
{
	static const Type kType = kGiveOtherWorshipResult;
	Result result;
	bool is_worship_success;//Ĥ���Ƿ�ɹ���1���ɹ� 0��ʧ�� �ɹ� ǰ��Ĥ�ݴ�����Ӧ+1��
};
typedef struct GiveOtherAddWorshipResult GiveOtherAddWorshipResult;

struct GetWorshipList //c2s
{
	static const Type kType = kGetWorshipList;
};
typedef struct GetWorshipList GetWorshipList;

struct Worship
{
	uint32_t id; 
	uint32_t type;
};
typedef struct Worship Worship;

struct GetWorshipListResult //��������Ѿ�Ĥ�ݵĹ������s2c
{
	static const Type kType = kGetWorshipListResult;
	Result result;
	uint32_t count;//Ĥ����ҵĸ��� +��Ĥ�ݹ���ĸ���
	Worship data[30];
};
typedef struct GetWorshipListResult GetWorshipListResult;


typedef struct _GetOtherPlayerTownInfo //��ȡ���˳����������Ϣ
{ 
	static const Type kType = kGetOtherPlayerTownInfo;
	UserID uid;
}GetOtherPlayerTownInfo;

#pragma pack(1)
typedef struct _OtherPlayerTownInfo
{ 
	static const Type kType = kOtherPlayerTownInfo;
	uint8_t block_status[36]; //36������Ŀ���״̬��0��ʾδ��������0��ʾ�ѿ���
	int32_t prosperity_degree; //���ٶ�
}OtherPlayerTownInfo;
#pragma pack()


struct AddPrestige //��������
{
	static const Type kType = kAddPrestige;
	uint32_t delta;
};
typedef struct AddPrestige AddPrestige;