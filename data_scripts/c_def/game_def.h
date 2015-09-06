#pragma once
#pragma pack(4)
#include "define.h"


enum ResourceType {kGoldRsc=1, kSilverRsc=2, kEnergyRsc=3, kLordExpRsc=4, kPropRsc=5, kFeatRsc=6, kPrestigeRsc=7, kHeroExpRsc=8,
	kMobilityRsc=9, kRechargedGold=10, kTicketsRsc=11, kAlchemyRsc=12, kProsperityDegree=13, kActivityRsc=14, kPowerRsc=15, 
	kStaminaTakeRsc=16};
typedef enum ResourceType RewardType;
enum PropType{kPropEquipment=1, kPropMaterial, kPropContainer, kPropSystem,  kPropGem, kPropResource, kPropFormula, kPropPlaygroundFood, kPropPlaygroundAgent, kPropPlaygroundEgg };
enum HoleStatus{kHoleNone, kHoleDisable, kHoleEnable, kHoleInlayed};
enum HeroStatus{kHeroDisable, kHeroInGroup, kHeroDismissed};

struct Reward  //����
{
	uint16_t type;  // ����� RewardType
	uint16_t kind; //���ֵֻ�е��ߣ�Prop���õ���
	uint32_t amount;
};
typedef struct Reward Reward;


enum GameMainType
{
	//9000
	//��ʼ״̬��ȡ
	kGetPlayerBaseInfo = kGameMainTypeBegin+1,
	kGetMyProps = kGameMainTypeBegin+2,
	kGetMyEquipment = kGameMainTypeBegin+3,
	kGetMyHeros = kGameMainTypeBegin+4,
	kGetMyHeroEquipment = kGameMainTypeBegin+5,
	kGetMyFormulas = kGameMainTypeBegin+6,
	kGetMyHeroProperty = kGameMainTypeBegin+7,
	kGetSkillsLevel = kGameMainTypeBegin+8,
	kGetArraysLevel = kGameMainTypeBegin+9,


	//���ߡ�װ���뱳�����ֿ����
	kMoveProp = kGameMainTypeBegin+101,
	kOverlapProp = kGameMainTypeBegin+102,
	kSellProp = kGameMainTypeBegin+103,
	kDropProp = kGameMainTypeBegin+104,
	kRearrangeProp = kGameMainTypeBegin+105,
	kBuyProp = kGameMainTypeBegin+106,
	kUseProp = kGameMainTypeBegin+107,
	kRenameEquipment = kGameMainTypeBegin+108,
	kUnlockPropGrid = kGameMainTypeBegin+109,
	kRepurchase = kGameMainTypeBegin+110,
	kEquipHero = kGameMainTypeBegin+111,
	kTakeOff = kGameMainTypeBegin+112,
	kStrengthen = kGameMainTypeBegin+113,
	kActiveHole = kGameMainTypeBegin+114,
	kInlay = kGameMainTypeBegin+115,
	kCompoundGem =kGameMainTypeBegin+116,
	kEquipmentPropertyMigrate = kGameMainTypeBegin+117,
	kEquipCompound = kGameMainTypeBegin+118,
	kBuyEquip2Hero = kGameMainTypeBegin+119,
	//	kPlayerGoldChanged = kGameMainTypeBegin+20,
	//	kPlayerSilverChanged = kGameMainTypeBegin+21,
	//	kPlayerEnergyChanged = kGameMainTypeBegin+22,
	//	kPlayerLordExpChanged = kGameMainTypeBegin+23,
	//	kPlayerPropChanged = kGameMainTypeBegin+27,

	//Ӣ��
	kRecruitHero = kGameMainTypeBegin+201,
	kDismissHero = kGameMainTypeBegin+202,
	kGetHerosRecruitable = kGameMainTypeBegin+203,
	kChangeHeroArray = kGameMainTypeBegin+204,
	kChangeHeroLocation = kGameMainTypeBegin+205,
	kUpgradeSkill = kGameMainTypeBegin+206,
	kGetMyHeroDetail = kGameMainTypeBegin+207,
	kGetBringupProperty = kGameMainTypeBegin+208,
	kApplyBringup = kGameMainTypeBegin+209,
	kAcceptBringup = kGameMainTypeBegin+210,
	kGetHeroArray = kGameMainTypeBegin+218,

	//�����Ӣ��ѵ��
	kGetTrainingNum = kGameMainTypeBegin + 219,
	kBuyTrainingNum = kGameMainTypeBegin + 220,
	kTraining = kGameMainTypeBegin + 221,
	
