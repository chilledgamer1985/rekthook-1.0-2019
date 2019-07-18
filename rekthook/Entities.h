#pragma once

#include "MiscDefinitions.h"
#include "ClientRecvProps.h"
#include "offsets.h"
#include "Vector.h"

#define TEAM_CS_T 2
#define TEAM_CS_CT 3

#define BONE_USED_BY_HITBOX			0x00000100

#define ptr( x, x1, x2 ) *(x*)( (DWORD)x1 + (DWORD)x2 )

class IClientRenderable;
class IClientNetworkable;
class IClientUnknown;
class IClientThinkable;
class IClientEntity;
class CSWeaponInfo;
//Class CCSWeaponData;

class CSWeaponInfo
{
public:
	/*
	char _0x0000[20];
	__int32 max_clip;			//0x0014
	char _0x0018[12];
	__int32 max_reserved_ammo;	//0x0024
	char _0x0028[96];
	char* hud_name;				//0x0088
	char* weapon_name;			//0x008C
	char _0x0090[60];
	__int32 type;				//0x00CC
	__int32 price;				//0x00D0
	__int32 reward;				//0x00D4
	char _0x00D8[20];
	BYTE full_auto;				//0x00EC
	char _0x00ED[3];
	__int32 damage;				//0x00F0
	float armor_ratio;			//0x00F4
	__int32 bullets;			//0x00F8
	char* szBulletType; //0x0080

	float penetration;			//0x00FC
	char _0x0100[8];
	float range;				//0x0108
	float range_modifier;		//0x010C
	char _0x0110[16];
	BYTE silencer;				//0x0120
	char _0x0121[15];
	float max_speed;			//0x0130
	float max_speed_alt;		//0x0134
	char _0x0138[76];
	__int32 recoil_seed;		//0x0184
	char _0x0188[32];
	*/

	char pad_0x0000[0x4]; //0x0000
	char* weapon_name;	 //0x0004 
	char pad_0x0008[0xC]; //0x0008
	__int32 max_clip; //0x0014 
	char pad_0x0018[0xC]; //0x0018
	__int32 max_reserved_ammo; //0x0024 
	char pad_0x0028[0x4]; //0x0028
	char* m_WeaponMdlPath; //0x002C 
	char pad_0x0030[0x4]; //0x0030
	char* m_DropWeaponMdlPath; //0x0034 
	char pad_0x0038[0x48]; //0x0038
	char* szBulletType; //0x0080 
	char pad_0x0084[0x4]; //0x0084
	char* hud_name; //0x0088 
	char pad_0x008C[0x40]; //0x008C
	__int32 type;	 //0x00CC 
	__int32 price; //0x00D0 
	__int32 reward; //0x00D4 
	char* m_WeaponGroupName; //0x00D8 
	char pad_0x00DC[0x10]; //0x00DC
	BYTE full_auto;	 //0x00EC 
	char pad_0x00ED[0x3]; //0x00ED
	__int32 damage; //0x00F0 
	float armor_ratio;	 //0x00F4 
	__int32 bullets;
	float penetration;	 //0x00F8
	char pad_0x00F8[0x8]; //0x00FC
	float range; //0x0108 
	float range_modifier; //0x010C 
	char pad_0x0110[0x10]; //0x0110
	BYTE silencer; //0x0120 
	char pad_0x0121[0xF]; //0x0121
	float max_speed; //0x0130 
	float max_speed_alt; //0x0134 
	char pad_0x0138[0x4C]; //0x0138
	__int32 recoil_seed; //0x0184 
	char pad_0x0188[0x68]; //0x0188
	char* m_WeaponTracesType; //0x01F0 
	char pad_0x01F4[0x638]; //0x01F4
};//Size=0x240

class CCSWeaponData
{
public:

	virtual ~CCSWeaponData() {};

