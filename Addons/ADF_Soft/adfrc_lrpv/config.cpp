class CfgPatches
{
	class adfrc_lrpv
	{
		addonRootClass = "ADF_Soft";
		name = "ADFRC LRPV";
		author = "ADF Re-Cut";
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Data_F_Mod_Loadorder","A3_Soft_F","A3_Soft_F_Exp","A3_Weapons_F","ADF_Core","ADF_Units","adfrc_abrams","adfrc_magazines"};
		units[] = {"adfrc_lrpv_m2"};
		weapons[] = {"adfrc_lrpv_m249"};
	};
};
class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		adfrc_lrpv_gunner_m2="adfrc_lrpv_gunner_m2";
		adfrc_lrpv_driver="adfrc_lrpv_driver";
		adfrc_lrpv_frontgunner="adfrc_lrpv_frontgunner";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class adfrc_lrpv_gunner_m2: Crew
		{
			file="\ADF_Soft\adfrc_lrpv\anim\hmmwv_m2gunnerout.rtm";
			interpolateTo[]={"adfrc_lrpv_gunner_m2_KIA",1};
			leftHandIKCurve[]={1};
			leftHandIKBeg=1;
			leftHandIKEnd=1;
			rightHandIKCurve[]={1};
			rightHandIKBeg=1;
			rightHandIKEnd=1;
		};
		class adfrc_lrpv_gunner_m2_KIA: DefaultDie
		{
			file="\ADF_Soft\adfrc_lrpv\anim\kia_hmmwv_gunnerout.rtm";
			speed=0.5;
			looped=0;
			terminal=1;
			soundEnabled=0;
			connectTo[]={"Unconscious",0.1};
		};
		class adfrc_lrpv_driver: Crew
		{
			file="\ADF_Soft\adfrc_lrpv\anim\lrpv_driver.rtm";
			interpolateTo[]={"adfrc_lrpv_driver_KIA",1};
			leftHandIKCurve[]={1};
			leftHandIKBeg=1;
			leftHandIKEnd=1;
			rightHandIKCurve[]={1};
			rightHandIKBeg=1;
			rightHandIKEnd=1;
		};
		class adfrc_lrpv_driver_KIA: DefaultDie
		{
			file="\ADF_Soft\adfrc_lrpv\anim\kia_lrpv_driver.rtm";
			speed=0.5;
			looped=0;
			terminal=1;
			soundEnabled=0;
			connectTo[]={"Unconscious",0.1};
		};
		class adfrc_lrpv_frontgunner: Crew
		{
			file="\ADF_Soft\adfrc_lrpv\anim\lrpv_frontgunner.rtm";
			interpolateTo[]={"adfrc_lrpv_frontgunner_KIA",1};
			leftHandIKCurve[]={1};
			leftHandIKBeg=1;
			leftHandIKEnd=1;
			rightHandIKCurve[]={1};
			rightHandIKBeg=1;
			rightHandIKEnd=1;
		};
		class adfrc_lrpv_frontgunner_KIA: DefaultDie
		{
			file="\ADF_Soft\adfrc_lrpv\anim\kia_lrpv_frontgunner.rtm";
			speed=0.5;
			looped=0;
			terminal=1;
			soundEnabled=0;
			connectTo[]={"Unconscious",0.1};
		};
	};
};

class CfgWeapons
{
	class LMG_coax_ext;
	class adfrc_lrpv_m249: LMG_coax_ext
	{
		displayName = "M249 5.56mm";
		magazines[] = {"ADFRC_200Rnd_556_Minimi_TR","ADFRC_200Rnd_556_Minimi_TR5","ADFRC_200Rnd_556_Minimi"};
		magazineReloadTime = 6;
		ballisticsComputer = 0;
	};
};