	//����Ӣ��
	kEvolveHero = kGameMainTypeBegin + 230,
	
	//����ѵ������                                                                                                                                                    
	kPushTrainNum = kSocietyTypeBegin + 510,
	//////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////
	kGameBaseInfo = kGameMainTypeBegin+800,
	kHero,
	kEquipment4Client,
	//֪ͨ
	kPropsAlteration,
	kResourceDelta,
	kUseProp4Container,
	//////////////////////////////////////////////////////////////////////////


	kGameOperationException = kGameMainTypeBegin+998, 
	kGameMainTypeEnd = kGameMainTypeBegin+999,

	/////////////////////////////////////////////////////////////////////////////�����Ƿ���ֵ
	//15000
	kPlayerBaseInfo = kGameReturnBegin+1,
	kMyProps = kGameReturnBegin+2,
	kMyEquipment = kGameReturnBegin+3,
	kMyHeros = kGameReturnBegin+4,
	kMyHeroEquipment = kGameReturnBegin+5,
	kMyFormulas = kGameReturnBegin+6,
	kMyHeroProperty = kGameReturnBegin+7,
	kSkillsLevel = kGameReturnBegin+8,
	kArraysLevel = kGameReturnBegin+9,

	kMovePropResult = kGameReturnBegin+101,
	kOverlapPropResult = kGameReturnBegin+102,
	kSellPropResult = kGameReturnBegin+103,
	kDropPropResult = kGameReturnBegin+104,
	kRearrangePropResult = kGameReturnBegin+105,
	kBuyPropResult = kGameReturnBegin+106,
	kUsePropResult = kGameReturnBegin+107,
	kRenameEquipmentResult = kGameReturnBegin+108,
	kUnlockPropGridResult = kGameReturnBegin+109,
	kRePurchaseResult = kGameReturnBegin+110,
	kEquipHeroResult = kGameReturnBegin+111,
	kTakeOffResult = kGameReturnBegin+112,
	kStrengthenResult = kGameReturnBegin+113,
	kActiveHoleResult = kGameReturnBegin+114,
	kInlayResult = kGameReturnBegin+115,
	kCompoundGemResult =kGameReturnBegin+116,
	kEquipmentPropertyMigrateResult = kGameReturnBegin+117,
	kEquipCompoundResult = kGameReturnBegin+118,
	kBuyEquip2HeroResult = kGameReturnBegin+119,

	kRecruitHeroResult = kGameReturnBegin+201,
	kDismissHeroResult = kGameReturnBegin+202,
	kGetHerosRecruitableResult = kGameReturnBegin+203,
	kChangeHeroArrayResult = kGameReturnBegin+204,
	kChangeHeroLocationResult = kGameReturnBegin+205,
	kUpgradeSkillResult = kGameReturnBegin+206,
	kHeroDetail = kGameReturnBegin+207,
	kBringupProperty = kGameReturnBegin+208,
	kApplyBringupResult = kGameReturnBegin+209,
	kAcceptBringupResult = kGameReturnBegin+210,
	kStartTrainResult = kGameReturnBegin+213,
	kGetHeroArrayResult = kGameReturnBegin+218,
	//����ӷ���ֵ
	kResultTrainingNum = kGameReturnBegin + 219,
	kResultBuyTrainingNum = kGameReturnBegin + 220,
	kTrainingResult = kGameReturnBegin + 221,
	
	
	kEvolveHeroResult = kGameReturnBegin + 230,

	kHeroLevelUp = kGameReturnBegin+ 501,
};

struct GameOperationException //���������쳣ʱ���أ���Ҫ��������
{
	static const Type kType = kGameOperationException;
	int16_t operation_type;
	StringLength len;
	char error[2048];
};
typedef struct GameOperationException GameOperationException;

struct GameBaseInfo
{
	static const Type kType = kGameBaseInfo;
	UserID uid;
	int32_t gold; //����
	double silver; //��Ϸ��
	int32_t feat; //����
	int32_t prestige; //����
	int16_t energy; //����������
	int16_t mobility; //�ж���
	int32_t lord_experience; //exp
	int16_t level;  //�ȼ�
	int16_t progress; //���߽��ȣ��ؿ�sid
	uint8_t country;
	uint8_t array; //����
	uint16_t vip;//���VIP�ȼ�
	uint32_t recharged_gold; //��ֵ���
	uint32_t guild_id;	//����ID
	uint32_t power;//ս����
};
typedef struct GameBaseInfo GameBaseInfo;

