#pragma once
#include "define.h"

//////////////////////////////////////////////////////////////////////////////////////////////////

enum MiscRequestType
{
//c2s

    //����
    kGetStoveStatus = kMiscTypeBegin + 1,
    kGetStoveRunes = kMiscTypeBegin + 2,
    kClickMaterial = kMiscTypeBegin + 3,
    kPickupRunes = kMiscTypeBegin + 4,
    kResolveRunes = kMiscTypeBegin + 5,
    //kCooling = kMiscTypeBegin + 6,
    //kQuench = kMiscTypeBegin + 7,
    kGetBagRunes = kMiscTypeBegin + 8,
    kGetHeroRunes = kMiscTypeBegin + 9,
    kResolveBagRune = kMiscTypeBegin + 10,
    kLockRune = kMiscTypeBegin + 11,
    //kMergeAllRunes = kMiscTypeBegin + 12,
    //kMergeRune = kMiscTypeBegin + 13,
    kChangeRuneInBag = kMiscTypeBegin + 14,
    kChangeRuneOnHero = kMiscTypeBegin + 15,
    kWearDropRune = kMiscTypeBegin + 16,
    //kInjectRune = kMiscTypeBegin + 17,
    kUpgradeRune = kMiscTypeBegin + 18,
    kResolveAllRunes = kMiscTypeBegin + 19,
    kGoldActivation = kMiscTypeBegin + 20,
    kSortRunes = kMiscTypeBegin + 21,
    kUpgradeRuneOnHero = kMiscTypeBegin + 22,
    
    //�ɾ�
    kGetAllAchievements = kMiscTypeBegin+101,
    
    //����BOSS
    kGetWorldBossInfo = kMiscTypeBegin + 201,
    kEnterWorldBoss = kMiscTypeBegin + 202,
    kLeaveWorldBoss = kMiscTypeBegin + 203,
    kAttackWorldBoss = kMiscTypeBegin + 204,
    kReduceWorldBossCD = kMiscTypeBegin + 205,
    kPhoenixNirvana = kMiscTypeBegin + 206,

	//������
	kGetTreeWater = kMiscTypeBegin + 300,
	kGetTreeSeeds = kMiscTypeBegin + 301,
	kGetTreeLogs = kMiscTypeBegin + 302,
	kExitTree = kMiscTypeBegin + 303,
	kWaterTree = kMiscTypeBegin + 304,
	kPickFruit = kMiscTypeBegin + 305,

	//ǰ������ȡ���
	kGetDaysAgoInfo = kMiscTypeBegin + 330,
	kGetRewardDaysAgo = kMiscTypeBegin + 331,
	//�ղ���ַ
	kGetSaveWebsiteInfo = kMiscTypeBegin + 340,
	kGetSaveWebsiteReward = kMiscTypeBegin + 341,
	//�齱
	kGetLuckyDrawInfo = kMiscTypeBegin + 350,
	kDoLuckyDraw = kMiscTypeBegin + 351,
	//ÿ��ǩ��
	kGetCheckInEveryDayInfo = kMiscTypeBegin + 360,
	kDoCheckInEveryDay = kMiscTypeBegin + 361,
	//�ۼ�ǩ��
	kGetCheckInAccumulateInfo = kMiscTypeBegin + 370,
	kGetCheckInAccumulateReward = kMiscTypeBegin + 371,
	
	//������
	kGetTowerInfo = kMiscTypeBegin + 401,
	kResetTower = kMiscTypeBegin + 402,
	kFightTower = kMiscTypeBegin + 403,
	kMopupTower = kMiscTypeBegin + 404,

	//����
	kSelectCountry = kMiscTypeBegin + 901,
	kBuyGameResource = kMiscTypeBegin + 902,
	//kGetRemainResourceBuyTimes = kMiscTypeBegin + 903,
	kGetSystemConfig = kMiscTypeBegin + 904,
	kSetSystemConfig = kMiscTypeBegin + 905,
	kGetActivedFunctions = kMiscTypeBegin + 906,
	kGetRecommendCountry = kMiscTypeBegin + 907,
	//kGetAlchemyCount = kMiscTypeBegin + 908,
	//kUseAlchemy = kMiscTypeBegin + 909,
	kGetVIPSurplusCount = kMiscTypeBegin + 910,
	kGetRewardStatus = kMiscTypeBegin + 911,
	kViewFightRecord = kMiscTypeBegin + 912,
	//С����
	kNotifyResetAssistant = kMiscTypeBegin + 913,
	kAssistantGetReward = kMiscTypeBegin + 914,
	kGetAssistantInfo = kMiscTypeBegin + 915,
	kRetrieveAssistantTask = kMiscTypeBegin + 916,
	
	kGetRaiders = kMiscTypeBegin + 920,
	kPing = kMiscTypeBegin + 930,
	
	kGetStageAwardInfo = kMiscTypeBegin + 940,
	kGetStageAward = kMiscTypeBegin + 941,

//s2c
    //����
    kGetStoveStatusResult = kMiscReturnBegin + 1,
    kGetStoveRunesResult = kMiscReturnBegin + 2,
    kClickMaterialResult = kMiscReturnBegin + 3,
    kPickupRunesResult = kMiscReturnBegin + 4,
    kResolveRunesResult = kMiscReturnBegin + 5,
    //kCoolingResult = kMiscReturnBegin + 6,
    //kQuenchResult = kMiscReturnBegin + 7,
    kGetBagRunesResult = kMiscReturnBegin + 8,
    kGetHeroRunesResult = kMiscReturnBegin + 9,
    kResolveBagRuneResult = kMiscReturnBegin + 10,
    kLockRuneResult = kMiscReturnBegin + 11,
    //kMergeAllRunesResult = kMiscReturnBegin + 12,
    //kMergeRuneResult = kMiscReturnBegin + 13,
    kChangeRuneInBagResult = kMiscReturnBegin + 14,
    kChangeRuneOnHeroResult = kMiscReturnBegin + 15,
    kWearDropRuneResult = kMiscReturnBegin + 16,
    //kInjectRuneResult = kMiscReturnBegin + 17,
    kUpgradeRuneResult = kMiscReturnBegin + 18,
    kResolveAllRunesResult = kMiscReturnBegin + 19,
    kGoldActivationResult = kMiscReturnBegin + 20,
    kSortRunesResult = kMiscReturnBegin + 21,
    kUpgradeRuneOnHeroResult = kMiscReturnBegin + 22,

    //�ɾ�
    kAllAchievements = kMiscReturnBegin+101,
    kAchievementAccomplished = kMiscReturnBegin+151,
	kBigPacket = kMiscReturnBegin+171, //���Դ��

    //����BOSS
    kGetWorldBossInfoResult = kMiscReturnBegin + 201,
    kEnterWorldBossResult = kMiscReturnBegin + 202,
    kLeaveWorldBossResult = kMiscReturnBegin + 203,
    kAttackWorldBossResult = kMiscReturnBegin + 204,
    kReduceWorldBossCDResult = kMiscReturnBegin + 205,
    kPhoenixNirvanaResult = kMiscReturnBegin + 206,
    
