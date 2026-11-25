class CfgPatches
{
	class adfrc_arafura
	{
		addonRootClass = "A3_Boat_F";
		requiredAddons[] = {"A3_Boat_F","A3_Weapons_F","A3_Data_F_Mod_Loadorder","cba_main","cba_xeh","ADF_Core","ADF_Units","adfrc_abrams","adfrc_lcm","adfrc_fremantle","adfrc_aslav","adfrc_rhib","A3_Weapons_F_Destroyer"};
		requiredVersion = 0.1;
		units[] = {"adfrc_arafura"};
		weapons[] = {"adfrc_typhoon_m242","adfrc_arafura_horn","adfrc_asm_launcher"};
	};
};

class CfgFunctions
{
	// Tag = first-level class, so functions compile as adfrc_arafura_fnc_*
	class adfrc_arafura
	{
		class Arafura
		{
			file = "ADF_Boat\adfrc_arafura\functions";
			class rhib {};
			class boatInit {};
			class ladder {};
			class asmFired {};
		};
	};
};

// XEH must live at config root, keyed by the leaf vehicle class.
class Extended_Init_EventHandlers
{
	class adfrc_arafura
	{
		class adfrc_arafura_board
		{
			init = "(_this select 0) call adfrc_arafura_fnc_boatInit";
		};
		// RAN ensign on the flag proxy (\A3\data_f\proxies\flags\flag_alone). Runs on every machine, so JIP is covered.
		class adfrc_arafura_flag
		{
			init = "(_this select 0) forceFlagTexture '\ADF_Core\data\adf_ran_flag_co.paa'";
		};
		// Death sequence (function lives in adfrc_fremantle)
		class adfrc_arafura_sinkFx
		{
			init = "(_this select 0) call adfrc_fremantle_fnc_sinkInit";
		};
	};
};

// Anti-ship missiles leave from the four launch canisters in turn (round 1 uses the turret's missileBeg).
// FiredBIS passes the game's own fired arguments [unit, weapon, muzzle, mode, ammo, magazine, projectile, ...];
// the legacy XEH fired event uses an older order without the magazine.
class Extended_FiredBIS_EventHandlers
{
	class adfrc_arafura
	{
		adfrc_arafura_asm = "_this call adfrc_arafura_fnc_asmFired";
	};
};

// Vanilla sensor templates (defined at config root by A3 data_f)
class SensorTemplateActiveRadar;
class SensorTemplateDataLink;

class CfgAmmo
{
	// Anti-ship missile: sea-skimming cruise profile, active radar seeker that tracks moving ships,
	// datalink from the ship's radar. Vanilla cruise missile base with the Liberty's missile model.
	class ammo_Missile_CruiseBase;
	class adfrc_asm_nsm: ammo_Missile_CruiseBase
	{
		model = "\A3\Weapons_F_Destroyer\Ammo\Missile_Cruise_01_Fly_F";
		proxyShape = "\A3\Weapons_F_Destroyer\Ammo\Missile_Cruise_01_Fly_F";
		hit = 3000;
		indirectHit = 1200;
		indirectHitRange = 15;
		maxSpeed = 290;
		thrust = 60;
		thrustTime = 140;
		timeToLive = 160;
		initTime = 0.3;
		maneuvrability = 20;
		fuseDistance = 150;
		muzzleEffect = "";
		weaponLockSystem = "8 + 16";
		autoSeekTarget = 1;
		lockSeekRadius = 2000;
		missileLockCone = 360;
		missileKeepLockedCone = 360;
		missileLockMaxSpeed = 40;
		missileLockMaxDistance = 30000;
		missileLockMinDistance = 300;
		flightProfiles[] = {"Cruise"};
		class Cruise
		{
			preferredFlightAltitude = 12;
			lockDistanceToTarget = 2000;
		};
		class Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange = 0;
							maxRange = 0;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						class GroundTarget
						{
							minRange = 15000;
							maxRange = 15000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						angleRangeHorizontal = 60;
						angleRangeVertical = 40;
						groundNoiseDistanceCoef = -1;
						maxGroundNoiseDistance = -1;
						minSpeedThreshold = 0;
						maxSpeedThreshold = 0;
						maxTrackableSpeed = 40;
					};
					class DataLinkSensorComponent: SensorTemplateDataLink
					{
						class AirTarget
						{
							minRange = 0;
							maxRange = 0;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						class GroundTarget
						{
							minRange = 30000;
							maxRange = 30000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						maxTrackableSpeed = 40;
					};
				};
			};
		};
	};

	class adfrc_aslav_m242_25mm_HE;
	// lockable (air + ground) so the FCS can compute lead on radar-locked targets
	class adfrc_typhoon_25mm_HE: adfrc_aslav_m242_25mm_HE
	{
		airLock = 1;
		canLock = 2;
	};
};

