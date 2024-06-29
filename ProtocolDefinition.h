#ifndef __PROTOCOL_DEFINITION__
#define __PROTOCOL_DEFINITION__


#include "CommonGlobalDefine.h"


#define START_CMD_SERVER				0
#define START_CMD_AGENT_SERVER			500
#define START_CMD_WORLD_SERVER			240
#define START_CMD_DUNGEON_SERVER		0


//////////////////////////////////////////////////////////////////////////
//	Common Packet Header Structure Definition
//////////////////////////////////////////////////////////////////////////
#pragma pack (push,1 )
struct WORLD_PACKET_HEADER
{
	BYTE	bGameStatus;
	BYTE	bHeader;
};

struct DUNGEON_PACKET_HEADER
{
	BYTE	bStatus;
	BYTE	bHeader;
};

struct GAME_PACKET_HEADER
{
	BYTE	bStatus;
	BYTE	bHeader;
};

struct LOGIN_PACKET_HEADER
{
	BYTE	bGameStatus;
	BYTE	bHeader;
};

struct CHARSELECT_PACKET_HEADER
{
	BYTE	bGameStatus;
	BYTE	bHeader;
};

typedef struct tagDungeonMoveInfo
{
	tagDungeonMoveInfo()
	{
		wDungeonID = 0;
		byLayerIndex = 0;
		wX = 0;
		wY = 0;
	}
	WORD wDungeonID;
	BYTE byLayerIndex;
	WORD wX;
	WORD wY;
}DUNGEON_MOVE_INFO;

//////////////////////////////////////////////////////////////////////////
//	Agent Protocol
//////////////////////////////////////////////////////////////////////////
struct Protocol_Agent_Server
{
	enum
	{
		ACMD_SERVER_ATTACH				=	START_CMD_AGENT_SERVER + 0,
		ACMD_SERVER_ATTACH_RESULT		=	START_CMD_AGENT_SERVER + 1,	
		ACMD_ADD_NEW_USER				=	START_CMD_AGENT_SERVER + 2,	
		ACMD_USER_ACCEPT_ALLOWED		=	START_CMD_AGENT_SERVER + 3,	
		ACMD_USER_ACCEPT_FAILED			=   START_CMD_AGENT_SERVER + 4,
		ACMD_USER_WORLD_LOGIN_SUCCESS	=	START_CMD_AGENT_SERVER + 5,
		ACMD_WORLD_USER_DISCONNECT		=	START_CMD_AGENT_SERVER + 6,
		ACMD_KICK_USER					=   START_CMD_AGENT_SERVER + 7,		
		ACMD_REQUEST_SERVER_ALIVE		=   START_CMD_AGENT_SERVER + 8,		
		ACMD_SERVER_ALIVE_INFO			=	START_CMD_AGENT_SERVER + 9,		
		ACMD_GUILD_CHARACTER_DELETE		=	START_CMD_AGENT_SERVER + 10,
		ACMD_CMTOOL_NOTICE				=	START_CMD_AGENT_SERVER + 11,
		ACMD_BILLING_SMALL_TIME			=   START_CMD_AGENT_SERVER + 12,
		ACMD_CHANGE_BILLING_TYPE		=	START_CMD_AGENT_SERVER + 13,
		ACMD_CHINA_BILLING_INFO			= 	START_CMD_AGENT_SERVER + 14,
		ACMD_REQUEST_CHINA_BILLING		= 	START_CMD_AGENT_SERVER + 15,
		ACMD_REQUEST_CHINA_BILLINGINFO	=	START_CMD_AGENT_SERVER + 16,
	};
};

//////////////////////////////////////////////////////////////////////////
//	Login Protocol
//////////////////////////////////////////////////////////////////////////
struct Protocol_Login
{
	enum 
	{
		CMD_LOGIN						= 0,
		CMD_LOGIN_FAIL					= 1,
		CMD_LOGIN_SUCCESS				= 2,
		CMD_REQUEST_SERVER_ALIVE		= 3,
		CMD_SERVER_ALIVE_INFO			= 4,
		CMD_CHECK_MONITORING			= 5,
		CMD_LOGIN_NETMARBLE				= 6,
		CMD_CMTOOL_NOTICE				= 7,
		CMD_IS_ALIVE_USER				= 8,
		CMD_ANSWER_ALIVE_USER			= 9,
		CMD_CM_KICK_USER				= 10,	
		CMD_LOGIN_FAIL_WITH_REASON		= 11,	
		CMD_CHINA_BILL_REMAINED_TIME	= 12,	
		CMD_ENCRYPTION_KEY				= 13,	
	};
};

//////////////////////////////////////////////////////////////////////////
//	Character Select Protocol
//////////////////////////////////////////////////////////////////////////
struct Protocol_CharSelect
{
	enum 
	{
		CMD_CHARACTER_SELECT		= 0,
		CMD_CREATE_NEW_CHARACTER	= 1,
		CMD_CREATE_CHARACTER_SUCCESS= 2,
		CMD_DELETE_CHARACTER		= 3,
		CMD_CREATE_CHARACTER_FAIL	= 4,
		CMD_WORLD_USER_INFO			= 5,
		CMD_CHECK_GM				= 6,

		CMD_CHARACTER_SELECT_FAIL	= 9,
		ACMD_CONNECT_WORLD_SERVER	= 10,
		CMD_WORLD_LOGIN				= 11,	
		CMD_WORLD_LOGIN_FAIL		= 12,

		CMD_DELETE_CHARACTER_RESULT	= 20,
		ACMD_ITEMMALL_INFO			= 21,
		CMD_WARNING_TITLE			= 22,
		CMD_CHR_MOVE_CHK			= 23,
		CMD_CHR_MOVE_CHKRT			= 24,	
		CMD_MOVE_CHARACTER_FAIL		= 25,
		CMD_MOVE_CHARACTER_SUCCESS	= 26,
		CMD_MOVE_CHARACTER_RESEND	= 27,
	};
};