	char* consoleName; // 0x0004
	char pad_0008[12]; // 0x0008
	int iMaxClip1; // 0x0014
	int iMaxClip2; // 0x0018
	int iDefaultClip1; // 0x001C
	int iDefaultClip2; // 0x0020
	char pad_0024[8]; // 0x0024
	char* szWorldModel; // 0x002C
	char* szViewModel; // 0x0030
	char* szDroppedModel; // 0x0034
	char pad_0038[4]; // 0x0038
	char* N0000023E; // 0x003C
	char pad_0040[56]; // 0x0040
	char* szEmptySound; // 0x0078
	char pad_007C[4]; // 0x007C
	char* szBulletType; // 0x0080
	char pad_0084[4]; // 0x0084
	char* szHudName; // 0x0088
	char* szWeaponName; // 0x008C
	char pad_0090[56]; // 0x0090
	int WeaponType; // 0x00C8
	int iWeaponPrice; // 0x00CC
	int iKillAward; // 0x00D0
	char* szAnimationPrefix; // 0x00D4
	float flCycleTime; // 0x00D8
	float flCycleTimeAlt; // 0x00DC
	float flTimeToIdle; // 0x00E0
	float flIdleInterval; // 0x00E4
	bool bFullAuto; // 0x00E8
	char pad_0x00E5[3]; // 0x00E9
	int iDamage; // 0x00EC
	float flArmorRatio; // 0x00F0
	int iBullets; // 0x00F4
	float flPenetration; // 0x00F8
	float flFlinchVelocityModifierLarge; // 0x00FC
	float flFlinchVelocityModifierSmall; // 0x0100
	float flRange; // 0x0104
	float flRangeModifier; // 0x0108
	float flThrowVelocity; // 0x010C
	char pad_0x010C[12]; // 0x0110
	bool bHasSilencer; // 0x011C
	char pad_0x0119[3]; // 0x011D
	char* pSilencerModel; // 0x0120
	int iCrosshairMinDistance; // 0x0124
	int iCrosshairDeltaDistance;// 0x0128 - iTeam?
	float flMaxPlayerSpeed; // 0x012C
	float flMaxPlayerSpeedAlt; // 0x0130
	float flSpread; // 0x0134
	float flSpreadAlt; // 0x0138
	float flInaccuracyCrouch; // 0x013C
	float flInaccuracyCrouchAlt; // 0x0140
	float flInaccuracyStand; // 0x0144
	float flInaccuracyStandAlt; // 0x0148
	float flInaccuracyJumpInitial;// 0x014C
	float flInaccuracyJump; // 0x0150
	float flInaccuracyJumpAlt; // 0x0154
	float flInaccuracyLand; // 0x0158
	float flInaccuracyLandAlt; // 0x015C
	float flInaccuracyLadder; // 0x0160
	float flInaccuracyLadderAlt; // 0x0164
	float flInaccuracyFire; // 0x0168
	float flInaccuracyFireAlt; // 0x016C
	float flInaccuracyMove; // 0x0170
	float flInaccuracyMoveAlt; // 0x0174
	float flInaccuracyReload; // 0x0178
	int iRecoilSeed; // 0x017C
	float flRecoilAngle; // 0x0180
	float flRecoilAngleAlt; // 0x0184
	float flRecoilAngleVariance; // 0x0188
	float flRecoilAngleVarianceAlt; // 0x018C
	float flRecoilMagnitude; // 0x0190
	float flRecoilMagnitudeAlt; // 0x0194
	float flRecoilMagnitudeVariance; // 0x0198
	float flRecoilMagnitudeVarianceAlt; // 0x019C
	float flRecoveryTimeCrouch; // 0x01A0
	float flRecoveryTimeStand; // 0x01A4
	float flRecoveryTimeCrouchFinal; // 0x01A8
	float flRecoveryTimeStandFinal; // 0x01AC
	int iRecoveryTransitionStartBullet;// 0x01B0
	int iRecoveryTransitionEndBullet; // 0x01B4
	bool bUnzoomAfterShot; // 0x01B8
	bool bHideViewModelZoomed; // 0x01B9
	char pad_0x01B5[2]; // 0x01BA
	char iZoomLevels[3]; // 0x01BC
	int iZoomFOV[2]; // 0x01C0
	float fZoomTime[3]; // 0x01C4
	char* szWeaponClass; // 0x01D4
	float flAddonScale; // 0x01D8
	char pad_0x01DC[4]; // 0x01DC
	char* szEjectBrassEffect; // 0x01E0
	char* szTracerEffect; // 0x01E4
	int iTracerFrequency; // 0x01E8
	int iTracerFrequencyAlt; // 0x01EC
	char* szMuzzleFlashEffect_1stPerson; // 0x01F0
	char pad_0x01F4[4]; // 0x01F4
	char* szMuzzleFlashEffect_3rdPerson; // 0x01F8
	char pad_0x01FC[4]; // 0x01FC
	char* szMuzzleSmokeEffect; // 0x0200
	float flHeatPerShot; // 0x0204
	char* szZoomInSound; // 0x0208
	char* szZoomOutSound; // 0x020C
	float flInaccuracyPitchShift; // 0x0210
	float flInaccuracySoundThreshold; // 0x0214
	float flBotAudibleRange; // 0x0218
	char pad_0x0218[8]; // 0x0220
	char* pWrongTeamMsg; // 0x0224
	bool bHasBurstMode; // 0x0228
	char pad_0x0225[3]; // 0x0229
	bool bIsRevolver; // 0x022C
	bool bCannotShootUnderwater; // 0x0230
};

