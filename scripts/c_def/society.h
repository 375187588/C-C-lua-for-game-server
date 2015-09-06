#pragma once
#include "define.h"

enum Society
{
    kCreateGuild = kSocietyTypeBegin + 1,
    kGetGuildList = kSocietyTypeBegin + 2,
    kApplyGuild =  kSocietyTypeBegin + 3,
    kLeaveGuild =  kSocietyTypeBegin + 4,
    kInviteGuildMember =  kSocietyTypeBegin + 5,
    kReplyGuildInvite =  kSocietyTypeBegin + 6,
    kGetGuildApplyMemberList =  kSocietyTypeBegin + 7,
    kReplyGuildApply =  kSocietyTypeBegin + 8,
    kEditCallBoard = kSocietyTypeBegin + 9,
    kChangeGuildMemberGrade = kSocietyTypeBegin + 10,
    kDelateGuildLeader = kSocietyTypeBegin + 11,
    kTransferGuildLeader = kSocietyTypeBegin + 12,
    kKickoutGuildMember = kSocietyTypeBegin + 13,
    kGetGuildMainInfo = kSocietyTypeBegin + 14,
    kDisbandGuild = kSocietyTypeBegin + 15,
    kGetGuildMemberList = kSocietyTypeBegin + 16,

    kGetGuildHeavensent = kSocietyTypeBegin + 101,
    kSaveGuildHeavensent = kSocietyTypeBegin + 102,
    kResetGuildHeavensent = kSocietyTypeBegin + 103,

    kGetGuildAuthority = kSocietyTypeBegin + 201,
    kGetGuildGradesInfo = kSocietyTypeBegin + 202,
    kSaveGuildGradeInfo = kSocietyTypeBegin + 203,

    kUpgradeGulildIconFrame = kSocietyTypeBegin + 301,
    kUploadGulildIcon = kSocietyTypeBegin + 302,
    kGetGulildIcons = kSocietyTypeBegin + 303,
    kSaveGulildUseIcon = kSocietyTypeBegin + 304,
    kGetGuildNews = kSocietyTypeBegin + 305,
	kApplication = kSocietyTypeBegin + 306,
    //����ս
    kGetGuildWarFieldList = kSocietyTypeBegin + 401,
    kGetGuildWarFieldSignList = kSocietyTypeBegin + 402,
    kSignGuildWar = kSocietyTypeBegin + 403,
    kGetGuildGivingList = kSocietyTypeBegin + 404,
    kPrizeGuildGiving = kSocietyTypeBegin + 405,
    kEndowGuildWarField = kSocietyTypeBegin + 406,
    kGetGuildWarFieldMemberReward = kSocietyTypeBegin + 407,
    //kGetGuildWarFieldGuildReward = kSocietyTypeBegin + 408,
    kGetGuildWarFieldInfo = kSocietyTypeBegin + 409,
	kCanGuildWarFileMap = kSocietyTypeBegin + 410,
    kIsGuildInWar = kSocietyTypeBegin + 451,
    kGetGuildWarFieldFigtersCount = kSocietyTypeBegin + 452,
    kEnterGuildWarField = kSocietyTypeBegin + 453,
    kLeaveGuildWarField = kSocietyTypeBegin + 454,
    kBuyGuildWarBuff = kSocietyTypeBegin + 455,
    kGuildWarMove = kSocietyTypeBegin + 456,
    kGetGuildWarLocationInfo = kSocietyTypeBegin + 457,
    kGetGuildWarFightersInfo = kSocietyTypeBegin + 458,
    kGetGuildWarFighterName = kSocietyTypeBegin + 459,
	kGuildWarBeginTime = kSocietyTypeBegin + 460,
	kGuildWarCanBuyHarm = kSocietyTypeBegin + 461,
	kGuildWarCanBuyBuff = kSocietyTypeBegin + 462,
    
    //������
    kOpenAuctionHouse   = kSocietyTypeBegin + 801,
    kCloseAuctionHouse  = kSocietyTypeBegin + 802,
    kSaleAuctionProps   = kSocietyTypeBegin + 803,
    kBuyAuctionProps    = kSocietyTypeBegin + 804,
    kViewAuctionProps   = kSocietyTypeBegin + 805,
    kSearchAuctionProps = kSocietyTypeBegin + 806,
    kAuctionRecord      = kSocietyTypeBegin + 807,
    kAuctionPropsDetail = kSocietyTypeBegin + 808,

    //////////////////////////////////////////////////////////////////
    kCreateGuildResult = kSocietyReturnBegin + 1,
    kGuildList = kSocietyReturnBegin + 2,
    kApplyGuildResult = kSocietyReturnBegin + 3,
    kLeaveGuildResult = kSocietyReturnBegin + 4,
    kInviteGuildMemberResult = kSocietyReturnBegin + 5,
    kReplyGuildInviteResult = kSocietyReturnBegin + 6,
    kGuildApplyMemberList = kSocietyReturnBegin + 7,
    kReplyGuildApplyResult = kSocietyReturnBegin + 8,
    kEditCallBoardResult = kSocietyReturnBegin + 9,
    kChangeGuildMemberGradeResult = kSocietyReturnBegin + 10,
    kDelateGuildLeaderResult = kSocietyReturnBegin + 11,
    kTransferGuildLeaderResult = kSocietyReturnBegin + 12,
    kKickoutGuildMemberResult = kSocietyReturnBegin + 13,
    kGuildMainInfo = kSocietyReturnBegin + 14,
    kDisbandGuildResult = kSocietyReturnBegin + 15,
    kGuildMemberList = kSocietyReturnBegin + 16,

    kGuildHeavensent = kSocietyReturnBegin + 101,
    kSaveGuildHeavensentResult = kSocietyReturnBegin + 102,
    kResetGuildHeavensentResult = kSocietyReturnBegin + 103,

    kGuildAuthority = kSocietyReturnBegin + 201,
    kGuildGradesInfo = kSocietyReturnBegin + 202,
    kSaveGuildGradeInfoResult = kSocietyReturnBegin + 203,

    kUpgradeGulildIconFrameResult = kSocietyReturnBegin + 301,
    kUploadGulildIconResult = kSocietyReturnBegin + 302,
    kGulildIcons = kSocietyReturnBegin + 303,
    kSaveGulildUseIconResult = kSocietyReturnBegin + 304,
    kGulildNews = kSocietyReturnBegin + 305,

    //����ս
    kGuildWarFieldList = kSocietyReturnBegin + 401,
    kGuildWarFieldSignList = kSocietyReturnBegin + 402,
    kSignGuildWarResult = kSocietyReturnBegin + 403,
    kGuildGivingList = kSocietyReturnBegin + 404,
    kPrizeGuildGivingResult = kSocietyReturnBegin + 405,
    kEndowGuildWarFieldResult = kSocietyReturnBegin + 406,
    kGuildWarFieldMemberReward = kSocietyReturnBegin + 407,
    //kGuildWarFieldGuildReward = kSocietyReturnBegin + 408,
    kGuildWarFieldInfo = kSocietyReturnBegin + 409,
	kResultCanGuildWarFileMap =  kSocietyReturnBegin + 410,
	kGuildWarCanBuyHarmResult = kSocietyReturnBegin + 461,
	kGuildWarCanBuyBuffResult = kSocietyReturnBegin + 462,