//////////////////////////////////////////////////////////////////////////
//	Server to Server Protocol
//////////////////////////////////////////////////////////////////////////
struct Protocol_Server
{
	enum 
	{
		CMD_SERVER_ATTACH						= START_CMD_SERVER + 0,
		CMD_SERVER_TERMINATE					= START_CMD_SERVER + 1,
		CMD_ADD_USER_ACCEPT_ALLOWED				= START_CMD_SERVER + 2,
		CMD_USER_ACCEPT_ALLOWED					= START_CMD_SERVER + 3,
		CMD_REMOVE_USER_ACCEPT_ALLOWED			= START_CMD_SERVER + 4,
		CMD_USER_ACCEPT_FAILED					= START_CMD_SERVER + 5,
		CMD_DUNGEON_MAGICARRAY_ATTACH			= START_CMD_SERVER + 6,
		CMD_START_SIEGE							= START_CMD_SERVER + 7,
		CMD_END_SIEGE							= START_CMD_SERVER + 8,
		CMD_PARTY_MSG							= START_CMD_SERVER + 9,
		CMD_DUNGEON_OWNER_CHANGE				= START_CMD_SERVER + 10,
		CMD_DUNGEON_GUARDIANITEM_ATTACH			= START_CMD_SERVER + 11,
		CMD_DUNGEON_INFO						= START_CMD_SERVER + 13,
		CMD_DUNGEON_GROUPEXP					= START_CMD_SERVER + 15,
		CMD_DUNGEON_LEVELUP						= START_CMD_SERVER + 17,
		CMD_REFRESH_ALL_DS_DATA					= START_CMD_SERVER + 18,
		CMD_REFRESH_DUNGEON_OWNER_GUILD			= START_CMD_SERVER + 19,
		CMD_GOTOWORLD							= START_CMD_SERVER + 20,
		CMD_REQUEST_USER_ACCEPT_FOR_PORTAL		= START_CMD_SERVER + 21,
		CMD_USER_ACCEPT_FAILED_FOR_PORTAL		= START_CMD_SERVER + 22,
		CMD_USER_ACCEPT_ALLOWED_FOR_PORTAL		= START_CMD_SERVER + 23,
		CMD_PARTY_LEVEL							= START_CMD_SERVER + 24,
		CMD_PARTY_INFO							= START_CMD_SERVER + 25,
		CMD_PARTY_INFORT						= START_CMD_SERVER + 26,
		CMD_PARTY_HP							= START_CMD_SERVER + 27,
		CMD_PARTY_PORTAL						= START_CMD_SERVER + 28,
		CMD_PARTY_PORTALUSED					= START_CMD_SERVER + 29,
		CMD_PARTY_PORTALMOVE					= START_CMD_SERVER + 30,
		CMD_DUNGEON_CHANGE_OPERATION_TYPE		= START_CMD_SERVER + 31,
		CMD_DUNGEON_JOIN_SUCCESS				= START_CMD_SERVER + 32,
		CMD_CREATEPRODUCTION					= START_CMD_SERVER + 33,
		CMD_REFRESH_PRODUCT_ACQUISITION			= START_CMD_SERVER + 34,
		CMD_REFRESH_ACCEXP_ACQUISITION			= START_CMD_SERVER + 35,
		CMD_REFRESH_ENTRANCE_EDIT				= START_CMD_SERVER + 36,
		CMD_REFRESH_ACCENTRANCE_ACQUISITION		= START_CMD_SERVER + 37,
		CMD_PARTY_ALLPORTAL						= START_CMD_SERVER + 38,
		CMD_EVENT_DUNGEON_INIT					= START_CMD_SERVER + 39,
		CMD_EVENT_DUNGEON_USER_OUT				= START_CMD_SERVER + 40,
		CMD_EVENT_DUNGEON_SET					= START_CMD_SERVER + 41,
		CMD_EVENT_DUNGEON_CLEAR					= START_CMD_SERVER + 42,
		CMD_GUILD_INFO							= START_CMD_SERVER + 43,
		CMD_GUILD_FAIL							= START_CMD_SERVER + 44,
		CMD_PARTY_PORTALFAIL					= START_CMD_SERVER + 45,
		CMD_KICK_USER							= START_CMD_SERVER + 46,
		CMD_NOTICE_ACTION						= START_CMD_SERVER + 47,
		CMD_DUNGEON_MESSAGE						= START_CMD_SERVER + 48,
		CMD_REQUEST_DUNGEON_ALIVE				= START_CMD_SERVER + 49,
		CMD_DUNGEON_ALIVE_IFNO					= START_CMD_SERVER + 50,
		CMD_GUILD_MSG							= START_CMD_SERVER + 51,
		CMD_GUILDUSER_INFO						= START_CMD_SERVER + 52,
		CMD_GUILDUSER_INFORT					= START_CMD_SERVER + 53,
		CMD_GUILDINFO_MSG						= START_CMD_SERVER + 55,
		CMD_GUILD_LEVEL							= START_CMD_SERVER + 56,
		CMD_CHARACTER_SEARCH					= START_CMD_SERVER + 57,
		CMD_CHARACTER_SEARCHRT					= START_CMD_SERVER + 58,
		CMD_GM_COMMAND_WS_DS					= START_CMD_SERVER + 59,
		CMD_GM_COMMAND_DS_WS					= START_CMD_SERVER + 60,
		CMD_FRIENDUSER_INFO						= START_CMD_SERVER + 61,
		CMD_FRIENDUSER_INFORT					= START_CMD_SERVER + 62,
		CMD_EVENT_DUNGEON_OPEN_INFO				= START_CMD_SERVER + 63,
		CMD_USER_PORTAL							= START_CMD_SERVER + 64,
		CMD_SET_DOUBLE_EXP						= START_CMD_SERVER + 65,
		CMD_SET_MAGICITEM_DROPRATE				= START_CMD_SERVER + 66,
		CMD_SET_EXPGAIN							= START_CMD_SERVER + 67,
		CMD_GUILD_LIST							= START_CMD_SERVER + 68,
		CMD_GUILD_ALLPORTAL						= START_CMD_SERVER + 69,
		CMD_GUILD_PORTALUSED					= START_CMD_SERVER + 70,
		CMD_GUILD_PORTALFAIL					= START_CMD_SERVER + 71,
		CMD_GULIDWAR_POINT						= START_CMD_SERVER + 72,
		CMD_GULIDWAR_DELETE						= START_CMD_SERVER + 73,
		CMD_GUILD_RANK							= START_CMD_SERVER + 74,
		CMD_GUILDUSER_RANK						= START_CMD_SERVER + 75,
		CMD_SERVER_ATTACH_RESULT				= START_CMD_SERVER + 76,
		CMD_EVENT_DUNGEON_USER_ENTER_BY_PORTAL	= START_CMD_SERVER + 77,
		CMD_EVENT_DUNGEON_CLOSE_INFO			= START_CMD_SERVER + 78,
		CMD_EVENT_DUNGEON_FIRST_TIMEOUT			= START_CMD_SERVER + 79,
		CMD_PARTY_BOARD							= START_CMD_SERVER + 80,
		CMD_EVENT_DUNGEON_CLOSE					= START_CMD_SERVER + 81,
		CMD_GUILDWAR_MESSAGE					= START_CMD_SERVER + 82,
		CMD_EVENT_JOINUSER_COUNT				= START_CMD_SERVER + 83,
		CMD_REFRESH_DEFENSECOUNT				= START_CMD_SERVER + 84,
		CMD_REFRESH_DUNGEON_OPERATIONMODE		= START_CMD_SERVER + 85,
		CMD_CHECK_DUNGEON_JOIN					= START_CMD_SERVER + 86,
		CMD_CHECK_DUNGEON_JOIN_RT				= START_CMD_SERVER + 87,
		CMD_CB_LEVELCHK							= START_CMD_SERVER + 88,		
		CMD_TEAM_MATCH							= START_CMD_SERVER + 89,	//길드전 패킷 : hwoarang 050129
		CMD_PARTY_LEADER						= START_CMD_SERVER + 90,	
		CMD_SET_PARTY_BONUS_EXP_GAIN			= START_CMD_SERVER + 91,
		CMD_PARTY_CONFIG						= START_CMD_SERVER + 92,	// 파티 설정 : 최덕석 2005.1.25
		CMD_STADIUM_STATE						= START_CMD_SERVER + 93,	//운동장 생성: hwoarang 050129
	};
};

