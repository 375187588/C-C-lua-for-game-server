#pragma once
#include "define.h"

enum PVP
{
    //������
    kGetArenaInfo = kPVPTypeBegin + 1,
    kGetChallengeList = kPVPTypeBegin + 2,
    kGetWarReport = kPVPTypeBegin + 3,
    kGetRankingTop = kPVPTypeBegin + 4,
    kClearCDTime = kPVPTypeBegin + 5,
    kBuyChallengeTimes = kPVPTypeBegin + 6,
    kGetRankReward = kPVPTypeBegin + 7,
    //kGetbackRankReward = kPVPTypeBegin + 8,
    kStartChallenge = kPVPTypeBegin + 9,
    kGetFirstPlace = kPVPTypeBegin + 20,
    //����
    kGetGradeInfo = kPVPTypeBegin + 101,
    kGetGradeReward = kPVPTypeBegin + 102,
    //kGetbackGradeReward = kPVPTypeBegin + 103,
    kElevateOfficial = kPVPTypeBegin + 104,
    kActivateHeros = kPVPTypeBegin + 105,
    kGetSpecialGradeInfo = kPVPTypeBegin + 106,
    //����
    kGetEscortStatus = kPVPTypeBegin + 201,
    kGetEscortNews = kPVPTypeBegin + 202,
    kEnterEscortPlace = kPVPTypeBegin + 203,
    kLeaveEscortPlace = kPVPTypeBegin + 204,
    kGetEscortInfo = kPVPTypeBegin + 205,
    kSetAutoAccept = kPVPTypeBegin + 206,
    kRefreshTransport = kPVPTypeBegin + 207,
    kStartEscort = kPVPTypeBegin + 208,
    kGetEscortInfoDetail = kPVPTypeBegin + 212,
    kGetEscortRank = kPVPTypeBegin + 213,
    kRobEscort = kPVPTypeBegin + 214,
    kInviteEscortRequest = kPVPTypeBegin + 216,
    kInviteEscortRespond = kPVPTypeBegin + 217,
    kClearEscortCD = kPVPTypeBegin + 221,
    
    /*
        ��սռ����
        300-500
    */
    
    //���
    kGetTerritoryStatus = kPVPTypeBegin + 501,
    kViewTerritory = kPVPTypeBegin + 502,
    kTerritoryGPS = kPVPTypeBegin + 503,
    kMoveTerritory = kPVPTypeBegin + 504,
    //kReapResource = kPVPTypeBegin + 505,
    kGrabResource = kPVPTypeBegin + 506,
    kDiscardResource = kPVPTypeBegin + 507,
    kKillBandits = kPVPTypeBegin + 508,
    kStopViewTerritory = kPVPTypeBegin + 509,
    kClearTerritoryCD = kPVPTypeBegin + 510,
    kSetTerritorySkin = kPVPTypeBegin + 511,
    
    ////////////////////////////////////////////////////////////////////////////////////////
    // ������Ϣ
    
    //������
    kGetArenaInfoResult = kPVPReturnBegin + 1,
    kGetChallengeListResult = kPVPReturnBegin + 2,
    kGetWarReportResult = kPVPReturnBegin + 3,
    kGetRankingTopResult = kPVPReturnBegin + 4,
    kClearCDTimeResult = kPVPReturnBegin + 5,
    kBuyChallengeTimesResult = kPVPReturnBegin + 6,
    kGetRankRewardResult = kPVPReturnBegin + 7,
    //kGetbackRankRewardResult = kPVPReturnBegin + 8,
    kStartChallengeResult = kPVPReturnBegin + 9,
    kPushOccurredChallenge = kPVPReturnBegin + 10,
    kGetFirstPlaceResult = kPVPReturnBegin + 20,
    //����
    kGetGradeInfoResult = kPVPReturnBegin + 101,
    kGetGradeRewardResult = kPVPReturnBegin + 102,
    //kGetbackGradeRewardResult = kPVPReturnBegin + 103,
    kElevateOfficialResult = kPVPReturnBegin + 104,
    kActivateHerosResult = kPVPReturnBegin + 105,
    kGetSpecialGradeInfoResult = kPVPReturnBegin + 106,
    
    kPushGradeChange = kPVPReturnBegin + 150,
    
    //���ͷ���
    kGetEscortStatusResult = kPVPReturnBegin + 201,
    kGetEscortNewsResult = kPVPReturnBegin + 202,
    kEnterEscortPlaceResult = kPVPReturnBegin + 203,
    kLeaveEscortPlaceResult = kPVPReturnBegin + 204,
    kGetEscortInfoResult = kPVPReturnBegin + 205,
    kSetAutoAcceptResult = kPVPReturnBegin + 206,
    kRefreshTransportResult = kPVPReturnBegin + 207,
    
    kStartEscortResult = kPVPReturnBegin + 208,
    kPushEscortNews = kPVPReturnBegin + 209,
    kPushEscortInfo = kPVPReturnBegin + 210,
    kPushEscortReward = kPVPReturnBegin + 211,

    kGetEscortInfoDetailResult = kPVPReturnBegin + 212,
    kGetEscortRankResult = kPVPReturnBegin + 213,
    
    kRobEscortResult = kPVPReturnBegin + 214,
    kPushEscortBeRobed = kPVPReturnBegin + 215,
    
    kInviteEscortRequestResult = kPVPReturnBegin + 216,
    kInviteEscortRespondResult = kPVPReturnBegin + 217,
    kPushEscortInviteRequest = kPVPReturnBegin + 218,
    kPushEscortInviteRespond = kPVPReturnBegin + 219,
    kPushEscortInviteResult = kPVPReturnBegin + 220,
    
    kClearEscortCDResult = kPVPReturnBegin + 221,
    
    /*
        ��սռ����
        300-500
    */
    
