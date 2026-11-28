// M72A6 LAW. Original ADFU asset, re-implemented for ADF Re-Cut.
//   adfrc_m72a6_collapsed : the Arsenal / Eden item. Collapsed tube, no rocket, nothing in the inventory.
//                           Reload (R) runs fn_prepare: prep gesture + sound, then swaps it for adfrc_m72a6
//                           with the rocket loaded. Non-playable AI get a ready tube straight away (fn_readyForAI).
//   adfrc_m72a6           : extended tube with the rocket, ready to fire.
//   adfrc_m72a6_used      : what CBA's disposable framework swaps to after firing (empty tube). CBA's own
//                           "Drop used launcher" setting decides when it hits the ground.
//   adfrc_m72a6_loaded    : only here because CBA's framework needs a loaded class (crates etc). Hidden.
// CBA checks: mass(adfrc_m72a6) == mass(used), mass(adfrc_m72a6) + mass(mag) == mass(loaded).
class CfgPatches
{
	class adfrc_m72
	{
		name = "ADF Re-Cut M72A6 LAW";
		author = "$STR_ADF_AUTHOR";
		units[] = {};
		weapons[] = {"adfrc_m72a6_collapsed", "adfrc_m72a6", "adfrc_m72a6_loaded", "adfrc_m72a6_used"};
		magazines[] = {"adfrc_m72a6_mag"};
		ammo[] = {"adfrc_r_66mm_m72"};
		requiredVersion = 1;
		requiredAddons[] = {"A3_Weapons_F", "A3_Weapons_F_Acc", "A3_Anims_F_Config_Sdr", "cba_xeh", "cba_disposable", "ADF_Core"};
	};
};

class CfgFunctions
{
	class adfrc_m72
	{
		tag = "adfrc_m72";
		class m72
		{
			file = "\ADF_Weapons2\adfrc_m72\functions";
			class prepare {};
			class readyForAI {};
		};
	};
};

class Extended_PostInit_EventHandlers
{
	class adfrc_m72
	{
		init = "call compileScript ['\ADF_Weapons2\adfrc_m72\XEH_postInit.sqf']";
		clientInit = "call compileScript ['\ADF_Weapons2\adfrc_m72\XEH_postInitClient.sqf']";
	};
};

// Prepare gesture, played by fn_prepare (not by the engine's reload). Wired the same way BI wires GestureReloadRPG7 (CfgMovesBasic + CfgGesturesMale).
// PLACEHOLDER ANIM: both gestures inherit the vanilla launcher reload (LauncherMagazineReloadStand, what
// "reloadMagazine" plays on launchers, stand and kneel) until the real M72 prep RTMs exist.
// When they do: set file (and speed = 1 / length in seconds) in the two CfgGesturesMale classes below.
// fn_prepare waits 1 / speed before swapping the tube, so the swap stays in sync with the animation.
class CfgMovesBasic
{
	class ManActions
	{
		ADFRC_GestureReloadM72 = "ADFRC_GestureReloadM72";
	};
	class Actions
	{
		class NoActions: ManActions
		{
			ADFRC_GestureReloadM72[] = {"ADFRC_GestureReloadM72", "Gesture"};
		};
		class LauncherKneelActions: NoActions
		{
			ADFRC_GestureReloadM72[] = {"ADFRC_GestureReloadM72Kneel", "Gesture"};
		};
		class LauncherStandActions: LauncherKneelActions
		{
			ADFRC_GestureReloadM72[] = {"ADFRC_GestureReloadM72", "Gesture"};
		};
	};
};

class CfgGesturesMale
{
	class States
	{
		class LauncherMagazineReloadStand;
		class ADFRC_GestureReloadM72: LauncherMagazineReloadStand
		{
			// file = "\ADF_Weapons2\adfrc_m72\anim\m72a6_prep.rtm";
			// speed = 0.4;
		};
		class ADFRC_GestureReloadM72Kneel: LauncherMagazineReloadStand
		{
			// file = "\ADF_Weapons2\adfrc_m72\anim\m72a6_prep_knl.rtm";
			// speed = 0.4;
		};
	};
};

class CBA_DisposableLaunchers
{
	adfrc_m72a6[] = {"adfrc_m72a6_loaded", "adfrc_m72a6_used"};
};