struct GetPlayerBaseInfo
{
	static const Type kType = kGetPlayerBaseInfo;
	UserID uid;
};
typedef struct GetPlayerBaseInfo GetPlayerBaseInfo;

struct PlayerBaseInfo
{
	static const Type kType = kPlayerBaseInfo;
	Role role;
	GameBaseInfo game_info;
};
typedef struct PlayerBaseInfo PlayerBaseInfo;

typedef int8_t HeroSid;

struct Bringup
{
	uint16_t strength;				//��������
	uint16_t agility;
	uint16_t intelligence;
};
typedef struct Bringup Bringup;

struct BringupBin
{
	uint16_t strength;				//ԭʼ����
	uint16_t agility;
	uint16_t intelligence;
	uint16_t changes_strength;		//������ֵ
	uint16_t changes_agility;
	uint16_t changes_intelligence;
};
typedef struct BringupBin BringupBin;

struct Hero // (�����ݿ����͹����Ľṹ)
{
	static const Type kType = kHero;
	HeroSid id;
	int8_t status; //1�ڶ����� 
	uint8_t level;
	int8_t location; //�������е�λ��
	int32_t exp;
	int32_t hp;
	BringupBin bringup_bin;		//������ֵ
};
typedef struct Hero Hero;

struct HeroProperty
{
	HeroSid id;
	int8_t status; //1�ڶ����� 
	uint8_t level;
	int8_t location; //�������е�λ��
	int32_t exp;
	int32_t hp;
	uint16_t strength;	//ԭʼ����
	uint16_t agility;
	uint16_t intelligence;
	uint16_t speed;
	uint32_t power;//ս����
};
typedef struct HeroProperty HeroProperty;
/*
*/

typedef uint32_t PropID;
typedef uint16_t PropSid;

#pragma pack(1)
struct Prop4Client //����
{
	PropID id;
	PropSid kind;
	uint8_t location; //λ�ã������������enum PropLocation��
	uint8_t amount;
	uint8_t bind;//�Ƿ��Ѿ���
	uint8_t unused1;
	uint16_t unuesd2;
};
#pragma pack()
typedef struct Prop4Client Prop4Client;


struct Equipment4Client //װ��
{
	static const Type kType = kEquipment4Client;
	uint8_t level;
	uint8_t base_strength;
	uint8_t base_agility;
	uint8_t base_intelligence;
	int8_t holes[3]; //0=�޿� 1=�п�δ���� 2=�Ѽ���δ��Ƕ 3=����Ƕ
	bool unused; //
	PropSid gems[3]; //3��λ����Ƕ�ı�ʯ 
};
typedef struct Equipment4Client Equipment4Client;


enum PropArea{kAreaBag=1, kAreaWarehouse=2, kAreaHero=3, kAreaSold=4, kAreaGem=5, kAreaAuction=6, kAreaMail=7};

struct GetMyProps // c2s, ��ȡ���еĵ��߻�����Ϣ������װ��
{
	static const Type kType = kGetMyProps;
	int8_t area; //1=������2=�ֿ�, 3=װ���� 4=�ع��� 5=��ʯ��
};
typedef struct GetMyProps GetMyProps;

struct MyProps //s2c, ������Ϣ�ķ��أ�  ���е�װ��
{
	static const Type kType = kMyProps;
	int16_t grids_count; //����һ���ж��ٸ�����
	int16_t count; //ע��������2���ֽ�
	Prop4Client props[256]; //ʵ����Ч������count����
};
typedef struct MyProps MyProps;

struct GetMyEquipment //c2s,��ȡĳ��װ�������� 
{
	static const Type kType = kGetMyEquipment;
	PropID id; //����id
};
typedef struct GetMyEquipment GetMyEquipment;

struct MyEquipment //s2c ,������Ϣ�ķ���
{
	static const Type kType = kMyEquipment;
	Equipment4Client equipment;
};
typedef struct MyEquipment MyEquipment;

struct Prop4Container
{
	PropSid kind;
	uint16_t amount;
};
typedef struct Prop4Container Prop4Container;

struct UseProp4Container
{
	static const Type kType = kUseProp4Container;
	uint32_t amount;
	Prop4Container props[12];
};
typedef struct UseProp4Container UseProp4Container;


struct GetMyHeros
{
	static const Type kType = kGetMyHeros;
};
typedef struct GetMyHeros GetMyHeros;

