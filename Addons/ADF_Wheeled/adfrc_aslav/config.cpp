class CfgPatches
{
	class adfrc_aslav
	{
		requiredVersion = 0.1;
		requiredAddons[]=
		{
			"A3_Data_F_AoW_Loadorder",
			"A3_Data_F_Mod_Loadorder",
			"ADF_Core",
			"ADF_Wheeled",
			"ADF_Weapons",
			"A3_Armor_F_EPB",
			"cba_main",
			"cba_xeh"
		};
		units[] = 
		{
			"adfrc_aslav_base",
			"adfrc_aslav_pc_base",
			
			"adfrc_aslav_25",
			"adfrc_aslav_25_mag58",
			"adfrc_aslav_pc",
		};
		weapons[]=
		{
			"adfrc_aslav_m242",
			"adfrc_aslav_mag58_coax",
			"adfrc_aslav_mag58_pintle",
			"adfrc_aslav_m2hbqcb",
			"adfrc_aslav_m2hbqcb_rws"
		};
		magazines[]=
		{
			"adfrc_aslav_m242_300rnd_25mm_HE",
			"adfrc_aslav_m242_120rnd_25mm_AP",
			"adfrc_aslav_200Rnd_762x51_Tracer",
		};
	};
};
#include "c_ammo.hpp"
#include "c_anims.hpp"
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
class VehicleSystemsTemplateLeftCommander: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightCommander: DefaultVehicleSystemsDisplayManagerRight
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
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateNV;
class SensorTemplateDataLink;
class DefaultEventHandlers;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class RCWSOptics;
class Optics_Armored;
class Optics_Commander_03: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class Optics_Gunner_MBT_03: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class CfgVehicles
{
	class Car;
	class Car_F: Car
	{
		class Sounds;
		class HitPoints
		{
			class HitBody;
			class HitEngine;
			class HitFuel;
			class HitHull;
			class HitLFWheel;
			class HitLBWheel;
			class HitLMWheel;
			class HitLF2Wheel;
			class HitRFWheel;
			class HitRBWheel;
			class HitRMWheel;
			class HitRF2Wheel;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
		};
	};
	class Wheeled_APC_F: Car_F
	{
		class ViewPilot;
		class ViewOptics;
		class ViewCargo;
		class Sounds: Sounds
		{
			class Engine;
			class Movement;
		};
		class CargoTurret;
		class NewTurret;
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewOptics;
				class ViewGunner;
				class Turrets
				{
					class CommanderOptics;
				};
			};
		};
		class AnimationSources;
		class EventHandlers;
	};
	class APC_Wheeled_03_base_F: Wheeled_APC_F
	{
	};
	class adfrc_aslav_base: APC_Wheeled_03_base_F
	{
		author = "Quiggs / Index";
		model = "\ADF_Wheeled\adfrc_aslav\adfrc_aslav_25.p3d";
		tf_hasLRradio=1;
		tf_RadioType="TFAR_rt1523g";
		mapSize=10.25;
		accuracy=0.25;
		brakeIdleSpeed=1.78;
		maxSpeed=100;
		fuelCapacity=30;
		wheelCircumference=3.275;
		normalSpeedForwardCoef=0.51999998;
		accelAidForceYOffset=-1.5;
		antiRollbarForceCoef=30;
		antiRollbarForceLimit=10;
		antiRollbarSpeedMin=15;
		antiRollbarSpeedMax=65;
		simulation="carx";
		dampersBumpCoef=3;
		differentialType="all_limited";
		frontRearSplit=0.5;
		frontBias=1.3;
		rearBias=1.3;
		centreBias=1.3;
		enginePower=205;
		peakTorque=603;
		maxOmega=293;
		minOmega=40;
		idleRpm=450;
		redRpm=2800;
		engineMOI=3.5;
		dampingRateFullThrottle=0.079999998;
		dampingRateZeroThrottleClutchEngaged=2;
		dampingRateZeroThrottleClutchDisengaged=0.050000001;
		torqueCurve[]=
		{
			
			{
				"(0/2300)",
				"(0/2260)"
			},
			
			{
				"(1200/2300)",
				"(1625/2260)"
			},
			
			{
				"(1400/2300)",
				"(2100/2260)"
			},
			
			{
				"(1500/2300)",
				"(2200/2260)"
			},
			
			{
				"(1550/2300)",
				"(2260/2260)"
			},
			
			{
				"(1600/2300)",
				"(2200/2260)"
			},
			
			{
				"(2300/2300)",
				"(1700/2260)"
			},
			
			{
				"(4700/2300)",
				"(0/2260)"
			}
		};
		changeGearMinEffectivity[]={0.5,0.15000001,0.97000003,0.97000003,0.97000003,0.97000003,0.97000003,0.98500001};
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-4.8400002,
				"N",
				0,
				"D1",
				3.5,
				"D2",
				2.2,
				"D3",
				1.42,
				"D4",
				1,
				"D5",
				0.82999998,
				"D6",
				0.58999997
			};
			TransmissionRatios[]=
			{
				"High",
				7.3000002
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
		};
		switchTime=0;
		latency=1;
		thrustDelay=0.15;
		clutchStrength=75;
		numberPhysicalWheels=8;
		class Wheels
		{
			class L1
			{
				side="left";
				suspTravelDirection[]={-0.125,-1,0};
				boneName="wheel_1_1_damper";
				steering=1;
				center="wheel_1_1_center";
				boundary="wheel_1_1_bound";
				width="0.33";
				mass=187.5;
				MOI=50;
				dampingRate=1;
				dampingRateDamaged=1;
				dampingRateDestroyed=1000;
				maxBrakeTorque=20000;
				maxHandBrakeTorque=5000;
				suspForceAppPointOffset="wheel_1_1_center";
				tireForceAppPointOffset="wheel_1_1_center";
				maxCompression=0.15;
				maxDroop=0.15;
				sprungMass=1800;
				springStrength=125000;
				springDamperRate=10000;
				longitudinalStiffnessPerUnitGravity=10000;
				latStiffX=10;
				latStiffY=100;
				frictionVsSlipGraph[]=
				{
					{0,1},
					{0.5,1},
					{1,1}
				};
			};
			class L2: L1
			{
				boneName="wheel_1_2_damper";
				steering=1;
				center="wheel_1_2_center";
				boundary="wheel_1_2_bound";
				suspForceAppPointOffset="wheel_1_2_center";
				tireForceAppPointOffset="wheel_1_2_center";
			};
			class L3: L1
			{
				boneName="wheel_1_3_damper";
				steering=0;
				center="wheel_1_3_center";
				boundary="wheel_1_3_bound";
				suspForceAppPointOffset="wheel_1_3_center";
				tireForceAppPointOffset="wheel_1_3_center";
			};
			class L4: L1
			{
				boneName="wheel_1_4_damper";
				steering=0;
				center="wheel_1_4_center";
				boundary="wheel_1_4_bound";
				suspForceAppPointOffset="wheel_1_4_center";
				tireForceAppPointOffset="wheel_1_4_center";
			};
			class R1: L1
			{
				side="right";
				suspTravelDirection[]={0.125,-1,0};
				boneName="wheel_2_1_damper";
				center="wheel_2_1_center";
				boundary="wheel_2_1_bound";
				suspForceAppPointOffset="wheel_2_1_center";
				tireForceAppPointOffset="wheel_2_1_center";
			};
			class R2: R1
			{
				boneName="wheel_2_2_damper";
				steering=1;
				center="wheel_2_2_center";
				boundary="wheel_2_2_bound";
				suspForceAppPointOffset="wheel_2_2_center";
				tireForceAppPointOffset="wheel_2_2_center";
			};
			class R3: R1
			{
				boneName="wheel_2_3_damper";
				steering=0;
				center="wheel_2_3_center";
				boundary="wheel_2_3_bound";
				suspForceAppPointOffset="wheel_2_3_center";
				tireForceAppPointOffset="wheel_2_3_center";
			};
			class R4: R1
			{
				boneName="wheel_2_4_damper";
				steering=0;
				center="wheel_2_4_center";
				boundary="wheel_2_4_bound";
				suspForceAppPointOffset="wheel_2_4_center";
				tireForceAppPointOffset="wheel_2_4_center";
			};
		};
		armor=300;
		armorStructural=5;
		armorLights=0.1;
		canFloat = 1;
		waterPPInVehicle=0;
		waterAngularDampingCoef=10;
		waterLinearDampingCoefY=2;
		waterLinearDampingCoefX=2;
		rudderForceCoef=1.5;
		rudderForceCoefAtMaxSpeed=0.30000001;
		crewVulnerable=1;
		crewCrashProtection=1.35;
		crewExplosionProtection=0.99949998;
		damageResistance=0.0071899998;
		driverAction="Driver_APC_Wheeled_03_cannon_F_out";
		driverInAction="Driver_APC_Wheeled_03_cannon_F_in";
		getInAction = "GetInHemttBack";
		getOutAction = "GetOutHigh";
		cargoGetInAction[] = {"GetInAMV_cargo"};
		cargoGetOutAction[] = {"GetOutLow"};
		cargoProxyIndexes[] = {1,2,3,4};
		getInProxyOrder[] = {1,2,3,4};
		cargoAction[]=
		{
			"passenger_apc_narrow_generic01",
			"passenger_apc_narrow_generic01",
			"passenger_apc_narrow_generic01_low",
			"passenger_apc_narrow_generic01_low",
		};
		hideWeaponsCargo=1;
		LODDriverTurnedOut=1100;
		LODDriverTurnedin=1201;
		LODDriverOpticsIn=1201;
		driverForceOptics=0;
		memoryPointDriverOptics="driverview";
		memoryPointDriverOutOptics="driverview";
		gunnerCompartments = "Compartment1";
		cargoIsCoDriver[]={0};
		forceHideDriver=0;
		viewDriverInExternal=1;
		viewDriverShadowAmb=1;
		viewDriverShadowDiff=1;
		driverOpticsEffect[] = {""};
		driverOpticsModel = "\a3\weapons_f\Reticle\Optics_Driver_01_F.p3d";
		incomingMissileDetectionSystem = 0;
		weapons[] = {"TruckHorn3"};
		unitInfoType="RscUnitInfoTank";
		driverLeftLegAnimName="pedal_brake";
		showNVGDriver=0;
		showNVGCommander=0;
		showNVGGunner=0;
		class ViewOptics: ViewOptics
		{
			initAngleX = 5;
			minAngleX = -75;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -150;
			maxAngleY = 150;
			initFov = 1;
			minFov=0.95;
			maxFov=1.5;
			maxMoveX = 0.2;
			maxMoveY = 0;
			maxMoveZ = 0;
			minMoveX = 0.2;
			minMoveY = 0;
			minMoveZ = 0;
			thermalMode[] = {0,1};
			visionMode[] = {"Normal","NVG"};
		};
		class ViewPilot: ViewPilot
		{
			initAngleX=-15;
			initAngleY=0;
			initFov=0.95;
			minFov=0.25;
			maxFov=1.25;
			minAngleX=-65;
			maxAngleX=85;
			minAngleY=-150;
			maxAngleY=150;
			minMoveX=-0.075;
			maxMoveX=0.075;
			minMoveY=-0.075;
			maxMoveY=0.015;
			minMoveZ=-0.075;
			maxMoveZ=0.075;
		};
		extCameraPosition[] = { 0, 2, -7 };
		cargoCompartments[] = {"Compartment1"};
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor = 1.6;
				material = -1;
				armorComponent="hit_hull";
				name="hit_hull_point";
				visual="hull_damage";
				passThrough = 1;
				minimalHit = 0.1;
				explosionShielding = 0.2;
				radius = 0.2;
			};
			class HitEngine: HitEngine
			{
				armor = 0.75;
				material = -1;
				armorComponent="hit_engine";
				name="hit_engine_point";
				visual="engine_damage";
				passThrough = 0.005;
				minimalHit = 0.1;
				explosionShielding = 0.5;
				radius = 0.3;
				class DestructionEffects
				{
					class QAVEngineSparks
					{
						simulation = "particles";
						type = "FireSparks";
						position = "hit_engine_effects";
						intensity = 2;
						interval = 1;
						lifeTime = 2.8;
					};
					class QAVSmoke
					{
						simulation = "particles";
						type = "ObjectDestructionSmoke1_2Small";
						position = "hit_engine_effects";
						intensity = 0.15;
						interval = 1;
						lifeTime = 5;
					};
					class Sound
					{
						simulation = "sound";
						position = "hit_engine_effects";
						intensity = 1;
						interval = 1;
						lifeTime = 1;
						type = "Fire";
					};
				};
			};
			class HitFuel: HitFuel
			{
				armor = 0.75;
				material = -1;
				armorComponent="hit_fuel";
				name="hit_fuel_point";
				visual="-";
				passThrough = 0.3;
				minimalHit = 0.1;
				explosionShielding = 0.6;
				radius = 0.2;
			};
			class HitLFWheel: HitLFWheel
			{
				radius = 0.33;
				visual = "wheel_1_1_hide";
				armorComponent = "wheel_1_1_hit";
				name="wheel_1_1_hit";
				armor = -250;
				minimalHit = -0.016;
				explosionShielding = 4;
				passThrough = 0;
			};
			class HitLF2Wheel: HitLF2Wheel
			{
				radius = 0.33;
				visual = "wheel_1_2_hide";
				armorComponent = "wheel_1_2_hit";
				name="wheel_1_2_hit";
				armor = -250;
				minimalHit = -0.016;
				explosionShielding = 4;
				passThrough = 0;
			};
			class HitLMWheel: HitLMWheel
			{
				radius = 0.33;
				visual = "wheel_1_3_hide";
				armorComponent = "wheel_1_3_hit";
				name="wheel_1_3_hit";
				armor = -250;
				minimalHit = -0.016;
				explosionShielding = 4;
				passThrough = 0;
			};
			class HitLBWheel: HitLBWheel
			{
				radius = 0.33;
				visual = "wheel_1_4_hide";
				armorComponent = "wheel_1_4_hit";
				name="wheel_1_4_hit";
				armor = -250;
				minimalHit = -0.016;
				explosionShielding = 4;
				passThrough = 0;
			};
			class HitRFWheel: HitRFWheel
			{
				radius = 0.33;
				visual = "wheel_2_1_hide";
				armorComponent = "wheel_2_1_hit";
				name="wheel_2_1_hit";
				armor = -250;
				minimalHit = -0.016;
				explosionShielding = 4;
				passThrough = 0;
			};
			class HitRF2Wheel: HitRF2Wheel
			{
				radius = 0.33;
				visual = "wheel_2_2_hide";
				armorComponent = "wheel_2_2_hit";
				name="wheel_2_2_hit";
				armor = -250;
				minimalHit = -0.016;
				explosionShielding = 4;
				passThrough = 0;
			};
			class HitRMWheel: HitRMWheel
			{
				radius = 0.33;
				visual = "wheel_2_3_hide";
				armorComponent = "wheel_2_3_hit";
				name="wheel_2_3_hit";
				armor = -250;
				minimalHit = -0.016;
				explosionShielding = 4;
				passThrough = 0;
			};
			class HitRBWheel: HitRBWheel
			{
				radius = 0.33;
				visual = "wheel_2_4_hide";
				armorComponent = "wheel_2_4_hit";
				name="wheel_2_4_hit";
				armor = -250;
				minimalHit = -0.016;
				explosionShielding = 4;
				passThrough = 0;
			};
		};
		hullExplosionDelay[] = { 10, 20 };
		class PlayerSteeringCoefficients // steering sensitivity configuration
		{
			turnIncreaseConst	= 0.2; // basic sensitivity value, higher value = faster steering
			turnIncreaseLinear	= 1; // higher value means less sensitive steering in higher speed, more sensitive in lower speeds
			turnIncreaseTime	= 1; // higher value means smoother steering around the center and more sensitive when the actual steering angle gets closer to the max. steering angle

			turnDecreaseConst	= 2.0; // basic caster effect value, higher value = the faster the wheels align in the direction of travel
			turnDecreaseLinear	= 5.0; // higher value means faster wheel re-centering in higher speed, slower in lower speeds
			turnDecreaseTime	= 0.0; // higher value means stronger caster effect at the max. steering angle and weaker once the wheels are closer to centered position

			maxTurnHundred		= 0.3; // coefficient of the maximum turning angle @ 100km/h; limit goes linearly to the default max. turn. angle @ 0km/h
		};
		wheelDamageThreshold=0.18000001;
		wheelDamageRadiusCoef=0.75;
		engineEffectSpeed = 5.0;
		dustFrontLeftPos="wheel_1_1_bound";
		dustFrontRightPos="wheel_2_1_bound";
		dustBackLeftPos="wheel_1_4_bound";
		dustBackRightPos="wheel_2_4_bound";
		explosionEffect = "FuelExplosionBig";	
		memoryPointsLeftWaterEffect = "waterEffectR";
		memoryPointsRightWaterEffect = "waterEffectL";
		memoryPointsLeftEngineEffect = "EngineEffectL";
		memoryPointsRightEngineEffect = "EngineEffectR";
		memoryPointTrackFLL="track_FLL";
		memoryPointTrackFLR="track_FLR";
		memoryPointTrackBLL="track_BLL";
		memoryPointTrackBLR="track_BLR";
		memoryPointTrackFRL="track_FRL";
		memoryPointTrackFRR="track_FRR";
		memoryPointTrackBRL="track_BRL";
		memoryPointTrackBRR="track_BRR";
		smokeLauncherGrenadeCount=8;
		smokeLauncherVelocity=14;
		smokeLauncherOnTurret=1;
		smokeLauncherAngle=100;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						body = "";
						gun = "";
						animationSourceBody = "";
						animationSourceGun = "";
						animationSourceHatch="HatchCommander";
						memoryPointGunnerOptics = "gunnerview";
						commanding = 3;
						minElev = -25;
						maxElev = 60;
						initElev = 0;
						minTurn = -180;
						maxTurn = 180;
						initTurn = 0;
						outGunnerMayFire = 0;
						inGunnerMayFire = 1;
						weapons[] = {"SmokeLauncher"};
						magazines[] = {"SmokeLauncherMag"};
						soundServo[] = {"","db-50",1};
						soundServoVertical[] = {"","db-50",1};
						gunnerAction = "Commander_MBT_01_cannon_F_out";
						gunnerInAction = "Commander_MBT_01_cannon_F_in";
						gunnerGetInAction = "GetInHigh";
						gunnerGetOutAction = "GetOutHigh";
						gunnerOpticsModel = "\a3\weapons_f\empty.p3d";
						gunnerOutOpticsModel= "\a3\weapons_f\empty.p3d";
						gunnerOpticsEffect[] = {};
						turretInfoType = "RscOptics_Offroad_01";
						hideWeaponsGunner = 1;
						isPersonTurret = 1;
						personTurretAction = "vehicle_turnout_2";
						minOutElev = -20;
						maxOutElev = 45;
						initOutElev = 0;
						minOutTurn = -100;
						maxOutTurn = 120;
						initOutTurn = 0;
						usepip = 2;
						turretFollowFreeLook = 2;
						stabilizedInAxes = 3;
						LODTurnedIn = 1202;
						LODTurnedOut = 1100;
						LODOpticsOut = 1100;
						LODOpticsIn = 1100;
						viewGunnerShadowAmb = 1;
						viewGunnerShadowDiff = 1;
						gunnerHasFlares = 1;
						viewGunnerInExternal = 1;
						startEngine = 0;
						primaryGunner = 0;
						primaryObserver = 1;
						class ViewGunner: ViewGunner
						{
							initAngleX = 0;
							initAngleY = 20;
							initFov = 0.9;
							minFov = 0.25;
							maxFov = 1.25;
							minAngleX = -65;
							maxAngleX = 85;
							minAngleY = -150;
							maxAngleY = 150;
							minMoveX = -0.075;
							maxMoveX = 0.075;
							minMoveY = -0.075;
							maxMoveY = 0.075;
							minMoveZ = -0.075;
							maxMoveZ = 0.1;
						};
						class ViewOptics: ViewOptics
						{
							initAngleX = 0;
							minAngleX = -30;
							maxAngleX = 30;
							initAngleY = 0;
							minAngleY = -100;
							maxAngleY = 100;
							initFov = 0.31;
							minFov = 0.034;
							maxFov = 0.31;
							visionMode[] = {"Normal","TI"};
							thermalMode[] = {2,3};
						};
						class OpticsIn: Optics_Gunner_MBT_03
						{
							class Periscope : Wide
							{
								gunnerOpticsModel = "\a3\weapons_f\Reticle\Optics_Driver_01_F.p3d";
								camPos = "commanderview_periscope";
								camDir = "";
								initFov = "0.4/0.5";
								visionMode[] = {"Normal","nvg"};
							};
							class M252daysight: Medium
							{
								gunnerOpticsModel = "ADF_Wheeled\adfrc_aslav\Optics_M242.p3d";
								gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
								camPos = "gunnerview_optics";
								camDir = "gunnerview_optics_dir";
								visionMode[] = {"Normal","nvg"};
								initFov = 0.08;
							};
							class Wide: Wide 
							{
								gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
								camPos = "gunnerview_optics";
								camDir = "gunnerview_optics_dir";
								visionMode[] = {"TI"};
								thermalMode[] = {2,3};
								thermalResolution[] = { 600 };
							};
							class Narrow: Narrow 
							{
								gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
								camPos = "gunnerview_optics";
								camDir = "gunnerview_optics_dir";
								visionMode[] = {"TI"};
								thermalMode[] = {2,3};
								thermalResolution[] = { 600 };
							};
						};
						class HitPoints
						{
							class HitComTurret
							{
								armor = 0.5;
								material = -1;
								armorComponent = "hit_com_turret";
								name = "hit_com_turret_point";
								visual = "commander_turret";
								passThrough = 0;
								minimalHit = 0.05;
								explosionShielding = 1;
								radius = 0.15;
								isTurret = 1;
							};
							class HitComGun
							{
								armor = 0.1;
								material = -1;
								armorComponent = "hit_com_gun";
								name = "hit_com_gun_point";
								visual = "commander_gun";
								passThrough = 0;
								minimalHit = 0.05;
								explosionShielding = 1;
								radius = 0.15;
								isGun = 1;
							};
						};
					};
				};
				weapons[] = 
				{
					"adfrc_aslav_M242",
					"adfrc_aslav_mag58_coax"
				};
				magazines[] = 
				{
					"adfrc_aslav_m242_300rnd_25mm_HE",
					"adfrc_aslav_m242_120rnd_25mm_AP",
					"adfrc_aslav_200Rnd_762x51_Tracer",
					"adfrc_aslav_200Rnd_762x51_Tracer",
					"adfrc_aslav_200Rnd_762x51_Tracer",
					"adfrc_aslav_200Rnd_762x51_Tracer",
					"adfrc_aslav_200Rnd_762x51_Tracer",
				};
				minElev = -10;
				maxElev = 50;
				initElev = 0;
				minTurn = -360;
				maxTurn = 360;
				initTurn = 0;
				minOutElev=-60;
				maxOutElev=50;
				initOutElev=0;
				minOutTurn=-135;
				maxOutTurn=135;
				maxHorizontalRotSpeed = "((360/10)/45)";
				maxVerticalRotSpeed = 0.4;
				gunnerAction = "vehicle_turnout_1";
				gunnerInAction = "Commander_MBT_01_cannon_F_in";
				personTurretAction = "vehicle_turnout_2";
				animationSourceBody = "MainTurret";
				animationSourceGun = "MainGun";
				animationSourceHatch = "hatchGunner";
				isPersonTurret = 1;
				gunnerGetInAction = "GetInHigh";
				gunnerGetOutAction = "GetOutHigh";
				gunnerCompartments = "Compartment1";
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_02_F";
				gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
				soundServo[] = {"A3\Sounds_F\vehicles\armor\APC\noises\servo_APC_gunner",0.39810717,1,30};
				soundServoVertical[] = {"A3\Sounds_F\vehicles\armor\APC\noises\servo_APC_comm",0.56234133,1,30};
				turretInfoType="RscOptics_Offroad_01";
				hideWeaponsGunner = 1;
				lockWhenDriverOut = 1;
				discreteDistance[] = {0,100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,};
				discreteDistanceInitIndex = 0;
				ace_fcs_enabled = 0;
				ace_fcs_minDistance = 0;
				ace_fcs_maxDistance = 2000;
				ace_fcs_distanceInterval = 5;
				LODTurnedIn = 1100;
				LODTurnedOut = 1100;
				LODOpticsOut = 1100;
				LODOpticsIn = 1100;
				usepip = 2;
				turretFollowFreeLook = 2;
				memoryPointGun[] = {"usti hlavne2"};
				gunBeg = "konec hlavne";
				gunEnd = "usti hlavne";
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				gunnerForceOptics = 1;
				forceHideGunner = 0;
				memoryPointGunnerOptics="gunnerview";
				memoryPointGunnerOutOptics = "gunnerviewOut";
				viewGunnerInExternal = 1;
				commanding = 2;
				primaryGunner = 1;
				primaryObserver = 0;
				stabilizedInAxes = 3;
				selectionFireAnim="25mm_muzzle_hide";
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.3;
					minFov = 0.5;
					maxFov = 1;
				};
				class OpticsIn: Optics_Gunner_MBT_03
				{
					class Periscope : Wide
					{
						gunnerOpticsModel = "\a3\weapons_f\Reticle\Optics_Driver_01_F.p3d";
						camPos = "gunnerview_periscope";
						camDir = "gunnerview_periscope_dir";
						initFov = "0.4/0.5";
						visionMode[] = {"Normal","nvg"};
					};
					class M252daysight: Medium
					{
						gunnerOpticsModel = "ADF_Wheeled\adfrc_aslav\Optics_M242.p3d";
						gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
						camPos = "gunnerview_optics";
						camDir = "gunnerview_optics_dir";
						visionMode[] = {"Normal","nvg"};
						initFov = 0.08;
					};
					class Wide: Wide 
					{
						gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
						camPos = "gunnerview_optics";
						camDir = "gunnerview_optics_dir";
						visionMode[] = {"TI"};
						thermalMode[] = {2,3};
						thermalResolution[] = { 600 };
					};
					class Narrow: Narrow 
					{
						gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
						camPos = "gunnerview_optics";
						camDir = "gunnerview_optics_dir";
						visionMode[] = {"TI"};
						thermalMode[] = {2,3};
						thermalResolution[] = { 600 };
					};
				};
				class HitPoints: HitPoints
				{
					class HitTurret
					{
						armor = 0.8;
						material = -1;
						armorComponent = "hit_mainturret";
						name = "hit_mainturret_point";
						visual = "mainturret_damage";
						passThrough = 0;
						minimalHit = 0.1;
						explosionShielding = 0.2;
						radius = 0.25;
						isTurret = 1;
					};
					class HitGun
					{
						armor = 0.6;
						material = -1;
						armorComponent = "hit_maingun";
						name = "hit_maingun_point";
						visual = "maingun_damage";
						passThrough = 0;
						minimalHit = 0.1;
						explosionShielding = 0.4;
						radius = 0.2;
						isGun = 1;
					};
				};
			};
			class CargoGunner_1: CargoTurret
			{
				weapons[]={};
				magazines[]={};
				proxyType="CPGunner";
				proxyIndex=2;
				gunnerName="Left Hatch Gunner";
				primaryGunner=0;
				primaryObserver=0;
				gunnerOpticsShowCursor=0;
				body="";
				gun="";
				animationSourceBody="";
				animationSourceGun="";
				animationSourceHatch="hatchleft";
				soundServo[]=
				{
					"",
					"db-50",
					1
				};
				startEngine=0;
				hideWeaponsGunner=1;
				allowLauncherOut=1;
				gunnerGetInAction="GetInAMV_cargo";
				gunnerGetOutAction="GetOutLow";
				gunnerAction="vehicle_turnout_2";
				gunnerInAction="passenger_apc_narrow_generic01";
				ispersonturret=1;
				dontCreateAI=1;
				minOutElev=-10;
				maxOutElev=40;
				initOutElev=0;
				minOutTurn=-60;
				maxOutTurn=80;
				initOutTurn=0;
				minElev=-15;
				maxElev=50;
				initElev=0;
				minTurn=-120;
				maxTurn=120;
				initTurn=0;
				commanding=-1;
				viewGunnerInExternal=1;
				gunnerOpticsModel="";
				gunnerOutOpticsColor[]={0,0,0,1};
				gunnerForceOptics=0;
				gunnerOutForceOptics=0;
				gunnerOutOpticsShowCursor=0;
				memoryPointGunnerOptics="";
				gunnerOpticsEffect[]={};
				outGunnerMayFire=1;
				inGunnerMayFire=0;
				stabilizedInAxes=0;
				LODTurnedOut=-1;
				LODTurnedIn=1000;
				LODOpticsIn=1000;
				LODOpticsOut=-1;
				gunnerCompartments="Compartment1";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
			};
			class CargoGunner_2: CargoGunner_1
			{
				proxyIndex=3;
				gunnerName="Right Hatch Gunner";
				animationSourceHatch="hatchright";
				gunnerGetInAction="GetInAMV_cargo";
				gunnerGetOutAction="GetOutLow";
				gunnerAction="vehicle_turnout_2";
				gunnerInAction="passenger_apc_narrow_generic01";
				hideWeaponsGunner=1;
				minOutElev=-10;
				maxOutElev=40;
				initOutElev=0;
				minOutTurn=-60;
				maxOutTurn=80;
				initOutTurn=0;
				minElev=-15;
				maxElev=50;
				initElev=0;
				minTurn=-120;
				maxTurn=120;
				initTurn=0;
			};
		};
		class AnimationSources
		{
			class convoylights
			{
				source="user";
				animPeriod=0;
				initPhase=0;
			};
			class convoylights_hide_brakelights
			{
				source="user";
				animPeriod=0;
				initPhase=1;
			};
			class proxy
			{
				source="user";
				animPeriod=0.1;
				initPhase=0;
			};
			class waterSkid
			{
				source="door";
				initPhase=0;
				animPeriod=3;
			};
			class doorright
			{
				source="door";
				initPhase=0;
				animPeriod=2;
			};
			class doorleft
			{
				source="door";
				initPhase=0;
				animPeriod=2;
			};
			class wheelcarrier
			{
				source="door";
				initPhase=0;
				animPeriod=2;
			};
			class HideTurret
			{
				source="user";
				initPhase=0;
				animPeriod=0.001;
			};
			class m240_hide_turret
			{
				source="user";
				initPhase=0;
				animPeriod=0;
			};
			class 25mm_muzzle_hide
			{
				source="reload";
				weapon="adfrc_aslav_M242";
			};
			class 25mm_recoil
			{
				source="reload";
				weapon="adfrc_aslav_M242";
			};
			class coax_muzzle_rot
			{
				source="ammorandom";
				weapon="adfrc_aslav_mag58_coax";
			};
			class coax_muzzle_hide
			{
				source="reload";
				weapon="adfrc_aslav_mag58_coax";
			};
			// --- Garage Selections
			class hull_net
			{
				DisplayName="Camo Net - Hull";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class turret_net
			{
				DisplayName="Camo Net - Turret";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class sparewheel
			{
				DisplayName="Spare Wheel";
				source="user";
				animPeriod=0;
				initPhase=1;
				author="ADFRC";
			};
			class duke
			{
				DisplayName="AN/VLQ-12 Duke";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class sensors
			{
				DisplayName="EW IED Sensors";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
				forceAnimatePhase = 1;
				forceAnimate[] = {"sensors_trimvane",1};
			};
			class sensors_trimvane
			{
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};	
			
			/* Old garage selections
			class slat_armor
			{
				DisplayName="Slat Armour";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class slat_armor2
			{
				DisplayName="Slat Armour Turret";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			*/
			class HitLFWheel
			{
				source = "Hit";
				hitpoint = "HitLFWheel";
				raw = 1;
			};
			class HitLF2Wheel: HitLFWheel
			{
				hitpoint = "HitLF2Wheel";
			};
			class HitRFWheel: HitLFWheel
			{
				hitpoint = "HitRFWheel";
			};
			class HitRF2Wheel: HitLFWheel
			{
				hitpoint = "HitRF2Wheel";
			};
			class HitLBWheel: HitLFWheel
			{
				hitpoint = "HitLBWheel";
			};
			class HitLMWheel: HitLFWheel
			{
				hitpoint = "HitLMWheel";
			};
			class HitRBWheel: HitLFWheel
			{
				hitpoint = "HitRBWheel";
			};
			class HitRMWheel: HitLFWheel
			{
				hitpoint = "HitRMWheel";
			};
			class HitEngine_src
			{
				source = "Hit";
				hitpoint = "HitEngine";
				raw = 1;
			};
			class HitFuel_src
			{
				source = "Hit";
				hitpoint = "HitFuel";
				raw = 1;
			};
			class HitHull_src
			{
				source = "Hit";
				hitpoint = "HitHull";
				raw = 1;
			};
			class HitMainGun_src
			{
				source = "Hit";
				hitpoint = "HitGun";
				raw = 1;
			};
			class HitTurret_src
			{
				source = "Hit";
				hitpoint = "HitTurret";
				raw = 1;
			};
			class HitComTurret_src
			{
				source="Hit";
				hitpoint="HitComTurret";
				raw=1;
			};
		};
		class UserActions
		{
			class open_reardoors //--------- This is disabled until a better interior is modelled
			{
				userActionID = 50;
				displayName = "Open Rear Doors";
				radius = 5;
				aiMaxRange = 5;
				showIn3D = 17;
				priority = 2;
				position = "driverview";
				onlyForPlayer = 0;
				condition = "((this DoorPhase 'doorright') == 0) AND Alive (this) and driver this == player";
				statement = "this animateDoor ['doorright', 1];";
			};
			class close_reardoors: open_reardoors
			{
				userActionID = 51;
				displayName = "Close Rear Doors";
				condition = "((this DoorPhase 'doorright') > 0) AND Alive (this) and driver this == player";
				statement = "this animateDoor ['doorright', 0];";
			};
			
			class convoylights_on
			{
				userActionID = 50;
				displayName = "Enable Convoy Lights";
				radius = 5;
				aiMaxRange = 5;
				showIn3D = 17;
				priority = 2;
				position ="driverview";
				hideOnUse = 1;
				onlyForPlayer = 0;
				condition = "(driver this == player) AND  {this animationPhase 'convoylights' < 0.5}";
				statement = "this animateSource ['convoylights',1]; this animateSource ['convoylights_hide_brakelights',0];";
			};
			class convoylights_off : convoylights_on
			{
				displayName = "Disable Convoy Lights";
				condition = "(driver this == player) AND  {this animationPhase 'convoylights' > 0.5}";
				statement = "this animateSource ['convoylights',0]; this animateSource ['convoylights_hide_brakelights',1];";
			};
		};
		destrType = "DestructEngine";
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull1.rvmat",
				"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull1_damage.rvmat",
				"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25_destruct.rvmat",
				"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull2.rvmat",
				"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull2_damage.rvmat",
				"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25_destruct.rvmat",
				"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25turret.rvmat",
				"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25turret_damage.rvmat",
				"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25_destruct.rvmat",
				"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25susp.rvmat",
				"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25susp_damage.rvmat",
				"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25_destruct.rvmat",
				"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25wheel.rvmat",
				"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25wheel_damage.rvmat",
				"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25_destruct.rvmat",
				"ADF_Wheeled\adfrc_aslav\data\textures\standard\aslavparts.rvmat",
				"ADF_Wheeled\adfrc_aslav\data\textures\standard\aslavparts_damage.rvmat",
				"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25_destruct.rvmat",
			};
		};
		hiddenSelections[]=
		{
			lav25hull1,
			lav25hull2,
			lav25turret,
			lav25susp,
			lav25wheel,
			lav25extmesh,
			aslavparts,
			labels,
			labels_door_l,
			labels_door_r,
		};
		hiddenSelectionsTextures[]=
		{
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull1_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull2_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25turret_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25susp_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25wheel_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25extmesh_ca.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\aslavparts_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\labels\labels_01.paa",
			"ADF_Wheeled\adfrc_aslav\data\labels\labels_01.paa",
			"ADF_Wheeled\adfrc_aslav\data\labels\labels_01.paa",
		};
		class TextureSources
		{
			class Standard
			{
				displayName="Standard";
				author="ADFRC_Quiggs";
				textures[]=
				{
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull1_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull2_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25turret_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25susp_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25wheel_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25extmesh_ca.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\aslavparts_co.paa",
				};
			};
			
			class un
			{
				displayName="United Nations";
				author="ADFRC_Quiggs";
				textures[]=
				{
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull1_un_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull2_un_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25turret_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25susp_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25wheel_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25extmesh_ca.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\aslavparts_co.paa",
				};
			};
		};
		class Exhausts
		{
			class Exhaust1
			{
				position = "exhaust_pos";
				direction = "exhaust_dir";
				effect = "ExhaustsEffectAMV";
			};
			class Exhaust2
			{
				position = "exhaust_pos";
				direction = "exhaust_dir";
				effect = "ExhaustEffectHEMTT";
			};
		};
		class NVGMarkers
		{
			class NVGMarker01
			{
				name = "nvg_marker";
				color[] = {0.03,0.003,0.003,1};
				ambient[] = {0.003,0.0003,0.0003,1};
				brightness = 0.001;
				blinking = 1;
			};
		};
		class Reflectors
		{
			class Headlight_Left
			{
				position = "Headlight_Left_pos";
				direction = "Headlight_Left_dir";
				hitpoint = "Headlight_Left";
				selection = "Light_l";
				innerAngle = 60;
				outerAngle = 130;
				color[] = {1,0.75,0.525};
				ambient[] = {1,0.75,0.525};
				intensity = 750;
				size = 5;
				coneFadeCoef = 10;
				useFlare = 1;
				flareSize = 1;
				flareMaxDistance = 250;
				dayLight = 0;
				class Attenuation
				{
					start = 1.0;
					constant = 0;
					linear = 0;
					quadratic = 0.05;
					hardLimitStart = 25;
					hardLimitEnd = 150;
				};
			};
			class Headlight_Right: Headlight_Left
			{
				position = "Headlight_Right_pos";
				direction = "Headlight_Right_dir";
				hitpoint = "Headlight_Right";
				selection = "Light_r";
			};
		};
		aggregateReflectors[] = {{"Left","Left2","Left3","Right","Right2","Right3"}};
		selectionFireAnim = "";
		class RenderTargets
		{
			class commander_display
			{
				class rendertarget1 
				{
					pointDirection   = "commander_pip_dir";
					pointPosition    = "commander_pip_pos";
					fov              = 0.7;
					renderQuality    = 1;
					renderVisionMode = 4;
				};
			};
		};
		class compartmentsLights
		{
			class Comp1
			{
				class Light1
				{
					point = "int_light_1";
					color[] = {250,30,35};
					ambient[] = {50,0,0};
					intensity = 10;
					size = 0;
					useFlare = 0;
					flareSize = 0;
					flareMaxDistance = 0;
					dayLight = 0;
					blinking = 0;
					class Attenuation
					{
						start = 0;
						constant = 0;
						linear = 1;
						quadratic = 70;
						hardLimitStart = 0.15;
						hardLimitEnd = 1.15;
					};
				};
				class Light2: Light1
				{
					point = "int_light_2";
				};
				class Light3: Light1
				{
					point = "int_light_3";
				};
			};
		};
		class TransportMagazines
		{
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellRed
			{
				magazine = "SmokeShellRed";
				count = 2;
			};
			class _xx_ADFRC_30Rnd_aug_ef88
			{
				magazine = "ADFRC_30Rnd_aug_ef88";
				count = 4;
			};
		};
		class TransportWeapons
		{
			class _xx_arifle_ADFRC_Preset_EF88C_Black_Spectr
			{
				weapon = "ADFRC_Preset_EF88C_Black_Spectr";
				count = 2;
			};
		};
		class TransportItems
		{
			class _xx_FirstAidKit
			{
				name = "FirstAidKit";
				count = 4;
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 5;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
		};
		slingLoadCargoMemoryPoints[] = {"SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
		transportSoldier = 4;
		class Attributes
		{
			class PlatoonMarkings
			{
				//--- Mandatory properties
				displayName = "Vehicle Callsigns";
				tooltip = "The vehicle callsign shown on the sides and back of the vehicle";
				property = "ADFRC_PlatoonMarkings"; //Unique config property name saved in SQM
				control = "Combo"; //UI control base class displayed in Edit Attributes window, points to Cfg3DEN >> Attributes

				//Expression called when applying the attribute in Eden and at the scenario start
				//The expression is called twice - first for data validation, and second for actual saving
				//Entity is passed as _this, value is passed as _value
				//%s is replaced by attribute config name. It can be used only once in the expression
				//In MP scenario, the expression is called only on server.
				expression = "_this setVariable ['%s', _value, true]; private _i = _value; if (_value isEqualTo 0) then {_i = floor (random 22) + 1}; private _f = if (_i < 10) then {format ['\adf_wheeled\adfrc_aslav\data\labels\labels_0%1.paa', _i]} else {format ['\adf_wheeled\adfrc_aslav\data\labels\labels_%1.paa', _i]}; {_this setObjectTextureGlobal [_x, _f]} forEach [7, 8, 9];";

				//Expression called when custom property is undefined yet (i.e., when setting the attribute for the first time)
				//Entity (unit, group, marker, comment etc.) is passed as _this
				//Returned value is the default value
				//Used when no value is returned, or when it is of other type than NUMBER, STRING or ARRAY
				//Custom attributes of logic entities (e.g., modules) are saved always, even when they have default value
				defaultValue = 0;
				
				class Values 
				{
					class One {
						name = "Bullryder | 7B";
						tooltip = "Select this callsign";
						value = 1;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_01.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_01.paa";
					};
					class Two: One {
						name = "Cerebral | 3A";
						value = 2;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_02.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_02.paa";
					};
					class Three: One {
						name = "Circle Work | 5A";
						value = 3;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_03.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_03.paa";
					};
					class Four: One {
						name = "Bollocks | 11A";
						value = 4;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_04.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_04.paa";
					};
					class Five: One {
						name = "Comalgo | 2C";
						value = 5;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_05.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_05.paa";
					};
					class Six: One {
						name = "Sandgroper | 15C";
						value = 6;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_06.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_06.paa";
					};
					class Seven: One {
						name = "Courage | 12C";
						value = 7;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_07.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_07.paa";
					};
					class Eight: One {
						name = "Atomic | 13A";
						value = 8;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_08.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_08.paa";
					};
					class Nine: One {
						name = "Cannibal | 33B";
						value = 9;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_09.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_09.paa";
					};
					class Ten: One {
						name = "Bourbon | 23B";
						value = 10;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_10.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_10.paa";
					};
					class Eleven: One {
						name = "Cant Help Ya | 21A";
						value = 11;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_11.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_11.paa";
					};
					class Twelve: One {
						name = "ANZAC | 11A";
						value = 12;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_12.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_12.paa";
					};
					class Thirteen: One {
						name = "Angry Bird | 9A";
						value = 13;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_13.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_13.paa";
					};
					class Fourteen: One {
						name = "Atlas | 13B";
						value = 14;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_14.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_14.paa";
					};
					class Fifteen: One {
						name = "Achilles | 22C";
						value = 15;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_15.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_15.paa";
					};
					class Sixteen: One {
						name = "Boomer | 31A";
						value = 16;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_16.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_16.paa";
					};
					class Seventeen: One {
						name = "Big Papi | 23C";
						value = 17;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_17.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_17.paa";
					};
					class Eighteen: One {
						name = "Blame | 21B";
						value = 18;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_18.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_18.paa";
					};
					class Nineteen: One {
						name = "Boxer | 2F";
						value = 19;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_19.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_19.paa";
					};
					class Twenty: One {
						name = "Hammersley | 0C";
						value = 20;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_20.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_20.paa";
					};
					class TwentyOne: One {
						name = "Hold My Brew | 0F";
						value = 21;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_21.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_21.paa";
					};
					class TwentyTwo: One {
						name = "Akula | 1D";
						value = 22;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_22.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_22.paa";
					};
					class Zero: One {
						name = "Random";
						tooltip = "Choose the markings randomly.";
						value = 0;
					};
				};
				
				//--- Optional properties
				unique = 0; // When 1, only one entity of the type can have the value in the mission (used for example for variable names or player control)
				validate = "number"; // Validate the value before saving. If the value is not of given type e.g. "number", the default value will be set. Can be "none", "expression", "condition", "number" or "variable"
				condition = "_this isKindOf 'adfrc_aslav_base'"; // Condition for attribute to appear (see the table below)
				typeName = "NUMBER"; // Defines data type of saved value, can be STRING, NUMBER or BOOL. Used only when control is "Combo", "Edit" or their variants
			};
		};
	};
	class adfrc_aslav_pc_base: adfrc_aslav_base
	{
		author="Quiggs";
		model = "\ADF_Wheeled\adfrc_aslav\adfrc_aslav_pc.p3d";
		//editorPreview = "\ADF_Wheeled\adfrc_aslav_crv.jpg";
		//picture="ADF_Wheeled\adfrc_aslav\data\ui\boxercrv.paa";
		icon="ADF_Wheeled\adfrc_aslav\data\ui\icon_aslav_pc_ca.paa";
		faction="ADFRC_F_MD";
		crew="ADFRC_MD_AMCU_Soldier_Crewman";
		typicalCargo[] = {"ADFRC_MD_AMCU_Soldier_CavalryScout"};
		transportSoldier = 6;
		cargoProxyIndexes[] = {1,2,3,4,5,6};
		getInProxyOrder[] = {1,2,3,4,5,6};
		cargoGetInAction[] = {"getInLow"};
		cargoAction[] = 
		{
			"passenger_apc_narrow_generic01",
			"passenger_apc_narrow_generic01",
			"passenger_apc_narrow_generic01",
			"passenger_generic01_foldhands",
			"passenger_generic01_foldhands",
			"passenger_apc_narrow_generic01",
		};
		smokeLauncherGrenadeCount=4;
		smokeLauncherVelocity=14;
		smokeLauncherOnTurret=0;
		smokeLauncherAngle=60;
		hiddenSelections[]=
		{
			"lav25hull1",
			"lav25hull2",
			"lav25bison",
			"lav25turret",
			"lav25susp",
			"lav25wheel",
			"lav25extmesh",
			"aslavparts",
			"labels",
			"labels_ramp",
		};
		hiddenSelectionsTextures[]=
		{
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull1_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull2_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25bison_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25turret_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25susp_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25wheel_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25extmesh_ca.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\aslavparts_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\labels\labels_00.paa",
			"ADF_Wheeled\adfrc_aslav\data\labels\labels_00.paa",
		};
		class TextureSources
		{
			class Standard
			{
				displayName="Standard";
				author="ADFRC_Quiggs";
				textures[]=
				{
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull1_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull2_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25bison_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25turret_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25susp_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25wheel_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25extmesh_ca.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\aslavparts_co.paa",
				};
			};
			class un
			{
				displayName="United Nations";
				author="ADFRC_Quiggs";
				textures[]=
				{
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull1_un_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull2_un_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25bison_un_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25turret_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25susp_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25wheel_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25extmesh_ca.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\aslavparts_co.paa",
				};
			};
		};
		class Turrets: Turrets
		{
			class M2Turret: NewTurret
			{
				class Turrets{};
				body="commanderturret";
				gun="commandergun";
				gunBeg = "m2_muzzle";
				gunEnd = "m2_chamber";
				gunnerName="Commander";
				proxyType="CPCommander";
				animationSourceHatch="HatchCommander";
				animationSourceBody = "obsTurret";
				animationSourceGun = "obsGun";
				proxyIndex=1;
				turretFollowFreeLook = 0;
				weapons[]=
				{
					"adfrc_aslav_m2hbqcb",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"100Rnd_127x99_mag_Tracer_Red",
					"100Rnd_127x99_mag_Tracer_Red",
					"100Rnd_127x99_mag_Tracer_Red",
					"100Rnd_127x99_mag_Tracer_Red",
					"100Rnd_127x99_mag_Tracer_Red",
					"100Rnd_127x99_mag_Tracer_Red",
					"100Rnd_127x99_mag_Tracer_Red",
					"100Rnd_127x99_mag_Tracer_Red",
					"100Rnd_127x99_mag_Tracer_Red",
					"100Rnd_127x99_mag_Tracer_Red",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
					"SmokeLauncherMag"
				};
				soundServo[]=
				{
					"A3\sounds_f\dummysound",
					0.0099999998,
					1,
					10
				};
				commanding=3;
				minElev=-25;
				initElev=0;
				maxElev=30;
				minOutElev=-30;
				maxOutElev=50;
				initOutElev=0;
				minOutTurn=-145;
				maxOutTurn=125;
				gunnerRightHandAnimName="m2_shake";
				gunnerLeftHandAnimName="m2_shake";
				gunnerLeftLegAnimName="commanderturret";
				gunnerRightLegAnimName="commanderturret";
				gunnerAction = "gunner_lsv_02";
				lockWhenDriverOut = 0;
				isPersonTurret = 0;
				gunnerInAction = "Commander_APC_tracked_01_crv_in";
				gunnerGetInAction="GetInHemttBack";
				gunnerGetOutAction="GetOuthigh";
				viewGunnerInExternal=1;
				castGunnerShadow=1;
				forceHideGunner=0;
				gunnerForceOptics=0;
				inGunnerMayFire=1;
				outGunnerMayFire=1;
				discreteDistance[]={0,100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex=0;
				turretInfoType="RscWeaponZeroing";
				memoryPointGunnerOptics="commanderview";
				memoryPointGunnerOutOptics="eye";
				memoryPointsGetInGunner="pos commander";
				memoryPointsGetInGunnerDir="pos commander dir";
				gunnerOpticsModel="\a3\weapons_f\Reticle\Optics_Driver_01_F.p3d";
				gunnerOutOpticsModel="\A3\weapons_f\reticle\optics_empty";
				gunnerCompartments="Compartment1";
				selectionFireAnim="m2_flash";
				stabilizedInAxes=0;
				primaryGunner=0;
				primaryObserver=1;
				usePip=0;
				LODTurnedIn = 1202;
				LODTurnedOut = 1;
				LODOpticsIn = 1;
				LODOpticsOut = 1;
				startEngine=0;
				disableSoundAttenuation=1;
				class ViewGunner
				{
					initAngleX = 0;
					initAngleY = 0;
					initFov = 0.9;
					minFov = 0.25;
					maxFov = 1.25;
					minAngleX = -65;
					maxAngleX = 85;
					minAngleY = -150;
					maxAngleY = 150;
					minMoveX = -0.075;
					maxMoveX = 0.075;
					minMoveY = -0.075;
					maxMoveY = 0.075;
					minMoveZ = 1;
					maxMoveZ = 0.1;
				};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.9;
					minFov = 0.25;
					maxFov = 0.9;
				};
				class TurnIn
                {
                    limitsArrayTop[] = {{-0, 0}};
                    limitsArrayBottom[] = {{-0, 0}};
                };
				class HitPoints
				{
					class HitTurret
					{
						armor=0.60000002;
						material=-1;
						name="vez";
						visual="vez";
						passThrough=1;
						minimalHit=0.2;
						explosionShielding=1;
						radius=0.20;
					};
					class HitGun
					{
						armor=0.60000002;
						material=-1;
						name="zbran";
						visual="";
						passThrough=0;
						minimalHit=0.2;
						explosionShielding=1;
						radius=0.20;
					};
				};
			};
			class CargoTurret_01: CargoTurret
			{
				weapons[]={};
				magazines[]={};
				body="";
				gun="";
				animationSourceBody="";
				animationSourceGun="";
				primaryGunner=0;
				primaryObserver=0;
				gunnerOpticsShowCursor=0;
				showAsCargo=1;
				gunnerAction="vehicle_turnout_1";
				gunnerInAction="passenger_apc_narrow_generic01";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerName="Left Hatch Gunner";
				animationSourceHatch="Hatchleft";
				viewGunnerInExternal=1;
				startEngine=0;
				hideWeaponsGunner=1;
				allowLauncherOut=1;
				proxyType="CPGunner";
				proxyIndex=1;
				isPersonTurret=1;
				dontCreateAI=1;
				maxElev=150;
				minElev=-80;
				maxTurn=90;
				minTurn=-90;
				minOutElev=-20;
				maxOutElev=50;
				initOutElev=0;
				minOutTurn=-90;
				maxOutTurn=90;
				ejectDeadGunner=0;
				enabledByAnimationSource="";
				usepip=0;
				commanding=-0;
				outGunnerMayFire=1;
				inGunnerMayFire=0;
				stabilizedInAxes=0;
				LODTurnedIn = 1200;
				LODTurnedOut = 1000;
				LODOpticsIn = 1000;
				LODOpticsOut = 1000;
				gunnerOpticsModel="";
				gunnerOutOpticsColor[]={0,0,0,1};
				gunnerForceOptics=0;
				gunnerOutForceOptics=0;
				gunnerOutOpticsShowCursor=0;
				soundServo[]=
				{
					"",
					"db-50",
					1
				};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -90;
					maxAngleX = 90;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 1;
					minFov = 0.5;
					maxFov = 1;
				};
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerInAction="passenger_apc_narrow_generic01";
				gunnerName="Right Hatch Gunner";
				animationSourceHatch="Hatchright";
				proxyType="CPGunner";
				proxyIndex=2;
				maxElev=150;
				minElev=-80;
				maxTurn=90;
				minTurn=-90;
				minOutElev=-20;
				maxOutElev=50;
				initOutElev=0;
				minOutTurn=-90;
				maxOutTurn=90;
			};
			class SquadLeaderSeat: CargoTurret_02
			{
				gunnerAction="vehicle_turnout_1";
				gunnerInAction="passenger_generic01_foldhands";
				gunnerName="Squad Leader";
				proxyType="CPCargo";
				proxyIndex=7;
				forceHideGunner = 1;
				isPersonTurret=0;
			};
		};
		class AnimationSources: AnimationSources
		{
			class convoylights
			{
				source="user";
				animPeriod=0;
				initPhase=0;
			};
			class convoylights_hide_brakelights
			{
				source="user";
				animPeriod=0;
				initPhase=1;
			};
			class sparewheels
			{
				DisplayName="Spare Wheels";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class sparewheel
			{
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class commanderturret_mount
			{
				source="user";
				initPhase=1;
				animPeriod=1;
			};
			class bison_rws_mount
			{
				source="user";
				initPhase=0;
				animPeriod=0;
			};
			class interior_pc
			{
				source="user";
				initPhase=1;
				animPeriod=1;
			};
			class interior_ambulance
			{
				source="user";
				initPhase=0;
				animPeriod=0;
			};
			class interior_surveillance
			{
				source="user";
				initPhase=0;
				animPeriod=0;
			};
			class exterior_surveillance
			{
				source="user";
				initPhase=0;
				animPeriod=0;
			};
			class exterior_command
			{
				source="user";
				initPhase=0;
				animPeriod=0;
			};
			class ramp_open
			{
				source = "door";
				animPeriod = 5;
				initPhase = 0;
				sound = "ServoRampSound_2";
			};
			class muzzle_source_m2
			{
				source="reload";
				weapon="adfrc_aslav_m2hbqcb";
			};
			class muzzle_source_rot_m2
			{
				source="ammorandom";
				weapon="adfrc_aslav_m2hbqcb";
			};
			class m2_fire_source
			{
				source="reload";
				weapon="adfrc_aslav_m2hbqcb";
			};
			class m2_reload_source
			{
				source="reloadmagazine";
				weapon="adfrc_aslav_m2hbqcb";
			};
			class m2_Revolving_source
			{
				source="revolving";
				weapon="adfrc_aslav_m2hbqcb";
			};
			class tools
			{
				DisplayName="Tool Set";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
				forceAnimatePhase = 1;
				forceAnimate[] = {"rack_tools",1};
			};
			class fak
			{
				DisplayName="Interior First Aid Kit";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class ammo_f
			{
				DisplayName="Ammo Boxs 1";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class ammo_r
			{
				DisplayName="Ammo Boxs 2";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class fuel_l
			{
				DisplayName="Left Fuel Jerrys";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
				forceAnimatePhase = 1;
				forceAnimate[] = {"rack_l",1};
			};
			class fuel_r
			{
				DisplayName="Right Fuel Jerrys";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
				forceAnimatePhase = 1;
				forceAnimate[] = {"rack_r",1};
			};
			class hull_jerry
			{
				DisplayName="Hull Jerry";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class spinalboard
			{
				DisplayName="Spinalboard";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class stretcher
			{
				DisplayName="Stretcher";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
				forceAnimatePhase = 1;
				forceAnimate[] = {"rack_r",1};
			};
			class shackles_front
			{
				DisplayName="Shackles Front";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class shackles_rear
			{
				DisplayName="Shackles Rear";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class rack_l
			{
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};	
			class rack_r
			{
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};	
			class rack_tools
			{
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class equipment1
			{
				DisplayName="Field Equipment 1 (Roof)";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class equipment1_l
			{
				DisplayName="Field Equipment 1 (Left)";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
				forceAnimatePhase = 1;
				forceAnimate[] = {"rack_l",1};
			};
			class equipment1_r
			{
				DisplayName="Field Equipment 1 (Right)";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
				forceAnimatePhase = 1;
				forceAnimate[] = {"rack_r",1};
			};
		};
		class UserActions
		{
			class Ramp_Open
			{
				userActionID=50;
				displayName = "Lower Ramp";
				radius=5;
				showIn3D=17;
				priority=1;
				position="driverview";
				onlyForPlayer=0;
				condition="((this DoorPhase 'ramp_open') == 0) AND Alive (this) and driver this == player";
				statement="this animateDoor ['ramp_open', 1];";
			};
			class Ramp_Close: Ramp_Open
			{
				userActionID=51;
				displayName="Raise Ramp";
				condition="(driver this == player) AND  {this animationPhase 'ramp_open' > 0.5} AND {Alive(this)}";
				statement="this animateDoor [""ramp_open"", 0];";
			};
			
			class convoylights_on
			{
				userActionID = 50;
				displayName = "Enable Convoy Lights";
				radius = 5;
				aiMaxRange = 5;
				showIn3D = 17;
				priority = 2;
				position ="driverview";
				hideOnUse = 1;
				onlyForPlayer = 0;
				condition = "(driver this == player) AND  {this animationPhase 'convoylights' < 0.5}";
				statement = "this animateSource ['convoylights',1]; this animateSource ['convoylights_hide_brakelights',0];";
			};
			class convoylights_off : convoylights_on
			{
				displayName = "Disable Convoy Lights";
				condition = "(driver this == player) AND  {this animationPhase 'convoylights' > 0.5}";
				statement = "this animateSource ['convoylights',0]; this animateSource ['convoylights_hide_brakelights',1];";
			};
		};
		class compartmentsLights
		{
			class Comp1
			{
				class Light1
				{
					point = "int_light_1";
					color[] = {250,30,35};
					ambient[] = {50,0,0};
					intensity = 20;
					size = 0;
					useFlare = 0;
					flareSize = 0;
					flareMaxDistance = 0;
					dayLight = 0;
					blinking = 0;
					class Attenuation
					{
						start = 0;
						constant = 0;
						linear = 1;
						quadratic = 70;
						hardLimitStart = 0.15;
						hardLimitEnd = 1.15;
					};
				};
				class Light2: Light1
				{
					point = "int_light_2";
				};
				class Light3: Light1
				{
					point = "int_light_3";
				};
				class Light4: Light1
				{
					point = "int_light_4";
				};
			};
		};
		class Attributes
		{
			class PlatoonMarkings
			{
				//--- Mandatory properties
				displayName = "Vehicle Callsigns";
				tooltip = "The vehicle callsign shown on the sides and back of the vehicle";
				property = "ADFRC_PlatoonMarkings"; //Unique config property name saved in SQM
				control = "Combo"; //UI control base class displayed in Edit Attributes window, points to Cfg3DEN >> Attributes

				//Expression called when applying the attribute in Eden and at the scenario start
				//The expression is called twice - first for data validation, and second for actual saving
				//Entity is passed as _this, value is passed as _value
				//%s is replaced by attribute config name. It can be used only once in the expression
				//In MP scenario, the expression is called only on server.
				expression = "_this setVariable ['%s', _value, true]; private _i = _value; if (_value isEqualTo 0) then {_i = floor (random 22) + 1}; private _f = if (_i < 10) then {format ['\adf_wheeled\adfrc_aslav\data\labels\labels_0%1.paa', _i]} else {format ['\adf_wheeled\adfrc_aslav\data\labels\labels_%1.paa', _i]}; {_this setObjectTextureGlobal [_x, _f]} forEach [8, 9];";

				//Expression called when custom property is undefined yet (i.e., when setting the attribute for the first time)
				//Entity (unit, group, marker, comment etc.) is passed as _this
				//Returned value is the default value
				//Used when no value is returned, or when it is of other type than NUMBER, STRING or ARRAY
				//Custom attributes of logic entities (e.g., modules) are saved always, even when they have default value
				defaultValue = 0;
				
				class Values 
				{
					class One {
						name = "Bullryder | 7B";
						tooltip = "Select this callsign";
						value = 1;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_01.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_01.paa";
					};
					class Two: One {
						name = "Cerebral | 3A";
						value = 2;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_02.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_02.paa";
					};
					class Three: One {
						name = "Circle Work | 5A";
						value = 3;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_03.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_03.paa";
					};
					class Four: One {
						name = "Bollocks | 11A";
						value = 4;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_04.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_04.paa";
					};
					class Five: One {
						name = "Comalgo | 2C";
						value = 5;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_05.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_05.paa";
					};
					class Six: One {
						name = "Sandgroper | 15C";
						value = 6;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_06.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_06.paa";
					};
					class Seven: One {
						name = "Courage | 12C";
						value = 7;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_07.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_07.paa";
					};
					class Eight: One {
						name = "Atomic | 13A";
						value = 8;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_08.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_08.paa";
					};
					class Nine: One {
						name = "Cannibal | 33B";
						value = 9;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_09.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_09.paa";
					};
					class Ten: One {
						name = "Bourbon | 23B";
						value = 10;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_10.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_10.paa";
					};
					class Eleven: One {
						name = "Cant Help Ya | 21A";
						value = 11;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_11.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_11.paa";
					};
					class Twelve: One {
						name = "ANZAC | 11A";
						value = 12;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_12.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_12.paa";
					};
					class Thirteen: One {
						name = "Angry Bird | 9A";
						value = 13;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_13.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_13.paa";
					};
					class Fourteen: One {
						name = "Atlas | 13B";
						value = 14;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_14.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_14.paa";
					};
					class Fifteen: One {
						name = "Achilles | 22C";
						value = 15;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_15.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_15.paa";
					};
					class Sixteen: One {
						name = "Boomer | 31A";
						value = 16;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_16.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_16.paa";
					};
					class Seventeen: One {
						name = "Big Papi | 23C";
						value = 17;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_17.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_17.paa";
					};
					class Eighteen: One {
						name = "Blame | 21B";
						value = 18;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_18.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_18.paa";
					};
					class Nineteen: One {
						name = "Boxer | 2F";
						value = 19;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_19.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_19.paa";
					};
					class Twenty: One {
						name = "Hammersley | 0C";
						value = 20;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_20.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_20.paa";
					};
					class TwentyOne: One {
						name = "Hold My Brew | 0F";
						value = 21;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_21.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_21.paa";
					};
					class TwentyTwo: One {
						name = "Akula | 1D";
						value = 22;
						picture = "\adf_wheeled\adfrc_aslav\data\labels\labels_22.paa";
						pictureRight = "\adf_wheeled\adfrc_aslav\data\labels\labels_22.paa";
					};
					class Zero: One {
						name = "Random";
						tooltip = "Choose the markings randomly.";
						value = 0;
					};
				};

				//--- Optional properties
				unique = 0; // When 1, only one entity of the type can have the value in the mission (used for example for variable names or player control)
				validate = "number"; // Validate the value before saving. If the value is not of given type e.g. "number", the default value will be set. Can be "none", "expression", "condition", "number" or "variable"
				condition = "_this isKindOf 'adfrc_aslav_base'"; // Condition for attribute to appear (see the table below)
				typeName = "NUMBER"; // Defines data type of saved value, can be STRING, NUMBER or BOOL. Used only when control is "Combo", "Edit" or their variants
			};
		};
		class EventHandlers: EventHandlers
		{
			//init = "(_this select 0) execVM ""\adf_wheeled\adfrc_aslav\script\labelInitPC.sqf""; if (local (_this select 0)) then {[(_this select 0), """", [], false] call bis_fnc_initVehicle;};";
		};
	};
	class adfrc_aslav_25: adfrc_aslav_base
	{
		displayName="ASLAV-25";
		author="Quiggs";
		editorPreview = "\ADF_Wheeled\adfrc_aslav\adfrc_aslav_25.jpg";
		//picture="ADF_Wheeled\adfrc_aslav\data\ui\boxercrv.paa";
		icon="ADF_Wheeled\adfrc_aslav\data\ui\icon_aslav25_ca.paa";
		side = 1;
		scope=2;
		scopeCurator=2;
		faction="ADFRC_F_MD";
		crew="ADFRC_MD_AMCU_Soldier_Crewman";
		typicalCargo[] = {"ADFRC_MD_AMCU_Soldier_CavalryScout"};
		
	};
	class adfrc_aslav_25_mag58: adfrc_aslav_base
	{
		displayName="ASLAV-25 (Mag58)";
		author="Quiggs";
		editorPreview = "\ADF_Wheeled\adfrc_aslav\adfrc_aslav_25_mag58.jpg";
		side = 1;
		scope=2;
		scopeCurator=2;
		faction="ADFRC_F_MD";
		crew="ADFRC_MD_AMCU_Soldier_Crewman";
		typicalCargo[] = {"ADFRC_MD_AMCU_Soldier_CavalryScout"};
		class RenderTargets
		{
			class commander_display
			{
				renderTarget="rendertarget1";
				class rendertarget1 
				{
					pointDirection   = "commander_pip_dir";
					pointPosition    = "commander_pip_pos";

					fov              = 0.15;
					renderQuality    = 2;
					renderVisionMode = 2;
				};
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class CommanderTurret_mag58: NewTurret
					{
						commanding=3;
						gunnerName="Commander";
						gunBeg = "usti hlavne3";
						gunEnd = "konec hlavne3";
						body = "commanderturret2";
						gun = "commandergun2";
						animationSourceBody = "obsTurret";
						animationSourceGun = "obsGun";
						animationSourceHatch="HatchCommander";
						memoryPointGunnerOutOptics = "eye";
						memoryPointGunnerOptics = "commanderview_periscope";
						minElev=-20;
						maxElev=40;
						initElev=0;
						minTurn=-57.5;
						maxTurn=57.5;
						initTurn=0;
						initOutTurn=0;
						optics=1;
						weapons[] = 
						{
							"adfrc_aslav_mag58_pintle",
							"SmokeLauncher",
						};
						magazines[] = 
						{
							"adfrc_aslav_200Rnd_762x51_Tracer",
							"adfrc_aslav_200Rnd_762x51_Tracer",
							"adfrc_aslav_200Rnd_762x51_Tracer",
							"adfrc_aslav_200Rnd_762x51_Tracer",
							"adfrc_aslav_200Rnd_762x51_Tracer",
							"adfrc_aslav_200Rnd_762x51_Tracer",
							"adfrc_aslav_200Rnd_762x51_Tracer",
							"adfrc_aslav_200Rnd_762x51_Tracer",
							"adfrc_aslav_200Rnd_762x51_Tracer",
							"SmokeLauncherMag",
						};
						proxyType="CPCommander";
						proxyIndex=1;
						soundServo[] = {"","db-50",1};
						soundServoVertical[] = {"","db-50",1};
						gunnerLeftHandAnimName = "m240_shake";
						gunnerRightHandAnimName = "m240_shake";
						gunnerLeftLegAnimName = "commanderfeet";
						gunnerRightLegAnimName = "commanderfeet";
						gunnerAction = "adfrc_aslav25_commander_mg_out";
						gunnerInAction = "Commander_MBT_01_cannon_F_in";
						gunnerGetInAction = "GetInHigh";
						gunnerGetOutAction = "GetOutHigh";
						gunnerOpticsModel = "\a3\weapons_f\Reticle\Optics_Driver_01_F.p3d";
						gunnerOutOpticsModel= "\a3\weapons_f\empty.p3d";
						gunnerOpticsEffect[] = {};
						turretInfoType = "RscOptics_Offroad_01";
						hideWeaponsGunner=1;
						forceHideGunner = 0;
						isPersonTurret = 0;
						InGunnerMayFire = 1;
						outGunnerMayFire = 1;
						gunnerForceOptics = 0;
						usepip = 0;
						LODTurnedIn = 1202;
						LODTurnedOut = 1100;
						LODOpticsOut = 1100;
						LODOpticsIn = 1100;
						turretFollowFreeLook = 0;
						animationSourceStickX = "com_turret_control_x";
						animationSourceStickY = "com_turret_control_y";
						viewGunnerShadowAmb = 1;
						viewGunnerShadowDiff = 1;
						gunnerOutOpticsShowCursor=0;
						gunnerOpticsShowCursor=0;
						discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200};
						discreteDistanceInitIndex=2;
						primaryGunner=0;
						primaryObserver=1;
						stabilizedInAxes = 0;
						maxHorizontalRotSpeed = 1.8;
						maxVerticalRotSpeed = 1.8;
						gunnerHasFlares = 1;
						viewGunnerInExternal = 1;
						showCrewAim = 1;
						startEngine = 0;
						class TurnIn
						{
							limitsArrayTop[] = {{-0, 0}};
							limitsArrayBottom[] = {{-0, 0}};
						};
						class ViewGunner: ViewGunner
						{
							initAngleX=0;
							initAngleY=0;
							initFov=0.95;
							minFov=0.25;
							maxFov=1.25;
							minAngleX=-65;
							maxAngleX=85;
							minAngleY=-150;
							maxAngleY=150;
							minMoveX=-0.075;
							maxMoveX=0.075;
							minMoveY=-0.075;
							maxMoveY=0.075;
							minMoveZ=-0.075;
							maxMoveZ=0.075;
						};
						class ViewOptics: ViewOptics
						{
							initAngleX = 0;
							minAngleX = -30;
							maxAngleX = 30;
							initAngleY = 0;
							minAngleY = -100;
							maxAngleY = 100;
							initFov = 0.9;
							minFov = 0.25;
							maxFov = 0.9;
						};
						class OpticsIn{};
						class HitPoints
						{
							class HitComTurret
							{
								armor = 0.5;
								material = -1;
								armorComponent = "hit_com_turret";
								name = "hit_com_turret_point";
								visual = "commander_turret";
								passThrough = 0;
								minimalHit = 0.05;
								explosionShielding = 1;
								radius = 0.15;
								isTurret = 1;
							};
							class HitComGun
							{
								armor = 0.1;
								material = -1;
								armorComponent = "hit_com_gun";
								name = "hit_com_gun_point";
								visual = "commander_gun";
								passThrough = 0;
								minimalHit = 0.05;
								explosionShielding = 1;
								radius = 0.15;
								isGun = 1;
							};
						};
					};
				};
			};
			class CargoGunner_1: CargoGunner_1
			{};
			class CargoGunner_2: CargoGunner_2
			{};
		};
		class AnimationSources: AnimationSources
		{
			class m240_hide_turret
			{
				source="user";
				initPhase=1;
				animPeriod=1;
			};
			class commandersmg_muzzle_rot
			{
				source="ammorandom";
				weapon="adfrc_aslav_mag58_pintle";
			};
			class commandersmg_muzzle_hide
			{
				source="reload";
				weapon="adfrc_aslav_mag58_pintle";
			};
			class m240_reload_source
			{
				source="reloadmagazine";
				weapon="adfrc_aslav_mag58_pintle";
			};
			class m240_fire_source
			{
				source="reload";
				weapon="adfrc_aslav_mag58_pintle";
			};
			class m240_Revolving_source
			{
				source="revolving";
				weapon="adfrc_aslav_mag58_pintle";
			};
			class m240_opticrail_spectr
			{
				//DisplayName="Hide Spectr Optic";
				DisplayName="";
				source="user";
				useSource=1;
				animPeriod=0.01;
				initPhase=1;
				author="ADFRC";
				forceAnimatePhase = 0;
				forceAnimate[] = {"m240_opticrail_xps3",1,};
			};
			class m240_opticrail_xps3
			{
				//DisplayName="Hide XPS3 Optic";
				DisplayName="";
				source="user";
				useSource=1;
				animPeriod=0.01;
				initPhase=1;
				author="ADFRC";
				forceAnimatePhase = 0;
				forceAnimate[] = {"m240_opticrail_spectr",1,};
			};
		};
	};
	class adfrc_aslav_pc: adfrc_aslav_pc_base
	{
		displayName="ASLAV-PC (M2HB)";
		author="Quiggs";
		editorPreview = "\ADF_Wheeled\adfrc_aslav\adfrc_aslav_pc.jpg";
		//picture="ADF_Wheeled\adfrc_aslav\data\ui\boxercrv.paa";
		side=1;
		scope=2;
		scopeCurator=2;
		faction="ADFRC_F_MD";
		crew="ADFRC_MD_AMCU_Soldier_Crewman";
		typicalCargo[] = {"ADFRC_MD_AMCU_Soldier_CavalryScout"};
	};
	class adfrc_aslav_pc_mag58: adfrc_aslav_pc
	{
		scope=0;
		displayName="ASLAV-PC (M2HB/Mag58)";
		author="Quiggs";
		//editorPreview = "\ADF_Wheeled\adfrc_aslav\adfrc_aslav_pc_mag58.jpg";
	};
	class adfrc_aslav_pc_rws: adfrc_aslav_pc
	{
		displayName="ASLAV-PC (M2HB-RWS)";
		author="Quiggs";
		editorPreview = "\ADF_Wheeled\adfrc_aslav\adfrc_aslav_pc_rws.jpg";
		class Turrets: Turrets
		{
			class M2RWSTurret: NewTurret
			{
				body="m151_turret";
				gun="m151_cradle";
				gunBeg = "m2_rws_muzzle";
				gunEnd = "m2_rws_chamber";
				gunnerName="Commander";
				proxyType="CPCommander";
				animationSourceHatch="HatchCommander";
				animationSourceBody = "m151_turret";
				animationSourceGun = "m151_cradle";
				weapons[]=
				{
					"adfrc_aslav_m2hbqcb_rws",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"100Rnd_127x99_mag_Tracer_Red",
					"100Rnd_127x99_mag_Tracer_Red",
					"100Rnd_127x99_mag_Tracer_Red",
					"100Rnd_127x99_mag_Tracer_Red",
					"100Rnd_127x99_mag_Tracer_Red",
					"100Rnd_127x99_mag_Tracer_Red",
					"100Rnd_127x99_mag_Tracer_Red",
					"100Rnd_127x99_mag_Tracer_Red",
					"100Rnd_127x99_mag_Tracer_Red",
					"100Rnd_127x99_mag_Tracer_Red",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
					"SmokeLauncherMag"
				};
				soundServo[] = {"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP01",0.17782794,1,10};
				soundServoVertical[] = {"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP01",0.17782794,1,10};
				stabilizedInAxes = 3;
				inGunnerMayFire=1;
				outGunnerMayFire=1;
				gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_02_F";
				memoryPointGunnerOptics="m151_optic_pos";
				turretInfoType = "RscOptics_crows";
				selectionFireAnim="m2_rws_flash";
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex = 2;
				minElev=-25;
				initElev=0;
				maxElev=30;
				minOutElev=-30;
				maxOutElev=50;
				initOutElev=0;
				minOutTurn=-145;
				maxOutTurn=125;
				gunnerRightHandAnimName="m2_shake";
				gunnerLeftHandAnimName="m2_shake";
				gunnerLeftLegAnimName="commanderturret";
				gunnerRightLegAnimName="commanderturret";
				gunnerAction = "gunner_lsv_02";
				isPersonTurret = 1;
				gunnerInAction = "gunner_MRAP_01";
				gunnerForceOptics=0;
				usePip = 1;
				LODTurnedIn = 1202;
				LODTurnedOut = 1;
				LODOpticsIn = 1;
				LODOpticsOut = 1;
				class ViewOptics: RCWSOptics{};
				class HitPoints
				{
					class HitRWSTurret
					{
						armor=0.60000002;
						material=-1;
						name="vez";
						visual="vez";
						passThrough=1;
						minimalHit=0.2;
						explosionShielding=1;
						radius=0.20;
					};
					class HitRWSGun
					{
						armor=0.60000002;
						material=-1;
						name="zbran";
						visual="";
						passThrough=0;
						minimalHit=0.2;
						explosionShielding=1;
						radius=0.20;
					};
				};
			};
			class CargoTurret_01: CargoTurret
			{
				weapons[]={};
				magazines[]={};
				body="";
				gun="";
				animationSourceBody="";
				animationSourceGun="";
				primaryGunner=0;
				primaryObserver=0;
				gunnerOpticsShowCursor=0;
				showAsCargo=1;
				gunnerAction="vehicle_turnout_1";
				gunnerInAction="passenger_apc_narrow_generic01";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				gunnerName="Left Hatch Gunner";
				animationSourceHatch="Hatchleft";
				viewGunnerInExternal=1;
				startEngine=0;
				hideWeaponsGunner=1;
				allowLauncherOut=1;
				proxyType="CPGunner";
				proxyIndex=1;
				isPersonTurret=1;
				dontCreateAI=1;
				maxElev=150;
				minElev=-80;
				maxTurn=90;
				minTurn=-90;
				minOutElev=-20;
				maxOutElev=50;
				initOutElev=0;
				minOutTurn=-90;
				maxOutTurn=90;
				ejectDeadGunner=0;
				enabledByAnimationSource="";
				usepip=0;
				commanding=-0;
				outGunnerMayFire=1;
				inGunnerMayFire=0;
				stabilizedInAxes=0;
				LODTurnedIn = 1200;
				LODTurnedOut = 1000;
				LODOpticsIn = 1000;
				LODOpticsOut = 1000;
				gunnerOpticsModel="";
				gunnerOutOpticsColor[]={0,0,0,1};
				gunnerForceOptics=0;
				gunnerOutForceOptics=0;
				gunnerOutOpticsShowCursor=0;
				soundServo[]=
				{
					"",
					"db-50",
					1
				};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -90;
					maxAngleX = 90;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 1;
					minFov = 0.5;
					maxFov = 1;
				};
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerInAction="passenger_apc_narrow_generic01";
				gunnerName="Right Hatch Gunner";
				animationSourceHatch="Hatchright";
				proxyType="CPGunner";
				proxyIndex=2;
				maxElev=150;
				minElev=-80;
				maxTurn=90;
				minTurn=-90;
				minOutElev=-20;
				maxOutElev=50;
				initOutElev=0;
				minOutTurn=-90;
				maxOutTurn=90;
			};
			class SquadLeaderSeat: CargoTurret_02
			{
				gunnerAction="vehicle_turnout_1";
				gunnerInAction="passenger_generic01_foldhands";
				gunnerName="Squad Leader";
				proxyType="CPCargo";
				proxyIndex=7;
				forceHideGunner = 1;
				isPersonTurret=0;
			};
		};
		class AnimationSources: AnimationSources
		{
			class commanderturret_mount
			{
				source="user";
				initPhase=0;
				animPeriod=0;
			};
			class bison_rws_mount
			{
				source="user";
				initPhase=1;
				animPeriod=1;
			};
			class muzzle_source_m2_rws
			{
				source="reload";
				weapon="adfrc_aslav_m2hbqcb_rws";
			};
			class muzzle_source_rot_m2_rws
			{
				source="ammorandom";
				weapon="adfrc_aslav_m2hbqcb_rws";
			};
			class ReloadAnim_m2_rws
			{
				source="reload";
				weapon="adfrc_aslav_m2hbqcb_rws";
			};
			class reloadmagazine_m2_rws
			{
				source="reloadmagazine";
				weapon="adfrc_aslav_m2hbqcb_rws";
			};
			class Revolving_m2_rws
			{
				source="revolving";
				weapon="adfrc_aslav_m2hbqcb_rws";
			};
		};
		
	};
	class adfrc_aslav_a: adfrc_aslav_pc
	{
		displayName="ASLAV-A";
		icon="ADF_Wheeled\adfrc_aslav\data\ui\icon_aslav_a_ca.paa";
		author="Quiggs";
		editorPreview = "\ADF_Wheeled\adfrc_aslav\adfrc_aslav_a.jpg";
		vehicleClass = "Support";
		attendant = 1;
		transportSoldier = 2;
		cargoProxyIndexes[] = {8,9};
		getInProxyOrder[] = {8,9};
		cargoAction[]=
		{
			"passenger_injured_medevac_truck02",
			"Patient_Van_02_Medevac_Front",
		};
		hiddenSelections[]=
		{
			"lav25hull1",
			"lav25hull2",
			"lav25bison",
			"lav25turret",
			"lav25susp",
			"lav25wheel",
			"lav25extmesh",
			"aslavparts",
			"labels",
		};
		hiddenSelectionsTextures[]=
		{
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull1_amb_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull2_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25bison_amb_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25turret_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25susp_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25wheel_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25extmesh_ca.paa",
			"ADF_Wheeled\adfrc_aslav\data\textures\standard\aslavparts_co.paa",
			"ADF_Wheeled\adfrc_aslav\data\labels\labels_06.paa",
		};
		class AnimationSources: AnimationSources
		{
			class interior_pc
			{
				source="user";
				initPhase=0;
				animPeriod=0;
			};
			class interior_ambulance
			{
				source="user";
				initPhase=1;
				animPeriod=1;
			};
		};
		class Turrets: Turrets
		{
			class M2Turret: M2Turret{};
			class ParamedicSeat: SquadLeaderSeat { gunnerName="Medical Attendant"; };
		};
		class TransportItems: TransportItems
		{
			class _xx_FirstAidKit
			{
				name = "FirstAidKit";
				count = 10;
			};
		};
		class TextureSources
		{
			class Standard
			{
				displayName="Standard";
				author="ADFRC_Quiggs";
				textures[]=
				{
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull1_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull2_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25bison_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25turret_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25susp_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25wheel_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25extmesh_ca.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\aslavparts_co.paa",
				};
			};
			class ambulance
			{
				displayName="Ambulance";
				author="ADFRC_Quiggs";
				textures[]=
				{
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull1_amb_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull2_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25bison_amb_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25turret_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25susp_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25wheel_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25extmesh_ca.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\aslavparts_co.paa",
				};
			};
			class un
			{
				displayName="United Nations";
				author="ADFRC_Quiggs";
				textures[]=
				{
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull1_un_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25hull2_un_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25bison_un_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25turret_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25susp_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25wheel_co.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\lav25extmesh_ca.paa",
					"ADF_Wheeled\adfrc_aslav\data\textures\standard\aslavparts_co.paa",
				};
			};
		};
	};
	class adfrc_aslav_c: adfrc_aslav_pc
	{
		displayName="ASLAV-C";
		icon="ADF_Wheeled\adfrc_aslav\data\ui\icon_aslav_c_ca.paa";
		author="Quiggs";
		editorPreview = "\ADF_Wheeled\adfrc_aslav\adfrc_aslav_c.jpg";
		reportOwnPosition = 1;
		reportRemoteTargets = 1;
		receiveRemoteTargets = 1;
		transportSoldier = 0;
		tf_hasLRradio=1;
		tf_RadioType="TFAR_rt1523g";
		tf_range=20000;
		tf_subtype="airborne";
		class Turrets: Turrets
		{
			class M2Turret: M2Turret{};
			class CargoTurret_01: CargoTurret_01{};
			class CargoTurret_02: CargoTurret_02 
			{ 
				gunnerName="Radio Operator"; 
				proxyIndex = 3;
				forceHideGunner = 1;
				isPersonTurret=0;
				class Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
					{
						defaultDisplay="MinimapDisplay";
						class Components
						{
							class EmptyDisplay { componentType="EmptyDisplayComponent"; };
							class MinimapDisplay { componentType="MinimapDisplayComponent"; resource="RscCustomInfoMiniMap"; };
							class UAVDisplay { componentType="UAVFeedDisplayComponent"; };
							class SensorDisplay { componentType="SensorsDisplayComponent"; range[]={10000,7500,5000,2500,1000}; resource="RscCustomInfoSensors"; };
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
					{
						defaultDisplay="SensorDisplay";
						class Components
						{
							class EmptyDisplay { componentType="EmptyDisplayComponent"; };
							class MinimapDisplay { componentType="MinimapDisplayComponent"; resource="RscCustomInfoMiniMap"; };
							class UAVDisplay { componentType="UAVFeedDisplayComponent"; };
							class SensorDisplay { componentType="SensorsDisplayComponent"; range[]={10000,7500,5000,2500,1000}; resource="RscCustomInfoSensors"; };
						};
					};
					class SensorsManagerComponent
					{
						class Components
						{
							class DataLinkSensorComponent: SensorTemplateDataLink {};
						};
					};
				};
			};
			class CargoTurret_03: CargoTurret_02
			{
				gunnerName="Warfare Officer";
				gunnerInAction="passenger_generic01_foldhands";
				proxyType = "CPGunner";
				proxyIndex = 4;
				forceHideGunner = 1;
				isPersonTurret=0;
				class ViewGunner
				{
					initAngleX = -25;
					initAngleY = 0;
					initFov = 0.9;
					minFov = 0.25;
					maxFov = 1.25;
					minAngleX = -65;
					maxAngleX = 85;
					minAngleY = -150;
					maxAngleY = 150;
					minMoveX = -0.075;
					maxMoveX = 0.075;
					minMoveY = -0.075;
					maxMoveY = 0.075;
					minMoveZ = 1;
					maxMoveZ = 0.1;
				};
				/*class Components
				{
					class SensorsManagerComponent
					{
						class Components
						{
							class LaserSensorComponent : SensorTemplateLaser
							{
								class AirTarget
								{
									minRange=1;
									maxRange=5000;
									objectDistanceLimitCoef=1;
									viewDistanceLimitCoef=1;
									nightRangeCoef = 0.5;
								};
								class GroundTarget
								{
									minRange=1;
									maxRange=5000;
									objectDistanceLimitCoef=1;
									viewDistanceLimitCoef=1;
									nightRangeCoef = 0.5;
								};
								typeRecognitionDistance=5000;
								maxTrackableSpeed = 1e10;
								angleRangeHorizontal=150;
								angleRangeVertical=180;
								animDirection="cameraturret";
								aimDown=0;
							};
							class DataLinkSensorComponent: SensorTemplateDataLink
							{
							};
						};
					};
					class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
					{
						defaultDisplay="MinimapDisplay";
						class Components
						{
							class EmptyDisplay
							{
								componentType="EmptyDisplayComponent";
							};
							class MinimapDisplay
							{
								componentType="MinimapDisplayComponent";
								resource="RscCustomInfoMiniMap";
							};
							class UAVDisplay
							{
								componentType="UAVFeedDisplayComponent";
							};
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={10000,7500,5000,2500,1000,};
								resource="RscCustomInfoSensors";
							};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
					{
						defaultDisplay="SensorDisplay";
						class Components
						{
							class EmptyDisplay
							{
								componentType="EmptyDisplayComponent";
							};
							class MinimapDisplay
							{
								componentType="MinimapDisplayComponent";
								resource="RscCustomInfoMiniMap";
							};
							class UAVDisplay
							{
								componentType="UAVFeedDisplayComponent";
							};
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={10000,7500,5000,2500,1000,};
								resource="RscCustomInfoSensors";
							};
						};
					};
				};*/
			};
		};
		class AnimationSources: AnimationSources
		{
			class interior_pc
			{
				source="user";
				initPhase=0;
				animPeriod=0;
			};
			class interior_ambulance
			{
				source="user";
				initPhase=0;
				animPeriod=0;
			};
			class interior_surveillance
			{
				source="user";
				initPhase=1;
				animPeriod=1;
			};
			class exterior_command
			{
				source="user";
				initPhase=1;
				animPeriod=1;
			};
		};
		/*class Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class LaserSensorComponent : SensorTemplateLaser
					{
						class AirTarget
						{
							minRange=1;
							maxRange=5000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
							nightRangeCoef = 0.5;
						};
						class GroundTarget
						{
							minRange=1;
							maxRange=5000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
							nightRangeCoef = 0.5;
						};
						typeRecognitionDistance=5000;
						maxTrackableSpeed = 1e10;
						angleRangeHorizontal=150;
						angleRangeVertical=180;
						animDirection="cameraturret";
						aimDown=0;
					};
					class DataLinkSensorComponent: SensorTemplateDataLink
					{
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
			{
				defaultDisplay="MinimapDisplay";
				class Components
				{
					class EmptyDisplay
					{
						componentType="EmptyDisplayComponent";
					};
					class MinimapDisplay
					{
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoMiniMap";
					};
					class UAVDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={10000,7500,5000,2500,1000,};
						resource="RscCustomInfoSensors";
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
			{
				defaultDisplay="SensorDisplay";
				class Components
				{
					class EmptyDisplay
					{
						componentType="EmptyDisplayComponent";
					};
					class MinimapDisplay
					{
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoMiniMap";
					};
					class UAVDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={10000,7500,5000,2500,1000,};
						resource="RscCustomInfoSensors";
					};
				};
			};
		};*/
	};
	class adfrc_aslav_s: adfrc_aslav_pc
	{
		displayName="ASLAV-S";
		icon="ADF_Wheeled\adfrc_aslav\data\ui\icon_aslav_c_ca.paa";
		author="Quiggs";
		editorPreview = "\ADF_Wheeled\adfrc_aslav\adfrc_aslav_s.jpg";
		transportSoldier = 0;
		reportOwnPosition = 1;
		reportRemoteTargets = 1;
		receiveRemoteTargets = 1;
		tf_hasLRradio=1;
		tf_RadioType="TFAR_rt1523g";
		tf_range=20000;
		tf_subtype="airborne";
		class RenderTargets
		{
			class cameradisplay0
			{
				renderTarget="rendertarget0";
				class rendertarget0 
				{
					pointDirection   = "cameraview_dir";
					pointPosition    = "cameraview_pos";
					fov              = 0.5;
					renderQuality    = 2;
					renderVisionMode = 3;
				};
			};
			class cameradisplay1: cameradisplay0
			{
				renderTarget="rendertarget1";
				class rendertarget1: rendertarget0
				{
					fov              = 0.5;
					renderQuality    = 2;
					renderVisionMode = 3;
				};
			};
			class cameradisplay2: cameradisplay0
			{
				renderTarget="rendertarget2";
				class rendertarget2: rendertarget0
				{
					renderVisionMode = 2;
				};
			};
			class cameradisplay3: cameradisplay0
			{
				renderTarget="rendertarget3";
				class rendertarget3: rendertarget0
				{
					renderVisionMode = 2;
				};
			};
		};
		class Turrets: Turrets
		{
			class M2Turret: M2Turret{};
			class CargoTurret_01: CargoTurret_01{};
			class CargoTurret_02: CargoTurret_02 
			{ 
				gunnerName="Radio Operator"; 
				forceHideGunner = 1;
				proxyIndex = 4;
				isPersonTurret=0;
			};
			class CamOperatorTurret: NewTurret
			{
				gunnerName = "Camera Operator";
				body = "cameraturret";
				gun = "cameragun";
				gunBeg = "cameralaser_dir";
				gunEnd = "cameralaser_pos";
				gunnerOpticsModel = "\a3\Weapons_F_Enoch\Reticle\Optics_Gunner_UGV_02_demining_cam3_F";
				gunnerOutOpticsModel = "\A3\weapons_f\reticle\optics_empty";
				gunnerCompartments = "Compartment1";
				proxyType = "CPGunner";
				proxyIndex = 3;
				animationSourceHatch = "HatchCamera";
				animationSourceBody = "cameraturret";
				animationSourceGun = "cameragun";
				animationSourceElevation = "cameraelevation";
				elevationAnimSourceSpeed = 0.35;
				turretFollowFreeLook = 2;
				turretInfoType = "RscOptics_UGV_02_Demining_gunner";
				weapons[]=
				{
					"Laserdesignator_vehicle",
				};
				magazines[]=
				{
					"Laserbatteries",
				};
				soundServo[] = 
				{
					"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP03",0.17782794,1.0,10
				};
				soundServoVertical[] = 
				{
					"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP03",0.17782794,1.0,10
				};
				soundElevation[] = 
				{
					"A3\Sounds_F\vehicles\soft\noises\servo_turret_MRAP03_elevation",0.31622776,1.0,10
				};
				commanding=4;
				minElev=-40;
				initElev=0;
				maxElev=60;
				minOutElev=-30;
				maxOutElev=50;
				initOutElev=0;
				minOutTurn=-145;
				maxOutTurn=125;
				gunnerRightHandAnimName="";
				gunnerLeftHandAnimName="";
				gunnerLeftLegAnimName="";
				gunnerRightLegAnimName="";
				gunnerAction = "gunner_lsv_02";
				Laser = 1;
				lockWhenDriverOut = 0;
				isPersonTurret = 0;
				gunnerInAction = "passenger_apc_narrow_generic01";
				gunnerGetInAction="GetInMRAP_01Rfl";
				gunnerGetOutAction="GetOuthigh";
				viewGunnerInExternal=1;
				castGunnerShadow=1;
				forceHideGunner=1;
				gunnerForceOptics=0;
				inGunnerMayFire=1;
				outGunnerMayFire=1;
				discreteDistance[]={0,100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex=0;
				memoryPointGunnerOptics="cameraview_pos";
				memoryPointGunnerOutOptics="";
				memoryPointsGetInGunner="pos cargo";
				memoryPointsGetInGunnerDir="pos cargo dir";
				selectionFireAnim="m2_flash";
				stabilizedInAxes = 3;
				primaryGunner = 1;
				primaryObserver = 0;
				usePip = 2;
				LODTurnedIn = 1;
				LODTurnedOut = 1;
				LODOpticsIn = 1;
				LODOpticsOut = 1;
				startEngine = 1;
				disableSoundAttenuation=1;
				class ViewGunner
				{
					initAngleX = -25;
					initAngleY = 0;
					initFov = 0.9;
					minFov = 0.25;
					maxFov = 1.25;
					minAngleX = -65;
					maxAngleX = 85;
					minAngleY = -150;
					maxAngleY = 150;
					minMoveX = -0.075;
					maxMoveX = 0.075;
					minMoveY = -0.075;
					maxMoveY = 0.075;
					minMoveZ = 1;
					maxMoveZ = 0.1;
				};
				class ViewOptics: ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.5;
					minFov = 0.005;
					maxFov = 1;
					visionMode[] = {"Normal","NVG","Ti"};
					thermalMode[] = {0,1,2,3,4,5,6};
				};
				class TurnIn
                {};
				class HitPoints
				{
					class HitCameraTurret
					{
						armor=0.60000002;
						material=-1;
						name="vez";
						visual="vez";
						passThrough=1;
						minimalHit=0.2;
						explosionShielding=1;
						radius=0.20;
					};
					class HitCameraGun
					{
						armor=0.60000002;
						material=-1;
						name="zbran";
						visual="";
						passThrough=0;
						minimalHit=0.2;
						explosionShielding=1;
						radius=0.20;
					};
				};
				class Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
					{
						class Components
						{
							defaultDisplay="MinimapDisplay";
							class EmptyDisplay
							{
								componentType="EmptyDisplayComponent";
							};
							class MinimapDisplay
							{
								componentType="MinimapDisplayComponent";
								resource="RscCustomInfoMiniMap";
							};
							class UAVDisplay
							{
								componentType="UAVFeedDisplayComponent";
							};
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={10000,7500,5000,2500,1000,};
								resource="RscCustomInfoSensors";
							};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
					{
						defaultDisplay="SensorDisplay";
						class Components
						{
							class EmptyDisplay
							{
								componentType="EmptyDisplayComponent";
							};
							class MinimapDisplay
							{
								componentType="MinimapDisplayComponent";
								resource="RscCustomInfoMiniMap";
							};
							class UAVDisplay
							{
								componentType="UAVFeedDisplayComponent";
							};
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={10000,7500,5000,2500,1000,};
								resource="RscCustomInfoSensors";
							};
						};
					};
				};
			};
		};
		class AnimationSources: AnimationSources
		{
			class interior_pc
			{
				source="user";
				initPhase=0;
				animPeriod=0;
			};
			class interior_ambulance
			{
				source="user";
				initPhase=0;
				animPeriod=0;
			};
			class interior_surveillance
			{
				source="user";
				initPhase=1;
				animPeriod=1;
			};
			class exterior_surveillance
			{
				source="user";
				initPhase=1;
				animPeriod=1;
			};
			class cameraelevation_deployed
			{
				source = "door";
				animPeriod = 15;
				initPhase = 0;
				sound = "ServoRampSound_2";
			};
			
		};
		class UserActions:UserActions
		{
			class Camera_Raise
			{
				userActionID=52;
				displayName = "Deploy Camera";
				radius=5;
				showIn3D=17;
				priority=1;
				position="driverview";
				onlyForPlayer=0;
				condition="((this DoorPhase 'cameraelevation_deployed') == 0) AND Alive (this) and driver this == player";
				statement="this animateDoor ['cameraelevation_deployed', 1];";
			};
			class Camera_lower: Camera_Raise
			{
				userActionID=53;
				displayName="Retract Camera";
				condition="((this DoorPhase 'cameraelevation_deployed') > 0) AND Alive (this) and driver this == player";
				statement="this animateDoor [""cameraelevation_deployed"", 0];";
			};
		};
		class Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent: SensorTemplateIR 
					{
						class AirTarget
						{
							minRange=1;
							maxRange=10000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
							nightRangeCoef = 0.5;
						};
						class GroundTarget
						{
							minRange=1;
							maxRange=10000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
							nightRangeCoef = 0.5;
						};
						typeRecognitionDistance=7500;
						maxTrackableSpeed = 1e10;
						angleRangeHorizontal=35;
						angleRangeVertical=180;
						animDirection="cameraturret";
						aimDown=0;
					};
					class VisualSensorComponent: SensorTemplateVisual
					{
						class AirTarget
						{
							minRange=1;
							maxRange=7500;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
							nightRangeCoef = 0.5;
						};
						class GroundTarget
						{
							minRange=1;
							maxRange=7500;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
							nightRangeCoef = 0.5;
						};
						typeRecognitionDistance=5000;
						maxTrackableSpeed = 1e10;
						angleRangeHorizontal=35;
						angleRangeVertical=180;
						animDirection="cameraturret";
						aimDown=0;
					};
					class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
					{
						class AirTarget
						{
							minRange=1;
							maxRange=5000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
							nightRangeCoef = 0.5;
						};
						class GroundTarget
						{
							minRange=1;
							maxRange=5000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
							nightRangeCoef = 0.5;
						};
						typeRecognitionDistance=5000;
						maxTrackableSpeed = 1e10;
						angleRangeHorizontal=150;
						angleRangeVertical=180;
						animDirection="cameraturret";
						aimDown=0;
					};
					class LaserSensorComponent : SensorTemplateLaser
					{
						class AirTarget
						{
							minRange=1;
							maxRange=5000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
							nightRangeCoef = 0.5;
						};
						class GroundTarget
						{
							minRange=1;
							maxRange=5000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
							nightRangeCoef = 0.5;
						};
						typeRecognitionDistance=5000;
						maxTrackableSpeed = 1e10;
						angleRangeHorizontal=150;
						angleRangeVertical=180;
						animDirection="cameraturret";
						aimDown=0;
					};
					class DataLinkSensorComponent: SensorTemplateDataLink
					{
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
			{
				defaultDisplay="MinimapDisplay";
				class Components
				{
					class EmptyDisplay
					{
						componentType="EmptyDisplayComponent";
					};
					class MinimapDisplay
					{
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoMiniMap";
					};
					class UAVDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={10000,7500,5000,2500,1000,};
						resource="RscCustomInfoSensors";
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
			{
				defaultDisplay="SensorDisplay";
				class Components
				{
					class EmptyDisplay
					{
						componentType="EmptyDisplayComponent";
					};
					class MinimapDisplay
					{
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoMiniMap";
					};
					class UAVDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={10000,7500,5000,2500,1000,};
						resource="RscCustomInfoSensors";
					};
				};
			};
		};
	};
	//------------------------------------------------------------- GWOT
	class adfrc_aslav_25_gwot: adfrc_aslav_25
	{
		faction="ADFRC_F_GWOT";
		author="Quiggs";
	};
	class adfrc_aslav_25_mag58_gwot: adfrc_aslav_25_mag58
	{
		faction="ADFRC_F_GWOT";
		author="Quiggs";
	};
	class adfrc_aslav_pc_gwot: adfrc_aslav_pc
	{
		faction="ADFRC_F_GWOT";
		author="Quiggs";
	};
	class adfrc_aslav_pc_rws_gwot: adfrc_aslav_pc_rws
	{
		faction="ADFRC_F_GWOT";
		author="Quiggs";
	};
	class adfrc_aslav_a_gwot: adfrc_aslav_a
	{
		faction="ADFRC_F_GWOT";
		author="Quiggs";
	};
	class adfrc_aslav_s_gwot: adfrc_aslav_s
	{
		faction="ADFRC_F_GWOT";
		author="Quiggs";
	};
	//// BACKWARDS COMPATIBILITY --- THIS IS FOR THE OLD ASLAV25 CLASSNAME TO CONTINUE WORKING ////
	class ADFRC_ASLAV: adfrc_aslav_25_mag58
	{
		scope=1;
		scopeCurator=1;
	};
	/*  LAV-25A3 SLEP ------- This is a version for QAV, this model is not in use by the ADF, leaving here to convert over later
	class ADF_Wheeled\adfrc_aslav25a3: adfrc_aslav_base
	{
		displayName="LAV-25A3 SLEP";
		author="Quiggs";
		//editorPreview = "\ADF_Wheeled\adfrc_aslav_crv.jpg";
		//picture="ADF_Wheeled\adfrc_aslav\data\ui\boxercrv.paa";
		//icon="ADF_Wheeled\adfrc_aslav\data\ui\mapboxercrv.paa";
		side = 1;
		scope=1;
		scopeCurator=1;
		faction="QAV_vehicles";
		crew="ADFRC_MD_AMCU_Soldier_Crewman";
		typicalCargo[] = {"ADFRC_MD_AMCU_Soldier_CavalryScout"};
		enginePower=325;
		peakTorque=750;
		canFloat = 0;
		waterPPInVehicle=0;
		waterAngularDampingCoef=10;
		waterLinearDampingCoefY=2;
		waterLinearDampingCoefX=2;
		rudderForceCoef=0;
		rudderForceCoefAtMaxSpeed=0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				maxHorizontalRotSpeed = "((360/10)/37.5)";
				maxVerticalRotSpeed = 0.6;
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.3;
					minFov = 0.5;
					maxFov = 1;
				};
				class OpticsIn: Optics_Gunner_MBT_03
				{
					class Periscope : Wide
					{
						gunnerOpticsModel = "\qav_core\optics\qav_optics_commander.p3d";
						camPos = "gunnerview_periscope";
						camDir = "";
						initFov = "0.4/0.5";
						visionMode[] = {"Normal","nvg"};
					};
					class M252daysight: Medium
					{
						gunnerOpticsModel = "ADF_Wheeled\adfrc_aslav\Optics_M242.p3d";
						gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
						visionMode[] = {"Normal","nvg"};
						initFov = 0.08;
					};
					class Wide: Wide 
					{
						gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
						visionMode[] = {"TI"};
						thermalMode[] = {0,1};
					};
					class Medium: Medium 
					{
						gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
						visionMode[] = {"TI"};
						thermalMode[] = {0,1};
					};
					class Narrow: Narrow 
					{
						gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
						visionMode[] = {"TI"};
						thermalMode[] = {0,1};
					};
				};
				class HitPoints: HitPoints{};
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						class OpticsIn: Optics_Gunner_MBT_03
						{
							class Periscope : Wide
							{
								gunnerOpticsModel = "\qav_core\optics\qav_optics_commander.p3d";
								camPos = "commanderview_periscope";
								camDir = "";
								initFov = "0.4/0.5";
								visionMode[] = {"Normal","nvg"};
							};
							class M252daysight: Medium
							{
								gunnerOpticsModel = "ADF_Wheeled\adfrc_aslav\Optics_M242.p3d";
								gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
								visionMode[] = {"Normal","nvg"};
								initFov = 0.08;
							};
							class Wide: Wide 
							{
								gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
								visionMode[] = {"TI"};
								thermalMode[] = {0,1};
							};
							class Medium: Medium 
							{
								gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
								visionMode[] = {"TI"};
								thermalMode[] = {0,1};
							};
							class Narrow: Narrow 
							{
								gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
								visionMode[] = {"TI"};
								thermalMode[] = {0,1};
							};
						};
						class HitPoints: HitPoints{};
					};
				};
			};
			class CargoGunner_1: CargoGunner_1{};
			class CargoGunner_2: CargoGunner_2{};
		};
	};*/
};
class Extended_Init_EventHandlers
{
    class adfrc_aslav_base
    {
        ADFRC_labelRandom = "_this spawn {sleep 0.1; params ['_veh']; if (!isServer) exitWith {}; private _v = _veh getVariable ['PlatoonMarkings', 0]; if (_v isEqualTo 0) then {private _i = floor (random 22) + 1; private _f = if (_i < 10) then {format ['\adf_wheeled\adfrc_aslav\data\labels\labels_0%1.paa', _i]} else {format ['\adf_wheeled\adfrc_aslav\data\labels\labels_%1.paa', _i]}; {_veh setObjectTextureGlobal [_x, _f]} forEach [7, 8, 9];}};";
    };
	class adfrc_aslav_pc_base
    {
        ADFRC_labelRandom = "_this spawn {sleep 0.1; params ['_veh']; if (!isServer) exitWith {}; private _v = _veh getVariable ['PlatoonMarkings', 0]; if (_v isEqualTo 0) then {private _i = floor (random 22) + 1; private _f = if (_i < 10) then {format ['\adf_wheeled\adfrc_aslav\data\labels\labels_0%1.paa', _i]} else {format ['\adf_wheeled\adfrc_aslav\data\labels\labels_%1.paa', _i]}; {_veh setObjectTextureGlobal [_x, _f]} forEach [8, 9];}};";
    };
};
