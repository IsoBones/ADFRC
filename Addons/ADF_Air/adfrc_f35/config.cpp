// F-35A Lightning II (RAAF), converted from the Arma 3 Aegis F-38 (Plane_Fighter_05).
// Model and original config: AveryTheKitty & OlliKoskelainen (Arma 3 Aegis), APL-SA.
class CfgPatches
{
	class adfrc_f35
	{
		units[] = {"adfrc_f35","adfrc_f35_stealth"};
		weapons[] = {"ADFRC_F35_GAU22"};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Data_F_Mod_Loadorder","ADF_Core"};
		author = "ADFRC - AveryTheKitty & OlliKoskelainen (Arma 3 Aegis)";
	};
};

#include "\ADF_Core\basicDefines_A3.hpp"

class CfgAmmo
{
	class ammo_Fighter01_Gun20mm_AA;
	class ADFRC_F35_GAU22_25mm: ammo_Fighter01_Gun20mm_AA
	{
		// 25 mm: vanilla 20 mm jet round with the vanilla 25 mm (B_25mm) hit and calibre
		hit = 70;
		indirectHit = 6;
		caliber = 3.8;
	};
};
class CfgMagazines
{
	class magazine_Fighter01_Gun20mm_AA_x450;
	class ADFRC_F35_GAU22_x180: magazine_Fighter01_Gun20mm_AA_x450
	{
		displayName = "25 mm";
		displayNameShort = "25 mm";
		descriptionShort = "GAU-22/A 25 mm, 180 rounds";
		ammo = "ADFRC_F35_GAU22_25mm";
		count = 180;
		initSpeed = 1036;
	};
};
class CfgWeapons
{
	class CannonCore;
	class weapon_Fighter_Gun20mm_AA: CannonCore
	{
		class manual;
	};
	class ADFRC_F35_GAU22: weapon_Fighter_Gun20mm_AA
	{
		displayName = "GAU-22/A 25 mm";
		magazines[] = {"ADFRC_F35_GAU22_x180"};
		class manual: manual
		{
			displayName = "GAU-22/A 25 mm";
			reloadTime = 0.018;	// ~3,300 rounds/min
		};
	};
};

class SensorTemplatePassiveRadar;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateAntiRadiation;
class SensorTemplateLaser;
class SensorTemplateNV;
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;

class CfgVehicles
{
	/* Inheritance (same as BI's Plane_Fighter_01) */
	class Air;
	class Plane: Air
	{
		class HitPoints;
	};
	class Plane_Base_F: Plane
	{
		class AnimationSources;
		class HitPoints: HitPoints
		{
			class HitHull;
		};
		class Components;
		class ViewPilot;
		class EventHandlers;
	};
	class Ejection_Seat_Base_F;
	class Plane_Canopy_Base_F;
	class PlaneWreck;