class CfgAmmo
{
	class R_60mm_HE;
	class adfrc_r_66mm_m72: R_60mm_HE
	{
		author = "$STR_ADF_AUTHOR";
		model = "\ADF_Weapons2\adfrc_m72\adfrc_m72a6_rocket_fly";
		hit = 550;
		cost = 300;
		initTime = 0;
		AIS_Penetrator = 1;
		AIS_Penetrator_HEAT = 1;
		AIS_Penetrator_Ammo = "AIS_HEAT_JET_Light";
		maxSpeed = 250;
		thrustTime = 2;
		thrust = 100;
		timeToLive = 20;
		fuseDistance = 15;
		airFriction = 0.05;
		sideAirFriction = 0.5;
		indirectHit = 50;
		indirectHitRange = 10;
		effectsMissile = "missile3";
		whistleDist = 16;
		CraterEffects = "ATRocketCrater";
		explosionEffects = "ATRocketExplosion";
		effectsMissileInit = "RocketBackEffectsNLAW";
		simulationStep = 0.02;
		airLock = 0;
		irLock = 0;
		maneuvrability = 0;
		allowAgainstInfantry = 1;
	};
};

class CfgMagazines
{
	class CA_LauncherMagazine;
	class adfrc_m72a6_mag: CA_LauncherMagazine
	{
		scope = 1;
		author = "$STR_ADF_AUTHOR";
		displayName = "M72A6 66mm HEAT Rocket";
		descriptionShort = "M72A6 66mm HEAT rocket";
		picture = "\ADF_Weapons2\adfrc_m72\ui\m72a6_at_co.paa";
		model = "\ADF_Weapons2\adfrc_m72\adfrc_m72a6_rocket";
		ammo = "adfrc_r_66mm_m72";
		allowedSlots[] = {801, 901, 701};
		count = 1;
		initSpeed = 145;
		mass = 30;
	};
};

class Mode_SemiAuto;
class CfgWeapons
{
	class Launcher;
	class Launcher_Base_F: Launcher
	{
		class WeaponSlotsInfo;
	};