class CfgVehicles
{
	class LandVehicle;
	class Car: LandVehicle
	{
		class NewTurret;
	};
	class Car_F: Car
	{
		class EventHandlers;
		class CargoTurret;
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewGunner;
				class ViewOptics;
			};
		};
		class HitPoints
		{
			class HitLFWheel;
			class HitLF2Wheel;
			class HitLMWheel;
			class HitRFWheel;
			class HitRF2Wheel;
			class HitRMWheel;
			class HitBody;
			class HitEngine;
			class HitFuel;
		};
	};

	class adfrc_lrpv_base: Car_F
	{
		scope = 0;
		scopeCurator = 0;
		author = "Bones";
		model = "\ADF_Soft\adfrc_lrpv\adfrc_lrpv";
		picture = "\A3\Soft_F_Exp\LSV_01\Data\UI\LSV_01_armed_CA.paa";
		icon = "\A3\Soft_F_Exp\LSV_01\Data\UI\Map_LSV_01_armed_CA.paa";
		displayName = "LRPV 6x6";
		side = 1;
		faction = "ADFRC_F_MD";
		editorSubcategory = "EdSubcat_Cars";
		crew = "ADFRC_MD_MC_SASR_Light";
		typicalCargo[] = {"ADFRC_MD_MC_SASR_Light"};
		mapSize = 6;

		hiddenSelections[] = {"camo1","camo2","camo3"};
		hiddenSelectionsTextures[] =
		{
			"\ADF_Soft\adfrc_lrpv\data\lr_base_auscam_co.paa",
			"\ADF_Soft\adfrc_lrpv\data\lr_special_auscam_co.paa",
			"\ADF_Soft\adfrc_lrpv\data\lrpvside_auscam_co.paa"
		};
		textureList[] = {"Auscam",1,"DesertCat",0};
		class TextureSources
		{
			class Auscam
			{
				displayName = "Auscam";
				author = "ADFRC";
				textures[] =
				{
					"\ADF_Soft\adfrc_lrpv\data\lr_base_auscam_co.paa",
					"\ADF_Soft\adfrc_lrpv\data\lr_special_auscam_co.paa",
					"\ADF_Soft\adfrc_lrpv\data\lrpvside_auscam_co.paa"
				};
				factions[] = {"ADFRC_F_MD"};
			};
			class DesertCat
			{
				displayName = "Desert Cat";
				author = "ADFRC";
				textures[] =
				{
					"\ADF_Soft\adfrc_lrpv\data\lr_base_sasdesert_co.paa",
					"\ADF_Soft\adfrc_lrpv\data\lr_special_sasdesert_co.paa",
					"\ADF_Soft\adfrc_lrpv\data\lrpvside_sasdesert_co.paa"
				};
				factions[] = {"ADFRC_F_MD"};
			};
		};

		armor = 60;
		fireResistance = 5;
		cost = 100000;
		terrainCoef = 1.5;
		turnCoef = 3;
		precision = 10;
		brakeDistance = 3.0;
		acceleration = 15;
		maxFordingDepth = 0.7;
		waterResistance = 1;
		crewCrashProtection = 0.25;
		wheelDamageRadiusCoef = 0.9;
		wheelDestroyRadiusCoef = 0.4;
		transportSoldier = 0;
		transportMaxBackpacks = 4;

		driverCompartments = "Compartment1";
		driverAction = "adfrc_lrpv_driver";
		driverInAction = "adfrc_lrpv_driver";
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		memoryPointsGetInDriver = "pos driver";
		memoryPointsGetInDriverDir = "pos driver dir";
		driverLeftHandAnimName = "drivewheel_hand_l";
		driverRightHandAnimName = "drivewheel_hand_r";

		memoryPointTrackFLL = "stopa PLL";
		memoryPointTrackFLR = "stopa PLP";
		memoryPointTrackFRL = "stopa PPL";
		memoryPointTrackFRR = "stopa PPP";
		memoryPointTrackBLL = "stopa ZLL";
		memoryPointTrackBLR = "stopa ZLP";
		memoryPointTrackBRL = "stopa ZPL";
		memoryPointTrackBRR = "stopa ZPP";

		#include "sounds.hpp"
		#include "physx.hpp"

		class PlayerSteeringCoefficients
		{
			turnIncreaseConst = 0.3;
			turnIncreaseLinear = 1.0;
			turnIncreaseTime = 1.0;
			turnDecreaseConst = 5.0;
			turnDecreaseLinear = 3.0;
			turnDecreaseTime = 0.0;
			maxTurnHundred = 0.7;
		};

		// Component damage (same setup as the Boxer/Abrams): each hitpoint is driven by its own
		// Fire Geometry component (armorComponent) with A3 penetration materials, plus a point
		// cloud of the same name in the HitPoints LOD for blast/indirect damage.
		class HitPoints: HitPoints
		{
			class HitBody: HitBody
			{
				armor = 1;
				material = -1;
				armorComponent = "hit_hull";
				name = "hit_hull_point";
				visual = "-";
				passThrough = 1;
				minimalHit = 0.02;
				explosionShielding = 1.5;
				radius = 0.3;
			};
			class HitEngine: HitEngine
			{
				armor = 0.5;
				material = -1;
				armorComponent = "hit_engine";
				name = "hit_engine_point";
				visual = "-";
				passThrough = 0.2;
				minimalHit = 0.1;
				explosionShielding = 0.5;
				radius = 0.25;
			};
			class HitFuel: HitFuel
			{
				armor = 0.5;
				material = -1;
				armorComponent = "hit_fuel";
				name = "hit_fuel_point";
				visual = "-";
				passThrough = 0.2;
				minimalHit = 0.1;
				explosionShielding = 0.5;
				radius = 0.25;
			};
			class HitLFWheel: HitLFWheel
			{
				armor = 0.2;
				material = -1;
				armorComponent = "wheel_1_1_hide";
				name = "wheel_1_1_steering";
				visual = "wheel_1_1_hide";
				passThrough = 0;
				minimalHit = 0.02;
				explosionShielding = 4;
				radius = 0.33;
			};
			class HitLF2Wheel: HitLF2Wheel
			{
				armor = 0.2;
				material = -1;
				armorComponent = "wheel_1_2_hide";
				name = "wheel_1_2_steering";
				visual = "wheel_1_2_hide";
				passThrough = 0;
				minimalHit = 0.02;
				explosionShielding = 4;
				radius = 0.33;
			};
			class HitLMWheel: HitLMWheel
			{
				armor = 0.2;
				material = -1;
				armorComponent = "wheel_1_3_hide";
				name = "wheel_1_3_steering";
				visual = "wheel_1_3_hide";
				passThrough = 0;
				minimalHit = 0.02;
				explosionShielding = 4;
				radius = 0.33;
			};
			class HitRFWheel: HitRFWheel
			{
				armor = 0.2;
				material = -1;
				armorComponent = "wheel_2_1_hide";
				name = "wheel_2_1_steering";
				visual = "wheel_2_1_hide";
				passThrough = 0;
				minimalHit = 0.02;
				explosionShielding = 4;
				radius = 0.33;
			};
			class HitRF2Wheel: HitRF2Wheel
			{
				armor = 0.2;
				material = -1;
				armorComponent = "wheel_2_2_hide";
				name = "wheel_2_2_steering";
				visual = "wheel_2_2_hide";
				passThrough = 0;
				minimalHit = 0.02;
				explosionShielding = 4;
				radius = 0.33;
			};
			class HitRMWheel: HitRMWheel
			{
				armor = 0.2;
				material = -1;
				armorComponent = "wheel_2_3_hide";
				name = "wheel_2_3_steering";
				visual = "wheel_2_3_hide";
				passThrough = 0;
				minimalHit = 0.02;
				explosionShielding = 4;
				radius = 0.33;
			};
		};

		class Exhausts
		{
			class Exhaust1
			{
				position = "vyfuk start";
				direction = "vyfuk konec";
				effect = "ExhaustsEffect";
			};
		};

		// Headlights: memory points Light_L/_end/_flare and Light_R/_end/_flare (same naming as the
		// A3 Offroad); hitpoints Light_L/Light_R in the HitPoints LOD. Taillights are LOD1 face
		// selections "zadni svetlo" (tail) and "brzdove svetlo" (brake), inherited engine defaults.
		class Reflectors
		{
			class Left
			{
				color[] = {1900,1800,1700};
				ambient[] = {5,5,5};
				position = "Light_L";
				direction = "Light_L_end";
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
				position = "Light_R";
				direction = "Light_R_end";
				hitpoint = "Light_R";
				selection = "Light_R";
			};
			class Left2: Left
			{
				position = "light_L_flare";
				useFlare = 1;
			};
			class Right2: Right
			{
				position = "light_R_flare";
				useFlare = 1;
			};
		};
		aggregateReflectors[] = {{"Left","Right","Left2","Right2"}};


		class Damage
		{
			tex[] = {};
			mat[] = {};
		};

		class Turrets: Turrets
		{
			// Rear pintle .50 (centre ring)
			class MainTurret: MainTurret
			{
				class HitPoints
				{
					class HitTurret
					{
						armor = 0.5;
						material = -1;
						armorComponent = "hit_main_turret";
						name = "hit_main_turret_point";
						visual = "-";
						passThrough = 0;
						minimalHit = 0.05;
						explosionShielding = 1;
						radius = 0.15;
						isTurret = 1;
					};
					class HitGun
					{
						armor = 0.4;
						material = -1;
						armorComponent = "hit_main_gun";
						name = "hit_main_gun_point";
						visual = "-";
						passThrough = 0;
						minimalHit = 0.05;
						explosionShielding = 1;
						radius = 0.15;
						isGun = 1;
					};
				};
				body = "MainTurret";
				gun = "MainGun";
				animationSourceBody = "mainTurret";
				animationSourceGun = "mainGun";
				proxyIndex = 1;
				primaryGunner = 1;
				gunnerName = "Rear Gunner";
				gunnerAction = "adfrc_lrpv_gunner_m2";
				gunnerInAction = "adfrc_lrpv_gunner_m2";
				gunnerLeftHandAnimName = "m2_hand_l";
				gunnerRightHandAnimName = "m2_hand_r";
				gunnerCompartments = "Compartment1";
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				memoryPointGun = "machinegun";
				memoryPointGunnerOptics = "gunnerview";
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				selectionFireAnim = "zasleh";
				gunnerOpticsModel = "\A3\weapons_f\reticle\optics_empty";
				weapons[] = {"ADFRC_abrams_M2HBQCB"};
				magazines[] = {"100rnd_127x99_mag_Tracer_Red","100rnd_127x99_mag_Tracer_Red","100rnd_127x99_mag_Tracer_Red","100rnd_127x99_mag_Tracer_Red","100rnd_127x99_mag_Tracer_Red","100rnd_127x99_mag_Tracer_Red"};
				minElev = -15;
				maxElev = 45;
				minTurn = -360;
				maxTurn = 360;
				initTurn = 0;
				outGunnerMayFire = 1;
				inGunnerMayFire = 1;
				gunnerForceOptics = 0;
				castGunnerShadow = 1;
				startEngine = 0;
				stabilizedInAxes = 0;
				class GunParticles
				{
					class effect1
					{
						positionName = "usti hlavne";
						directionName = "konec hlavne";
						effectName = "MachineGunCloud";
					};
					class effect2
					{
						positionName = "nabojnicestart";
						directionName = "nabojniceend";
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
			// Front passenger pintle MAG58
			class FrontTurret: MainTurret
			{
				class HitPoints
				{
					class HitTurret
					{
						armor = 0.5;
						material = -1;
						armorComponent = "hit_front_turret";
						name = "hit_front_turret_point";
						visual = "-";
						passThrough = 0;
						minimalHit = 0.05;
						explosionShielding = 1;
						radius = 0.15;
						isTurret = 1;
					};
					class HitGun
					{
						armor = 0.4;
						material = -1;
						armorComponent = "hit_front_gun";
						name = "hit_front_gun_point";
						visual = "-";
						passThrough = 0;
						minimalHit = 0.05;
						explosionShielding = 1;
						radius = 0.15;
						isGun = 1;
					};
				};
				body = "FrontTurret";
				gun = "FrontGun";
				animationSourceBody = "frontTurret";
				animationSourceGun = "frontGun";
				proxyIndex = 2;
				primaryGunner = 0;
				commanding = -2;
				gunnerName = "Front Gunner";
				gunnerAction = "adfrc_lrpv_frontgunner";
				gunnerInAction = "adfrc_lrpv_frontgunner";
				gunnerLeftHandAnimName = "fg_hand_l";
				gunnerRightHandAnimName = "fg_hand_r";
				memoryPointsGetInGunner = "pos_Gunner2";
				memoryPointsGetInGunnerDir = "pos_Gunner2_Dir";
				memoryPointGun = "machinegun_2";
				memoryPointGunnerOptics = "gunnerview_2";
				gunBeg = "usti hlavne_2";
				gunEnd = "konec hlavne_2";
				selectionFireAnim = "zasleh_1";
				weapons[] = {"adfrc_lrpv_m249"};
				magazines[] = {"ADFRC_200Rnd_556_Minimi_TR","ADFRC_200Rnd_556_Minimi_TR","ADFRC_200Rnd_556_Minimi_TR","ADFRC_200Rnd_556_Minimi_TR","ADFRC_200Rnd_556_Minimi_TR"};
				minElev = -15;
				maxElev = 30;
				minTurn = -60;
				maxTurn = 60;
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
			};
			// FFV seats on the water crates in the tray, facing inward
			class CargoTurret_01: CargoTurret
			{
				gunnerName = "Tray Seat (Right Front)";
				gunnerAction = "passenger_inside_1";
				gunnerInAction = "passenger_inside_1";
				gunnerCompartments = "Compartment1";
				memoryPointsGetInGunner = "pos cargo";
				memoryPointsGetInGunnerDir = "pos cargo dir";
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				proxyIndex = 1;
				isPersonTurret = 1;
				maxElev = 40;
				minElev = -20;
				maxTurn = 95;
				minTurn = -95;
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerName = "Tray Seat (Right Rear)";
				proxyIndex = 2;
			};
			class CargoTurret_03: CargoTurret_01
			{
				gunnerName = "Tray Seat (Left)";
				proxyIndex = 3;
			};
		};

		class EventHandlers: EventHandlers {};
	};

	class adfrc_lrpv_m2: adfrc_lrpv_base
	{
		scope = 2;
		scopeCurator = 2;
		displayName = "LRPV 6x6 (M2/MAG58) [WIP]";
	};
	class adfrc_lrpv_m2_GWOT: adfrc_lrpv_m2
	{
		faction="ADFRC_F_GWOT";
	};
};