    kIsGuildInWarResult = kSocietyReturnBegin + 501,
    kGuildWarFieldFigtersCount = kSocietyReturnBegin + 502,
    kEnterGuildWarFieldResult = kSocietyReturnBegin + 503,
    kLeaveGuildWarFieldResult = kSocietyReturnBegin + 504,
    kBuyGuildWarBuffResult = kSocietyReturnBegin + 505,
    kGuildWarMoveResult = kSocietyReturnBegin + 506,
    kGuildWarLocationInfo = kSocietyReturnBegin + 507,
    kGuildWarFightersInfo = kSocietyReturnBegin + 508,
    kGuildWarFighterName = kSocietyReturnBegin + 509,
    kGuildWarBeginTimeResult = kSocietyReturnBegin + 510,
    //���Ͳ���
    kPushInviteGuildMember = kSocietyTypeBegin + 500,
    kPushGuildDisbanded = kSocietyTypeBegin + 501,
    kPushReplyGuildApply = kSocietyTypeBegin + 502,
    kPushReplyGuildInvite = kSocietyTypeBegin + 503,
    kPushKickoutGuildMember = kSocietyTypeBegin + 504,
    kPushTransferGuildLeader = kSocietyTypeBegin + 505,
    kPushChangeGuildMemberGrade = kSocietyTypeBegin + 506,
	kPushAddGuildMember = kSocietyTypeBegin + 507,
	kPushDeleteGuildMember = kSocietyTypeBegin + 508,

    kPushGuildWarLocationFightersInfo = kSocietyTypeBegin + 551,
    kPushGuildWarLocationMembersInfo = kSocietyTypeBegin + 552,
    kPushPlayerLeaveGuildWarField = kSocietyTypeBegin + 553,
    kPushGuildWarWinItem = kSocietyTypeBegin + 554,
    kPushGuildWarResource = kSocietyTypeBegin + 555,
	kPushGuildWarEnter = kSocietyTypeBegin + 556,
	kPushGuildGradeInfo = kSocietyTypeBegin + 557,
	kPushGuildEnterAndOrderNum = kSocietyTypeBegin + 558,
	kPushGuildWarCanBuyHarm = kSocietyTypeBegin + 559,


    //������
    kOpenAuctionHouseResult   = kSocietyReturnBegin + 801,
    kCloseAuctionHouseResult  = kSocietyReturnBegin + 802,
    kSaleAuctionPropsResult   = kSocietyReturnBegin + 803,
    kBuyAuctionPropsResult    = kSocietyReturnBegin + 804,
    kViewAuctionPropsResult   = kSocietyReturnBegin + 805,
    kSearchAuctionPropsResult = kSocietyReturnBegin + 806,
    kAuctionRecordResult      = kSocietyReturnBegin + 807,
    kAuctionPropsDetailResult = kSocietyReturnBegin + 808,
    
    //��������������
    kPushAuctionPriceChange   = kSocietyReturnBegin + 821,
    kPushAuctionAppend        = kSocietyReturnBegin + 822,
    kPushAuctionDelete        = kSocietyReturnBegin + 823,
    kPushAuctionFailed        = kSocietyReturnBegin + 824,
};

enum SocietyResultType
{
    SocietyResultBegin = 14000,
    SOCIETY_ERROR = SocietyResultBegin + 1,                             //�Ƿ����ݲ������������ݴ���
    SOCIETY_NOT_ENOUGH_GOLD = SocietyResultBegin + 2,                   //��Ҳ���
    SOCIETY_NOT_ENOUGH_SILVER = SocietyResultBegin + 3,                 //���Ҳ���
    SOCIETY_OVERLONG_GUILD_NAME = SocietyResultBegin + 4,               //����������
    SOCIETY_BEINGLESS_GUILD = SocietyResultBegin + 5,                   //���᲻����
    SOCIETY_OVERLONG_CALLBOARD = SocietyResultBegin + 6,                //���ṫ�泬��    
    SOCIETY_ALREADY_IN_GUILD = SocietyResultBegin + 7,                  //�Ѿ��й���
    SOCIETY_NO_IN_GUILD = SocietyResultBegin + 8,                       //δ�ڹ�����
    SOCIETY_GRADE_ERROR = SocietyResultBegin + 9,                       //Ȩ�޲���
    SOCIETY_BEINGLESS_GRADE_LEVEL = SocietyResultBegin + 10,            //�����ڵĹ���Ȩ��
    SOCIETY_ALREADY_IN_GUILD_APPLY_LIST = SocietyResultBegin + 11,      //�Ѿ��������б���
    SOCIETY_ALREADY_IN_GUILD_DELATE_LIST = SocietyResultBegin + 12,     //�Ѿ��ڵ����б���
    SOCIETY_NOT_FIND_MEMBER = SocietyResultBegin + 13,                  //��Ա������
    SOCIETY_YOU_ARE_LEADER = SocietyResultBegin + 14,                   //���ǻ᳤
    SOCIETY_YOU_ARE_NOT_LEADER = SocietyResultBegin + 15,               //�㲻�ǻ᳤
    SOCIETY_DELATE_GUILD_LEADER = SocietyResultBegin + 16,              //���ڲ��ܵ����᳤
    SOCIETY_GUILD_FRAME_MAX = SocietyResultBegin + 17,                  //�Ѿ�����߼�
    SOCIETY_UNKNOW_HEAVENSENT = SocietyResultBegin + 18,                //δ֪���츳�ӵ�
    SOCIETY_HEAVENSENT_LEVEL_ERR = SocietyResultBegin + 19,             //�츳�ӵ㳬�����ȼ����� �� ����ȼ��������ܼӵ�
    SOCIETY_HEAVENSENT_PREPARE_ERR = SocietyResultBegin + 20,           //�츳�ӵ�ǰ�ô�λ
    SOCIETY_HEAVENSENT_COUNT_ERR = SocietyResultBegin + 21,             //�츳�ӵ㳬���ܵ���
    SOCIETY_ACTION_ERR = SocietyResultBegin + 22,                       //�޷����Լ�����
    SOCIETY_DATA_NILL = SocietyResultBegin + 23,                        //�������ݳ���
    SOCIETY_ALREADY_IN_SING_LIST = SocietyResultBegin + 24,             //�Ѿ��ڱ����б�����
    SOCIETY_GUILD_NOT_IN_WAR = SocietyResultBegin + 25,                 //����û�в�ս
    SOCIETY_NOT_THE_TIME = SocietyResultBegin + 26,                     //ʱ��δ��
    SOCIETY_BUY_ERROR = SocietyResultBegin + 27,                        //������������
    SOCIETY_LEVEL_ERROR = SocietyResultBegin + 28,
	SOCIETY_GUILD_QUEUE = SocietyResultBegin +29,                      //����μӹ���ս���ܽ�ɢ����
	SOCIETY_GUILD_WAR_IS_ENCOURAGEMENT = SocietyResultBegin + 30,      //����Ѿ���ȡ������
	SOCIETY_GUILD_WAR = SocietyResultBegin + 31,                       //����սӵ����ز��ܽ�ɢ����
};

enum AuctionResultType
{
    AuctionResultBegin = 14500,
    AUCTION_SUCCESS          = AuctionResultBegin + 1,            // �ɹ���ռλ�ã��ɹ���Ȼ����0��
    AUCTION_NOT_ACTIVATE     = AuctionResultBegin + 2,            // ��δ�����
    AUCTION_INVALID_ARGUMENT = AuctionResultBegin + 3,            // ��������ȷ
    AUCTION_NOT_ENOUGH_SPACE = AuctionResultBegin + 4,            // ʣ��λ�ò���
    AUCTION_NOT_FOR_AUCTION  = AuctionResultBegin + 5,            // ����Ʒ���ɳ���
    AUCTION_NOT_ENOUGH_GOLD  = AuctionResultBegin + 6,            // ��Ҳ���
    AUCTION_NOT_INVALID_ID   = AuctionResultBegin + 7,            // ID��Ч
    AUCTION_NOT_SET_PRICE    = AuctionResultBegin + 8,            // δ����һ�ڼ�
    AUCTION_NOT_INVALID_PAGE = AuctionResultBegin + 9,            // ҳ������ȷ
};
//////////////////////////////////////////////////////////////////////////