//////////////////////////////////////////////////////////////////////////
//	Client to Server Protocol
//////////////////////////////////////////////////////////////////////////
struct Protocol_CTS
{
	enum
	{
		CMD_DUNGEON_JOIN					= 0,
		CMD_DUNGEON_OUT						= 1,		
		CMD_DUNGEON_MOVE					= 2,
		CMD_DUNGEON_STOP					= 3,
		CMD_DUNGEON_ATTACK_USER_MON			= 4,			
		CMD_DUNGEON_ATTACK_USER_USER		= 5,			

		CMD_DUNGEON_CHAT					= 8,

		CMD_DUNGEON_CASTING					= 12,
		CMD_SKILL_LEVELUP					= 13,
		CMD_ITEM_PICKUP						= 14,
		CMD_ITEM_USED						= 15,
		CMD_STATUS_LEVELUP					= 16,

		CMD_DUNGEON_CHANGE_LRSKILLKIND		= 19,
		CMD_GUILD_ITEM						= 20,
		CMD_DUNGEON_REQUEST_INFO			= 21,
		CMD_GUILD_USERDATA					= 22,
		CMD_DUNGEON_CALLDUARDIAN			= 23,
		CMD_GUARDIAN_ATTACK					= 24,
		CMD_GUARDIAN_COMMAND				= 25,
		CMD_MONSTER_COMMAND					= 26,
		CMD_GUARDIAN_COMMAND_MOVE			= 27,			
		CMD_GUARDIAN_COMMAND_ATTACK			= 28,
		CMD_SKILL							= 29,
		CMD_GUILD_JOININFO					= 30,
		CMD_GUILD_INFO						= 31,
		CMD_RIVAL_GUILD_WAR					= 32,	
		CMD_GUARDIAN_SKILL_SELECT			= 33,
		
		CMD_TRADE_REQUEST					= 35,
		CMD_TRADE_RESULT					= 36,
		CMD_TRADE_CANCEL					= 37,
		CMD_TRADE_OK						= 38, 
		CMD_TRADE_TRADE						= 39,
		CMD_EMOTICON						= 40,
		CMD_DUNGEON_PKMODE					= 41,
		CMD_PLAYERSHOP_OPEN					= 42,
		CMD_PLAYERSHOP_CLOSE				= 43,
		CMD_REQUEST_MATCH_MAN2MAN			= 44,
		CMD_REPLY_MATCH_MAN2MAN				= 45,
		CMD_PLAYERSHOP_SHOWALL				= 46,
		CMD_FINISH_MAPLOADING				= 47,
		CMD_READY_MATCH_MAN2MAN				= 48,
//		CMD_MAGICFIELDARRAY_ACQUISITION		= 49,	// 사용안함
		CMD_ITEMUPGRADE						= 50,	
		CMD_ACCENTRANCE_ACQUISITION			= 51,
		CMD_PRODUCT_ACQUISITION				= 52,
		CMD_ACCEXP_ACQUISITION				= 53,
		CMD_ENTRANCE_EDIT					= 54,
		CMD_USER_DIE_OK						= 55,
		CMD_ITEMMAKING						= 56,

		CMD_PORTAL_MOVE						= 71,
		CMD_REQUEST_SECTION_INFO_FOR_PORTAL	= 72,
		CMD_PARTY_PORTAL					= 73,
		CMD_PARTY_PORTALUSED				= 74,
		CMD_PARTY_PORTALFAIL				= 75,
		CMD_UPGRADE_FAIL					= 76,
		CMD_EVENT_USER_PREV_DUNGEON_ID		= 77,
		CMD_EVENT_CLEAR_EFFECT_FINISH		= 78,
		CMD_MAKING_CANCEL					= 79,