class CfgMagazines
{
	class VehicleMagazine;
	class adfrc_asm_4Rnd: VehicleMagazine
	{
		author = "ADFRC";
		scope = 2;
		displayName = "Anti-Ship Missile x4";
		displayNameShort = "ASM";
		descriptionShort = "Sea-skimming anti-ship missile, active radar homing";
		ammo = "adfrc_asm_nsm";
		initSpeed = 25;
		maxLeadSpeed = 40;
		count = 4;
		nameSound = "missiles";
	};
	class adfrc_aslav_m242_300rnd_25mm_HE;
	class adfrc_typhoon_165rnd_25mm_HE: adfrc_aslav_m242_300rnd_25mm_HE
	{
		displayName = "25mm HE-T (Typhoon)";
		ammo = "adfrc_typhoon_25mm_HE";
		count = 165;
	};
};

class CfgWeapons
{
	class CarHorn;
	// Driver's "weapon": ship horn (same clip as the Fremantle).
	class adfrc_arafura_horn: CarHorn
	{
		displayName = "Ship Horn";
		drySound[] = {"ADF_Boat\adfrc_fremantle\sounds\fremantle_horn.ogg",3.1622777,1,2500};
		reloadTime = 2.4;
	};
	// Anti-ship missile launcher (captain): radar lock through the ship's sensors, fires from the canisters.
	class MissileLauncher;
	class weapon_VLSBase: MissileLauncher
	{
		class Cruise;
	};
	class adfrc_asm_launcher: weapon_VLSBase
	{
		author = "ADFRC";
		displayName = "Anti-Ship Missiles";
		magazines[] = {"adfrc_asm_4Rnd"};
		reloadTime = 6;
		magazineReloadTime = 900;
		weaponLockDelay = 3;
		class Cruise: Cruise
		{
			displayName = "ASM";
			reloadTime = 6;
			minRange = 300;
			maxRange = 30000;
		};
	};
	// Typhoon 25 mm: the ADFRC ASLAV M242 with a radar lead FCS (locks radar contacts, computes lead).
	class autocannon_Base_F;
	class adfrc_aslav_M242: autocannon_Base_F
	{
		class HE;
		class AP;
	};
	class adfrc_typhoon_m242: adfrc_aslav_M242
	{
		displayName = "Typhoon 25mm (M242)";
		canLock = 2;
		weaponLockSystem = 2;
		weaponLockDelay = 2;
		class HE: HE
		{
			displayName = "Typhoon 25mm HE-T";
			magazines[] = {"adfrc_typhoon_165rnd_25mm_HE","adfrc_aslav_m242_300rnd_25mm_HE"};
			canLock = 2;
			ballisticsComputer = "1 + 2 + 16";
			FCSMaxLeadSpeed = 200;
			weaponLockSystem = 2;
			weaponLockDelay = 2;
		};
		class AP: AP
		{
			canLock = 2;
			ballisticsComputer = "1 + 2 + 16";
			FCSMaxLeadSpeed = 200;
		};
	};
};

// Vanilla sensor + panel templates (defined at config root by A3 data_f), declared exactly as BI does
class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftDriver: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightDriver: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftGunner: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightGunner: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftCommander: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightCommander: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};

#define ARA_SENSOR_PANELS(LEFT,RIGHT) \
	class Components \
	{ \
		class VehicleSystemsDisplayManagerComponentLeft: LEFT \
		{ \
			class Components: components \
			{ \
				class SensorDisplay \
				{ \
					componentType = "SensorsDisplayComponent"; \
					range[] = {16000,8000,4000,2000}; \
					resource = "RscCustomInfoSensors"; \
				}; \
			}; \
		}; \
		class VehicleSystemsDisplayManagerComponentRight: RIGHT \
		{ \
			defaultDisplay = "SensorDisplay"; \
			class Components: components \
			{ \
				class SensorDisplay \
				{ \
					componentType = "SensorsDisplayComponent"; \
					range[] = {16000,8000,4000,2000}; \
					resource = "RscCustomInfoSensors"; \
				}; \
			}; \
		}; \
	};