	// Prepared launcher (extended, rocket loaded, held and fired). Hidden: the Arsenal shows adfrc_m72a6_collapsed.
	class adfrc_m72a6: Launcher_Base_F
	{
		scope = 1;
		scopeArsenal = 1;
		author = "$STR_ADF_AUTHOR";
		displayName = "M72A6 LAW";
		descriptionShort = "66mm disposable rocket launcher<br/>Australian manufacture";
		picture = "\ADF_Weapons2\adfrc_m72\ui\m72a6_armed_ca.paa";
		// model = empty tube: its memory points (eye, usti/konec hlavne) are on the tube axis.
		// The loaded p3d has usti hlavne 36 cm up, so as "model" it tilts the whole launcher ~19 deg (broken ADS).
		// Same arrangement as the ADFU original: loaded p3d is only modelSpecial (shown while the rocket is in).
		model = "\ADF_Weapons2\adfrc_m72\adfrc_m72a6_empty.p3d";
		modelSpecial = "\ADF_Weapons2\adfrc_m72\adfrc_m72a6_loaded.p3d";
		handAnim[] = {"OFP2_ManSkeleton", "\ADF_Weapons2\adfrc_m72\anim\m72a6.rtm"};
		reloadAction = "ADFRC_GestureReloadM72";
		magazineReloadTime = 0.1; // CBA wiki: avoids the launcher being unusable right after first selection
		magazines[] = {"adfrc_m72a6_mag"};
		recoil = "recoil_single_nlaw";
		// dry / reload / fire sounds: same as vanilla RPG-7 (launch_RPG7_F, which uses the RPG-32 set)
		drySound[] = {"A3\Sounds_F\arsenal\weapons\Launchers\RPG32\Dry_RPG32", 0.4466836, 1, 20};
		reloadMagazineSound[] = {"A3\Sounds_F\arsenal\weapons\Launchers\RPG32\reload_RPG32", 1.0, 1, 10};
		soundFly[] = {"A3\sounds_f\weapons\Explosion\cannon_fly", 0.316228, 1.5, 700};
		modelOptics = "\A3\Weapons_F\acc\reticle_NLAW";
		cameraDir = "look";
		canLock = 0;
		weaponLockDelay = 3;
		lockAcquire = 0;
		opticsZoomMin = 0.375;
		opticsZoomMax = 1;
		opticsZoomInit = 0.75;
		class OpticsModes
		{
			class IronSight
			{
				opticsID = 1;
				useModelOptics = 0;
				opticsZoomMin = 0.375;
				opticsZoomMax = 1;
				opticsZoomInit = 0.75;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				memoryPointCamera = "eye";
				opticsFlare = 1;
				opticsDisablePeripherialVision = 0;
				cameraDir = "look";
				visionMode[] = {"Normal"};
				opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
			};
		};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			sounds[] = {"StandardSound"};
			class BaseSoundModeType {};
			class StandardSound: BaseSoundModeType
			{
				begin1[] = {"A3\Sounds_F\arsenal\weapons\Launchers\RPG32\rpg32", 1.9952624, 1, 1500};
				soundBegin[] = {"begin1", 1};
			};
			recoil = "recoil_single_nlaw";
			aiRateOfFire = 7;
			aiRateOfFireDistance = 600;
			minRange = 10;
			minRangeProbab = 0.3;
			midRange = 400;
			midRangeProbab = 0.58;
			maxRange = 600;
			maxRangeProbab = 0.04;
		};
		class GunParticles
		{
			class effect1
			{
				positionName = "back_end";
				directionName = "back_start";
				effectName = "RocketBackEffectsRPGNT";
			};
			class effect2
			{
				positionName = "front_end";
				directionName = "front_start";
				effectName = "ADFRC_M72_ForwardBlast";
			};
		};
		class EventHandlers
		{
			fired = "_this call CBA_fnc_firedDisposable"; // required by the CBA disposable framework
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 50;
		};
		class Library
		{
			libTextDesc = "66mm Disposable Rocket Launcher";
		};
	};

	// Collapsed tube: the Arsenal / Eden item. Can't be fired or reloaded by the engine (fake magazine only);
	// Reload is caught by XEH_postInitClient.sqf and runs adfrc_m72_fnc_prepare.
	class adfrc_m72a6_collapsed: adfrc_m72a6
	{
		scope = 2;
		scopeArsenal = 2;
		baseWeapon = "adfrc_m72a6_collapsed";
		displayName = "M72A6 LAW";
		picture = "\ADF_Weapons2\adfrc_m72\ui\m72a6_launcher_ca.paa";
		model = "\ADF_Weapons2\adfrc_m72\adfrc_m72a6_collapsed.p3d";
		modelSpecial = "\ADF_Weapons2\adfrc_m72\adfrc_m72a6_collapsed.p3d";
		magazines[] = {"CBA_FakeLauncherMagazine"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 80;
		};
	};

	// CBA disposable "loaded" class. Required by the framework, not handed out by ADFRC. If a unit ever
	// gets one (e.g. CBA turning a loose rocket in a crate into a launcher), CBA makes it adfrc_m72a6 + rocket.
	class adfrc_m72a6_loaded: adfrc_m72a6
	{
		scope = 1;
		scopeArsenal = 1;
		baseWeapon = "adfrc_m72a6_loaded";
		displayName = "M72A6 LAW";
		picture = "\ADF_Weapons2\adfrc_m72\ui\m72a6_launcher_ca.paa";
		model = "\ADF_Weapons2\adfrc_m72\adfrc_m72a6_loaded.p3d";
		modelSpecial = "\ADF_Weapons2\adfrc_m72\adfrc_m72a6_loaded.p3d";
		magazines[] = {"CBA_FakeLauncherMagazine"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 80;
		};
	};

	// Spent tube.
	class adfrc_m72a6_used: adfrc_m72a6
	{
		scope = 1;
		scopeArsenal = 1;
		baseWeapon = "adfrc_m72a6_used";
		displayName = "M72A6 LAW (Used)";
		picture = "\ADF_Weapons2\adfrc_m72\ui\m72a6_used_ca.paa";
		model = "\ADF_Weapons2\adfrc_m72\adfrc_m72a6_empty.p3d";
		modelSpecial = "\ADF_Weapons2\adfrc_m72\adfrc_m72a6_empty.p3d";
		magazines[] = {"CBA_FakeLauncherMagazine"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 50;
		};
	};
};