		CMD_FIND_HACK						= 100,
		CMD_TICK_CHECK						= 101,
		CMD_GM_COMMAND						= 102,
		CMD_PLAYER_REST						= 103,
		CMD_GUILD_PORTALUSED				= 104,
		CMD_GUILD_PORTALFAIL				= 105,
		CMD_WORLD_MOVE						= 106,
		CMD_ITEM_MOVE						= 107,	
		CMD_ITEM_USED_NATIVE				= 108,
		CMD_PARTY_PORTAL_RECOGNITION		= 109,		
		CMD_SWITCH_WEAPON					= 110,
	};
};


//////////////////////////////////////////////////////////////////////////
//	World Server to Client Protocol
//	던전에서 WorldServer의 메세지를 받을때의 Protocol
//////////////////////////////////////////////////////////////////////////
struct Protocol_WSTC
{
	enum
	{
		CMD_REPLY_DUNGEON_ADDRESS_FOR_PORTAL	= START_CMD_WORLD_SERVER + 0,

		CMD_GO_TO_WORLD							= START_CMD_WORLD_SERVER + 2,
		CMD_GO_TO_WORLD_FAIL					= START_CMD_WORLD_SERVER + 3,
	};	
};


//////////////////////////////////////////////////////////////////////////
//	World Server Protocol
//////////////////////////////////////////////////////////////////////////
struct Protocol_World
{
	enum 
	{
		CMD_REQUEST_DUNGEON_INFO							= 0,
		CMD_REPLY_DUNGEON_INFO								= 1,
		CMD_TRY_TO_JOIN_DUNGEON								= 2,
		CMD_DUNGEON_JOIN_FAILED								= 3,
		CMD_CONNECT_DUNGEON_SERVER							= 4,
//		CMD_REQUEST_DUNGEON_OWNER							= 5,	// 사용안함 
//		CMD_REPLY_DUNGEON_OWNER								= 6,	// 사용안함 
//		CMD_DUNGEON_JOIN									= 7,	// 사용안함		
		CMD_REFRESHEVENT_DUNGEON_STARTSIEGE					= 8,
		CMD_REFRESHEVENT_DUNGEON_LEVELUP					= 9,
		CMD_REFRESHEVENT_DUNGEON_CREATEPRODUCTION			= 10,
		CMD_REFRESHEVENT_DUNGEON_ENDSIEGE					= 11,

		CMD_REFRESHEVENT_DUNGEON_CHANGE_OWNER				= 13,
		CMD_NOTICE											= 14,
		CMD_REFRESH_RECENT_DUNGEON							= 15,
		CMD_REFRESHEVENT_DUNGEON_CHANGE_OWNER_GUILD			= 16,
		CMD_EVENT_DUNGEON_INFO								= 17,
		CMD_REQUEST_OWN_DUNGEON_INFO						= 18,
		CMD_EVENT_DUNGEON_STATE_INFO						= 19,	
	
		CMD_QUERY_EVENT_DUNGEON_INFO						= 21,
		CMD_GO_TO_WORLD										= 22,
		CMD_GO_TO_WORLD_FAIL								= 23,

		CMD_REFRESHEVENT_DUNGEON_ACCENTRANCE_ACQUISITION	= 25,	
		CMD_REFRESHEVENT_DUNGEON_ACCEXP_ACQUISITION			= 26,
		CMD_REFRESHEVENT_DUNGEON_ENTRANCE_EDIT				= 27,
		CMD_GO_TO_WORLD_SUCCESS								= 28,
		CMD_WORLD_MOVE										= 29,
		CMD_WORLD_STOP										= 30,
		CMD_WORLD_APPEAR									= 31,
		CMD_WORLD_DISAPPEAR									= 32,
		CMD_WORLD_PARTY_USER_INFO							= 33,
		CMD_WORLD_SET_POSITION								= 34,
		
		CMD_PARTY_USER_TRY_TO_CONNECT						= 36,
		CMD_AIRSHIP_RIDING									= 37,
		CMD_AIRSHIP_GETOFF									= 38,
		CMD_REFRESHEVENT_DUNGEON_GUARDIANITEM				= 39,
		CMD_REFRESHEVENT_DUNGEON_MAGICFIELDARRAYITEM		= 40,
		CMD_GM_COMMAND										= 41,
		CMD_GM_COMMAND_RESULT								= 42,
//		CMD_ACCEXP_ACQUISITION								= 43,	// 사용안함 
		CMD_CHECK_MONITORING								= 44,

		CMD_REFRESHEVENT_DEFENSECOUNT						= 50,
		CMD_REFRESHEVENT_DUNGEON_OPERATIONMODE				= 51,
		
		// 파티 매칭 : 최덕석 2005.1.24
		CMD_PMATCH_REGISTER									= 60,
		CMD_PMATCH_REGISTER_RESULT							= 61,
		CMD_PMATCH_ESCAPE									= 62,
		CMD_PMATCH_ESCAPE_RESULT							= 63,
		CMD_PMATCH_REQUEST									= 64,
		CMD_PMATCH_REQUEST_RESULT							= 65,
		CMD_PMATCH_CHANGE									= 66,
		CMD_PMATCH_CHANGE_RESULT							= 67,
		CMD_PARTY_CONFIG									= 68,	// 파티 설정 : 최덕석 2005.1.25
	
		CMD_TEAM_MATCH										= 69,	// 팀전(ex> Guiild전) 관련 모음 : hwoarang 050129
		CMD_PARTY_FRIEND									= 70,	// 최근 파티원 목록 : 최덕석 2005.2.21
		//////////////////////////////////////
		// 전병렬 
		CMD_GUILD_MATCH_BEGIN								= 79,	// 길드전 수락후 셋팅시의 프로토콜 모음
		CMD_GUILD_MATCHBEGIN_SETTING						= 80,	// 길드전 수락후 셋팅시의 프로토콜 모음
		CMD_GUILD_MATCH_STATUS								= 81,	// 길드전 수락후 셋팅시의 프로토콜 모음
		CMD_GUILD_MATCH_STATUS_REQUEST						= 82,	// 길드전 수락후 셋팅시의 프로토콜 모음
		CMD_GUILD_MATCH_STATUS_RESPON						= 83,	// 길드전 수락후 셋팅시의 프로토콜 모음
		CMD_GUILD_MATCH_CANCEL_OBSERVER						= 84,	// 길드전 들어가서, 옵저버 그만둘 때 프로토콜
		// 전병렬 
		///////////////////////////////////////
		CMD_GUILD_WAR_INVITE								= 84,  // 길드전 초대
		CMD_GUILD_WAR_BBS									= 85,  // 길드전 방송

