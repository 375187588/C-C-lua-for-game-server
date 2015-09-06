#pragma once
#include "define.h"
#include "game_def.h"

enum 
{
	kGenericNotify = kBroadcastTypeBegin+1,
	kWorldBossPrepare = kBroadcastTypeBegin + 2,
	kWorldBossBegin = kBroadcastTypeBegin + 3,
	kWorldBossEnd = kBroadcastTypeBegin + 4,
	kWorldBossDead = kBroadcastTypeBegin + 5,
	kWorldBossFinalReward = kBroadcastTypeBegin + 6,
	kArenaReward = kBroadcastTypeBegin + 7,
	kNextDayOpen = kBroadcastTypeBegin + 8,
	kSystemMsg = kBroadcastTypeBegin + 9,
	kResetStamina = kBroadcastTypeBegin + 10,
	kTurntableMaxReward = kBroadcastTypeBegin + 11,
	kSectionRewardGot = kBroadcastTypeBegin + 12,
	kBossSectionPassed = kBroadcastTypeBegin + 13,
	kArenaWinner = kBroadcastTypeBegin + 14,
	kArenaTop = kBroadcastTypeBegin + 15,
	kGetRune = kBroadcastTypeBegin + 16,
	kWorldWarNotify = kBroadcastTypeBegin + 17,
	kStrengthenProp = kBroadcastTypeBegin + 18,
	kFishSomething = kBroadcastTypeBegin + 19,
	kHeroRecruited = kBroadcastTypeBegin + 20,
	kAchievementFirstAccomplish = kBroadcastTypeBegin + 21,
	kSystemNotice = kBroadcastTypeBegin + 22,
	KUpdateWorship = kBroadcastTypeBegin + 23,
	kPickTheSeed = kBroadcastTypeBegin + 24,
	kTowerNotify = kBroadcastTypeBegin + 25,
};

struct GenericNotify
{ 
	static const Type kType = kGenericNotify;
	int16_t len;
	uint8_t data[256-sizeof(int16_t)]; //ѹ�����ַ���
};
typedef struct GenericNotify GenericNotify;

struct WorldBossPrepare // ������սBOSS׼��
{ 
    static const Type kType = kWorldBossPrepare;
};
typedef struct WorldBossPrepare WorldBossPrepare;

struct WorldBossBegin // BOSS������ս
{ 
    static const Type kType = kWorldBossBegin;
};
typedef struct WorldBossBegin WorldBossBegin;

struct WorldBossEnd // BOSS��ս������ʱ�䵽��
{ 
    static const Type kType = kWorldBossEnd;
};
typedef struct WorldBossEnd WorldBossEnd;

struct WorldBossDead // BOSS��ս������������
{ 
    static const Type kType = kWorldBossDead;
};
typedef struct WorldBossDead WorldBossDead;

struct WorldBossRewardInfo
{
    Nickname nickname;      // ����ǳ�
    UserID uid;
    uint32_t hurt;          // ��BOSS��ɵ����˺�
    uint32_t silver;        // �������
};
typedef struct WorldBossRewardInfo WorldBossRewardInfo;

struct WorldBossFinalReward // BOSS�������а�
{ 
    static const Type kType = kWorldBossFinalReward;
    uint32_t life;                  // BOSS��Ѫ��
    uint8_t killer;                 // 0û�����һ�� 1�����һ��
    uint8_t sid;                    // ����BOSS��SID
    uint16_t count;                 // �ϰ�����(���������һ��)
    WorldBossRewardInfo list[4];    // [0]������һ��������[1][2][3]���1��2��3��
};
typedef struct WorldBossFinalReward WorldBossFinalReward;

struct ArenaReward // ����������
{ 
    static const Type kType = kArenaReward;
};
typedef struct ArenaReward ArenaReward;


struct NextDayOpen // �ڶ��쵽��
{ 
    static const Type kType = kNextDayOpen;
};
typedef struct NextDayOpen NextDayOpen;

struct SystemMsg//ϵͳ
{
	static const Type kType = kSystemMsg;
	StringLength msg_len;
	char msg[513];
};
typedef struct SystemMsg SystemMsg;

struct ResetStamina
{
	static const Type kType = kResetStamina;
};
typedef struct ResetStamina ResetStamina;

struct TurntableMaxReward
{
	static const Type kType = kTurntableMaxReward;
	UserID uid;
	Nickname name;
};
typedef struct TurntableMaxReward TurntableMaxReward;

typedef struct _SectionRewardGot
{ 
	static const Type kType = kSectionRewardGot;
	UserID uid;
	Nickname name;
	Reward rwd;
	uint16_t section_index;
}SectionRewardGot;

typedef struct _BossSectionPassed
{ 
	static const Type kType = kBossSectionPassed;
	UserID uid;
	Nickname name;
	uint16_t section_index;
}BossSectionPassed;


typedef struct ArenaWinner  // ��������ʤ
{ 
	static const Type kType = kArenaWinner;
	Nickname name;
    UserID uid;
	uint32_t count; // ����
}ArenaWinner;

typedef struct ArenaTop  // ����������
{ 
	static const Type kType = kArenaTop;
	Nickname winner; /* winner�����loser ����˵�X�� */
	Nickname loser;
    UserID uid1;
    UserID uid2;
	uint32_t rank; // ����
}ArenaTop;

typedef struct GetRune  // ��÷���
{ 
	static const Type kType = kGetRune;
	Nickname name;
    UserID uid;
	uint32_t rune; // ����SID
}GetRune;

typedef struct WorldWarNotify  // ��ս֪ͨ
{ 
    static const Type kType = kWorldWarNotify;
    uint8_t attack;         // ����������
    uint8_t defend;         // ���ط�����
    uint8_t map;            // ��ͼID
    uint8_t type;           // �����¼���0ͶƱ��ɣ�1������ɣ�2�������
}WorldWarNotify;

typedef struct _StrengthenProp
{
	static const Type kType = kStrengthenProp;
	UserID uid;
	Nickname name;
	uint8_t  level;	//װ���ȼ�
}StrengthenProp;

typedef struct _HeroRecruited   //ĳ�����ļ��ĳӢ��
{ 
	static const Type kType = kHeroRecruited;
	UserID uid;
	Nickname name;
	HeroSid hero;
}HeroRecruited;

typedef struct _AchievementFirstAccomplish //ĳ�ɾͱ�ĳ�����ȫ����һ�����
{ 
	static const Type kType = kAchievementFirstAccomplish;
	UserID uid;
	Nickname name;
	uint32_t achievement_id;
}AchievementFirstAccomplish;

typedef struct _SystemNotice	//ϵͳ����
{
	static const Type kType = kSystemNotice;
	uint16_t	 type;				//��������	{�����1,�����2,ͬʱ3}
	StringLength len;				//���泤��
	char		 notice[1024];		//��������
}SystemNotice;

struct UpdateWorship
{
	static const Type kType = KUpdateWorship;

};
typedef struct UpdateWorship UpdateWorship;

typedef struct _BC_PickTheSeed
{
	static const Type kType = kPickTheSeed;
	UserID uid;
	Nickname name;
	uint16_t kind;		//����sid
}BC_PickTheSeed;

typedef struct _BC_FishTheFish
{
	static const Type kType = kFishSomething;
	UserID uid;
	Nickname name;
	uint32_t kind;		//sid
	uint32_t amount;	//�õ���������(ֻ�е�����,��ֵ����Ч)
}BC_FishTheFish;


typedef struct TowerNotify
{
	static const Type kType = kTowerNotify;
	UserID uid;
	Nickname name;
	uint16_t tower;		//ͨ�ص���
}TowerNotify;