class CfgCloudlets
{
	class Default;
	class ADFRC_M72_CircleSmoke: Default
	{
		interval = 0.05;
		circleRadius = 0;
		circleVelocity[] = {0, 0, 0};
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 8;
		particleFSLoop = 0;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 1.25;
		moveVelocity[] = {"directionX * 2.2", "directionY * 2.2", "directionZ * 2.2"};
		rotationVelocity = 1;
		weight = 0.1285;
		volume = 0.1;
		rubbing = 0.8;
		size[] = {0.15, 0.3, 0.5};
		sizeCoef = "1.5 * (vehicleSpeedSize interpolate [1.5,18,1,2])";
		color[] = {{0.8, 0.8, 0.8, 0.4}, {0.8, 0.8, 0.8, 0.3}, {0.8, 0.8, 0.8, 0.05}, {0.8, 0.8, 0.8, 0.01}};
		colorCoef[] = {1, 1, 1, "0.3 * (vehicleSpeedSize interpolate [1.5,18,2,1])"};
		animationSpeed[] = {2, 1};
		animationSpeedCoef = 1;
		randomDirectionPeriod = 0.05;
		randomDirectionIntensity = 0.15;
		onTimerScript = "";
		beforeDestroyScript = "";
		blockAIVisibility = 0;
		destroyOnWaterSurface = 1;
		destroyOnWaterSurfaceOffset = -0.1;
		lifeTimeVar = 0.2;
		position[] = {"positionX", "positionY", "positionZ"};
		positionVar[] = {0.05, 0.05, 0.05};
		MoveVelocityVar[] = {0.15, 0.15, 0.001};
		rotationVelocityVar = 20;
		sizeVar = 0.1;
		colorVar[] = {0, 0, 0, 0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
};

// Front blast ring: 12 puffs around the muzzle (unchanged from ADFU)
class ADFRC_M72_ForwardBlast
{
	class _xx_00 { simulation = "particles"; type = "ADFRC_M72_CircleSmoke"; position[] = {0.2, 0, 0.05}; intensity = 1; interval = 1; lifeTime = 1; qualityLevel = -1; };
	class _xx_02 { simulation = "particles"; type = "ADFRC_M72_CircleSmoke"; position[] = {0.1732, 0.1, 0.05}; intensity = 1; interval = 1; lifeTime = 1; qualityLevel = -1; };
	class _xx_04 { simulation = "particles"; type = "ADFRC_M72_CircleSmoke"; position[] = {0.1, 0.1732, 0.05}; intensity = 1; interval = 1; lifeTime = 1; qualityLevel = -1; };
	class _xx_06 { simulation = "particles"; type = "ADFRC_M72_CircleSmoke"; position[] = {0, 0.2, 0.05}; intensity = 1; interval = 1; lifeTime = 1; qualityLevel = -1; };
	class _xx_08 { simulation = "particles"; type = "ADFRC_M72_CircleSmoke"; position[] = {-0.1, 0.1732, 0.05}; intensity = 1; interval = 1; lifeTime = 1; qualityLevel = -1; };
	class _xx_10 { simulation = "particles"; type = "ADFRC_M72_CircleSmoke"; position[] = {-0.1732, 0.1, 0.05}; intensity = 1; interval = 1; lifeTime = 1; qualityLevel = -1; };
	class _xx_12 { simulation = "particles"; type = "ADFRC_M72_CircleSmoke"; position[] = {-0.2, 0, 0.05}; intensity = 1; interval = 1; lifeTime = 1; qualityLevel = -1; };
	class _xx_14 { simulation = "particles"; type = "ADFRC_M72_CircleSmoke"; position[] = {-0.1732, -0.1, 0.05}; intensity = 1; interval = 1; lifeTime = 1; qualityLevel = -1; };
	class _xx_16 { simulation = "particles"; type = "ADFRC_M72_CircleSmoke"; position[] = {-0.1, -0.1732, 0.05}; intensity = 1; interval = 1; lifeTime = 1; qualityLevel = -1; };
	class _xx_18 { simulation = "particles"; type = "ADFRC_M72_CircleSmoke"; position[] = {0, -0.2, 0.05}; intensity = 1; interval = 1; lifeTime = 1; qualityLevel = -1; };
	class _xx_20 { simulation = "particles"; type = "ADFRC_M72_CircleSmoke"; position[] = {0.1, -0.1732, 0.05}; intensity = 1; interval = 1; lifeTime = 1; qualityLevel = -1; };
	class _xx_22 { simulation = "particles"; type = "ADFRC_M72_CircleSmoke"; position[] = {0.1732, -0.1, 0.05}; intensity = 1; interval = 1; lifeTime = 1; qualityLevel = -1; };
};