struct MyHeros
{
	static const Type kType = kMyHeros;
	int32_t count;
	HeroSid heros[200];
};
typedef struct MyHeros MyHeros;

struct GetMyHeroProperty
{
	static const Type kType = kGetMyHeroProperty;
	HeroSid id;
};
typedef struct GetMyHeroProperty GetMyHeroProperty;

struct MyHeroProperty	
{
	static const Type kType = kMyHeroProperty;
	HeroProperty hero;
};
typedef struct MyHeroProperty MyHeroProperty;


//����//////////////////////////////////////////////////////////////
struct GetBringupProperty		//c2s ���󷵻�Ӣ����������
{
	static const Type kType = kGetBringupProperty;
	HeroSid id;
};
typedef struct GetBringupProperty GetBringupProperty;

struct BringupProperty			//s2c ������������
{
	static const Type kType = kBringupProperty;
	Bringup cur;				//��ǰ����ֵ
	Bringup max;				//��������
	uint16_t no_saved;			//�ϴ��Ƿ񱣴�	1-δ���� 0-�ѱ���
	Bringup changes;			//�ϴ�������ֵ��δ���������ֵ��
};
typedef struct BringupProperty BringupProperty;

struct ApplyBringup				//c2s ����
{
	static const Type kType = kApplyBringup;
	HeroSid id;
	uint8_t type;				//1-��ͨ���� 2-������� 3-�ƽ����� 4-�׽�����
};
typedef struct ApplyBringup ApplyBringup;

struct ApplyBringupResult		//s2c
{
	static const Type kType = kApplyBringupResult;
	Bringup bringup;			//������ֵ��δ�����ֵ��
};
typedef struct ApplyBringupResult ApplyBringupResult;

struct AcceptBringup			//c2s ����������ֵ
{
	static const Type kType = kAcceptBringup;
	HeroSid id;
	uint8_t type;				//1-���� 2-����
};
typedef struct AcceptBringup AcceptBringup;

struct AcceptBringupResult		//s2c
{
	static const Type kType = kAcceptBringupResult;
	Result result;
};
typedef struct AcceptBringupResult AcceptBringupResult;

struct GetMyHeroEquipment
{
	static const Type kType = kGetMyHeroEquipment;
	HeroSid hero_id;
};
typedef struct GetMyHeroEquipment GetMyHeroEquipment;

struct MyHeroEquipment
{
	static const Type kType = kMyHeroEquipment;
	int32_t count;
	Prop4Client equipments[8];
};
typedef struct MyHeroEquipment MyHeroEquipment;

struct GetMyFormulas //��ȡ�ϳ��䷽
{
	static const Type kType = kGetMyFormulas;
};
typedef struct GetMyFormulas GetMyFormulas;

struct MyFormulas //�ϳ��䷽
{
	static const Type kType = kMyFormulas;
	enum {MAX_COUNT=300};
	uint16_t count;
	uint16_t kinds[MAX_COUNT]; //�䷽��sid
};
typedef struct MyFormulas MyFormulas;

//////////////////////////////////////////////////////////////////////////////////////////

struct GetSkillsLevel //��ȡ���ܵĵȼ�
{ 
	static const Type kType = kGetSkillsLevel;
};
typedef struct GetSkillsLevel GetSkillsLevel;

struct SkillLevel
{
	uint8_t sid;
	uint8_t level;
};
typedef struct SkillLevel SkillLevel;

struct SkillsLevel  //GetSkillsLevel�ķ���
{ 
	static const Type kType = kSkillsLevel;
	uint16_t count;
	SkillLevel values[128];
};
typedef struct SkillsLevel SkillsLevel;

//////////////////////////////////////////////////////////////////////////////////////////

struct UpgradeSkill //�����Ƽ�
{ 
	static const Type kType = kUpgradeSkill;
	uint8_t sid;
};
typedef struct UpgradeSkill UpgradeSkill;

struct UpgradeSkillResult
{ 
	static const Type kType = kUpgradeSkillResult;
	Result result;
};
typedef struct UpgradeSkillResult UpgradeSkillResult;

//////////////////////////////////////////////////////////////////////////////////////////

struct GetArraysLevel //��ȡ���εĵȼ�
{ 
	static const Type kType = kGetArraysLevel;
};
typedef struct GetArraysLevel GetArraysLevel;

struct ArraysLevel  //GetArrayLevel�ķ���
{ 
	static const Type kType = kArraysLevel;
	uint16_t count;
	SkillLevel values[32];
};
typedef struct ArraysLevel ArraysLevel;


