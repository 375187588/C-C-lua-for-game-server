#pragma once

#include "define.h"
#include "game_def.h"

enum MapType
{

	kEnterSection = kMapTypeBegin+1,
	kChallengeSubSection = kMapTypeBegin+2,
	kMopUpSection = kMapTypeBegin+3,
	kGetSectionScores = kMapTypeBegin+4,
	kEnterMapArea = kMapTypeBegin+5,
	kMove2RoadLocation = kMapTypeBegin+6,
	kOpenCurrentLocationBox = kMapTypeBegin+7,
	kGetArmyLocation = kMapTypeBegin+8,
	kGetSectionPassedReward = kMapTypeBegin+9,
	kGetTaskStatus = kMapTypeBegin+10,
	kGetMapRandomBoxes = kMapTypeBegin+11,
	kGetAvailableTasks = kMapTypeBegin+12,
	kReceiveTask = kMapTypeBegin+13,
	kTryCompleteSubTask = kMapTypeBegin+14,
	kSubmitTask = kMapTypeBegin+15,
	kAbandonTask = kMapTypeBegin+16,
	kGetSectionPassedBoxReward =  kMapTypeBegin+17,
	kConvey = kMapTypeBegin+18,
	kTryCompleteTrunkTask = kMapTypeBegin+19,
	kGetBossSectionStatus = kMapTypeBegin+20,
	kResetAvailableTasks = kMapTypeBegin+21,
	kChallengeBossSection = kMapTypeBegin+22,
	kGetStamina = kMapTypeBegin+23,
	kBackToMainCity = kMapTypeBegin+24,
	kClearStaminaCD = kMapTypeBegin+25,
	kReplenishStamina = kMapTypeBegin+26,
	kClearBackToTownCD = kMapTypeBegin+27,

	//////////////////////////////////////////////////////////////////////////
	kEnterSectionResult = kMapResultBegin+1,
	kChallengeSubSectionResult = kMapResultBegin+2,
	kMopUpSectionResult = kMapResultBegin+3,
	kGetSectionScoresResult = kMapResultBegin+4,
	kEnterMapAreaResult =  kMapResultBegin+5,
	kMove2RoadLocationResult = kMapResultBegin+6,
	kOpenCurrentLocationBoxResult = kMapResultBegin+7,
	kArmyLocation = kMapResultBegin+8,
	kSectionPassedReward = kMapResultBegin+9,
	kTaskStatus = kMapResultBegin+10,
	kMapRandomBoxes = kMapResultBegin+11,
	kAvailableTasks = kMapResultBegin+12,
	kReceiveTaskResult = kMapResultBegin+13,
	kTryCompleteSubTaskResult = kMapResultBegin+14,
	kSubmitTaskResult = kMapResultBegin+15,
	kAbandonTaskResult = kMapResultBegin+16,
	kSectionPassedBoxReward = kMapResultBegin+17,
	kConveyResult = kMapResultBegin+18,
	kTryCompleteTrunkTaskResult =  kMapResultBegin+19,
	kBossSectionStatus = kMapResultBegin+20,
	kResetAvailableTasksResult = kMapResultBegin+21,
	kChallengeBossSectionResult = kMapResultBegin+22,
	kGetStaminaResult = kMapResultBegin+23,
	kBackToMainCityResult = kMapResultBegin+24,
	kClearStaminaCDResult = kMapResultBegin+25,
	kReplenishStaminaResult = kMapResultBegin+26,
	kClearBackToTownCDResult = kMapResultBegin+27,


	kEncounteredMonsters = kMapResultBegin+101,
	kWeatherChanged = kMapResultBegin+102,
	kPushStaminaInfo = kMapResultBegin+103,
	kPushForceBackToMainCity = kMapResultBegin+104,
};

typedef int16_t SectionIndex; //�ؿ�����

struct EnterSection //����һ���ؿ�
{
	static const Type kType = kEnterSection;
	SectionIndex id;
};
typedef struct EnterSection EnterSection;

struct EnterSectionResult
{
	static const Type kType = kEnterSectionResult;
	Result result;
};
typedef struct EnterSectionResult EnterSectionResult;

struct ChallengeSubSection //��ǰ�ؿ�����һ��֣�������������
{
	static const Type kType = kChallengeSubSection;
};
typedef struct ChallengeSubSection ChallengeSubSection;

struct ChallengeSubSectionResult
{ 
	static const Type kType = kChallengeSubSectionResult;
	Result result;
	bool win; //�Ƿ�ʤ��
	int8_t rewards_count;//����ĸ���
	int16_t fight_record_bytes; //ս�����ֽ���
	Reward rewards[8]; //ʵ�ʳ�����ǰ���countΪ׼
	uint8_t fight_record[kMaxFightRecordLength]; //ʵ�ʳ�����ǰ���bytesΪ׼����¼Ϊѹ���������
};
typedef struct ChallengeSubSectionResult ChallengeSubSectionResult;

