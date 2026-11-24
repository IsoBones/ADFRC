class CfgPatches
{
	class adfrc_fremantle
	{
		addonRootClass = "A3_Boat_F";
		requiredAddons[] = {"A3_Boat_F","A3_Weapons_F","A3_Data_F_Mod_Loadorder","cba_main","cba_xeh","ADF_Core","ADF_Units","adfrc_abrams","adfrc_lrpv","adfrc_lcm"};
		requiredVersion = 0.1;
		units[] = {"adfrc_fremantle"};
		weapons[] = {"adfrc_bofors_l60","adfrc_fremantle_horn"};
	};
};

class CfgFunctions
{
	// Tag = first-level class, so functions compile as adfrc_fremantle_fnc_*
	class adfrc_fremantle
	{
		class AssaultBoat
		{
			file = "ADF_Boat\adfrc_fremantle\functions";
			class assaultBoat {};
			class boatInit {};
			class ladder {};
		};
	};
};

// XEH must live at config root, keyed by the leaf vehicle class.
class Extended_Init_EventHandlers
{
	class adfrc_fremantle
	{
		class adfrc_fremantle_board
		{
			init = "(_this select 0) call adfrc_fremantle_fnc_boatInit";
		};
	};
};

class CfgAmmo
{
	class B_40mm_GPR_Tracer_Red;
	// lockable (air + ground) so the FCS can compute lead on radar-locked targets
	class adfrc_bofors_40mm_HE: B_40mm_GPR_Tracer_Red
	{
		airLock = 1;
		canLock = 2;
	};
};

class CfgMagazines
{
	class 60Rnd_40mm_GPR_Tracer_Red_shells;
	class adfrc_bofors_60Rnd_40mm_HE: 60Rnd_40mm_GPR_Tracer_Red_shells
	{
		displayName = "40mm HE-T (Bofors)";
		ammo = "adfrc_bofors_40mm_HE";
	};
};

class CfgWeapons
{
	class CarHorn;
	// Driver's "weapon": ship horn (sound from the HAFM Navy pack, sounds\fremantle_horn.ogg).
	// reloadTime = clip length so a held trigger doesn't stack blasts.
	class adfrc_fremantle_horn: CarHorn
	{
		displayName = "Ship Horn";
		drySound[] = {"ADF_Boat\adfrc_fremantle\sounds\fremantle_horn.ogg",3.1622777,1,2000};
		reloadTime = 2.4;
	};
	class autocannon_Base_F;
	class autocannon_40mm_CTWS: autocannon_Base_F
	{
		class HE;
	};
	// Stop-gap Bofors: vanilla 40mm CTWS HE muzzle only, GPR tracer belts.
	class adfrc_bofors_l60: autocannon_40mm_CTWS
	{
		displayName = "Bofors 40mm L/60";
		muzzles[] = {"HE"};
		// Fire control: lock a radar target and the sight shows where to lead
		// (same setup as the adfrc_boxer coax by Quiggs). FCSMaxLeadSpeed in m/s, tune if needed.
		canLock = 2;
		weaponLockSystem = 2;
		weaponLockDelay = 2;
		class HE: HE
		{
			displayName = "Bofors 40mm L/60";
			magazines[] = {"adfrc_bofors_60Rnd_40mm_HE","60Rnd_40mm_GPR_Tracer_Red_shells"};
			canLock = 2;
			ballisticsComputer = "1 + 2 + 16";
			FCSMaxLeadSpeed = 200;
			weaponLockSystem = 2;
			weaponLockDelay = 2;
		};
	};
};

// Vanilla sensor + panel templates (defined at config root by A3 data_f), declared exactly as BI does
class SensorTemplateActiveRadar;
class SensorTemplateDataLink;
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