//////////////////////////////////////////////////////////////////////////////////////////






struct MoveProp //�ڱ������ֿ��ڲ������֮���ƶ�����
{
	static const Type kType = kMoveProp;
	PropID id;
	int8_t new_area; //1=������2=�ֿ�
	uint8_t new_location; //�µ�λ�� 
};
typedef struct MoveProp MoveProp;

struct MovePropResult
{
	static const Type kType = kMovePropResult;
	Result result;
};
typedef struct MovePropResult MovePropResult;

struct OverlapProp //�ѵ�����
{
	static const Type kType = kOverlapProp;
	PropID a; //��a����b��
	PropID b;
};
typedef struct OverlapProp OverlapProp;

struct OverlapPropResult 
{
	static const Type kType = kOverlapPropResult;
	Result result;
	uint8_t a_amount;
	uint8_t b_amount;
};
typedef struct OverlapPropResult OverlapPropResult;

struct SellProp //����
{
	static const Type kType = kSellProp;
	PropID id;
};
typedef struct SellProp SellProp;

struct SellPropResult
{
	static const Type kType = kSellPropResult;
	Result result;
	int32_t price;
};
typedef struct SellPropResult SellPropResult;

struct DropProp //����
{
	static const Type kType = kDropProp;
	PropID id;
};
typedef struct DropProp DropProp;

struct DropPropResult
{
	static const Type kType = kDropPropResult;
	Result result;
};
typedef struct DropPropResult DropPropResult;

struct RearrangeProp //����
{
	static const Type kType = kRearrangeProp;
	int8_t area;
};
typedef struct RearrangeProp RearrangeProp;

struct RearrangePropResult
{
	static const Type kType = kRearrangePropResult;
	Result result;
};
typedef struct RearrangePropResult RearrangePropResult;

struct BuyProp //����
{
	static const Type kType = kBuyProp;
	uint8_t shop;
	uint8_t prop_index;
	uint8_t location; //�ŵ������е�λ��
};
typedef struct BuyProp BuyProp;

struct BuyPropResult
{
	static const Type kType = kBuyPropResult;
	Result result;
	PropID id;
};
typedef struct BuyPropResult BuyPropResult;

struct UseProp //ʹ��
{
	static const Type kType = kUseProp;
	PropID id;
	uint8_t amount;
};
typedef struct UseProp UseProp;

struct UsePropResult
{
	static const Type kType = kUsePropResult;
	Result result;
};
typedef struct UsePropResult UsePropResult;

struct RenameEquipment //������װ��
{
	static const Type kType = kRenameEquipment;
	PropID id;
	StringLength len;
	char name[24];
};
typedef struct RenameEquipment RenameEquipment;

struct RenameEquipmentResult
{
	static const Type kType = kRenameEquipmentResult;
	Result result;
};
typedef struct  RenameEquipmentResult RenameEquipmentResult;

struct  UnlockPropGrid //������
{
	static const Type kType = kUnlockPropGrid;
	int8_t area;
	uint8_t count;
};
typedef struct UnlockPropGrid UnlockPropGrid;

struct UnlockPropGridResult
{
	static const Type kType = kUnlockPropGridResult;
	Result result;
};
typedef struct UnlockPropGridResult UnlockPropGridResult;

struct Repurchase //�ع������ĵ���
{
	static const Type kType = kRepurchase;
	PropID id;
	uint8_t location; //�ŵ������е�λ��
};
typedef struct Repurchase Repurchase;

struct RepurchaseResult
{
	static const Type kType = kRePurchaseResult;
	Result result;
};
typedef struct RepurchaseResult RepurchaseResult;

enum EquipmentLocation 
{
	klHat=0,		//ͷ��
	klFrock=1,	//�·�
	klMantle=2,		//����
	klMainHand=3,		//����
	klJewelry=4,		//����
	klTrousers=5,		//����
	klShoes=6,		//Ь��
	klDeputyHand=7,		//����
};

struct BuyEquip2Hero
{
	static const Type kType = kBuyEquip2Hero;
	uint8_t shop;
	uint8_t prop_index;
	HeroSid hero_id;
	uint8_t location; //Ӣ�۵�װ������ϵ�λ�� EquipmentLocation
};
typedef struct BuyEquip2Hero BuyEquip2Hero;