enum class CSGOClassID
{
	CTestTraceline = 223,
	CTEWorldDecal = 224,
	CTESpriteSpray = 221,
	CTESprite = 220,
	CTESparks = 219,
	CTESmoke = 218,
	CTEShowLine = 216,
	CTEProjectedDecal = 213,
	CFEPlayerDecal = 71,
	CTEPlayerDecal = 212,
	CTEPhysicsProp = 209,
	CTEParticleSystem = 208,
	CTEMuzzleFlash = 207,
	CTELargeFunnel = 205,
	CTEKillPlayerAttachments = 204,
	CTEImpact = 203,
	CTEGlowSprite = 202,
	CTEShatterSurface = 215,
	CTEFootprintDecal = 199,
	CTEFizz = 198,
	CTEExplosion = 196,
	CTEEnergySplash = 195,
	CTEEffectDispatch = 194,
	CTEDynamicLight = 193,
	CTEDecal = 191,
	CTEClientProjectile = 190,
	CTEBubbleTrail = 189,
	CTEBubbles = 188,
	CTEBSPDecal = 187,
	CTEBreakModel = 186,
	CTEBloodStream = 185,
	CTEBloodSprite = 184,
	CTEBeamSpline = 183,
	CTEBeamRingPoint = 182,
	CTEBeamRing = 181,
	CTEBeamPoints = 180,
	CTEBeamLaser = 179,
	CTEBeamFollow = 178,
	CTEBeamEnts = 177,
	CTEBeamEntPoint = 176,
	CTEBaseBeam = 175,
	CTEArmorRicochet = 174,
	CTEMetalSparks = 206,
	CSteamJet = 167,
	CSmokeStack = 157,
	DustTrail = 275,
	CFireTrail = 74,
	SporeTrail = 281,
	SporeExplosion = 280,
	RocketTrail = 278,
	SmokeTrail = 279,
	CPropVehicleDriveable = 144,
	ParticleSmokeGrenade = 277,
	CParticleFire = 116,
	MovieExplosion = 276,
	CTEGaussExplosion = 201,
	CEnvQuadraticBeam = 66,
	CEmbers = 55,
	CEnvWind = 70,
	CPrecipitation = 137,
	CPrecipitationBlocker = 138,
	CBaseTempEntity = 18,
	NextBotCombatCharacter = 0,
	CEconWearable = 54,
	CBaseAttributableItem = 4,
	CEconEntity = 53,
	CWeaponXM1014 = 272,
	CWeaponTaser = 267,
	CTablet = 171,
	CSnowball = 158,
	CSmokeGrenade = 155,
	CWeaponShield = 265,
	CWeaponSG552 = 263,
	CSensorGrenade = 151,
	CWeaponSawedoff = 259,
	CWeaponNOVA = 255,
	CIncendiaryGrenade = 99,
	CMolotovGrenade = 112,
	CMelee = 111,
	CWeaponM3 = 247,
	CKnifeGG = 108,
	CKnife = 107,
	CHEGrenade = 96,
	CFlashbang = 77,
	CFists = 76,
	CWeaponElite = 238,
	CDecoyGrenade = 47,
	CDEagle = 46,
	CWeaponUSP = 271,
	CWeaponM249 = 246,
	CWeaponUMP45 = 270,
	CWeaponTMP = 269,
	CWeaponTec9 = 268,
	CWeaponSSG08 = 266,
	CWeaponSG556 = 264,
	CWeaponSG550 = 262,
	CWeaponScout = 261,
	CWeaponSCAR20 = 260,
	CSCAR17 = 149,
	CWeaponP90 = 258,
	CWeaponP250 = 257,
	CWeaponP228 = 256,
	CWeaponNegev = 254,
	CWeaponMP9 = 253,
	CWeaponMP7 = 252,
	CWeaponMP5Navy = 251,
	CWeaponMag7 = 250,
	CWeaponMAC10 = 249,
	CWeaponM4A1 = 248,
	CWeaponHKP2000 = 245,
	CWeaponGlock = 244,
	CWeaponGalilAR = 243,
	CWeaponGalil = 242,
	CWeaponG3SG1 = 241,
	CWeaponFiveSeven = 240,
	CWeaponFamas = 239,
	CWeaponBizon = 234,
	CWeaponAWP = 232,
	CWeaponAug = 231,
	CAK47 = 1,
	CWeaponCSBaseGun = 236,
	CWeaponCSBase = 235,
	CC4 = 34,
	CBumpMine = 32,
	CBumpMineProjectile = 33,
	CBreachCharge = 28,
	CBreachChargeProjectile = 29,
	CWeaponBaseItem = 233,
	CBaseCSGrenade = 8,
	CSnowballProjectile = 160,
	CSnowballPile = 159,
	CSmokeGrenadeProjectile = 156,
	CSensorGrenadeProjectile = 152,
	CMolotovProjectile = 113,
	CItem_Healthshot = 104,
	CItemDogtags = 106,
	CDecoyProjectile = 48,
	CPhysPropRadarJammer = 126,
	CPhysPropWeaponUpgrade = 127,
	CPhysPropAmmoBox = 124,
	CPhysPropLootCrate = 125,
	CItemCash = 105,
	CEnvGasCanister = 63,
	CDronegun = 50,
	CParadropChopper = 115,
	CSurvivalSpawnChopper = 170,
	CBRC4Target = 27,
	CInfoMapRegion = 102,
	CFireCrackerBlast = 72,
	CInferno = 100,
	CChicken = 36,
	CDrone = 49,
	CFootstepControl = 79,
	CCSGameRulesProxy = 39,
	CWeaponCubemap = 0,
	CWeaponCycler = 237,
	CTEPlantBomb = 210,
	CTEFireBullets = 197,
	CTERadioIcon = 214,
	CPlantedC4 = 128,
	CCSTeam = 43,
	CCSPlayerResource = 41,
	CCSPlayer = 40,
	CPlayerPing = 130,
	CCSRagdoll = 42,
	CTEPlayerAnimEvent = 211,
	CHostage = 97,
	CHostageCarriableProp = 98,
	CBaseCSGrenadeProjectile = 9,
	CHandleTest = 95,
	CTeamplayRoundBasedRulesProxy = 173,
	CSpriteTrail = 165,
	CSpriteOriented = 164,
	CSprite = 163,
	CRagdollPropAttached = 147,
	CRagdollProp = 146,
	CPropCounter = 141,
	CPredictedViewModel = 139,
	CPoseController = 135,
	CGrassBurn = 94,
	CGameRulesProxy = 93,
	CInfoLadderDismount = 101,
	CFuncLadder = 85,
	CTEFoundryHelpers = 200,
	CEnvDetailController = 61,
	CDangerZone = 44,
	CDangerZoneController = 45,
	CWorldVguiText = 274,
	CWorld = 273,
	CWaterLODControl = 230,
	CWaterBullet = 229,
	CVoteController = 228,
	CVGuiScreen = 227,
	CPropJeep = 143,
	CPropVehicleChoreoGeneric = 0,
	CTriggerSoundOperator = 226,
	CBaseVPhysicsTrigger = 22,
	CTriggerPlayerMovement = 225,
	CBaseTrigger = 20,
	CTest_ProxyToggle_Networkable = 222,
	CTesla = 217,
	CBaseTeamObjectiveResource = 17,
	CTeam = 172,
	CSunlightShadowControl = 169,
	CSun = 168,
	CParticlePerformanceMonitor = 117,
	CSpotlightEnd = 162,
	CSpatialEntity = 161,
	CSlideshowDisplay = 154,
	CShadowControl = 153,
	CSceneEntity = 150,
	CRopeKeyframe = 148,
	CRagdollManager = 145,
	CPhysicsPropMultiplayer = 122,
	CPhysBoxMultiplayer = 120,
	CPropDoorRotating = 142,
	CBasePropDoor = 16,
	CDynamicProp = 52,
	CProp_Hallucination = 140,
	CPostProcessController = 136,
	CPointWorldText = 134,
	CPointCommentaryNode = 133,
	CPointCamera = 132,
	CPlayerResource = 131,
	CPlasma = 129,
	CPhysMagnet = 123,
	CPhysicsProp = 121,
	CStatueProp = 166,
	CPhysBox = 119,
	CParticleSystem = 118,
	CMovieDisplay = 114,
	CMaterialModifyControl = 110,
	CLightGlow = 109,
	CItemAssaultSuitUseable = 0,
	CItem = 0,
	CInfoOverlayAccessor = 103,
	CFuncTrackTrain = 92,
	CFuncSmokeVolume = 91,
	CFuncRotating = 90,
	CFuncReflectiveGlass = 89,
	CFuncOccluder = 88,
	CFuncMoveLinear = 87,
	CFuncMonitor = 86,
	CFunc_LOD = 81,
	CTEDust = 192,
	CFunc_Dust = 80,
	CFuncConveyor = 84,
	CFuncBrush = 83,
	CBreakableSurface = 31,
	CFuncAreaPortalWindow = 82,
	CFish = 75,
	CFireSmoke = 73,
	CEnvTonemapController = 69,
	CEnvScreenEffect = 67,
	CEnvScreenOverlay = 68,
	CEnvProjectedTexture = 65,
	CEnvParticleScript = 64,
	CFogController = 78,
	CEnvDOFController = 62,
	CCascadeLight = 35,
	CEnvAmbientLight = 60,
	CEntityParticleTrail = 59,
	CEntityFreezing = 58,
	CEntityFlame = 57,
	CEntityDissolve = 56,
	CDynamicLight = 51,
	CColorCorrectionVolume = 38,
	CColorCorrection = 37,
	CBreakableProp = 30,
	CBeamSpotlight = 25,
	CBaseButton = 5,
	CBaseToggle = 19,
	CBasePlayer = 15,
	CBaseFlex = 12,
	CBaseEntity = 11,
	CBaseDoor = 10,
	CBaseCombatCharacter = 6,
	CBaseAnimatingOverlay = 3,
	CBoneFollower = 26,
	CBaseAnimating = 2,
	CAI_BaseNPC = 0,
	CBeam = 24,
	CBaseViewModel = 21,
	CBaseParticleEntity = 14,
	CBaseGrenade = 13,
	CBaseCombatWeapon = 7,
	CBaseWeaponWorldModel = 23
};

