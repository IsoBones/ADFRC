class CfgPatches
{
	class adfrc_rhib
	{
		addonRootClass = "A3_Boat_F";
		requiredAddons[] = {"A3_Boat_F","A3_Data_F_Mod_Loadorder","ADF_Core","ADF_Units"};
		requiredVersion = 0.1;
		units[] = {"adfrc_rhib"};
		weapons[] = {};
	};
};

// Crew poses for the RHIB jockey seats
class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		ADFRC_RHIB_Driver = "ADFRC_RHIB_Driver";
		ADFRC_RHIB_Cargo = "ADFRC_RHIB_Cargo";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class ADFRC_KIA_RHIB_Driver: DefaultDie
		{
			file = "\ADF_Boat\adfrc_rhib\data\anim\kia_rhib_driver.rtm";
			actions = "DeadActions";
			speed = 0.5;
			looped = 0;
			terminal = 1;
			connectTo[] = {"DeadState",0.1};
		};
		class ADFRC_RHIB_Driver: Crew
		{
			file = "\ADF_Boat\adfrc_rhib\data\anim\rhib_driver.rtm";
			interpolateTo[] = {"ADFRC_KIA_RHIB_Driver",1};
			leftHandIKCurve[] = {1};
			leftHandIKBeg = 1;
			leftHandIKEnd = 1;
			rightHandIKCurve[] = {1};
			rightHandIKBeg = 1;
			rightHandIKEnd = 1;
		};
		class ADFRC_KIA_RHIB_Cargo: ADFRC_KIA_RHIB_Driver
		{
			file = "\ADF_Boat\adfrc_rhib\data\anim\kia_rhib_cargo.rtm";
		};
		class ADFRC_RHIB_Cargo: Crew
		{
			file = "\ADF_Boat\adfrc_rhib\data\anim\rhib_cargo.rtm";
			interpolateTo[] = {"ADFRC_KIA_RHIB_Cargo",1};
		};
	};
};