struct GetSectionPassedReward //ͨ�ؽ���
{ 
	static const Type kType = kGetSectionPassedReward;
};
typedef struct GetSectionPassedReward GetSectionPassedReward;

struct SectionPassedReward 
{
	static const Type kType = kSectionPassedReward;
	int32_t hero_exp; 
	int16_t feat;
	int8_t score;
	int8_t reserve; //��������
	int32_t lord_exp; //��������
};
typedef struct  SectionPassedReward SectionPassedReward;

struct GetSectionPassedBoxReward //��ȡͨ�ر��佱��
{ 
	static const Type kType = kGetSectionPassedBoxReward;
};
typedef struct GetSectionPassedBoxReward GetSectionPassedBoxReward;

struct SectionPassedBoxReward
{ 
	static const Type kType = kSectionPassedBoxReward;
	uint32_t silver; //��������
	uint16_t gold; //������,����Ϊ0
	PropSid prop;  //�����еĵ���(�����ǹ̶���1)��0��ʾû��
	PropID prop_id; 
};
typedef struct SectionPassedBoxReward SectionPassedBoxReward;

struct MopUpSection // ɨ��
{ 
	static const Type kType = kMopUpSection;
	SectionIndex id;
	bool auto_sell_prop;
};
typedef struct MopUpSection MopUpSection;

#pragma pack(1)
struct MonsterGroupRewards
{
	int8_t count;
	Reward rewards[8]; //ʵ�ʳ�����ǰ���countΪ׼
};
typedef struct MonsterGroupRewards MonsterGroupRewards;
#pragma pack()


struct MopUpSectionResult
{ 
	static const Type kType = kMopUpSectionResult;
	Result result;
	bool bag_full; //��������  ���ֵΪtrue
	int8_t monsters_group_count;
	MonsterGroupRewards rewards[7]; // ʵ�ʳ�����ǰ���countΪ׼
	SectionPassedReward spr;
	SectionPassedBoxReward spbr;
};
typedef struct MopUpSectionResult MopUpSectionResult;

struct GetSectionScores //��ȡ�ؿ�����
{ 
	static const Type kType = kGetSectionScores;
};
typedef struct GetSectionScores GetSectionScores;

struct GetSectionScoresResult
{ 
	static const Type kType = kGetSectionScoresResult;
	uint16_t max_index;
	int8_t scores[2000];
};
typedef struct GetSectionScoresResult GetSectionScoresResult;

struct EnterMapArea
{ 
	static const Type kType = kEnterMapArea;
	uint16_t id;
};
typedef struct EnterMapArea EnterMapArea;

struct EnterMapAreaResult
{ 
	static const Type kType = kEnterMapAreaResult;
	Result result;
};
typedef struct EnterMapAreaResult EnterMapAreaResult;

struct EncounteredMonsters //���������ս�����̣��ƶ���ĳ�������ʱ��������Move2RoadLocationResult��OpenCurrentLocationBoxResultǰ����
{ 
	static const Type kType = kEncounteredMonsters;
	int16_t fight_record_bytes;
	int16_t rewards_count;
	uint8_t record[kMaxFightRecordLength]; //ʵ�ʳ�����ǰ���Ϊ׼�� ��¼Ϊѹ���������
	Reward rewards[8];
};
typedef struct EncounteredMonsters EncounteredMonsters;

struct Move2RoadLocation //�ƶ����Աߵ�һ��·��
{ 
	static const Type kType = kMove2RoadLocation;
	uint8_t location;
};
typedef struct Move2RoadLocation Move2RoadLocation;

struct Move2RoadLocationResult
{ 
	static const Type kType = kMove2RoadLocationResult;
	Result result;
	int32_t encountered_monsters; // ��0��ʾ�������﷢��ս��
	EncounteredMonsters em;
};
typedef struct Move2RoadLocationResult Move2RoadLocationResult;


struct OpenCurrentLocationBox //������
{ 
	static const Type kType = kOpenCurrentLocationBox;
};
typedef struct OpenCurrentLocationBox OpenCurrentLocationBox;

struct OpenCurrentLocationBoxResult
{ 
	static const Type kType = kOpenCurrentLocationBoxResult;
	Result result;
	int16_t rwds_count;
	int16_t encountered_monsters; // ��0��ʾ�������﷢��ս��
	Reward rewards[8]; //������ǰ���rwds_countΪ׼
	EncounteredMonsters em;
};
typedef struct OpenCurrentLocationBoxResult OpenCurrentLocationBoxResult;