enum CSWeaponType
{
	WEAPONTYPE_KNIFE = 0,
	WEAPONTYPE_PISTOL,
	WEAPONTYPE_SUBMACHINEGUN,
	WEAPONTYPE_RIFLE,
	WEAPONTYPE_SHOTGUN,
	WEAPONTYPE_SNIPER_RIFLE,
	WEAPONTYPE_MACHINEGUN,
	WEAPONTYPE_C4,
	WEAPONTYPE_GRENADE,
	WEAPONTYPE_UNKNOWN
};

enum moveTypes
{
	MOVETYPE_NONE = 0,			// never moves
	MOVETYPE_ISOMETRIC,					// For players -- in TF2 commander view, etc.
	MOVETYPE_WALK,						// Player only - moving on the ground
	MOVETYPE_STEP,						// gravity, special edge handling -- monsters use this
	MOVETYPE_FLY,						// No gravity, but still collides with stuff
	MOVETYPE_FLYGRAVITY,				// flies through the air + is affected by gravity
	MOVETYPE_VPHYSICS,					// uses VPHYSICS for simulation
	MOVETYPE_PUSH,						// no clip to world, push and crush
	MOVETYPE_NOCLIP,					// No gravity, no collisions, still do velocity/avelocity
	MOVETYPE_LADDER,					// Used by players only when going onto a ladder
	MOVETYPE_OBSERVER,					// Observer movement, depends on player's observer mode
	MOVETYPE_CUSTOM,					// Allows the entity to describe its own physics
	MOVETYPE_LAST = MOVETYPE_CUSTOM,	// should always be defined as the last item in the list
	MOVETYPE_MAX_BITS = 4
};