struct Heavensent
{
    uint8_t id;             //�츳id
    uint8_t level;          //�츳�ȼ�
};
typedef struct Heavensent Heavensent;

struct NewHeavensent        //ȫ���츳
{
    Heavensent heavensent[10];
};
typedef struct NewHeavensent NewHeavensent;

struct GuildInfo
{
    uint32_t guild_id;          //����id
    uint32_t level;             //����ȼ�
    uint32_t leader;            //�᳤id
    uint16_t leader_name_len;   //�᳤��
    char leader_name[6*3];
    uint32_t icon;              //���
    uint32_t icon_frame;        //����
    uint32_t exp;               //���ᾭ��
    uint32_t activity_exp;      //�����Ծ��
    uint8_t member_cur;         //��ǰ��Ա��
    uint8_t member_max;         //����Ա��
    uint16_t guild_name_len;
    char guild_name[8*3];       //������
    Heavensent heavensent[10];  //�츳
    uint32_t is_in_delate_list; //�Ƿ�Ͷ��Ʊ�����᳤
    uint16_t call_board_len0;
    uint16_t call_board_len;
    char call_board[200*3];     //����

};
typedef struct GuildInfo GuildInfo;

struct CreateGuild              //c2s ��������
{
    static const Type kType = kCreateGuild;
    uint16_t len;
    char name[24];              //������

};
typedef struct CreateGuild CreateGuild;

struct CreateGuildResult        //c2s
{
    static const Type kType = kCreateGuildResult;
    Result result;
    uint32_t state;             //1-�������Ѿ���ʹ��
};
typedef struct CreateGuildResult CreateGuildResult;

struct GuildInfoTidy
{
    uint32_t guild_id;          //����id
    uint32_t level;             //����ȼ�
    uint32_t icon;              //���
    uint32_t icon_frame;        //����
    uint32_t is_applying;       //�Ƿ���������    1-�������б��� 0-û������
    uint32_t member_cur;        //��ǰ��Ա��
    uint32_t member_max;        //����Ա��
    uint32_t leader;            //�᳤id
    uint16_t leader_name_len;   //�᳤��
    char leader_name[6*3];
    uint16_t unused;            //�ڴ油��  
    uint16_t guild_name_len;
    char guild_name[8*3];       //������
};
typedef struct GuildInfoTidy GuildInfoTidy;

struct GetGuildList             //c2s �����б�
{
    static const Type kType = kGetGuildList;
    uint32_t page;
};
typedef struct GetGuildList GetGuildList;

struct GuildList                //s2c
{
    static const Type kType = kGuildList;
    uint32_t pages;             //��ҳ��
    uint32_t count;             //��ҳ���ؼ�¼��
    GuildInfoTidy guild_info_tidy[10];
};
typedef struct GuildList GuildList;

struct ApplyGuild               //c2s ���빫��
{
    static const Type kType = kApplyGuild;
    uint32_t guild_id;          //���빫���ID
};
typedef struct ApplyGuild ApplyGuild;

struct ApplyGuildResult         //s2c
{
    static const Type kType = kApplyGuildResult;
    Result result;
    uint32_t state;             //1-����Ĺ��᲻���ڻ��ѽ�ɢ 2-���������б����� 3-�ȼ�����25����������
};
typedef struct ApplyGuildResult ApplyGuildResult;

struct LeaveGuild               //c2s �˳�����
{
    static const Type kType = kLeaveGuild;
};
typedef struct LeaveGuild LeaveGuild;

struct LeaveGuildResult         //s2c
{
    static const Type kType = kLeaveGuildResult;
    uint32_t result;
};
typedef struct LeaveGuildResult LeaveGuildResult;

struct InviteGuildMember        //c2s �������
{
    static const Type kType = kInviteGuildMember;
    uint16_t player_name_len;   //�������
    char player_name[18];   
};
typedef struct InviteGuildMember InviteGuildMember;

struct InviteGuildMemberResult  //s2c
{
    static const Type kType = kInviteGuildMemberResult;
    Result result;
    uint32_t state;             //0-����ɹ� 1-���� 2-Ȩ�޲��� 3-δ�ҵ�������һ�������Ҳ�����
                                //4-��������Ѿ��������б� 5-���������ӵ�й���,6�ȼ�����
};
typedef struct InviteGuildMemberResult InviteGuildMemberResult;

struct PushInviteGuildMember    //s2c �����������
{
    static const Type kType = kPushInviteGuildMember;
    uint32_t player_id;         //������
    uint16_t player_name_len;
    char player_name[18];   
    uint32_t guild_id;
    uint16_t guild_name_len;
    char guild_name[8*3];       //������
};
typedef struct PushInviteGuildMember PushInviteGuildMember;

struct PushGuildDisbanded       //s2c ���͹����ɢ
{
    static const Type kType = kPushGuildDisbanded;
    uint16_t guild_name_len;
    char guild_name[8*3];       //������
};
typedef struct PushGuildDisbanded PushGuildDisbanded;

struct PushReplyGuildApply      //s2c ���ͻظ�������������
{
    static const Type kType = kPushReplyGuildApply;
    uint32_t guild_id;
    uint16_t agree;             //0-�ܾ� 1-ͬ��
    uint16_t guild_name_len;
    char guild_name[8*3];       //������
};
typedef struct PushReplyGuildApply PushReplyGuildApply;

struct PushReplyGuildInvite     //s2c ���ͻظ����������������
{
    static const Type kType = kPushReplyGuildInvite;
    uint16_t player_name_len;
    char player_name[18];   
    uint32_t agree;             //0-�ܾ� 1-ͬ��
};
typedef struct PushReplyGuildInvite PushReplyGuildInvite;

struct PushKickoutGuildMember   //s2c �����߳����
{
    static const Type kType = kPushKickoutGuildMember;
    uint16_t guild_name_len;
    char guild_name[8*3];       //������
};
typedef struct PushKickoutGuildMember PushKickoutGuildMember;

struct PushTransferGuildLeader  //s2c ���ͻ᳤ת��
{
    static const Type kType = kPushTransferGuildLeader;
};
typedef struct PushTransferGuildLeader PushTransferGuildLeader;

struct ReplyGuildInvite         //c2s �ظ���������
{
    static const Type kType = kReplyGuildInvite;
    uint32_t agree;             //1-ͬ�� 0-��ͬ��
    uint32_t guild_id;          //����ID
    uint32_t player_id;         //������
};
typedef struct ReplyGuildInvite ReplyGuildInvite;

struct ReplyGuildInviteResult   //s2c
{
    static const Type kType = kReplyGuildInviteResult;
    Result result;
    uint32_t state;             //1-����������У���ʱ��Ƿ����ݣ� 2-�Ѿ��ڹ����� 3-���빫���Ա���� 4-���빤�᲻���ڣ������Ѿ���ɢ��Ƿ�����
};
typedef struct ReplyGuildInviteResult ReplyGuildInviteResult;

struct ReplyGuildApply          //c2s �ظ�����
{
    static const Type kType = kReplyGuildApply;
    uint32_t player_id;         //�ظ�����
    uint32_t agree;             //0-�ܾ� 1-���� 
};
typedef struct ReplyGuildApply ReplyGuildApply;

struct ReplyGuildApplyResult    //s2c
{
    static const Type kType = kReplyGuildApplyResult;
    Result result;
    uint32_t state;             // 2-Ȩ�޲��� 3-�Ѿ����������б�(��ʱ�����Ѿ�����������Ա����) 4-�ظ���������Ѿ��ڹ����� 5-�����Ա���� �Է��ܾ� 6
};
typedef struct ReplyGuildApplyResult ReplyGuildApplyResult;