    //��������BOOS�������������
    kPushWorldBossBoard = kMiscReturnBegin + 210,
    kPushWorldBossHurt = kMiscReturnBegin + 211,
    kPushWorldBossChallengerCount = kMiscReturnBegin + 212,
    kPushWorldBossCollectReward = kMiscReturnBegin + 213,
    kPushWorldBossReward = kMiscReturnBegin + 214,

	//������
	kGetTreeWaterResult = kMiscReturnBegin + 300,
	kGetTreeSeedsResult = kMiscReturnBegin + 301,
	kGetTreeLogsResult = kMiscReturnBegin + 302,
	kExitTreeResult = kMiscReturnBegin + 303,
	kWaterTreeResult = kMiscReturnBegin + 304,
	kPickFruitResult = kMiscReturnBegin + 305,

	kPushSeedStatus = kMiscReturnBegin + 320,
	kPushVisitLog = kMiscReturnBegin + 321,
	kPushResetTree = kMiscReturnBegin + 322,

	//ǰ3�ս��
	kGetDaysAgoInfoResult = kMiscReturnBegin + 330,
	kGetRewardDaysAgoResult = kMiscReturnBegin + 331,
	//�ղ���ַ
	kGetSaveWebsiteInfoResult = kMiscReturnBegin + 340,
	kGetSaveWebsiteRewardResult = kMiscReturnBegin + 341,
	//�齱
	kGetLuckyDrawInfoResult = kMiscReturnBegin + 350,
	kDoLuckyDrawResult = kMiscReturnBegin + 351,
	//ÿ��ǩ��
	kGetCheckInEveryDayInfoResult = kMiscReturnBegin + 360,
	kDoCheckInEveryDayResult = kMiscReturnBegin + 361,
	//�ۼ�ǩ��
	kGetCheckInAccumulateInfoResult = kMiscReturnBegin + 370,
	kGetCheckInAccumulateRewardResult = kMiscReturnBegin + 371,


	//������
	kGetTowerInfoResult = kMiscReturnBegin + 401,
	kResetTowerResult = kMiscReturnBegin + 402,
	kFightTowerResult = kMiscReturnBegin + 403,
	kMopupTowerResult = kMiscReturnBegin + 404,
	
	kPushTowerReward = kMiscReturnBegin + 411,
	
	
	//����
	kSelectCountryResult =  kMiscReturnBegin + 901,
	kBuyGameResourceResult = kMiscReturnBegin + 902,
	//kGetRemainResourceBuyTimesResult = kMiscReturnBegin + 903,
	kGetSystemConfigResult = kMiscReturnBegin + 904,
	kSetSystemConfigResult = kMiscReturnBegin + 905,
	kActivedFunctions = kMiscReturnBegin + 906,
	kRecommendCountry = kMiscReturnBegin + 907,
	//kAlchemyCount = kMiscReturnBegin + 908,
	//kUseAlchemyResult = kMiscReturnBegin + 909,
	kVIPSurplusCount = kMiscReturnBegin + 910,
	kRewardStatus = kMiscReturnBegin + 911,
	kFightRecord = kMiscReturnBegin + 912,
	kAssistantGetRewardResult = kMiscReturnBegin + 913,
	kGetAssistantInfoResult = kMiscReturnBegin + 914,
	kRetrieveAssistantTaskResult = kMiscReturnBegin + 915,
	
	kRaiders = kMiscReturnBegin + 920,

	kPingResult = kMiscReturnBegin + 930,

	kFunctionActived = kMiscReturnBegin + 951,
	
	kGetStageAwardInfoResult = kMiscReturnBegin + 940,
	kGetStageAwardResult = kMiscReturnBegin + 941,
};

enum RuneMaxCount
{
    RUNE_MAX_COUNT_STOVE = 20,              // ��¯�����20������
    RUNE_MAX_COUNT_INBAG = 30,              // ���������30������
    RUNE_MAX_COUNT_HERO = 30,               // Ӣ���������20������
};

enum RuneResultType
{
    RuneResultBegin = 13000,
    RUNE_SUCCESS = RuneResultBegin + 1,                           // �ɹ���������ã���0���أ�
    RUNE_NOT_YET_ACTIVATE = RuneResultBegin + 2,                  // ��δ�������
    RUNE_NOT_ENOUGH_GOLD = RuneResultBegin + 3,                   // ��Ҳ���
    RUNE_NOT_ENOUGH_COIN = RuneResultBegin + 4,                   // ���Ҳ���
    RUNE_NOT_ENOUGH_STOVE_SPACE = RuneResultBegin + 5,            // ��¯�ռ�����
    RUNE_NOT_ENOUGH_BAG_SPACE = RuneResultBegin + 6,              // �����ռ�����
    RUNE_NOT_ENOUGH_RUNE_SPACE = RuneResultBegin + 7,             // �������ݿ�ռ�����
    RUNE_AMOUNT_ERROR = RuneResultBegin + 8,                      // ������Ŀ����ȷ
    //RUNE_LOW_TEMPERATURE = RuneResultBegin + 9,                   // �¶ȹ���
    //RUNE_NOT_ENOUGH_T = RuneResultBegin + 10,                     // �¶Ȳ���
    //RUNE_CANT_USE_COOLING = RuneResultBegin + 11,                 // ����ʹ��������
    RUNE_CANT_PICKUP_GARBAGE = RuneResultBegin + 12,              // ����ʰȡ��������
    RUNE_INVALID_RUNE_ID = RuneResultBegin + 13,                  // ��Ч�ķ���ID
    RUNE_BAG_IS_EMPTY = RuneResultBegin + 14,                     // �����ǿյ�
    RUNE_CANT_MERGE_LOCKED = RuneResultBegin + 15,                // ���ܺϲ������ķ���
    RUNE_INVALID_RUNE_POS = RuneResultBegin + 16,                 // ��Ч�ķ���λ��
    RUNE_INVALID_MATERIAL = RuneResultBegin + 17,                 // ��Ч�Ĳ���
    RUNE_NOT_ENOUGH_ENERGY = RuneResultBegin + 18,                // û���㹻�ķ�������
    RUNE_RUNE_MAX_LEVEL = RuneResultBegin + 19,                   // �����Ѿ���������߼�
    RUNE_NO_MORE_TIMES = RuneResultBegin + 20,                    // û�м��������
    RUNE_NO_NEED_BUY = RuneResultBegin + 21,                      // ����Ҫʹ�ý�Ҽ���
};

enum WorldBossResultType
{
    WorldBossResultBegin = 13200,
    BOSS_NOT_YET_ACTIVATE = WorldBossResultBegin + 1,               // ��δ�������
    BOSS_NOT_YET_BEGIN = WorldBossResultBegin + 2,                  // BOSSսδ��ʼ
    BOSS_NOT_YET_REAL_BEGIN = WorldBossResultBegin + 3,             // BOSSսδ������ʼ
    BOSS_BOSS_ALREADY_DEAD = WorldBossResultBegin + 4,              // BOSS�Ѿ�����
    BOSS_NOT_YET_ENTER = WorldBossResultBegin + 5,                  // �㻹û�н���BOSS����
    BOSS_ON_THE_CD_TIME = WorldBossResultBegin + 6,                 // CD��ȴ��
    BOSS_DONT_NEED_REDUCE_CD = WorldBossResultBegin + 7,            // �㲻��Ҫ���CD
    BOSS_NOT_ENOUGH_GOLD = WorldBossResultBegin + 8,                // ��Ҳ���
    BOSS_NO_MORE_TIMES = WorldBossResultBegin + 9,                  // û�й��������
};