class CfgVehicles
{
	class Ship_F;
	class Boat_F: Ship_F
	{
		class ViewPilot;
	};
	// Rigid hull inflatable boat, unarmed: driver plus 10 on the jockey seats.
	class adfrc_rhib: Boat_F
	{
		editorPreview = "\ADF_Boat\adfrc_rhib\data\editorPreviews\adfrc_rhib.jpg";
		author = "ADFRC";
		displayName = "RHIB";
		model = "\ADF_Boat\adfrc_rhib\adfrc_rhib.p3d";
		scope = 2;
		scopeCurator = 2;
		side = 1;
		faction = "ADFRC_F_MD";
		crew = "ADFRC_MD_RAN_Coxswain";
		typicalCargo[] = {"ADFRC_MD_RAN_Coxswain"};
		vehicleClass = "Ship";
		editorSubcategory = "EdSubcat_Boats";
		picture = "\A3\boat_f\Boat_Armed_01\data\ui\Boat_Armed_01_minigun.paa";
		Icon = "\A3\boat_f\Boat_Armed_01\data\ui\map_boat_armed_01_minigun.paa";
		mapSize = 10;
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
		unitInfoType = "RscUnitInfoShip";
		extCameraPosition[] = {0,4,-14};
		slingLoadCargoMemoryPoints[] = {"SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
		attenuationEffectType = "OpenCarAttenuation";
		insideSoundCoef = 0;
		crewVulnerable = 1;
		ejectDeadDriver = 0;
		ejectDeadCargo = 0;
		enableGPS = 1;
		cost = 200000;
		threat[] = {0,0,0};

		// Crew: driver at the helm console, 10 passengers on the jockey seats
		driverAction = "ADFRC_RHIB_Driver";
		driverLeftHandAnimName = "volant_hand_l";
		driverRightHandAnimName = "throttle_hand_r";
		cargoAction[] = {"ADFRC_RHIB_Cargo"};
		transportSoldier = 10;
		LODDriverTurnedIn = 1100;
		LODDriverTurnedOut = 1100;
		hideWeaponsDriver = 0;
		hideWeaponsCargo = 0;
		castDriverShadow = 1;
		castCargoShadow = 1;
		memoryPointsGetInDriver = "pos driver";
		memoryPointsGetInDriverDir = "pos driver dir";
		memoryPointsGetInCargo = "pos cargo";
		memoryPointsGetInCargoDir = "pos cargo dir";
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		cargoGetInAction[] = {"GetInLow"};
		cargoGetOutAction[] = {"GetOutLow"};
		getInRadius = 10;
		class Turrets {};
		class ViewPilot: ViewPilot
		{
			initAngleX = 5;
		};

		armor = 50;
		class HitPoints
		{
			class HitBody
			{
				armor = 0.6;
				material = 50;
				name = "telo";
				visual = "";
				passThrough = 1;
				explosionShielding = 2;
			};
			class HitEngine
			{
				armor = 1.2;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 1;
				minimalHit = 0.1;
				explosionShielding = 0.5;
				radius = 0.4;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] =
			{
				"ADF_Boat\adfrc_rhib\data\rhib.rvmat","ADF_Boat\adfrc_rhib\data\rhib.rvmat","ADF_Boat\adfrc_rhib\data\rhib_destruct.rvmat",
				"ADF_Boat\adfrc_rhib\data\rhib_dash.rvmat","ADF_Boat\adfrc_rhib\data\rhib_dash.rvmat","ADF_Boat\adfrc_rhib\data\rhib_dash_destruct.rvmat"
			};
		};

		// Handling: the vanilla Apex RHIB (Boat_Transport_02_base_F) values; the model's mass (5,000 kg) matches it.
		simulation = "shipX";
		maxSpeed = 90;
		overSpeedBrakeCoef = 0.5;
		thrustDelay = 0.5;
		enginePower = 190;
		engineShiftY = 1.25;
		waterLeakiness = 0.1;
		waterResistance = 3;
		waterResistanceCoef = 0.002;
		waterLinearDampingCoefX = 1.0;
		waterLinearDampingCoefY = 4.0;
		waterAngularDampingCoef = 1.0;
		rudderForceCoef = 0.15;
		rudderForceCoefAtMaxSpeed = 0.001;
		idleRpm = 200;
		redRpm = 1050;
		class complexGearbox
		{
			GearboxRatios[] = {"R1",-5.5,"N",0,"D1",2,"D2",1.75,"D3",1.6,"D4",1.46,"D5",1.32,"D6",1.25};
			TransmissionRatios[] = {"High",1.0};
			gearBoxMode = "auto";
			moveOffGear = 1;
			driveString = "D";
			neutralString = "N";
			reverseString = "R";
		};
		memoryPointsLeftEngineEffect = "EngineEffectL";
		memoryPointsRightEngineEffect = "EngineEffectR";
		memoryPointsLeftWaterEffect = "waterEffectL";
		memoryPointsRightWaterEffect = "waterEffectR";
		engineEffectSpeed = 2;
		leftEngineEffect = "LEngEffectsSmall";
		rightEngineEffect = "REngEffectsSmall";
		waterEffectSpeed = 2;
		leftWaterEffect = "LWaterEffects";
		rightWaterEffect = "RWaterEffects";
		waterFastEffectSpeed = 18;
		leftFastWaterEffect = "LFastWaterEffects";
		rightFastWaterEffect = "RFastWaterEffects";

		soundEngineOnInt[] = {"a3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-ext-start-02",0.56234133,1};
		soundEngineOnExt[] = {"a3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-ext-start-02",0.56234133,1,200};
		soundEngineOffInt[] = {"a3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-ext-stop-02",0.56234133,1};
		soundEngineOffExt[] = {"a3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-ext-stop-02",0.56234133,1,200};
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
				sound[] = {"A3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-idle-2",0.5011872,1,300};
				frequency = "0.95 + ((rpm/ 1200) factor[(100/ 1200),(300/ 1200)])*0.15";
				volume = "engineOn*(((rpm/ 1200) factor[(0/ 1200),(30/ 1200)]) * ((rpm/ 1200) factor[(500/ 1200),(300/ 1200)]))";
			};
			class Engine
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-low-2",0.63095737,1,450};
				frequency = "0.95 + ((rpm/ 1200) factor[(300/ 1200),(600/ 1200)])*0.2";
				volume = "engineOn*(((rpm/ 1200) factor[(150/ 1200),(250/ 1200)]) * ((rpm/ 1200) factor[(600/ 1200),(400/ 1200)]))";
			};
			class EngineMidOut
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-mid-2",0.7943282,1,500};
				frequency = "0.95 + ((rpm/ 1200) factor[(600/ 1200),(900/ 1200)])*0.2";
				volume = "engineOn*(((rpm/ 1200) factor[(350/ 1200),(500/ 1200)]) * ((rpm/ 1200) factor[(1000/ 1200),(700/ 1200)]))";
			};
			class EngineMaxOut
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-high-2",1,1,600};
				frequency = "0.95 + ((rpm/ 1200) factor[(700/ 1200),(1000/ 1200)])*0.2";
				volume = "engineOn*((rpm/ 1200) factor[(800/ 1200),(1200/ 1200)])";
			};
			class WaternoiseOutW0
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-0-speed1",0.70794576,1,150};
				frequency = "1";
				volume = "(speed factor[4, 1]) * water";
			};
			class WaternoiseOutW1
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-20-speed",0.7943282,1,250};
				frequency = "1";
				volume = "((speed factor[2, 6]) min (speed factor[6, 4]))";
			};
			class WaternoiseOutW2
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\SFX\voda-o-bok-lodi-50-speed",1,1,350};
				frequency = "1";
				volume = "(speed factor[3, 9])";
			};
			class scrubLandExt
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\noises\boat_land_on_shallow",1.7782794,0.9,100};
				frequency = 1;
				volume = "(scrubLand factor[0.01, 0.20])";
			};
		};

		// Navigation lights
		class MarkerLights
		{
			class light_side_p
			{
				name = "light_side_p";
				color[] = {0.8,0.0,0.0};
				ambient[] = {0.08,0.0,0.0};
				intensity = 75;
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
			class light_side_s: light_side_p
			{
				name = "light_side_s";
				color[] = {0.0,0.8,0.0};
				ambient[] = {0.0,0.08,0.0};
			};
			class light_mast: light_side_p
			{
				name = "light_mast";
				color[] = {1.0,1.0,0.95};
				ambient[] = {0.1,0.1,0.1};
			};
			class light_stern: light_mast
			{
				name = "light_stern";
			};
		};
	};
};