		CMD_BILLING_INFO									= 100,
		CMD_CHINA_BILL_KICK_CODE							= 101,		
		
		CMD_TIMER_READY										= 110,
		CMD_TIMER_SYNC										= 111,
		CMD_TIMER_ACK										= 112,
		
		CMD_CB_MESSAGE										= 125,
		CMD_RIVAL_GUILD_WAR									= 126,	
		CMD_PARTYUSER_WORLDINFO								= 127,
		CMD_GUILDWAR_MESSAGE								= 128,
		CMD_PARTY_BOARDDELETE								= 129,
		CMD_PARTY_INFOREQUESTRT								= 130,
		CMD_PARTY_INFOREQUEST								= 131,
		CMD_PARTY_ENTRYRT									= 132,
		CMD_PARTY_ENTRY										= 133,
		CMD_GUILDWAR_RANKRT									= 134,
		CMD_GUILDWAR_RANK									= 135,
		CMD_GUILDWAR_EXITRT									= 136,
		CMD_GUILDWAR_EXIT									= 137,
		CMD_GUILDWAR_POINT									= 138,
		CMD_GUILDWAR_CREATE									= 139,
		CMD_GUILDWAR_JOIN									= 140,
		CMD_GUILDWAR_MASTERRT								= 141,
		CMD_GUILDWAR_ERRORRT								= 142,
		CMD_GUILDWAR_ERROR									= 143,
		CMD_GUILDWAR_MASTER									= 144,
		CMD_GUILDWAR_REQUEST								= 145,
		CMD_GUILD_PORTALFAIL								= 146,
		CMD_GUILD_PORTALUSED								= 147,
		CMD_GUILD_PORTAL									= 148,
		CMD_GUILD_FAIL										= 149,
		CMD_GUILD_LIST										= 150,
		CMD_COMMAND_SUCCESS									= 151,
		CMD_COMMAND_FAIL									= 152,
		CMD_COMMAND_WHISPER									= 153,
		CMD_COMMAND_DSUCCESS								= 154,
		CMD_COMMAND_MESSAGE									= 155,
		CMD_COMMAND_MESSAGERQ								= 156,
		CMD_COMMAND_RQ										= 157,
		CMD_CHAT_USER										= 158,
		CMD_DGCHAT_USER										= 159,				
		CMD_COMMAND_DGFAIL									= 160,
		CMD_COMMAND_DGWHISPER								= 161,
//		CMD_COMMAND_DMESSAGE								= 162,	// 사용안함 
		CMD_WSDGCHAT_USER									= 163,		
		CMD_GUILD_USER										= 164,
		CMD_GUILD_USERINFO									= 165,
		CMD_GUILD_USERINFODEL								= 166,
		CMD_GUILD_CREATE									= 167,		
		CMD_WSGUILD_CREATE									= 168,
		CMD_DGGUILD_USERINFO								= 169,
		CMD_DGGUILD_USER									= 170,
		CMD_GUILDJOIN_MESSAGE								= 171,
		CMD_GUILDJOINRECV_MESSAGE							= 172,		

		CMD_GUILD_JOIN										= 174,
		CMD_GUILD_JOINRESULT								= 175,
		CMD_GUILD_JOININFO									= 176,
		CMD_GUILD_RANK										= 177,
		CMD_GUILD_RANKRT									= 178,
		CMD_GUILD_INFO										= 179,
		CMD_GUILD_INFORT									= 180,
		CMD_GUILD_USERDEL									= 181,		

		CMD_USER_DELETE										= 184,
		CMD_GUILD_DELETE									= 185,
		CMD_GUILD_DELETERT									= 186,
		CMD_PARTY_JOIN										= 187,
		CMD_PARTY_JOINRT									= 188,
		CMD_PARTY_APPROVE									= 189,