    //���
    kGetTerritoryStatusResult = kPVPReturnBegin + 501,
    kViewTerritoryResult = kPVPReturnBegin + 502,
    kTerritoryGPSResult = kPVPReturnBegin + 503,
    kMoveTerritoryResult = kPVPReturnBegin + 504,
    //kReapResourceResult = kPVPReturnBegin + 505,
    kGrabResourceResult = kPVPReturnBegin + 506,
    kDiscardResourceResult = kPVPReturnBegin + 507,
    kKillBanditsResult = kPVPReturnBegin + 508,
    kStopViewTerritoryResult = kPVPReturnBegin + 509,
    kClearTerritoryCDResult = kPVPReturnBegin + 510,
    kSetTerritorySkinResult = kPVPReturnBegin + 511,
    
    kPushTerritoryChallenge = kPVPReturnBegin + 551,
    kPushTerritoryChange = kPVPReturnBegin + 552,
    kPushTerritoryTimeout = kPVPReturnBegin + 553,
    kPushTerritoryPage = kPVPReturnBegin + 554,
};

enum ArenaResultType
{
    ArenaResultBegin = 12000,
    ARENA_SUCCESS = ArenaResultBegin + 1,                           // �ɹ���������ã���0���أ�
    ARENA_NOT_ENOUGH_GOLD = ArenaResultBegin + 2,                   // ��Ҳ���
    ARENA_NOT_ENOUGH_CHALLENGE_TIMES = ArenaResultBegin + 3,        // ��ս��������
    ARENA_NOT_ENOUGH_BUY_TIMES = ArenaResultBegin + 4,              // �����������
    ARENA_NOT_YET_ACTIVATE = ArenaResultBegin + 5,                  // ��δ�����������
    ARENA_HAVE_CD_TIME = ArenaResultBegin + 6,                      // CD��ȴ��
    ARENA_INVALID_TARGET = ArenaResultBegin + 7,                    // ��Ч����ս��Ŀ��
    ARENA_INVALID_STEP = ArenaResultBegin + 8,                      // ��Ч����ս�߽���
    ARENA_CANT_GETBACK_REWARD = ArenaResultBegin + 9,               // �����һ����ս���
    ARENA_NO_GETBACK_REWARD = ArenaResultBegin + 10,                // û�����ս���
    ARENA_NOT_ENOUGH_REWARD = ArenaResultBegin + 11,                // ����û�н���
    ARENA_NO_NEED_CLEAR_CD = ArenaResultBegin + 12,                 // �������CD
};

enum GradeResultType
{
    GradeResultBegin = 12100,
    GRADE_NOT_ACTIVATE = GradeResultBegin + 1,                  // ��δ������׹���
    GRADE_NOT_ENOUGH_REWARD = GradeResultBegin + 2,             // ������ȡ����
    GRADE_CANT_GETBACK_REWARD = GradeResultBegin + 3,           // �����һؽ���
    GRADE_CANT_UPGRADE_LEVEL = GradeResultBegin + 4,            // ����������ְ
    GRADE_HAVE_ACTIVATE_HERO = GradeResultBegin + 5,            // �Ѿ������Ӣ��
    GRADE_CANT_ACTIVATE_HERO = GradeResultBegin + 6,            // δ�������Ӣ������
};

enum EscortResultType
{
    EscortResultBegin = 12200,
    ESCORT_SUCCESS = EscortResultBegin + 1,                    // �ɹ�
    ESCORT_NOT_ACTIVATE = EscortResultBegin + 2,               // ��δ����͹���
    ESCORT_NOT_ENOUGH_GOLD = EscortResultBegin + 3,            // ��Ҳ���
    ESCORT_ON_THE_TOP = EscortResultBegin + 4,                 // �Ѿ��Ƕ�����ͨ����
    ESCORT_NO_MORE_TIMES = EscortResultBegin + 5,              // û�л��ʹ�����
    ESCORT_ON_THE_WAY = EscortResultBegin + 6,                 // ���ڻ���·��
    ESCORT_INVALID_TRANSPORT = EscortResultBegin + 7,          // û�������ͨ����
    ESCORT_INVALID_PAGE = EscortResultBegin + 8,               // û����ҳ���а�
    ESCORT_INVALID_TARGET = EscortResultBegin + 9,             // ����ȷ��Ŀ��
    ESCORT_DONT_NEED_CLEAR = EscortResultBegin + 10,           // ����Ҫ���CD
};