struct GetArmyLocation //��ȡ���ӵ�λ��
{ 
	static const Type kType = kGetArmyLocation;
};
typedef struct GetArmyLocation GetArmyLocation;

struct ArmyLocation
{ 
	static const Type kType = kArmyLocation;
	uint16_t area; //���ڵĵ�ͼ���� 0��ʾ�ڳ���
	uint8_t location; //���ڵ�·��
};
typedef struct ArmyLocation ArmyLocation;

struct GetTaskStatus //��ȡ��������
{ 
	static const Type kType = kGetTaskStatus;
};
typedef struct GetTaskStatus GetTaskStatus;

#pragma pack(1)
struct TaskStatus  
{ 
	static const Type kType = kTaskStatus;
	uint16_t current_trunk_task; //��������id
	int32_t current_branch_task; //֧������id,      ע������ĳ���4�ֽ���������
	int8_t sub_trunk_task; //2������id��������δʹ��
	int8_t trunk_task_progress;
	int8_t sub_branch_task; 
	int8_t brach_task_progress;
};
#pragma pack()
typedef struct TaskStatus TaskStatus;

struct GetMapRandomBoxes //��ȡ��ǰ��ͼ�����box
{ 
	static const Type kType = kGetMapRandomBoxes;
};
typedef struct GetMapRandomBoxes GetMapRandomBoxes;

struct MapRandomBoxes
{ 
	static const Type kType = kMapRandomBoxes;
	uint16_t refresh_cd; //��һ�ε�ͼ����ˢ�µ���ȴʱ�䣨�룩
	uint16_t count;
	struct 
	{
		uint8_t location; //��������·��
		bool opened; //�Ƿ��Ѿ�����������
		uint16_t sid; //���ӵ�sid
	}boxes[16];
};
typedef struct MapRandomBoxes MapRandomBoxes;

struct BranchTask
{
	int16_t task; //����id
};
typedef struct BranchTask BranchTask;

struct GetAvailableTasks //��ȡ�ɽӵ�����
{ 
	static const Type kType = kGetAvailableTasks;
	int16_t area; //�����ͼ��id
};
typedef struct GetAvailableTasks GetAvailableTasks;

struct AvailableTasks
{ 
	static const Type kType = kAvailableTasks;
	uint32_t next_reset_time;
	int32_t count;
	int32_t tasks[4];
};
typedef struct AvailableTasks AvailableTasks;

typedef struct  //  ˢ�¿ɽ�����
{ 
	static const Type kType = kResetAvailableTasks;
	int32_t map;
}ResetAvailableTasks;

typedef struct 
{ 
	static const Type kType = kResetAvailableTasksResult;
	Result result;
}ResetAvailableTasksResult;



struct ReceiveTask //������
{ 
	static const Type kType = kReceiveTask;
	int32_t task;
};
typedef struct ReceiveTask ReceiveTask;

struct ReceiveTaskResult
{ 
	static const Type kType = kReceiveTaskResult;
	Result result;
};
typedef struct ReceiveTaskResult ReceiveTaskResult;

struct TryCompleteSubTask  //��ɵ�ǰ���ڽ��е�������
{ 
	static const Type kType = kTryCompleteSubTask;
};
typedef struct TryCompleteSubTask TryCompleteSubTask;

struct TryCompleteSubTaskResult
{ 
	static const Type kType = kTryCompleteSubTaskResult;
	Result result;
	int32_t has_encountered_monster; //0 δ���� 1����
	EncounteredMonsters em; //����Ǵ��  �������
};
typedef struct TryCompleteSubTaskResult TryCompleteSubTaskResult;

struct SubmitTask //������
{ 
	static const Type kType = kSubmitTask;
	bool next_task_depend_this; //  �Ƿ�ֱ�ӽ�ȡ����������һ��ϵ������
};
typedef struct SubmitTask SubmitTask;

struct SubmitTaskResult
{ 
	static const Type kType = kSubmitTaskResult;
	Result result;
};
typedef struct SubmitTaskResult SubmitTaskResult;

struct AbandonTask //��������
{ 
	static const Type kType = kAbandonTask;

};
typedef struct AbandonTask AbandonTask;

struct AbandonTaskResult
{ 
	static const Type kType = kAbandonTaskResult;
	Result result;
};
typedef struct AbandonTaskResult AbandonTaskResult;

struct TryCompleteTrunkTask //��ɵ�ǰ��������������ж�������񣬼���ʾ��ɵ�ǰ��������
{ 
	static const Type kType = kTryCompleteTrunkTask;
};
typedef struct TryCompleteTrunkTask TryCompleteTrunkTask;

struct TryCompleteTrunkTaskResult
{ 
	static const Type kType = kTryCompleteTrunkTaskResult;
	Result result;
};
typedef struct TryCompleteTrunkTaskResult TryCompleteTrunkTaskResult;