struct BuyEquip2HeroResult
{
	static const Type kType = kBuyEquip2HeroResult;
	Result result;
	PropID id;
};
typedef struct BuyEquip2HeroResult BuyEquip2HeroResult;

struct EquipHero //��װ����Ӣ����
{
	static const Type kType = kEquipHero;
	PropID prop;
	HeroSid hero;
	uint8_t location; //Ӣ�۵�װ������ϵ�λ�� EquipmentLocation
};
typedef struct EquipHero EquipHero;

struct EquipHeroResult
{
	static const Type kType = kEquipHeroResult;
	Result result;
};
typedef struct EquipHeroResult EquipHeroResult;

struct TakeOff //����Ӣ�۵�װ��
{
	static const Type kType = kTakeOff;
	PropID prop;
	HeroSid hero;
	uint8_t location; //�������λ��
};
typedef struct TakeOff TakeOff;

struct TakeOffResult
{
	static const Type kType = kTakeOffResult;
	Result result;
};
typedef struct TakeOffResult TakeOffResult;

struct Strengthen //c2s ǿ��
{
	static const Type kType = kStrengthen;
	PropID id;
};
typedef struct Strengthen Strengthen;

struct StrengthenResult //s2c
{
	static const Type kType = kStrengthenResult;
	Result result;
};
typedef struct StrengthenResult StrengthenResult;

struct  ActiveHole //c2s ����װ���Ŀ�
{
	static const Type kType = kActiveHole;
	PropID id;
	uint32_t hole;//0,1,2�׵�����
};
typedef struct ActiveHole ActiveHole;

struct ActiveHoleResult //s2c 
{
	static const Type kType = kActiveHoleResult;
	Result result;
};
typedef struct ActiveHoleResult ActiveHoleResult;

struct Inlay //c2s ��Ƕ��ʯ
{
	static const Type kType = kInlay;
	PropID equipment;
	PropID inlay_gem;		//���ĸ���ʯǶ��
	PropID dis_gem;			//���µı�ʯ�������ĸ���ʯ��
	uint8_t hole; //0,1,2   �׵�����
	uint8_t b_inlay;	//Ƕ��(1)	ж��(0)
};
typedef struct Inlay Inlay;

struct InlayResult //s2c
{
	static const Type kType = kInlayResult;
	Result result;
};
typedef struct InlayResult InlayResult;

struct CompoundGem //�ϳɱ�ʯkAreaGem
{
	static const Type kType = kCompoundGem;
	uint16_t formula_kind; //�䷽sid
	uint16_t b_direct;		//�Ƿ�һ���ϳ�
};
typedef struct CompoundGem CompoundGem;

struct CompoundGemResult
{
	static const Type kType = kCompoundGemResult;
	Result result;
	PropSid gem; //�õ��ı�ʯ����
	uint8_t amount; //��ʯ������
};
typedef struct CompoundGemResult CompoundGemResult;

struct EquipmentPropertyMigrate //װ������ת�ƣ����������ݡ���������source��dest
{ 
	static const Type kType = kEquipmentPropertyMigrate;
	PropID source;  
	PropID dest;
};
typedef struct EquipmentPropertyMigrate EquipmentPropertyMigrate;

struct EquipmentPropertyMigrateResult
{ 
	static const Type kType = kEquipmentPropertyMigrateResult;
	Result result;
};
typedef struct EquipmentPropertyMigrateResult EquipmentPropertyMigrateResult;

struct EquipCompound
{
	static const Type kType = kEquipCompound;
	PropID	 equip_id;			//�������ٵ�װ��id
	uint16_t b_reserved;		//�Ƿ�����ʯ�Ͷ���
	uint16_t b_direct;			//�Ƿ�ֱ������װ��
};
typedef struct EquipCompound EquipCompound;

struct EquipCompoundResult
{
	static const Type kType = kEquipCompoundResult;
	Result result;
	PropID equip_id;		//�����װ��id
};
typedef struct EquipCompoundResult EquipCompoundResult;












/////////////////////////////////////////////Ӣ��

struct RecruitHero //��ļ
{
	static const Type kType = kRecruitHero;
	HeroSid hero;
};
typedef struct RecruitHero RecruitHero;

struct RecruitHeroResult
{
	static const Type kType = kRecruitHeroResult;
	Result result;
};
typedef struct RecruitHeroResult RecruitHeroResult;

struct DismissHero //���
{
	static const Type kType = kDismissHero;
	HeroSid hero;
};
typedef struct DismissHero DismissHero;