enum TerritoryResultType
{
    TerritoryResultBegin     = 12300,
    TERRITORY_SUCCESS        = TerritoryResultBegin + 1,               // �ɹ�
    TERRITORY_NOT_ACTIVATE   = TerritoryResultBegin + 2,               // ��δ������ع���
    TERRITORY_INVALID_TYPE   = TerritoryResultBegin + 3,               // ���ʹ���
    TERRITORY_INVALID_PAGE   = TerritoryResultBegin + 4,               // ҳ������
    TERRITORY_NO_MORE_TIMES  = TerritoryResultBegin + 5,               // ��������
    TERRITORY_INVALID_TARGET = TerritoryResultBegin + 6,               // ��Ч��Ŀ��
    TERRITORY_HAVE_CD_TIME   = TerritoryResultBegin + 7,               // ս��CD��/����CD��
    TERRITORY_NO_RESOURCE    = TerritoryResultBegin + 8,               // ���û����Դ��
    TERRITORY_NO_NEED_CLEAR  = TerritoryResultBegin + 9,               // ����Ҫ���CD
    TERRITORY_NO_ENOUGH_GOLD = TerritoryResultBegin + 10,              // ��Ҳ���
    TERRITORY_NO_RIGHT       = TerritoryResultBegin + 11,              // Ȩ������
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// c2s ����"��ʼһ����ս����ȡ��������"��������Ϣ������Ҫ����Type�������Ϣ

struct StartChallenge // ��ʼһ����ս
{
    static const Type kType = kStartChallenge;
    uint32_t target_rank; // Ŀ�꾺��������
};
typedef struct StartChallenge StartChallenge;

struct GetRankReward // ��ȡ��������
{
    static const Type kType = kGetRankReward;
    //uint8_t getback;      // �Ƿ���ȡ����Ľ�����0Ϊ����Ľ�����1Ϊ����Ľ���
};
typedef struct GetRankReward GetRankReward;

struct GetArenaInfo // ��ȡ��������Ϣ
{
    static const Type kType = kGetArenaInfo;
};
typedef struct GetArenaInfo GetArenaInfo;

struct GetChallengeList // ��ȡ��ս�б�
{
    static const Type kType = kGetChallengeList;
};
typedef struct GetChallengeList GetChallengeList;

struct GetWarReport // ���뾺����
{
    static const Type kType = kGetWarReport;
};
typedef struct GetWarReport GetWarReport;

struct GetRankingTop // ��ȡ���а�ǰʮ���
{
    static const Type kType = kGetRankingTop;
};
typedef struct GetRankingTop GetRankingTop;

struct ClearCDTime // ���CD
{
    static const Type kType = kClearCDTime;
};
typedef struct ClearCDTime ClearCDTime;

struct BuyChallengeTimes // ������ս����
{
    static const Type kType = kBuyChallengeTimes;
};
typedef struct BuyChallengeTimes BuyChallengeTimes;

/*
struct GetbackRankReward // �һ���������
{
    static const Type kType = kGetbackRankReward;
};
typedef struct GetbackRankReward GetbackRankReward;
*/

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// s2c ������Ҫ������

struct GetArenaInfoReturn // ��ȡ��������Ϣ
{
    static const Type kType = kGetArenaInfoResult;
    Result result;            //
    uint32_t rank;             // ��ǰ����������
    uint32_t time;             // �´ο�����ս��ʱ��
    uint16_t remain_count;     // ʣ����ս����
    uint16_t win_count;        // ��ʤ����
    uint16_t reward;           // 0Ϊ��������ȡ���콱����1Ϊ�����콱
    //uint16_t reward_bak;       // 0Ϊ�������һأ�1Ϊ�����һأ�2Ϊ������ȡ����Ľ���
    uint8_t grade;            // ����
    uint8_t buy_count;         // ʣ�๺�����
};
typedef struct GetArenaInfoReturn GetArenaInfoReturn;

struct ArenaTargetInfo // Ŀ����Ϣ
{
    uint32_t rank;      // ����
    UserID player;      // ���ID
    Nickname nickname;  // ����
    uint16_t level;      // �ȼ�
    uint16_t grade;      // ����
};
typedef struct ArenaTargetInfo ArenaTargetInfo;

struct GetChallengeListReturn // ��ȡ��ս�б�
{
    static const Type kType = kGetChallengeListResult;
    Result result;          //
    uint32_t list_count;      //����ʵ�ʸ���
    ArenaTargetInfo list[10]; //��ս�б����վ����������������У�6 5 4 3 2����
};
typedef struct GetChallengeListReturn GetChallengeListReturn;

struct ArenaWarInfo // ������ս����Ϣ
{
    UserID target;       // �Է����ID
    Nickname nickname;   // �Է�����
    uint16_t initiative;  // �Ƿ�������ս��1Ϊ������0Ϊ����
    uint16_t winner;      // ��Ӯ 1Ϊʤ����0Ϊʧ��
    int32_t rank_change; // �����ı䣬0δ�ı䣬���������������ǽ�����ֵ����������ֵ
    uint32_t war_id;     // ս��ID
    uint32_t time;       // ��ս����ʱ��
};
typedef struct ArenaWarInfo ArenaWarInfo;
struct GetWarReportReturn   // ��ȡ���ս��
{
    static const Type kType = kGetWarReportResult;
    Result result;          //
    uint32_t war_count;    // ս��ʵ�ʸ���
    ArenaWarInfo list[5];  // ս��ID��������սʱ���������У�[0]���������ս��[4]����õ���ս
};
typedef struct GetWarReportReturn GetWarReportReturn;

struct GetRankingTopReturn // ��ȡ���а�ǰʮ���
{
    static const Type kType = kGetRankingTopResult;
    Result result;           //
    uint32_t list_count;       //����ʵ�ʸ���
    ArenaTargetInfo list[10]; //��ս�б����վ����������������У�1 2 3 4 5 6
};
typedef struct GetRankingTopReturn GetRankingTopReturn;

struct ClearCDTimeReturn // ���CD
{
    static const Type kType = kClearCDTimeResult;
    Result result;          //
    uint32_t time;           //�´ο�����ս��ʱ��
};
typedef struct ClearCDTimeReturn ClearCDTimeReturn;

struct BuyChallengeTimesReturn // ������ս����
{
    static const Type kType = kBuyChallengeTimesResult;
    Result result;          //
    uint8_t remain_count;    //ʣ����ս����
    uint8_t buy_count;      // ʣ�๺�����
};
typedef struct BuyChallengeTimesReturn BuyChallengeTimesReturn;

struct GetRankRewardReturn // ��ȡ��������
{
    static const Type kType = kGetRankRewardResult;
    Result result;          //
    uint32_t silver;          // ����
    uint16_t prestige;        // ����
};
typedef struct GetRankRewardReturn GetRankRewardReturn;

/*
struct GetbackRankRewardReturn // �һ���������
{
    static const Type kType = kGetbackRankRewardResult;
    Result result;          //
};
typedef struct GetbackRankRewardReturn GetbackRankRewardReturn;
*/
struct StartChallengeReturn // ��ʼһ����ս
{
    static const Type kType = kStartChallengeResult;
    Result result;          //
    uint32_t silver;          // ����
    uint8_t victory;         // 1����ʤ����0������սʧ��
    uint8_t prestige;        // ����
    uint16_t fight_record_bytes;
    uint8_t fight_record[kMaxFightRecordLength];       // ս��ʵ�ʳ�����ǰ���Ϊ׼�� ��¼Ϊѹ���������
};
typedef struct StartChallengeReturn StartChallengeReturn;

struct PushOccurredChallenge  // �㱻������ս�ˣ��յ�����Ϣˢ�����ս����
{
    static const Type kType = kPushOccurredChallenge;
    Nickname nickname;         // ��ս������
    int32_t rank_change;  // �����ı䣬0δ�ı䣨��Ӯ�ˣ���1δ�ı䣨�����ˣ��������ǽ��������ˣ���Ҫˢ�����а񣩣���ֵ����������ֵ
    uint32_t war_id;      // ս��ID
    uint16_t fight_record_bytes;      // ���Ϊ0��˵����������Ϣ��û�б���ս��������ս��ID�ٴ�ȡ��ս��
    uint8_t fight_record[kMaxFightRecordLength];       // ս��ʵ�ʳ�����ǰ���Ϊ׼�� ��¼Ϊѹ���������
};
typedef struct PushOccurredChallenge PushOccurredChallenge;


struct GetFirstPlace
{
    static const Type kType = kGetFirstPlace;
};
typedef struct GetFirstPlace GetFirstPlace;

struct GetFirstPlaceResult
{
    static const Type kType = kGetFirstPlaceResult;
    Result result;
    uint32_t time;          // ����ʱ�䣨���Ϊ0˵��û�У�����Ĳ�����
    Nickname winner; /* winner�����loser ����˵�1�� */
    Nickname loser;
};
typedef struct GetFirstPlaceResult GetFirstPlaceResult;


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// �����Ǿ���ϵͳ

struct GetGradeInfo // ��ȡ������Ϣ c2s
{
    static const Type kType = kGetGradeInfo;
};
typedef struct GetGradeInfo GetGradeInfo;

struct HeroRecruitInfo // Ӣ����ļ״̬
{
    uint8_t hero_id;
    uint8_t status;     // 0 ������ļ��1 �Ѿ���ļ��2 ������ļ
};
typedef struct HeroRecruitInfo HeroRecruitInfo;

struct GetGradeInfoReturn // ��ȡ������Ϣ s2c
{
    static const Type kType = kGetGradeInfoResult;
    Result result;          // 
    uint32_t prestige;      // ��ǰ������
    uint16_t level;          // ��ǰ���׵ȼ�
    uint16_t count;          // Ӣ������
    HeroRecruitInfo heros[8];     // ���Լ����Ӣ�ۣ����8��
};
typedef struct GetGradeInfoReturn GetGradeInfoReturn;

//////////////////////////////////////////////////////////////////////////

struct GetGradeReward // ��ȡ���ν��� c2s
{
    static const Type kType = kGetGradeReward;
    //uint8_t getback;      // �Ƿ���ȡ����Ľ�����0Ϊ����Ľ�����1Ϊ����Ľ���
};
typedef struct GetGradeReward GetGradeReward;

struct GetGradeRewardReturn // ��ȡ���ν��� s2c
{
    static const Type kType = kGetGradeRewardResult;
    Result result;          // 
    uint32_t silver;        // �쵽������
};
typedef struct GetGradeRewardReturn GetGradeRewardReturn;

//////////////////////////////////////////////////////////////////////////
/*
struct GetbackGradeReward // �һؽ��� c2s
{
    static const Type kType = kGetbackGradeReward;
};
typedef struct GetbackGradeReward GetbackGradeReward;

struct GetbackGradeRewardReturn // �һؽ��� s2c
{
    static const Type kType = kGetbackGradeRewardResult;
    Result result;          // 
};
typedef struct GetbackGradeRewardReturn GetbackGradeRewardReturn;
*/
//////////////////////////////////////////////////////////////////////////

struct ElevateOfficial // ������ְ c2s
{
    static const Type kType = kElevateOfficial;
};
typedef struct ElevateOfficial ElevateOfficial;

struct ElevateOfficialReturn // ������ְ s2c
{
    static const Type kType = kElevateOfficialResult;
    Result result;          // 
};
typedef struct ElevateOfficialReturn ElevateOfficialReturn;

//////////////////////////////////////////////////////////////////////////

struct ActivateHeros // ����Ӣ�� c2s
{
    static const Type kType = kActivateHeros;
    uint8_t hero_id;    
};
typedef struct ActivateHeros ActivateHeros;

struct ActivateHerosReturn // ����Ӣ�� s2c
{
    static const Type kType = kActivateHerosResult;
    Result result;          // 
};
typedef struct ActivateHerosReturn ActivateHerosReturn;

//////////////////////////////////////////////////////////////////////////

//!!!!!!!�˽ӿڷ�����ʹ��WorldWar.h�е�kAdvancedGradeInfo
struct GetSpecialGradeInfo // ��ȡ���������Ϣ c2s
{
    static const Type kType = kGetSpecialGradeInfo;
};
typedef struct GetSpecialGradeInfo GetSpecialGradeInfo;

struct GetSpecialGradeInfoResult // ��ȡ���������Ϣ s2c
{
    static const Type kType = kGetSpecialGradeInfoResult;
    Result result;          // 
    uint32_t score;         // ���ܹ��ҹ���
    uint32_t total;         // ���ܲ�ս����
    uint32_t rank;          // ���ܹ��ҹ�������
};
typedef struct GetSpecialGradeInfoResult GetSpecialGradeInfoResult;

//////////////////////////////////////////////////////////////////////////

struct GradeChange // ���ױ䶯���� s2c
{
    static const Type kType = kPushGradeChange;
    uint8_t level;
};
typedef struct GradeChange GradeChange;

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// �����ǻ���ϵͳ

//////////////////////////////////////////////////////////////////////////

struct GetEscortStatus // ��ȡ����״̬ c2s
{
    static const Type kType = kGetEscortStatus;
};
typedef struct GetEscortStatus GetEscortStatus;

struct GetEscortStatusReturn // ��ȡ����״̬ s2c
{
    static const Type kType = kGetEscortStatusResult;
    Result result;          // 
    uint8_t escort_count;     // ʣ�໤�ʹ���
    uint8_t defend_count;     // ʣ�໤������
    uint8_t intercept_count;  // ʣ�����ش���
    uint8_t auto_accept;      // �Զ�Ӧ��״̬
    uint32_t time;            // ���ʱ���Ժ�ſ����ٴλ���
    uint16_t type;            // ��ͨ����״̬
    uint16_t refresh;         // ˢ�´���
    uint32_t rob_time;        // ���ʱ���Ժ�ſ����ٴδ��
};
typedef struct GetEscortStatusReturn GetEscortStatusReturn;

//////////////////////////////////////////////////////////////////////////

struct EscortNews
{
    uint16_t isRob;  // �Ƿ����������ţ�1�����ǣ�0������
    uint16_t type;   // ��ͨ����
    union
    {
        struct 
        {
            // ĳĳĳ �ɹ� ������ ĳĳĳ ���͵� XXX ���飬������ XX ���� �� XX ����
            Nickname looter;    // ������
            Nickname escort;    // ������
            uint32_t silver;     // ����
            uint32_t prestige;   // ����
        }looter;
        struct 
        {
            // ĳĳĳ ��ʼ���� ��������ħ̺��
            Nickname escort;    // ������
        }escort;
    }news;
};
typedef struct EscortNews EscortNews;

struct GetEscortNews // ��ȡ������ѯ c2s
{
    static const Type kType = kGetEscortNews;
};
typedef struct GetEscortNews GetEscortNews;

struct GetEscortNewsReturn // ��ȡ������ѯ s2c
{
    static const Type kType = kGetEscortNewsResult;
    Result result;          // 
    uint32_t count;          // ����ʵ�ʸ���
    EscortNews list[5];     // ����
};
typedef struct GetEscortNewsReturn GetEscortNewsReturn;

//////////////////////////////////////////////////////////////////////////

struct EnterEscortPlace // ���뻤������׼������ˢ����Ϣ c2s
{
    static const Type kType = kEnterEscortPlace;
};
typedef struct EnterEscortPlace EnterEscortPlace;

struct EnterEscortPlaceReturn // ���뻤������ s2c
{
    static const Type kType = kEnterEscortPlaceResult;
    Result result;          // 
};
typedef struct EnterEscortPlaceReturn EnterEscortPlaceReturn;

//////////////////////////////////////////////////////////////////////////

struct LeaveEscortPlace // �˳���������ֹͣ����ˢ����Ϣ c2s
{
    static const Type kType = kLeaveEscortPlace;
};
typedef struct LeaveEscortPlace LeaveEscortPlace;

struct LeaveEscortPlaceReturn // �˳��������� s2c
{
    static const Type kType = kLeaveEscortPlaceResult;
    Result result;          // 
};
typedef struct LeaveEscortPlaceReturn LeaveEscortPlaceReturn;

//////////////////////////////////////////////////////////////////////////

struct ClientEscortInfo
{
    UserID id;      // ���ID
    uint16_t time;  // �Ѿ�������ʱ��
    uint16_t type;  // ��ͨ��������
};
typedef struct ClientEscortInfo ClientEscortInfo;

struct GetEscortInfo // ��ȡ����������Ϣ c2s
{
    static const Type kType = kGetEscortInfo;
};
typedef struct GetEscortInfo GetEscortInfo;

struct GetEscortInfoReturn // ��ȡ����������Ϣ s2c
{
    static const Type kType = kGetEscortInfoResult;
    Result result;          // 
    uint32_t count;          // ʵ�ʸ���
    ClientEscortInfo list[512];
};
typedef struct GetEscortInfoReturn GetEscortInfoReturn;

//////////////////////////////////////////////////////////////////////////

struct SetAutoAccept // �����Զ����� c2s  
{
    static const Type kType = kSetAutoAccept;
    uint8_t type;           // ��ͨ���ߣ�����0����ȡ���Զ�����
};
typedef struct SetAutoAccept SetAutoAccept;

struct SetAutoAcceptReturn // �����Զ����� s2c
{
    static const Type kType = kSetAutoAcceptResult;
    Result result;          // 
};
typedef struct SetAutoAcceptReturn SetAutoAcceptReturn;

//////////////////////////////////////////////////////////////////////////

struct RefreshTransport // ˢ�½�ͨ���� c2s
{
    static const Type kType = kRefreshTransport;
};
typedef struct RefreshTransport RefreshTransport;

struct RefreshTransportReturn // ˢ�½�ͨ���� s2c
{
    static const Type kType = kRefreshTransportResult;
    Result result;          // 
    uint8_t type;           // ��ȡ�Ľ�ͨ����
};
typedef struct RefreshTransportReturn RefreshTransportReturn;

//////////////////////////////////////////////////////////////////////////

struct StartEscort // ��ʼ���� c2s
{
    static const Type kType = kStartEscort;
};
typedef struct StartEscort StartEscort;

struct StartEscortReturn // ��ʼ���� s2c
{
    static const Type kType = kStartEscortResult;
    Result result;          // 
};
typedef struct StartEscortReturn StartEscortReturn;

//////////////////////////////////////////////////////////////////////////

struct EscortRank
{
    UserID id;            // ���ID
    Nickname nickname;  // �������
    uint32_t rank;      // ��һ�������
    uint8_t level;        // �ȼ�
    uint8_t total;        // ��������
    uint8_t count;        // ʣ�໤������
    uint8_t accept;        // �Զ�Ӧ��״̬
    uint32_t score;        // �ܻ���
};
typedef struct EscortRank EscortRank;

struct GetEscortRank // �������а� c2s
{
    static const Type kType = kGetEscortRank;
    uint16_t page;           // �ڼ�ҳ
};
typedef struct GetEscortRank GetEscortRank;

struct GetEscortRankReturn // �������а� s2c
{
    static const Type kType = kGetEscortRankResult;
    Result result;          // 
    uint16_t page_count;    // ��ҳ��
    uint16_t count;         // ����ʵ�ʸ���
    EscortRank list[10];
};
typedef struct GetEscortRankReturn GetEscortRankReturn;

//////////////////////////////////////////////////////////////////////////

struct EscortInfoDetail
{
    Nickname nickname;    // �������
    uint8_t level;        // �ȼ�
    uint8_t type;         // ����
    uint8_t count;        // ���ش�����3�����Ѿ����ع�����ң������ٴδ�٣�4�����Ѿ����Ǵ���ҵĻ����ߣ����ܴ�٣���������Ϊ��������ɵ��ջ�
    uint8_t guard_level;        // �����ߵȼ������Ϊ0����û�л�����
    Nickname guard_nickname;    // ����������
    uint32_t silver;            // ��ȡ����
    uint32_t prestige;          // ��ȡ����
};
typedef struct EscortInfoDetail EscortInfoDetail;

struct GetEscortInfoDetail // ������ϸ��Ϣ c2s
{
    static const Type kType = kGetEscortInfoDetail;
    UserID uid;           // ���ID
};
typedef struct GetEscortInfoDetail GetEscortInfoDetail;

struct GetEscortInfoDetailReturn // ������ϸ��Ϣ s2c
{
    static const Type kType = kGetEscortInfoDetailResult;
    Result result;          // 
    EscortInfoDetail info;
};
typedef struct GetEscortInfoDetailReturn GetEscortInfoDetailReturn;

//////////////////////////////////////////////////////////////////////////

struct RobEscort // ��� c2s
{
    static const Type kType = kRobEscort;
    UserID player;           // Ҫ��ٵ����
};
typedef struct RobEscort RobEscort;

struct RobEscortReturn // ��� s2c
{
    static const Type kType = kRobEscortResult;
    Result result;          // 
    uint32_t rob_time;        // ���ʱ���Ժ�ſ����ٴδ��
    uint32_t victory;         // 1����ʤ����0������սʧ��
    Nickname nickname;        // �����������
    uint32_t silver;          // ��ȡ����
    uint16_t prestige;        // ��ȡ����
    uint16_t fight_record_bytes;
    uint8_t fight_record[kMaxFightRecordLength];       // ս��ʵ�ʳ�����ǰ���Ϊ׼�� ��¼Ϊѹ���������
};
typedef struct RobEscortReturn RobEscortReturn;

//////////////////////////////////////////////////////////////////////////

struct InviteEscortRequest // ������ѻ��� c2s
{
    static const Type kType = kInviteEscortRequest;
    UserID player;    // �����ߣ�ͨ��kGetUserIDByName��ȡ
};
typedef struct InviteEscortRequest InviteEscortRequest;

struct InviteEscortRequestResultReturn // ������ѻ��� s2c
{
    static const Type kType = kInviteEscortRequestResult;
    Result result;          // 
    uint8_t agree;          // 0�Զ�Ӧ��ɹ���1���������Լ���2��Ҳ���ȷ��3�Է����������ù⣻4�Զ�Ӧ��ܾ�����ͨ���ߵȼ����㣩��5û���Զ�Ӧ���Ҳ����ߣ�6�ȴ�������һظ�
};
typedef struct InviteEscortRequestResultReturn InviteEscortRequestResultReturn;

//////////////////////////////////////////////////////////////////////////

struct InviteEscortRespond // ��Ӧ�������� c2s
{
    static const Type kType = kInviteEscortRespond;
    UserID player;
    uint8_t agree;      // 0�ܾ���1ͬ��
};
typedef struct InviteEscortRespond InviteEscortRespond;

struct InviteEscortRespondResultReturn // ��Ӧ�������� s2c
{
    static const Type kType = kInviteEscortRespondResult;
    Result result;          // 
    uint8_t status;         // 0��Ӧ�����ɹ���1������Ч��2��Ӧ�Ѿ���ʱ��3�������Ѿ�����
};
typedef struct InviteEscortRespondResultReturn InviteEscortRespondResultReturn;

//////////////////////////////////////////////////////////////////////////

struct ClearEscortCD // ������CD c2s
{
    static const Type kType = kClearEscortCD;
};
typedef struct ClearEscortCD ClearEscortCD;

struct ClearEscortCDResult // ������CD s2c
{
    static const Type kType = kClearEscortCDResult;
    Result result;          // 
};
typedef struct ClearEscortCDResult ClearEscortCDResult;

//////////////////////////////////////////////////////////////////////////
// �������������Ϣ

struct PushEscortNews // �������� s2c
{
    static const Type kType = kPushEscortNews;
    EscortNews news;        //���һ������
};
typedef struct PushEscortNews PushEscortNews;

struct PushEscortInfo // ���ͻ�����Ϣ s2c
{
    static const Type kType = kPushEscortInfo;
    ClientEscortInfo info;        // ���һ������
};
typedef struct PushEscortInfo PushEscortInfo;

struct PushEscortReward // ��ȡ���� s2c
{
    static const Type kType = kPushEscortReward;
    uint8_t isOnline;         // 0����������Ϣ��1����������Ϣ
    uint8_t isHelper;         // 0�����Լ���õĽ�����1���������˻�ȡ�Ľ���
    uint8_t count;            // ����ٴ���
    uint8_t type;            // ʹ�õĽ�ͨ����
    uint32_t silver;          // ��ȡ����     ����ǻ�����������������õĻ���
    uint32_t prestige;        // ��ȡ����
};
typedef struct PushEscortReward PushEscortReward;

struct PushEscortBeRobed // ������� s2c
{
    static const Type kType = kPushEscortBeRobed;
    uint16_t isHelper;           // 0�����Լ��ı������ˣ�1���������˵ı������
    uint8_t type;              // ��ͨ����
    uint8_t victory;           // 1��Ӯ�ˣ�0���������
    Nickname nickname;         // ���������
    uint32_t silver;           // ��ʧ���ҡ������ʧ��ֻ�����ȡ�п۳���
    uint16_t prestige;         // ��ʧ����
    uint16_t fight_record_bytes;      // ���Ϊ0��˵���ǡ�������Ϣ��û�б���ս����
    uint8_t fight_record[kMaxFightRecordLength];       // ս��ʵ�ʳ�����ǰ���Ϊ׼�� ��¼Ϊѹ���������
};
typedef struct PushEscortBeRobed PushEscortBeRobed;

struct PushEscortInviteRequest // ���������㻤�� s2c
{
    static const Type kType = kPushEscortInviteRequest;
    UserID id;            // ���ID
    Nickname nickname;    // �������
    uint8_t type;         // ��ͨ��������
};
typedef struct PushEscortInviteRequest PushEscortInviteRequest;

struct PushEscortInviteRespond // ���˶���������Ӧ s2c
{
    static const Type kType = kPushEscortInviteRespond;
    Nickname nickname;    // �������
    uint8_t agree;        // 0�ܾ���1ͬ��
};
typedef struct PushEscortInviteRespond PushEscortInviteRespond;

struct PushEscortInviteResult // �㻤��������Ѿ��������������������ı� s2c
{
    static const Type kType = kPushEscortInviteResult;
    uint8_t count;        // ʣ�໤������
};
typedef struct PushEscortInviteResult PushEscortInviteResult;

//////////////////////////////////////////////////////////////////////////
// ������������Ϣ

struct GetTerritoryStatus // ��ȡ��ػ�����Ϣ c2s
{
    static const Type kType = kGetTerritoryStatus;
};
typedef struct GetTerritoryStatus GetTerritoryStatus;

struct GetTerritoryStatusResult // ��ȡ��ػ�����Ϣ s2c
{
    static const Type kType = kGetTerritoryStatusResult;
    Result result;          // 
    uint8_t can_move;       // 0���ղ���Ǩ�� 1���տ�Ǩ��
    uint8_t can_grab;       // 0���ղ�����ռ��Դ�� 1���տ���ռ��Դ��
    uint8_t rob_count;      // ��������ϵ�ǿ������
    uint8_t assist;         // ������ʣ��˷˴���
    uint32_t move_cd;       // Ǩ�Ƴǳ�ʧ��CDʱ��
    uint32_t grab_cd;       // ��Դ����ռʧ��CDʱ��
    uint32_t kill_cd;       // �˷�CDʱ��
    uint32_t reap_cd;       // �ջ���ԴCDʱ��
};
typedef struct GetTerritoryStatusResult GetTerritoryStatusResult;


struct TerritoryCity // �ǳ�
{
    uint8_t index;    // ��ҳλ��
    uint8_t type;     // �ǳ����ͣ�Ƥ����
    uint8_t busy;     // �Ƿ����� 0���� 1����
    uint8_t bandits;  // ǿ������
    UserID id;        // ���ID   (������ȡ��Ҹ���ϸ��Ϣ)
    Nickname name;    // �������
};
typedef struct TerritoryCity TerritoryCity;

struct TerritoryResource // ��Դ��
{
    uint8_t index;    // ��ҳλ��
    uint8_t type;     // ��Դ�����ͣ�SID��
    uint8_t busy;     // �Ƿ����� 0���� 1����
    uint8_t unused;   // ���뱣��
    UserID id;        // ���ID   (������ȡ��Ҹ���ϸ��Ϣ)
    Nickname name;    // �������
    uint32_t time;    // ռ�쵽��ʱ��
    uint32_t guard_time;    // ��������ʱ��
};
typedef struct TerritoryResource TerritoryResource;

struct ViewTerritory // �鿴��� c2s
{
    static const Type kType = kViewTerritory;
    uint32_t page;   // ���ҳ�� �ӵ�һҳ��ʼ
    uint8_t type;    // ������� 1�ƽ���� 2������� 3������� 4��ͭ���
};
typedef struct ViewTerritory ViewTerritory;

struct ViewTerritoryResult // �鿴��� s2c
{
    static const Type kType = kViewTerritoryResult;
    Result result;          // 
    uint32_t page;          // �����ҳ��
    uint8_t style;          // ��ҳ�ֲ�����
    uint8_t unused;         // ���뱣��
    uint8_t city_count;     // ��ҳ�ǳ�����
    uint8_t resource_count; // ��ҳ��Դ������
    TerritoryCity city_list[10];            //ʵ�ʸ�����city_count
    TerritoryResource resource_list[10];    //ʵ�ʸ�����resource_count
};
typedef struct ViewTerritoryResult ViewTerritoryResult;


struct TerritoryGPS // ��λ������ c2s
{
    static const Type kType = kTerritoryGPS;
};
typedef struct TerritoryGPS TerritoryGPS;

struct TerritoryGPSResult // ��λ������ s2c
{
    static const Type kType = kTerritoryGPSResult;
    Result result;          // 
    uint32_t page;          // ���ҳ��
    uint8_t type;           // ������� 1�ƽ���� 2������� 3������� 4��ͭ���
};
typedef struct TerritoryGPSResult TerritoryGPSResult;


struct MoveTerritory // Ǩ�������� c2s
{
    static const Type kType = kMoveTerritory;
    uint32_t page;          // ���ҳ��
    uint8_t type;           // ������� 1�ƽ���� 2������� 3������� 4��ͭ���
    uint8_t index;          // ��ҳ���еľ���λ��
};
typedef struct MoveTerritory MoveTerritory;

struct MoveTerritoryResult // Ǩ�������� s2c
{
    static const Type kType = kMoveTerritoryResult;
    Result result;          // 
    uint32_t move_cd;        // �´ο���սʱ��
    uint8_t can_move;        // 0���ղ���Ǩ�� 1���տ�Ǩ��
    uint8_t succeed;         // ս����� 0ʧ�� 1ʤ��
    uint16_t fight_record_bytes;      // ս������
    uint8_t fight_record[kMaxFightRecordLength];       // ս��ʵ�ʳ�����ǰ���Ϊ׼�� ��¼Ϊѹ���������
};
typedef struct MoveTerritoryResult MoveTerritoryResult;

/*
struct ReapResource // ��ȡ��Դ c2s
{
    static const Type kType = kReapResource;
};
typedef struct ReapResource ReapResource;

struct ReapResourceResult // ��ȡ��Դ s2c
{
    static const Type kType = kReapResourceResult;
    Result result;          //
    uint32_t amount;         // ��Դ��
    uint8_t type;           // ��Դ���ͣ�����Դ�����ã�
};
typedef struct ReapResourceResult ReapResourceResult;
*/

struct GrabResource // ������Դ c2s
{
    static const Type kType = kGrabResource;
    uint32_t page;          // ���ҳ��
    uint8_t type;           // ������� 1�ƽ���� 2������� 3������� 4��ͭ���
    uint8_t index;          // ��ҳ���еľ���λ��
};
typedef struct GrabResource GrabResource;

struct GrabResourceResult // ������Դ s2c
{
    static const Type kType = kGrabResourceResult;
    Result result;          // 
    uint32_t grab_cd;        // �´ο���սʱ��
    uint8_t can_grab;        // 0���ղ�����ռ��Դ�� 1���տ���ռ��Դ��
    uint8_t succeed;         // ս����� 0ʧ�� 1ʤ��
    uint16_t fight_record_bytes;      // ս������
    uint8_t fight_record[kMaxFightRecordLength];       // ս��ʵ�ʳ�����ǰ���Ϊ׼�� ��¼Ϊѹ���������
};
typedef struct GrabResourceResult GrabResourceResult;


struct DiscardResource // ������Դ c2s
{
    static const Type kType = kDiscardResource;
};
typedef struct DiscardResource DiscardResource;

struct DiscardResourceResult // ������Դ s2c
{
    static const Type kType = kDiscardResourceResult;
    Result result;          // 
};
typedef struct DiscardResourceResult DiscardResourceResult;


struct KillBandits // ����ǿ�� c2s
{
    static const Type kType = kKillBandits;
    uint32_t page;          // ���ҳ��
    uint8_t type;           // ������� 1�ƽ���� 2������� 3������� 4��ͭ���
    uint8_t index;          // ��ҳ���еľ���λ��
};
typedef struct KillBandits KillBandits;

struct KillBanditsResult // ����ǿ�� s2c
{
    static const Type kType = kKillBanditsResult;
    Result result;           // 
    uint32_t kill_cd;        // �´ο���սʱ��
    uint8_t assist;          // ʣ���������
    uint8_t succeed;         // ս����� 0ʧ�� 1ʤ��
    uint8_t unused;          // ���뱣��
    uint8_t type;            // �������ͣ�����ع������ã�
    uint32_t amount;         // ��������
    uint16_t fight_record_bytes;      // ս������
    uint8_t fight_record[kMaxFightRecordLength];       // ս��ʵ�ʳ�����ǰ���Ϊ׼�� ��¼Ϊѹ���������
};
typedef struct KillBanditsResult KillBanditsResult;


struct StopViewTerritory // ֹͣ�鿴��� c2s
{
    static const Type kType = kStopViewTerritory;
};
typedef struct StopViewTerritory StopViewTerritory;

struct StopViewTerritoryResult // ֹͣ�鿴��� s2c
{
    static const Type kType = kStopViewTerritoryResult;
    Result result;          // 
};
typedef struct StopViewTerritoryResult StopViewTerritoryResult;


struct ClearTerritoryCD // ���ѽ�����CD c2s
{
    static const Type kType = kClearTerritoryCD;
    uint8_t type;       // 1 Ǩ��CD 2 ��Դ��ս��CD 3 �˷�CD
};
typedef struct ClearTerritoryCD ClearTerritoryCD;

struct ClearTerritoryCDResult // ���ѽ�����CD s2c
{
    static const Type kType = kClearTerritoryCDResult;
    Result result;          // 
};
typedef struct ClearTerritoryCDResult ClearTerritoryCDResult;


struct SetTerritorySkin // �ı�ǳ���� c2s
{
    static const Type kType = kSetTerritorySkin;
    uint8_t type;       // �ǳ���� 0-����
};
typedef struct SetTerritorySkin SetTerritorySkin;

struct SetTerritorySkinResult // �ı�ǳ���� s2c
{
    static const Type kType = kSetTerritorySkinResult;
    Result result;          // 
};
typedef struct SetTerritorySkinResult SetTerritorySkinResult;

//////////////////////////////////////////////////////////////////////////
// ����������������Ϣ

struct TerritoryChallenge // �����ս s2c
{
    static const Type kType = kPushTerritoryChallenge;
    Nickname name;           // �������
    uint8_t type;            // ս����ʽ 0�ǳ� 1��Դ��
    uint8_t succeed;         // ս����� 0�Է�ʧ�� 1�Է�ʤ��
};
typedef struct TerritoryChallenge TerritoryChallenge;

struct TerritoryChange // ��ظı� s2c ����������Ϣʱ���»�ȡ��ǰ�鿴ҳ����Ϣ��
{
    static const Type kType = kPushTerritoryChange;
};
typedef struct TerritoryChange TerritoryChange;

struct TerritoryTimeout // ��س�ʱ s2c ������ʱ�䲻���ߣ���XXʱ����ر�ϵͳ���·����
{
    static const Type kType = kPushTerritoryTimeout;
    uint32_t time;          // �Ƴ�����
};
typedef struct TerritoryTimeout TerritoryTimeout;

struct TerritoryPage // ���ҳ���䶯 s2c
{
    static const Type kType = kPushTerritoryPage;
    uint32_t page;          // ��ǰҳ��
    uint32_t total;         // �����ҳ��
};
typedef struct TerritoryPage TerritoryPage;