enum TowerResultType
{
    TowerResultBegin = 13300,
    TOWER_SUCCESS           = TowerResultBegin + 1,                  // �ɹ�
    TOWER_NOT_ACTIVATE      = TowerResultBegin + 2,                  // ��δ�������
    TOWER_INVALID_TOWER     = TowerResultBegin + 3,                  // ��Ч����
    TOWER_ALREADY_RESET     = TowerResultBegin + 4,                  // �Ѿ����ù���
    TOWER_NO_RESET_TIMES    = TowerResultBegin + 5,                  // û�����ô�����
    TOWER_NO_ENOUGH_GOLD    = TowerResultBegin + 6,                  // ��Ҳ���
    TOWER_ONLY_MOPUP        = TowerResultBegin + 7,                  // ��ʱֻ��ɨ��
    TOWER_CANT_MOPUP        = TowerResultBegin + 8,                  // ��ʱ����ɨ��
    TOWER_ON_THE_CD_TIME    = TowerResultBegin + 9,                  // CD��ȴ��
    TOWER_BAG_IS_FULL       = TowerResultBegin + 10,                 // �����Ѿ����ˣ�������ս����ɨ��
};
//////////////////////////////////////////////////////////////////////////////////////////////////

struct GetStoveStatus // ��ȡ��¯״̬ c2s
{
    static const Type kType = kGetStoveStatus;
};
typedef struct GetStoveStatus GetStoveStatus;

struct GetStoveStatusReturn // ��ȡ��¯״̬ s2c
{
    static const Type kType = kGetStoveStatusResult;
    Result result;          // 
    uint8_t status;        // ��ǰ����״̬��һ�Ų�����Զ������status��һλ�������2״̬��status�ڶ�λ�������3״̬���Դ�����
    uint8_t count;          // VIP���������ѵĴ���
};
typedef struct GetStoveStatusReturn GetStoveStatusReturn;

//////////////////////////////////////////////////////////////////////////////////////////////////
struct RuneInfoToClient
{
    uint32_t rune_id;         // ����ID
    uint16_t rune_type;        // �������ͣ����ı��е�SID��
    uint8_t position;         // ����λ�ã����Ϊ0�������ID��С�Զ������
    uint8_t lock;             // �Ƿ�������1Ϊ������0Ϊû������
    uint32_t exp;             // �����ܾ���
};
typedef struct RuneInfoToClient RuneInfoToClient;

struct GetStoveRunes // ��ȡ��¯�з����б� c2s
{
    static const Type kType = kGetStoveRunes;
};
typedef struct GetStoveRunes GetStoveRunes;

struct GetStoveRunesReturn // ��ȡ��¯�з����б� s2c
{
    static const Type kType = kGetStoveRunesResult;
    Result result;            // 
    uint32_t bag_count;        // �������ĸ���
    uint32_t list_count;       // ����ʵ�ʸ���
    RuneInfoToClient rune_list[RUNE_MAX_COUNT_STOVE];   // �����б�����λ���������У�1 2 3 4 5 6
};
typedef struct GetStoveRunesReturn GetStoveRunesReturn;

//////////////////////////////////////////////////////////////////////////////////////////////////

struct ClickMaterial // ������� c2s
{
    static const Type kType = kClickMaterial;
    uint8_t material;       // ����Ĳ���λ��
};
typedef struct ClickMaterial ClickMaterial;

struct ClickMaterialReturn // ������� s2c
{
    static const Type kType = kClickMaterialResult;
    Result result;          // ���δ�ɹ����򲻶�ȡ���������
    //uint8_t temperature;    // ��ǰ��¯�¶�
    //bool is_droped;        // �Ƿ������ģ�1Ϊ���䣬0Ϊδ����
    uint32_t rune_id;       // �������ID
    uint8_t rune_type;      // ����������ͣ����ı��е�SID��
    uint8_t status;         // ��ǰ����״̬
};
typedef struct ClickMaterialReturn ClickMaterialReturn;

//////////////////////////////////////////////////////////////////////////////////////////////////

struct PickupRunes // ʰȡ���� c2s
{
    static const Type kType = kPickupRunes;
    uint32_t runes_count;       // ����ʵ�ʸ���
    uint32_t runes_id[RUNE_MAX_COUNT_STOVE];     // �����б�
};
typedef struct PickupRunes PickupRunes;

struct PickupRunesReturn // ʰȡ���� s2c
{
    static const Type kType = kPickupRunesResult;
    Result result;          // 
};
typedef struct PickupRunesReturn PickupRunesReturn;

//////////////////////////////////////////////////////////////////////////////////////////////////

struct ResolveRunes // �ֽ���� c2s
{
    static const Type kType = kResolveRunes;
    uint32_t runes_count;       // ����ʵ�ʸ���
    uint32_t runes_id[RUNE_MAX_COUNT_STOVE];     // �����б�
};
typedef struct ResolveRunes ResolveRunes;

struct ResolveRunesReturn // �ֽ���� s2c
{
    static const Type kType = kResolveRunesResult;
    Result result;          // 
    uint32_t energy;           // ����������
};
typedef struct ResolveRunesReturn ResolveRunesReturn;
//////////////////////////////////////////////////////////////////////////////////////////////////
/*
struct Cooling // ��ȴ��ʹ���������� c2s
{
    static const Type kType = kCooling;
};
typedef struct Cooling Cooling;

struct CoolingReturn // ��ȴ s2c
{
    static const Type kType = kCoolingResult;
    Result result;           // 
    uint32_t temperature;    // ��ǰ��¯�¶�
};
typedef struct CoolingReturn CoolingReturn;
//////////////////////////////////////////////////////////////////////////////////////////////////

struct Quench // ��� c2s
{
    static const Type kType = kQuench;
};
typedef struct Quench Quench;

struct QuenchReturn // ��� s2c
{
    static const Type kType = kQuenchResult;
    Result result;          // 
    uint32_t rune_id;       // �������ID
    uint8_t rune_type;      // ����������ͣ����ı��е�SID��
};
typedef struct QuenchReturn QuenchReturn;
*/
//////////////////////////////////////////////////////////////////////////////////////////////////

struct GetBagRunes // ��ȡ�����еķ��� c2s
{
    static const Type kType = kGetBagRunes;
};
typedef struct GetBagRunes GetBagRunes;

struct GetBagRunesReturn // ��ȡ�����еķ��� s2c
{
    static const Type kType = kGetBagRunesResult;
    Result result;            // 
    uint32_t energy;           // ����������
    uint32_t list_count;       // ����ʵ�ʸ���
    RuneInfoToClient rune_list[RUNE_MAX_COUNT_INBAG];   // �����б�������λ������
};
typedef struct GetBagRunesReturn GetBagRunesReturn;
//////////////////////////////////////////////////////////////////////////////////////////////////

struct GetHeroRunes // ��ȡӢ���ϵķ��� c2s
{
    static const Type kType = kGetHeroRunes;
    uint8_t hero_id;
};
typedef struct GetHeroRunes GetHeroRunes;

