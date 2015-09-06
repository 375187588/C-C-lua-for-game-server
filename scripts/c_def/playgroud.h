#pragma once

#include "define.h"

enum PlaygroudType
{
//�ͻ��˷�������˵���Ϣ
	//kPlayGroundBegin = 7000
	kGetFishingInfo = kPlayGroundBegin + 1,
	kGetFishKindRecord,
	kThrowFishingRod,
	kPullFishingRod,
	kThrowTorpedo,

	kRaceDragonGuess = kPlayGroundBegin+10,	//���뾺��
	kRaceDragonSignup,				//��������
	kGetRaceDragonCurStep,			//��ǰ�׶�
	kGetRaceDragonTime,				//����ʱ���<��ĳʱ�䵽ĳʱ��>
	kGetRaceDragonMyGuess,			//�ҵľ���
	kGetRaceDragonGuessInfo,		//����������Ϣ<�ܶ�>
	kGetRaceDragonMyLimit,			//�ҵľ����ܶ�����
	kGetRaceDragonToptenInfo,		//��ȡǰʮ������Ϣ
	kGetRaceDragonSeasonRank,		//������λ

	kRearDragonChangeName = kPlayGroundBegin+30,		//����
	kRearDragonRelease,				//����
	kRearDragonMate,				//����
	kGetDragonList,					//��������б�
	kRearDragonFeed,				//ι��
	kRearDragonResetMateTime,		//���ý���ʱ��
	//kGetRearDragonMateKind,			//��ý�����ܵõ�������

	kGetTurntableInfo = kPlayGroundBegin+40,//��ȡ����ת����Ϣ
	kTurnTurntable ,			//ת��
	kGetRewardTurntable,		//�콱

	kGetPlaygroundInfo = kPlayGroundBegin+50,		//��ȡ���ֳ���Ϣ

	kGetPlaygroundPropsInfo = kPlayGroundBegin+70,		//��ȡ������Ϣ
	kPlaygroundPropBuy,								//����
	kPlaygroundPropSell,							//����
	kNotifyPlaygourndPropReset,						//����


//	����˷���ȥ����Ϣ
	//kPlayGroundReturnBegin = 21000
	kGetFishingInfoResult = kPlayGroundReturnBegin +1,
	kGetFishKindRecordResult,
	kThrowFishingRodResult,
	kPullFishingRodResult,
	kThrowTorpedoResult,
	kFishingInfoReset,

	kRaceDragonGuessResult = kPlayGroundReturnBegin + 10,
	kRaceDragonSignupResult,
	kGetRaceDragonCurStepResult,
	kGetRaceDragonTimeResult,
	kGetRaceDragonMyGuessResult,
	kGetRaceDragonGuessInfoResult,
	kGetRaceDragonMyLimitResult,
	kNotifyRaceDragonCurStep,				//֪ͨ,��������ĳ�׶�
	kGetRaceDragonToptenInfoResult,
	kGetRaceDragonSeasonRankResult,

	kRearDragonChangeNameResult = kPlayGroundReturnBegin + 30,		//
	kRearDragonReleaseResult,
	kRearDragonMateResult,
	kGetDragonListResult,
	kRearDragonFeedResult,
	kRearDragonResetMateTimeResult,

	kGetNewDragonNotify,				//�������֪ͨ


	kGetTurntableInfoResult = kPlayGroundReturnBegin+40,
	kTurnTurntableResult,
	kGetRewardTurntableResult,
	kResetTurntableInfo,				//ת��������Ϣ,ÿ��0�����ô���

	kGetPlaygroundInfoResult = kPlayGroundReturnBegin+50,

	kGetPlaygroundPropsInfoResult = kPlayGroundReturnBegin+70,
	kPlaygroundPropBuyResult ,
	kPlaygroundPropSellResult,
};

enum FishResultType
{
	FISH_SUCCEEDED = 0,
	FISH_INVALID_VALUE = kPlayGroundReturnBegin,	//��Ч��ֵ
	FISH_INVALID_OPERATION,	//�Ƿ�����
	FISH_DISABLE,			//δ����
	FISH_NOT_IN_TIME,		//δ��ʱ����
	FISH_GOLD_NOT_ENOUGH,	//��Ҳ���
	FISH_NO_TIMES,			//�����ٵ���
	FISH_LOW_VIP_LEVEL,		//vip�ȼ�����
	FISH_BAG_LEACK_SPACE,	//�������Ӳ���
};