enum class CSGOHitboxID
{
	Head = 0,
	Neck,
	NeckLower,
	Pelvis,
	Stomach,
	LowerChest,
	Chest,
	UpperChest,
	RightThigh,
	LeftThigh,
	RightShin,
	LeftShin,
	RightFoot,
	LeftFoot,
	RightHand,
	LeftHand,
	RightUpperArm,
	RightLowerArm,
	LeftUpperArm,
	LeftLowerArm,
	Max,
};

enum ItemDefinitionIndex : int
{
	WEAPON_NONE = 0,
	WEAPON_DEAGLE,
	WEAPON_ELITE,
	WEAPON_FIVESEVEN,
	WEAPON_GLOCK,
	WEAPON_AK47 = 7,
	WEAPON_AUG,
	WEAPON_AWP,
	WEAPON_FAMAS,
	WEAPON_G3SG1,
	WEAPON_GALILAR = 13,
	WEAPON_M249,
	WEAPON_M4A1 = 16,
	WEAPON_MAC10,
	WEAPON_P90 = 19,
	WEAPON_MP5SD = 23,
	WEAPON_UMP45,
	WEAPON_XM1014,
	WEAPON_BIZON,
	WEAPON_MAG7,
	WEAPON_NEGEV,
	WEAPON_SAWEDOFF,
	WEAPON_TEC9,
	WEAPON_TASER,
	WEAPON_HKP2000,
	WEAPON_MP7,
	WEAPON_MP9,
	WEAPON_NOVA,
	WEAPON_P250,
	WEAPON_SHIELD,
	WEAPON_SCAR20,
	WEAPON_SG556,
	WEAPON_SSG08,
	WEAPON_KNIFEGG,
	WEAPON_KNIFE,
	WEAPON_FLASHBANG,
	WEAPON_HEGRENADE,
	WEAPON_SMOKEGRENADE,
	WEAPON_MOLOTOV,
	WEAPON_DECOY,
	WEAPON_INCGRENADE,
	WEAPON_C4,
	WEAPON_HEALTHSHOT = 57,
	WEAPON_KNIFE_T = 59,
	WEAPON_M4A1_SILENCER,
	WEAPON_USP_SILENCER,
	WEAPON_CZ75A = 63,
	WEAPON_REVOLVER,
	WEAPON_TAGRENADE = 68,
	WEAPON_FISTS,
	WEAPON_BREACHCHARGE,
	WEAPON_TABLET = 72,
	WEAPON_MELEE = 74,
	WEAPON_AXE,
	WEAPON_HAMMER,
	WEAPON_SPANNER = 78,
	WEAPON_KNIFE_GHOST = 80,
	WEAPON_FIREBOMB,
	WEAPON_DIVERSION,
	WEAPON_FRAG_GRENADE,
	WEAPON_SNOWBALL,
	WEAPON_BUMPMINE,
	WEAPON_BAYONET = 500,
	WEAPON_KNIFE_FLIP = 505,
	WEAPON_KNIFE_GUT,
	WEAPON_KNIFE_KARAMBIT,
	WEAPON_KNIFE_M9_BAYONET,
	WEAPON_KNIFE_TACTICAL,
	WEAPON_KNIFE_FALCHION = 512,
	WEAPON_KNIFE_BOWIE = 514,
	WEAPON_KNIFE_BUTTERFLY,
	WEAPON_KNIFE_PUSH,
	WEAPON_KNIFE_URSUS = 519,
	WEAPON_KNIFE_GYPSY_JACKKNIFE,
	WEAPON_KNIFE_STILETTO = 522,
	WEAPON_KNIFE_WIDOWMAKER,
	GLOVE_STUDDED_BLOODHOUND = 5027,
	GLOVE_T_SIDE = 5028,
	GLOVE_CT_SIDE = 5029,
	GLOVE_SPORTY = 5030,
	GLOVE_SLICK = 5031,
	GLOVE_LEATHER_WRAP = 5032,
	GLOVE_MOTORCYCLE = 5033,
	GLOVE_SPECIALIST = 5034,
	GLOVE_HYDRA = 5035
};

class ScriptCreatedItem
{
public:
	CPNETVAR_FUNC(short*, ItemDefinitionIndex, 0xE67AB3B8); //m_iItemDefinitionIndex
	CPNETVAR_FUNC(int*, ItemIDHigh, 0x714778A); //m_iItemIDHigh
	CPNETVAR_FUNC(int*, ItemIDLow, 0x3A3DFC74); //m_iItemIDLow
	CPNETVAR_FUNC(int*, AccountID, 0x24abbea8); //m_iAccountID
};

class AttributeContainer
{
public:
	CPNETVAR_FUNC(ScriptCreatedItem*, m_Item, 0x7E029CE5);
};