struct EditCallBoard            //c2s �༭����
{
    static const Type kType = kEditCallBoard;
    uint16_t len;
    char content[600];
};
typedef struct EditCallBoard EditCallBoard;

struct EditCallBoardResult      //s2c
{
    static const Type kType = kEditCallBoardResult;
    Result result;
    uint32_t state;             //1-���� 2-Ȩ�޲���
};
typedef struct EditCallBoardResult EditCallBoardResult;

struct ChangeGuildMemberGrade   //c2s �ı乫���Աְλ
{
    static const Type kType = kChangeGuildMemberGrade;
    uint32_t player_id;         //�ı�����id
    uint32_t state;             //0-���� 1-����
};
typedef struct ChangeGuildMemberGrade ChangeGuildMemberGrade;

struct ChangeGuildMemberGradeResult     //s2c
{
    static const Type kType = kChangeGuildMemberGradeResult;
    Result result;
    uint32_t state;                     //1-Ŀ�겻�ڹ����� 2-Ȩ�޲���
};
typedef struct ChangeGuildMemberGradeResult ChangeGuildMemberGradeResult;

struct DelateGuildLeader                //c2s �����᳤
{
    static const Type kType = kDelateGuildLeader;
};
typedef struct DelateGuildLeader DelateGuildLeader;

struct DelateGuildLeaderResult          //s2c
{
    static const Type kType = kDelateGuildLeaderResult;
    Result result;
    //uint32_t state;
};
typedef struct DelateGuildLeaderResult DelateGuildLeaderResult;

struct TransferGuildLeader              //c2s ת�û᳤
{
    static const Type kType = kTransferGuildLeader;
    uint32_t player_id;                 //ת�ö���ID
};
typedef struct TransferGuildLeader TransferGuildLeader;

struct TransferGuildLeaderResult        //s2c
{
    static const Type kType = kTransferGuildLeaderResult;
    Result result;
    uint32_t state;                     //1-��Ա������
};
typedef struct TransferGuildLeaderResult TransferGuildLeaderResult;

struct KickoutGuildMember               //c2s �߳���Ա
{
    static const Type kType = kKickoutGuildMember;
    uint32_t player_id;                 //�߳�����ID
};
typedef struct KickoutGuildMember KickoutGuildMember;

struct KickoutGuildMemberResult         //s2c
{
    static const Type kType = kKickoutGuildMemberResult;
    Result result;
    uint32_t state;                     //1-Ŀ�겻�ڹ�����(ȡ����б��Ŀ���˳�����) 2-Ȩ�޲���
};
typedef struct KickoutGuildMemberResult KickoutGuildMemberResult;

struct GetGuildMainInfo                 //c2s ȡ������Ϣ
{
    static const Type kType = kGetGuildMainInfo;
};
typedef struct GetGuildMainInfo GetGuildMainInfo;

struct GuildMainInfo                    //s2c
{
    static const Type kType = kGuildMainInfo;
    Result result;
    GuildInfo guild_info;
};
typedef struct GuildMainInfo GuildMainInfo;

struct DisbandGuild                     //c2s ��ɢ����
{
    static const Type kType = kDisbandGuild;
};
typedef struct DisbandGuild DisbandGuild;

struct DisbandGuildResult               //s2c
{
    static const Type kType = kDisbandGuildResult;
    Result result;
};
typedef struct DisbandGuildResult DisbandGuildResult;

struct GetGuildMemberList               //c2s ȡ�����Ա�б�
{
    static const Type kType = kGetGuildMemberList;
};
typedef struct GetGuildMemberList GetGuildMemberList;

struct GuildMemberInfo
{
    uint32_t player_id;                 //��Աid
    uint32_t member_level;              //��Ա�ȼ�
    uint32_t member_sex;                //�Ա�
    uint32_t guild_offer;               //��Ա���׶�
    uint32_t grade_level;               //��Ա��׵ȼ�
    uint16_t unused;                    //�ڴ油��
    uint16_t grade_name_len;            //�����
    char grade_name[24];
    uint32_t online_state;              //����״̬ 0- ���� ��0-����ʱ��
    uint16_t member_name_len;           //��Ա��
    char member_name[6*3];
    uint32_t unused1;                   //war_field_offer;          //��ع��׶�
    uint32_t unused2;                   //is_get_member_box;        //�Ƿ���ȡ������ر���
};
typedef struct GuildMemberInfo GuildMemberInfo;

struct GuildMemberList                  //s2c
{
    static const Type kType = kGuildMemberList;
    Result result;
    //uint32_t pages;                       //��ҳ��
    uint32_t count;                     //��ҳ���ؼ�¼��
    GuildMemberInfo guild_member_info[50];
};
typedef struct GuildMemberList GuildMemberList;

struct GetGuildApplyMemberList          //c2s ȡ���������Ա�б�
{
    static const Type kType = kGetGuildApplyMemberList;
};
typedef struct GetGuildApplyMemberList GetGuildApplyMemberList;

struct GuildApplyMemberInfo
{
    uint32_t player_id;                 //��Աid
    uint32_t player_level;              //��Ա�ȼ�
    uint16_t player_name_len;           //��Ա��
    char player_name[6*3];
};
typedef struct GuildApplyMemberInfo GuildApplyMemberInfo;

struct GuildApplyMemberList             //s2c
{
    static const Type kType = kGuildApplyMemberList;
    uint32_t state;                     //1-���� 2-Ȩ�޲���
    uint32_t count;                     //���ؼ�¼��
    GuildApplyMemberInfo guild_apply_member_info[100];
};
typedef struct GuildApplyMemberList GuildApplyMemberList;

struct GetGuildHeavensent               //c2s ȡ�츳�ӵ�
 { 
    static const Type kType = kGetGuildHeavensent;
};
typedef struct GetGuildHeavensent GetGuildHeavensent;

struct GuildHeavensent                  //s2c
 { 
    static const Type kType = kGuildHeavensent;
    Result result;
    uint32_t count;                     //�츳����  --��ֵһֱĬ��Ϊ10
    Heavensent heavensent[10];
};
typedef struct GuildHeavensent GuildHeavensent;

struct SaveGuildHeavensent              //c2s �����츳�ӵ�
 { 
    static const Type kType = kSaveGuildHeavensent;
    uint32_t count;                     //�츳����  --Ĭ��Ϊ10
    Heavensent heavensent[10];
};
typedef struct SaveGuildHeavensent SaveGuildHeavensent;

struct SaveGuildHeavensentResult        //s2c
 { 
    static const Type kType = kSaveGuildHeavensentResult;
    Result result;
};
typedef struct SaveGuildHeavensentResult SaveGuildHeavensentResult;

struct ResetGuildHeavensent             //c2s �����츳�ӵ�
 { 
    static const Type kType = kResetGuildHeavensent;
};
typedef struct ResetGuildHeavensent ResetGuildHeavensent;

struct ResetGuildHeavensentResult       //s2c
 { 
    static const Type kType = kResetGuildHeavensentResult;
    Result result;
};
typedef struct ResetGuildHeavensentResult ResetGuildHeavensentResult;


struct GetGuildAuthority                //c2s ȡ��׶�ӦȨ��
{
    static const Type kType = kGetGuildAuthority;
};
typedef struct GetGuildAuthority GetGuildAuthority;

struct Authority
{
    uint8_t talk_with;                  //���ᷢ��
    uint8_t change_grade;               //������Ա
    uint8_t invite_member;              //���ճ�Ա
    uint8_t kickout_member;             //������Ա
    uint8_t edit_call_board;            //�༭����
    uint8_t edit_icon;                  //�༭���
    uint8_t sign_guild_war;             //ս������
    uint8_t prize_guild_giving;         //����ֿ���Ʒ
};
typedef struct Authority Authority;