enum RaceDragonResultType
{
	RACE_DRAGON_SUCCEEDED = 0,
	RACE_DRAGON_INVALID = kPlayGroundReturnBegin+10,		//�Ƿ�������
	RACE_DRAGON_NOT_TIME,		//��ʱ����
	RACE_DRAGON_LIMIT_MONEY,	//Ͷע���ﵽ������
	RACE_DRAGON_ALREADY_SELECT,	//�Ѿ����й���Ͷע��
	RACE_DRAGON_SIGNUP,			//�Ѿ���������
	RACE_DRAGON_NOT_ENOUGH,		//Ǯ����Ŷ
};

enum RearDragonResultType
{
	REAR_DRAGON_SUCCEEDED = 0,
	REAR_DRAGON_INVALID = kPlayGroundReturnBegin+30,		//
	REAR_DRAGON_NOT_ENOUGH,		//Ǯ����
	REAR_DRAGON_RACING,			//�������������.
	REAR_DRAGON_FEED_FAIL,		//ιʳ��ʳ��ʧ��
	REAR_DRAGON_NOT_TIME,		//��ֳCDʱ����
	REAR_DRAGON_ROOM_LIMIT,		//��������
	REAR_DRAGON_MATE_FAILED,	//������û��������
	REAR_DRAGON_LACK_RSC,		//��Դ����<����ʳ��,�߻�����>
	REAR_DRAGON_PROPERTY_LIMIT,	//��������,��������ιʳ��
};

enum TurntableTurnResultType
{
	TURNTABLE_SUCCEEDED = 0,
	TURNTABLE_INVALID = kPlayGroundReturnBegin+40,
	TURNTABLE_INVALIDOPERATION,		//�Ƿ�����
	TURNTABLE_NO_TIMES,				//û��ʣ�������
	TURNTABLE_GOLD_NOT_ENOUGH,		//��Ҳ���
	TURNTABLE_SHOULD_GET_REWARD,	//����Ӧ����ȡ����
	TURNTABLE_DISABLE,				//δ����
};

enum PlaygroundPropResultType
{
	PP_SUCCEEDED = 0,
	PP_INVALID = kPlayGroundReturnBegin+70,
	PP_LackResource,			//��Դ����
	PP_AMOUNT_LIMIT,			//��������
	PP_LOW_VIP_LEVEL,			//vip�ȼ�����
	PP_LIMIT_BUY_COUNT,			//�����������
};




struct GetFishingInfo
{
	static const Type kType = kGetFishingInfo;
};
typedef struct GetFishingInfo GetFishingInfo;

struct GetFishingInfoResult
{
	static const Type kType = kGetFishingInfoResult;
	Result result;
	uint16_t fish_times;		//����ʣ��ɵ������
	uint16_t gold_times;		//����ʹ�ûƽ���ʹ���
	uint16_t torpedo_times;		//..����..
	uint16_t fisheries;			//�ѽ����泡,ÿһλ����һ���泡
};
typedef struct GetFishingInfoResult GetFishingInfoResult;

struct GetFishKindRecord
{
	static const Type kType = kGetFishKindRecord;
	uint8_t fishery;		//�泡
};
typedef struct GetFishKindRecord GetFishKindRecord;

struct FishKindRecord
{
	uint16_t  kind;		//fish kind(sid)
	uint16_t  weight;	//=0�ǽ����˵�û�е����<ֻ����Ҫ������,����=0>
};
typedef struct FishKindRecord FishKindRecord;

struct GetFishKindRecordResult
{
	static const Type kType = kGetFishKindRecordResult;
	Result result;
	int32_t amount;		//records����
	FishKindRecord records[20];
};
typedef struct GetFishKindRecordResult GetFishKindRecordResult;



struct FishReward
{
	uint16_t type;		//1: ����,    2: ��
	uint16_t kind;		//type�ǵ���ʱΪ����sid, ����ʱΪ���Kind
	uint32_t weight;	//�������Ч, �������*100,���õ�ʱҪ����100���������ʵ����
	uint32_t amount;	//�������Ч, ��ʾ��õĽ���,����1000����,10���,300����
};
typedef struct FishReward FishReward;

enum RodType { kNormalFishingRod=0, kGoldFishingRod=1, kTorpedoBomb=2 };
struct ThrowFishingRod
{
	static const Type kType = kThrowFishingRod;
	uint8_t fishery;		//�泡, 1,2,3,4,...
	uint8_t rod;			//
};
typedef struct ThrowFishingRod ThrowFishingRod;

struct ThrowFishingRodResult
{
	static const Type kType = kThrowFishingRodResult;
	Result result;
	uint32_t time;
};
typedef struct ThrowFishingRodResult ThrowFishingRodResult;