struct GetHeroRunesReturn // ��ȡӢ���ϵķ��� s2c
{
    static const Type kType = kGetHeroRunesResult;
    Result result;          // 
    uint32_t list_count;       // ����ʵ�ʸ���
    RuneInfoToClient rune_list[RUNE_MAX_COUNT_HERO];   // �����б�������λ������
};
typedef struct GetHeroRunesReturn GetHeroRunesReturn;
//////////////////////////////////////////////////////////////////////////////////////////////////

struct ResolveBagRune // �ֽⱳ���еķ��� c2s
{
    static const Type kType = kResolveBagRune;
    uint8_t position;       // ����λ��
};
typedef struct ResolveBagRune ResolveBagRune;

struct ResolveBagRuneReturn // �ֽⱳ���еķ��� s2c
{
    static const Type kType = kResolveBagRuneResult;
    Result result;          // 
    uint32_t energy;           // ��õ�����
};
typedef struct ResolveBagRuneReturn ResolveBagRuneReturn;
//////////////////////////////////////////////////////////////////////////////////////////////////

struct LockRune // �������� c2s ������Ѿ������������Ϊ������
{
    static const Type kType = kLockRune;
    uint8_t position;       // ����λ��
};
typedef struct LockRune LockRune;

struct LockRuneReturn // �������� s2c
{
    static const Type kType = kLockRuneResult;
    Result result;          // 
};
typedef struct LockRuneReturn LockRuneReturn;
//////////////////////////////////////////////////////////////////////////////////////////////////
/*
struct MergeAllRunes // һ���ϲ����� c2s ���ɹ��������·������󱳰��б��
{
    static const Type kType = kMergeAllRunes;
};
typedef struct MergeAllRunes MergeAllRunes;

struct MergeAllRunesReturn // һ���ϲ����� s2c
{
    static const Type kType = kMergeAllRunesResult;
    Result result;          // 
};
typedef struct MergeAllRunesReturn MergeAllRunesReturn;
//////////////////////////////////////////////////////////////////////////////////////////////////

struct MergeRune // �ϲ��������� c2s ��λ��2����λ��1�ķ��ģ�
{
    static const Type kType = kMergeRune;
    uint8_t position1;       // ����λ��1
    uint8_t position2;       // ����λ��2
};
typedef struct MergeRune MergeRune;

struct MergeRuneReturn // �ϲ��������� s2c
{
    static const Type kType = kMergeRuneResult;
    Result result;          // 
    RuneInfoToClient rune;       // �²����ķ���
};
typedef struct MergeRuneReturn MergeRuneReturn;
*/
//////////////////////////////////////////////////////////////////////////////////////////////////

struct ChangeRuneInBag // �ı�����ڱ����е�λ�� c2s
{
    static const Type kType = kChangeRuneInBag;
    uint8_t old_position;        // ���ľɵ�λ��
    uint8_t new_position;        // �����µ�λ��
};
typedef struct ChangeRuneInBag ChangeRuneInBag;

struct ChangeRuneInBagReturn // �ı�����ڱ����е�λ�� s2c
{
    static const Type kType = kChangeRuneInBagResult;
    Result result;          // 
};
typedef struct ChangeRuneInBagReturn ChangeRuneInBagReturn;
//////////////////////////////////////////////////////////////////////////////////////////////////

struct ChangeRuneOnHero // �ı������Ӣ�����ϵ�λ��
{
    static const Type kType = kChangeRuneOnHero;
    uint32_t rune_id;        // ����ID
    uint8_t hero_id;         // Ӣ��ID
    uint8_t position;        // λ��
};
typedef struct ChangeRuneOnHero ChangeRuneOnHero;

struct ChangeRuneOnHeroReturn // �ı������Ӣ�����ϵ�λ�� s2c
{
    static const Type kType = kChangeRuneOnHeroResult;
    Result result;          // 
};
typedef struct ChangeRuneOnHeroReturn ChangeRuneOnHeroReturn;
//////////////////////////////////////////////////////////////////////////////////////////////////

struct WearDropRune // ��������/ȡ�·��� c2s ����������ڱ����У���ζ��������ģ���������Ѿ���Ӣ���ϣ���ζ�����·��ģ�
{
    static const Type kType = kWearDropRune;
    uint32_t rune_id;        // ����ID
    uint8_t hero_id;         // Ӣ��ID
    uint8_t position;        // λ�ã���������µ�δ֪�ط�����0��
};
typedef struct WearDropRune WearDropRune;

struct WearDropRuneReturn // �ı������Ӣ�����ϵ�λ�� s2c
{
    static const Type kType = kWearDropRuneResult;
    Result result;          // 
    uint8_t position;       // ���º��λ��
};
typedef struct WearDropRuneReturn WearDropRuneReturn;
//////////////////////////////////////////////////////////////////////////////////////////////////
/*
struct InjectRune // �������еķ���ע������ c2s
{
    static const Type kType = kInjectRune;
    int32_t energy;         // Ҫע�������
    uint8_t position;       // ����λ��
};
typedef struct InjectRune InjectRune;

struct InjectRuneReturn // �������еķ���ע������ s2c
{
    static const Type kType = kInjectRuneResult;
    Result result;          // 
    int32_t energy;           // ����������
    RuneInfoToClient rune;    // �²����ķ���
};
typedef struct InjectRuneReturn InjectRuneReturn;
*/
//////////////////////////////////////////////////////////////////////////////////////////////////

struct UpgradeRune // �������еķ���ע������ c2s
{
    static const Type kType = kUpgradeRune;
    uint8_t position;       // ����λ��
};
typedef struct UpgradeRune UpgradeRune;

struct UpgradeRuneReturn // �������еķ���ע������ s2c
{
    static const Type kType = kUpgradeRuneResult;
    Result result;          // 
    uint32_t energy;           // ����������
    //RuneInfoToClient rune;    // �²����ķ���
};
typedef struct UpgradeRuneReturn UpgradeRuneReturn;
//////////////////////////////////////////////////////////////////////////////////////////////////

struct ResolveAllRunes // �ֽ����з��� c2s
{
    static const Type kType = kResolveAllRunes;
    uint8_t position;       // Ҫ�����ķ���λ��
};
typedef struct ResolveAllRunes ResolveAllRunes;

struct ResolveAllRunesReturn // �ֽ����з��� s2c
{
    static const Type kType = kResolveAllRunesResult;
    Result result;          // 
    uint32_t energy;           // ����������
};
typedef struct ResolveAllRunesReturn ResolveAllRunesReturn;
//////////////////////////////////////////////////////////////////////////////////////////////////

struct GoldActivation // ���ֱ�Ӽ����� c2s
{
    static const Type kType = kGoldActivation;
};
typedef struct GoldActivation GoldActivation;

struct GoldActivationReturn // ���ֱ�Ӽ����� s2c
{
    static const Type kType = kGoldActivationResult;
    Result result;          // 
    uint8_t status;         // ��ǰ����״̬
    uint8_t count;  
};
typedef struct GoldActivationReturn GoldActivationReturn;
//////////////////////////////////////////////////////////////////////////////////////////////////


struct SortRunes // ������ı��� c2s
{
    static const Type kType = kSortRunes;
};
typedef struct SortRunes SortRunes;

struct SortRunesResult // ������ı��� s2c
{
    static const Type kType = kSortRunesResult;
    Result result;          // 
	uint8_t changed;	// 1�����˸ı� 0 δ�����ı�
};
typedef struct SortRunesResult SortRunesResult;