class CfgVehicles
{
	class Ship_F;
	class Boat_F: Ship_F
	{
		class NewTurret;
		class Turrets;
		class ViewPilot;
		class ViewOptics;
	};
	class adfrc_arafura_base: Boat_F
	{
		author = "ADFRC";
		model = "\ADF_Boat\adfrc_arafura\adfrc_arafura.p3d";
		mapSize = 80;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {"veh_ship_attackBoat_s"};
				speechPlural[] = {"veh_ship_attackBoat_p"};
			};
		};
		textSingular = "$STR_A3_nameSound_veh_ship_attackBoat_s";
		textPlural = "$STR_A3_nameSound_veh_ship_attackBoat_p";
		nameSound = "veh_ship_attackBoat_s";
		vehicleClass = "Ship";
		editorSubcategory = "EdSubcat_Boats";
		picture = "\A3\boat_f\Boat_Armed_01\Data\UI\Boat_Armed_01_Base.paa";
		Icon = "\A3\boat_f\Boat_Armed_01\data\ui\map_boat_armed_01.paa";
		unitInfoType = "RscUnitInfoShip";
		extCameraPosition[] = {0,8,-80};
		memoryPointTaskMarker = "TaskMarker_1_pos";
		crewVulnerable = 0;
		attenuationEffectType = "OpenCarAttenuation";
		insideSoundCoef = 0;
		soundEngineOnInt[] = {"a3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-ext-start-02",0.56234133,0.6};
		soundEngineOnExt[] = {"a3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-ext-start-02",0.56234133,0.6,300};
		soundEngineOffInt[] = {"a3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-ext-stop-02",0.56234133,0.6};
		soundEngineOffExt[] = {"a3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-ext-stop-02",0.56234133,0.6,300};
		buildCrash0[] = {"A3\sounds_f\Vehicles\boat\noises\Metal_boat_crash_building_01",1.7782794,1,200};
		buildCrash1[] = {"A3\sounds_f\Vehicles\boat\noises\Metal_boat_crash_building_02",1.7782794,1,200};
		buildCrash2[] = {"A3\sounds_f\Vehicles\boat\noises\Metal_boat_crash_building_03",1.7782794,1,200};
		soundBuildingCrash[] = {"buildCrash0",0.33,"buildCrash1",0.33,"buildCrash2",0.34};
		WoodCrash0[] = {"A3\sounds_f\Vehicles\boat\noises\Metal_boat_crash_wood_01",1.7782794,1,200};
		WoodCrash1[] = {"A3\sounds_f\Vehicles\boat\noises\Metal_boat_crash_wood_02",1.7782794,1,200};
		WoodCrash2[] = {"A3\sounds_f\Vehicles\boat\noises\Metal_boat_crash_wood_03",1.7782794,1,200};
		soundWoodCrash[] = {"woodCrash0",0.33,"woodCrash1",0.33,"woodCrash2",0.34};
		ArmorCrash0[] = {"A3\sounds_f\Vehicles\boat\noises\Metal_boat_crash_armor_01",3.1622777,1,200};
		ArmorCrash1[] = {"A3\sounds_f\Vehicles\boat\noises\Metal_boat_crash_armor_02",3.1622777,1,200};
		ArmorCrash2[] = {"A3\sounds_f\Vehicles\boat\noises\Metal_boat_crash_armor_03",3.1622777,1,200};
		soundArmorCrash[] = {"ArmorCrash0",0.33,"ArmorCrash1",0.33,"ArmorCrash2",0.34};
		soundGeneralCollision1[] = {"A3\sounds_f\Vehicles\boat\noises\Metal_boat_crash_armor_01",1.7782794,1,100};
		soundGeneralCollision2[] = {"A3\sounds_f\Vehicles\boat\noises\Metal_boat_crash_armor_02",1.7782794,1,100};
		soundGeneralCollision3[] = {"A3\sounds_f\Vehicles\boat\noises\Metal_boat_crash_armor_03",1.7782794,1,100};
		soundCrashes[] = {"soundGeneralCollision1",0.33,"soundGeneralCollision2",0.33,"soundGeneralCollision3",0.34};
		// Engine: vanilla Boat_Armed_01 set pitched down (0.6) as a stop-gap for the twin diesels, same approach as the Fremantle.
		class Sounds
		{
			class IdleOut
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-idle-2",0.5011872,1.0,400};
				frequency = "0.6 * (0.95	+	((rpm/	1200) factor[(100/	1200),(300/	1200)])*0.15)";
				volume = "engineOn*(((rpm/	1200) factor[(0/	1200),(30/	1200)])	*	((rpm/	1200) factor[(500/	1200),(300/	1200)]))";
			};
			class Engine
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-low-2",0.63095737,1.0,550};
				frequency = "0.6 * (0.95	+	((rpm/	1200) factor[(300/	1200),(600/	1200)])*0.2)";
				volume = "engineOn*(((rpm/	1200) factor[(150/	1200),(250/	1200)])	*	((rpm/	1200) factor[(600/	1200),(400/	1200)]))";
			};
			class EngineMidOut
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-mid-2",0.7943282,1.0,600};
				frequency = "0.6 * (0.95	+		((rpm/	1200) factor[(600/	1200),(900/	1200)])*0.2)";
				volume = "engineOn*(((rpm/	1200) factor[(350/	1200),(500/	1200)])	*	((rpm/	1200) factor[(1000/	1200),(700/	1200)]))";
			};
			class EngineMaxOut
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-high-2",1.0,1.0,700};
				frequency = "0.6 * (0.95	+	((rpm/	1200) factor[(700/	1200),(1000/	1200)])*0.2)";
				volume = "engineOn*((rpm/	1200) factor[(800/	1200),(1200/	1200)])";
			};
			class WaternoiseOutW0
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-0-speed1",0.70794576,1.0,200};
				frequency = "1";
				volume = "(speed factor[4, 1]) * water";
			};
			class WaternoiseOutW1
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-20-speed",0.7943282,1.0,300};
				frequency = "1";
				volume = "((speed factor[2, 6]) min (speed factor[6, 4]))";
			};
			class WaternoiseOutW2
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-50-speed",1.0,1.0,400};
				frequency = "1";
				volume = "(speed factor[3, 9])";
			};
			class scrubLandExt
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\noises\boat_land_on_shallow",1.7782794,0.9,100};
				frequency = 1;
				volume = "(scrubLand factor[0.01, 0.20])";
			};
			class RainExt
			{
				sound[] = {"A3\Sounds_F\vehicles\noises\rain1_ext",1.0,1.0,100};
				frequency = 1;
				volume = "camPos * (rain - rotorSpeed/2) * 2";
			};
			class RainInt
			{
				sound[] = {"A3\Sounds_F\vehicles\noises\rain1_ext",1.0,1.0,100};
				frequency = 1;
				volume = "(1-camPos)*(rain - rotorSpeed/2)*2";
			};
		};
		armor = 600;
		armorStructural = 6;
		class HitPoints
		{
			class HitBody
			{
				armor = 1;
				material = 50;
				name = "karoserie";
				visual = "";
				passThrough = 1;
				explosionShielding = 2;
			};
			class HitEngine
			{
				armor = 0.8;
				material = -1;
				name = "engine";
				visual = "";
				passThrough = 0.3;
				minimalHit = 0.1;
				explosionShielding = 0.5;
				radius = 0.9;
			};
			class HitFuel
			{
				armor = 0.7;
				material = -1;
				name = "fuel";
				visual = "";
				passThrough = 0.3;
				minimalHit = 0.1;
				explosionShielding = 0.6;
				radius = 0.9;
			};
		};

		// Driver: helm chair, centre of the bridge.
		driverAction = "driver_mid01";
		driverInAction = "driver_mid01";
		forceHideDriver = 1;
		driverForceOptics = 0;
		// first person uses the View Pilot LOD for every seat (there is no View Gunner LOD)
		LODDriverTurnedIn = 1100;
		LODDriverTurnedOut = 1100;
		hideProxyInCombat = 0;
		viewDriverInExternal = 1;
		memoryPointsGetInDriver = "pos driver";
		memoryPointsGetInDriverDir = "pos driver dir";
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		castDriverShadow = 1;

		// Passengers: 16 seats on the benches along the mission bay sides (cargo proxies 1-16).
		cargoAction[] = {"passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands"};
		cargoProxyIndexes[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
		transportSoldier = 16;
		memoryPointsGetInCargo = "pos cargo";
		memoryPointsGetInCargoDir = "pos cargo dir";
		cargoGetInAction[] = {"GetInLow"};
		cargoGetOutAction[] = {"GetOutLow"};
		castCargoShadow = 1;
		// Crew = Compartment1, passengers = Compartment2: no "Move to" between them.
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment2"};

		// Active radar (surface + air search) shared over datalink; sensor panels for the bridge crew.
		radarTarget = 1;
		radarTargetSize = 2.5;
		reportRemoteTargets = 1;
		receiveRemoteTargets = 1;
		reportOwnPosition = 1;
		allowTabLock = 1;
		class Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange = 16000;
							maxRange = 16000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						class GroundTarget
						{
							minRange = 16000;
							maxRange = 16000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						typeRecognitionDistance = 6000;
						// surface search: no ground-clutter filter, otherwise slow ships at sea level drop off the scope
						groundNoiseDistanceCoef = -1;
						maxGroundNoiseDistance = -1;
						minSpeedThreshold = 0;
						maxSpeedThreshold = 0;
						angleRangeHorizontal = 360;
						angleRangeVertical = 90;
						aimDown = 0;
						maxTrackableSpeed = 400;
					};
					class DataLinkSensorComponent: SensorTemplateDataLink {};
				};
			};
			class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftDriver
			{
				class Components: components
				{
					class SensorDisplay
					{
						componentType = "SensorsDisplayComponent";
						range[] = {16000,8000,4000,2000};
						resource = "RscCustomInfoSensors";
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightDriver
			{
				defaultDisplay = "SensorDisplay";
				class Components: components
				{
					class SensorDisplay
					{
						componentType = "SensorsDisplayComponent";
						range[] = {16000,8000,4000,2000};
						resource = "RscCustomInfoSensors";
					};
				};
			};
		};
		enableGPS = 1;
		enableRadio = 1;
		class TransportItems
		{
			class _xx_FirstAidKit
			{
				name = "FirstAidKit";
				count = 20;
			};
			class _xx_medikit
			{
				name = "medikit";
				count = 2;
			};
		};

		// Handling: first pass between the HAFM Buyan and MEKO sets for 1,640 t and 22 kn (40 km/h). Tune in game.
		simulation = "shipx";
		precision = 100;
		brakeDistance = 20;
		steerAheadSimul = 0.5;
		steerAheadPlan = 0.35;
		predictTurnPlan = 0.8;
		predictTurnSimul = 0.6;
		acceleration = 1;
		turnCoef = 500;
		maxSpeed = 41;
		thrustDelay = 2;
		overSpeedBrakeCoef = 0.6;
		enginePower = 260000;
		engineShiftY = 2.0;
		waterLeakiness = 600;
		waterLinearDampingCoefY = 5;
		waterLinearDampingCoefX = 2;
		waterAngularDampingCoef = 3;
		waterResistanceCoef = 0.05;
		rudderForceCoef = 30;
		rudderForceCoefAtMaxSpeed = 6;
		idleRpm = 300;
		redRpm = 3000;
		class complexGearbox
		{
			GearboxRatios[] = {"R1",-0.782,"N",0,"D1",2.0,"D2",1.85,"D3",1.75};
			TransmissionRatios[] = {"High",1.0};
			gearBoxMode = "auto";
			moveOffGear = 1;
			driveString = "D";
			neutralString = "N";
			reverseString = "R";
		};
		class Exhausts
		{
			class Exhaust1
			{
				position = "exhaust_01";
				direction = "exhaust_01_dir";
				effect = "ExhaustsEffectBig";
			};
			class Exhaust2: Exhaust1
			{
				position = "exhaust_02";
				direction = "exhaust_02_dir";
			};
			class Exhaust3: Exhaust1
			{
				position = "exhaust_03";
				direction = "exhaust_03_dir";
			};
		};
		leftEngineEffect = "LEngEffectsSmall";
		rightEngineEffect = "REngEffectsSmall";
		memoryPointsLeftWaterEffect = "waterEffectL";
		memoryPointsRightWaterEffect = "waterEffectR";
		leftFastWaterEffect = "LFastWaterEffects";
		rightFastWaterEffect = "RFastWaterEffects";
		waterEffectSpeed = 3;
		engineEffectSpeed = 3;
		weapons[] = {"adfrc_arafura_horn"};      // driver
		magazines[] = {};

		class ViewPilot: ViewPilot
		{
			initAngleX = -5;
		};

		class Turrets: Turrets
		{
			// Main gun, remote operated from the port bridge chair. Turret path [0].
			class MainTurret: NewTurret
			{
				gunnerCompartments = "Compartment1";
				LODTurnedIn = 1100;
				LODTurnedOut = 1100;
				ARA_SENSOR_PANELS(VehicleSystemsTemplateLeftGunner,VehicleSystemsTemplateRightGunner)
				body = "MainTurret";
				gun = "MainGun";
				animationSourceBody = "mainTurret";
				animationSourceGun = "mainGun";
				proxyIndex = 1;
				primaryGunner = 1;
				commanding = 1;
				gunnerName = "Gunner (25mm)";
				gunnerAction = "passenger_generic01_foldhands";
				gunnerInAction = "passenger_generic01_foldhands";
				forceHideGunner = 1;
				hideProxyInCombat = 0;
				viewGunnerInExternal = 1;
				gunnerForceOptics = 0;
				gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
				memoryPointGunnerOptics = "gunnerview";
				memoryPointGun = "usti hlavne";
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				selectionFireAnim = "zasleh";
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				weapons[] = {"adfrc_typhoon_m242"};
				magazines[] = {"adfrc_typhoon_165rnd_25mm_HE","adfrc_typhoon_165rnd_25mm_HE","adfrc_typhoon_165rnd_25mm_HE","adfrc_aslav_m242_120rnd_25mm_AP"};
				// Rafael Typhoon: -20 / +70
				minElev = -20;
				maxElev = 70;
				initElev = 0;
				// clear of the bridge: 150 deg each side
				minTurn = -150;
				maxTurn = 150;
				initTurn = 0;
				maxHorizontalRotSpeed = 1.5;
				maxVerticalRotSpeed = 1.5;
				stabilizedInAxes = 3;
				startEngine = 0;
				outGunnerMayFire = 1;
				inGunnerMayFire = 1;
				class HitPoints {};
				class GunParticles
				{
					class effect1
					{
						positionName = "usti hlavne";
						directionName = "konec hlavne";
						effectName = "AutoCannonFired";
					};
				};
				class ViewOptics: ViewOptics
				{
					initAngleX = 0; minAngleX = -30; maxAngleX = 30;
					initAngleY = 0; minAngleY = -100; maxAngleY = 100;
					initFov = 0.3; minFov = 0.05; maxFov = 0.5;
					visionMode[] = {"Normal","NVG","Ti"};
					thermalMode[] = {0,1,2,3,4,5,6};
				};
			};
			// Port 12.7 mm on the bridge wing. Same gunner rig as the Fremantle / adfrc_lrpv M2.
			class PortM2Turret: NewTurret
			{
				gunnerCompartments = "Compartment1";
				LODTurnedIn = 1100;
				LODTurnedOut = 1100;
				body = "PortTurret";
				gun = "PortGun";
				animationSourceBody = "portTurret";
				animationSourceGun = "portGun";
				proxyIndex = 2;
				primaryGunner = 0;
				commanding = 0;
				gunnerType = "ADFRC_MD_RAN_Coxswain";
				gunnerName = "Port Gunner";
				gunnerAction = "adfrc_lrpv_gunner_m2";
				gunnerInAction = "adfrc_lrpv_gunner_m2";
				gunnerLeftHandAnimName = "m2_2_hand_l";
				gunnerRightHandAnimName = "m2_2_hand_r";
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				memoryPointsGetInGunner = "pos gunner_2";
				memoryPointsGetInGunnerDir = "pos gunner_2 dir";
				memoryPointGun = "machinegun_2";
				memoryPointGunnerOptics = "gunnerview_2";
				gunBeg = "usti hlavne_2";
				gunEnd = "konec hlavne_2";
				selectionFireAnim = "zasleh_2";
				gunnerOpticsModel = "\A3\weapons_f\reticle\optics_empty";
				weapons[] = {"adfrc_ship_M2HB"};
				magazines[] = {"adfrc_ship_100Rnd_127x99_tracer_red","adfrc_ship_100Rnd_127x99_tracer_red","adfrc_ship_100Rnd_127x99_tracer_red","adfrc_ship_100Rnd_127x99_tracer_red","adfrc_ship_100Rnd_127x99_tracer_red","adfrc_ship_100Rnd_127x99_tracer_red"};
				minElev = -15;
				maxElev = 45;
				minTurn = 0;
				maxTurn = 180;      // 12 to 6 o'clock, port side (positive = to port)
				initTurn = 0;
				outGunnerMayFire = 1;
				inGunnerMayFire = 1;
				gunnerForceOptics = 0;
				castGunnerShadow = 1;
				startEngine = 0;
				stabilizedInAxes = 0;
				class HitPoints {};
				class GunParticles
				{
					class effect1
					{
						positionName = "usti hlavne_2";
						directionName = "konec hlavne_2";
						effectName = "MachineGunCloud";
					};
					class effect2
					{
						positionName = "nabojnicestart_2";
						directionName = "nabojniceend_2";
						effectName = "MachineGunEject";
					};
				};
				class ViewOptics: ViewOptics
				{
					initAngleX = 0; minAngleX = -30; maxAngleX = 30;
					initAngleY = 0; minAngleY = -100; maxAngleY = 100;
					initFov = 0.75; minFov = 0.25; maxFov = 1.1;
				};
			};
			class StbdM2Turret: PortM2Turret
			{
				body = "StbdTurret";
				gun = "StbdGun";
				animationSourceBody = "stbdTurret";
				animationSourceGun = "stbdGun";
				proxyIndex = 3;
				gunnerName = "Starboard Gunner";
				memoryPointsGetInGunner = "pos gunner_3";
				memoryPointsGetInGunnerDir = "pos gunner_3 dir";
				minTurn = -180;     // 12 to 6 o'clock, starboard side
				maxTurn = 0;
				gunnerLeftHandAnimName = "m2_3_hand_l";
				gunnerRightHandAnimName = "m2_3_hand_r";
				memoryPointGun = "machinegun_3";
				memoryPointGunnerOptics = "gunnerview_3";
				gunBeg = "usti hlavne_3";
				gunEnd = "konec hlavne_3";
				selectionFireAnim = "zasleh_3";
				class GunParticles
				{
					class effect1
					{
						positionName = "usti hlavne_3";
						directionName = "konec hlavne_3";
						effectName = "MachineGunCloud";
					};
					class effect2
					{
						positionName = "nabojnicestart_3";
						directionName = "nabojniceend_3";
						effectName = "MachineGunEject";
					};
				};
			};
			// Captain: starboard bridge chair. Turret path [3]. Fires the anti-ship missiles; the optics view is
			// an invisible camera (asm_cam) on the front of the mast platform that can traverse and look/lock targets.
			class CaptainTurret: NewTurret
			{
				gunnerCompartments = "Compartment1";
				LODTurnedIn = 1100;
				LODTurnedOut = 1100;
				ARA_SENSOR_PANELS(VehicleSystemsTemplateLeftCommander,VehicleSystemsTemplateRightCommander)
				body = "CmdTurret";
				gun = "CmdGun";
				animationSourceBody = "cmdTurret";
				animationSourceGun = "cmdGun";
				proxyIndex = 4;
				primaryGunner = 0;
				primaryObserver = 1;
				commanding = 2;
				gunnerName = "Captain (ASM)";
				gunnerAction = "passenger_generic01_foldhands";
				gunnerInAction = "passenger_generic01_foldhands";
				forceHideGunner = 1;
				hideProxyInCombat = 0;
				viewGunnerInExternal = 1;
				gunnerForceOptics = 0;
				gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Commander_02_F";
				memoryPointGunnerOptics = "asm_cam";
				memoryPointGun = "asm_cam";
				gunBeg = "asm_cam";
				gunEnd = "asm_cam_end";
				missileBeg = "asm_tube_1";
				missileEnd = "asm_tube_1_end";
				memoryPointsGetInGunner = "pos commander";
				memoryPointsGetInGunnerDir = "pos commander dir";
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				weapons[] = {"adfrc_asm_launcher"};
				magazines[] = {"adfrc_asm_4Rnd"};
				minElev = -25;
				maxElev = 30;
				initElev = 0;
				minTurn = -360;
				maxTurn = 360;
				initTurn = 0;
				maxHorizontalRotSpeed = 2;
				maxVerticalRotSpeed = 2;
				stabilizedInAxes = 3;
				isPersonTurret = 0;
				startEngine = 0;
				outGunnerMayFire = 1;
				inGunnerMayFire = 1;
				turretInfoType = "RscOptics_crows";
				class HitPoints {};
				class ViewOptics: ViewOptics
				{
					initAngleX = 0; minAngleX = -30; maxAngleX = 30;
					initAngleY = 0; minAngleY = -100; maxAngleY = 100;
					initFov = 0.5; minFov = 0.02; maxFov = 0.75;
					visionMode[] = {"Normal","NVG","Ti"};
					thermalMode[] = {0,1};
				};
			};
		};
		// Navigation lights (first placement; positions are memory points, move them in Object Builder or a lights blend).
		class MarkerLights
		{
			class light_side_p
			{
				name = "light_side_p";
				color[] = {0.8,0.0,0.0};
				ambient[] = {0.08,0.0,0.0};
				intensity = 112.5;
				drawLight = 1;
				drawLightSize = 0.25;
				drawLightCenterSize = 0.06;
				activeLight = 0;
				blinking = 0;
				dayLight = 0;
				useFlare = 0;
				class Attenuation
				{
					start = 0;
					constant = 0;
					linear = 25;
					quadratic = 50;
					hardLimitStart = 0.75;
					hardLimitEnd = 1;
				};
			};
			class light_side_s: light_side_p
			{
				name = "light_side_s";
				color[] = {0.0,0.8,0.0};
				ambient[] = {0.0,0.08,0.0};
			};
			class light_mast_01: light_side_p
			{
				name = "light_mast_01";
				color[] = {1.0,1.0,0.95};
				ambient[] = {0.1,0.1,0.1};
			};
			class light_mast_02: light_mast_01
			{
				name = "light_mast_02";
			};
			class light_stern: light_mast_01
			{
				name = "light_stern";
			};
		};
		// Headlights: two floods over the foredeck from the bridge front, two over the flight deck from the funnel.
		class Reflectors
		{
			class light_flood_01
			{
				color[] = {1900,1800,1700};
				ambient[] = {5,5,5};
				position = "light_flood_01";
				direction = "light_flood_01_dir";
				hitpoint = "light_flood_01";
				selection = "light_flood_01";
				size = 1;
				innerAngle = 40;
				outerAngle = 110;
				coneFadeCoef = 10;
				intensity = 1.5;
				useFlare = 1;
				flareSize = 1;
				dayLight = 0;
				class Attenuation
				{
					start = 1;
					constant = 0;
					linear = 0;
					quadratic = 0.25;
					hardLimitStart = 40;
					hardLimitEnd = 70;
				};
			};
			class light_flood_02: light_flood_01
			{
				position = "light_flood_02";
				direction = "light_flood_02_dir";
				hitpoint = "light_flood_02";
				selection = "light_flood_02";
			};
			class light_flood_03: light_flood_01
			{
				position = "light_flood_03";
				direction = "light_flood_03_dir";
				hitpoint = "light_flood_03";
				selection = "light_flood_03";
			};
			class light_flood_04: light_flood_01
			{
				position = "light_flood_04";
				direction = "light_flood_04_dir";
				hitpoint = "light_flood_04";
				selection = "light_flood_04";
			};
		};
		class AnimationSources
		{
			class rhib_p_deployed
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class rhib_s_deployed: rhib_p_deployed {};
			// Garage / Eden option, on = containers hidden (default)
			class hide_containers
			{
				displayName = "Hide mission bay containers";
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class stern_door
			{
				source = "user";
				animPeriod = 8;
				initPhase = 0;
				sound = "ServoRampSound_2";
			};
		};
		class UserActions
		{
			// Ladders: vehicles don't support real ladders, so climb = move to the other end
			class ladder_1_up
			{
				displayName = "Climb ladder up";
				position = "ladder_1_bottom";
				radius = 1.8;
				priority = 2;
				onlyForPlayer = 1;
				showWindow = 0;
				condition = "vehicle player == player";
				statement = "[this, player, 'ladder_1_top'] call adfrc_arafura_fnc_ladder";
			};
			class ladder_1_down: ladder_1_up
			{
				displayName = "Climb ladder down";
				position = "ladder_1_top";
				statement = "[this, player, 'ladder_1_bottom'] call adfrc_arafura_fnc_ladder";
			};
			class ladder_2_up: ladder_1_up
			{
				position = "ladder_2_bottom";
				statement = "[this, player, 'ladder_2_top'] call adfrc_arafura_fnc_ladder";
			};
			class ladder_2_down: ladder_1_down
			{
				position = "ladder_2_top";
				statement = "[this, player, 'ladder_2_bottom'] call adfrc_arafura_fnc_ladder";
			};
			// Past the port davit RHIB, which blocks the side deck
			class move_astern_p: ladder_1_up
			{
				displayName = "Move astern";
				position = "pass_p_fore";
				statement = "[this, player, 'pass_p_aft'] call adfrc_arafura_fnc_ladder";
			};
			class move_fore_p: ladder_1_up
			{
				displayName = "Move fore";
				position = "pass_p_aft";
				statement = "[this, player, 'pass_p_fore'] call adfrc_arafura_fnc_ladder";
			};
			class ladder_4_up: ladder_1_up
			{
				position = "ladder_4_bottom";
				statement = "[this, player, 'ladder_4_top'] call adfrc_arafura_fnc_ladder";
			};
			class ladder_4_down: ladder_1_down
			{
				position = "ladder_4_top";
				statement = "[this, player, 'ladder_4_bottom'] call adfrc_arafura_fnc_ladder";
			};
			class ladder_5_up: ladder_1_up
			{
				position = "ladder_5_bottom";
				statement = "[this, player, 'ladder_5_top'] call adfrc_arafura_fnc_ladder";
			};
			class ladder_5_down: ladder_1_down
			{
				position = "ladder_5_top";
				statement = "[this, player, 'ladder_5_bottom'] call adfrc_arafura_fnc_ladder";
			};
			class ladder_6_up: ladder_1_up
			{
				position = "ladder_6_bottom";
				statement = "[this, player, 'ladder_6_top'] call adfrc_arafura_fnc_ladder";
			};
			class ladder_6_down: ladder_1_down
			{
				position = "ladder_6_top";
				statement = "[this, player, 'ladder_6_bottom'] call adfrc_arafura_fnc_ladder";
			};
			class ladder_7_up: ladder_1_up
			{
				position = "ladder_7_bottom";
				statement = "[this, player, 'ladder_7_top'] call adfrc_arafura_fnc_ladder";
			};
			class ladder_7_down: ladder_1_down
			{
				position = "ladder_7_top";
				statement = "[this, player, 'ladder_7_bottom'] call adfrc_arafura_fnc_ladder";
			};
			// Davit RHIBs: driver or captain only
			class deploy_rhib_p
			{
				displayName = "Deploy port RHIB";
				position = "driverview";
				radius = 15;
				priority = 0.5;
				onlyForPlayer = 1;
				showWindow = 0;
				condition = "(driver this == player || {(this turretUnit [3]) == player}) && {this animationSourcePhase 'rhib_p_deployed' < 0.5}";
				statement = "[this, 'p', 'deploy'] call adfrc_arafura_fnc_rhib";
			};
			class recover_rhib_p: deploy_rhib_p
			{
				displayName = "Recover port RHIB";
				condition = "(driver this == player || {(this turretUnit [3]) == player}) && {this animationSourcePhase 'rhib_p_deployed' > 0.5}";
				statement = "[this, 'p', 'recover'] call adfrc_arafura_fnc_rhib";
			};
			class deploy_rhib_s: deploy_rhib_p
			{
				displayName = "Deploy starboard RHIB";
				condition = "(driver this == player || {(this turretUnit [3]) == player}) && {this animationSourcePhase 'rhib_s_deployed' < 0.5}";
				statement = "[this, 's', 'deploy'] call adfrc_arafura_fnc_rhib";
			};
			// Stern door (mission bay ramp): driver or captain only
			class open_stern_door: deploy_rhib_p
			{
				displayName = "Lower stern door";
				condition = "(driver this == player || {(this turretUnit [3]) == player}) && {this animationSourcePhase 'stern_door' < 0.5}";
				statement = "this animateSource ['stern_door', 1]";
			};
			class close_stern_door: open_stern_door
			{
				displayName = "Raise stern door";
				condition = "(driver this == player || {(this turretUnit [3]) == player}) && {this animationSourcePhase 'stern_door' > 0.5}";
				statement = "this animateSource ['stern_door', 0]";
			};
			class recover_rhib_s: deploy_rhib_p
			{
				displayName = "Recover starboard RHIB";
				condition = "(driver this == player || {(this turretUnit [3]) == player}) && {this animationSourcePhase 'rhib_s_deployed' > 0.5}";
				statement = "[this, 's', 'recover'] call adfrc_arafura_fnc_rhib";
			};
		};
		// Death sequence (adfrc_fremantle_fnc_sinkFx). Existing memory points; offsets are
		// model space [x,y,z], z up, from the point. Delays in seconds after death.
		class adfrc_sinkFx
		{
			// {memPoint, {offset}, ammo, delay}
			explosions[] = {
				{"engineeffectl", {0,0,4.5}, "adfrc_ship_explosion_big", 0.3},
				{"pos commander", {0,0,-3.5}, "adfrc_ship_explosion_big", 1.2},
				{"pos driver", {0,0,-3.5}, "adfrc_ship_explosion_medium", 2.0},
				{"watereffectr", {0,0,1.5}, "adfrc_ship_explosion_big", 3.2}
			};
			// {memPoint, {offset}, "big"|"medium"|"small", delay}
			fires[] = {
				{"adfrc_board_pos", {0,0,0}, "big", 1.0},
				{"pos commander", {0,0,0}, "medium", 1.8},
				{"pass_p_fore", {0,0,0}, "medium", 2.5},
				{"pass_p_aft", {0,0,0}, "small", 3.0},
				{"exhaust_02", {0,0,-3}, "medium", 4.0},
				{"exhaust_01", {0,0,0}, "medium", 3.4},
				{"exhaust_03", {0,0,0}, "medium", 3.7},
				{"ladder_1_bottom", {0,0,0}, "small", 4.5},
				{"driverview", {0,0,0}, "big", 8.0}
			};
			extinguishHeight = 0.3;
			burnTime = 600;
			sinkAssist = 0;
			sinkMassMult = 3;
			sinkTime = 120;
			sinkTowards = "engineeffectl";
			sinkBias = 0.3;
		};
		class VehicleTransport
		{
			class Cargo
			{
				canBeTransported = 0;
			};
		};
	};
	class adfrc_arafura: adfrc_arafura_base
	{
		editorPreview = "\ADF_Boat\adfrc_arafura\data\editorPreviews\adfrc_arafura.jpg";
		author = "ADFRC";
		displayName = "Arafura-class OPV";
		scope = 2;
		scopeCurator = 2;
		crew = "ADFRC_MD_RAN_OOW";
		faction = "ADFRC_F_MD";
		side = 1;
		typicalCargo[] = {"ADFRC_MD_RAN_OOW"};
	};
};