class CfgVehicles
{
	class Ship_F;
	class Boat_F: Ship_F
	{
		class NewTurret;
		class CargoTurret;
		class Turrets;
		class ViewPilot;
		class ViewOptics;
	};
	class adfrc_fremantle_base: Boat_F
	{
		author = "ADFRC";
		model = "\ADF_Boat\adfrc_fremantle\adfrc_fremantle.p3d";
		mapSize = 42;
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
		extCameraPosition[] = {0,4,-45};
		memoryPointTaskMarker = "TaskMarker_1_pos";
		crewVulnerable = 0;
		attenuationEffectType = "OpenCarAttenuation";
		insideSoundCoef = 0;
		soundEngineOnInt[] = {"a3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-ext-start-02",0.56234133,0.72};
		soundEngineOnExt[] = {"a3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-ext-start-02",0.56234133,0.72,200};
		soundEngineOffInt[] = {"a3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-ext-stop-02",0.56234133,0.72};
		soundEngineOffExt[] = {"a3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-ext-stop-02",0.56234133,0.72,200};
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
		class Sounds
		{
			class IdleOut
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-idle-2",0.5011872,1.0,300};
				frequency = "0.72 * (0.95	+	((rpm/	1200) factor[(100/	1200),(300/	1200)])*0.15)";
				volume = "engineOn*(((rpm/	1200) factor[(0/	1200),(30/	1200)])	*	((rpm/	1200) factor[(500/	1200),(300/	1200)]))";
			};
			class Engine
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-low-2",0.63095737,1.0,450};
				frequency = "0.72 * (0.95	+	((rpm/	1200) factor[(300/	1200),(600/	1200)])*0.2)";
				volume = "engineOn*(((rpm/	1200) factor[(150/	1200),(250/	1200)])	*	((rpm/	1200) factor[(600/	1200),(400/	1200)]))";
			};
			class EngineMidOut
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-mid-2",0.7943282,1.0,500};
				frequency = "0.72 * (0.95	+		((rpm/	1200) factor[(600/	1200),(900/	1200)])*0.2)";
				volume = "engineOn*(((rpm/	1200) factor[(350/	1200),(500/	1200)])	*	((rpm/	1200) factor[(1000/	1200),(700/	1200)]))";
			};
			class EngineMaxOut
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-high-2",1.0,1.0,600};
				frequency = "0.72 * (0.95	+	((rpm/	1200) factor[(700/	1200),(1000/	1200)])*0.2)";
				volume = "engineOn*((rpm/	1200) factor[(800/	1200),(1200/	1200)])";
			};
			class WaternoiseOutW0
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-0-speed1",0.70794576,1.0,150};
				frequency = "1";
				volume = "(speed factor[4, 1]) * water";
			};
			class WaternoiseOutW1
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-20-speed",0.7943282,1.0,250};
				frequency = "1";
				volume = "((speed factor[2, 6]) min (speed factor[6, 4]))";
			};
			class WaternoiseOutW2
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-50-speed",1.0,1.0,350};
				frequency = "1";
				volume = "(speed factor[3, 9])";
			};
			class WaternoiseOutW3
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-0-speed1",0.70794576,1.0,150};
				frequency = "1";
				volume = "(speed factor[-4, -1]) * water";
			};
			class WaternoiseOutW4
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-20-speed",0.7943282,0.9,250};
				frequency = "1";
				volume = "((speed factor[-2, -6]) min (speed factor[-6, -4]))";
			};
			class WaternoiseOutW5
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-50-speed",1.0,0.9,350};
				frequency = "1";
				volume = "(speed factor[-3, -9])";
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
		armor = 200;
		armorStructural = 4;
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
				armor = 0.7;
				material = -1;
				name = "engine";
				visual = "";
				passThrough = 0.3;
				minimalHit = 0.1;
				explosionShielding = 0.5;
				radius = 0.6;
			};
			class HitFuel
			{
				armor = 0.6;
				material = -1;
				name = "fuel";
				visual = "";
				passThrough = 0.3;
				minimalHit = 0.1;
				explosionShielding = 0.6;
				radius = 0.6;
			};
		};

		// Driver: seated at the wheelhouse helm chair, or the port conning seat.
		// Boats don't offer engine turn in/out, so the move is a scroll action
		// (UserActions) animating the user source driver_conning, which
		// translates the driver proxy in model.cfg.
		driverAction = "driver_mid01";
		driverInAction = "driver_mid01";
		forceHideDriver = 1;
		driverForceOptics = 0;
		hideProxyInCombat = 0;
		LODDriverTurnedIn = 1100;
		LODDriverTurnedOut = 1100;
		viewDriverInExternal = 1;
		memoryPointsGetInDriver = "pos driver";       // 01 deck, port side aft of the wheelhouse
		memoryPointsGetInDriverDir = "pos driver dir";
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		castDriverShadow = 1;

		// Passenger cabin on the main deck below/aft of the bridge: 3 tables of 4, seated (cargo proxies 1-12).
		// Get in/out at the starboard cabin door ("pos cargo", main deck).
		// Deck positions are named cargo turrets (cargo proxies 13-20, see Turrets).
		cargoAction[] = {"passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands","passenger_generic01_foldhands"};
		cargoProxyIndexes[] = {1,2,3,4,5,6,7,8,9,10,11,12};
		transportSoldier = 12;
		memoryPointsGetInCargo = "pos cargo";
		memoryPointsGetInCargoDir = "pos cargo dir";
		// Crew (driver, Bofors, M2s, captain) = Compartment1, passengers (cabin + deck) = Compartment2:
		// "Move to" seat switching only works inside a compartment, so crew and pax can't swap.
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment2"};
		// Active radar (surface + air search) shared over datalink; sensor panels for the crew.
		radarTarget = 1;
		radarTargetSize = 1.5;
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
							minRange = 8000;
							maxRange = 8000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						class GroundTarget
						{
							minRange = 8000;
							maxRange = 8000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						typeRecognitionDistance = 4000;
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
								range[] = {8000,4000,2000,1000};
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
								range[] = {8000,4000,2000,1000};
								resource = "RscCustomInfoSensors";
							};
				};
			};
		};
		cargoGetInAction[] = {"GetInLow"};
		cargoGetOutAction[] = {"GetOutLow"};
		castCargoShadow = 1;
		enableGPS = 1;
		enableRadio = 1;
		class TransportItems
		{
			class _xx_FirstAidKit
			{
				name = "FirstAidKit";
				count = 10;
			};
			class _xx_medikit
			{
				name = "medikit";
				count = 1;
			};
		};

		// Handling: HAFM GunBoat (43 m / 350 t, known drivable) scaled to 220 t and 30 kn.
		simulation = "shipx";
		precision = 50;
		brakeDistance = 10;
		steerAheadSimul = 0.5;
		steerAheadPlan = 0.35;
		predictTurnPlan = 0.8;
		predictTurnSimul = 0.6;
		acceleration = 1;
		turnCoef = 4;
		maxSpeed = 56;
		thrustDelay = 1;
		overSpeedBrakeCoef = 0.2;
		enginePower = 44000;
		engineShiftY = 0.1;
		waterLeakiness = 150;
		waterLinearDampingCoefY = 5;
		waterLinearDampingCoefX = 2;
		waterAngularDampingCoef = 1.2;
		waterResistanceCoef = 0.05;
		rudderForceCoef = 2;
		rudderForceCoefAtMaxSpeed = 0.5;
		idleRpm = 200;
		redRpm = 3500;
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
		};
		leftEngineEffect = "LEngEffectsSmall";
		rightEngineEffect = "REngEffectsSmall";
		leftFastWaterEffect = "LFastWaterEffects";
		rightFastWaterEffect = "RFastWaterEffects";
		waterEffectSpeed = 3;
		engineEffectSpeed = 3;
		waterFastEffectSpeed = 25;
		weapons[] = {"adfrc_fremantle_horn"};      // driver
		magazines[] = {};

		class ViewPilot: ViewPilot
		{
			initAngleX = -5;
		};

		class Turrets: Turrets
		{
			// Bofors 40/60, enclosed gunhouse: gunner always inside, sight view only.
			class BoforsTurret: NewTurret
			{
				gunnerCompartments = "Compartment1";
				class Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftGunner
					{
						class Components: components
						{
							class SensorDisplay
								{
									componentType = "SensorsDisplayComponent";
									range[] = {8000,4000,2000,1000};
									resource = "RscCustomInfoSensors";
								};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightGunner
					{
						defaultDisplay = "SensorDisplay";
						class Components: components
						{
							class SensorDisplay
								{
									componentType = "SensorsDisplayComponent";
									range[] = {8000,4000,2000,1000};
									resource = "RscCustomInfoSensors";
								};
						};
					};
				};
				body = "MainTurret";
				gun = "MainGun";
				animationSourceBody = "mainTurret";
				animationSourceGun = "mainGun";
				proxyIndex = 1;
				primaryGunner = 1;
				commanding = 1;
				gunnerName = "Bofors Gunner";
				// Seated in the wheelhouse (third chair), normal first person;
				// right click goes to the gun sight on the mount.
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
				memoryPointsGetInGunner = "pos bofors";
				memoryPointsGetInGunnerDir = "pos bofors dir";
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				weapons[] = {"adfrc_bofors_l60"};
				magazines[] = {"adfrc_bofors_60Rnd_40mm_HE","adfrc_bofors_60Rnd_40mm_HE","adfrc_bofors_60Rnd_40mm_HE","adfrc_bofors_60Rnd_40mm_HE"};
				minElev = -5;
				maxElev = 60;
				initElev = 0;
				minTurn = -150;
				maxTurn = 150;
				initTurn = 0;
				stabilizedInAxes = 0;
				startEngine = 0;
				outGunnerMayFire = 1;
				inGunnerMayFire = 1;
				LODTurnedIn = 1100;
				LODTurnedOut = 1100;
				class HitPoints {};
				class GunParticles
				{
					class effect1
					{
						positionName = "usti hlavne";
						directionName = "konec hlavne";
						effectName = "MachineGunCloud";
					};
				};
				class ViewOptics: ViewOptics
				{
					initAngleX = 0; minAngleX = -30; maxAngleX = 30;
					initAngleY = 0; minAngleY = -100; maxAngleY = 100;
					initFov = 0.3; minFov = 0.1; maxFov = 0.5;
					visionMode[] = {"Normal","NVG","Ti"};
					thermalMode[] = {0,1,2,3,4,5,6};
				};
			};
			// Port M2 on the 01 deck. Same gunner rig as the adfrc_lrpv rear M2
			// (adfrc_lrpv_gunner_m2 + hand IK memory points).
			class PortM2Turret: NewTurret
			{
				gunnerCompartments = "Compartment1";
				body = "PortTurret";
				gun = "PortGun";
				animationSourceBody = "portTurret";
				animationSourceGun = "portGun";
				proxyIndex = 2;
				primaryGunner = 0;
				commanding = 0;
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
				weapons[] = {"ADFRC_abrams_M2HBQCB"};
				magazines[] = {"100rnd_127x99_mag_Tracer_Red","100rnd_127x99_mag_Tracer_Red","100rnd_127x99_mag_Tracer_Red","100rnd_127x99_mag_Tracer_Red","100rnd_127x99_mag_Tracer_Red","100rnd_127x99_mag_Tracer_Red"};
				minElev = -15;
				maxElev = 45;
				// 12 o'clock round to 8 o'clock on the port side (positive = to port)
				minTurn = 0;
				maxTurn = 180;      // 12 to 6 o'clock, port side
				initTurn = 0;
				outGunnerMayFire = 1;
				inGunnerMayFire = 1;
				gunnerForceOptics = 0;
				castGunnerShadow = 1;
				startEngine = 0;
				stabilizedInAxes = 0;
				LODTurnedIn = 1000;
				LODTurnedOut = 1000;
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
				// 12 o'clock round to 4 o'clock on the starboard side
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
			// Captain: seated at the wheelhouse chair, or the starboard conning seat.
			// Moved by scroll action (user source captain_conning). Turret path [3].
			class CaptainTurret: NewTurret
			{
				gunnerCompartments = "Compartment1";
				class Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftCommander
					{
						class Components: components
						{
							class SensorDisplay
								{
									componentType = "SensorsDisplayComponent";
									range[] = {8000,4000,2000,1000};
									resource = "RscCustomInfoSensors";
								};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightCommander
					{
						defaultDisplay = "SensorDisplay";
						class Components: components
						{
							class SensorDisplay
								{
									componentType = "SensorsDisplayComponent";
									range[] = {8000,4000,2000,1000};
									resource = "RscCustomInfoSensors";
								};
						};
					};
				};
				body = "";
				gun = "";
				animationSourceBody = "";
				animationSourceGun = "";
				proxyIndex = 4;
				primaryGunner = 0;
				primaryObserver = 1;
				commanding = 2;
				gunnerName = "Captain";
				gunnerAction = "passenger_generic01_foldhands";
				gunnerInAction = "passenger_generic01_foldhands";
				forceHideGunner = 1;
				hideProxyInCombat = 0;
				viewGunnerInExternal = 1;
				gunnerForceOptics = 0;
				gunnerOpticsModel = "";
				memoryPointGunnerOptics = "commanderview";
				memoryPointsGetInGunner = "pos commander";
				memoryPointsGetInGunnerDir = "pos commander dir";
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				weapons[] = {};
				magazines[] = {};
				minElev = 0;
				maxElev = 0;
				initElev = 0;
				minTurn = 0;
				maxTurn = 0;
				initTurn = 0;
				isPersonTurret = 0;
				startEngine = 0;
				outGunnerMayFire = 0;
				inGunnerMayFire = 0;
				LODTurnedIn = 1100;
				LODTurnedOut = 1100;
				class HitPoints {};
				class ViewOptics: ViewOptics
				{
					initAngleX = 0; minAngleX = -30; maxAngleX = 30;
					initAngleY = 0; minAngleY = -100; maxAngleY = 100;
					initFov = 0.75; minFov = 0.25; maxFov = 1.1;
				};
			};
			// Deck positions 1-4 port (foredeck, then aft deck bow to stern), 5-8 starboard.
			class DeckPosition_1: CargoTurret
			{
				gunnerCompartments = "Compartment2";   // passengers
				gunnerName = "Deck Position 1";
				memoryPointsGetInGunner = "pos deck_1";
				memoryPointsGetInGunnerDir = "pos deck_1 dir";
				gunnerAction = "passenger_boat_holdleft";
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				proxyIndex = 13;
				isPersonTurret = 0;
			};
			class DeckPosition_2: DeckPosition_1
			{
				gunnerName = "Deck Position 2";
				memoryPointsGetInGunner = "pos deck_2";
				memoryPointsGetInGunnerDir = "pos deck_2 dir";
				proxyIndex = 14;
			};
			class DeckPosition_3: DeckPosition_1
			{
				gunnerName = "Deck Position 3";
				memoryPointsGetInGunner = "pos deck_3";
				memoryPointsGetInGunnerDir = "pos deck_3 dir";
				proxyIndex = 15;
			};
			class DeckPosition_4: DeckPosition_1
			{
				gunnerName = "Deck Position 4";
				memoryPointsGetInGunner = "pos deck_4";
				memoryPointsGetInGunnerDir = "pos deck_4 dir";
				proxyIndex = 16;
			};
			class DeckPosition_5: DeckPosition_1
			{
				gunnerName = "Deck Position 5";
				memoryPointsGetInGunner = "pos deck_5";
				memoryPointsGetInGunnerDir = "pos deck_5 dir";
				gunnerAction = "passenger_boat_holdright";
				proxyIndex = 17;
			};
			class DeckPosition_6: DeckPosition_5
			{
				gunnerName = "Deck Position 6";
				memoryPointsGetInGunner = "pos deck_6";
				memoryPointsGetInGunnerDir = "pos deck_6 dir";
				proxyIndex = 18;
			};
			class DeckPosition_7: DeckPosition_5
			{
				gunnerName = "Deck Position 7";
				memoryPointsGetInGunner = "pos deck_7";
				memoryPointsGetInGunnerDir = "pos deck_7 dir";
				proxyIndex = 19;
			};
			class DeckPosition_8: DeckPosition_5
			{
				gunnerName = "Deck Position 8";
				memoryPointsGetInGunner = "pos deck_8";
				memoryPointsGetInGunnerDir = "pos deck_8 dir";
				proxyIndex = 20;
			};
		};
		// Collision lights (360 deg). Point positions come from fremantle_lights.blend (Memory object).
		class MarkerLights
		{
			class collision_red_01
			{
				name = "collision_red_01";
				color[] = {0.8,0.0,0.0};
				ambient[] = {0.08,0.0,0.0};
				intensity = 112.5;       // 1.5x the first pass
				drawLight = 1;
				drawLightSize = 0.15;
				drawLightCenterSize = 0.04;
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
			class collision_red_02: collision_red_01
			{
				name = "collision_red_02";
			};
			class collision_red_03: collision_red_01
			{
				name = "collision_red_03";
			};
			class collision_red_04: collision_red_01
			{
				name = "collision_red_04";
			};
			class collision_red_05: collision_red_01
			{
				name = "collision_red_05";
			};
			class collision_red_06: collision_red_01
			{
				name = "collision_red_06";
			};
			class collision_red_07: collision_red_01
			{
				name = "collision_red_07";
			};
			class collision_red_08: collision_red_01
			{
				name = "collision_red_08";
			};
			class collision_red_09: collision_red_01
			{
				name = "collision_red_09";
			};
			class collision_red_10: collision_red_01
			{
				name = "collision_red_10";
			};
			class collision_red_11: collision_red_01
			{
				name = "collision_red_11";
			};
			class collision_red_12: collision_red_01
			{
				name = "collision_red_12";
			};
			class collision_red_13: collision_red_01
			{
				name = "collision_red_13";
			};
			class collision_red_14: collision_red_01
			{
				name = "collision_red_14";
			};
			class collision_green_01: collision_red_01
			{
				name = "collision_green_01";
				color[] = {0.0,0.8,0.0};
				ambient[] = {0.0,0.08,0.0};
			};
			class collision_green_02: collision_red_01
			{
				name = "collision_green_02";
				color[] = {0.0,0.8,0.0};
				ambient[] = {0.0,0.08,0.0};
			};
			class collision_green_03: collision_red_01
			{
				name = "collision_green_03";
				color[] = {0.0,0.8,0.0};
				ambient[] = {0.0,0.08,0.0};
			};
			class collision_green_04: collision_red_01
			{
				name = "collision_green_04";
				color[] = {0.0,0.8,0.0};
				ambient[] = {0.0,0.08,0.0};
			};
			// starboard sidelight in front of the bridge (mirror of collision_red_14)
			class collision_green_05: collision_red_01
			{
				name = "collision_green_05";
				color[] = {0.0,0.8,0.0};
				ambient[] = {0.0,0.08,0.0};
			};
			// Bulkhead downlights: switched with the collision lights, and actually light the deck
			// (activeLight = 1, as BI's buoy / tower marker lights). Omni lights; start values, tune in game.
			class light_down_01
			{
				name = "light_down_01";
				color[] = {1.0,0.97,0.9};
				ambient[] = {0.01,0.01,0.01};
				intensity = 300;
				drawLight = 1;
				drawLightSize = 0.1;
				drawLightCenterSize = 0.03;
				activeLight = 1;
				blinking = 0;
				dayLight = 0;
				useFlare = 0;
				class Attenuation
				{
					start = 0;
					constant = 0;
					linear = 1;
					quadratic = 8;
					hardLimitStart = 4;
					hardLimitEnd = 6;
				};
			};
			class light_down_02: light_down_01
			{
				name = "light_down_02";
			};
			class light_down_03: light_down_01
			{
				name = "light_down_03";
			};
			class light_down_04: light_down_01
			{
				name = "light_down_04";
			};
			class light_down_05: light_down_01
			{
				name = "light_down_05";
			};
			class light_down_06: light_down_01
			{
				name = "light_down_06";
			};
			class light_down_07: light_down_01
			{
				name = "light_down_07";
			};
			class light_down_08: light_down_01
			{
				name = "light_down_08";
			};
		};
		// Headlights: the 8 bright floods on the bridge window tops only.
		// The 8 bulkhead downlights are MarkerLights, so they switch with the collision lights.
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
			class light_flood_05: light_flood_01
			{
				position = "light_flood_05";
				direction = "light_flood_05_dir";
				hitpoint = "light_flood_05";
				selection = "light_flood_05";
			};
			class light_flood_06: light_flood_01
			{
				position = "light_flood_06";
				direction = "light_flood_06_dir";
				hitpoint = "light_flood_06";
				selection = "light_flood_06";
			};
			class light_flood_07: light_flood_01
			{
				position = "light_flood_07";
				direction = "light_flood_07_dir";
				hitpoint = "light_flood_07";
				selection = "light_flood_07";
			};
			class light_flood_08: light_flood_01
			{
				position = "light_flood_08";
				direction = "light_flood_08_dir";
				hitpoint = "light_flood_08";
				selection = "light_flood_08";
			};
		};
		// no aggregateReflectors: aggregating merges each group into one light at the group's average position
		class AnimationSources
		{
			class driver_conning
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
			class captain_conning: driver_conning {};
			class assaultboat_deployed
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
		class UserActions
		{
			class driver_to_conning
			{
				displayName = "Move to conning position";
				position = "driverview";
				radius = 15;
				priority = 1;
				onlyForPlayer = 1;
				showWindow = 0;
				condition = "driver this == player && {this animationSourcePhase 'driver_conning' < 0.5}";
				statement = "this animateSource ['driver_conning', 1]";
			};
			class driver_to_helm: driver_to_conning
			{
				displayName = "Move to helm";
				condition = "driver this == player && {this animationSourcePhase 'driver_conning' > 0.5}";
				statement = "this animateSource ['driver_conning', 0]";
			};
			class captain_to_conning: driver_to_conning
			{
				condition = "(this turretUnit [3]) == player && {this animationSourcePhase 'captain_conning' < 0.5}";
				statement = "this animateSource ['captain_conning', 1]";
			};
			class captain_to_wheelhouse: driver_to_conning
			{
				displayName = "Move to wheelhouse";
				condition = "(this turretUnit [3]) == player && {this animationSourcePhase 'captain_conning' > 0.5}";
				statement = "this animateSource ['captain_conning', 0]";
			};
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
				statement = "[this, player, 'ladder_1_top'] call adfrc_fremantle_fnc_ladder";
			};
			class ladder_1_down: ladder_1_up
			{
				displayName = "Climb ladder down";
				position = "ladder_1_top";
				statement = "[this, player, 'ladder_1_bottom'] call adfrc_fremantle_fnc_ladder";
			};
			class ladder_2_up: ladder_1_up
			{
				position = "ladder_2_bottom";
				statement = "[this, player, 'ladder_2_top'] call adfrc_fremantle_fnc_ladder";
			};
			class ladder_2_down: ladder_1_up
			{
				displayName = "Climb ladder down";
				position = "ladder_2_top";
				statement = "[this, player, 'ladder_2_bottom'] call adfrc_fremantle_fnc_ladder";
			};
			// Assault Boat: driver or captain only
			class deploy_assaultboat: driver_to_conning
			{
				displayName = "Deploy Assault Boat";
				priority = 0.5;
				condition = "(driver this == player || {(this turretUnit [3]) == player}) && {this animationSourcePhase 'assaultboat_deployed' < 0.5}";
				statement = "[this, 'deploy'] call adfrc_fremantle_fnc_assaultBoat";
			};
			class recover_assaultboat: deploy_assaultboat
			{
				displayName = "Recover Assault Boat";
				condition = "(driver this == player || {(this turretUnit [3]) == player}) && {this animationSourcePhase 'assaultboat_deployed' > 0.5}";
				statement = "[this, 'recover'] call adfrc_fremantle_fnc_assaultBoat";
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				canBeTransported = 0;
			};
		};
	};
	class adfrc_fremantle: adfrc_fremantle_base
	{
		author = "ADFRC";
		displayName = "Fremantle-class Patrol Boat";
		scope = 2;
		scopeCurator = 2;
		crew = "ADFRC_MD_RAN_Coxswain";
		faction = "ADFRC_F_MD";
		side = 1;
		typicalCargo[] = {"ADFRC_MD_RAN_Coxswain"};
	};
};