		CMD_PARTY_JOINID									= 191,
		CMD_PARTY_LOGOUT									= 192,
		CMD_PARTY_LOGOUTCL									= 193,
		CMD_SKILL_KEY										= 194,
		CMD_SKILL_KEYRT										= 195,
		CMD_COMMAND_MSG										= 196,
		CMD_COMMAND_MSGRT									= 197,
		CMD_PARTY_SET										= 198,		
		CMD_PARTY_SETRT										= 199,
		CMD_PARTY_LEVEL										= 200,
		CMD_PARTY_LEADER									= 201,
		CMD_PARTY_INFO										= 202,
		CMD_PARTY_INFORT									= 203,
		CMD_PARTY_LOGOUTUSER								= 204,
		CMD_PARTY_HP										= 205,
		CMD_PARTY_PORTAL									= 206,
		CMD_PARTY_PORTALUSED								= 207,
		CMD_PARTY_PORTALMOVE								= 208,
		CMD_HELP_INFO										= 209,		
		CMD_PARTY_PORTALFAIL								= 210,
		CMD_EVENT_DUNGEON_ENTER_FAILED						= 211,
		CMD_GUILD_OFFLINE_USER								= 212,
		CMD_GUILD_OFFLINE_USER_DELETE						= 213,
		CMD_PARTY_USERREQUEST								= 214,
		CMD_PARTY_USERREQUESTWS								= 215,
		CMD_PARTY_USERREQUEST_FAIL							= 216,
		CMD_PARTY_USERREQUESTWS_FAIL						= 217,
		CMD_GUILDUSER_INFO									= 218,
		CMD_GUILDUSER_INFORT								= 219,
		CMD_GUILD_REQUEST									= 220,
		CMD_GUILD_REQUESTRT									= 221,
		CMD_GUILD_USERREQUESTWS_FAIL						= 222,
		CMD_GUILD_USERREQUEST_FAIL							= 223,
		CMD_GUILD_DATA_REQUEST								= 224,
		CMD_GUILD_DATA_REQUESTRT							= 225,
		CMD_GUILD_COUNT										= 226,
		CMD_GUILD_EXP										= 227,
		CMD_GUILD_LEVEL										= 228,
		CMD_RANK_FAIL										= 229,
		CMD_MESSENGER_USER									= 230,
		CMD_MESSENGER_USERINFO								= 231,
		CMD_MESSENGER_USERADD								= 232,		
		CMD_MESSENGER_USERFAIL								= 233,
		CMD_MESSENGER_USERADDRT								= 234,
		CMD_CHARACTER_SEARCH								= 235,
		CMD_CHARACTER_SEARCHRT								= 236,
		CMD_MESSENGER_ANSWER								= 237,
		CMD_MESSENGER_FAIL									= 238,
		CMD_MESSENGER_SUCCESS								= 239,
		CMD_GUILDUSER_LEVEL									= 240,
		CMD_FRIENDUSER_INFO									= 241,
		CMD_FRIENDUSER_INFORT								= 242,
		CMD_FRIENDUSER_DELETE								= 243,
		CMD_FRIENDUSER_DELETERT								= 244,
		CMD_MESSENGER_STATUS								= 245,
		CMD_MESSENGER_STATUSRT								= 246,
		CMD_USER_MASTER										= 247,
		CMD_USER_GUILDMASTER								= 248,
		CMD_USER_GUILDMASTERRT								= 249,
		CMD_CM_KICK_USER									= 0xfa,
		CMD_LOADING_STATUS									= 0xfb,
		CMD_INVALID_GM										= 0xfc,
		CMD_GM_LOGIN_SUCCESS								= 0xfd,
		CMD_CHECK_GM										= 0xfe,
		CMD_CHECK_CONNECTION								= 0xff,
	};
};

