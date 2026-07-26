class CfgPatches
{
	class adfrc_abrams
	{
		requiredAddons[]=
		{
			"A3_Data_F_AoW_Loadorder",
			"A3_Data_F_Mod_Loadorder",
			"ADF_Core",
			"ADF_Tracked",
			"ADF_Weapons",
			"A3_Armor_F_EPB",
			"cba_main",
		};
		requiredVersion=0.1;
		units[]=
		{
			"adfrc_abrams",
			"adfrc_m1a1aim_md",
			"adfrc_m1a1aim_gwot",
			"adfrc_m1a2sepv3_md",
		};
		weapons[]=
		{
			"ADFRC_abrams_M256",
			"ADFRC_abrams_coax",
			"ADFRC_abrams_mag58",
			"ADFRC_abrams_M2HBQCB",
			"ADFRC_abrams_M2HBQCB_RWS"
		};
		magazines[]=
		{
			"adfrc_abrams_1000Rnd_762x51_Tracer",
			"adfrc_abrams_200Rnd_762x51_Tracer",
			"adfrc_abrams_1Rnd_M829A2_shell",
			"adfrc_abrams_1Rnd_M830A1_shell",
			"adfrc_abrams_1Rnd_M908_shell",
			"adfrc_abrams_1Rnd_M1028_shell",
		};
	};
};