struct GuildAuthority                   //s2c
{
    static const Type kType = kGuildAuthority;
    Result result;
    Authority authority;
};
typedef struct GuildAuthority GuildAuthority;

struct GetGuildGradesInfo               //c2s �᳤ȡ���л����Ϣ����
 { 
    static const Type kType = kGetGuildGradesInfo;
};
typedef struct GetGuildGradesInfo GetGuildGradesInfo;

struct PushGuildGradesInfo             //�ı��˻�ף�֪ͨ��Ӧ������
{
	static const Type kType = kPushGuildGradeInfo;
    Authority authority;
};
typedef struct PushGuildGradesInfo PushGuildGradesInfo;

struct GuildGradeInfo
{
    uint16_t grade_level;
    uint16_t grade_name_len;
    char grade_name[24];
    Authority authority;
};
typedef struct GuildGradeInfo GuildGradeInfo;

struct PushChangeGuildMemberGrade   //s2c ���ͻ�׸ı�
{
    static const Type kType = kPushChangeGuildMemberGrade;
    uint32_t grade_level;               //��׵ȼ�
    uint16_t unused;                    //�ڴ油��
    uint16_t grade_name_len;            //�����
    char grade_name[24];                //�����
    Authority grade_authority;           //Ȩ��
};
typedef struct PushChangeGuildMemberGrade PushChangeGuildMemberGrade;

struct PushAddGuildMember	//������ӳ�Ա
{
	static const Type kType = kPushAddGuildMember;
	GuildMemberInfo info;
};
typedef struct PushAddGuildMember PushAddGuildMember;

struct PushDeleteGuildMember	//����ɾ����Ա
{
	static const Type kType = kPushDeleteGuildMember ;
	uint16_t player_id;
};
typedef struct PushDeleteGuildMember PushDeleteGuildMember;


struct GuildGradesInfo                  //s2c
 { 
    static const Type kType = kGuildGradesInfo;
    Result result;
    uint32_t count;
    GuildGradeInfo grade_info[5];   
};
typedef struct GuildGradesInfo GuildGradesInfo;

struct SaveGuildGradeInfo               //c2s �᳤��������Ϣ
 { 
    static const Type kType = kSaveGuildGradeInfo;
    GuildGradeInfo grade_info;
};
typedef struct SaveGuildGradeInfo SaveGuildGradeInfo;

struct SaveGuildGradeInfoResult         //s2c
 { 
    static const Type kType = kSaveGuildGradeInfoResult;
    Result result;
};
typedef struct SaveGuildGradeInfoResult SaveGuildGradeInfoResult;

struct UpgradeGulildIconFrame           //c2s ��������
 { 
    static const Type kType = kUpgradeGulildIconFrame;
};
typedef struct UpgradeGulildIconFrame UpgradeGulildIconFrame;

struct UpgradeGulildIconFrameResult     //s2c
 { 
    static const Type kType = kUpgradeGulildIconFrameResult;
    Result result;
    uint32_t state;                     //1-���� 2-Ȩ�޲��� 3-�ﵽ����
};
typedef struct UpgradeGulildIconFrameResult UpgradeGulildIconFrameResult;

struct UploadGulildIcon                 //c2s �ϴ����
 { 
    static const Type kType = kUploadGulildIcon;
    uint16_t unused;                    //�ڴ油��
    uint16_t icon_bin_len;              //ͼ���С
    char icon_bin[1024*20];             //20k
};
typedef struct UploadGulildIcon UploadGulildIcon;

struct UploadGulildIconResult           //s2c
 { 
    static const Type kType = kUploadGulildIconResult;
    Result result;
    uint32_t state;                     //1-���� 2-Ȩ�޲���
};
typedef struct UploadGulildIconResult UploadGulildIconResult;

struct GetGulildIcons                 //c2s ȡ�������ϴ��Ļ��
 { 
  static const Type kType = kGetGulildIcons;
  uint32_t guild_id;
};
typedef struct GetGulildIcons GetGulildIcons;

struct GulildIcons                    //s2c
 { 
  static const Type kType = kGulildIcons;
  Result result;
  uint16_t unused;                    //�ڴ油��
  uint16_t icon_bin_len;              //ͼ���С
  char icon_bin[1024*20];             //20k
 };
typedef struct GulildIcons GulildIcons;

struct SaveGulildUseIcon                //c2s ����ѡ����
 { 
    static const Type kType = kSaveGulildUseIcon;
    uint32_t icon;
};
typedef struct SaveGulildUseIcon SaveGulildUseIcon;

struct SaveGulildUseIconResult          //s2c
 { 
    static const Type kType = kSaveGulildUseIconResult;
    Result result;
    uint32_t state;                     //1-���� 2-Ȩ�޲���
};
typedef struct SaveGulildUseIconResult SaveGulildUseIconResult;

struct GetGuildNews                     //c2s ȡ��������
 { 
    static const Type kType = kGetGuildNews;
};
typedef struct GetGuildNews GetGuildNews;

struct GNews
{
    uint16_t triger_name_len;           //��Ա��
    char triger_name[6*3];
    uint32_t time;                      //��������ʱ��
    uint32_t type;                      //1 ���EXP
    uint32_t content;
};
typedef struct GNews GNews;

struct GuildNews                        //s2c
 { 
    static const Type kType = kGulildNews;
    Result result;
    uint32_t count;
    GNews gnews[100];    
};
typedef struct GuildNews GuildNews;






struct GetGuildWarFieldList             //c2s ȡ����ս���б�(��ظ�ս��ͳһΪͬһ����,δ����ϸ����)
 { 
    static const Type kType = kGetGuildWarFieldList;
};
typedef struct GetGuildWarFieldList GetGuildWarFieldList;

struct WarFieldTidy
{
    uint32_t war_field_id;              //ս��ID
    uint32_t guild_id;                  //ռ�칫��
    uint32_t is_signed;                 //�Ƿ��Ѿ����������ͼ
    uint32_t technology_level;          //�Ƽ��ȼ�
    uint16_t unused;                    //�ڴ油��
    uint16_t guild_name_len;
    char guild_name[8*3];               //������
};
typedef struct WarFieldTidy WarFieldTidy;

struct GuildWarFieldList                //s2c
 { 
    static const Type kType = kGuildWarFieldList;
    uint32_t count;
    WarFieldTidy war_fields_tidy[10];   //��ʱ����10�������������ʵ���������
};
typedef struct GuildWarFieldList GuildWarFieldList;

struct GetGuildWarFieldSignList         //c2s ȡ����ս�������б�
 { 
    static const Type kType = kGetGuildWarFieldSignList;
    uint32_t war_field_id;
};
typedef struct GetGuildWarFieldSignList GetGuildWarFieldSignList;

struct WarFieldSignInfo
{
    uint16_t guild_id;                  //��������ID
    uint16_t guild_name_len;
    char guild_name[8*3];
    uint32_t activity_exp;              //�����Ծ��
};
typedef struct WarFieldSignInfo WarFieldSignInfo;

struct GuildWarFieldSignList            //s2c
 { 
    static const Type kType = kGuildWarFieldSignList;
    uint32_t count;
    WarFieldSignInfo war_fields_sign_info[100];         //��ʱ����100�������������ʵ���������  
};
typedef struct GuildWarFieldSignList GuildWarFieldSignList;

struct SignGuildWar                     //c2s ����ս������
 { 
    static const Type kType = kSignGuildWar;
    uint32_t war_field_id;
};
typedef struct SignGuildWar SignGuildWar;

struct SignGuildWarResult               //s2c
 { 
    static const Type kType = kSignGuildWarResult;
    Result result;
    uint32_t state;                     //0-�����ɹ� 1-ÿ����ֻ�ܱ�1��ս��������ʧ�� 2-Ȩ�޲��� 3-�Ѿ����� -4ռ�칫��Ĭ���Ѿ���������Ҫ�ٱ���
};
typedef struct SignGuildWarResult SignGuildWarResult;