struct UpgradeRuneOnHero // ����Ӣ�����ϵķ��� c2s
{
    static const Type kType = kUpgradeRuneOnHero;
    uint32_t rune_id;        // ����ID
    uint8_t hero_id;         // Ӣ��ID
};
typedef struct UpgradeRuneOnHero UpgradeRuneOnHero;

struct UpgradeRuneOnHeroResult // ����Ӣ�����ϵķ��� s2c
{
    static const Type kType = kUpgradeRuneOnHeroResult;
    Result result;          // 
    uint32_t energy;           // ����������
};
typedef struct UpgradeRuneOnHeroResult UpgradeRuneOnHeroResult;



//�ɾ�
struct GetAllAchievements //c2s
{ 
    static const Type kType = kGetAllAchievements;
};
typedef struct GetAllAchievements GetAllAchievements;

struct AllAchievements //s2c
{ 
    static const Type kType = kAllAchievements;
    int32_t count;
    struct 
    {
        uint16_t id;
        uint16_t reserve; //����
		uint32_t progress;
        uint32_t accomplish_time;
    }achievements[600]; //��Ч������count����
};
typedef struct AllAchievements AllAchievements;

struct AchievementAccomplished //s2c
{ 
    static const Type kType = kAchievementAccomplished;
    uint16_t id;
};
typedef struct AchievementAccomplished AchievementAccomplished;



//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
// ����BOSS

//////////////////////////////////////////////////////////////////////////////////////////////////

struct WorldBossInfo
{
    uint32_t enter_time;        // ����ʱ�� ����ֵ
    uint32_t start_time;        // ����ʱ��
    uint32_t over_time;         // ����ʱ��
    uint8_t level;              // BOSS�ȼ�
    uint8_t dead;               // BOSS�Ƿ�����
    uint8_t sid;                // BOSS SID
    uint8_t id;                 // BOSS ID
};
typedef struct WorldBossInfo WorldBossInfo;

struct GetWorldBossInfo // ��ȡ����BOSS��Ϣ c2s
{
    static const Type kType = kGetWorldBossInfo;
};
typedef struct GetWorldBossInfo GetWorldBossInfo;

struct GetWorldBossInfoReturn // ��ȡ����BOSS��Ϣ s2c
{
    static const Type kType = kGetWorldBossInfoResult;
    Result result;          // 
    uint32_t count;         // ʵ�ʸ���
    WorldBossInfo list[5];      
};
typedef struct GetWorldBossInfoReturn GetWorldBossInfoReturn;
//////////////////////////////////////////////////////////////////////////////////////////////////

struct EnterWorldBoss // ��������BOSS���� c2s
{
    static const Type kType = kEnterWorldBoss;
};
typedef struct EnterWorldBoss EnterWorldBoss;

struct EnterWorldBossReturn // ��������BOSS���� s2c
{
    static const Type kType = kEnterWorldBossResult;
    Result result;          // 
    uint32_t life;          // BOSS��ǰѪ��
    uint32_t max_life;      // BOSS��Ѫ��
    uint32_t time;          // ���CDʱ��
    uint32_t hurt;          // ����˺�
    uint8_t count;          // ������ʹ�ò����񸴻�Ĵ���
};
typedef struct EnterWorldBossReturn EnterWorldBossReturn;
//////////////////////////////////////////////////////////////////////////////////////////////////

struct LeaveWorldBoss // �˳�����BOSS���� c2s
{
    static const Type kType = kLeaveWorldBoss;
};
typedef struct LeaveWorldBoss LeaveWorldBoss;

struct LeaveWorldBossReturn // �˳�����BOSS���� s2c
{
    static const Type kType = kLeaveWorldBossResult;
    Result result;          // 
};
typedef struct LeaveWorldBossReturn LeaveWorldBossReturn;
//////////////////////////////////////////////////////////////////////////////////////////////////

struct AttackWorldBoss // ����BOSS c2s
{
    static const Type kType = kAttackWorldBoss;
};
typedef struct AttackWorldBoss AttackWorldBoss;

struct AttackWorldBossReturn // ����BOSS s2c
{
    static const Type kType = kAttackWorldBossResult;
    Result result;          // 
    uint32_t time;          // �´ο�����ս��ʱ��
    uint32_t hurt;          // �������BOSS�˺�
    uint32_t hurt_total;    // ��ǰ��BOSS��ɵ����˺�
    uint32_t silver;        // �������
    uint32_t prestige;      // �������
    uint16_t killer;        // �Ƿ����һ����1�ǣ�0��
    uint16_t fight_record_bytes;      //
    uint8_t fight_record[kMaxFightRecordLength];       // ս��ʵ�ʳ�����ǰ���Ϊ׼�� ��¼Ϊѹ���������
};
typedef struct AttackWorldBossReturn AttackWorldBossReturn;
//////////////////////////////////////////////////////////////////////////////////////////////////


struct ReduceWorldBossCD // ����CD c2s
{
    static const Type kType = kReduceWorldBossCD;
};
typedef struct ReduceWorldBossCD ReduceWorldBossCD;

struct ReduceWorldBossCDReturn // ����CD s2c
{
    static const Type kType = kReduceWorldBossCDResult;
    Result result;          // 
    uint32_t time;          // �´ο�����ս��ʱ��
};
typedef struct ReduceWorldBossCDReturn ReduceWorldBossCDReturn;
//////////////////////////////////////////////////////////////////////////////////////////////////


struct PhoenixNirvana // �����񸴻� c2s
{
    static const Type kType = kPhoenixNirvana;
};
typedef struct PhoenixNirvana PhoenixNirvana;

struct PhoenixNirvanaReturn // �����񸴻� s2c
{
    static const Type kType = kPhoenixNirvanaResult;
    Result result;          // 
    uint32_t time;          // �´ο�����ս��ʱ��
    uint8_t count;
};
typedef struct PhoenixNirvanaReturn PhoenixNirvanaReturn;


//////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
// ������������Ϣ����������BOOS�������������
struct WorldBossBoardInfo
{
    Nickname nickname;      // ����ǳ�
    uint32_t hurt;          // ��BOSS��ɵ����˺�
};
typedef struct WorldBossBoardInfo WorldBossBoardInfo;

struct WorldBossBoard // ��Ҷ�BOSS��ɵ��˺����а�
{ 
    static const Type kType = kPushWorldBossBoard;
    uint32_t count;
    WorldBossBoardInfo list[10];    // �������˺��Ӹߵ�������
};
typedef struct WorldBossBoard WorldBossBoard;


struct WorldBossHurt // ��Ҷ�BOSS��ɵ��˺�
{ 
    static const Type kType = kPushWorldBossHurt;
    uint32_t life;          // BOSS��ǰѪ��
    uint32_t count;
    uint32_t list[512];
};
typedef struct WorldBossHurt WorldBossHurt;

struct WorldBossChallengerCount // ��ǰ�������
{ 
    static const Type kType = kPushWorldBossChallengerCount;
    uint32_t count;
};
typedef struct WorldBossChallengerCount WorldBossChallengerCount;

struct WorldBossCollectReward // BOSSս��������ҵĻ�ͳ��
{ 
    static const Type kType = kPushWorldBossCollectReward;
    uint32_t silver;                // ������
    uint32_t prestige;              // ������
    uint32_t silver_extra;          // ���һ����õ�����
};
typedef struct WorldBossCollectReward WorldBossCollectReward;