#include "c_ammo.hpp"
#include "CfgDigVehicles.hpp"
class DefaultEventHandlers;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class RCWSOptics;
class CargoTurret;
class Optics_Armored;
class Optics_Commander_02: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class Optics_Gunner_APC_01: Optics_Armored
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
	class LandVehicle;
	class Tank: LandVehicle
	{
		class NewTurret;
		class Sounds;
		class HitPoints;
		class CommanderOptics;
	};
	class Tank_F: Tank
	{
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewGunner;
				class Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						class ViewGunner;
					};
				};
			};
		};
		class AnimationSources;
		class ViewPilot;
		class ViewOptics;
		class ViewCargo;
		class HeadLimits;
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitFuel;
			class HitEngine;
			class HitLTrack;
			class HitRTrack;
		};
		class Sounds: Sounds
		{
			class Engine;
			class Movement;
		};
	};
	class MBT_03_base_F: Tank_F {};
	class I_MBT_03_base_F: MBT_03_base_F {};
	class I_MBT_03_cannon_F: I_MBT_03_base_F {};
	class adfrc_abrams: I_MBT_03_cannon_F
	{
		author="ADFRC_Quiggs";
		mapSize=11.57;
		simulation="tankX";
		fuelCapacity=18;
		brakeIdleSpeed=0.2;
		maxSpeed=70;
		normalSpeedForwardCoef=0.75;
		slowSpeedForwardCoef=0.25;
		waterResistanceCoef=0.25;
		enginePower=1600;
		maxOmega=345.57501;
		minOmega=146.608;
		redRpm=4000;
		idleRpm=700;
		peakTorque=5500;
		torqueCurve[]=
		{
			{0.42424199,0.80000001},
			{0.54545498,0.94999999},
			{0.60606098,0.99000001},
			{0.63636398,1},
			{0.66666698,0.98000002},
			{0.72727299,0.93000001},
			{0.87878799,0.75999999},
			{1,0.60000002}
		};
		thrustDelay=0.5;
		engineMOI=25;
		dampingRateFullThrottle=2.5;
		dampingRateZeroThrottleClutchEngaged=8;
		dampingRateZeroThrottleClutchDisengaged=2;
		clutchStrength=40;
		latency=2;
		switchTime=0;
		changeGearType="rpmratio";
		changeGearOmegaRatios[]={1,0.42424199,0.45454499,0.33333299,0.98484802,0.42424199,0.98484802,0.60606098,0.98484802,0.57575798,1,0.54545498};
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-6,
				"N",
				0,
				"D1",
				4.,
				"D2",
				3.2,
				"D3",
				2.2,
				"D4",
				1.6,
				"D5",
				0.8
			};
			transmissionRatios[]=
			{
				"High",
				13
			};
			gearBoxMode="auto";
			moveOffGear=2;
			driveString="D";
			neutralString="N";
			reverseString="R";
		};
		class Wheels
		{
			class L2
			{
				side="left";
				suspTravelDirection[]={-0.125,-1,0};
				boneName="wheel_podkoloL1";
				center="wheel_1_2_axis";
				boundary="wheel_1_2_bound";
				steering=0;
				width=0.5;
				mass=150;
				MOI=17;
				dampingRate=1125;
				dampingRateInAir=3000;
				dampingRateDestroyed=3000;
				maxDroop=0.15;
				maxCompression=0.15;
				sprungMass=4729;
				springStrength=250000;
				springDamperRate=20000;
				maxBrakeTorque=10000;
				latStiffX=2;
				latStiffY=33;
				longitudinalStiffnessPerUnitGravity=12000;
				frictionVsSlipGraph[]=
				{
					{0,0.55000001},
					{0.30000001,1.28},
					{0.64999998,0.55000001}
				};
			};
			class L3: L2
			{
				boneName="wheel_podkolol2";
				center="wheel_1_3_axis";
				boundary="wheel_1_3_bound";
			};
			class L4: L2
			{
				boneName="wheel_podkolol3";
				center="wheel_1_4_axis";
				boundary="wheel_1_4_bound";
			};
			class L5: L4
			{
				boneName="wheel_podkolol4";
				center="wheel_1_5_axis";
				boundary="wheel_1_5_bound";
			};
			class L6: L4
			{
				boneName="wheel_podkolol5";
				center="wheel_1_6_axis";
				boundary="wheel_1_6_bound";
			};
			class L7: L2
			{
				boneName="wheel_podkolol6";
				center="wheel_1_7_axis";
				boundary="wheel_1_7_bound";
			};
			class L8: L2
			{
				boneName="wheel_podkolol7";
				center="wheel_1_8_axis";
				boundary="wheel_1_8_bound";
			};
			class L9: L2
			{
				boneName="wheel_podkolol9";
				center="wheel_1_9_axis";
				boundary="wheel_1_9_bound";
			};
			class L1: L2
			{
				boneName="";
				center="wheel_1_1_axis";
				boundary="wheel_1_1_bound";
			};
			class R2: L2
			{
				side="right";
				suspTravelDirection[]={0.125,-1,0};
				boneName="wheel_podkolop1";
				center="wheel_2_2_axis";
				boundary="wheel_2_2_bound";
			};
			class R3: R2
			{
				boneName="wheel_podkolop2";
				center="wheel_2_3_axis";
				boundary="wheel_2_3_bound";
			};
			class R4: R2
			{
				boneName="wheel_podkolop3";
				center="wheel_2_4_axis";
				boundary="wheel_2_4_bound";
			};
			class R5: R2
			{
				boneName="wheel_podkolop4";
				center="wheel_2_5_axis";
				boundary="wheel_2_5_bound";
			};
			class R6: R2
			{
				boneName="wheel_podkolop5";
				center="wheel_2_6_axis";
				boundary="wheel_2_6_bound";
			};
			class R7: R2
			{
				boneName="wheel_podkolop6";
				center="wheel_2_7_axis";
				boundary="wheel_2_7_bound";
			};
			class R8: R2
			{
				boneName="wheel_podkolop7";
				center="wheel_2_8_axis";
				boundary="wheel_2_8_bound";
			};
			class R9: R2
			{
				boneName="wheel_podkolop9";
				center="wheel_2_9_axis";
				boundary="wheel_2_9_bound";
			};
			class R1: R2
			{
				boneName="";
				center="wheel_2_1_axis";
				boundary="wheel_2_1_bound";
			};
		};
		tankTurnForce=800000;
		tankTurnForceAngMinSpd=0.1;
		tankTurnForceAngSpd=1;
		accelAidForceCoef=1;
		accelAidForceYOffset=-1;
		accelAidForceSpd=1;
		numberPhysicalWheels=18;
		editorSubcategory="EdSubcat_Tanks";
		scope=0;
		maxFordingDepth=-1.5;
		steerAheadSimul=0.5;
		steerAheadPlan=0.34999999;
		predictTurnPlan=2.8;
		predictTurnSimul=2.5999999;
		brakeDistance=20;
		precision=5;
		transportSoldier=0;
		getInAction="GetInLow";
		getOutAction="GetOutLow";
		cargoGetInAction[]=
		{
			"GetInLow"
		};
		cargoGetOutAction[]=
		{
			"GetOutLow"
		};
		cargoAction[]=
		{
			"passenger_flatground_leanleft",
			"passenger_flatground_generic01",
			"passenger_flatground_generic02",
			"passenger_flatground_generic03",
			"passenger_flatground_generic04",
			"passenger_flatground_generic05"
		};
		waterResistance=3;
		waterDamageEngine=0.1;
		wheelCircumference=2.513;
		tracksSpeed=1;
		forceHideDriver=0;
		driverForceOptics=0;
		LODDriverOpticsIn=1100;
		LODDriverTurnedOut=0;
		driverOpticsModel="\a3\weapons_f\Reticle\Optics_Driver_01_F.p3d";
		viewDriverInExternal=0;
		animationSourceHatch="driverhatch";
		driverDoor="driverhatch";
		driverInfoPanelCameraPos="driverview_old";
		driverAction="Driver_MBT_04_in";
		driverInAction="Driver_MBT_04_in";
		extCameraPosition[]={0,2,-9};
		driverLeftHandAnimName="drivewheel";
		driverRightHandAnimName="drivewheel";
		driverLeftLegAnimName="pedal_brake";
		driverRightLegAnimName="pedal_thrust";
		viewDriverShadowAmb=1;
		viewDriverShadowDiff=1;
		armor=800;
		armorLights=0.1;
		armorStructural=6;
		damageResistance=0.0054700002;
		cost=2500000;
		crewVulnerable=1;
		crewExplosionProtection=0.99989998;
		epeImpulseDamageCoef=18;
		picture="\ADF_Tracked\adfrc_abrams\Data\UI\M1_abrams_CA.paa";
		icon="\ADF_Tracked\adfrc_abrams\data\UI\icomap_m1a1_CA.paa";
		memoryPointTaskMarker="TaskMarker_1_pos";
		insideSoundCoef=0.89999998;
		threat[]={0.80000001,1,0.30000001};
		class ViewOptics: ViewOptics
		{
			visionMode[]=
			{
				"Normal",
				"NVG"
			};
			initFov=1.1;
			minFov=1.1;
			maxFov=1.1;
		};
		class ViewPilot: ViewPilot
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
			maxMoveY=0.015;
			minMoveZ=-0.075;
			maxMoveZ=0.075;
		};
		class Reflectors
		{
			class Left
			{
				color[]={1900,1800,1700};
				ambient[]={5,5,5};
				position="Light_L";
				direction="Light_L_end";
				hitpoint="Light_L";
				selection="Light_L";
				size=1;
				innerAngle=75;
				outerAngle=180;
				coneFadeCoef=10;
				intensity=1;
				useFlare=0;
				dayLight=0;
				flareSize=1;
				class Attenuation
				{
					start=1;
					constant=0;
					linear=0;
					quadratic=0.25;
					hardLimitStart=30;
					hardLimitEnd=100;
				};
			};
			class Right: Left
			{
				position="Light_R";
				direction="Light_R_end";
				hitpoint="Light_R";
				selection="Light_R";
			};
			class Right2: Right
			{
				position="light_R_flare";
				hitpoint="Light_R_flare";
				useFlare=1;
			};
			class Left2: Left
			{
				position="light_L_flare";
				hitpoint="Light_L_flare";
				useFlare=1;
			};
		};
		aggregateReflectors[]=
		{
			
			{
				"Left",
				"Right",
				"Left2",
				"Right2"
			}
		};
		class compartmentsLights
		{
			class Comp1
			{
				class Light1
				{
					color[]={20,18,12};
					ambient[]={0,0,0};
					intensity=1.5;
					size=0;
					useFlare=0;
					flareSize=0;
					flareMaxDistance=0;
					dayLight=0;
					blinking=0;
					class Attenuation
					{
						start=0;
						constant=0;
						linear=1;
						quadratic=70;
						hardLimitStart=0.15000001;
						hardLimitEnd=1.15;
					};
					point="light_interior1";
				};
				class Light2: Light1
				{
					point="light_interior2";
					color[]={20,18,12};
					ambient[]={0,0,0};
					intensity=1;
				};
				class Light3: Light1
				{
					point="light_interior3";
					color[]={20,18,12};
					ambient[]={0,0,0};
					intensity=0.69999999;
				};
				class Light4: Light1
				{
					point="light_interior4";
					color[]={22,18,10};
					ambient[]={0,0,0};
					intensity=1.2;
				};
				class Light5: Light1
				{
					point="light_interior5";
					color[]={20,20,20};
					ambient[]={0,0,0};
					intensity=0.40000001;
				};
				class Light6: Light1
				{
					point="light_interior6";
					color[]={20,18,12};
					ambient[]={0,0,0};
					intensity=0.80000001;
				};
			};
		};
		class Exhausts
		{
			class Exhaust1
			{
				position="exhaust";
				direction="exhaust_dir";
				effect="ExhaustsEffectPlaneHP";
			};
			class Exhaust2
			{
				position="exhaust2";
				direction="exhaust2_dir";
				effect="ExhaustsEffectPlaneHP";
			};
			class Exhaust3
			{
				position="exhaust3";
				direction="exhaust3_dir";
				effect="ExhaustsEffectPlaneHP";
			};
		};
		smokeLauncherGrenadeCount = 8;
		smokeLauncherVelocity = 14;
		smokeLauncherOnTurret = 1;
		smokeLauncherAngle = 120;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						body="commanderturret";
						gun="commandergun";
						animationSourceBody="commanderturret";
						animationSourceGun="commandergun";
						animationSourceHatch="commanderhatch";
						memoryPointGunnerOutOptics="commanderview";
						memoryPointGunnerOptics="commander_digital_view";
						gunBeg="m2_muzzle";
						gunEnd="m2_chamber";
						gunnerDoor = "commanderhatch";
						particlesdir = "Konec hlavne2";
						particlespos = "Usti hlavne2";
						memoryPointGun="m2_muzzle";
						selectionFireAnim="zasleh2";
						minElev=-9;
						maxElev=65;
						initElev=0;
						minTurn=-360;
						maxTurn=360;
						initTurn=0;
						weapons[]=
						{
							"ADFRC_abrams_M2HBQCB",
							"SmokeLauncher"
						};
						magazines[]=
						{
							"100rnd_127x99_mag_Tracer_Red",
							"100rnd_127x99_mag_Tracer_Red",
							"100rnd_127x99_mag_Tracer_Red",
							"100rnd_127x99_mag_Tracer_Red",
							"100rnd_127x99_mag_Tracer_Red",
							"100rnd_127x99_mag_Tracer_Red",
							"100rnd_127x99_mag_Tracer_Red",
							"100rnd_127x99_mag_Tracer_Red",
							"100rnd_127x99_mag_Tracer_Red",
							"100rnd_127x99_mag_Tracer_Red",
							"SmokeLauncherMag"
						};
						soundServo[]=
						{
							"A3\Sounds_F\vehicles\armor\noises\servo_armor_comm",
							0.56234133,
							0.8,
							30
						};
						soundServoVertical[]=
						{
							"A3\Sounds_F\vehicles\armor\noises\servo_armor_comm",
							0.56234133,
							1,
							30
						};
						outGunnerMayFire=0;
						inGunnerMayFire=1;
						gunnerAction="Commander_MBT_03_cannon_F_out";
						gunnerInAction="Commander_MBT_03_cannon_F_in";
						gunnerGetInAction="GetInLow";
						gunnerGetOutAction="GetOutLow";
						discreteDistance[]={0,100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
						discreteDistanceInitIndex=0;
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_02_F";
						gunnerOutOpticsColor[]={1,0,0,1};
						gunnerOutOpticsModel="";
						gunnerOpticsEffect[]={"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
						gunnerForceOptics=0;
						usePip=2;
						LODTurnedIn = 1;
						LODTurnedOut = 1;
						LODOpticsIn = 1;
						LODOpticsOut = 1;
						isPersonTurret=1;
						personTurretAction="vehicle_turnout_1";
						animationSourceStickX="com_turret_control_x";
						animationSourceStickY="com_turret_control_y";
						gunnerRightHandAnimName="com_turret_control";
						class dynamicViewLimits
						{
							MainTurret[]={-135,75};
						};
						minOutElev=-20;
						maxOutElev=45;
						initOutElev=0;
						minOutTurn=-120;
						maxOutTurn=120;
						initOutTurn=0;
						class ViewGunner: ViewGunner
						{
							initAngleX=0;
							initAngleY=0;
							initFov=0.89999998;
							minFov=0.25;
							maxFov=1.25;
							minAngleX=-65;
							maxAngleX=85;
							minAngleY=-150;
							maxAngleY=150;
							minMoveX=-0.5;
							maxMoveX=0.5;
							minMoveY=-0.5;
							maxMoveY=0.5;
							minMoveZ=-0.2;
							maxMoveZ=0.2;
						};
						class ViewOptics: ViewOptics
						{
							initAngleX=0;
							minAngleX=-30;
							maxAngleX=30;
							initAngleY=0;
							minAngleY=-100;
							maxAngleY=100;
							initFov=0.31;
							minFov=0.034000002;
							maxFov=0.31;
							visionMode[]=
							{
								"Normal",
							};
						};
						class OpticsIn: Optics_Gunner_MBT_03
						{
							class Comwidesight: wide
							{
								gunnerOpticsModel="\a3\weapons_f\Reticle\Optics_Driver_01_F.p3d";
								gunnerOpticsEffect[] = {"OpticsBlur1","OpticsCHAbera1"};
								initAngleX=0;
								minAngleX=-30;
								maxAngleX=30;
								initAngleY=0;
								minAngleY=-100;
								maxAngleY=100;
								camPos = "commander_periscope_view_pos";
								camDir = "commander_periscope_view_dir";
								initFov="0.4/0.5";
								minFov="0.4/0.5";
								maxFov="0.4/0.5";
								visionMode[]=
								{
									"Normal",
									"NVG",
								};
							};
							class Comdaysight: Medium
							{
								gunnerOpticsModel = "\ADF_Tracked\adfrc_abrams\abrams_comsight_m2.p3d";
								gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
								
								initAngleX=0;
								minAngleX=-30;
								maxAngleX=30;
								initAngleY=0;
								minAngleY=-100;
								maxAngleY=100;
								camPos = "commander_analogue_view_pos";
								camDir = "commander_analogue_view_dir";
								initFov="0.4/3";
								minFov="0.4/3";
								maxFov="0.4/3";
								visionMode[]=
								{
									"Normal",
									"NVG",
								};
							};
							class Medium: Medium 
							{
								initAngleX=0;
								minAngleX=-30;
								maxAngleX=30;
								initAngleY=0;
								minAngleY=-100;
								maxAngleY=100;
								camPos = "commander_digital_view_pos";
								camDir = "commander_digital_view_dir";
								initFov="0.4/3";
								minFov="0.4/3";
								maxFov="0.4/3";
								visionMode[]=
								{
									"TI"
								};
								thermalMode[]={2,3};
								thermalResolution[] = {800};
							};
							class Narrow: Narrow 
							{
								initAngleX=0;
								minAngleX=-30;
								maxAngleX=30;
								initAngleY=0;
								minAngleY=-100;
								maxAngleY=100;
								camPos = "commander_digital_view_pos";
								camDir = "commander_digital_view_dir";
								initFov="0.4/8";
								minFov="0.4/8";
								maxFov="0.4/8";
								visionMode[]=
								{
									"TI"
								};
								thermalMode[]={2,3};
								thermalResolution[] = {800};
							};
						};
						viewGunnerShadowAmb=1;
						viewGunnerShadowDiff=1;
						turretInfoType="RscOptics_APC_Wheeled_03_commander";
						showCrewAim=1;
						startEngine=0;
						gunnerHasFlares=1;
						stabilizedInAxes=0;
						maxHorizontalRotSpeed=0.6;
						maxVerticalRotSpeed=0.5;
						viewGunnerInExternal=0;
						class HitPoints
						{
							class HitComTurret
							{
								armor=0.1;
								material=-1;
								armorComponent="hit_commanderturret";
								name="hit_commanderturret_point";
								visual="commanderturret";
								passThrough=0;
								minimalHit=0.1;
								explosionShielding=1;
								radius=0.15000001;
								isTurret=1;
							};
							class HitComGun
							{
								armor=0.1;
								material=-1;
								armorComponent="hit_commandergun";
								name="hit_commandergun_point";
								visual="commandergun";
								passThrough=0;
								minimalHit=0.1;
								explosionShielding=1;
								radius=0.15000001;
								isGun=1;
							};
						};
					};
				};
				body="mainturret";
				gun="maingun";
				gunBeg="maingun_muzzle";
				gunEnd="maingun_chamber";
				selectionFireAnim="zasleh";
				gunnerInAction="Commander_MBT_02_arty_F_in";
				gunnerAction="Gunner_MBT_03_cannon_F_out";
				gunnerGetInAction="GetInLow";
				gunnerGetOutAction="GetOutLow";
				gunnerDoor = "loaderhatch";
				weapons[]=
				{
					"ADFRC_abrams_M256",
					"ADFRC_abrams_coax"
				};
				magazines[]=
				{
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M829A2_shell",
					"adfrc_abrams_1Rnd_M830A1_shell",
					"adfrc_abrams_1Rnd_M830A1_shell",
					"adfrc_abrams_1Rnd_M830A1_shell",
					"adfrc_abrams_1Rnd_M830A1_shell",
					"adfrc_abrams_1Rnd_M830A1_shell",
					"adfrc_abrams_1Rnd_M830A1_shell",
					"adfrc_abrams_1Rnd_M830A1_shell",
					"adfrc_abrams_1Rnd_M830A1_shell",
					"adfrc_abrams_1Rnd_M830A1_shell",
					"adfrc_abrams_1Rnd_M830A1_shell",
					"adfrc_abrams_1Rnd_M908_shell",
					"adfrc_abrams_1Rnd_M908_shell",
					"adfrc_abrams_1Rnd_M908_shell",
					"adfrc_abrams_1Rnd_M908_shell",
					"adfrc_abrams_1Rnd_M908_shell",
					"adfrc_abrams_1Rnd_M908_shell",
					"adfrc_abrams_1Rnd_M908_shell",
					"adfrc_abrams_1Rnd_M1028_shell",
					"adfrc_abrams_1Rnd_M1028_shell",
					"adfrc_abrams_1Rnd_M1028_shell",
					"adfrc_abrams_1Rnd_M1028_shell",
					"adfrc_abrams_1Rnd_M1028_shell",
					"ADFRC_abrams_200Rnd_762x51_Tracer",
					"ADFRC_abrams_200Rnd_762x51_Tracer",
					"ADFRC_abrams_200Rnd_762x51_Tracer",
					"ADFRC_abrams_200Rnd_762x51_Tracer",
					"ADFRC_abrams_200Rnd_762x51_Tracer",
					"ADFRC_abrams_200Rnd_762x51_Tracer",
					"ADFRC_abrams_200Rnd_762x51_Tracer",
					"ADFRC_abrams_200Rnd_762x51_Tracer",
					"ADFRC_abrams_200Rnd_762x51_Tracer",
					"ADFRC_abrams_200Rnd_762x51_Tracer",
					"ADFRC_abrams_200Rnd_762x51_Tracer",
					"ADFRC_abrams_200Rnd_762x51_Tracer",
					"ADFRC_abrams_200Rnd_762x51_Tracer",
					"ADFRC_abrams_200Rnd_762x51_Tracer",
					"ADFRC_abrams_200Rnd_762x51_Tracer",
					"ADFRC_abrams_200Rnd_762x51_Tracer",
				};
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner",
					0.15848932,
					1.5,
					75
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner_vertical",
					0.15848932,
					1.5,
					75
				};
				forceHideGunner=1;
				usePip=2;
				LODTurnedIn = 1;
				LODTurnedOut = 1;
				LODOpticsIn = 1;
				LODOpticsOut = 1;
				animationSourceStickX="turret_control_x";
				animationSourceStickY="turret_control_y";
				gunnerRightHandAnimName="turret_control";
				viewGunnerShadowAmb=1;
				viewGunnerShadowDiff=1;
				discreteDistance[]={0,100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000,3100,3200,3300,3400,3500,3600,3700,3800,3900,4000,4100,4200,4300,4400,4500,4600,4700,4800,4900,5000};
				discreteDistanceInitIndex=5;
				memoryPointGunnerOptics="gunnerview";
				memoryPointGun="coax";
				particlesdir = "konec hlavne";
				particlespos = "usti hlavne";
				turretInfoType="RscOptics_APC_Wheeled_01_gunner";
				minElev=-10;
				maxElev=20;
				initElev=0;
				maxHorizontalRotSpeed = "((360/12)/45)";
				maxVerticalRotSpeed = "((360/21)/45)";
				gunnerOutOpticsModel="\ADF_Tracked\adfrc_abrams\abrams_daysight_3x.p3d";
				gunnerOutOpticsEffect[]={};
				gunnerOpticsEffect[]={"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
				gunnerForceOptics=1;
				startEngine=1;
				inGunnerMayFire=1;
				viewGunnerInExternal=0;
				isPersonTurret=0;
				class dynamicViewLimits
				{
					CommanderOptics[]={-65,90};
				};
				class OpticsIn
				{
					class unitysight
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						gunnerOpticsModel="\a3\weapons_f\Reticle\Optics_Driver_01_F.p3d";
						gunnerOpticsEffect[] = {""};
						camPos = "unitysight_pos";
						camDir = "unitysight_dir";
						initFov="0.4/0.5";
						minFov="0.4/0.5";
						maxFov="0.4/0.5";
						visionMode[]=
						{
							"Normal",
							"NVG"
						};
					};
					class gas
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						gunnerOpticsModel="\ADF_Tracked\adfrc_abrams\abrams_gas_3x.p3d";
						gunnerOpticsEffect[] = {""};
						camPos = "gas_pos";
						camDir = "gas_dir";
						initFov="0.4/8";
						minFov="0.4/8";
						maxFov="0.4/8";
						visionMode[]=
						{
							"Normal",
							"NVG"
						};
					};
					class daysight_3x
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						gunnerOpticsModel="\ADF_Tracked\adfrc_abrams\abrams_daysight_3x.p3d";
						gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
						camPos = "gunnerview_pos";
						camDir = "gunnerview_dir";
						initFov="0.4/3";
						minFov="0.4/3";
						maxFov="0.4/3";
						visionMode[]=
						{
							"Normal",
							"TI"
						};
						thermalMode[]={2,3};
						thermalResolution[] = {320};
					};
					class daysight_10x: daysight_3x
					{
						gunnerOpticsModel="\ADF_Tracked\adfrc_abrams\abrams_daysight_10x.p3d";
						initFov="0.4/10";
						minFov="0.4/10";
						maxFov="0.4/10";
					};
				};
				class ViewGunner: ViewGunner
				{
					initAngleX=-13;
					initAngleY=0;
					initFov=0.89999998;
					minFov=0.25;
					maxFov=1.25;
					minAngleX=-65;
					maxAngleX=85;
					minAngleY=-150;
					maxAngleY=150;
					minMoveX=-0.075000003;
					maxMoveX=0.075000003;
					minMoveY=-0.075000003;
					maxMoveY=0.075000003;
					minMoveZ=-0.075000003;
					maxMoveZ=0.1;
				};
				showCrewAim=2;
				class TurnOut
				{
					limitsArrayTop[]=
					{
						{20.1126,-107.5349},
						{19.8932,99.317703}
					};
					limitsArrayBottom[]=
					{
						{-9.1273003,-108.1836},
						{-7.1046,-44.255001},
						{-9.1674995,31.497801},
						{-9.0504999,102.8447}
					};
				};
				/*class TurnIn: TurnOut
				{
					limitsArrayTop[]=
					{
						{19.9995,-180},
						{19.998501,180}
					};
					limitsArrayBottom[]=
					{
						{-2,-180},
						{-1,-154.4525},
						{-5.8804998,-82.711601},
						{-8.9499998,20.756201},
						{-7.9499998,-20.756201},
						{-5.8804998,82.711601},
						{-1,153.1266},
						{-2,180}
					};
				};*/
				class HitPoints
				{
					class HitTurret
					{
						armor=1;
						material=-1;
						armorComponent="hit_mainturret";
						name="hit_mainturret_point";
						visual="mainturret_damage";
						passThrough=0;
						minimalHit=0.1;
						explosionShielding=0.2;
						radius=0.25;
						isTurret=1;
					};
					class HitGun
					{
						armor=0.60000002;
						material=-1;
						armorComponent="hit_maingun";
						name="hit_maingun_point";
						visual="maingun_damage";
						passThrough=0;
						minimalHit=0.1;
						explosionShielding=0.40000001;
						radius=0.2;
						isGun=1;
					};
				};
			};
			class LoaderTurret: NewTurret
			{
				class Turrets
				{
				};
				body="LoaderTurret";
				gun="LoaderGun";
				animationSourceBody = "LoaderTurret";
				animationSourceGun = "LoaderGun";
				animationSourceHatch="loaderhatch";
				gunBeg = "mag58_muzzle";
				gunEnd = "mag58_chamber";
				gunnerName="Loader";
				gunnerDoor = "loaderhatch";
				proxyType="CPGunner";
				particlesdir = "mag58_muzzle";
				particlespos = "mag58_chamber";
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				maxVerticalRotSpeed = 0.8;
				maxHorizontalRotSpeed = 1;
				proxyIndex=2;
				turretFollowFreeLook = 1;
				weapons[]=
				{
					"ADFRC_abrams_mag58"
				};
				magazines[]=
				{
					
					"ADFRC_abrams_200rnd_762x51_Tracer",
					"ADFRC_abrams_200rnd_762x51_Tracer",
					"ADFRC_abrams_200rnd_762x51_Tracer",
					"ADFRC_abrams_200rnd_762x51_Tracer",
					"ADFRC_abrams_200rnd_762x51_Tracer",
					"ADFRC_abrams_200rnd_762x51_Tracer",
					"ADFRC_abrams_200rnd_762x51_Tracer",
					"ADFRC_abrams_200rnd_762x51_Tracer",
					"ADFRC_abrams_200rnd_762x51_Tracer",
					"ADFRC_abrams_200rnd_762x51_Tracer",
					"ADFRC_abrams_200rnd_762x51_Tracer",
					"ADFRC_abrams_200rnd_762x51_Tracer",
					"ADFRC_abrams_200rnd_762x51_Tracer"
				};
				soundServo[]=
				{
					"A3\sounds_f\dummysound",
					0.0099999998,
					1,
					10
				};
				minElev=-18;
				initElev=0;
				maxElev=35;
				minTurn=-45;
				initTurn=0;
				maxTurn=160;
				gunnerRightHandAnimName="handle_l_2";
				gunnerLeftHandAnimName="handle_r_2";
				gunnerAction = "gunner_lsv_02";
				lockWhenDriverOut = 0;
				isPersonTurret = 0;
				gunnerInAction = "passenger_generic01_leanright";
				gunnerGetInAction="GetInhigh";
				gunnerGetOutAction="GetOuthigh";
				viewGunnerInExternal=0;
				castGunnerShadow=1;
				forceHideGunner=0;
				gunnerForceOptics=1;
				inGunnerMayFire=0;
				outGunnerMayFire=1;
				playerPosition = 0;
				discreteDistance[]={0,100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex=0;
				turretInfoType="";
				memoryPointGunnerOptics="loaderviewport_view";
				gunnerOpticsModel="\a3\weapons_f\Reticle\Optics_Driver_01_F.p3d";
				memoryPointGunnerOutOptics="loadereye";
				gunnerOutOpticsModel ="\A3\weapons_f\reticle\optics_empty";
				gunnerCompartments="Compartment1";
				selectionFireAnim="zasleh3";
				stabilizedInAxes=0;
				primaryGunner=0;
				primaryObserver=0;
				usePip=0;
				LODTurnedIn = 1;
				LODTurnedOut = 1;
				LODOpticsIn = 1;
				LODOpticsOut = 1;
				startEngine=0;
				disableSoundAttenuation=0;
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.8;
					minFov = 0.8;
					maxFov = 0.8;
				};
				class TurnIn
                {
					/*limitsArrayTop[] = {{-0, 0}};
                    limitsArrayBottom[] = {{-0, 0}};*/
				};
				class HitPoints
						{
							class HitLodTurret
							{
								armor=0.1;
								material=-1;
								armorComponent="hit_loaderturret";
								name="hit_loaderturret_point";
								visual="loaderturret";
								passThrough=0;
								minimalHit=0.1;
								explosionShielding=1;
								radius=0.15000001;
								isTurret=1;
							};
							class HitLodGun
							{
								armor=0.1;
								material=-1;
								armorComponent="hit_loadergun";
								name="hit_loadergun_point";
								visual="loadergun";
								passThrough=0;
								minimalHit=0.1;
								explosionShielding=1;
								radius=0.15000001;
								isGun=1;
							};
						};
			};
		};
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=1;
				material=-1;
				armorComponent="hit_hull";
				name="hit_hull_point";
				visual="hull_damage";
				passThrough=1;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.35;
			};
			class HitEngine: HitEngine
			{
				armor=0.5;
				material=-1;
				armorComponent="hit_engine";
				name="hit_engine_point";
				visual="engine_damage";
				passThrough=0.05;
				minimalHit=0.1;
				explosionShielding=0.2;
				radius=0.25;
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
				armor=0.5;
				material=-1;
				armorComponent="hit_fuel";
				name="hit_fuel_point";
				visual="-";
				passThrough=0;
				minimalHit=0.1;
				explosionShielding=0.2;
				radius=0.25;
			};
			class HitLTrack: HitLTrack
			{
				material=-1;
				armorComponent="hit_trackL";
				name="hit_trackL_point";
				visual="track_left_damage";
				radius=0.2;
				armor=-150;
				minimalHit=0.1;
				explosionShielding=0.5;
				passThrough=0;
			};
			class HitRTrack: HitRTrack
			{
				material=-1;
				armorComponent="hit_trackR";
				name="hit_trackR_point";
				visual="track_right_damage";
				radius=0.2;
				armor=-150;
				minimalHit=0.1;
				explosionShielding=0.5;
				passThrough=0;
			};
			class hit_era_l1_point
			{
				simulation = "Armor_ERA_Light";
				name = "hit_era_l1_point";
				armorComponent = "hit_era_l1";
				armor = -100;
				minimalHit = 1;
				radius = 0.3;
				passThrough = 0;
				visual = "-";
				explosionShielding = 2;
				class DestructionEffects
				{
					ammoExplosionEffect = "";
					effectRadius = 1;
					ignoreFuel = 1;
					class Explo
					{
						simulation = "particles";
						type = "MineExplosionParticles";
						position = "era_l1_pos";
						lifeTime = 0.01;
						interval = 1;
						intensity = 0.01;
					};
					class Smoke: Explo
					{
						type = "ERASmoke";
						lifeTime = 0.05;
					};
					class Sound: Explo
					{
						simulation = "sound";
						type = "ERA_Explosion";
						lifeTime = 1;
					};
				};
			};
			class hit_era_l2_point: hit_era_l1_point
			{
				name = "hit_era_l2_point";
				armorComponent = "hit_era_l2";
				class DestructionEffects
				{
					ammoExplosionEffect = "";
					effectRadius = 1;
					ignoreFuel = 1;
					class Explo
					{
						simulation = "particles";
						type = "MineExplosionParticles";
						position = "era_l2_pos";
						lifeTime = 0.01;
						interval = 1;
						intensity = 0.01;
					};
					class Smoke: Explo
					{
						type = "ERASmoke";
						lifeTime = 0.05;
					};
					class Sound: Explo
					{
						simulation = "sound";
						type = "ERA_Explosion";
						lifeTime = 1;
					};
				};
			};
			class hit_era_l3_point: hit_era_l1_point
			{
				name = "hit_era_l3_point";
				armorComponent = "hit_era_l3";
				class DestructionEffects
				{
					ammoExplosionEffect = "";
					effectRadius = 1;
					ignoreFuel = 1;
					class Explo
					{
						simulation = "particles";
						type = "MineExplosionParticles";
						position = "era_l3_pos";
						lifeTime = 0.01;
						interval = 1;
						intensity = 0.01;
					};
					class Smoke: Explo
					{
						type = "ERASmoke";
						lifeTime = 0.05;
					};
					class Sound: Explo
					{
						simulation = "sound";
						type = "ERA_Explosion";
						lifeTime = 1;
					};
				};
			};
			class hit_era_l4_point: hit_era_l1_point
			{
				name = "hit_era_l4_point";
				armorComponent = "hit_era_l4";
				class DestructionEffects
				{
					ammoExplosionEffect = "";
					effectRadius = 1;
					ignoreFuel = 1;
					class Explo
					{
						simulation = "particles";
						type = "MineExplosionParticles";
						position = "era_l4_pos";
						lifeTime = 0.01;
						interval = 1;
						intensity = 0.01;
					};
					class Smoke: Explo
					{
						type = "ERASmoke";
						lifeTime = 0.05;
					};
					class Sound: Explo
					{
						simulation = "sound";
						type = "ERA_Explosion";
						lifeTime = 1;
					};
				};
			};
			class hit_era_l5_point: hit_era_l1_point
			{
				name = "hit_era_l5_point";
				armorComponent = "hit_era_l5";
				class DestructionEffects
				{
					ammoExplosionEffect = "";
					effectRadius = 1;
					ignoreFuel = 1;
					class Explo
					{
						simulation = "particles";
						type = "MineExplosionParticles";
						position = "era_l5_pos";
						lifeTime = 0.01;
						interval = 1;
						intensity = 0.01;
					};
					class Smoke: Explo
					{
						type = "ERASmoke";
						lifeTime = 0.05;
					};
					class Sound: Explo
					{
						simulation = "sound";
						type = "ERA_Explosion";
						lifeTime = 1;
					};
				};
			};
			class hit_era_l6_point: hit_era_l1_point
			{
				name = "hit_era_l6_point";
				armorComponent = "hit_era_l6";
				class DestructionEffects
				{
					ammoExplosionEffect = "";
					effectRadius = 1;
					ignoreFuel = 1;
					class Explo
					{
						simulation = "particles";
						type = "MineExplosionParticles";
						position = "era_l6_pos";
						lifeTime = 0.01;
						interval = 1;
						intensity = 0.01;
					};
					class Smoke: Explo
					{
						type = "ERASmoke";
						lifeTime = 0.05;
					};
					class Sound: Explo
					{
						simulation = "sound";
						type = "ERA_Explosion";
						lifeTime = 1;
					};
				};
			};
			class hit_era_l7_point: hit_era_l1_point
			{
				name = "hit_era_l7_point";
				armorComponent = "hit_era_l7";
				class DestructionEffects
				{
					ammoExplosionEffect = "";
					effectRadius = 1;
					ignoreFuel = 1;
					class Explo
					{
						simulation = "particles";
						type = "MineExplosionParticles";
						position = "era_l7_pos";
						lifeTime = 0.01;
						interval = 1;
						intensity = 0.01;
					};
					class Smoke: Explo
					{
						type = "ERASmoke";
						lifeTime = 0.05;
					};
					class Sound: Explo
					{
						simulation = "sound";
						type = "ERA_Explosion";
						lifeTime = 1;
					};
				};
			};
			class hit_era_l8_point: hit_era_l1_point
			{
				name = "hit_era_l8_point";
				armorComponent = "hit_era_l8";
				class DestructionEffects
				{
					ammoExplosionEffect = "";
					effectRadius = 1;
					ignoreFuel = 1;
					class Explo
					{
						simulation = "particles";
						type = "MineExplosionParticles";
						position = "era_l8_pos";
						lifeTime = 0.01;
						interval = 1;
						intensity = 0.01;
					};
					class Smoke: Explo
					{
						type = "ERASmoke";
						lifeTime = 0.05;
					};
					class Sound: Explo
					{
						simulation = "sound";
						type = "ERA_Explosion";
						lifeTime = 1;
					};
				};
			};
			class hit_era_r1_point: hit_era_l1_point
			{
				name = "hit_era_r1_point";
				armorComponent = "hit_era_r1";
				class DestructionEffects
				{
					ammoExplosionEffect = "";
					effectRadius = 1;
					ignoreFuel = 1;
					class Explo
					{
						simulation = "particles";
						type = "MineExplosionParticles";
						position = "era_r1_pos";
						lifeTime = 0.01;
						interval = 1;
						intensity = 0.01;
					};
					class Smoke: Explo
					{
						type = "ERASmoke";
						lifeTime = 0.05;
					};
					class Sound: Explo
					{
						simulation = "sound";
						type = "ERA_Explosion";
						lifeTime = 1;
					};
				};
			};
			class hit_era_r2_point: hit_era_r1_point
			{
				name = "hit_era_r2_point";
				armorComponent = "hit_era_r2";
				class DestructionEffects
				{
					ammoExplosionEffect = "";
					effectRadius = 1;
					ignoreFuel = 1;
					class Explo
					{
						simulation = "particles";
						type = "MineExplosionParticles";
						position = "era_r2_pos";
						lifeTime = 0.01;
						interval = 1;
						intensity = 0.01;
					};
					class Smoke: Explo
					{
						type = "ERASmoke";
						lifeTime = 0.05;
					};
					class Sound: Explo
					{
						simulation = "sound";
						type = "ERA_Explosion";
						lifeTime = 1;
					};
				};
			};
			class hit_era_r3_point: hit_era_r1_point
			{
				name = "hit_era_r3_point";
				armorComponent = "hit_era_r3";
				class DestructionEffects
				{
					ammoExplosionEffect = "";
					effectRadius = 1;
					ignoreFuel = 1;
					class Explo
					{
						simulation = "particles";
						type = "MineExplosionParticles";
						position = "era_r3_pos";
						lifeTime = 0.01;
						interval = 1;
						intensity = 0.01;
					};
					class Smoke: Explo
					{
						type = "ERASmoke";
						lifeTime = 0.05;
					};
					class Sound: Explo
					{
						simulation = "sound";
						type = "ERA_Explosion";
						lifeTime = 1;
					};
				};
			};
			class hit_era_r4_point: hit_era_r1_point
			{
				name = "hit_era_r4_point";
				armorComponent = "hit_era_r4";
				class DestructionEffects
				{
					ammoExplosionEffect = "";
					effectRadius = 1;
					ignoreFuel = 1;
					class Explo
					{
						simulation = "particles";
						type = "MineExplosionParticles";
						position = "era_r4_pos";
						lifeTime = 0.01;
						interval = 1;
						intensity = 0.01;
					};
					class Smoke: Explo
					{
						type = "ERASmoke";
						lifeTime = 0.05;
					};
					class Sound: Explo
					{
						simulation = "sound";
						type = "ERA_Explosion";
						lifeTime = 1;
					};
				};
			};
			class hit_era_r5_point: hit_era_r1_point
			{
				name = "hit_era_r5_point";
				armorComponent = "hit_era_r5";
				class DestructionEffects
				{
					ammoExplosionEffect = "";
					effectRadius = 1;
					ignoreFuel = 1;
					class Explo
					{
						simulation = "particles";
						type = "MineExplosionParticles";
						position = "era_r5_pos";
						lifeTime = 0.01;
						interval = 1;
						intensity = 0.01;
					};
					class Smoke: Explo
					{
						type = "ERASmoke";
						lifeTime = 0.05;
					};
					class Sound: Explo
					{
						simulation = "sound";
						type = "ERA_Explosion";
						lifeTime = 1;
					};
				};
			};
			class hit_era_r6_point: hit_era_r1_point
			{
				name = "hit_era_r6_point";
				armorComponent = "hit_era_r6";
				class DestructionEffects
				{
					ammoExplosionEffect = "";
					effectRadius = 1;
					ignoreFuel = 1;
					class Explo
					{
						simulation = "particles";
						type = "MineExplosionParticles";
						position = "era_r6_pos";
						lifeTime = 0.01;
						interval = 1;
						intensity = 0.01;
					};
					class Smoke: Explo
					{
						type = "ERASmoke";
						lifeTime = 0.05;
					};
					class Sound: Explo
					{
						simulation = "sound";
						type = "ERA_Explosion";
						lifeTime = 1;
					};
				};
			};
			class hit_era_r7_point: hit_era_r1_point
			{
				name = "hit_era_r7_point";
				armorComponent = "hit_era_r7";
				class DestructionEffects
				{
					ammoExplosionEffect = "";
					effectRadius = 1;
					ignoreFuel = 1;
					class Explo
					{
						simulation = "particles";
						type = "MineExplosionParticles";
						position = "era_r7_pos";
						lifeTime = 0.01;
						interval = 1;
						intensity = 0.01;
					};
					class Smoke: Explo
					{
						type = "ERASmoke";
						lifeTime = 0.05;
					};
					class Sound: Explo
					{
						simulation = "sound";
						type = "ERA_Explosion";
						lifeTime = 1;
					};
				};
			};
			class hit_era_r8_point: hit_era_r1_point
			{
				name = "hit_era_r8_point";
				armorComponent = "hit_era_r8";
				class DestructionEffects
				{
					ammoExplosionEffect = "";
					effectRadius = 1;
					ignoreFuel = 1;
					class Explo
					{
						simulation = "particles";
						type = "MineExplosionParticles";
						position = "era_r8_pos";
						lifeTime = 0.01;
						interval = 1;
						intensity = 0.01;
					};
					class Smoke: Explo
					{
						type = "ERASmoke";
						lifeTime = 0.05;
					};
					class Sound: Explo
					{
						simulation = "sound";
						type = "ERA_Explosion";
						lifeTime = 1;
					};
				};
			};
		};
		destrType = "DestructBuilding";
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"ADF_Tracked\adfrc_abrams\Data\Standard\abramshull1.rvmat",
				"ADF_Tracked\adfrc_abrams\Data\Standard\abramshull1_damage.rvmat",
				"ADF_Tracked\adfrc_abrams\Data\Standard\abramshull1_wreck.rvmat",
				"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc1.rvmat",
				"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc1_damage.rvmat",
				"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc1_wreck.rvmat",
				"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc2.rvmat",
				"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc2_damage.rvmat",
				"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc2_wreck.rvmat",
				"ADF_Tracked\adfrc_abrams\Data\Standard\abramsturret1.rvmat",
				"ADF_Tracked\adfrc_abrams\Data\Standard\abramsturret1_damage.rvmat",
				"ADF_Tracked\adfrc_abrams\Data\Standard\abramsturret1_wreck.rvmat",
				"ADF_Tracked\adfrc_abrams\Data\Standard\abramswheels.rvmat",
				"ADF_Tracked\adfrc_abrams\Data\Standard\abramswheels_damage.rvmat",
				"ADF_Tracked\adfrc_abrams\Data\Standard\abramswheels_wreck.rvmat",
				"ADF_Tracked\adfrc_abrams\Data\abrams_tracks.rvmat",
				"ADF_Tracked\adfrc_abrams\Data\abrams_tracks_damage.rvmat",
				"ADF_Tracked\adfrc_abrams\Data\abrams_tracks_wreck.rvmat",
			};
		};
		class AnimationSources
		{
			class maingun_recoil
			{
				source="reloadMagazine";
				weapon="ADFRC_abrams_M256";
			};
			class zasleh_rot
			{
				source="ammorandom";
				weapon="ADFRC_abrams_M256";
			};
			class zasleh_hide
			{
				source="reloadMagazine";
				weapon="ADFRC_abrams_M256";
			};
			class zasleh_1_rot
			{
				source="ammorandom";
				weapon="ADFRC_abrams_coax";
			};
			class zasleh_1_hide
			{
				source="reload";
				weapon="ADFRC_abrams_coax";
			};
			class zasleh_2_rot
			{
				source="ammorandom";
				weapon="ADFRC_abrams_M2HBQCB";
			};
			class zasleh_2_hide
			{
				source="reload";
				weapon="ADFRC_abrams_M2HBQCB";
			};
			class zasleh_3_rot
			{
				source="ammorandom";
				weapon="ADFRC_abrams_mag58";
			};
			class zasleh_3_hide
			{
				source="reload";
				weapon="ADFRC_abrams_mag58";
			};
			class Smoke_source
			{
				source="revolving";
				weapon="SmokeLauncher";
			};
			class reloadanim_m2
			{
				source="reload";
				weapon="ADFRC_abrams_M2HBQCB";
			};
			class reloadmagazine_m2
			{
				source="reloadmagazine";
				weapon="ADFRC_abrams_M2HBQCB";
			};
			class Revolving_m2
			{
				source="revolving";
				weapon="ADFRC_abrams_M2HBQCB";
			};
			class reloadanim_mag58
			{
				source="reload";
				weapon="ADFRC_abrams_MAG58";
			};
			class reloadmagazine_mag58
			{
				source="reloadmagazine";
				weapon="ADFRC_abrams_MAG58";
			};
			class revolving_mag58
			{
				source="revolving";
				weapon="ADFRC_abrams_MAG58";
			};
			class towcable
			{
				DisplayName="Turret Tow Cable";
				source="user";
				animPeriod=0;
				initPhase=1;
				author="ADFRC";
			};
			class sparewheelsturret
			{
				DisplayName="Spare Wheels - Basket";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class sparewheelroof
			{
				DisplayName="Spare Wheel - Roof";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class sparetracks
			{
				DisplayName="Spare Tracks";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class towshackles
			{
				DisplayName="Recovery Shackles";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class sprocketcovers
			{
				DisplayName="Sprocket Covers";
				source="user";
				animPeriod=0;
				initPhase=1;
				author="ADFRC";
			};
			/*class abramstowbar --- Undergoing rework, shitty mesh lol
			{
				DisplayName="Front Tow Bar";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};*/
			class turretjerrys
			{
				DisplayName="Turret Jerry Cans";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class plowframe
			{
				DisplayName="Mine Plow (+7.0T)";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
				mass = 7000;
			};
			class plow
			{
				source="door";
				initPhase=0;
				animPeriod=3;
				sound = "ServoRampSound_2";
			};
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
			class turret_net_short
			{
				DisplayName="Camo Net - Turret (Short)";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class turret_net_roof
			{
				DisplayName="Camo Net - Shade";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class barrel_net
			{
				DisplayName="Camo Net - barrel";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
				forceAnimatePhase = 1;
				forceAnimate[] = {"barrel_recoil_net",1};
				forceAnimate2[] = {"barrel_recoil_net",0};
			};
			class barrel_recoil_net
			{
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class loadersandbags
			{
				DisplayName="Loaders Sandbag Armor";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class equipment1
			{
				DisplayName="Field Equipment 1 (Rear)";
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
			};
			class equipment1_r
			{
				DisplayName="Field Equipment 1 (Right)";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class equipment1_t
			{
				DisplayName="Field Equipment 1 (Roof)";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			/*class equipment2
			{
				DisplayName="Field Equipment 2 (Rear)";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class equipment2_l
			{
				DisplayName="Field Equipment 2 (Left)";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class equipment2_r
			{
				DisplayName="Field Equipment 2 (Right)";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class equipment2_t
			{
				DisplayName="Field Equipment 2 (Roof)";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class equipment3
			{
				DisplayName="Field Equipment 3 (Rear)";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class equipment3_l
			{
				DisplayName="Field Equipment 3 (Left)";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class equipment3_r
			{
				DisplayName="Field Equipment 3 (Right)";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class equipment3_t
			{
				DisplayName="Field Equipment 3 (Roof)";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class label_roo
			{
				DisplayName="Switch to Red Kangaroo";
				source= "user";
				initPhase= 1;
				animPeriod=0.001;
				author="Quiggs";
			};
			*/
			class driverhatch
			{
				source="door";
				initPhase=0;
				animPeriod=1;
			};
			class loaderhatch
			{
				source="door";
				initPhase=0;
				animPeriod=1;
			};
			class commanderhatch
			{
				source="door";
				initPhase=0;
				animPeriod=1;
			};
			class HitERA_Left_1_src
			{
				source = "Hit";
				hitpoint = "hit_era_l1_point";
				raw = 1;
			};
			class HitERA_Left_2_src
			{
				source = "Hit";
				hitpoint = "hit_era_l2_point";
				raw = 1;
			};
			class HitERA_Left_3_src
			{
				source = "Hit";
				hitpoint = "hit_era_l3_point";
				raw = 1;
			};
			class HitERA_Left_4_src
			{
				source = "Hit";
				hitpoint = "hit_era_l4_point";
				raw = 1;
			};
			class HitERA_Left_5_src
			{
				source = "Hit";
				hitpoint = "hit_era_l5_point";
				raw = 1;
			};
			class HitERA_Left_6_src
			{
				source = "Hit";
				hitpoint = "hit_era_l6_point";
				raw = 1;
			};
			class HitERA_Left_7_src
			{
				source = "Hit";
				hitpoint = "hit_era_l7_point";
				raw = 1;
			};
			class HitERA_Left_8_src
			{
				source = "Hit";
				hitpoint = "hit_era_l8_point";
				raw = 1;
			};
			class HitERA_Right_1_src
			{
				source = "Hit";
				hitpoint = "hit_era_r1_point";
				raw = 1;
			};
			class HitERA_Right_2_src
			{
				source = "Hit";
				hitpoint = "hit_era_r2_point";
				raw = 1;
			};
			class HitERA_Right_3_src
			{
				source = "Hit";
				hitpoint = "hit_era_r3_point";
				raw = 1;
			};
			class HitERA_Right_4_src
			{
				source = "Hit";
				hitpoint = "hit_era_r4_point";
				raw = 1;
			};
			class HitERA_Right_5_src
			{
				source = "Hit";
				hitpoint = "hit_era_r5_point";
				raw = 1;
			};
			class HitERA_Right_6_src
			{
				source = "Hit";
				hitpoint = "hit_era_r6_point";
				raw = 1;
			};
			class HitERA_Right_7_src
			{
				source = "Hit";
				hitpoint = "hit_era_r7_point";
				raw = 1;
			};
			class HitERA_Right_8_src
			{
				source = "Hit";
				hitpoint = "hit_era_r8_point";
				raw = 1;
			};
		};
		animationList[]=
		{
			"sprocketcovers",
			1,
		};
		hiddenSelections[]=
		{
			"abramshull1",
			"abramsmisc1",
			"abramsmisc2",
			"abramsturret1",
			"abramswheels",
			"plow",
			"label_hull",
			"label_barrel",
			"label_callsign",
		};
		hiddenSelectionsTextures[]=
		{
			"ADF_Tracked\adfrc_abrams\Data\Standard\abramshull1_co.paa",
			"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc1_co.paa",
			"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc2_co.paa",
			"ADF_Tracked\adfrc_abrams\Data\Standard\abramsturret1_co.paa",
			"ADF_Tracked\adfrc_abrams\Data\Standard\abramswheels_co.paa",
			"ADF_Tracked\adfrc_abrams\Data\plow\plow_co.paa",
			"\ADF_Tracked\adfrc_abrams\Data\labels\labels_01.paa",
			"\ADF_Tracked\adfrc_abrams\Data\labels\labels_01.paa",
			"\ADF_Tracked\adfrc_abrams\Data\labels\labels_01.paa",
		};
		class TextureSources
		{
			class Standard
			{
				displayName="Standard";
				author="ADFRC_Quiggs";
				textures[]=
				{
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramshull1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc2_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramsturret1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramswheels_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\plow\plow_co.paa",
				};
			};
			class Fishscale
			{
				displayName="Fish Scale";
				author="ADFRC_Quiggs";
				textures[]=
				{
					"ADF_Tracked\adfrc_abrams\Data\fish\abramshull1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc2_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\fish\abramsturret1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramswheels_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\plow\plow_co.paa",
				};
			};
			class Polka
			{
				displayName="Polka Dot";
				author="ADFRC_Quiggs";
				textures[]=
				{
					"ADF_Tracked\adfrc_abrams\Data\polka\abramshull1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc2_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\polka\abramsturret1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramswheels_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\plow\plow_co.paa",
				};
			};
			class Lines
			{
				displayName="Lines";
				author="ADFRC_Quiggs";
				textures[]=
				{
					"ADF_Tracked\adfrc_abrams\Data\tiger\abramshull1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc2_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\tiger\abramsturret1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramswheels_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\plow\plow_co.paa",
				};
			};
			class Garudashield
			{
				displayName="Garuda Shield";
				author="ADFRC_Quiggs";
				textures[]=
				{
					"ADF_Tracked\adfrc_abrams\Data\garuda\abramshull1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\garuda\abramsmisc1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\garuda\abramsmisc2_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\garuda\abramsturret1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\garuda\abramswheels_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\plow\plow_co.paa",
				};
			};
		};
		class UVAnimations
		{
			class label_roo
			{
				type			= "translation";
				source			= "label_roo";
				section			= "label_roo";
				minValue		= 0;
				maxValue		= 1;
				offset0[]		= { 0, 0 };
				offset1[]		= { 0, 0.463509 };
			};
		};
		class Sounds
		{
			class Engine
			{
				sound[]=
				{
					"a3\sounds_f_jets\vehicles\air\plane_fighter_02\o_plane_fighter_02_engine_low_ext",
					1,
					1,
					500
				};
				frequency="0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_ext
			{
				sound[]=
				{
					"a3\sounds_f_jets\vehicles\air\plane_fighter_02\o_plane_fighter_02_engine_low_ext",
					1.1220185,
					1.2,
					320
				};
				frequency="0.8 + ((rpm/ 3000) factor[(950/ 3000),(1400/ 3000)])*0.2";
				volume="engineOn*camPos*(((rpm/ 3000) factor[(900/ 3000),(1050/ 3000)]) * ((rpm/ 3000) factor[(1400/ 3000),(1200/ 3000)]))";
			};
			class Engine2_ext
			{
				sound[]=
				{
					"a3\sounds_f_jets\vehicles\air\plane_fighter_02\o_plane_fighter_02_engine_low_ext",
					1.2589254,
					1.4,
					360
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1200/ 3000),(1700/ 3000)])*0.2";
				volume="engineOn*camPos*(((rpm/ 3000) factor[(1170/ 3000),(1380/ 3000)]) * ((rpm/ 3000) factor[(1700/ 3000),(1500/ 3000)]))";
			};
			class Engine3_ext
			{
				sound[]=
				{
					"a3\sounds_f_jets\vehicles\air\plane_fighter_02\o_plane_fighter_02_engine_low_ext",
					1.4125376,
					1.8,
					400
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1500/ 3000),(2100/ 3000)])*0.1";
				volume="engineOn*camPos*(((rpm/ 3000) factor[(1500/ 3000),(1670/ 3000)]) * ((rpm/ 3000) factor[(2100/ 3000),(1800/ 3000)]))";
			};
			class Engine4_ext
			{
				sound[]=
				{
					"a3\sounds_f_jets\vehicles\air\plane_fighter_02\o_plane_fighter_02_engine_low_ext",
					1.5848932,
					2.2,
					440
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1800/ 3000),(2300/ 3000)])*0.1";
				volume="engineOn*camPos*(((rpm/ 3000) factor[(1780/ 3000),(2060/ 3000)]) * ((rpm/ 3000) factor[(2450/ 3000),(2200/ 3000)]))";
			};
			class Engine5_ext
			{
				sound[]=
				{
					"a3\sounds_f_jets\vehicles\air\plane_fighter_02\o_plane_fighter_02_engine_low_ext",
					1.7782794,
					2.6,
					480
				};
				frequency="0.8 + ((rpm/ 3000) factor[(2100/ 3000),(3000/ 3000)])*0.1";
				volume="engineOn*camPos*((rpm/ 3000) factor[(2150/ 3000),(2500/ 3000)])";
			};
			class EngineThrust
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_ext_rpm2",
					1.4125376,
					1,
					200
				};
				frequency="0.8 + ((rpm/ 3000) factor[(700/ 3000),(1100/ 3000)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(705/ 3000),(850/ 3000)]) * ((rpm/ 3000) factor[(1100 / 3000),(950/ 3000)]))";
			};
			class Engine1_Thrust_ext
			{
				sound[]=
				{
					"ADF_Tracked\adfrc_abrams\sounds\vehicles\tracked\M1A1\ext\ext-m1acceleration-01",
					1.7782794,
					1.1,
					230
				};
				frequency="0.8 + ((rpm/ 3000) factor[(950/ 3000),(1400/ 3000)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(900/ 3000),(1050/ 3000)]) * ((rpm/ 3000) factor[(1400/ 3000),(1200/ 3000)]))";
			};
			class Engine2_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_ext_rpm4",
					1.9952624,
					1.2,
					290
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1200/ 3000),(1700/ 3000)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(1170/ 3000),(1380/ 3000)]) * ((rpm/ 3000) factor[(1700/ 3000),(1500/ 3000)]))";
			};
			class Engine3_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_ext_rpm5",
					1.7782794,
					1.3,
					350
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1500/ 3000),(2100/ 3000)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(1500/ 3000),(1670/ 3000)]) * ((rpm/ 3000) factor[(2100/ 3000),(1800/ 3000)]))";
			};
			class Engine4_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_ext_rpm6",
					2.2387211,
					1.4,
					400
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1800/ 3000),(2300/ 3000)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(1780/ 3000),(2060/ 3000)]) * ((rpm/ 3000) factor[(2450/ 3000),(2200/ 3000)]))";
			};
			class Engine5_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_ext_rpm7",
					2.5118864,
					1.5,
					450
				};
				frequency="0.8 + ((rpm/ 3000) factor[(2100/ 3000),(3000/ 3000)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 3000) factor[(2150/ 3000),(2500/ 3000)])";
			};
			class IdleOut
			{
				sound[]=
				{
					"ADF_Tracked\adfrc_abrams\sounds\vehicles\tracked\M1A1\ext\ext-m1idle-02",
					0.63095737,
					1.1,
					500
				};
				frequency="0.95 + ((rpm/ 3000) factor[(400/ 3000),(900/ 3000)])*0.15";
				volume="engineOn*camPos*(((rpm/ 3000) factor[(100/ 3000),(200/ 3000)]) * ((rpm/ 3000) factor[(900/ 3000),(700/ 3000)]))";
			};
			class NoiseOut
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\ext\noise2",
					1,
					1,
					400
				};
				frequency="1";
				volume="camPos*(angVelocity max 0.04)*(speed factor[4, 15])";
			};
			class ThreadsOutH0
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\ext\ext-m1treads-hard-01",
					1.7782794,
					1,
					250
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsOutH1
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\ext\ext-m1treads-hard-02",
					1.7782794,
					1,
					250
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsOutH2
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\ext\ext-m1treads-hard-03",
					1.7782794,
					1,
					250
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsOutH3
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\ext\ext-m1treads-hard-04",
					1.7782794,
					1,
					250
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsOutH4
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\ext\ext-m1treads-hard-05",
					1.7782794,
					1,
					250
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class ThreadsOutS0
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\ext\ext-m1treads-soft-01",
					1.7782794,
					1,
					250
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsOutS1
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\ext\ext-m1treads-soft-02",
					1.7782794,
					1,
					250
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsOutS2
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\ext\ext-m1treads-soft-03",
					1.7782794,
					1,
					250
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsOutS3
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\ext\ext-m1treads-soft-04",
					1.7782794,
					1,
					250
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsOutS4
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\ext\ext-m1treads-soft-05",
					1.7782794,
					1,
					250
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class Movement
			{
				sound[]=
				{
					"",
					1,
					1
				};
				frequency="0";
				volume="0";
			};
			class Engine_int
			{
				sound[]=
				{
					"a3\sounds_f_jets\vehicles\air\plane_fighter_02\o_plane_fighter_02_engine_low_int",
					0.35481337,
					2
				};
				frequency="0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class IdleIn
			{
				sound[]=
				{
					"a3\sounds_f_jets\vehicles\air\plane_fighter_02\o_plane_fighter_02_engine_forsage_int",
					1,
					2
				};
				frequency="0.8 + ((rpm/ 3000) factor[(400/ 3000),(900/ 3000)])*0.15";
				volume="engineOn*(1-camPos)*(((rpm/ 3000) factor[(100/ 3000),(200/ 3000)]) * ((rpm/ 3000) factor[(900/ 3000),(700/ 3000)]))";
			};
			class NoiseIn
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\int\noise2",
					0.25118864,
					1
				};
				frequency="1";
				volume="(1-camPos)*(angVelocity max 0.04)*(speed factor[4, 15])";
			};
			class ThreadsInH0
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\int\int-m1treads-hard-01",
					1,
					0.75
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsInH1
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\int\int-m1treads-hard-02",
					1,
					0.75
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsInH2
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\int\int-m1treads-hard-03",
					1,
					0.75
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsInH3
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\int\int-m1treads-hard-04",
					1,
					0.75
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsInH4
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\int\int-m1treads-hard-05",
					1,
					0.75
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class ThreadsInS0
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\int\int-m1treads-soft-01",
					1,
					0.75
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsInS1
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\int\int-m1treads-soft-02",
					1,
					0.75
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsInS2
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\int\int-m1treads-soft-03",
					1,
					0.75
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsInS3
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\int\int-m1treads-soft-04",
					1,
					0.75
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsInS4
			{
				sound[]=
				{
					"adf_tracked\adfrc_abrams\sounds\Vehicles\Tracked\M1A1\int\int-m1treads-soft-05",
					1,
					0.75
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class Engine1_int
			{
				sound[]=
				{
					"a3\sounds_f_jets\vehicles\air\plane_fighter_02\o_plane_fighter_02_engine_low_int",
					0.39810717,
					1.4
				};
				frequency="0.8 + ((rpm/ 3000) factor[(950/ 3000),(1400/ 3000)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 3000) factor[(900/ 3000),(1050/ 3000)]) * ((rpm/ 3000) factor[(1400/ 3000),(1200/ 3000)]))";
			};
			class Engine2_int
			{
				sound[]=
				{
					"a3\sounds_f_jets\vehicles\air\plane_fighter_02\o_plane_fighter_02_engine_low_int",
					0.44668359,
					1.5
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1200/ 3000),(1700/ 3000)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 3000) factor[(1170/ 3000),(1380/ 3000)]) * ((rpm/ 3000) factor[(1700/ 3000),(1500/ 3000)]))";
			};
			class Engine3_int
			{
				sound[]=
				{
					"a3\sounds_f_jets\vehicles\air\plane_fighter_02\o_plane_fighter_02_engine_low_int",
					0.50118721,
					1.6
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1500/ 3000),(2100/ 3000)])*0.1";
				volume="engineOn*(1-camPos)*(((rpm/ 3000) factor[(1500/ 3000),(1670/ 3000)]) * ((rpm/ 3000) factor[(2100/ 3000),(1800/ 3000)]))";
			};
			class Engine4_int
			{
				sound[]=
				{
					"a3\sounds_f_jets\vehicles\air\plane_fighter_02\o_plane_fighter_02_engine_low_int",
					0.56234133,
					1.7
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1800/ 3000),(2300/ 3000)])*0.1";
				volume="engineOn*(1-camPos)*(((rpm/ 3000) factor[(1780/ 3000),(2060/ 3000)]) * ((rpm/ 3000) factor[(2450/ 3000),(2200/ 3000)]))";
			};
			class Engine5_int
			{
				sound[]=
				{
					"a3\sounds_f_jets\vehicles\air\plane_fighter_02\o_plane_fighter_02_engine_low_int",
					0.63095737,
					1.8
				};
				frequency="0.8 + ((rpm/ 3000) factor[(2100/ 3000),(3000/ 3000)])*0.1";
				volume="engineOn*(1-camPos)*((rpm/ 3000) factor[(2150/ 3000),(2500/ 3000)])";
			};
			class IdleThrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_int_rpm1",
					0.63095737,
					1.4
				};
				frequency="0.8 + ((rpm/ 3000) factor[(400/ 3000),(900/ 3000)])*0.15";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(100/ 3000),(200/ 3000)]) * ((rpm/ 3000) factor[(900/ 3000),(700/ 3000)]))";
			};
			class EngineThrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_int_rpm2",
					0.39810717,
					1.4
				};
				frequency="0.8 + ((rpm/ 3000) factor[(700/ 3000),(1100/ 3000)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(705/ 3000),(850/ 3000)]) * ((rpm/ 3000) factor[(1100 / 3000),(950/ 3000)]))";
			};
			class Engine1_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_int_rpm3",
					0.44668359,
					1.4
				};
				frequency="0.8 + ((rpm/ 3000) factor[(950/ 3000),(1400/ 3000)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(900/ 3000),(1050/ 3000)]) * ((rpm/ 3000) factor[(1400/ 3000),(1200/ 3000)]))";
			};
			class Engine2_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_int_rpm4",
					0.44668359,
					1.4
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1200/ 3000),(1700/ 3000)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(1170/ 3000),(1380/ 3000)]) * ((rpm/ 3000) factor[(1700/ 3000),(1500/ 3000)]))";
			};
			class Engine3_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_int_rpm5",
					0.50118721,
					1.4
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1500/ 3000),(2100/ 3000)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(1500/ 3000),(1670/ 3000)]) * ((rpm/ 3000) factor[(2100/ 3000),(1800/ 3000)]))";
			};
			class Engine4_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_int_rpm6",
					0.56234133,
					1.4
				};
				frequency="0.8 + ((rpm/ 3000) factor[(1800/ 3000),(2300/ 3000)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 3000) factor[(1780/ 3000),(2060/ 3000)]) * ((rpm/ 3000) factor[(2450/ 3000),(2200/ 3000)]))";
			};
			class Engine5_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\MBT_01\MBT1_exhaust_int_rpm7",
					0.63095737,
					1.4
				};
				frequency="0.8 + ((rpm/ 3000) factor[(2100/ 3000),(3000/ 3000)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 3000) factor[(2150/ 3000),(2500/ 3000)])";
			};
		};
		soundEngineOnInt[]=
		{
			"a3\sounds_f_jets\vehicles\air\plane_fighter_02\o_plane_fighter_02_engine_start_int",
			0.31622776,
			1
		};
		soundEngineOnExt[]=
		{
			"a3\sounds_f_jets\vehicles\air\plane_fighter_02\o_plane_fighter_02_engine_start_ext",
			0.56234133,
			2,
			400
		};
		soundEngineOffInt[]=
		{
			"a3\sounds_f_jets\vehicles\air\plane_fighter_02\o_plane_fighter_02_engine_shut_int",
			0.31622776,
			1
		};
		soundEngineOffExt[]=
		{
			"a3\sounds_f_jets\vehicles\air\plane_fighter_02\o_plane_fighter_02_engine_shut_ext",
			0.56234133,
			2,
			600
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
		class Library
		{
			libTextDesc="M1A1AIM";
		};
		class Attributes
		{
			class PlatoonMarkings
			{
				//--- Mandatory properties
				displayName = "Vehicle Callsigns";
				tooltip = "The vehicle callsign shown on the sides and back of the vehicle";
				property = "ADFRC_PlatoonMarkings_Abrams"; //Unique config property name saved in SQM
				control = "Combo"; //UI control base class displayed in Edit Attributes window, points to Cfg3DEN >> Attributes

				//Expression called when applying the attribute in Eden and at the scenario start
				//The expression is called twice - first for data validation, and second for actual saving
				//Entity is passed as _this, value is passed as _value
				//%s is replaced by attribute config name. It can be used only once in the expression
				//In MP scenario, the expression is called only on server.
				expression = "_this setVariable ['%s', _value, true]; private _i = _value; if (_value isEqualTo 0) then {_i = floor (random 7) + 1}; private _f = if (_i < 10) then {format ['\ADF_Tracked\adfrc_abrams\Data\labels\labels_0%1.paa', _i]} else {format ['\ADF_Tracked\adfrc_abrams\Data\labels\labels_%1.paa', _i]}; {_this setObjectTextureGlobal [_x, _f]} forEach [6, 7, 8];";

				//Expression called when custom property is undefined yet (i.e., when setting the attribute for the first time)
				//Entity (unit, group, marker, comment etc.) is passed as _this
				//Returned value is the default value
				//Used when no value is returned, or when it is of other type than NUMBER, STRING or ARRAY
				//Custom attributes of logic entities (e.g., modules) are saved always, even when they have default value
				defaultValue = 0;
				
				class Values 
				{
					class One {
						name = "Carnotaurus | 31B";
						tooltip = "Select this callsign";
						value = 1;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_01.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_01.paa";
					};
					class Two: One {
						name = "Commisar | 31C";
						value = 2;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_02.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_02.paa";
					};
					class Three: One {
						name = "Bojo | 33B";
						value = 3;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_03.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_03.paa";
					};
					class Four: One {
						name = "Conchoraptor | 31";
						value = 4;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_04.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_04.paa";
					};
					class Five: One {
						name = "Charging Rhino | 21A";
						value = 5;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_05.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_05.paa";
					};
					class Six: One {
						name = "Chewbacca | 33";
						value = 6;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_06.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_06.paa";
					};
					class Seven: One {
						name = "Checkmate | 32A";
						value = 7;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_07.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_07.paa";
					};
					/*class Eight: One {
						name = "Atomic | 13A";
						value = 8;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_08.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_08.paa";
					};
					class Nine: One {
						name = "Cannibal | 33B";
						value = 9;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_09.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_09.paa";
					};
					class Ten: One {
						name = "Bourbon | 23B";
						value = 10;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_10.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_10.paa";
					};
					class Eleven: One {
						name = "Cant Help Ya | 21A";
						value = 11;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_11.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_11.paa";
					};
					class Twelve: One {
						name = "ANZAC | 11A";
						value = 12;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_12.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_12.paa";
					};
					class Thirteen: One {
						name = "Angry Bird | 9A";
						value = 13;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_13.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_13.paa";
					};
					class Fourteen: One {
						name = "Atlas | 13B";
						value = 14;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_14.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_14.paa";
					};
					class Fifteen: One {
						name = "Achilles | 22C";
						value = 15;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_15.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_15.paa";
					};
					class Sixteen: One {
						name = "Boomer | 31A";
						value = 16;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_16.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_16.paa";
					};
					class Seventeen: One {
						name = "Big Papi | 23C";
						value = 17;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_17.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_17.paa";
					};
					class Eighteen: One {
						name = "Blame | 21B";
						value = 18;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_18.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_18.paa";
					};
					class Nineteen: One {
						name = "Boxer | 2F";
						value = 19;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_19.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_19.paa";
					};
					class Twenty: One {
						name = "Hammersley | 0C";
						value = 20;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_20.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_20.paa";
					};
					class TwentyOne: One {
						name = "Hold My Brew | 0F";
						value = 21;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_21.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_21.paa";
					};
					class TwentyTwo: One {
						name = "Akula | 1D";
						value = 22;
						picture = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_22.paa";
						pictureRight = "\ADF_Tracked\adfrc_abrams\Data\labels\labels_22.paa";
					};*/
					class Zero: One {
						name = "Random";
						tooltip = "Choose the markings randomly.";
						value = 0;
					};
				};
				
				//--- Optional properties
				unique = 0; // When 1, only one entity of the type can have the value in the mission (used for example for variable names or player control)
				validate = "number"; // Validate the value before saving. If the value is not of given type e.g. "number", the default value will be set. Can be "none", "expression", "condition", "number" or "variable"
				condition = "_this isKindOf 'adfrc_abrams'"; // Condition for attribute to appear (see the table below)
				typeName = "NUMBER"; // Defines data type of saved value, can be STRING, NUMBER or BOOL. Used only when control is "Combo", "Edit" or their variants
			};
		};
	};
	class adfrc_m1a1aim_md: adfrc_abrams
	{
		displayName="M1A1AIM";
		author="ADFRC - Quiggs";
		editorPreview = "\ADF_Tracked\adfrc_abrams\data\adfrc_m1a1aim_md.jpg";
		model="ADF_Tracked\adfrc_abrams\adfrc_m1a1aim.p3d";
		picture="ADF_Tracked\adfrc_abrams\adfrc_m1a1aim_icon";
		icon="\ADF_Tracked\adfrc_abrams\data\UI\icomap_m1a1_CA.paa";
		side=1;
		scope=2;
		faction="ADFRC_F_MD";
		vehicleClass="Armored";
		crew="ADFRC_MD_AMCU_Soldier_Crewman";
		typicalCargo[]={};
	};
	class adfrc_m1a1aim_gwot: adfrc_m1a1aim_md
	{
		faction="ADFRC_F_GWOT";
		crew="ADFRC_crewman_dpcu";
	};
	class adfrc_m1a2sepv3_md: adfrc_abrams
	{
		displayName="M1A2SEPv3";
		author="ADFRC - Quiggs";
		editorPreview = "\ADF_Tracked\adfrc_abrams\data\adfrc_m1a2sepv3_md.jpg";
		model="ADF_Tracked\adfrc_abrams\adfrc_m1a2sepv3.p3d";
		picture="ADF_Tracked\adfrc_abrams\adfrc_m1a1aim_icon";
		icon="\ADF_Tracked\adfrc_abrams\data\UI\icomap_m1a2tusk_CA.paa";
		side=1;
		scope=2;
		faction="ADFRC_F_MD";
		vehicleClass="Armored";
		crew="ADFRC_MD_AMCU_Soldier_Crewman";
		typicalCargo[]={};
		class ViewOptics: ViewOptics
		{
			visionMode[]=
			{
				"Normal",
				"NVG",
				"TI",
			};
			initFov=1.1;
			minFov=1.1;
			maxFov=1.1;
			thermalMode[]={0,1};
			thermalResolution[] = {1920};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						minElev=-20;
						maxElev=60;
						initOutTurn=0;
						weapons[]=
						{
							"ADFRC_abrams_M2HBQCB_RWS",
							"Laserdesignator_vehicle",
							"SmokeLauncher"
						};
						magazines[]=
						{
							"100rnd_127x99_mag_Tracer_Red",
							"100rnd_127x99_mag_Tracer_Red",
							"100rnd_127x99_mag_Tracer_Red",
							"100rnd_127x99_mag_Tracer_Red",
							"100rnd_127x99_mag_Tracer_Red",
							"100rnd_127x99_mag_Tracer_Red",
							"100rnd_127x99_mag_Tracer_Red",
							"100rnd_127x99_mag_Tracer_Red",
							"100rnd_127x99_mag_Tracer_Red",
							"100rnd_127x99_mag_Tracer_Red",
							"Laserbatteries",
							"SmokeLauncherMag"
						};
						soundServo[]=
						{
							"A3\Sounds_F\vehicles\armor\noises\servo_armor_comm",
							0.56234133,
							0.8,
							30
						};
						soundServoVertical[]=
						{
							"A3\Sounds_F\vehicles\armor\noises\servo_armor_comm",
							0.56234133,
							1,
							30
						};
						
						gunnerOpticsEffect[]={"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
						maxHorizontalRotSpeed = "((360/6)/45)";
						maxVerticalRotSpeed = "((360/6)/45)";
						turretInfoType = "RscOptics_APC_Wheeled_03_commander";
						stabilizedInAxes=3;
						class OpticsIn
						{
							class rwssight_x1
							{
								gunnerOpticsModel = "\A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
								gunnerOpticsEffect[] = {"OpticsBlur1","OpticsCHAbera1"};
								initAngleX=0;
								minAngleX=-30;
								maxAngleX=30;
								initAngleY=0;
								minAngleY=-100;
								maxAngleY=100;
								camPos = "commander_digital_view_pos";
								camDir = "commander_digital_view_dir";
								initFov="0.4/1";
								minFov="0.4/1";
								maxFov="0.4/1";
								visionMode[]=
								{
									"Normal",
									"TI",
								};
								thermalMode[]={0,1};
								thermalResolution[] = {1920};
							};
							class rwssight_x6: rwssight_x1
							{
								gunnerOpticsModel = "\A3\Weapons_F\Reticle\Optics_Gunner_APC_03_m_F.p3d";
								initFov="0.4/3";
								minFov="0.4/3";
								maxFov="0.4/3";
							};
							class rwssight_x10: rwssight_x6
							{
								gunnerOpticsModel = "\A3\Weapons_F\Reticle\Optics_Gunner_APC_03_n_F.p3d";
								initFov="0.4/8";
								minFov="0.4/8";
								maxFov="0.4/8";
							};
							class citv_13x: rwssight_x10
							{
								gunnerOpticsModel = "\A3\Weapons_F\Reticle\Optics_Commander_02_w_F.p3d";
								camPos = "commander_citv_view_pos";
								camDir = "commander_citv_view_dir";
								initFov="0.4/13";
								minFov="0.4/13";
								maxFov="0.4/13";
							};
							class citv_25x: citv_13x
							{
								gunnerOpticsModel = "\A3\Weapons_F\Reticle\Optics_Commander_02_m_F.p3d";
								initFov="0.4/25";
								minFov="0.4/25";
								maxFov="0.4/25";
								visionMode[]=
								{
									"TI",
								};
							};
							class citv_50x: citv_25x
							{
								gunnerOpticsModel = "\A3\Weapons_F\Reticle\Optics_Commander_02_n_F.p3d";
								initFov="0.4/50";
								minFov="0.4/50";
								maxFov="0.4/50";
								visionMode[]=
								{
									"TI",
								};
							};
						};
					};
				};
				maxHorizontalRotSpeed = "((360/12)/45)";
				maxVerticalRotSpeed = "((360/21)/45)";
				minOutElev=-20;
				maxOutElev=65;
				initOutElev=0;
				minOutTurn=-135;
				maxOutTurn=135;
				initOutTurn=0;
				
				class OpticsIn
				{
					class unitysight
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						gunnerOpticsModel="\a3\weapons_f\Reticle\Optics_Driver_01_F.p3d";
						gunnerOpticsEffect[] = {""};
						camPos = "unitysight_pos";
						camDir = "unitysight_dir";
						initFov="0.4/0.5";
						minFov="0.4/0.5";
						maxFov="0.4/0.5";
						visionMode[]=
						{
							"Normal",
							"NVG"
						};
					};
					class gas
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						gunnerOpticsModel="\ADF_Tracked\adfrc_abrams\abrams_gas_3x.p3d";
						gunnerOpticsEffect[] = {""};
						camPos = "gas_pos";
						camDir = "gas_dir";
						initFov="0.4/8";
						minFov="0.4/8";
						maxFov="0.4/8";
						visionMode[]=
						{
							"Normal",
							"NVG"
						};
					};
					class daysight_3x
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						gunnerOpticsModel="\ADF_Tracked\adfrc_abrams\abrams_daysight_3x.p3d";
						gunnerOpticsEffect[] = {"TankGunnerOptics2","OpticsBlur1","OpticsCHAbera1"};
						camPos = "gunnerview_pos";
						camDir = "gunnerview_dir";
						initFov="0.4/3";
						minFov="0.4/3";
						maxFov="0.4/3";
						visionMode[]=
						{
							"Normal",
							"TI",
						};
						thermalMode[]={0,1};
						thermalResolution[] = {1920};
					};
					class daysight_6x: daysight_3x
					{
						gunnerOpticsModel="\ADF_Tracked\adfrc_abrams\abrams_daysight_3x.p3d";
						initFov="0.4/6";
						minFov="0.4/6";
						maxFov="0.4/6";
					};
					class daysight_13x: daysight_6x
					{
						gunnerOpticsModel="\ADF_Tracked\adfrc_abrams\abrams_daysight_10x.p3d";
						initFov="0.4/13";
						minFov="0.4/13";
						maxFov="0.4/13";
					};
					class tisight_25x: daysight_13x
					{
						gunnerOpticsModel="\ADF_Tracked\adfrc_abrams\abrams_daysight_10x.p3d";
						initFov="0.4/25";
						minFov="0.4/25";
						maxFov="0.4/25";
						visionMode[]=
						{
							"TI",
						};
					};
					class tisight_50x: tisight_25x
					{
						gunnerOpticsModel="\ADF_Tracked\adfrc_abrams\abrams_daysight_10x.p3d";
						initFov="0.4/50";
						minFov="0.4/50";
						maxFov="0.4/50";
					};
				};
			};
			class LoaderTurret: LoaderTurret
			{
				class TurnOut
				{
					limitsArrayTop[] = {{35.0000, -44.9999}, {34.9961, 159.9998}};
					limitsArrayBottom[] = {{-13.6158, -31.1559}, {-14.4236, -2.4734}, {-2.4153, 8.0533}, {-17.9486, 32.8736}, {-2.5188, 33.0502}, {-17.9910, 128.2262}, {-10.5657, 156.9531}};
				};
			};
		};
		class AnimationSources:AnimationSources
		{
			class zasleh_2_rot
			{
				source="ammorandom";
				weapon="ADFRC_abrams_M2HBQCB_RWS";
			};
			class zasleh_2_hide
			{
				source="reload";
				weapon="ADFRC_abrams_M2HBQCB_RWS";
			};
			class reloadanim_m2
			{
				source="reload";
				weapon="ADFRC_abrams_M2HBQCB_RWS";
			};
			class reloadmagazine_m2
			{
				source="reloadmagazine";
				weapon="ADFRC_abrams_M2HBQCB_RWS";
			};
			class Revolving_m2
			{
				source="revolving";
				weapon="ADFRC_abrams_M2HBQCB_RWS";
			};
			class tusk1_era
			{
				DisplayName="ARAT-1 (M19) ERA Kit (+2.5T)";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
				mass = 2500;
			};
			class loadershield
			{
				DisplayName="TUSK Loaders Armor (+250kg)";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
				mass = 250;
			};
			class loaderturret_shield
			{
				DisplayName="TUSK Loaders Shield (+50kg)";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
				mass = 50;
			};
			class loadersandbags
			{
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
			class sepshackles
			{
				DisplayName="SEP HD Recovery Shackles";
				source="user";
				animPeriod=0;
				initPhase=0;
				author="ADFRC";
			};
		};
		hiddenSelections[]=
		{
			"abramshull1",
			"abramsmisc1",
			"abramsmisc2",
			"abramsturret1",
			"abramswheels",
			"plow",
			"label_hull",
			"label_barrel",
			"label_callsign",
			"abramssep",
		};
		hiddenSelectionsTextures[]=
		{
			"ADF_Tracked\adfrc_abrams\Data\Standard\abramshull1_co.paa",
			"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc1_co.paa",
			"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc2_co.paa",
			"ADF_Tracked\adfrc_abrams\Data\Standard\abramsturret1_co.paa",
			"ADF_Tracked\adfrc_abrams\Data\Standard\abramswheels_co.paa",
			"ADF_Tracked\adfrc_abrams\Data\plow\plow_co.paa",
			"\ADF_Tracked\adfrc_abrams\Data\labels\labels_01.paa",
			"\ADF_Tracked\adfrc_abrams\Data\labels\labels_01.paa",
			"\ADF_Tracked\adfrc_abrams\Data\labels\labels_01.paa",
			"ADF_Tracked\adfrc_abrams\Data\Standard\abramssep_co.paa",
		};
		class TextureSources: TextureSources
		{
			class Standard
			{
				displayName="Standard";
				author="ADFRC_Quiggs";
				textures[]=
				{
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramshull1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc2_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramsturret1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramswheels_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\plow\plow_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramssep_co.paa",
				};
			};
			class Fishscale
			{
				displayName="Fish Scale";
				author="ADFRC_Quiggs";
				textures[]=
				{
					"ADF_Tracked\adfrc_abrams\Data\fish\abramshull1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc2_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\fish\abramsturret1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramswheels_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\plow\plow_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramssep_co.paa",
				};
			};
			class Polka
			{
				displayName="Polka Dot";
				author="ADFRC_Quiggs";
				textures[]=
				{
					"ADF_Tracked\adfrc_abrams\Data\polka\abramshull1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc2_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\polka\abramsturret1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramswheels_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\plow\plow_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramssep_co.paa",
				};
			};
			class Lines
			{
				displayName="Lines";
				author="ADFRC_Quiggs";
				textures[]=
				{
					"ADF_Tracked\adfrc_abrams\Data\tiger\abramshull1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramsmisc2_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\tiger\abramsturret1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramswheels_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\plow\plow_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\Standard\abramssep_co.paa",
				};
			};
			class Garudashield
			{
				displayName="Garuda Shield";
				author="ADFRC_Quiggs";
				textures[]=
				{
					"ADF_Tracked\adfrc_abrams\Data\garuda\abramshull1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\garuda\abramsmisc1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\garuda\abramsmisc2_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\garuda\abramsturret1_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\garuda\abramswheels_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\plow\plow_co.paa",
					"ADF_Tracked\adfrc_abrams\Data\garuda\abramssep_co.paa",
				};
			};
		};
	};
};
class Extended_Init_EventHandlers
{
    class adfrc_abrams
    {
        ADFRC_plowInit = "_this call compile preprocessFileLineNumbers '\ADF_Tracked\adfrc_abrams\scripts\fn_plowInit.sqf'";
		ADFRC_labelRandom = "_this spawn {sleep 0.1; params ['_veh']; if (!isServer) exitWith {}; private _v = _veh getVariable ['PlatoonMarkings', 0]; if (_v isEqualTo 0) then {private _i = floor (random 7) + 1; private _f = if (_i < 10) then {format ['\ADF_Tracked\adfrc_abrams\Data\labels\labels_0%1.paa', _i]} else {format ['\ADF_Tracked\adfrc_abrams\Data\labels\labels_%1.paa', _i]}; {_veh setObjectTextureGlobal [_x, _f]} forEach [6, 7, 8];}};";
    };
    class adfrc_m1a1aim_md:    adfrc_abrams {};
    class adfrc_m1a1aim_gwot:  adfrc_abrams {};
    class adfrc_m1a2sepv3_md:  adfrc_abrams {};
};