class CBaseCombatWeapon
{
public:
	CNETVAR_FUNC(float, GetNextPrimaryAttack, 0xDB7B106E); //m_flNextPrimaryAttack
	CNETVAR_FUNC(int, GetAmmoInClip, 0x97B6F70C); //m_iClip1
	CNETVAR_FUNC(HANDLE, GetOwnerHandle, 0xC32DF98D); //m_hOwner
	CNETVAR_FUNC(float, GetAccuracyPenalty, 0xE2958A63); //m_fAccuracyPenalty
	CNETVAR_FUNC(Vector, GetOrigin, 0x1231CE10); //m_vecOrigin
	CPNETVAR_FUNC(int*, FallbackPaintKit, 0xADE4C870); // m_nFallbackPaintKit
	CPNETVAR_FUNC(int*, FallbackSeed, 0xC2D0683D); // m_nFallbackSeed
	CPNETVAR_FUNC(float*, FallbackWear, 0xA263576C); //m_flFallbackWear
	CPNETVAR_FUNC(int*, FallbackStatTrak, 0x1ED78768); //m_nFallbackStatTrak
	CPNETVAR_FUNC(int*, OwnerXuidLow, 0xAD8D897F);
	CPNETVAR_FUNC(int*, OwnerXuidHigh, 0x90511E77);
	CPNETVAR_FUNC(int*, ViewModelIndex, 0x7F7C89C1);
	CPNETVAR_FUNC(int*, ModelIndex, 0x27016F83);
	CPNETVAR_FUNC(int*, WorldModelIndex, 0x4D8AD9F3);
	CPNETVAR_FUNC(char*, szCustomName, 0x0);
	CPNETVAR_FUNC(AttributeContainer*, m_AttributeManager, 0xCFFCE089);
	CNETVAR_FUNC(int, GetZoomLevel, 0x26553F1A);


	float GetInaccuracy()
	{
		typedef float(__thiscall* oInaccuracy)(PVOID);
		return call_vfunc< oInaccuracy >(this, 476)(this);
	}

	float GetSpread()
	{
		return call_vfunc<float(__thiscall*)(void*)>(this, 446)(this);
	}

	int* GetEntityQuality()
	{
		return (int*)((DWORD)this + 0x2D70 + 0x40 + 0x1DC);
	}

	int GetWeaponID2()
	{
		return *(int*)((DWORD)this + 0x00002F88);
	}

	void PreDataUpdate(int updateType)
	{
		PVOID pNetworkable = (PVOID)((DWORD)(this) + 0x8);
		typedef void(__thiscall* OriginalFn)(PVOID, int);
		return call_vfunc<OriginalFn>(pNetworkable, 6)(pNetworkable, updateType);
	}

	void SetModelIndex(int modelIndex) {
		typedef void(__thiscall* OriginalFn)(PVOID, int);
		return call_vfunc<OriginalFn>(this, 75)(this, modelIndex);
	}

	void UpdateAccPenalty()
	{
		typedef void(__thiscall *OrigFn)(void *);
		return call_vfunc<OrigFn>(this, 470)(this);
	}

	bool IsScoped(int x = 0)
	{
		return GetZoomLevel() > 0;
	}

	CSWeaponInfo* GetCSWpnData()
	{
		if (!this)
			return nullptr;
		typedef CSWeaponInfo*(__thiscall* OriginalFn)(void*);
		return call_vfunc<OriginalFn >(this, 454)(this);
	}
};

class CCSBomb
{
public:
	CNETVAR_FUNC(HANDLE, GetOwnerHandle, 0xC32DF98D); //m_hOwner 0x29BC
	CNETVAR_FUNC(float, GetC4BlowTime, 0xB5E0CA1C); //m_flC4Blow
	CNETVAR_FUNC(float, GetC4DefuseCountDown, 0x2994); //m_flDefuseCountDown 0x2994
};

class CLocalPlayerExclusive
{
public:
	CNETVAR_FUNC(Vector, GetViewPunchAngle, 0x68F014C0);//m_viewPunchAngle
	CNETVAR_FUNC(Vector, GetAimPunchAngle, 0xBF25C290);//m_aimPunchAngle
	CNETVAR_FUNC(Vector, GetAimPunchAngleVel, 0x8425E045);//m_aimPunchAngleVel
};

class CollisionProperty
{
public:
	CNETVAR_FUNC(Vector, GetMins, 0xF6F78BAB);//m_vecMins
	CNETVAR_FUNC(Vector, GetMaxs, 0xE47C6FC4);//m_vecMaxs
	CNETVAR_FUNC(unsigned char, GetSolidType, 0xB86722A1);//m_nSolidType
	CNETVAR_FUNC(unsigned short, GetSolidFlags, 0x63BB24C1);//m_usSolidFlags
	CNETVAR_FUNC(int, GetSurroundsType, 0xB677A0BB); //m_nSurroundType

	bool IsSolid()
	{
		return (GetSolidType() != SOLID_NONE) && ((GetSolidFlags() & FSOLID_NOT_SOLID) == 0);
	}
};

class IClientRenderable
{
public:
	//virtual void*					GetIClientUnknown() = 0;
	virtual Vector const&			GetRenderOrigin(void) = 0;
	virtual Vector const&			GetRenderAngles(void) = 0;
	virtual bool					ShouldDraw(void) = 0;
	virtual bool					IsTransparent(void) = 0;
	virtual bool					UsesPowerOfTwoFrameBufferTexture() = 0;
	virtual bool					UsesFullFrameBufferTexture() = 0;
	virtual void					GetShadowHandle() const = 0;
	virtual void*					RenderHandle() = 0;
	virtual const model_t*				GetModel() const = 0;
	virtual int						DrawModel(int flags) = 0;
	virtual int						GetBody() = 0;
	virtual void					ComputeFxBlend() = 0;