struct WorldBossReward // BOSSս�������ϰ���һ�ȡ����
{ 
    static const Type kType = kPushWorldBossReward;
    uint32_t silver;                // ����
};
typedef struct WorldBossReward WorldBossReward;

//////////////////////////////////////////////////////////////////////////////////////////////////



struct SelectCountry //ѡ�����
{ 
	static const Type kType = kSelectCountry;
	int8_t country;
};
typedef struct SelectCountry SelectCountry;

struct SelectCountryResult
{ 
	static const Type kType = kSelectCountryResult;
	Result result;
};
typedef struct SelectCountryResult SelectCountryResult;

struct BuyGameResource  //�����ж�����������
{ 
	static const Type kType = kBuyGameResource;
	int8_t type; //��Դ�����ͣ�������game_def.h��
};
typedef struct BuyGameResource BuyGameResource;

struct BuyGameResourceResult
{ 
	static const Type kType = kBuyGameResourceResult;
	Result result;
	uint16_t count;      // ʣ�๺�����
	uint16_t use_count;      // �Ѿ��������
};
typedef struct BuyGameResourceResult BuyGameResourceResult;

/*
struct GetRemainResourceBuyTimes  //��ȡʣ��Ĺ������
{ 
	static const Type kType = kGetRemainResourceBuyTimes;
	int8_t type; //��Դ�����ͣ�������game_def.h��
};
typedef struct GetRemainResourceBuyTimes GetRemainResourceBuyTimes;

struct GetRemainResourceBuyTimesResult
{ 
	static const Type kType = kGetRemainResourceBuyTimesResult;
	int8_t times;
};
typedef struct GetRemainResourceBuyTimesResult GetRemainResourceBuyTimesResult;
*/


struct BigPacket
{ 
	static const Type kType = kBigPacket;
	char sz[30*1024]; 
};
typedef struct BigPacket BigPacket;

/////////////////////////////////////////////////////////

struct GetConfig
{ 
	static const Type kType = kGetSystemConfig;
};
typedef struct GetConfig GetConfig;

struct GetConfigResult
{ 
	static const Type kType = kGetSystemConfigResult;
	uint8_t str[256];     //���256�ֽڣ����峤�ȿ�ʵ�ʳ���
};
typedef struct GetConfigResult GetConfigResult;

/////////////////////////////////////////////////////////

struct SetConfig
{ 
	static const Type kType = kSetSystemConfig;
	uint8_t str[256];   //���256�ֽڣ����������Զ��ض�
};
typedef struct SetConfig SetConfig;

struct SetConfigResult
{ 
	static const Type kType = kSetSystemConfigResult;
};
typedef struct SetConfigResult SetConfigResult;



/////////////////////////////////////////////////////////

enum {kBuidingActive=1, kSubsystemActive=2, kMaxCityhallLevelActive=3, kMapActive=4, kSkillActive=5};
struct GetActivedFunctions //��ȡ�����Ĺ���
{ 
	static const Type kType = kGetActivedFunctions;
	int8_t type; //1���� 2��ϵͳ 3����������ȼ� 4��ͼ 5�Ƽ�
};
typedef struct GetActivedFunctions GetActivedFunctions;

struct ActivedFunctions
{ 
	static const Type kType = kActivedFunctions;
	int16_t count;
	int16_t values[255];
};
typedef struct ActivedFunctions ActivedFunctions;

struct FunctionsActived //�������������
{ 
	static const Type kType = kFunctionActived;
	int16_t count;
	int16_t functions[16];
};
typedef struct FunctionsActived FunctionsActived;

/////////////////////////////////////////////////////////

struct GetRecommendCountry //��ȡ�Ƽ�����
{ 
	static const Type kType = kGetRecommendCountry;
};
typedef struct GetRecommendCountry GetRecommendCountry;

struct RecommendCountry
{ 
	static const Type kType = kRecommendCountry;
	uint8_t country;
};
typedef struct RecommendCountry RecommendCountry;
/////////////////////////////////////////////////////////
/*
struct GetAlchemyCount // ��ȡ����ʹ������������
{ 
	static const Type kType = kGetAlchemyCount;
};
typedef struct GetAlchemyCount GetAlchemyCount;

struct AlchemyCount
{ 
	static const Type kType = kAlchemyCount;
	uint32_t count;
};
typedef struct AlchemyCount AlchemyCount;

/////////////////////////////////////////////////////////

struct UseAlchemy // ʹ��������
{ 
	static const Type kType = kUseAlchemy;
};
typedef struct UseAlchemy UseAlchemy;

struct UseAlchemyResult
{ 
	static const Type kType = kUseAlchemyResult;
	Result result;          // ֻ��ִ���Ƿ���ȷ��ʹ�ú��ҡ�������������
};
typedef struct UseAlchemyResult UseAlchemyResult;
*/
/////////////////////////////////////////////////////////

struct GetVIPSurplusCount // ��ȡVIPϵͳ����ʣ�����
{ 
	static const Type kType = kGetVIPSurplusCount;
};
typedef struct GetVIPSurplusCount GetVIPSurplusCount;

struct VIPSurplusCount
{ 
	static const Type kType = kVIPSurplusCount;
	uint16_t count[4];       // ĿǰΪ����������������ж������������������ʹ�ô����������м�����Ĵ���
	uint16_t use_count[4];   // �Ѿ�ʹ�õĴ���
};
typedef struct VIPSurplusCount VIPSurplusCount;


/////////////////////////////////////////////////////////

struct GetRewardStatus // ��ȡ����״̬
{ 
	static const Type kType = kGetRewardStatus;
};
typedef struct GetRewardStatus GetRewardStatus;

struct RewardStatus // ����״̬
{ 
	static const Type kType = kRewardStatus;
	uint8_t arena;
	uint8_t grade;
};
typedef struct RewardStatus RewardStatus;
/////////////////////////////////////////////////////////

struct ViewFightRecord // �鿴ս��
{ 
	static const Type kType = kViewFightRecord;
	uint32_t war_id;
};
typedef struct ViewFightRecord ViewFightRecord;

struct FightRecord // ս��
{ 
	static const Type kType = kFightRecord;
    uint16_t fight_record_bytes;
    uint8_t fight_record[kMaxFightRecordLength];
};
typedef struct FightRecord FightRecord;
/////////////////////////////////////////////////////////

struct NotifyResetAssistant	//��������
{
	static const Type kType = kNotifyResetAssistant;
};
typedef struct NotifyResetAssistant NotifyResetAssistant;

struct AssistantGetReward	//��ȡ����
{
	static const Type kType = kAssistantGetReward;
	uint8_t index;		//��ȡ��һ��,��1Ϊ����
};
typedef struct AssistantGetReward AssistantGetReward;

struct AssistantGetRewardResult
{
	static const Type kType = kAssistantGetRewardResult;
	Result result;
};
typedef struct AssistantGetRewardResult AssistantGetRewardResult;

struct GetAssistantInfo
{
	static const Type kType = kGetAssistantInfo;
};
typedef struct GetAssistantInfo GetAssistantInfo;