struct PullFishingRod
{
	static const Type kType = kPullFishingRod;
};
typedef struct PullFishingRod PullFishingRod;

struct PullFishingRodResult
{
	static const Type kType = kPullFishingRodResult;
	Result result;
	FishReward reward;
};
typedef struct PullFishingRodResult PullFishingRodResult;

struct ThrowTorpedo
{
	static const Type kType = kThrowTorpedo;
	uint8_t fishery;
};
typedef struct ThrowTorpedo ThrowTorpedo;

struct ThrowTorpedoResult
{
	static const Type kType = kThrowTorpedoResult;
	Result result;
	int32_t amount;			//reward������
	FishReward rewards[5];
};
typedef struct ThrowTorpedoResult ThrowTorpedoResult;

struct FishingInfoReset
{
	static const Type kType = kFishingInfoReset;
};
typedef struct FishingInfoReset FishingInfoReset;


//����

struct RaceDragonGuess
{
	static const Type kType = kRaceDragonGuess;
	int16_t	type;	//��������,����1-10, ��11,  ˫12
	int16_t money;	//��λΪ��
};
typedef struct RaceDragonGuess RaceDragonGuess;

struct RaceDragonGuessResult
{
	static const Type kType = kRaceDragonGuessResult;
	Result result;
};
typedef struct RaceDragonGuessResult RaceDragonGuessResult;

struct RaceDragonSignup
{
	static const Type kType = kRaceDragonSignup;
	int32_t	dragon_id;
};
typedef struct RaceDragonSignup RaceDragonSignup;

struct RaceDragonSignupResult
{
	static const Type kType = kRaceDragonSignupResult;
	Result result;
};
typedef struct RaceDragonSignupResult RaceDragonSignupResult;

struct GetRaceDragonCurStep
{
	static const Type kType = kGetRaceDragonCurStep;
};
typedef struct GetRaceDragonCurStep GetRaceDragonCurStep;

struct GetRaceDragonCurStepResult
{
	static const Type kType = kGetRaceDragonCurStepResult;
	Result	result;
	int16_t season;//����
	int16_t step;// 1 �ȴ���һ������;  2 ����;  3 ��ѡ����;		4 ����
	int32_t t_begin;
	int32_t t_end;
};
typedef struct GetRaceDragonCurStepResult GetRaceDragonCurStepResult;

struct NotifyRaceDragonCurStep
{
	static const Type kType = kNotifyRaceDragonCurStep;
	int16_t season;
	int16_t step;
	int32_t t_begin;
	int32_t t_end;
};
typedef struct NotifyRaceDragonCurStep NotifyRaceDragonCurStep;

struct GetRaceDragonTime
{
	static const Type kType = kGetRaceDragonTime;
	int8_t step;
};
typedef struct GetRaceDragonTime GetRaceDragonTime;

struct GetRaceDragonTimeResult
{
	static const Type kType = kGetRaceDragonTimeResult;
	Result result;
	int32_t t_begin;
	int32_t t_end;
};
typedef struct GetRaceDragonTimeResult GetRaceDragonTimeResult;

struct GetRaceDragonMyGuess
{
	static const Type kType = kGetRaceDragonMyGuess;
};
typedef struct GetRaceDragonMyGuess GetRaceDragonMyGuess;

struct GetRaceDragonMyGuessResult
{
	static const Type kType = kGetRaceDragonMyGuessResult;
	Result	result;
	//����, 1-10 ����,,  11 ��,, 12 ˫
	int16_t money[12];		//���½��, ��λΪ��
};
typedef struct GetRaceDragonMyGuessResult GetRaceDragonMyGuessResult;

struct GetRaceDragonGuessInfo
{
	static const Type kType = kGetRaceDragonGuessInfo;
};
typedef struct GetRaceDragonGuessInfo GetRaceDragonGuessInfo;

struct GetRaceDragonGuessInfoResult
{
	static const Type kType = kGetRaceDragonGuessInfoResult;
	Result	result;
	int16_t	peoples[12];	//��������
	int16_t odds[12];		//����
	int32_t money[12];		//�����ܶ�
};
typedef struct GetRaceDragonGuessInfoResult	GetRaceDragonGuessInfoResult;

struct GetRaceDragonToptenInfo
{
	static const Type kType = kGetRaceDragonToptenInfo;
};
typedef struct GetRaceDragonToptenInfo GetRaceDragonToptenInfo;