struct DismissHeroResult
{
	static const Type kType = kDismissHeroResult;
	Result result;
};
typedef struct DismissHeroResult DismissHeroResult;

struct GetHerosRecruitable //��ȡ����ļ��Ӣ��
{
	static const Type kType = kGetHerosRecruitable;
};
typedef struct GetHerosRecruitable GetHerosRecruitable;

struct GetHerosRecruitableResult
{
	static const Type kType = kGetHerosRecruitableResult;
	uint16_t count;
	struct 
	{
		HeroSid hero;
		bool dismissed;
	}heros[127];
};
typedef struct GetHerosRecruitableResult GetHerosRecruitableResult;

struct ChangeHeroArray //�ı�����
{ 
	static const Type kType = kChangeHeroArray;
	int16_t array_id;
};
typedef struct ChangeHeroArray ChangeHeroArray;

struct ChangeHeroArrayResult
{ 
	static const Type kType = kChangeHeroArrayResult;
	Result result;
};
typedef struct ChangeHeroArrayResult ChangeHeroArrayResult;


struct GetHeroArray //��ȡ����
{ 
	static const Type kType = kGetHeroArray;
	int16_t array_id;
};
typedef struct GetHeroArray GetHeroArray;
struct GetHeroArrayResult
{ 
	static const Type kType = kGetHeroArrayResult;
	Result result;
	struct 
	{
		uint8_t id;//0��������
		int8_t location;
	}heros[5];
};
typedef struct GetHeroArrayResult GetHeroArrayResult;


struct ChangeHeroLocation //�ı�Ӣ���������е�λ��
{ 
	static const Type kType = kChangeHeroLocation;
	HeroSid hero;
	int8_t location;  //0��ʾ����
	int16_t array_id; //����ID
};
typedef struct ChangeHeroLocation ChangeHeroLocation;

struct ChangeHeroLocationResult
{ 
	static const Type kType = kChangeHeroLocationResult;
	Result result;
};
typedef struct ChangeHeroLocationResult ChangeHeroLocationResult;

struct GetMyHeroDetail  //��ȡӢ�۵���ϸ��Ϣ
{ 
	static const Type kType = kGetMyHeroDetail;
	HeroSid hero;
};
typedef struct GetMyHeroDetail GetMyHeroDetail;

struct HeroDetail //
{ 
	static const Type kType = kHeroDetail;
	int32_t		hp;
	uint16_t		strength;
	uint16_t		agility;
	uint16_t		intelligence;
	uint16_t		speed;

	int32_t		physical_attack_min;
	int32_t		physical_attack_max;
	int32_t		physical_defense;
	int32_t		magical_attack_min;
	int32_t		magical_attack_max;
	int32_t		magical_defense;
	int32_t		real_damage;

	double	hit;
	double	dodge; 
	double	dodge_reduce;
	double	resistance;
	double	magical_accurate;
	double	block;
	double	block_damage_reduction;
	double	parry;
	double	counterattack;
	double	counterattack_damage;
	double	crit;
	double	toughness;
	double	crit_damage;
	double	dizziness_resistance;
	double	sleep_resistance;
	double	paralysis_resistance;
	double	charm_resistance;
	double	silence_resistance;
	double	detained_resistance;
	double	ridicule_resistance;

	double	plain;
	double	mountain;
	double	forest;
	double	lake;
	double coastal;
	double	cave;
	double	wasteland;
	double	citadel;
	double	sunny;
	double	rain;
	double	cloudy;
	double	snow;
	double	fog;
};
typedef struct HeroDetail HeroDetail;


enum AlterationType{kAlterationAdd=1, kAlterationRemove, kAlterationUpdate, kAlterationMove};

#pragma pack(1)
struct PropAlteration
{
	PropID  id;
	PropSid kind;
	int16_t hero_id;
	int8_t  area;
	uint8_t location;
	uint8_t amount;
	uint8_t bind;//�Ƿ��Ѿ���
	uint8_t type; // 1���� 2ɾ�� 3�ı����� 4�ƶ�λ��
	uint8_t unused1;
	uint16_t unused2;
};
#pragma pack()
typedef struct PropAlteration PropAlteration;

struct PropsAlteration //���ߵı�������������֪ͨ
{ 
	static const Type kType = kPropsAlteration;
	uint32_t amount;
	PropAlteration alters[256];
};
typedef struct PropsAlteration PropsAlteration;