struct AssistantTask
{
	int16_t task_id;
	int16_t b_retrieve;		//�Ƿ���һ�
	int32_t times;			//��ɴ���
};
typedef struct AssistantTask AssistantTask;

struct GetAssistantInfoResult
{
	static const Type kType = kGetAssistantInfoResult;
	uint16_t activity;		//��Ծ��
	uint16_t draw;			//��ȡ״̬
	int16_t unuse1;
	int16_t amount;			//task amount
	AssistantTask tasks[64];
};
typedef struct GetAssistantInfoResult GetAssistantInfoResult;

struct RetrieveAssistantTask
{
	static const Type kType = kRetrieveAssistantTask;
	int16_t task_id;
};
typedef struct RetrieveAssistantTask RetrieveAssistantTask;

struct RetrieveAssistantTaskResult
{
	static const Type kType = kRetrieveAssistantTaskResult;
	Result result;
	int32_t times;
};
typedef struct RetrieveAssistantTaskResult RetrieveAssistantTaskResult;


/////////////////////////////////////////////////////////////
struct GetTreeWater
{
	static const Type kType = kGetTreeWater;
};
typedef struct GetTreeWater GetTreeWater;

struct GetTreeWaterResult
{
	static const Type kType = kGetTreeWaterResult;
	Result  result;
	uint8_t water_amount;	//��ˮ����
	uint8_t buy_count;		//������ˮ����

};
typedef struct GetTreeWaterResult GetTreeWaterResult;

struct GetTreeSeeds
{
	static const Type kType = kGetTreeSeeds;
	UserID uid;
};
typedef struct GetTreeSeeds GetTreeSeeds;

enum TreeSeedStatus { kSeedGrowing=1, kSeedArid=2, kSeedRipe=3 };

struct TreeSeed
{
	int32_t ripe_time;	//ʣ�����ʱ��
	uint32_t last_water;	//�ϴν�ˮʱ��,����ʱ��
	uint8_t	kind;	//��������
	int8_t	location;//λ��
	int8_t  status;		//״̬,�����ж���
	int8_t  watered;		//����ˮ����
};
typedef struct TreeSeed TreeSeed;

struct GetTreeSeedsResult
{
	static const Type kType = kGetTreeSeedsResult;
	Result	result;
	int32_t amount;
	TreeSeed seeds[10];
};
typedef struct GetTreeSeedsResult GetTreeSeedsResult;

struct GetTreeLogs
{
	static const Type kType = kGetTreeLogs;
	UserID uid;
};
typedef struct GetTreeLogs GetTreeLogs;

struct TreeLog
{
	uint32_t time;	//����ʱ��
	Nickname name;	//�������
};
typedef struct TreeLog TreeLog;

struct GetTreeLogsResult
{
	static const Type kType = kGetTreeLogsResult;
	Result  result;
	int16_t sex;
	int16_t amount;
	TreeLog logs[50];
};
typedef struct GetTreeLogsResult GetTreeLogsResult;

struct ExitTree		//�˳�������,�ӱ��˵������������뿪
{
	static const Type kType = kExitTree;
};
typedef struct ExitTree ExitTree;

struct ExitTreeResult
{
	static const Type kType = kExitTreeResult;
	Result result;
};
typedef struct ExitTreeResult ExitTreeResult;

enum WaterTreeType { kWaterNormal=1, kWaterGod=2, kWaterGodByBuy=3 };
struct WaterTree
{
	static const Type kType = kWaterTree;
	UserID uid;
	int8_t type;	//������
	int8_t location;
};
typedef struct WaterTree WaterTree;

struct WaterTreeResult
{
	static const Type kType = kWaterTreeResult;
	Result result;
};
typedef struct WaterTreeResult WaterTreeResult;

struct PushSeedStatus
{
	static const Type kType = kPushSeedStatus;
	TreeSeed seed;
};
typedef struct PushSeedStatus PushSeedStatus;

struct PushVisitLog
{
	static const Type kType = kPushVisitLog;
	TreeLog log;
};
typedef struct PushVisitLog PushVisitLog;

struct PickFruit
{
	static const Type kType = kPickFruit;
	int8_t location;
};
typedef struct PickFruit PickFruit;

struct PickFruitResult
{
	static const Type kType = kPickFruitResult;
	Result result;
};
typedef struct PickFruitResult PickFruitResult;

struct PushResetTree
{
	static const Type kType = kPushResetTree;
};
typedef struct PushResetTree PushResetTree;



//////////////////////////////////////////////////////////////////////////
//ǰ3�ս��
typedef struct _GetDaysAgoInfo
{
	static const Type kType = kGetDaysAgoInfo;
}GetDaysAgoInfo;

typedef struct _GetDaysAgoInfoResult
{
	static const Type kType = kGetDaysAgoInfoResult;
	uint16_t amount;		//��ȡ���ٽ��
	uint16_t exist_reward;	//�Ƿ���ڽ���, 1(����), 0(������)
}GetDaysAgoInfoResult;

typedef struct _GetRewardDaysAgo
{
	static const Type kType = kGetRewardDaysAgo;
}GetRewardDaysAgo;

typedef struct _GetRewardDaysAgoResult
{
	static const Type kType = kGetRewardDaysAgoResult;
	Result result;
}GetRewardDaysAgoResult;

//////////////////////////////////////////////////////////////////////////
//�ղ���ַ
typedef struct _GetSaveWebsiteInfo
{
	static const Type kType = kGetSaveWebsiteInfo;
}GetSaveWebsiteInfo;

typedef struct _SaveWebsiteReward
{
	uint16_t type;
	uint16_t kind;
	uint32_t amount;
}SaveWebsiteReward;

typedef struct _GetSaveWebsiteInfoResult
{
	static const Type kType = kGetSaveWebsiteInfoResult;
	uint16_t exist_reward;
	uint16_t amount;		//reward������
	SaveWebsiteReward rewards[4];
}GetSaveWebsiteInfoResult;

typedef struct _GetSaveWebsiteReward
{
	static const Type kType = kGetSaveWebsiteReward;
}GetSaveWebsiteReward;

typedef struct _GetSaveWebsiteRewardResult
{
	static const Type kType = kGetSaveWebsiteRewardResult;
	Result result;
}GetSaveWebsiteRewardResult;
//////////////////////////////////////////////////////////////////////////
//�齱
typedef struct _GetLuckyDrawInfo
{
	static const Type kType = kGetLuckyDrawInfo;
}GetLuckyDrawInfo;

typedef struct _GetLuckyDrawInfoResult
{
	static const Type kType = kGetLuckyDrawInfoResult;
	uint32_t times;	//�Ѿ��齱����
}GetLuckyDrawInfoResult;

typedef struct _DoLuckyDraw
{
	static const Type kType = kDoLuckyDraw;
}DoLuckyDraw;

typedef struct _DoLuckyDrawResult
{
	static const Type kType = kDoLuckyDrawResult;
	Result result;
	PropID equip_id;		//װ��id
	uint8_t location;
}DoLuckyDrawResult;


//////////////////////////////////////////////////////////////////////////
//ÿ��ǩ��
typedef struct _GetCheckInEveryDayInfo
{
	static const Type kType = kGetCheckInEveryDayInfo;
}GetCheckInEveryDayInfo;

typedef struct _CheckInEveryDayReward
{
	PropSid  kind;
	uint16_t amount;
}CheckInEveryDayReward;