	bool SetupBones(matrix3x4 *pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime)
	{
		typedef bool(__thiscall* oSetupBones)(PVOID, matrix3x4*, int, int, float);
		return call_vfunc< oSetupBones>(this, 13)(this, pBoneToWorldOut, nMaxBones, boneMask, currentTime);
	}
};

class IClientNetworkable
{
public:
	virtual IClientUnknown*	GetIClientUnknown() = 0;
	virtual void			Release() = 0;
	virtual ClientClass*	GetClientClass() = 0;// FOR NETVARS FIND YOURSELF ClientClass* stuffs
	virtual void			NotifyShouldTransmit( /* ShouldTransmitState_t state*/) = 0;
	virtual void			OnPreDataChanged( /*DataUpdateType_t updateType*/) = 0;
	virtual void			OnDataChanged( /*DataUpdateType_t updateType*/) = 0;
	virtual void			PreDataUpdate( /*DataUpdateType_t updateType*/) = 0;
	virtual void			PostDataUpdate( /*DataUpdateType_t updateType*/) = 0;
	virtual void			unknown();
	virtual bool			IsDormant(void) = 0;
	virtual int				GetIndex(void) const = 0;
	virtual void			ReceiveMessage(int classID /*, bf_read &msg*/) = 0;
	virtual void*			GetDataTableBasePtr() = 0;
	virtual void			SetDestroyedOnRecreateEntities(void) = 0;
};

class IClientUnknown
{
public:
	virtual void*		GetCollideable() = 0;
	virtual IClientNetworkable*	GetClientNetworkable() = 0;
	virtual IClientRenderable*	GetClientRenderable() = 0;
	virtual IClientEntity*		GetIClientEntity() = 0;
	virtual IClientEntity*		GetBaseEntity() = 0;
	virtual IClientThinkable*	GetClientThinkable() = 0;
};

class IClientThinkable
{
public:
	virtual IClientUnknown*		GetIClientUnknown() = 0;
	virtual void				ClientThink() = 0;
	virtual void*				GetThinkHandle() = 0;
	virtual void				SetThinkHandle(void* hThink) = 0;
	virtual void				Release() = 0;
};

class __declspec (novtable)IClientEntity : public IClientUnknown, public IClientRenderable, public IClientNetworkable, public IClientThinkable
{
public:
public:
	virtual void			Release(void) = 0;
	virtual void			blahblahpad(void) = 0;
	virtual Vector& GetAbsOrigin(void) const = 0;//in broken place use GetOrigin Below
	virtual const Vector& GetAbsAngles(void) const = 0;


	int GetGlowIndex()
	{
		return *(int*)(this + 0xA3F8);
	}
	CNETVAR_FUNC(int, GetTeamNum, 0xC08B6C6E); //m_iTeamNum

	CNETVAR_FUNC(int, GetAmmoInClip, 0x97B6F70C);

	CPNETVAR_FUNC(Vector*, GetOriginPtr, 0x1231CE10); //m_vecOrigin
	CPNETVAR_FUNC(CLocalPlayerExclusive*, localPlayerExclusive, 0x7177BC3E);// m_Local
	CPNETVAR_FUNC(CollisionProperty*, collisionProperty, 0xE477CBD0);//m_Collision
	CNETVAR_FUNC(float, GetLowerBodyYaw, 0xE6996CCF); //m_flLowerBodyYawTarget
	CNETVAR_FUNC(int, GetFlags, 0xE456D580); //m_fFlags
	CNETVAR_FUNC(int, GetHealth, 0xA93054E3); //m_iHealth
	CNETVAR_FUNC(float, GetTargetYaw, 0xE6996CCF);
	CNETVAR_FUNC(Vector, GetOrigin, 0x1231CE10); //m_vecOrigin 0x0134
	CNETVAR_FUNC(Vector, GetRotation, 0x6BEA197A); //m_angRotation

	CNETVAR_FUNC(int*, GetPointerFlags, 0xE456D580); //m_fFlags
	CNETVAR_FUNC(HANDLE, GetOwnerHandle, 0xC32DF98D); //m_hOwner
	CNETVAR_FUNC(int, GetMaxHealth, 0xC52E1C28); //m_iMaxHealth
	CNETVAR_FUNC(Vector, GetVecOrigin, 0x134); //m_vecVelocity[0]

