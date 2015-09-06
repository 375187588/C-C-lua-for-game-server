#pragma once
#include "define.h"
#include "game_def.h"

typedef int32_t TownItemID;


enum TownItemType
{
	kFunctionBuilding = 1,
	kBusinessBuilding = 2,
	kDecoration = 3,
	kRoad = 4
};

enum 
{
	kMaxFunctionBuildings = 100,
	kMaxBusinessBuildings = 200,
	kMaxDecorations = 4096,
	kMaxRoads = 2048,
};

typedef int16_t TownItemKind;  //sid

enum TownType
{
	//10000
	kGetMyTown = kTownTypeBegin+1,
	kGetMyTownBuildings = kTownTypeBegin + 2,
	kGetTownBlocks = kTownTypeBegin+3,
	kGetTownProsperityDegree = kTownTypeBegin+4,
	kGetBuildingExpireTime = kTownTypeBegin+5,

	kFoundation = kTownTypeBegin+10,
	kBuild = kTownTypeBegin+11,
	kMove = kTownTypeBegin+12,
	kWarehousing = kTownTypeBegin+14,
	kUpgrade = kTownTypeBegin+15,
	kMerge = kTownTypeBegin+16,
	kReap = kTownTypeBegin+17,
	kSell = kTownTypeBegin+18,
	kUnlockTownBlock =  kTownTypeBegin+19,

	kGetCommercialBuildingInfo = kTownTypeBegin + 20,
	kFusionUpgrade = kTownTypeBegin + 21,
	kOutOfNothing = kTownTypeBegin + 22,
	kTownTypeEnd = 10200,

	///�����Ƿ���ֵ

	//16000
	kGetMyTownResult = kTownReturnBegin+1,
	kFoundationResult = kTownReturnBegin+2,
	kBuildResult = kTownReturnBegin+3,
	kMoveResult = kTownReturnBegin+4,
	kWarehousingResult = kTownReturnBegin+6,
	kUpgradeResult = kTownReturnBegin+7,
	kMergeResult = kTownReturnBegin+8,
	kReapResult = kTownReturnBegin+9,
	kSellResult = kTownReturnBegin+10,
	kFunctionBuildingStatus = kTownReturnBegin+11,
	kBusinessBuildingStatus = kTownReturnBegin+12,
	kDecorationStatus = kTownReturnBegin+13 ,
	kRoadStatus = kTownReturnBegin+14 ,
	kTownBlocks = kTownReturnBegin+15 ,
	kUnlockTownBlockResult = kTownReturnBegin+16,
	kTownProsperityDegree = kTownReturnBegin+17,
	kMyTownBuildings = kTownReturnBegin+18,
	kGetBuildingExpireTimeResult = kTownReturnBegin+19,

	kGetCommercialBuildingInfoResult = kTownReturnBegin + 20,
	kFusionUpgradeResult = kTownReturnBegin + 21,
	kOutOfNothingResult = kTownReturnBegin + 22,
	kBuildingGot = kTownReturnBegin + 100,
};

//�������δ֪�Ķ��壬���������ļ�ͷ��#include���ļ�

static const int8_t kDefaultAspect = 0;

struct GetMyTown	//��ȡ�������ݣ�C2S
{
	static const Type kType = kGetMyTown;
};
typedef struct GetMyTown GetMyTown;

struct  GetMyTownReturn
{
	static const Type kType = kGetMyTownResult;
	uint8_t block_status[36]; //36������Ŀ���״̬��0��ʾδ��������0��ʾ�ѿ���
	int32_t max_hall_level; //�����������ȼ�
	int32_t prosperity_degree; //���ٶ�
};
typedef struct GetMyTownReturn GetMyTownReturn;


struct GetMyTownBuildings  // �������ͻ�ȡ
{
	static const Type kType = kGetMyTownBuildings;
	int8_t type;
};
typedef struct GetMyTownBuildings GetMyTownBuildings;

typedef struct _MyTownBuildings
{ 
	static const Type kType = kMyTownBuildings;
	int16_t count; //�����������
	uint8_t data[31*1024]; //����������ݣ��ṹΪ������Ϣ�����飬 ���������Ķ���
}MyTownBuildings;

