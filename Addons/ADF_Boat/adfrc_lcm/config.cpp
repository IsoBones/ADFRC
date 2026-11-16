class CfgPatches
{
	class adfrc_lcm
	{
		addonRootClass = "A3_Boat_F";
		requiredAddons[] = {"A3_Boat_F", "cba_main", "cba_xeh"};
		requiredVersion = 0.1;
		units[] = {"adfrc_lcm",};
		weapons[] = {};
	};
};

#include "cfg_tiedown.hpp"

class Extended_PreInit_EventHandlers
{
	class adfrc_lcm_tiedown_preinit
	{
		init = "call adfrc_lcm_fnc_preInit";
	};
};

class Extended_Init_EventHandlers;

class DefaultEventHandlers;
class RCWSOptics;
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
	class adfrc_lcm_base: Boat_F
	{
		author = "ADFRC - Quiggs";
		mapSize = 12.72;
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
		accuracy = 0.5;
		model = "\ADF_Boat\adfrc_lcm\adfrc_lcm.p3d";
		editorSubcategory = "EdSubcat_Boats";
		extCameraPosition[] = {0,2,-25};
		//picture = "\A3\boat_f\Boat_Armed_01\data\ui\Boat_Armed_01_base.paa";
		Icon = "\A3\boat_f\Boat_Armed_01\data\ui\map_boat_armed_01.paa";
		unitInfoType = "RscUnitInfoShip";
		memoryPointTaskMarker = "TaskMarker_1_pos";
		slingLoadCargoMemoryPoints[] = {"SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4","SlingLoadCargo5","SlingLoadCargo6"};
		attenuationEffectType = "OpenCarAttenuation";
		insideSoundCoef = 0;
		soundEngineOnInt[] = {"a3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-ext-start-02",0.56234133,1.0};
		soundEngineOnExt[] = {"a3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-ext-start-02",0.56234133,1.0,200};
		soundEngineOffInt[] = {"a3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-ext-stop-02",0.56234133,1.0};
		soundEngineOffExt[] = {"a3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-ext-stop-02",0.56234133,1.0,200};
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
				frequency = "0.95	+	((rpm/	1200) factor[(100/	1200),(300/	1200)])*0.15";
				volume = "engineOn*(((rpm/	1200) factor[(0/	1200),(30/	1200)])	*	((rpm/	1200) factor[(500/	1200),(300/	1200)]))";
			};
			class Engine
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-low-2",0.63095737,1.0,450};
				frequency = "0.95	+	((rpm/	1200) factor[(300/	1200),(600/	1200)])*0.2";
				volume = "engineOn*(((rpm/	1200) factor[(150/	1200),(250/	1200)])	*	((rpm/	1200) factor[(600/	1200),(400/	1200)]))";
			};
			class EngineMidOut
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-mid-2",0.7943282,1.0,500};
				frequency = "0.95	+		((rpm/	1200) factor[(600/	1200),(900/	1200)])*0.2";
				volume = "engineOn*(((rpm/	1200) factor[(350/	1200),(500/	1200)])	*	((rpm/	1200) factor[(1000/	1200),(700/	1200)]))";
			};
			class EngineMaxOut
			{
				sound[] = {"A3\Sounds_F\vehicles\boat\Boat_Armed_01\Boat_Armed_01-high-2",1.0,1.0,600};
				frequency = "0.95	+	((rpm/	1200) factor[(700/	1200),(1000/	1200)])*0.2";
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
		class RenderTargets
		{
			class driver_display_1
			{
				renderTarget = "rendertarget0";
				class CameraView1
				{
					pointPosition = "PIP0_pos";
					pointDirection = "PIP0_dir";
					renderVisionMode = 1;
					renderQuality = 0;
					fov = 0.4;
				};
				BBoxes[] = {"PIP_0_TL","PIP_0_TR","PIP_0_BL","PIP_0_BR"};
			};
			class Gunner_1
			{
				renderTarget = "rendertarget3";
				class CameraView1
				{
					pointPosition = "PIP3_pos";
					pointDirection = "PIP3_dir";
					renderVisionMode = 0;
					renderQuality = 0;
					fov = 0.5;
				};
				BBoxes[] = {"PIP_3_TL","PIP_3_TR","PIP_3_BL","PIP_3_BR"};
			};
			class Gunner_TV
			{
				renderTarget = "rendertarget4";
				class CameraView1
				{
					pointPosition = "PIP3_pos";
					pointDirection = "PIP3_dir";
					renderVisionMode = 2;
					renderQuality = 0;
					fov = 0.7;
				};
				BBoxes[] = {"PIP_4_TL","PIP_4_TR","PIP_4_BL","PIP_4_BR"};
			};
		};
		armor = 400;
		class HitPoints
		{
			class HitBody
			{
				armor = 0.2;
				material = 50;
				name = "karoserie";
				visual = "zbytek";
				passThrough = 1;
				explosionShielding = 2;
			};
			class HitEngine
			{
				armor = 0.6;
				material = -1;
				armorComponent = "hit_engine";
				name = "hit_engine_point";
				visual = "-";
				passThrough = 0.5;
				minimalHit = 0.2;
				explosionShielding = 0.2;
				radius = 0.3;
			};
			class HitFuel
			{
				armor = 0.5;
				material = -1;
				armorComponent = "hit_fuel";
				name = "hit_fuel_point";
				visual = "-";
				passThrough = 0.3;
				minimalHit = 0.1;
				explosionShielding = 0.6;
				radius = 0.3;
			};
		};
		driverLeftHandAnimName = "drivewheel";
		driverRightHandAnimName = "drivewheel";
		driverAction = "driver_boat01";
		cargoAction[] = {"passenger_boat_rightrear","passenger_flatground_leanright","passenger_boat_holdright2","passenger_boat_holdleft2","passenger_flatground_leanright","passenger_flatground_leanleft","passenger_boat_holdright","passenger_boat_holdleft"};
		getInAction = "GetInLow";
		getOutAction = "GetOutBoat";
		cargoGetInAction[] = {"GetInLow"};
		cargoGetOutAction[] = {"GetOutBoat"};
		castDriverShadow = 1;
		castCargoShadow = 1;
		gunnerHasFlares = 0;
		enableGPS = 1;
		enableRadio = 1;
		transportSoldier = 8;
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
		steerAheadSimul = 0.5;
		steerAheadPlan = 0.35;
		predictTurnPlan = 0.8;
		predictTurnSimul = 0.6;
		acceleration = 8;
		turnCoef = 1;
		maxSpeed = 50;
		simulation = "shipx";
		thrustDelay = 0.35;
		overSpeedBrakeCoef = 0.2;
		enginePower = 1600;
		engineShiftY = 2;
		waterLeakiness = 1000;
		waterLinearDampingCoefY = 10;
		waterLinearDampingCoefX = 10;
		waterAngularDampingCoef = 25;
		waterResistanceCoef = 0.01;
		rudderForceCoef = 2;
		rudderForceCoefAtMaxSpeed = 0.45;
		idleRpm = 200;
		redRpm = 1400;
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
		enableManualFire = 0;
		smokeLauncherGrenadeCount = 8;
		smokeLauncherVelocity = 14;
		smokeLauncherOnTurret = 0;
		smokeLauncherAngle = 360;
		weapons[] = {"SmokeLauncher"};
		magazines[] = {"SmokeLauncherMag_boat"};
		class Exhausts
		{
			class Exhaust1
			{
				position = "Exhaust1";
				direction = "Exhaust1_dir";
				effect = "";
			};
		};
		leftFastWaterEffect = "LFastWaterEffects";
		rightFastWaterEffect = "RFastWaterEffects";
		waterEffectSpeed = 3;
		engineEffectSpeed = 3;
		waterFastEffectSpeed = 20;
		class AnimationSources
		{
			class ramp_front
			{
				source="door";
				initPhase=0;
				animPeriod=6;
				sound = "ServoRampSound_2";
			};
			class ramp_rear
			{
				source="door";
				initPhase=0;
				animPeriod=6;
				sound = "ServoRampSound_2";
			};
		};
		class ViewPilot: ViewPilot
		{
			initAngleX = -15;
		};
		class Turrets
		{};
		class Library
		{
			libTextDesc = "$STR_A3_CfgVehicles_Boat_Armed_01_Base_Library0";
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"A3\boat_F\Boat_Armed_01\data\Boat_Armed_01_ext.rvmat","A3\boat_F\Boat_Armed_01\data\Boat_Armed_01_ext_damage.rvmat","A3\boat_F\Boat_Armed_01\data\Boat_Armed_01_ext_destruct.rvmat","A3\boat_F\Boat_Armed_01\data\Boat_Armed_01_int.rvmat","A3\boat_F\Boat_Armed_01\data\Boat_Armed_01_int_damage.rvmat","A3\boat_F\Boat_Armed_01\data\Boat_Armed_01_int_destruct.rvmat","A3\boat_F\Boat_Armed_01\data\Boat_Armed_01_ctrls.rvmat","A3\boat_F\Boat_Armed_01\data\Boat_Armed_01_ctrls_damage.rvmat","A3\boat_F\Boat_Armed_01\data\Boat_Armed_01_ctrls_destruct.rvmat","A3\Static_F_Gamma\data\staticturret_01.rvmat","A3\Static_F_Gamma\data\StaticTurret_01_damage.rvmat","A3\Static_F_Gamma\data\StaticTurret_01_destruct.rvmat","A3\Static_F_Gamma\data\staticturret_02.rvmat","A3\Static_F_Gamma\data\StaticTurret_02_damage.rvmat","A3\Static_F_Gamma\data\StaticTurret_02_destruct.rvmat","a3\boat_f\Boat_Armed_01\data\Minigun.rvmat","A3\boat_f\Boat_Armed_01\data\Minigun_damage.rvmat","A3\boat_f\Boat_Armed_01\data\Minigun_destruct.rvmat","a3\boat_f\Boat_Armed_01\data\Minigun_Boat_Armed_01_add.rvmat","A3\boat_f\Boat_Armed_01\data\Minigun_Boat_Armed_01_add_damage.rvmat","A3\boat_f\Boat_Armed_01\data\Minigun_Boat_Armed_01_add_destruct.rvmat","a3\Data_F\Vehicles\Turret.rvmat","A3\Data_F\Vehicles\Turret_damage.rvmat","A3\Data_F\Vehicles\Turret_destruct.rvmat"};
		};
		class Reflectors
		{
			class Left
			{
				color[] = {1900,1800,1700};
				ambient[] = {5,5,5};
				position = "Light_L_pos";
				direction = "Light_L_dir";
				hitpoint = "Light_L";
				selection = "Light_L";
				size = 1;
				innerAngle = 100;
				outerAngle = 179;
				coneFadeCoef = 10;
				intensity = 1;
				useFlare = 0;
				dayLight = 0;
				flareSize = 1.0;
				class Attenuation
				{
					start = 1.0;
					constant = 0;
					linear = 0;
					quadratic = 0.25;
					hardLimitStart = 30;
					hardLimitEnd = 60;
				};
			};
			class Right: Left
			{
				position = "Light_R_pos";
				direction = "Light_R_dir";
				hitpoint = "Light_R";
				selection = "Light_R";
			};
			class Right2: Right
			{
				position = "Light_R_pos";
				hitpoint = "Light_R_flare";
				useFlare = 1;
			};
			class Left2: Left
			{
				position = "light_L_pos";
				hitpoint = "Light_L_flare";
				useFlare = 1;
			};
			class Deck: Left
			{
				position = "Light_deck_pos";
				direction = "Light_deck_dir";
				hitpoint = "Light_deck";
				selection = "Light_deck";
			};
			class Deck2: Deck
			{
				position = "Light_deck_pos";
				hitpoint = "Light_deck_flare";
				useFlare = 1;
			};
		};
		aggregateReflectors[] = {{"Right","Right2"}};
		class UserActions
		{
			class open_front_ramp
			{
				userActionID=50;
				displayName="Lower Front Ramp";
				radius=5;
				showIn3D=17;
				priority=1;
				position="driverview";
				onlyForPlayer=0;
				condition="((this DoorPhase 'ramp_front') == 0) AND Alive (this) and driver this == player";
				statement="this animateDoor ['ramp_front', 1];";
			};
			class close_front_ramp: open_front_ramp
			{
				userActionID=51;
				displayName="Raise Front Ramp";
				condition="((this DoorPhase 'ramp_front') > 0) AND Alive (this) and driver this == player";
				statement="this animateDoor [""ramp_front"", 0];";
			};
			class open_rear_ramp
			{
				userActionID=50;
				displayName="Lower Rear Ramp";
				radius=5;
				showIn3D=17;
				priority=1;
				position="driverview";
				onlyForPlayer=0;
				condition="((this DoorPhase 'ramp_rear') == 0) AND Alive (this) and driver this == player";
				statement="this animateDoor ['ramp_rear', 1];";
			};
			class close_rear_ramp: open_rear_ramp
			{
				userActionID=51;
				displayName="Raise Rear Ramp";
				condition="((this DoorPhase 'ramp_rear') > 0) AND Alive (this) and driver this == player";
				statement="this animateDoor [""ramp_rear"", 0];";
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				canBeTransported = 0;
			};
			// ViV Carrier disabled - tie-down system replaces it.
			// maxLoadMass 0 + canBeTransported guards stop the ViV load action
			// appearing alongside the scroll-wheel tie-down.
			class Carrier
			{
				cargoBayDimensions[] = {};
				disableHeightLimit = 0;
				maxLoadMass = 0;
				cargoAlignment[] = {"center","front"};
				cargoSpacing[] = {0,0,0};
				exits[] = {};
				unloadingInterval = 2;
				loadingDistance = 5.0;
				loadingAngle = 60.0;
				parachuteClassDefault = "B_Parachute_02_F";
				parachuteHeightLimitDefault = 5;
			};
		};
	};
	class adfrc_lcm: adfrc_lcm_base
	{
		author = "ADFRC - Quiggs";
		//editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\B_Boat_Armed_01_minigun_F.jpg";
		displayName = "LCM-1E";
		scope = 2;
		scopeCurator = 2;
		accuracy = 1.5;
		crew = "B_soldier_F";
		faction = "BLU_F";
		side = 1;
		typicalCargo[] = {"B_Soldier_F","B_Soldier_F"};
		class Extended_Init_EventHandlers
		{
			class adfrc_lcm_tiedown
			{
				init = "(_this select 0) call adfrc_lcm_fnc_boatInit";
			};
		};
	};
};