	CNETVAR_FUNC(bool, IsDefusing, 0xA2C14106); //m_bIsDefusing
	CNETVAR_FUNC(float, GetFlashDuration, 0x4B5938D5); //m_flFlashDuration
	CNETVAR_FUNC(float, GetFlashAlpha, 0xFE79FB98); //m_flFlashMaxAlpha
	CNETVAR_FUNC(unsigned char, GetLifeState, 0xD795CCFC); //m_lifeState
	CNETVAR_FUNC(HANDLE, GetActiveWeaponHandle, 0xB4FECDA3); //m_hActiveWeapon
	CNETVAR_FUNC(int, GetTickBase, 0xD472B079); //m_nTickBase
	CNETVAR_FUNC(Vector, GetViewOffset, 0xA9F74931); //m_vecViewOffset[0]
	CNETVAR_FUNC(Vector, GetViewPunch, 0x68F014C0);
	CNETVAR_FUNC(int, GetMoney, 0xF4B3E183); //m_iAccount
	CNETVAR_FUNC(Vector, GetPunch, 0xBF25C290);
	CNETVAR_FUNC(Vector, GetVelocity, 0x40C1CA24); //m_vecVelocity[0]
	CNETVAR_FUNC(bool, HasGunGameImmunity, 0x6AD6FA0D); //m_bGunGameImmunity
	CNETVAR_FUNC(int, ArmorValue, 0x3898634); //m_ArmorValue
	CNETVAR_FUNC(bool, HasHelmet, 0x7B97F18A); //m_bHasHelmet
	CNETVAR_FUNC(int, GetObserverMode, 0x2441D093); // m_iObserverMode
	CNETVAR_FUNC(HANDLE, GetObserverTargetHandle, 0x8660FD83); //m_hObserverTarget
	CNETVAR_FUNC(bool, HasDefuser, 0x32D0F325); //m_bHasDefuser
	CNETVAR_FUNC(int, GetShotsFired, 0x3F2F6C66); //m_nTickBase
	CNETVAR_FUNC(float, GetSimulationTime, 0xC4560E44); //m_flSimulationTime
	CNETVAR_FUNC(float, GetAnimTime, 0xD27E8416);
	CNETVAR_FUNC(bool, IsScoped, 0x61B9C22C); //m_bIsScoped

	bool IsAlive()
	{
		return (GetLifeState() == LIFE_ALIVE && GetHealth() > 0);
	}

	int GetMoveType()
	{
		if (!this)
			return 0;

		return ptr(int, this, 0x25C);
	}

	QAngle* GetEyeAnglesPointer()
	{
		return reinterpret_cast<QAngle*>((DWORD)this + (DWORD)0x528C);
	}

	QAngle GetEyeAngles()
	{
		return *reinterpret_cast<QAngle*>((DWORD)this + (DWORD)0x528C);
	}

	QAngle* GetEyeAnglesXY()
	{
		return (QAngle*)((DWORD)this + GET_NETVAR("DT_CSPlayer", "m_angEyeAngles"));
	}

	Vector GetBonePos(int i)
	{
		matrix3x4 boneMatrix[128];
		if (this->SetupBones(boneMatrix, 128, BONE_USED_BY_HITBOX, GetTickCount64()))
		{
			return Vector(boneMatrix[i][0][3], boneMatrix[i][1][3], boneMatrix[i][2][3]);
		}
		return Vector(0, 0, 0);
	}

	Vector GetHeadPos()
	{
		return this->GetBonePos(8);
	}

	Vector GetHeadAngle()
	{
		return GetAbsOrigin() + GetViewOffset();
	}

	int GetId()
	{
		typedef int(__thiscall* tGetId)(void*);
		return call_vfunc<tGetId>(this, 458)(this);
	}

	bool IsPlayer()
	{
		return GetClientClass()->m_ClassID == (int)CSGOClassID::CCSPlayer;
	}

	Vector GetOrigin2() {
		return *(Vector*)((DWORD)this + 0x138);
	}

	Vector GetViewAngles2() {
		return *(Vector*)((DWORD)this + 0x108);
	}

	Vector GetAbsOrigin2() {
		__asm {
			MOV ECX, this
			MOV EAX, DWORD PTR DS : [ECX]
			CALL DWORD PTR DS : [EAX + 0x28]
		}
	}
	Vector GetAbsAngles2() {
		__asm {
			MOV ECX, this;
			MOV EAX, DWORD PTR DS : [ECX];
			CALL DWORD PTR DS : [EAX + 0x2C]
		}
	}

	Vector GetEyePosition() {
		Vector Origin = *(Vector*)((DWORD)this + 0x138);
		Vector View = *(Vector*)((DWORD)this + 0x108);
		return(Origin + View);
	}
	Vector GetAimPunch() {
		return *(Vector*)((DWORD)this + 0x302C);
	}
	bool IsImmune() {
		return *(bool*)((DWORD)this + 0x3928);
	}
	ClientClass* GetClientClass2() {
		PVOID Networkable = (PVOID)((DWORD)(this) + 0x8);
		using Original = ClientClass * (__thiscall*)(PVOID);
		return call_vfunc<Original>(Networkable, 2)(Networkable);
	}
	HANDLE GetWeaponHandle() {
		return *(HANDLE*)((DWORD)this + 0x00002EE8);
	}

};

class CBaseViewModel : public IClientUnknown, public IClientRenderable, public IClientNetworkable
{
public:
	inline int GetModelIndex() {
		// DT_BaseViewModel -> m_nModelIndex
		return *(int*)((DWORD)this + 0x258);
	}
	inline DWORD GetOwner() {
		// DT_BaseViewModel -> m_hOwner
		return *(PDWORD)((DWORD)this + 0x29CC);
	}
	inline DWORD GetWeapon() {
		// DT_BaseViewModel -> m_hWeapon
		return *(PDWORD)((DWORD)this + 0x29B8);
	}
	inline void SetWeaponModel(const char* Filename, IClientUnknown* Weapon) {
		return call_vfunc<void(__thiscall*)(void*, const char*, IClientUnknown*)>(this, 243)(this, Filename, Weapon);
	}
};

typedef unsigned short MaterialHandle_t;