#pragma pack(1)
struct FunctionBuildingStatus //���ܽ���  s2c
{
	static const Type kType = kFunctionBuildingStatus;
	TownItemID id;
	TownItemKind kind;   //sid
	int8_t x;
	int8_t y;
	int8_t aspect;
	uint8_t level;
	int8_t progress;
	int8_t reserve; //��������
	uint32_t last_reap; //���һ����Ǯʱ�䣬��λΪ1970�꿪ʼ���������
};
typedef struct FunctionBuildingStatus FunctionBuildingStatus;


struct BusinessBuildingStatus		//��ҵ����  s2c
{
	static const Type kType = kBusinessBuildingStatus;
	TownItemID id;
	TownItemKind kind; //���ֽ���
	int8_t x; //x pos
	int8_t y; //y pos
	int8_t aspect;
	bool warehoused;
	int8_t progress;
	int8_t reserve; //��������
	uint32_t last_reap; //ͬ��
};
typedef struct BusinessBuildingStatus BusinessBuildingStatus;


struct DecorationStatus		//װ��  s2c
{
	static const Type kType = kDecorationStatus;
	TownItemID id;
	TownItemKind kind;
	int8_t x;
	int8_t y;
	int8_t aspect;
	bool warehoused;
};
typedef struct DecorationStatus DecorationStatus;

struct RoadStatus		//��· s2c
{
	static const Type kType = kRoadStatus;
	TownItemID id;
	TownItemKind kind;
	int8_t x;
	int8_t y;
	int8_t aspect;
	bool warehoused;
};
typedef struct RoadStatus RoadStatus;

#pragma pack()

//struct TownDataEnd  //���ݽ�����־  s2c
//{
//	static const Type kType = kTownDataEnd;
//};


struct Foundation  // �����½���   c2s
{
	static const Type kType = kFoundation;
	TownItemKind kind;
	int8_t x;
	int8_t y;
};
typedef struct Foundation Foundation;

struct FoundationResult   //s2c
{
	static const Type kType = kFoundationResult;
	Result result; //ֵΪgame_def.h �е� enum GameResult ���涨���ֵ
	TownItemID id;
	Foundation foundation;
};
typedef struct FoundationResult FoundationResult;

struct Build   //����һ��   c2s
{
	static const Type kType = kBuild;
	TownItemID id ;
};
typedef struct Build Build;


struct BuildResult   //s2c
{
	static const Type kType = kBuildResult;
	Result result;
	TownItemID id;
	int32_t count;
	Reward rewards[5];
};
typedef struct BuildResult BuildResult;

struct Move  //c2s
{
	static const Type kType = kMove;
	TownItemID id;
	int8_t x;
	int8_t y;
	int8_t aspect;
};
typedef struct Move Move;

struct  MoveResult   //s2c
{
	static const Type kType = kMoveResult;
	Result result;
	TownItemID id;
	int8_t x;
	int8_t y;
	int8_t aspect;
};
typedef struct MoveResult MoveResult;



struct Warehousing //�յ��ֿ�   c2s
{
	static const Type kType = kWarehousing;
	TownItemID id;
};
typedef struct Warehousing Warehousing;

struct WarehousingResult   // s2c
{
	static const Type kType = kWarehousingResult;
	Result result;
	TownItemID id;
};
typedef struct WarehousingResult WarehousingResult;

struct Upgrade  //c2s
{
	static const Type kType = kUpgrade;
	TownItemID id;
};
typedef struct Upgrade Upgrade;

struct UpgradeResult  //s2c
{
	static const Type kType = kUpgradeResult;
	Result result;
	TownItemID id;
	int32_t lord_exp;
};
typedef struct UpgradeResult UpgradeResult;

struct Merge  //�����ں�  c2s
{
	static const Type kType = kMerge;
	TownItemID id;
	TownItemID other;
	TownItemKind target_kind;
	int8_t x;
	int8_t y;
};
typedef struct Merge Merge;

struct MergeResult  //s2c
{
	static const Type kType = kMergeResult;
	Result result;
	Merge origin;
	TownItemID new_item;
};
typedef struct MergeResult MergeResult;

struct Reap  //��Ǯ  c2s
{
	static const Type kType = kReap;
	TownItemID id;
};
typedef struct Reap Reap;

struct ReapResult // s2c
{
	static const Type kType = kReapResult;
	Result result;
	TownItemID id;
	int32_t count;
	Reward rewards[5]; //5Ϊ���ֵ�����Ժ������ֵ
};
typedef struct ReapResult ReapResult;