struct ResourceDelta //��Դ�ı�������Ͷ�����ResourceType��
{ 
	static const Type kType = kResourceDelta;
	double value; //����ֵ
	int32_t delta; //�仯ֵ
	int8_t type;    //enum ResourceType
};
typedef struct ResourceDelta ResourceDelta;

enum TrainResultType
{
	trainResultBegin = 14400,
	TRAIN_VIP_ERROR = trainResultBegin + 1,	//����VIP
	TRAIN_GOLD_ERROR = trainResultBegin + 2,//��Ҳ���
	TRAIN_BUY_ERROR = trainResultBegin + 3,//��������ﵽ���ֵ
	TRAIN_LEL_ERROR = trainResultBegin + 4,//Ӣ�۲��ܴ�����һ���ѵ�����ȼ�
	TRAIN_NUM_ERROR = trainResultBegin + 5,//ѵ�������ﵽ����
	TRAIN_MSG_ERROR = trainResultBegin + 6,      //�������ݴ���
	TRAIN_SILVER_ERROR = trainResultBegin + 7,//���Ҳ���
	TRAIN_VIP_LEL_ERROR = trainResultBegin + 8,//VIP�ȼ�����
};

struct GetTrainingNum//��ȡѵ���Ĵ��� c2s
{
	static const Type kType  = kGetTrainingNum;
};
typedef struct  GetTrainingNum GetTrainingNum;

struct GetTrainStatusResult//����ѵ����״̬ s2c
{
	static const Type kType = kResultTrainingNum;
	Result result;
	uint32_t available_train_count; //��ѵ������
	uint32_t max_available_train_count;//���ѵ������
	uint32_t cooldown_seconds; //�´�ѵ��+1����ȴʱ��(��)
	uint32_t used_buy_count;   //�ѹ������
	uint32_t remain_buy_count; //ʣ�๺�����
};
typedef struct GetTrainStatusResult GetTrainStatusResult;

struct PushTrainNum //s2c ���Ϳ���ѵ���Ĵ���,
{
	static const Type kType = kPushTrainNum;
	uint32_t available_train_count; //��ʹ�õ�ѵ������
	uint32_t max_available_train_count;//���ѵ������
	uint32_t used_buy_count;   //�ѹ������
	uint32_t remain_buy_count; //ʣ�๺�����
};
typedef struct PushTrainNum PushTrainNum;

struct BuyTrainingNum//VIP����ѵ������ c2s
{
	static const Type kType  = kBuyTrainingNum;
};
typedef struct  BuyTrainingNum BuyTrainingNum;

struct ResultBuyTrainingNum //VIP����ѵ������ s2c
{
	static const Type kType = kResultBuyTrainingNum;
	Result result;
	uint32_t is_buy_sucess;   //�����Ƿ�ɹ� 0 ʧ�� 1 �ɹ�
	uint32_t available_train_count;   //ѵ������; 
};
typedef struct ResultBuyTrainingNum ResultBuyTrainingNum;

struct Training//ѵ������ c2s
{
	static const Type kType = kTraining;
	uint32_t type;//1 ��ͨѵ�� 2 ���ѵ�� 3 ǿ��ѵ��
	uint32_t id;
};
typedef struct Training Training;

struct TrainResult //��ȡ�������� s2c
{
	static const Type kType = kTrainingResult;
	Result result;
	bool is_training_sucess;// ���ѵ��  ǿ��ѵ�� ѵ�������Ƿ�����(0:ʧ�� 1���ɹ�)
	uint8_t unuse1;
	uint8_t unuse2;
	uint8_t unuse3;
	uint32_t experience_num; //����ֵ
	uint32_t remain_available_train_count;   //ʣ��ѵ������
	bool is_crit; //�����Ƿ�ɹ� (0ʧ�� 1�ɹ�)
};
typedef struct TrainResult TrainResult;

typedef struct _HeroLevelUp
{ 
	static const Type kType = kHeroLevelUp;
	uint32_t exp;
	HeroSid hero;
	uint8_t level;
}HeroLevelUp;

// ����Ӣ��

struct EvolveHero
{
	static const Type kType = kEvolveHero;
	uint16_t hero;      //Ӣ��SID
	uint16_t use_vip;   //ʹ��VIP��Ȩֱ�ӽ���
};
typedef struct EvolveHero EvolveHero;

struct EvolveHeroResult
{
	static const Type kType = kEvolveHeroResult;
	Result result;
	uint16_t hero;       // ��Ӣ��SID
};
typedef struct EvolveHeroResult EvolveHeroResult;



#pragma pack()