//////////////////////////////////////////////////////////////////////////
//	Dungeon Server to Client Protocol
//////////////////////////////////////////////////////////////////////////
struct Protocol_DSTC		
{
	enum
	{
		CMD_DUNGEON_JOIN							= START_CMD_DUNGEON_SERVER + 0,		
		CMD_DUNGEON_MOVE							= START_CMD_DUNGEON_SERVER + 2,
		CMD_DUNGEON_STOP							= START_CMD_DUNGEON_SERVER + 3,
		CMD_DUNGEON_APPEAR							= START_CMD_DUNGEON_SERVER + 4,
		CMD_DUNGEON_DISAPPEAR						= START_CMD_DUNGEON_SERVER + 5,
		CMD_DUNGEON_ATTACK_USER_MON					= START_CMD_DUNGEON_SERVER + 6,		
		CMD_DUNGEON_ATTACK_USER_USER				= START_CMD_DUNGEON_SERVER + 7,		
		CMD_DUNGEON_ATTACK_MON_MON					= START_CMD_DUNGEON_SERVER + 8,
		CMD_DUNGEON_APPEAR_MON						= START_CMD_DUNGEON_SERVER + 11,	
		CMD_DUNGEON_DISAPPEAR_MON					= START_CMD_DUNGEON_SERVER + 12,
		CMD_DUNGEON_KILL_MON						= START_CMD_DUNGEON_SERVER + 13,	
		CMD_DUNGEON_MOVE_MON						= START_CMD_DUNGEON_SERVER + 14,	
		CMD_DUNGEON_STOP_MON						= START_CMD_DUNGEON_SERVER + 15,	
		CMD_DUNGEON_ATTACK_MON_USER					= START_CMD_DUNGEON_SERVER + 16,	
		CMD_DUNGEON_CHAT							= START_CMD_DUNGEON_SERVER + 17,
		CMD_DUNGEON_CHANGE_LAYER					= START_CMD_DUNGEON_SERVER + 18,
		CMD_DUNGEON_CHANGE_SECTION					= START_CMD_DUNGEON_SERVER + 19,
		CMD_DUNGEON_LEVELUP							= START_CMD_DUNGEON_SERVER + 20,
		CMD_DUNGEON_GUARDIAN_LEVELUP				= START_CMD_DUNGEON_SERVER + 21,
		CMD_DUNGEON_APPEAR_ITEM						= START_CMD_DUNGEON_SERVER + 22,
		CMD_DUNGEON_DISAPPEAR_ITEM					= START_CMD_DUNGEON_SERVER + 23,
		CMD_ITEM_PICKUP								= START_CMD_DUNGEON_SERVER + 24,
		CMD_ITEM_PUT								= START_CMD_DUNGEON_SERVER + 25,
		CMD_DUNGEON_USER_STATUS						= START_CMD_DUNGEON_SERVER + 26,
		CMD_DUNGEON_USER_SKILL_LEVEL				= START_CMD_DUNGEON_SERVER + 27,
		CMD_DUNGEON_ERROR_CODE						= START_CMD_DUNGEON_SERVER + 28,
		CMD_DUNGEON_GUARDIAN_STATUS					= START_CMD_DUNGEON_SERVER + 29,
		CMD_ACCENTRANCE_ACQUISITION					= START_CMD_DUNGEON_SERVER + 30,
		CMD_GURADIAN_EGG_SUMMON_STATUS				= START_CMD_DUNGEON_SERVER + 31,
		CMD_DUNGEON_APPENDIX_GUARDIAN_INFO			= START_CMD_DUNGEON_SERVER + 32,
		CMD_DUNGEON_EMOTICON						= START_CMD_DUNGEON_SERVER + 40,
		CMD_DUNGEON_REQUEST_MATCH_MAN2MAN			= START_CMD_DUNGEON_SERVER + 41,
		CMD_DUNGEON_REPLY_MATCH_MAN2MAN				= START_CMD_DUNGEON_SERVER + 42,
		CMD_READY_MATCH_MAN2MAN						= START_CMD_DUNGEON_SERVER + 43,
		CMD_START_MATCH_MAN2MAN						= START_CMD_DUNGEON_SERVER + 44,
		CMD_END_MATCH_MAN2MAN						= START_CMD_DUNGEON_SERVER + 45,
		CMD_MATCH_USER_INFO							= START_CMD_DUNGEON_SERVER + 46,
		CMD_PORTAL_JOIN_USER						= START_CMD_DUNGEON_SERVER + 61,
		CMD_PORTAL_MOVE_OUTSIDE						= START_CMD_DUNGEON_SERVER + 62,
		CMD_PORTAL_MOVE_OUTSIDE_FAIL				= START_CMD_DUNGEON_SERVER + 63,
		CMD_PORTAL_DISAPPEAR						= START_CMD_DUNGEON_SERVER + 64,
		CMD_CONGESTION_MODE							= START_CMD_DUNGEON_SERVER + 65,
		CMD_COPY_ITEM_INSERTED						= START_CMD_DUNGEON_SERVER + 66,
		CMD_EVENT_DUNGEON_CLEAR						= START_CMD_DUNGEON_SERVER + 75,
		CMD_EVENT_DUNGEON_LAST_LAYER				= START_CMD_DUNGEON_SERVER + 76,
		CMD_EVENT_DUNGEON_FAILED					= START_CMD_DUNGEON_SERVER + 77,
		CMD_EVENT_EXCEPTION_RESULT					= START_CMD_DUNGEON_SERVER + 78,
		CMD_EVENT_DUNGEON_ENTER						= START_CMD_DUNGEON_SERVER + 79,
		CMD_EVENT_DUNGEON_OPEN_INFO					= START_CMD_DUNGEON_SERVER + 80,
		CMD_EVENT_DUNGEON_LAYER_CLEAR				= START_CMD_DUNGEON_SERVER + 81,
		CMD_EVENT_CLEAR_CONDITION					= START_CMD_DUNGEON_SERVER + 82,
		CMD_EVENT_ALIVE_USER_COUNT					= START_CMD_DUNGEON_SERVER + 83,
		CMD_EVENT_DUNGEON_CLOSE						= START_CMD_DUNGEON_SERVER + 84,
		CMD_EVENT_DUNGEON_FIRST_TIMEOUT				= START_CMD_DUNGEON_SERVER + 85,
		CMD_EVENT_DUNGEON_TRAINING_DISPLAY			= START_CMD_DUNGEON_SERVER + 87,
		CMD_EVENT_DUNGEON_TRAINING_ONELAYER_CLAYER	= START_CMD_DUNGEON_SERVER + 88,
		CMD_EVENT_DUNGEON_SURVIVAL_DISPLAY			= START_CMD_DUNGEON_SERVER + 89,
		CMD_EVENT_DUNGEON_CLOSE_DISPLAY				= START_CMD_DUNGEON_SERVER + 90,
		CMD_EVENT_DUNGEON_JOINUSER_COUNT			= START_CMD_DUNGEON_SERVER + 91,
		CMD_EVENT_DUNGEON_CLEARUSER_SEND			= START_CMD_DUNGEON_SERVER + 92,
		CMD_DUNGEON_CASTING							= START_CMD_DUNGEON_SERVER + 100,
		CMD_DUNGEON_STOPSTATUSEFFECT				= START_CMD_DUNGEON_SERVER + 101,
		CMD_DUNGEON_CHANGE_LRSKILLKIND				= START_CMD_DUNGEON_SERVER + 103,
		CMD_SKILL									= START_CMD_DUNGEON_SERVER + 104,
		CMD_SKILL_RESULT							= START_CMD_DUNGEON_SERVER + 105,
		CMD_DUNGEON_SIEGEINFO						= START_CMD_DUNGEON_SERVER + 106,
		CMD_APEAR_SKILL								= START_CMD_DUNGEON_SERVER + 107,
		CMD_ATTACK_MODE								= START_CMD_DUNGEON_SERVER + 108,
		CMD_DESTROY_CP								= START_CMD_DUNGEON_SERVER + 109,
		CMD_PARTY									= START_CMD_DUNGEON_SERVER + 110,
		CMD_PLAYERSHOP_OPEN							= START_CMD_DUNGEON_SERVER + 111,
		CMD_PLAYERSHOP_CLOSE						= START_CMD_DUNGEON_SERVER + 112,
		CMD_PLAYERSHOP_SHOWALL						= START_CMD_DUNGEON_SERVER + 113,
		CMD_FINISH_MAPLOADING						= START_CMD_DUNGEON_SERVER + 114,
		CMD_RESPONSE_JOIN_USER						= START_CMD_DUNGEON_SERVER + 115,
		CMD_ITEMUPGRADE_SUCCESS						= START_CMD_DUNGEON_SERVER + 116,
		CMD_ITEMUPGRADE_FAIL						= START_CMD_DUNGEON_SERVER + 117,
		CMD_PKMODE									= START_CMD_DUNGEON_SERVER + 118,
		CMD_DUNGEON_USED_POTION						= START_CMD_DUNGEON_SERVER + 119,
		CMD_PLAYER_BAD								= START_CMD_DUNGEON_SERVER + 120,
		CMD_PKCOUNT									= START_CMD_DUNGEON_SERVER + 121,
		CMD_BADACTION								= START_CMD_DUNGEON_SERVER + 122,
		CMD_ORIGINATIONITEMWITHEFFECTKIND			= START_CMD_DUNGEON_SERVER + 123,
		CMD_DUNGEON_CASTING_FAIL					= START_CMD_DUNGEON_SERVER + 124,
		CMD_ITEMUPGRADE_FAIL_INSURANCE				= START_CMD_DUNGEON_SERVER + 125,
		CMD_ITEMMAKING_SUCCESS						= START_CMD_DUNGEON_SERVER + 126,
		CMD_ITEMMAKING_FAIL							= START_CMD_DUNGEON_SERVER + 127,
		CMD_ITEMMAKING_CANCEL						= START_CMD_DUNGEON_SERVER + 128,		
		CMD_GUILD_FLAG								= START_CMD_DUNGEON_SERVER + 129,
		CMD_SKILL_INFO								= START_CMD_DUNGEON_SERVER + 130,
		CMD_STATUS_INFO								= START_CMD_DUNGEON_SERVER + 131,
		CMD_WEAPON_HAND								= START_CMD_DUNGEON_SERVER + 132,
		CMD_ARMOR_ITEM								= START_CMD_DUNGEON_SERVER + 133,
		CMD_BANK_INFO								= START_CMD_DUNGEON_SERVER + 134,
		CMD_HELMET_ITEM								= START_CMD_DUNGEON_SERVER + 135,
		CMD_GUILD_RITEM								= START_CMD_DUNGEON_SERVER + 136,
		CMD_TRADE_REQUEST							= START_CMD_DUNGEON_SERVER + 137,
		CMD_TRADE_RESULT							= START_CMD_DUNGEON_SERVER + 138,
		CMD_TRADE_CANCEL							= START_CMD_DUNGEON_SERVER + 139,
		CMD_TRADE_OK								= START_CMD_DUNGEON_SERVER + 140,
		CMD_TRADE_ITEM								= START_CMD_DUNGEON_SERVER + 141,
		CMD_TRADE_TRADE								= START_CMD_DUNGEON_SERVER + 142,
		CMD_TRADE_RETURN							= START_CMD_DUNGEON_SERVER + 143,
		CMD_TRADE_DATA								= START_CMD_DUNGEON_SERVER + 144,		
		CMD_PARTY_PORTALMOVE						= START_CMD_DUNGEON_SERVER + 145,
		CMD_PARTY_PORTALFAIL						= START_CMD_DUNGEON_SERVER + 146,
		CMD_PARTY_ARRAY								= START_CMD_DUNGEON_SERVER + 147,
		CMD_PARTY_MAGICARRAYFAIL					= START_CMD_DUNGEON_SERVER + 148,
		CMD_EVENT_CHANGE_LAYER_RESULT				= START_CMD_DUNGEON_SERVER + 149,
		CMD_EVENT_ALIVE_MONSTER_COUNT				= START_CMD_DUNGEON_SERVER + 150,
		CMD_GUILD_FAIL								= START_CMD_DUNGEON_SERVER + 151,		
		CMD_UPGRADE_CANCEL							= START_CMD_DUNGEON_SERVER + 152,
		CMD_DUNGEON_NOTICE							= START_CMD_DUNGEON_SERVER + 153,
		CMD_DUNGEON_MESSAGE							= START_CMD_DUNGEON_SERVER + 154,
		CMD_DUNGEON_JOIN_FAILED						= START_CMD_DUNGEON_SERVER + 156,		
		CMD_TRADE_CANCELFAIL						= START_CMD_DUNGEON_SERVER + 157,	
		CMD_STATUS_INIT								= START_CMD_DUNGEON_SERVER + 158,	
		CMD_SKILL_INIT								= START_CMD_DUNGEON_SERVER + 159,	
		CMD_GUILD_INFO								= START_CMD_DUNGEON_SERVER + 160,	
		CMD_SHOP_FAIL								= START_CMD_DUNGEON_SERVER + 161,
		CMD_PLAYERSHOP_ITEM							= START_CMD_DUNGEON_SERVER + 162,
		CMD_PLAYERSHOP_SELL							= START_CMD_DUNGEON_SERVER + 163,
		CMD_PLAYERSHOP_SOLDOUT						= START_CMD_DUNGEON_SERVER + 164,
		CMD_USER_PORTAL								= START_CMD_DUNGEON_SERVER + 165,
		CMD_SHOP_ITEM								= START_CMD_DUNGEON_SERVER + 166,
		CMD_PLAYER_REST								= START_CMD_DUNGEON_SERVER + 167,
		CMD_GUILD_PORTALFAIL						= START_CMD_DUNGEON_SERVER + 168,
		CMD_GUILD_RANK								= START_CMD_DUNGEON_SERVER + 169,
		CMD_USER_SPEED								= START_CMD_DUNGEON_SERVER + 170,
		CMD_OVERDRIVE_CHK							= START_CMD_DUNGEON_SERVER + 171,
		CMD_UPGRADE_CHK								= START_CMD_DUNGEON_SERVER + 172,
		CMD_PARTY_BOARD								= START_CMD_DUNGEON_SERVER + 173,
		CMD_GUILD_WAR_MESSAGE						= START_CMD_DUNGEON_SERVER + 174,
		CMD_GUILDUSER_FLAG							= START_CMD_DUNGEON_SERVER + 175,
		CMD_ITEM_MOVE								= START_CMD_DUNGEON_SERVER + 176,
		CMD_RIVAL_GUILD_WAR							= START_CMD_DUNGEON_SERVER + 177,	
		CMD_PLAYERSHOPITEM_RETURN_INV				= START_CMD_DUNGEON_SERVER + 178,
		CMD_TRADE_CANCEL_RETURN_INV					= START_CMD_DUNGEON_SERVER + 179,
		CMD_ITEM_USED_NATIVE						= START_CMD_DUNGEON_SERVER + 180,
		CMD_UPDATE_GUARDIAN_ITEM					= START_CMD_DUNGEON_SERVER + 181,
		CMD_UPGRADE_CANCEL_RETURN_INV				= START_CMD_DUNGEON_SERVER + 182,
		CMD_MAKING_CANCEL_RETURN_INV				= START_CMD_DUNGEON_SERVER + 183,
		CMD_GUARDIANSUPPLIES_CANCAL_RETURN_INV		= START_CMD_DUNGEON_SERVER + 184,
		CMD_SWITCH_WEAPON							= START_CMD_DUNGEON_SERVER + 185,
		CMD_EVENT_DUNGEON_CLEAR_PRESENT				= START_CMD_DUNGEON_SERVER + 186,
		CMD_PARTY_CONFIG							= START_CMD_DUNGEON_SERVER + 187,		// 파티 설정 : 최덕석 2005.1.25
		CMD_DUNGEON_GUILDWAR_DIE_MSG				= START_CMD_DUNGEON_SERVER + 188,
	};
};

#pragma pack (pop,1)

#endif	