struct GetGuildGivingList               //c2s ȡ����ս��Ʒ�б�
 { 
    static const Type kType = kGetGuildGivingList;
};
typedef struct GetGuildGivingList GetGuildGivingList;

struct Giving
{
    uint32_t item_id;
    uint32_t item_count;
};
typedef struct Giving Giving;

struct GuildGivingList                  //s2c
 { 
    static const Type kType = kGuildGivingList;
    Result result;
    uint32_t state;                     //1-���� 2-Ȩ�޲���
    uint32_t count;
    Giving giving[100];                 //��ʱ����100�������������ʵ���������  
};
typedef struct GuildGivingList GuildGivingList;

struct PrizeGuildGiving                 //c2s ���乫��ս��Ʒ
 { 
    static const Type kType = kPrizeGuildGiving;
    uint32_t item_id;
    uint32_t count;
    uint32_t player_id[50];             //�������id,�����������޶�Ϊ50��,�˴�Ҳ����Ϊ50
};
typedef struct PrizeGuildGiving PrizeGuildGiving;

struct PrizeGuildGivingResult
 { 
    static const Type kType = kPrizeGuildGivingResult;
    Result result;
    uint32_t state;                     //1-��Ա��������Ҫ�������Ʒ��� 2-Ȩ�޲���
};
typedef struct PrizeGuildGivingResult PrizeGuildGivingResult;

struct EndowGuildWarField               //c2s ��ؾ���
 { 
    static const Type kType = kEndowGuildWarField;
    uint32_t war_field_id;              //�������
	uint32_t unable;                     //ռλ
    double endow_count;                 //����������
    uint32_t endow_type;                //0-���� 1-���
};
typedef struct EndowGuildWarField EndowGuildWarField;

struct EndowGuildWarFieldResult         //s2c
 { 
    static const Type kType = kEndowGuildWarFieldResult;
    Result result;
    uint32_t technology_level;          //�Ƽ��ȼ�
    uint32_t technology_exp;            //�Ƽ���ǰ����
    uint32_t war_field_offer;           //��ع���
};
typedef struct EndowGuildWarFieldResult EndowGuildWarFieldResult;

struct GetGuildWarFieldMemberReward     //c2s ��ȡ��Աÿ�ս���
 { 
    static const Type kType = kGetGuildWarFieldMemberReward;
    uint32_t war_field_id;
};
typedef struct GetGuildWarFieldMemberReward GetGuildWarFieldMemberReward;

struct GuildWarFieldMemberReward        //s2c
 { 
    static const Type kType = kGuildWarFieldMemberReward;
    Result result;
    uint32_t member_box_type;           //��ȡ����ID
    uint32_t member_box_count;          //��ȡ���Ӹ���
};
typedef struct GuildWarFieldMemberReward GuildWarFieldMemberReward;

struct GetGuildWarFieldInfo             //c2s ȡս����ϸ��Ϣ
 { 
    static const Type kType = kGetGuildWarFieldInfo;
    uint32_t war_field_id;  
};
typedef struct GetGuildWarFieldInfo GetGuildWarFieldInfo;

struct GuildWarFieldInfo                //s2c
 { 
    static const Type kType = kGuildWarFieldInfo;
    Result result;
    uint32_t technology_level;          //�Ƽ��ȼ�
    uint32_t technology_exp;            //�Ƽ���ǰ����
    uint32_t war_field_offer;           //��ع���
	uint32_t is_get_member_box;         //�Ƿ��ܹ���ȡ���� (0:������ȡ 1:�ܹ���ȡ)
};
typedef struct GuildWarFieldInfo GuildWarFieldInfo;

struct CanGuildWarFileMap             //���ʱ������ܷ��ս��ʱ���ͼc2s
{
	static const Type kType = kCanGuildWarFileMap;

};
typedef struct CanGuildWarFileMap CanGuildWarFileMap;

struct ResultCanGuildWarFileMap             //���ʱ������ܷ��ս��ʱ���ͼs2c
{
	static const Type kType = kResultCanGuildWarFileMap;
	Result result;
	uint32_t map[10];                      //����1��ʾ�ܹ���ĵ�ͼ
};
typedef struct ResultCanGuildWarFileMap ResultCanGuildWarFileMap;


struct GetGuildWarBeginTime            //ȡ���Ὺսʱ�� c2s
{
	static const Type kType = kGuildWarBeginTime;
};
typedef struct GetGuildWarBeginTime GetGuildWarBeginTime;

struct GuildWarBeginTimeResult        //s2c
{
	static const Type kType = kGuildWarBeginTimeResult;
	uint32_t begin_time;//��ʼ0 ��ʾû��ʼ 1��ʾ��ʼ��
};
typedef struct GuildWarBeginTimeResult GuildWarBeginTimeResult;

struct IsGuildInWar                     //c2s ȡ�����Ƿ��ս
 { 
    static const Type kType = kIsGuildInWar;
};
typedef struct IsGuildInWar IsGuildInWar;

struct IsGuildInWarResult               //s2c
 { 
    Result result;
    static const Type kType = kIsGuildInWarResult;
    //0-δ��ս ��0-ս������
	uint32_t guild_war_time; //��սʱ��
    uint32_t count; 
    uint32_t war_field_list[10];        //
};
typedef struct IsGuildInWarResult IsGuildInWarResult;

struct GetGuildWarFieldFigtersCount     //c2s ȡ����ս�����Ա����
 { 
    static const Type kType = kGetGuildWarFieldFigtersCount;
    uint32_t war_field_id;  
};
typedef struct GetGuildWarFieldFigtersCount GetGuildWarFieldFigtersCount;

struct GuildWarFieldFigtersCount        //s2c
 { 
    static const Type kType = kGuildWarFieldFigtersCount;
    Result result;
    uint32_t camp;                      //0-���ط� 1-������
    uint32_t enter_count;               //�Ѿ���������
};
typedef struct GuildWarFieldFigtersCount GuildWarFieldFigtersCount;

struct EnterGuildWarField               //c2s ���빫��ս��
 { 
    static const Type kType = kEnterGuildWarField;
    uint32_t war_field_id;  
};
typedef struct EnterGuildWarField EnterGuildWarField;

struct EnterGuildWarFieldResult         //s2c
 { 
    static const Type kType = kEnterGuildWarFieldResult;
    Result result;
    uint32_t enter_count;               //�����Ѿ���������
    uint32_t order_count;               //�����Ŷ�����
    uint32_t is_guild_waring;           //�Ƿ��Ѿ���ս
    uint32_t first_order_time;          //��һ����ʼ�Ŷ�ʱ��
    uint32_t location;                  //����ս��λ��(Ĭ��Ϊ�����)
    uint32_t buff_heal_hp_buy_num;     //����ʱ����Ѫ������
    uint32_t buff_add_attack_buy_num;  //����ʱ������˺��ӳɴ���
	uint32_t enter_time;                //����ʱ��
	uint32_t begin_time;                //��ʼʱ��
    uint32_t end_time;                  //����ʱ��
	uint32_t wait_time;                 //�Ŷӵȴ����ʱ��(eg:20��)
};
typedef struct EnterGuildWarFieldResult EnterGuildWarFieldResult;

struct LeaveGuildWarField               //c2s �뿪����ս��
 { 
    static const Type kType = kLeaveGuildWarField;
};
typedef struct LeaveGuildWarField LeaveGuildWarField;

struct LeaveGuildWarFieldResult         //s2c
 { 
    static const Type kType = kLeaveGuildWarFieldResult;
};
typedef struct LeaveGuildWarFieldResult LeaveGuildWarFieldResult;