struct Sell  //���� c2s
{
	static const Type kType = kSell;
	TownItemID id;
};
typedef struct Sell Sell;

struct SellResult  //c2s
{
	static const Type kType = kSellResult;
	Result result;
	TownItemID id;
};
typedef struct SellResult SellResult;

struct GetTownBlocks //c2s, ��ȡ���������״̬(�Ƿ��ѿ���)
{
	static const Type kType = kGetTownBlocks;
};
typedef struct GetTownBlocks GetTownBlocks;

struct TownBlocks //s2c  ���������״̬(�Ƿ��ѿ���)
{
	static const Type kType = kTownBlocks;
	uint8_t block_status[36]; //36������Ŀ���״̬��0��ʾδ��������0��ʾ�ѿ���
};
typedef struct TownBlocks TownBlocks;

struct UnlockTownBlock //c2s ���������һ������
{
	static const Type kType = kUnlockTownBlock;
	uint8_t block_index; //0-35
	uint8_t pay_type; //0���� 1���
};
typedef struct UnlockTownBlock UnlockTownBlock;

struct UnlockTownBlockResult
{
	static const Type kType = kUnlockTownBlockResult;
	Result result;
	uint8_t block_index; //0-35
};
typedef struct UnlockTownBlockResult UnlockTownBlockResult;

struct GetTownProsperityDegree  //��ȡ����ķ��ٶȣ�C2S
{ 
	static const Type kType = kGetTownProsperityDegree;
};
typedef struct GetTownProsperityDegree GetTownProsperityDegree;

struct TownProsperityDegree //��ȡ����ķ��ٶȵķ���ֵ,�����Ƿ������������͵ĵ�ǰ���ٶ�ֵ
{ 
	static const Type kType = kTownProsperityDegree;
	int32_t value; //���ٶȵ�ֵ
};
typedef struct TownProsperityDegree TownProsperityDegree;


typedef struct _BuildingGot //�����ĳ�ֽ�����  s2c
{ 
	static const Type kType = kBuildingGot;
	TownItemID id;
	TownItemKind kind; //sid
}BuildingGot;

typedef struct _GetBuildingExpireTime
{ 
	static const Type kType = kGetBuildingExpireTime;
	TownItemID id;
}GetBuildingExpireTime;

typedef struct _GetBuildingExpireTimeResult
{ 
	static const Type kType = kGetBuildingExpireTimeResult;
	uint32_t time;
}GetBuildingExpireTimeResult;


//�����������Ϣ
struct GetCommercialBuildingInfo //C2S
{
	static const Type kType = kGetCommercialBuildingInfo;
};
typedef struct GetCommercialBuildingInfo GetCommercialBuildingInfo;

struct BuildingInfo
{
	uint32_t is_only_building_have;			//Ψһ�����Ƿ��Ѿ�ӵ��(1:ûӵ�� 0:ӵ��)
};
typedef struct  BuildingInfo BuildingInfo;

struct GetCommercialBuildingInfoResult //s2c
{
	static const Type kType = kGetCommercialBuildingInfoResult;
	Result result;
	uint32_t open_num; //��������
	BuildingInfo building_info[100];
};
typedef struct GetCommercialBuildingInfoResult GetCommercialBuildingInfoResult;

//�ں�����
struct FusionUpgrade //c2s
{
	static const Type kType = kFusionUpgrade;
	uint32_t base_id;//��Ҫ�����Ļ�����������
	uint32_t upgrade_building_id;//��������id
	TownItemID id;
};
typedef struct FusionUpgrade FusionUpgrade;

struct FusionUpgradeResult //s2c
{
	static const Type kType = kFusionUpgradeResult;
	Result result;
	uint32_t is_success;//(1���ɹ� 2�����ϲ��� 3�����ݴ��� )
};
typedef struct FusionUpgradeResult FusionUpgradeResult;

//��������
struct OutOfNothing //c2s
{
	static const Type kType = kOutOfNothing;
	uint32_t base_id;//��Ҫ�����Ļ�����������
	uint32_t upgrade_building_id;//��������id
	TownItemID id;
};
typedef struct OutOfNothing OutOfNothing;

struct OutOfNothingResult //s2c
{
	static const Type kType = kOutOfNothingResult;
	Result result;
	uint32_t is_success;//(1���ɹ� 2:��Ҳ��� 3:����δ֪)
};
typedef struct OutOfNothingResult OutOfNothingResult;