typedef struct _CheckInEveryDayRewards
{
	CheckInEveryDayReward rewards[6];
}CheckInEveryDayRewards;

typedef struct _GetCheckInEveryDayInfoResult
{
	static const Type kType = kGetCheckInEveryDayInfoResult;
	CheckInEveryDayRewards rewards[5];
	uint32_t time;		//�ϴ�ǩ����ʱ��
	uint8_t days;		//����ǩ��������
}GetCheckInEveryDayInfoResult;

typedef struct _DoCheckInEveryDay
{
	static const Type kType = kDoCheckInEveryDay;
}DoCheckInEveryDay;

typedef struct _DoCheckInEveryDayResult
{
	static const Type kType = kDoCheckInEveryDayResult;
	Result result;
	uint32_t time;		//ǩ��ʱ��
}DoCheckInEveryDayResult;

//////////////////////////////////////////////////////////////////////////
//�ۼ�ǩ��
typedef struct _GetCheckInAccumulateInfo
{
	static const Type kType = kGetCheckInAccumulateInfo;
}GetCheckInAccumulateInfo;

typedef struct _GetCheckInAccumulateInfoResult
{
	static const Type kType = kGetCheckInAccumulateInfoResult;
	uint32_t time;		//�ϴ�ǩ��ʱ��
	uint8_t days;		//ǩ������
}GetCheckInAccumulateInfoResult;

typedef struct _GetCheckInAccumulateReward
{
	static const Type kType = kGetCheckInAccumulateReward;
	uint8_t b_direct;		//1=ֱ����ȡ(��ֵ�ﵽһ�����)
}GetCheckInAccumulateReward;

typedef struct _GetCheckInAccumulateRewardResult
{
	static const Type kType = kGetCheckInAccumulateRewardResult;
	Result result;
	uint32_t time;
}GetCheckInAccumulateRewardResult;



/////////////////////////////////////////////////////////

struct RaidersInfo
{
    Nickname nickname;      // ����ǳ�
    uint32_t level;         // ��ҵȼ�
    uint32_t war_id;        // ս��ID
};
typedef struct RaidersInfo RaidersInfo;

struct GetRaiders
{
	static const Type kType = kGetRaiders;
	uint16_t id;         // �ڼ���
	uint8_t type;        // �������� 1���� 2Ӣ�� 3������
	uint8_t sub_id;      // �ڼ���
};
typedef struct GetRaiders GetRaiders;

struct Raiders
{
	static const Type kType = kRaiders;
	uint32_t count;
	RaidersInfo list[5];        // ���ս��������ʱ������
};
typedef struct Raiders Raiders;




/////////////////////////////////////////////////////////
// ������

struct GetTowerInfo
{
    static const Type kType = kGetTowerInfo;
};
typedef struct GetTowerInfo GetTowerInfo;

struct GetTowerInfoResult
{
    static const Type kType = kGetTowerInfoResult;
    Result result;
    uint8_t tower;      // ��ͨ�ؽ���
    uint8_t layer;      // ��ͨ�ؽ���  ���� 1��0 ����ǰӦ����ս1������һ��
    uint8_t refresh;    // ˢ�´���
    uint8_t status;     // ��ǰ״̬ 0 ֻ����ս ���� ��ǰ����ɨ������
    uint32_t time;      // ��սCDʱ�䣬��ǰʱ��������ʱ�������ս
    uint8_t suspend;    // ��ǰɨ��Ӧ�ô���㿪ʼ
};
typedef struct GetTowerInfoResult GetTowerInfoResult;


struct ResetTower
{
    static const Type kType = kResetTower;
    uint8_t tower;      // �����ĸ���
};
typedef struct ResetTower ResetTower;

struct ResetTowerResult
{
    static const Type kType = kResetTowerResult;
    Result result;
};
typedef struct ResetTowerResult ResetTowerResult;


struct FightTower
{
    static const Type kType = kFightTower;
};
typedef struct FightTower FightTower;

struct FightTowerResult
{
    static const Type kType = kFightTowerResult;
    Result result;
    uint8_t tower;      // ��ͨ�ؽ���
    uint8_t layer;      // ��ͨ�ؽ���  ���� 1��0 ����ǰӦ����ս1������һ��
    uint8_t succeed;    // ս����� 0ʧ�� 1ʤ��
    uint8_t unused;     // ����ռ��
    uint32_t time;      // ��սCDʱ�䣬��ǰʱ��������ʱ�������ս
    uint16_t fight_record_bytes;      // ս������
    uint8_t fight_record[kMaxFightRecordLength];       // ս��ʵ�ʳ�����ǰ���Ϊ׼�� ��¼Ϊѹ���������
};
typedef struct FightTowerResult FightTowerResult;


struct MopupTower
{
    static const Type kType = kMopupTower;
};
typedef struct MopupTower MopupTower;

struct MopupTowerResult
{
    static const Type kType = kMopupTowerResult;
    Result result;
    uint8_t suspend;        // 1 ɨ����������������ɼ���ɨ�� 0 ɨ�����
};
typedef struct MopupTowerResult MopupTowerResult;


//��������������
struct TowerRewardProp
{
    uint16_t sid;       // ����sid
    uint16_t amount;    // ��������
};
typedef struct TowerRewardProp TowerRewardProp;

struct TowerReward
{
    uint32_t silver;    // ��������
    uint32_t exp;       // ��������
    uint8_t tower;
    uint8_t layer;
    uint8_t mopup;      // 0ս������ 1ɨ������
    uint8_t count;      // �������߸���
    TowerRewardProp list[10];   //ʵ�ʸ�����count
};
typedef struct TowerReward TowerReward;

struct PushTowerReward
{
    static const Type kType = kPushTowerReward;
    uint32_t count;
    TowerReward list[100];   // ʵ�ʸ�����count
};
typedef struct PushTowerReward PushTowerReward;

enum 
{
	kServerIDGate=1,
	kServerIDData=2,
	kServerIDWorld=3,
	kServerIDInteract=4,
};
typedef struct _Ping
{ 
	static const Type kType = kPing;
	uint8_t server;  //���涨���enum
}Ping;

typedef struct _PingResult
{ 
	static const Type kType = kPingResult;

}PingResult;


struct GetStageAwardInfo    // ��ȡĿ���콱��Ϣ
{
    static const Type kType = kGetStageAwardInfo;
};
typedef struct GetStageAwardInfo GetStageAwardInfo;

struct StageAwardInfo
{
    static const Type kType = kGetStageAwardInfoResult;
    uint32_t count;
    struct 
    {
        uint8_t sid;
        uint8_t stage;  // ��׶�
        uint8_t phase;  // С�׶�
        uint8_t status; // ״̬ 0δ��� 1���δ��ȡ 2����Ѿ���ȡ
    } list[1024];
};
typedef struct StageAwardInfo StageAwardInfo;


struct GetStageAward    // ��ȡĿ���콱
{
    static const Type kType = kGetStageAward;
    uint16_t stage;  // ��׶�
    uint16_t phase;  // С�׶Σ�0�����佱��
};
typedef struct GetStageAward GetStageAward;

struct StageAwardResult
{
    static const Type kType = kGetStageAwardResult;
    Result result; 
    // ʵ�ʽ��������
};
typedef struct StageAwardResult StageAwardResult;