struct PushPlayerLeaveGuildWarField //s2c �������������Ϣ���Ŷ������������
{
    static const Type kType = kPushPlayerLeaveGuildWarField;
    uint32_t enter_count;               //�����Ѿ���������  
    uint32_t order_count;               //���ǰ����Ŷ�����
    uint32_t enter_time;                //��һ���Ҫ�Ŷ�ʱ��
};
typedef struct PushPlayerLeaveGuildWarField PushPlayerLeaveGuildWarField;

struct PushGuildEnterAndOrderNum //s2c ��������,
{
	static const Type kType = kPushGuildEnterAndOrderNum;
	uint32_t enter_num;
	uint32_t order_num;
};
typedef struct PushGuildEnterAndOrderNum PushGuildEnterAndOrderNum;


struct BuyGuildWarBuff                  //c2s ����ս��BUFF
 { 
    static const Type kType = kBuyGuildWarBuff;
    uint32_t war_field_id;
    uint32_t buff_type;                 //1-�ָ��� 2-�˺�����
};
typedef struct BuyGuildWarBuff BuyGuildWarBuff;

struct BuyGuildWarBuffResult            //s2c
 { 
    static const Type kType = kBuyGuildWarBuffResult;
    Result result;
};   
typedef struct BuyGuildWarBuffResult BuyGuildWarBuffResult;

struct GetGuildWarLocationInfo          //c2s ȡս��·����Ϣ
 { 
    static const Type kType = kGetGuildWarLocationInfo;
    uint32_t location;
};
typedef struct GetGuildWarLocationInfo GetGuildWarLocationInfo;

struct GuildWarLocationInfo             //s2c
 { 
    static const Type kType = kGuildWarLocationInfo;
    Result result;
    uint32_t attack_count;              //�õ㹥��������
    uint32_t defense_count;             //�õ���ط�����
};
typedef struct GuildWarLocationInfo GuildWarLocationInfo;

struct GuildWarMove                     //c2s ս���ƶ�
 { 
    static const Type kType = kGuildWarMove;
    uint32_t war_field_id;
    uint32_t location;
};
typedef struct GuildWarMove GuildWarMove;

struct GuildWarMoveResult               //s2c
 { 
    static const Type kType = kGuildWarMoveResult;
    Result result;
    uint32_t isCanMove;                 //�Ƿ��ܹ��ƶ� 0�����ƶ� 1�ƶ�
    uint32_t is_fighting;               //0-ռ�� 1-ս��
    uint32_t is_dead;                   //�Ƿ�����
    uint32_t reborn_location;           //�����󸴻��(δ����Ϊ0)
    uint32_t life_percent;              //��ǰ��ʣ��Ѫ��%
    uint32_t win_count;                 //����������սʤ����
    uint32_t heal_hp;                   //buff�ظ���Ѫ��
};
typedef struct GuildWarMoveResult GuildWarMoveResult;

struct PushGuildWarLocationFightersInfo //s2c ����·��ս����Ϣ����������
{
    static const Type kType = kPushGuildWarLocationFightersInfo;
    uint32_t is_dead;                   //�Ƿ�����
    uint32_t reborn_location;           //�����󸴻��(δ����Ϊ0)
    uint32_t life_percent;              //��ǰ��ʣ��Ѫ��%
    uint32_t win_count;                 //����������սʤ����
    uint32_t heal_hp;                   //buff�ظ���Ѫ��
};
typedef struct PushGuildWarLocationFightersInfo PushGuildWarLocationFightersInfo;


struct LocationMembersInfo
{
    uint32_t location;
    uint32_t attack_count;              //����������
    uint32_t defense_count;             //���ط�����
    uint32_t camp;                      //������Ӫ 0-���ط� 1-������ 2-δռ��
};
typedef struct LocationMembersInfo LocationMembersInfo;

struct PushGuildWarLocationMembersInfo  //s2c ����·���Ա��Ϣ�����
{
    static const Type kType = kPushGuildWarLocationMembersInfo;
    uint32_t count;          //·�����
    LocationMembersInfo location_info[100];
};
typedef struct PushGuildWarLocationMembersInfo PushGuildWarLocationMembersInfo;

struct PushGuildWarResource  //������Դ
{
    static const Type kType = kPushGuildWarResource;
    uint32_t defenseResourceNum;  //������Դ��ȡ��
    uint32_t attackResourceNum;  //������Դ��ȡ��
};
typedef struct PushGuildWarResource PushGuildWarResource;

struct PushGuildWarEnter //֪ͨ������ҽ��빫��ս��
{
	 static const Type kType = kPushGuildWarEnter;
	 uint32_t isBegin;//1 ֪ͨ���׼��������
};
typedef struct PushGuildWarEnter PushGuildWarEnter;

struct PushGuildWarWinItem     //���ͻ�ʤ��
{
    static const Type kType = kPushGuildWarWinItem;  
    uint32_t isWinner;     //�Ƿ�ʤ�� 0��ʾʧ�� 1��ʾ�ɹ�  2��ʾƽ��
};
typedef struct PushGuildWarWinItem PushGuildWarWinItem;

struct GetGuildWarFighterName  // C2S ��ȡ��Դ������ �� ���ط�������
{
    static const Type kType = kGetGuildWarFighterName;
    uint32_t war_field_id;
};
typedef struct GetGuildWarFighterName GetGuildWarFighterName;

struct GuildWarFighterNamerResult  //S2C ��ȡ��Դ������ �� ���ط�������
{
    static const Type kType = kGuildWarFighterName;
    Result result;
    uint16_t unuesed1;
    uint16_t  defenseItemNameLenth;
    char defenseItemName[8*3]; //���ع�������
	uint32_t defense_id;
    uint32_t defense_icon;
    uint16_t unuesed2;
    uint16_t attackItemNameLenth;
    char attackItemName[8*3];  //������������
	uint32_t attack_id;
    uint32_t attack_icon;
    uint32_t defenseResourceNum;  //��ʼ��������Դ��ȡ��
    uint32_t attackResourceNum;  //��ʼ��������Դ��ȡ��
};
typedef struct GuildWarFighterNamerResult GuildWarFighterNamerResult;

struct GetGuildWarFightersInfo          //c2s ȡս����ɱ����������
 { 
    static const Type kType = kGetGuildWarFightersInfo;
    uint32_t war_field_id; //ս��id
};
typedef struct GetGuildWarFightersInfo GetGuildWarFightersInfo;

struct GuildWarFighter
{
    uint16_t player_name_len;           //��Ա��
    char player_name[6*3];
    uint32_t kill_count;                //��ɱ
    uint32_t dead_count;                //����
    uint32_t hits_count;                //����˺�
    uint32_t GuildId;                   //��ȡ����id
};
typedef struct GuildWarFighter GuildWarFighter;

struct GuildWarFightersInfo             //s2c
{ 
    static const Type kType = kGuildWarFightersInfo;
    Result result;
    uint32_t attack_count;              //����������
    uint32_t defense_count;             //���ط�����
    GuildWarFighter fighters[100];      //50+50
};
typedef struct GuildWarFightersInfo GuildWarFightersInfo;

struct GuildWarCanBuyHarm             //c2s
{ 
	static const Type kType = kGuildWarCanBuyHarm;
};
typedef struct GuildWarCanBuyHarm GuildWarCanBuyHarm;

struct GuildWarCanBuyHarmResult             //s2c
{ 
	static const Type kType = kGuildWarCanBuyHarmResult;
	bool isCanBuyHarm;
};
typedef struct GuildWarCanBuyHarmResult GuildWarCanBuyHarmResult;

struct GuildWarCanBuyBuff             //c2s
{ 
	static const Type kType = kGuildWarCanBuyBuff;
};
typedef struct GuildWarCanBuyBuff GuildWarCanBuyBuff;