	/* Bases */
	class adfrc_f35_base: Plane_Base_F
	{
		author = "AveryTheKitty & OlliKoskelainen (Arma 3 Aegis)";
		scope = private;
		vehicleClass = Air;
		editorSubcategory = EdSubcat_Planes;
		side = TWest;
		faction = ADFRC_F_MD;
		displayName = "F-35A Lightning II";
		simulation = airplaneX;
		crew = ADFRC_MD_AMCU_Soldier_FighterPilot;
		typicalCargo[] = {ADFRC_MD_AMCU_Soldier_FighterPilot};
		crewVulnerable = true;
		driverAction = Pilot_Plane_Fighter_01;
		driverLeftHandAnimName = throttle_pilot;
		driverRightHandAnimName = stick_pilot;
		precisegetinout = true;
		driverCanEject = false;
		cargoCanEject = false;
		ejectDeadGunner = false;
		ejectDeadCargo = false;
		ejectDeadDriver = false;
		disableInventory = true;
		getInAction = Pilot_Plane_Fighter_01_Enter;
		getOutAction = Pilot_Plane_Fighter_01_Exit;
		getInRadius = 5.5;
		picture = "\ADF_Air\adfrc_f35\Data\UI\adfrc_f35_CA.paa";
		icon = "\ADF_Air\adfrc_f35\Data\UI\Map_adfrc_f35_CA.paa";
		mapSize = 15.5;
		model = "\ADF_Air\adfrc_f35\adfrc_f35.p3d";
		animated = true;
		hiddenSelections[] =
		{
			Camo1,
			Camo2,
			Camo3,
			Camo4,
			CamoGlass,
			camo_cockpit_1,
			camo_cockpit_2
		};
		hiddenSelectionsTextures[] =
		{
			"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext1_CO.paa",
			"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext2_CO.paa",
			"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext3_CO.paa",
			"\ADF_Air\adfrc_f35\Data\adfrc_f35_pylon_CO.paa",
			"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext_glass_CA.paa",
			"\ADF_Air\adfrc_f35\Data\adfrc_f35_int1_CO.paa",
			"\ADF_Air\adfrc_f35\Data\adfrc_f35_int2_CO.paa"
		};
		weapons[] =
		{
			ADFRC_F35_GAU22,
			Laserdesignator_pilotCamera,
			CMFlareLauncher_Singles
		};
		magazines[] =
		{
			ADFRC_F35_GAU22_x180,
			Laserbatteries,
			240Rnd_CMFlare_Chaff_Magazine
		};
		driveOnComponent[] = {};
		cabinOpening = true;
		gearRetracting = true;
		geardowntime = 3;
		gearuptime = 4.5;
		lightOnGear = true;
		damperSize = 0.01;
		damperForce = 0.01;
		damperDamping = 0;
		canFloat = false;
		formationX = 30;
		formationZ = 30;
		fuelCapacity = 1500;
		availableForSupportTypes[] = {CAS_Bombing};
		armor = 40;
		armorStructural = 1;
		armorLights = 1;
		damageResistance = 0.01096;
		destrType = DestructWreck;
		epeImpulseDamageCoef = 150;
		waterLeakiness = 2.5;
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor = 3;
				explosionShielding = 5;
				name = HitHull;
				passThrough = 1;
				visual = Hit_Hull;
				radius = 0.3;
				minimalHit = 0.02;
				depends = false;
				material = -1;
			};
			class HitEngine: HitHull
			{
				armor = 1.5;
				explosionShielding = 2;
				name = HitEngine;
				passThrough = 0.5;
				visual = Hit_Engine;
				radius = 0.55;
				minimalHit = 0.1;
			};
			class HitAvionics: HitHull
			{
				armor = 1.5;
				explosionShielding = 4;
				name = HitAvionics;
				passThrough = 0.4;
				visual = "";
				radius = 0.3;
				minimalHit = 0.05;
			};
			class HitFuel: HitHull
			{
				armor = 3;
				explosionShielding = 4;
				name = HitFuel;
				passThrough = 0.5;
				visual = Hit_Hull;
				radius = 0.3;
				minimalHit = 0.1;
			};
			class HitFuel2: HitFuel
			{
				armor = 3;
				explosionShielding = 4;
				name = HitFuel2;
				passThrough = 0.5;
				visual = Hit_Hull;
				radius = 0.3;
				minimalHit = 0.1;
			};
			class HitGlass1: HitHull
			{
				armor = 1.5;
				explosionShielding = 3;
				name = HitGlass1;
				passThrough = 0;
				visual = glass1;
				radius = 0.2;
				minimalHit = 0.1;
			};
			class HitLAileron: HitHull
			{
				armor = 1.5;
				explosionShielding = 3;
				name = HitLAileron;
				passThrough = 0.1;
				visual = Hit_AileronL;
				radius = 0.2;
				minimalHit = 0.1;
			};
			class HitRAileron: HitLAileron
			{
				armor = 1.5;
				explosionShielding = 3;
				name = HitRAileron;
				passThrough = 0.1;
				visual = Hit_AileronR;
				radius = 0.2;
				minimalHit = 0.1;
			};
			class HitLCRudder: HitHull
			{
				armor = 1.5;
				explosionShielding = 3;
				name = HitLCRudder;
				passThrough = 0.1;
				visual = Hit_RudderL;
				radius = 0.2;
				minimalHit = 0.1;
			};
			class HitRRudder: HitLCRudder
			{
				armor = 1.5;
				explosionShielding = 3;
				name = HitRRudder;
				passThrough = 0.1;
				visual = Hit_RudderR;
				radius = 0.2;
				minimalHit = 0.1;
			};
			class HitLCElevator: HitHull
			{
				armor = 1.5;
				explosionShielding = 3;
				name = HitLCElevator;
				passThrough = 0.1;
				visual = Hit_ElevatorL;
				radius = 0.2;
				minimalHit = 0.1;
			};
			class HitRElevator: HitLCElevator
			{
				armor = 1.5;
				explosionShielding = 3;
				name = HitRElevator;
				passThrough = 0.1;
				visual = Hit_ElevatorR;
				radius = 0.2;
				minimalHit = 0.1;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] =
			{
				"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext1.rvmat",
				"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext1_damage.rvmat",
				"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext1_destruct.rvmat",
                
				"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext2.rvmat",
				"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext2_damage.rvmat",
				"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext2_destruct.rvmat",

				"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext3.rvmat",
				"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext3_damage.rvmat",
				"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext3_destruct.rvmat",

				"\ADF_Air\adfrc_f35\Data\adfrc_f35_pylon.rvmat",
				"\ADF_Air\adfrc_f35\Data\adfrc_f35_pylon_damage.rvmat",
				"\ADF_Air\adfrc_f35\Data\adfrc_f35_pylon_destruct.rvmat",

				"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext_glass.rvmat",
				"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext_glass_damage.rvmat",
				"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext_glass_damage.rvmat",

				"A3\Air_F_Jets\Plane_Fighter_01\Data\Fighter_01_glass_in.rvmat",
				"A3\Air_F_Jets\Plane_Fighter_01\Data\Fighter_01_glass_in_damage.rvmat",
				"A3\Air_F_Jets\Plane_Fighter_01\Data\Fighter_01_glass_in_damage.rvmat"
			};
		};
		LockDetectionSystem = CM_Lock_Radar;
		incomingMissileDetectionSystem = CM_Lock_Radar + CM_Missile;
		enableGPS = true;
		radarTarget = true;
		visualTarget = true;
		radarTargetSize = 0.8;
		visualTargetSize = 1.0;
		irTargetSize = 1.0;
		reportRemoteTargets = true;
		reportOwnPosition = true;
		receiveRemoteTargets = 1;
		namesound = veh_air_plane_s;
		class Components: Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent: SensorTemplateIR
					{
						class AirTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 3000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						angleRangeHorizontal = 360;
						angleRangeVertical = 90;
						maxTrackableSpeed = 400;
						aimDown = 0;
					};
					class VisualSensorComponent: SensorTemplateVisual
					{
						class AirTarget
						{
							minRange = 500;
							maxRange = 4000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget
						{
							minRange = 500;
							maxRange = 3000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						angleRangeHorizontal = 26;
						angleRangeVertical = 20;
						maxTrackableSpeed = 100;
					};
					class PassiveRadarSensorComponent: SensorTemplatePassiveRadar{};
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange = 14000;
							maxRange = 14000;
							viewDistanceLimitCoef = -1;
							objectDistanceLimitCoef = -1;
						};
						class GroundTarget
						{
							minRange = 8000;
							maxRange = 8000;
							viewDistanceLimitCoef = -1;
							objectDistanceLimitCoef = -1;
						};
						typeRecognitionDistance = 7000;
						angleRangeHorizontal = 60;
						angleRangeVertical = 60;
						groundNoiseDistanceCoef = 0.2;
					};
					class AntiRadiationSensorComponent: SensorTemplateAntiRadiation
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
						maxTrackableATL = 100;
						maxTrackableSpeed = 60;
						angleRangeHorizontal = 60;
						angleRangeVertical = 180;
					};
					class LaserSensorComponent: SensorTemplateLaser{};
					class NVSensorComponent: SensorTemplateNV{};
				};
			};
			class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
			{
				class Components
				{
					class EmptyDisplay
					{
						componentType = EmptyDisplayComponent;
					};
					class MinimapDisplay
					{
						componentType = MinimapDisplayComponent;
						resource = RscCustomInfoMiniMap;
					};
					class UAVDisplay
					{
						componentType = UAVFeedDisplayComponent;
					};
					class VehicleDriverDisplay
					{
						componentType = TransportFeedDisplayComponent;
						source = Driver;
					};
					class VehicleMissileDisplay
					{
						componentType = TransportFeedDisplayComponent;
						source = Missile;
					};
					class SensorDisplay
					{
						componentType = SensorsDisplayComponent;
						range[] =
						{
							16000,
							8000,
							4000,
							2000
						};
						resource = RscCustomInfoSensors;
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
			{
				defaultDisplay = SensorDisplay;
				class Components
				{
					class EmptyDisplay
					{
						componentType = EmptyDisplayComponent;
					};
					class MinimapDisplay
					{
						componentType = MinimapDisplayComponent;
						resource = RscCustomInfoMiniMap;
					};
					class UAVDisplay
					{
						componentType = UAVFeedDisplayComponent;
					};
					class VehicleDriverDisplay
					{
						componentType = TransportFeedDisplayComponent;
						source = Driver;
					};
					class VehicleMissileDisplay
					{
						componentType = TransportFeedDisplayComponent;
						source = Missile;
					};
					class SensorDisplay
					{
						componentType = SensorsDisplayComponent;
						range[] =
						{
							16000,
							8000,
							4000,
							2000
						};
						resource = RscCustomInfoSensors;
					};
				};
			};
			class TransportPylonsComponent
			{
				UIPicture = "\ADF_Air\adfrc_f35\Data\UI\adfrc_f35_3DEN_CA.paa";
				class pylons
				{
					class pylons1
					{
						hardpoints[] = {B_BIM9X_RAIL};
						attachment = PylonRack_Missile_BIM9X_x1;
						priority = 10;
						maxweight = 300;
						UIposition[] = {0.6,0.45};
					};
					class pylons2: pylons1
					{
						UIposition[] = {0.05,0.45};
						mirroredMissilePos = 1;
					};
					class pylons3: pylons1
					{
						hardpoints[] =
						{
							B_BIM9X_RAIL,
							B_BIM9X_DUAL_RAIL,
							B_AMRAAM_D_RAIL,
							B_AMRAAM_D_DUAL_RAIL,
							B_AGM65_RAIL,
							B_GBU12
						};
						attachment = PylonMissile_Bomb_GBU12_x1;
						priority = 9;
						maxweight = 2500;
						UIposition[] = {0.55,0.35};
					};
					class pylons4: pylons3
					{
						UIposition[] = {0.1,0.35};
						mirroredMissilePos = 3;
					};
					class pylons5: pylons1
					{
						hardpoints[] =
						{
							B_BIM9X_RAIL,
							B_BIM9X_DUAL_RAIL,
							B_AMRAAM_D_RAIL,
							B_AMRAAM_D_DUAL_RAIL,
							B_AGM65_RAIL,
							B_AGM65_DUAL_RAIL,
							B_GBU12,
							B_GBU12_DUAL_RAIL,
							B_HARM_RAIL,
							B_SDB_QUAD_RAIL
						};
						attachment = PylonRack_Missile_AMRAAM_D_x2;
						priority = 7;
						maxweight = 5000;
						UIposition[] = {0.5,0.25};
					};
					class pylons6: pylons5
					{
						UIposition[] = {0.15,0.25};
						mirroredMissilePos = 5;
					};
					class pylonBayRight1: pylons1
					{
						hardpoints[] =
						{
							B_AMRAAM_D_INT,
							B_GBU12
						};
						priority = 4;
						maxweight = 2500;
						attachment = PylonMissile_Missile_AMRAAM_D_INT_x1;
						UIposition[] = {0.33,0.35};
						bay = 2;
					};
					class pylonBayLeft1: pylonBayRight1
					{
						UIposition[] = {0.33,0.15};
						mirroredMissilePos = 7;
						bay = 1;
					};
					class pylonBayRight2: pylonBayRight1
					{
						hardpoints[] =
						{
							B_AMRAAM_D_INT,
							B_SDB_QUAD_RAIL,
							B_GBU12
						};
						priority = 2;
						attachment = PylonRack_Bomb_SDB_x4;
						UIposition[] = {0.33,0.3};
					};
					class pylonBayLeft2: pylonBayLeft1
					{
						hardpoints[] =
						{
							B_AMRAAM_D_INT,
							B_SDB_QUAD_RAIL,
							B_GBU12
						};
						attachment = PylonRack_Bomb_SDB_x4;
						UIposition[] = {0.33,0.2};
						mirroredMissilePos = 9;
					};
				};
				class Bays
				{
					class BayLeft1
					{
						bayOpenTime = 0.5;
						openBayWhenWeaponSelected = 0.0;
						autoCloseWhenEmptyDelay = 2.0;
					};
					class BayRight1
					{
						bayOpenTime = 0.5;
						openBayWhenWeaponSelected = 0.0;
						autoCloseWhenEmptyDelay = 2.0;
					};
				};
				class presets
				{
					class empty
					{
						displayName = "$STR_empty";
						attachment[] = {};
					};
					class default
					{
						displayName = "$STR_vehicle_default";
						attachment[] =
						{
							PylonRack_Missile_BIM9X_x1,
							PylonRack_Missile_BIM9X_x1,
							PylonRack_Missile_AMRAAM_D_x2,
							PylonRack_Missile_AMRAAM_D_x2,
							PylonMissile_Bomb_GBU12_x1,
							PylonMissile_Bomb_GBU12_x1,
							PylonMissile_Missile_AMRAAM_D_INT_x1,
							PylonMissile_Missile_AMRAAM_D_INT_x1,
							PylonRack_Bomb_SDB_x4,
							PylonRack_Bomb_SDB_x4
						};
					};
					class AA
					{
						displayName = "$STR_A3_Cfgmagazines_titan_aa_dns";
						attachment[] =
						{
							PylonRack_Missile_BIM9X_x1,
							PylonRack_Missile_BIM9X_x1,
							PylonRack_Missile_BIM9X_x2,
							PylonRack_Missile_BIM9X_x2,
							PylonRack_Missile_AMRAAM_D_x2,
							PylonRack_Missile_AMRAAM_D_x2,
							PylonMissile_Missile_AMRAAM_D_INT_x1,
							PylonMissile_Missile_AMRAAM_D_INT_x1,
							PylonMissile_Missile_AMRAAM_D_INT_x1,
							PylonMissile_Missile_AMRAAM_D_INT_x1
						};
					};
					class CAS
					{
						displayName = "$STR_A3_SHOWCASE_FIXEDWINGS_BIS_TSKAAF_WP";
						attachment[] =
						{
							PylonRack_Missile_BIM9X_x1,
							PylonRack_Missile_BIM9X_x1,
							PylonRack_Missile_AGM_02_x1,
							PylonRack_Missile_AGM_02_x1,
							PylonMissile_Bomb_GBU12_x1,
							PylonMissile_Bomb_GBU12_x1,
							PylonMissile_Missile_AMRAAM_D_INT_x1,
							PylonMissile_Missile_AMRAAM_D_INT_x1,
							PylonRack_Bomb_SDB_x4,
							PylonRack_Bomb_SDB_x4
						};
					};
					class Cluster
					{
						displayName = "$STR_A3_CfgVehicles_Pylons_Presets_Cluster0";
						attachment[] =
						{
							PylonRack_Missile_BIM9X_x1,
							PylonRack_Missile_BIM9X_x1,
							PylonRack_Missile_AGM_02_x1,
							PylonRack_Missile_AGM_02_x1,
							PylonRack_2Rnd_BombCluster_01_F,
							PylonRack_2Rnd_BombCluster_01_F,
							PylonMissile_Missile_AMRAAM_D_INT_x1,
							PylonMissile_Missile_AMRAAM_D_INT_x1,
							PylonMissile_1Rnd_BombCluster_01_F,
							PylonMissile_1Rnd_BombCluster_01_F
						};
					};
				};
			};
		};
		memoryPointLDust = "levy prach";
		memoryPointRDust = "pravy prach";
		memoryPointGun = "pos_nosegun";	// GAU-22/A, left upper fuselage over the intake (memory points added to the p3d)
		memoryPointLMissile = "l strela";
		memoryPointRMissile = "p strela";
		memoryPointLRocket = "l raketa";
		memoryPointRRocket = "p raketa";
		memoryPointCM[] = {flare_launcher1};
		memoryPointCMDir[] = {flare_launcher1_dir};
		memoryPointsGetInDriver = "pos driver";
		memoryPointsGetInDriverDir = "pos driver dir";
		memoryPointDriverOptics = PilotCamera_pos;
		slingLoadCargoMemoryPoints[] =
		{
			SlingLoadCargo1,
			SlingLoadCargo2,
			SlingLoadCargo3,
			SlingLoadCargo4
		};
		selectionClan = clan;
		selectionDashboard = autobacklit;
		selectionShowDamage = poskozeni;
		class TransportItems{};
		class Turrets{};
		unitInfoType = RscOptics_CAS_Pilot;
		driverWeaponsInfoType = RscOptics_CAS_01_TGP;
		class pilotCamera
		{
			class OpticsIn
			{
				class Wide
				{
					opticsDisplayName = "WFOV";
					initAngleX = 0;
					minAngleX = 0;
					maxAngleX = 0;
					initAngleY = 0;
					minAngleY = 0;
					maxAngleY = 0;
					initFov = (75 / 120);
					minFov = (75 / 120);
					maxFov = (75 / 120);
					directionStabilized = true;
					visionMode[] =
					{
						Normal,
						NVG,
						Ti
					};
					thermalMode[] = {0,1};
					gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
					opticsPPEffects[] =
					{
						OpticsCHAbera2,
						OpticsBlur2
					};
				};
				class Medium: Wide
				{
					opticsDisplayName = "MFOV";
					initFov = (14.4 / 120);
					minFov = (14.4 / 120);
					maxFov = (14.4 / 120);
					gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
				};
				class Narrow: Wide
				{
					opticsDisplayName = "NFOV";
					initFov = (4.8 / 120);
					minFov = (4.8 / 120);
					maxFov = (4.8 / 120);
					gunnerOpticsModel = "\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
				};
			};
			minTurn = -180;
			maxTurn = 180;
			initTurn = 0;
			minElev = -10;
			maxElev = 90;
			initElev = 0;
			maxXRotSpeed = 1.0;
			maxYRotSpeed = 1.0;
			maxMouseXRotSpeed = 0.5;
			maxMouseYRotSpeed = 0.5;
			pilotOpticsShowCursor = true;
			controllable = true;
		};
		#include "pip.hpp"
		#include "MFD.hpp"
		class AnimationSources
		{
			class canopy_hide
			{
				source = user;
				animPeriod = 0.001;
				initPhase = false;
			};
			class ejection_seat_hide
			{
				source = user;
				animPeriod = 0.001;
				initPhase = false;
			};
			class ejection_seat_motion
			{
				source = user;
				animPeriod = 0.25;
				initPhase = false;
			};
			class tailhook
			{
				source = user;
				animPeriod = 1.5;
				initPhase = true;
			};
			class gear_1_hook_down
			{
				source = user;
				animPeriod = 1.5;
				initPhase = false;
			};
			class tailhook_door_1
			{
				source = user;
				animPeriod = 1.5;
				initPhase = true;
			};
			class tailhook_door_2
			{
				source = user;
				animPeriod = 1.5;
				initPhase = true;
			};
			class tailhook_door_3
			{
				source = user;
				animPeriod = 1.5;
				initPhase = true;
			};
			class pylon_1_hide
			{
				source = user;
				animPeriod = 0.001;
				initPhase = false;
			};
			class pylon_2_hide
			{
				source = user;
				animPeriod = 0.001;
				initPhase = false;
			};
			class pylon_3_hide
			{
				source = user;
				animPeriod = 0.001;
				initPhase = false;
			};
			class pylon_4_hide
			{
				source = user;
				animPeriod = 0.001;
				initPhase = false;
			};
			class pylon_5_hide
			{
				source = user;
				animPeriod = 0.001;
				initPhase = false;
			};
			class pylon_6_hide
			{
				source = user;
				animPeriod = 0.001;
				initPhase = false;
			};
			class throttle_pilot
			{
				source = user;
				animPeriod = 0.5;
				initPhase = false;
			};
			class HitAvionics
			{
				source = Hit;
				hitpoint = HitAvionics;
				raw = true;
			};
			class HitLCRudder
			{
				source = Hit;
				hitpoint = HitLCRudder;
				raw = true;
			};
			class HitRRudder
			{
				source = Hit;
				hitpoint = HitRRudder;
				raw = true;
			};
			class HitLCElevator
			{
				source = Hit;
				hitpoint = HitLCElevator;
				raw = true;
			};
			class HitRElevator
			{
				source = Hit;
				hitpoint = HitRElevator;
				raw = true;
			};
			class HitEngine
			{
				source = Hit;
				hitpoint = HitEngine;
				raw = true;
			};
			class Damper_1_source
			{
				source = damper;
				wheel = Wheel_1;
			};
			class Damper_2_source
			{
				source = damper;
				wheel = Wheel_2;
			};
			class Damper_3_source
			{
				source = damper;
				wheel = Wheel_3;
			};
			class Wheel_1_source
			{
				source = wheel;
				wheel = Wheel_1;
			};
			class Wheel_2_source
			{
				source = wheel;
				wheel = Wheel_2;
			};
			class Wheel_3_source
			{
				source = wheel;
				wheel = Wheel_3;
			};
			class FakeCollisionLight_White_1_source
			{
				source = MarkerLight;
				markerLight = FakeCollisionLight_White_1;
			};
			class FakeCollisionLight_White_2_source
			{
				source = MarkerLight;
				markerLight = FakeCollisionLight_White_2;
			};
		};
		class MarkerLights
		{
			/*
			class PositionLight_Red_1
			{
				color[] =
				{
					0.8, // R
					0.0, // G
					0.0 // B
				};
				ambient[] =
				{
					0.08, // R
					0.0, // G
					0.0 // B
				};
				intensity = 75;
				name = PositionLight_Red_1_pos;
				drawLight = 1;
				drawLightSize = 0.15;
				drawLightCenterSize = 0.04;
				activeLight = false;
				blinking = false;
				dayLight = false;
				useFlare = true;
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
			class PositionLight_Green_1: PositionLight_Red_1
			{
				color[] =
				{
					0.0, // R
					0.8, // G
					0.0 // B
				};
				ambient[] =
				{
					0.0, // R
					0.08, // G
					0.0 // B
				};
				name = PositionLight_Green_1_pos;
			};
			class CollisionLight_White_1: PositionLight_Red_1
			{
				color[] =
				{
					1.0, // R
					1.0, // G
					1.0 // B
				};
				ambient[] =
				{
					0.1, // R
					0.1, // G
					0.1 // B
				};
				name = CollisionLight_White_1_pos;
				blinking = true;
				blinkingStartsOn = true;
				blinkingPattern[] = {0.1,0.9};
				blinkingPatternGuarantee = true;
				drawLightSize = 0.35;
				drawLightCenterSize = 0.05;
			};
			class CollisionLight_White_2: CollisionLight_White_1
			{
				name = CollisionLight_White_2_pos;
			};
			*/
			class FakeCollisionLight_White_1
			{
				color[] =
				{
					0.8, // R
					0.0, // G
					0.0 // B
				};
				ambient[] =
				{
					0.08, // R
					0.0, // G
					0.0 // B
				};
				intensity = 1;
				name = FakeCollisionLight_White_1_pos;
				drawLight = 0;
				drawLightSize = 0;
				drawLightCenterSize = 0;
				activeLight = false;
				blinking = true;
				blinkingStartsOn = true;
				blinkingPattern[] = {0.1,0.9};
				blinkingPatternGuarantee = true;
				dayLight = false;
				useFlare = false;
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
			class FakeCollisionLight_White_2: FakeCollisionLight_White_1
			{
				name = FakeCollisionLight_White_2_pos;
			};
		};
		class Reflectors
		{
			class Light
			{
				position = Light_pos;
				direction = Light_dir;
				hitpoint = Light;
				selection = Light;
				color[] =
				{
					0.85, // R
					0.95, // G
					1 // B
				};
				ambient[] =
				{
					0.0085, // R
					0.0095, // G
					0.01 // B
				};
				intensity = 500000;
				size = 1;
				innerAngle = 15;
				outerAngle = 50;
				coneFadeCoef = 1;
				useFlare = true;
				dayLight = false;
				FlareSize = 2;
				flareMaxDistance = 500;
				class Attenuation
				{
					start = 1;
					constant = 0;
					linear = 0;
					quadratic = 4;
					hardLimitStart = 350;
					hardLimitEnd = 650;
				};
			};
		};
		#include "flightModel.hpp"
		class UserActions
		{
			class adfrc_f35_Eject
			{
				priority = 0.05;
				shortcut = Eject;
				displayName = "$STR_A3_action_eject";
				condition = "player in this && {speed this > 1}";
				statement = "[this] spawn BIS_fnc_planeEjection";
				position = pilotcontrol;
				radius = 10;
				onlyforplayer = true;
				showWindow = false;
				hideOnUse = true;
			};
			class adfrc_f35_tailhook_down: adfrc_f35_Eject
			{
				displayName = "$STR_A3_action_tailhook_down";
				shortcut = "";
				condition = "this animationPhase 'tailhook' > 0.1  and {speed this > 100}";
				statement = "this animate ['tailhook',0]; this animate ['tailhook_door_1',0]; this animate ['tailhook_door_2',0]; this animate ['tailhook_door_3',0]; this say 'Plane_Fighter_01_tailhook_down_sound'; this say3D 'Plane_Fighter_01_tailhook_down_sound'; this SetUserMFDvalue [4,1]; [this] spawn BIS_fnc_AircraftTailhook;";
			};
			class adfrc_f35_tailhook_up: adfrc_f35_tailhook_down
			{
				displayName = "$STR_A3_action_tailhook_up";
				condition = "this animationPhase 'tailhook' < 0.1";
				statement = "this animate ['tailhook',1]; this animate ['tailhook_door_1',1]; this animate ['tailhook_door_2',1]; this animate ['tailhook_door_3',1]; this say 'Plane_Fighter_01_tailhook_up_sound'; this say3D 'Plane_Fighter_01_tailhook_up_sound'; this SetUserMFDvalue [4,0];";
			};
		};
		class TextureSources
		{
			class Grey
			{
				displayName = "Grey";
				author = "AveryTheKitty (Arma 3 Aegis)";
				textures[] =
				{
					"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext1_CO.paa",
					"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext2_CO.paa",
					"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext3_CO.paa",
					"\ADF_Air\adfrc_f35\Data\adfrc_f35_pylon_CO.paa",
					"\ADF_Air\adfrc_f35\Data\adfrc_f35_ext_glass_CA.paa",
					"\ADF_Air\adfrc_f35\Data\adfrc_f35_int1_CO.paa",
					"\ADF_Air\adfrc_f35\Data\adfrc_f35_int2_CO.paa"
				};
				factions[] =
				{
				};
			};
		};
		animationList[] = {};
		textureList[] =
		{
			Grey,1
		};
		#include "PhysX.hpp"
		extCameraPosition[] =
		{
			0.0, // X
			3.0, // Y
			-20.0 // Z
		};
		class ViewPilot: ViewPilot
		{
			initFov = 0.9;
			initAngleX = 0;
			minAngleX = -40;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -130;
			maxAngleY = 130;
			minMoveX = -0.1;
			maxMoveX = 0.1;
			minMoveY = -0.025;
			maxMoveY = 0.05;
			minMoveZ = -0.1;
			maxMoveZ = 0.1;
		};
		class Exhausts
		{
			class Exhaust_1
			{
				position = exhaust_pos;
				direction = exhaust_dir;
				effect = ExhaustsEffectPlaneHP;
				engineIndex = 0;
			};
		};
		class WingVortices
		{
			class WingTipLeft
			{
				effectName = FX_WingVortices_FighterJet;
				position = body_vapour_L_E;
			};
			class WingTipRight
			{
				effectName = FX_WingVortices_FighterJet;
				position = body_vapour_R_E;
			};
			class BodyLeft
			{
				effectName = FX_FuselageVapour_FighterJet;
				position = body_vapour_L_S;
			};
			class BodyRight
			{
				effectName = FX_FuselageVapour_FighterJet;
				position = body_vapour_R_S;
			};
		};
		class Library
		{
			libEnable = true;
			libTextDesc = "";
		};
		tailHook = true;
		class CarrierOpsCompatability
		{
			ArrestHookAnimationList[] =
			{
				tailhook,
				tailhook_door_1,
				tailhook_door_2,
				tailhook_door_3
			};
			ArrestHookAnimationStates[] =
			{
				0,
				0.53,
				1
			};
			ArrestHookMemoryPoint = tailhook_pos;
			ArrestMaxAllowedSpeed = 295;
			ArrestSlowDownStep = 0.7;
			ArrestVelocityReduction = -12;
			LaunchVelocity = 300;
			LaunchVelocityIncrease = 10;
			LaunchAccelerationStep = 0.001;
			LaunchBarMemoryPoint = gear_1_hook_pos;
		};
		class EjectionSystem
		{
			EjectionSeatEnabled = true;
			EjectionDual = false;
			EjectionSeatClass = adfrc_f35_ejection_seat;
			CanopyClass = adfrc_f35_canopy;
			EjectionSeatHideAnim = ejection_seat_hide;
			EjectionSeatRailAnim = ejection_seat_motion;
			CanopyHideAnim = canopy_hide;
			EjectionSeatPos = pos_eject;
			CanopyPos = pos_eject_canopy;
			EjectionSoundExt = Plane_Fighter_01_ejection_ext_sound;
			EjectionSoundInt = Plane_Fighter_01_ejection_in_sound;
			EjectionParachute = Steerable_Parachute_F;
			EjectionSeatForce = 50;
			CanopyForce = 30;
		};
		class Eventhandlers: Eventhandlers
		{
			hit = "_this call BIS_fnc_PlaneAiEject";
			landing = "[_this,true] call bis_fnc_aircraftTailhookAi";
			landingcanceled = "[_this,false] call bis_fnc_aircraftTailhookAi";
		};
	};
	class adfrc_f35_wreck: PlaneWreck
	{
		class SimpleObject
		{
			eden = false;
			animate[] = {};
			hide[] = {};
			verticalOffset = 1.855;
			verticalOffsetWorld = 0;
			init = "''";
		};
		author = "AveryTheKitty & OlliKoskelainen (Arma 3 Aegis)";
		scope = protected;
		class Armory
		{
			disabled = true;
		};
		model = "\ADF_Air\adfrc_f35\adfrc_f35_wreck.p3d";
		typicalCargo[] = {};
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		transportSoldier = 0;
	};
	class adfrc_f35_canopy: Plane_Canopy_Base_F
	{
		class SimpleObject
		{
			eden = false;
			animate[] = {};
			hide[] = {};
			verticalOffset = 0.284;
			verticalOffsetWorld = 0;
			init = "''";
		};
		author = "AveryTheKitty & OlliKoskelainen (Arma 3 Aegis)";
		scope = protected;
		displayName = "$STR_A3_Fighter_01_Canopy_name";
		model = "\ADF_Air\adfrc_f35\adfrc_f35_canopy.p3d";
	};
	class adfrc_f35_ejection_seat_base: Ejection_Seat_Base_F
	{
		author = "AveryTheKitty (Arma 3 Aegis)";
		scope = private;
		displayName = "$STR_A3_Ejection_Seat_01_name";
		model = "\ADF_Air\adfrc_f35\adfrc_f35_ejection_seat.p3d";
		icon = iconParachute;
		picture = "\A3\Air_F_Beta\Parachute_01\Data\UI\Portrait_Parachute_01_CA.paa";
		driverAction = Pilot_Plane_Fighter_Ejection;
		cargoAction[] = {Pilot_Plane_Fighter_Ejection};
	};

    
	/* RAAF */
	class adfrc_f35: adfrc_f35_base
	{
		class SimpleObject
		{
			eden = true;
			animate[] =
			{
				{canopy_rot,0}
			};
			hide[] =
			{
				clan,
				zasleh,
				light,
				"zadni svetlo",
				autobacklit,
				poskozeni
			};
			verticalOffset = 2.445;
			verticalOffsetWorld =-0.051;
			init = "[this, '', []] call bis_fnc_initVehicle";
		};
		author = "AveryTheKitty & OlliKoskelainen (Arma 3 Aegis)";
		scope = public;
		displayName = "F-35A Lightning II";
	};
	class adfrc_f35_stealth: adfrc_f35_base
	{
		author = "AveryTheKitty & OlliKoskelainen (Arma 3 Aegis)";
		scope = public;
		displayName = "F-35A Lightning II (Stealth)";
		radarTargetSize = 0.4;
	
	    /* Animation Sources */
		class AnimationSources: AnimationSources
		{
			class pylon_1_hide: pylon_1_hide
			{
			    initPhase = true;
			};
			class pylon_2_hide: pylon_2_hide
			{
			    initPhase = true;
			};
			class pylon_3_hide: pylon_3_hide
			{
			    initPhase = true;
			};
			class pylon_4_hide: pylon_4_hide
			{
			    initPhase = true;
			};
			class pylon_5_hide: pylon_5_hide
			{
			    initPhase = true;
			};
			class pylon_6_hide: pylon_6_hide
			{
			    initPhase = true;
			};
		};
	
	    /* Sensors & Components */
		class Components: Components
		{
			class TransportPylonsComponent
			{
	            UIPicture = "\ADF_Air\adfrc_f35\Data\UI\adfrc_f35_3DEN_CA.paa";
	            class pylons
	            {
	                class pylonDummy1
	                {
	                    attachment = "";
	                    UIposition[] = {10,10};
	                };
	                class pylonDummy2: pylonDummy1{};
	                class pylonDummy3: pylonDummy1{};
	                class pylonDummy4: pylonDummy1{};
	                class pylonDummy5: pylonDummy1{};
	                class pylonDummy6: pylonDummy1{};
	                class pylonBayRight1
	                {
	                    hardpoints[] =
	                    {
	                        B_AMRAAM_D_INT,
	                        B_GBU12
	                    };
	                    priority = 4;
	                    maxweight = 2500;
	                    attachment = PylonMissile_Missile_AMRAAM_D_INT_x1;
	                    UIposition[] = {0.33,0.35};
	                    bay = 2;
	                };
	                class pylonBayLeft1: pylonBayRight1
	                {
	                    UIposition[] = {0.33,0.15};
	                    mirroredMissilePos = 7;
	                    bay = 1;
	                };
	                class pylonBayRight2: pylonBayRight1
	                {
	                    hardpoints[] =
	                    {
	                        B_AMRAAM_D_INT,
	                        B_SDB_QUAD_RAIL,
	                        B_GBU12
	                    };
	                    priority = 2;
	                    attachment = PylonRack_Bomb_SDB_x4;
	                    UIposition[] = {0.33,0.3};
	                };
	                class pylonBayLeft2: pylonBayLeft1
	                {
	                    hardpoints[] =
	                    {
	                        B_AMRAAM_D_INT,
	                        B_SDB_QUAD_RAIL,
	                        B_GBU12
	                    };
	                    attachment = PylonRack_Bomb_SDB_x4;
	                    UIposition[] = {0.33,0.2};
	                    mirroredMissilePos = 9;
	                };
	            };
	            class presets
	            {
	                class empty
	                {
	                    displayName = "$STR_empty";
	                    attachment[] = {};
	                };
	                class default
	                {
	                    displayName = "$STR_vehicle_default";
	                    attachment[] =
	                    {
	                        "",
	                        "",
	                        "",
	                        "",
	                        "",
	                        "",
	                        PylonMissile_Missile_AMRAAM_D_INT_x1,
	                        PylonMissile_Missile_AMRAAM_D_INT_x1,
	                        PylonRack_Bomb_SDB_x4,
	                        PylonRack_Bomb_SDB_x4
	                    };
	                };
	                class AA
	                {
	                    displayName = "$STR_A3_Cfgmagazines_titan_aa_dns";
	                    attachment[] =
	                    {
	                        "",
	                        "",
	                        "",
	                        "",
	                        "",
	                        "",
	                        PylonMissile_Missile_AMRAAM_D_INT_x1,
	                        PylonMissile_Missile_AMRAAM_D_INT_x1,
	                        PylonMissile_Missile_AMRAAM_D_INT_x1,
	                        PylonMissile_Missile_AMRAAM_D_INT_x1
	                    };
	                };
	                class CAS
	                {
	                    displayName = "$STR_A3_SHOWCASE_FIXEDWINGS_BIS_TSKAAF_WP";
	                    attachment[] =
	                    {
	                        "",
	                        "",
	                        "",
	                        "",
	                        "",
	                        "",
	                        PylonMissile_Missile_AMRAAM_D_INT_x1,
	                        PylonMissile_Missile_AMRAAM_D_INT_x1,
	                        PylonMissile_Bomb_GBU12_x1,
	                        PylonMissile_Bomb_GBU12_x1
	                    };
	                };
	                class Cluster
	                {
	                    displayName = "$STR_A3_CfgVehicles_Pylons_Presets_Cluster0";
	                    attachment[] =
	                    {
	                        "",
	                        "",
	                        "",
	                        "",
	                        "",
	                        "",
	                        PylonMissile_Missile_AMRAAM_D_INT_x1,
	                        PylonMissile_Missile_AMRAAM_D_INT_x1,
	                        PylonMissile_1Rnd_BombCluster_01_F,
	                        PylonMissile_1Rnd_BombCluster_01_F
	                    };
	                };
	            };
	            class Bays
	            {
	                class BayLeft1
	                {
	                    bayOpenTime = 0.5;
	                    openBayWhenWeaponSelected = 0;
	                    autoCloseWhenEmptyDelay = 2;
	                };
	                class BayRight1
	                {
	                    bayOpenTime = 0.5;
	                    openBayWhenWeaponSelected = 0;
	                    autoCloseWhenEmptyDelay = 2;
	                };
	            };
			};
		};
	};
	class adfrc_f35_ejection_seat: adfrc_f35_ejection_seat_base
	{
		class SimpleObject
		{
			eden = false;
			animate[] = {};
			hide[] =
			{
	            zasleh,
	            "zadni svetlo",
	            "brzdove svetlo",
	            clan,
	            "podsvit pristroju",
	            poskozeni
			};
			verticalOffset = 0.002;
			verticalOffsetWorld = 0;
			init = "[this, '', []] call bis_fnc_initVehicle";
		};
		author = "AveryTheKitty (Arma 3 Aegis)";
		scope = protected;
		side = TWest;
		faction = ADFRC_F_MD;
		crew = ADFRC_MD_AMCU_Soldier_FighterPilot;
	};
};

class CfgNonAIVehicles
{
	class ProxyRetex;
	class Proxyadfrc_f35_wreck: ProxyRetex
	{
		model = "\ADF_Air\adfrc_f35\adfrc_f35_wreck.p3d";
		hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4","CamoGlass","camo_cockpit_1","camo_cockpit_2"};
	};
};