struct Convey // ���ͣ�վ�����͵��ϵ�ʱ�� �������Ϣ
{ 
	static const Type kType = kConvey;
};
typedef struct Convey Convey;

struct ConveyResult
{ 
	static const Type kType = kConveyResult;
	Result result;
};
typedef struct ConveyResult ConveyResult;


typedef struct _GetBossSectionStatus //��ȡӢ�۹ؿ���״��
{ 
	static const Type kType = kGetBossSectionStatus;
}GetBossSectionStatus;

typedef struct _BossSectionStatus //����ķ���ֵ
{ 
	static const Type kType = kBossSectionStatus;
	uint16_t	  max_avaialbe_section; //0��ʾ��û��
	uint8_t max_times; //�����ô���
	uint8_t used_times; //��ʹ�ô���
	int8_t killing_times[200]; //�±��ʾsid
}BossSectionStatus;

typedef struct _ChallengeBossSection //��ս��Ӣboss
{ 
	static const Type kType = kChallengeBossSection;
	uint16_t index;
	bool second_time; //�ٴ���ս
}ChallengeBossSection;

typedef struct _BossSectionRewards
{ 
	uint16_t gold;
	uint16_t feat;
	uint32_t silver;
	uint32_t hero_exp;
	PropSid prop;
}BossSectionRewards;

typedef struct _ChallengeBossSectionResult //���ֻ��ʾ��  ��ֱ��ʹ��
{ 
	static const Type kType = kChallengeBossSectionResult;
	Result result;
	bool  win;  //ս���Ƿ�ʤ��
	int8_t rewards_count;//����ĸ���
	int16_t fight_record_bytes; //ս�����ֽ���
	Reward rewards[8]; //ʵ�ʳ�����ǰ���countΪ׼
	uint8_t fight_record[kMaxFightRecordLength]; //ʵ�ʳ�����ǰ���bytesΪ׼����¼Ϊѹ���������
	BossSectionRewards section_rewards;
}ChallengeBossSectionResult;



struct GetStamina
{
	static const Type kType = kGetStamina;
};
typedef struct GetStamina GetStamina;

struct GetStaminaResult
{
	static const Type kType = kGetStaminaResult;
	uint32_t replenish_time;	//������������ʱ��
	uint32_t back_time;			//�ص�����ľ���
	uint16_t stamina_max;		//δʹ��
	uint16_t stamina;
	uint16_t stamina_take_max;	//Я������<ˮ��>����
	uint16_t stamina_take;
};
typedef struct GetStaminaResult GetStaminaResult;

struct PushStaminaInfo
{
	static const Type kType = kPushStaminaInfo;
	uint32_t replenish_time;	//������������ʱ��
	uint16_t stamina;			//����<ˮ��>
	uint16_t stamina_take;		//Я������<ˮ��>
};
typedef struct PushStaminaInfo PushStaminaInfo;

struct BackToMainCity
{
	static const Type kType = kBackToMainCity;
};
typedef struct BackToMainCity BackToMainCity;

struct BackToMainCityResult
{
	static const Type kType = kBackToMainCityResult;
	Result result;
};
typedef struct BackToMainCityResult BackToMainCityResult;

struct PushForceBackToMainCity
{
	static const Type kType = kPushForceBackToMainCity;
};
typedef struct PushForceBackToMainCity PushForceBackToMainCity;

struct ClearStaminaCD
{
	static const Type kType = kClearStaminaCD;
};
typedef struct ClearStaminaCD ClearStaminaCD;

struct ClearStaminaCDResult
{
	static const Type kType = kClearStaminaCDResult;
	Result result;
};
typedef struct ClearStaminaCDResult ClearStaminaCDResult;

struct ReplenishStamina
{
	static const Type kType = kReplenishStamina;
};
typedef struct ReplenishStamina ReplenishStamina;

struct ReplenishStaminaResult
{
	static const Type kType = kReplenishStaminaResult;
	Result result;
};
typedef struct ReplenishStaminaResult ReplenishStaminaResult;

struct ClearBackToTownCD
{
	static const Type kType = kClearBackToTownCD;
};
typedef struct ClearBackToTownCD ClearBackToTownCD;

struct ClearBackToTownCDResult
{
	static const Type kType = kClearBackToTownCDResult;
	Result result;
};
typedef struct ClearBackToTownCDResult ClearBackToTownCDResult;


enum Weather{kSunny, kRain, kCloudy, kSnow, kFog};
struct WeatherChanged //s2c ��������
{ 
	static const Type kType = kWeatherChanged;
	uint8_t weather; //���涨���ֵ
};
typedef struct WeatherChanged WeatherChanged;