struct GuildWarCanBuyBuffResult             //s2c
{ 
	static const Type kType = kGuildWarCanBuyBuffResult;
	bool isCanBuyBuff;
};
typedef struct GuildWarCanBuyBuffResult GuildWarCanBuyBuffResult;
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

// ��������
struct OpenAuctionHouse
{ 
    static const Type kType = kOpenAuctionHouse;
};
typedef struct OpenAuctionHouse OpenAuctionHouse;

struct OpenAuctionHouseResult
{ 
    static const Type kType = kOpenAuctionHouseResult;
    Result result;
    uint8_t space;      //ʣ��ռ�
};
typedef struct OpenAuctionHouseResult OpenAuctionHouseResult;

//////////////////////////////////////////////////////////////////////////////////////////////////////

// �ر�������
struct CloseAuctionHouse
{ 
    static const Type kType = kCloseAuctionHouse;
};
typedef struct CloseAuctionHouse CloseAuctionHouse;

struct CloseAuctionHouseResult
{ 
    static const Type kType = kCloseAuctionHouseResult;
    Result result;
};
typedef struct CloseAuctionHouseResult CloseAuctionHouseResult;

//////////////////////////////////////////////////////////////////////////////////////////////////////

// ������Ʒ
struct SaleAuctionProps
{ 
    static const Type kType = kSaleAuctionProps;
    uint32_t id;          // ������Ʒ����������ƷID��
    uint16_t amount;      // ����
    uint16_t day;         // ����������Ŀǰ֧��1��2��4��
    uint32_t start;       // ���ļ�
    uint32_t price;       // һ�ڼۣ�0����δ����
};
typedef struct SaleAuctionProps SaleAuctionProps;

struct SaleAuctionPropsResult
{ 
    static const Type kType = kSaleAuctionPropsResult;
    Result result;
};
typedef struct SaleAuctionPropsResult SaleAuctionPropsResult;

//////////////////////////////////////////////////////////////////////////////////////////////////////

// ������Ʒ
struct BuyAuctionProps
{ 
    static const Type kType = kBuyAuctionProps;
    uint32_t id;        // ��������ƷID
    uint8_t type;       // 1һ�ڼۣ�2���뾺��
};
typedef struct BuyAuctionProps BuyAuctionProps;

struct BuyAuctionPropsResult
{ 
    static const Type kType = kBuyAuctionPropsResult;
    Result result;
};
typedef struct BuyAuctionPropsResult BuyAuctionPropsResult;

//////////////////////////////////////////////////////////////////////////////////////////////////////

// �鿴��������Ʒ�б�
struct AuctionProps
{
    uint32_t id;           // ��������ƷID
    uint32_t kind;         // ���߱�sid
    uint32_t amount;       // ����
    uint32_t start;        // ���ļ�
    uint32_t current;      // ��ǰ���ļ�
    uint32_t price;        // һ�ڼۣ�0����δ����
    uint32_t time;         // ����ʱ��
};
typedef struct AuctionProps AuctionProps;

struct ViewAuctionProps
{ 
    static const Type kType = kViewAuctionProps;
    uint16_t page;         // ҳ������1��ʼ
    uint8_t sort;          // ����ʽ��1���ļۣ�Ĭ�ϣ���2һ�ڼۣ�3ʣ��ʱ��
    uint8_t order;         // ˳��0�Ӵ�С��1��С����
};
typedef struct ViewAuctionProps ViewAuctionProps;

struct ViewAuctionPropsResult
{ 
    static const Type kType = kViewAuctionPropsResult;
    Result result;
    uint16_t page;  //��ҳ��
    uint16_t count;
    AuctionProps list[11];
};
typedef struct ViewAuctionPropsResult ViewAuctionPropsResult;

//////////////////////////////////////////////////////////////////////////////////////////////////////

// ������������Ʒ
struct SearchAuctionProps
{ 
    static const Type kType = kSearchAuctionProps;
    uint16_t page;          // ҳ������1��ʼ
    uint8_t sort;           // ����ʽ��1���ļۣ�Ĭ�ϣ���2һ�ڼۣ�3ʣ��ʱ��
    uint8_t order;          // ˳��0�Ӵ�С��1��С����
    uint8_t kind;           // ��Ʒ���� 1װ����2���ߣ�3����
    uint8_t type;           // ���� 0����
    uint8_t level;          // �ȼ� 0����
    uint8_t quality;        // Ʒ�� 0���ޣ�1�ֲڣ�2��ͨ��3���㣬4������5ʷʫ��6��˵
    uint8_t addition;       // �Ƿ��и�������
    uint8_t addition1;      // 0���ޣ�1������2���ݣ�3������4����
    uint8_t addition2;      // 0���ޣ�1������2���ݣ�3������4����
    uint8_t addition3;      // 0���ޣ�1������2���ݣ�3������4����
};
typedef struct SearchAuctionProps SearchAuctionProps;

struct SearchAuctionPropsResult
{ 
    static const Type kType = kSearchAuctionPropsResult;
    Result result;
    uint16_t page;  //��ҳ��
    uint16_t count;
    AuctionProps list[11];
};
typedef struct SearchAuctionPropsResult SearchAuctionPropsResult;

//////////////////////////////////////////////////////////////////////////////////////////////////////

// ��������м�¼
struct TradeRecord
{
    uint32_t kind;              // ���߱�sid
    uint32_t status;            // �������״̬�� 0=δ���� 1=������ 2=���ĳɹ� 3=һ�ڼ۹��� // �����м�¼����ֵΪ���ļۣ����Ϊ0��ʾ��������Ϊ���ھ���
    uint32_t price;             // �ɽ����
    uint32_t amount;            // ��������
    uint32_t time;              // ���ʱ��
};
typedef struct TradeRecord TradeRecord;

struct AuctionRecord
{ 
    static const Type kType = kAuctionRecord;
    uint8_t type;       // 1�����У�2�������
};
typedef struct AuctionRecord AuctionRecord;

struct AuctionRecordResult
{ 
    static const Type kType = kAuctionRecordResult;
    Result result;
    uint32_t count;
    TradeRecord list[256];
};
typedef struct AuctionRecordResult AuctionRecordResult;

//////////////////////////////////////////////////////////////////////////////////////////////////////

// ��ȡ��Ʒ��ϸ��Ϣ
struct AuctionPropsDetail
{ 
    static const Type kType = kAuctionPropsDetail;
    uint32_t id;  // ��������ƷID
};
typedef struct AuctionPropsDetail AuctionPropsDetail;

struct AuctionPropsDetailResult
{ 
    static const Type kType = kAuctionPropsDetailResult;
    Result result;
};
typedef struct AuctionPropsDetailResult AuctionPropsDetailResult;

//////////////////////////////////////////////////////////////////////////////////////////////////////


//��������������

struct AuctionPriceChange // �۸�ı�
{ 
    static const Type kType = kPushAuctionPriceChange;
    uint32_t id;           // ��������ƷID
    uint32_t current;      // ��ǰ���ļ�
    uint32_t time;         // ��������ʱ��
};
typedef struct AuctionPriceChange AuctionPriceChange;

struct AuctionAppend // ������Ʒ
{ 
    static const Type kType = kPushAuctionAppend;
    AuctionProps prop;      // ��������Ʒ
};
typedef struct AuctionAppend AuctionAppend;

struct AuctionDelete // ��Ʒɾ��
{ 
    static const Type kType = kPushAuctionDelete;
    uint32_t id;           // ��������ƷID
};
typedef struct AuctionDelete AuctionDelete;

struct AuctionFailed // ����ʧ��
{ 
    static const Type kType = kPushAuctionFailed;
    uint32_t kind;              // ���߱�sid
};
typedef struct AuctionFailed AuctionFailed;