struct GetRaceDragonToptenInfoResult
{
	static const Type kType = kGetRaceDragonToptenInfoResult;
	Result result;
	int32_t len;
	struct RaceDragonToptenInfo
	{
		int32_t his_rank;
		int16_t	strength;
		int16_t agility;
		int16_t intellect;
		int16_t kind;		//
		int8_t  raceway;
		int8_t  d_state;	//1 ��,,,2 ��,,,, 3��ͨ
		int8_t  ch_name;	//�Ƿ�Ĺ���
		int8_t unuse1;
		DragonName d_name;
		Nickname p_name;
	}dragon[10];
};
typedef struct RaceDragonToptenInfo RaceDragonToptenInfo;
typedef struct GetRaceDragonToptenInfoResult GetRaceDragonToptenInfoResult;

struct GetRaceDragonMyLimit
{
	static const Type kType = kGetRaceDragonMyLimit;
};
typedef struct GetRaceDragonMyLimit GetRaceDragonMyLimit;

struct GetRaceDragonMyLimitResult
{
	static const Type kType = kGetRaceDragonMyLimitResult;
	Result result;
	int16_t limit;	//����,��
};
typedef struct GetRaceDragonMyLimitResult GetRaceDragonMyLimitResult;

struct GetRaceDragonSeasonRank
{
	static const Type kType = kGetRaceDragonSeasonRank;
	int16_t season;	//ָ����ȡ����
};
typedef struct GetRaceDragonSeasonRank GetRaceDragonSeasonRank;

struct RaceDragonRankInfo
{
	uint32_t live1;		//--2:23-1:0 : ��·<2λ��ʾһ��״̬>< 0 ����,, 1 ����,, 2,,����  3,,��� >
	uint32_t live2;		//--2:30-2:24: section<7λ>,,
	int32_t  speed;		//100%�ٶ�
	int8_t rank;
	int8_t raceway;
	uint8_t kind;
	int8_t  ch_name;	//�Ƿ�Ĺ���
	DragonName d_name;
	Nickname   p_name;
};
typedef struct RaceDragonRankInfo RaceDragonRankInfo;

struct GetRaceDragonSeasonRankResult
{
	static const Type kType = kGetRaceDragonSeasonRankResult;
	Result result;
	int32_t len;
	RaceDragonRankInfo info[10];
};
typedef struct GetRaceDragonSeasonRankResult GetRaceDragonSeasonRankResult;





//-----------����
struct RearDragonChangeName
{
	static const Type kType = kRearDragonChangeName;
	int32_t		 dragon_id;
	DragonName	 d_name;
};
typedef struct RearDragonChangeName RearDragonChangeName;

struct RearDragonChangeNameResult
{
	static const Type kType = kRearDragonChangeNameResult;
	Result result;
};
typedef struct RearDragonChangeNameResult RearDragonChangeNameResult;

struct RearDragonRelease
{
	static const Type kType = kRearDragonRelease;
	int32_t dragon_id;
};
typedef struct RearDragonRelease RearDragonRelease;

struct RearDragonReleaseResult
{
	static const Type kType = kRearDragonReleaseResult;
	Result result;
	int32_t amount;		//�һ�ȯ����
};
typedef struct RearDragonReleaseResult RearDragonReleaseResult;



struct GetDragonList
{
	static const Type kType = kGetDragonList;
};
typedef struct GetDragonList GetDragonList;

struct DragonInfo
{
	int32_t dragon_id;
	int32_t his_rank;
	int32_t m_time;		//����ʱ��
	int16_t strength;
	int16_t agility;
	int16_t intellect;
	int16_t max_str;
	int16_t max_agi;
	int16_t max_int;
	int16_t kind;
	int16_t unuse1;
	int8_t  sex;
	int8_t  signup;
	int8_t  ch_name;
	int8_t  unuse2;
	DragonName d_name;
};
typedef struct DragonInfo DragonInfo;

struct GetDragonListResult
{
	static const Type kType = kGetDragonListResult;
	Result result;
	int8_t len;
	int8_t rooms;
	int16_t unuse;
	DragonInfo dragon[9];
};
typedef struct GetDragonListResult GetDragonListResult;

struct RearDragonFeed
{
	static const Type kType = kRearDragonFeed;
	int32_t dragon_id;
	int32_t food_kind;
};
typedef struct RearDragonFeed RearDragonFeed;

struct RearDragonFeedResult
{
	static const Type kType = kRearDragonFeedResult;
	Result result;
	int16_t strength;
	int16_t agility;
	int16_t intellect;
	int16_t unuse;
};
typedef struct RearDragonFeedResult RearDragonFeedResult;

struct RearDragonMate
{
	static const Type kType = kRearDragonMate;
	int32_t dragon_fid;
	int32_t dragon_mid;
	int32_t agent_kind;		//�߻���
};
typedef struct RearDragonMate RearDragonMate;

struct RearDragonMateResult
{
	static const Type kType = kRearDragonMateResult;
	Result result;
	DragonInfo dragon;
};
typedef struct RearDragonMateResult RearDragonMateResult;

struct RearDragonResetMateTime
{
	static const Type kType = kRearDragonResetMateTime;
	int32_t dragon_id;
};
typedef struct RearDragonResetMateTime RearDragonResetMateTime;

struct RearDragonResetMateTimeResult
{
	static const Type kType = kRearDragonResetMateTimeResult;
	Result result;
};
typedef struct RearDragonResetMateTimeResult RearDragonResetMateTimeResult;

struct GetNewDragonNotify
{
	static const Type kType = kGetNewDragonNotify;
	DragonInfo dragon;
};
typedef struct GetNewDragonNotify GetNewDragonNotify;





//------------����ת��
struct GetTurntableInfo
{
	static const Type kType = kGetTurntableInfo;
};
typedef struct GetTurntableInfo GetTurntableInfo;

struct GetTurntableInfoResult
{
	static const Type kType = kGetTurntableInfoResult;
	Result result;
	int16_t results;//ת�����龰<ÿһλ����һ��λ��, 1:��ͼ��, 0:Ϊͼ��>
	int16_t re_times;//������ת����
	int8_t  cur_point;//��ǰָ��λ��
	int8_t  times;//ʣ��ת�ִ���
	int8_t  should_return;//�Ƿ�Ӧ����ת
};
typedef struct GetTurntableInfoResult GetTurntableInfoResult;

struct TurnTurntable
{
	static const Type kType = kTurnTurntable;
};
typedef struct TurnTurntable TurnTurntable;

struct TurnTurntableResult
{
	static const Type kType = kTurnTurntableResult;
	Result result;
	int16_t results;		//����ת�̵��龰
	int8_t  cur_point;		//��ǰָ��λ��
};
typedef struct TurnTurntableResult TurnTurntableResult;

struct GetRewardTurntable
{
	static const Type kType = kGetRewardTurntable;
};
typedef struct GetRewardTurntable GetRewardTurntable;

struct GetRewardTurntableResult
{
	static const Type kType = kGetRewardTurntableResult;
	Result result;
	int32_t amount;	//����ֵ
};
typedef struct GetRewardTurntableResult GetRewardTurntableResult;

struct ResetTurntableInfo
{
	static const Type kType = kResetTurntableInfo;
};
typedef struct ResetTurntableInfo ResetTurntableInfo;




//���ֳ�
struct GetPlaygroundInfo
{
	static const Type kType = kGetPlaygroundInfo;
};
typedef struct GetPlaygroundInfo GetPlaygroundInfo;

struct GetPlaygroundInfoResult
{
	static const Type kType = kGetPlaygroundInfoResult;
	int32_t tickets;
};
typedef struct GetPlaygroundInfoResult GetPlaygroundInfoResult;





//����
struct GetPlaygroundPropsInfo
{
	static const Type kType = kGetPlaygroundPropsInfo;
};
typedef struct GetPlaygroundPropsInfo GetPlaygroundPropsInfo;

struct PlaygroundProp
{
	int16_t kind;
	int16_t amount;
	int16_t buy_count;
	int16_t unuse1;
};
typedef struct PlaygroundProp PlaygroundProp;

struct GetPlaygroundPropsInfoResult
{
	static const Type kType = kGetPlaygroundPropsInfoResult;
	Result result;
	int32_t amount;
	PlaygroundProp prop[256];
};
typedef struct GetPlaygroundPropsInfoResult GetPlaygroundPropsInfoResult;

struct PlaygroundPropBuy
{
	static const Type kType = kPlaygroundPropBuy;
	uint8_t prop_index;
};
typedef struct PlaygroundPropBuy PlaygroundPropBuy;

struct PlaygroundPropBuyResult
{
	static const Type kType = kPlaygroundPropBuyResult;
	Result result;
};
typedef struct PlaygroundPropBuyResult PlaygroundPropBuyResult;

struct NotifyPlaygourndPropReset
{
	static const Type kType = kNotifyPlaygourndPropReset;
};
typedef struct NotifyPlaygourndPropReset NotifyPlaygourndPropReset;