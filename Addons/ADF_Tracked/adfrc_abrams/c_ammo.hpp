class cfgCloudlets 
{
	class MachineGunCartridge;
	class MachineGunEject;
	class ADFRC_abrams_cartridge: MachineGunCartridge 
	{
		moveVelocity[] = { "-directionX * 3", "- directionY * 3", "- directionZ * 3" };
		lifeTime = 20;
		size[] = {3};
		bounceOnSurface = 0.25;
	};
	class ADFRC_abrams_eject: MachineGunEject
	{
		moveVelocity[] = { "-directionX * 3", "- directionY * 3", "- directionZ * 3" };
		lifeTime=20;
		size[]={6};
		bounceOnSurface=0.25;
	};
	class ADFRC_abrams_mag58_cartridge: MachineGunCartridge 
	{
		moveVelocity[] = { "-directionX * 3", "- directionY * 3", "- directionZ * 3" };
		lifeTime = 10;
		size[] = {1.1};
		bounceOnSurface = 0.25;
	};
	class ADFRC_abrams_mag58_eject: MachineGunEject
	{
		moveVelocity[] = { "-directionX * 3", "- directionY * 3", "- directionZ * 3" };
		lifeTime=20;
		size[]={1.1};
		bounceOnSurface=0.25;
	};
};
class ADFRC_mag58_casingeject 
{
	class MachineGunEject {
		simulation = "particles";
		type = "ADFRC_abrams_mag58_cartridge";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.05;
	};
};
class ADFRC_mag58_linkeject 
{
	class MachineGunEject {
		simulation = "particles";
		type = "ADFRC_abrams_mag58_eject";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.05;
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class cfgAmmo
{
	
    //*
    //* Imports
    //*
	
	class Sh_120mm_APFSDS;
    class Sh_120mm_HEAT_MP;
	class Sh_120mm_HE;
	class B_762x54_Tracer_Red;
    class B_12Gauge_Pellets_Submunition_Deploy;
		
	//*
    //* 120mm
    //*
	
	class adfrc_abrams_120mm_M829A2_APFSDS: Sh_120mm_APFSDS ///Armour-Piercing Fin-Stabilized Discarding Sabot
	{
		hit = 500;
		indirectHit = 15;
		indirectHitRange = 0.5;
		warheadName = "AP";
		dangerRadiusHit = 100;
		suppressionRadiusHit = 18;
		explosive = 0;
		cost = 500;
		airFriction = -3.96e-05;
		CraterEffects = "ExploAmmoCrater";
		explosionEffects = "ExploAmmoExplosion";
		typicalSpeed = 1550;
		caliber = 35.2688;
		deflecting = 15;
		timeToLive = 15;
		whistleOnFire = 1;
		whistleDist = 14;
		model = "\A3\Weapons_f\Data\bullettracer\shell_tracer_red";
		tracerScale = 3;
		tracerStartTime = 0.1;
		tracerEndTime = 3.0;
		muzzleEffect = "";
		soundHit1[] = {"A3\Sounds_F\arsenal\explosives\shells\Tank_shell_explosion_01",1.7782794,1,1800};
		soundHit2[] = {"A3\Sounds_F\arsenal\explosives\shells\Tank_shell_explosion_02",1.7782794,1,1800};
		soundHit3[] = {"A3\Sounds_F\arsenal\explosives\shells\Tank_shell_explosion_03",1.7782794,1,1800};
		soundHit4[] = {"A3\Sounds_F\arsenal\explosives\shells\Tank_shell_explosion_04",1.7782794,1,1800};
		multiSoundHit[] = {"soundHit1",0.25,"soundHit2",0.25,"soundHit3",0.25,"soundHit4",0.25};
		aiAmmoUsageFlags = "128 + 512";
		class CamShakeExplode
		{
			power = 13.4164;
			duration = 2.6;
			frequency = 20;
			distance = 40.2492;
		};
		class CamShakeHit
		{
			power = 180;
			duration = 0.8;
			frequency = 20;
			distance = 1;
		};
		class CamShakeFire
		{
			power = 3.30975;
			duration = 2.2;
			frequency = 20;
			distance = 87.6356;
		};
		class CamShakePlayerFire
		{
			power = 0.02;
			duration = 0.1;
			frequency = 20;
			distance = 1;
		};
	};
	class adfrc_abrams_120mm_M830A1_HEATMP: Sh_120mm_HEAT_MP ///High Explosive Anti-Tank
	{
		hit = 95;
		warheadName = "HE";
		submunitionAmmo = "ammo_Penetrator_120mm";
		submunitionDirectionType = "SubmunitionModelDirection";
		submunitionInitSpeed = 1000;
		submunitionParentSpeedCoef = 0.0;
		submunitionInitialOffset[] = {0,0,-0.2};
		triggerOnImpact = 1;
		deleteParentWhenTriggered = 0;
		indirectHit = 30;
		indirectHitRange = 3.5;
		dangerRadiusHit = 160;
		suppressionRadiusHit = 32;
		typicalSpeed = 1400;
		explosive = 1;
		cost = 500;
		airFriction = -0.000275;
		deflecting = 8;
		timeToLive = 15;
		whistleOnFire = 1;
		whistleDist = 14;
		model = "\A3\Weapons_f\Data\bullettracer\shell_tracer_red";
		tracerScale = 1;
		tracerStartTime = 0.1;
		tracerEndTime = 3.0;
		muzzleEffect = "";
		soundHit1[] = {"A3\Sounds_F\arsenal\explosives\shells\Tank_shell_explosion_01",1.7782794,1,1800};
		soundHit2[] = {"A3\Sounds_F\arsenal\explosives\shells\Tank_shell_explosion_02",1.7782794,1,1800};
		soundHit3[] = {"A3\Sounds_F\arsenal\explosives\shells\Tank_shell_explosion_03",1.7782794,1,1800};
		soundHit4[] = {"A3\Sounds_F\arsenal\explosives\shells\Tank_shell_explosion_04",1.7782794,1,1800};
		multiSoundHit[] = {"soundHit1",0.25,"soundHit2",0.25,"soundHit3",0.25,"soundHit4",0.25};
		class CamShakeExplode
		{
			power = 24;
			duration = 2.2;
			frequency = 20;
			distance = 143.636;
		};
		class CamShakeHit
		{
			power = 120;
			duration = 0.6;
			frequency = 20;
			distance = 1;
		};
		class CamShakeFire
		{
			power = 3.30975;
			duration = 2.2;
			frequency = 20;
			distance = 87.6356;
		};
		class CamShakePlayerFire
		{
			power = 0.02;
			duration = 0.1;
			frequency = 20;
			distance = 1;
		};
		CraterEffects = "ATRocketCrater";
		explosionEffects = "ATRocketExplosion";
		explosionSoundEffect = "DefaultExplosion";
	};
	class adfrc_abrams_120mm_M908_HE: Sh_120mm_HE ///High Explosive Obstacle Reduction Shell
	{
		hit = 250;
		indirectHit = 60;
		indirectHitRange = 6;
		warheadName = "HE";
		dangerRadiusHit = 160;
		suppressionRadiusHit = 32;
		typicalSpeed = 1400;
		explosive = 0.8;
		cost = 300;
		airFriction = -0.000275;
		caliber = 10;
		deflecting = 4;
		timeToLive = 15;
		whistleOnFire = 1;
		whistleDist = 14;
		model = "\A3\Weapons_f\Data\bullettracer\shell_tracer_red";
		tracerScale = 1;
		tracerStartTime = 0.1;
		tracerEndTime = 3.0;
		muzzleEffect = "";
		soundHit1[] = {"A3\Sounds_F\arsenal\explosives\shells\Tank_shell_explosion_01",1.7782794,1,1800};
		soundHit2[] = {"A3\Sounds_F\arsenal\explosives\shells\Tank_shell_explosion_02",1.7782794,1,1800};
		soundHit3[] = {"A3\Sounds_F\arsenal\explosives\shells\Tank_shell_explosion_03",1.7782794,1,1800};
		soundHit4[] = {"A3\Sounds_F\arsenal\explosives\shells\Tank_shell_explosion_04",1.7782794,1,1800};
		multiSoundHit[] = {"soundHit1",0.25,"soundHit2",0.25,"soundHit3",0.25,"soundHit4",0.25};
		class CamShakeExplode
		{
			power = 24;
			duration = 2.2;
			frequency = 20;
			distance = 143.636;
		};
		class CamShakeHit
		{
			power = 120;
			duration = 0.6;
			frequency = 20;
			distance = 1;
		};
		class CamShakeFire
		{
			power = 3.30975;
			duration = 2.2;
			frequency = 20;
			distance = 87.6356;
		};
		class CamShakePlayerFire
		{
			power = 0.02;
			duration = 0.1;
			frequency = 20;
			distance = 1;
		};
	};
	class adfrc_abrams_120mm_M1028_C: Sh_120mm_HE ///Canister
	{
		Hit = 50;
		indirectHit = 1;
		indirectHitRange = 1;
		caliber = 5;
		warheadName = "HE";
		dangerRadiusHit = 160;
		suppressionRadiusHit = 32;
		typicalSpeed = 1400;
		explosive = 0.8;
		cost = 300;
		airFriction = -0.000275;
		deflecting = 4;
		timeToLive = 15;
		whistleOnFire = 1;
		whistleDist = 14;
		model = "\A3\Weapons_f\Data\bullettracer\shell_tracer_white";
		tracerScale = 1;
		tracerStartTime = 0.1;
		tracerEndTime = 3.0;
		muzzleEffect = "";
		soundHit1[] = {"A3\Sounds_F\arsenal\explosives\shells\Tank_shell_explosion_01",1.7782794,1,1800};
		soundHit2[] = {"A3\Sounds_F\arsenal\explosives\shells\Tank_shell_explosion_02",1.7782794,1,1800};
		soundHit3[] = {"A3\Sounds_F\arsenal\explosives\shells\Tank_shell_explosion_03",1.7782794,1,1800};
		soundHit4[] = {"A3\Sounds_F\arsenal\explosives\shells\Tank_shell_explosion_04",1.7782794,1,1800};
		multiSoundHit[] = {"soundHit1",0.25,"soundHit2",0.25,"soundHit3",0.25,"soundHit4",0.25};
		class CamShakeExplode
		{
			power = 24;
			duration = 2.2;
			frequency = 20;
			distance = 143.636;
		};
		class CamShakeHit
		{
			power = 120;
			duration = 0.6;
			frequency = 20;
			distance = 1;
		};
		class CamShakeFire
		{
			power = 3.30975;
			duration = 2.2;
			frequency = 20;
			distance = 87.6356;
		};
		class CamShakePlayerFire
		{
			power = 0.02;
			duration = 0.1;
			frequency = 20;
			distance = 1;
		};
		submunitionAmmo = "adfrc_abrams_120mm_M1028_C_Deploy";
		submunitionConeType[] =
		{
			"randomcenter",
			100
		};
		submunitionConeAngle = 0.60;
		triggerSpeedCoef[] = {0.85000002,1};
		triggerTime = 0.001;
	};
	class adfrc_abrams_120mm_M1028_C_Deploy : B_12Gauge_Pellets_Submunition_Deploy ///Canister Pellets
	{
		airFriction = -0.0066999998;
		hit = 25;
		indirectHit = 2;
		indirectHitRange = 1;
		typicalSpeed = 1000;
		deflecting = 45;
	};
};
class cfgMagazines
{
	class VehicleMagazine;
	class 150Rnd_762x51_Box;
	class adfrc_abrams_200Rnd_762x51_Tracer: 150Rnd_762x51_Box 
	{
		scope = 2;
		ammo = "B_762x54_Tracer_Red";
		author = "Quiggs";
		displayName = "200rnd 7.62 B";
		displayNameShort = "M80A1 Ball";
		descriptionShort = "$STR_A3_CfgMagazines_2000Rnd_762x45_Belt1";
		count = 200;
		type = "2*		256";
		tracersEvery = 4;
	};
	
	//*
    //* 120mm
    //*
	
	class adfrc_abrams_1Rnd_M829A2_shell: VehicleMagazine
	{
		author = "Quiggs";
		scope = 2;
		displayName = "M829A2 (APFSDS)";
		displayNameShort = "APFSDS";
		ammo = "adfrc_abrams_120mm_M829A2_APFSDS";
		nameSound = "cannon";
		initSpeed = 1680;
		count = 1;
		maxLeadSpeed = 25;
		tracersEvery = 1;
		// {push, hull rock}. The engine scales the kick by the round (it tracks hit x muzzle
		// speed in testing: APFSDS 840k, HEAT 134k, HE 350k, canister 70k), so each shell
		// carries its own factor to give all four the same punchy rock. Tested in game.
		muzzleImpulseFactor[] = {2.5, 16};
	};
	class adfrc_abrams_1Rnd_M830A1_shell: adfrc_abrams_1Rnd_M829A2_shell
	{
		author = "Quiggs";
		scope = 2;
		displayName = "M830A1 (HEAT-MP)";
		displayNameShort = "HEAT-MP";
		ammo = "adfrc_abrams_120mm_M830A1_HEATMP";
		tracersEvery = 1;
		initSpeed = 1410;
		muzzleImpulseFactor[] = {16, 100};
	};
	class adfrc_abrams_1Rnd_M908_shell: adfrc_abrams_1Rnd_M829A2_shell
	{
		author = "Quiggs";
		scope = 2;
		displayName = "M908 (HE-OR)";
		displayNameShort = "HE-OR";
		ammo = "adfrc_abrams_120mm_M908_HE";
		tracersEvery = 1;
		initSpeed = 1400;
		muzzleImpulseFactor[] = {6, 38};
	};
	class adfrc_abrams_1Rnd_M1028_shell: adfrc_abrams_1Rnd_M829A2_shell
	{
		author = "Quiggs";
		scope = 2;
		displayName = "M1028 (Canister)";
		displayNameShort = "Canister";
		ammo = "adfrc_abrams_120mm_M1028_C";
		tracersEvery = 0;
		initSpeed = 1410;
		muzzleImpulseFactor[] = {30, 190};
	};
	// Multi-round main gun magazines (#235). With 1Rnd magazines every shot is a magazine
	// reload, so the "reload" animation source never runs and recoil/flash had to use
	// reloadMagazine, which also fires on ammo switch. Same rounds and counts as the old
	// 1Rnd loadout (20/10/7/5); the 1Rnd classes stay for missions that still use them.
	class adfrc_abrams_20Rnd_M829A2_shell: adfrc_abrams_1Rnd_M829A2_shell
	{
		count = 20;
	};
	class adfrc_abrams_10Rnd_M830A1_shell: adfrc_abrams_1Rnd_M830A1_shell
	{
		count = 10;
	};
	class adfrc_abrams_7Rnd_M908_shell: adfrc_abrams_1Rnd_M908_shell
	{
		count = 7;
	};
	class adfrc_abrams_5Rnd_M1028_shell: adfrc_abrams_1Rnd_M1028_shell
	{
		count = 5;
	};
};
class cfgWeapons
{
	class MGun;
	class HMG_M2_Mounted;
	class LMG_RCWS;
	class LMG_coax: LMG_RCWS
	{
		class manual;
		class close;
		class short;
		class medium;
		class far;
	};
	class LMG_coax_ext: LMG_coax {};
	class adfrc_abrams_coax: LMG_coax_ext
	{
		// MAG58 sound (CfgSoundSets in adfrc_mag58), every fire mode incl. AI ones
		class manual: manual
		{
			class StandardSound
			{
				soundSetShot[]=
				{
					"ADFRC_MAG58_Shot_SoundSet",
					"ADFRC_MAG58_Tail_SoundSet",
					"ADFRC_MAG58_InteriorTail_SoundSet"
				};
			};
		};
		class close: close
		{
			class StandardSound
			{
				soundSetShot[]=
				{
					"ADFRC_MAG58_Shot_SoundSet",
					"ADFRC_MAG58_Tail_SoundSet",
					"ADFRC_MAG58_InteriorTail_SoundSet"
				};
			};
		};
		class short: short
		{
			class StandardSound
			{
				soundSetShot[]=
				{
					"ADFRC_MAG58_Shot_SoundSet",
					"ADFRC_MAG58_Tail_SoundSet",
					"ADFRC_MAG58_InteriorTail_SoundSet"
				};
			};
		};
		class medium: medium
		{
			class StandardSound
			{
				soundSetShot[]=
				{
					"ADFRC_MAG58_Shot_SoundSet",
					"ADFRC_MAG58_Tail_SoundSet",
					"ADFRC_MAG58_InteriorTail_SoundSet"
				};
			};
		};
		class far: far
		{
			class StandardSound
			{
				soundSetShot[]=
				{
					"ADFRC_MAG58_Shot_SoundSet",
					"ADFRC_MAG58_Tail_SoundSet",
					"ADFRC_MAG58_InteriorTail_SoundSet"
				};
			};
		};
		displayName = "MG 7.62mm Mag58 Coax";
		scope = 2;
		canlock = 0;
		airLock = 0;
		ballisticsComputer = "2 + 16";
		magazines[]=
		{
			"ADFRC_abrams_200Rnd_762x51_Tracer"
		};
		class GunParticles 
		{
			class effect1 
			{
				effectName = "MachineGunCloud";
				positionName = "Usti hlavne3";
				directionName = "konec hlavne3";
			};
		};
	};	
	class ADFRC_abrams_mag58: ADFRC_abrams_coax
	{
		displayName = "MG 7.62mm Mag58";
		scope = 2;
		ballisticsComputer = 2;
		magazines[]=
		{
			"ADFRC_abrams_200Rnd_762x51_Tracer"
		};
		class GunParticles 
		{
			class effect1
			{
				effectName = "MachineGunCloud";
				positionName = "Usti hlavne4";
				directionName = "konec hlavne4";
			};
		};
	};
	class player;
	class cannon_120mm;
	class adfrc_abrams_M256: cannon_120mm
	{
		displayName = "M256 120mm Cannon";
		scope = 2;
		aiDispersioncoefX = 4;
		aiDispersioncoefY = 6;
		airateoffire = 2;
		airateoffiredistance = 1000;
		canlock = 1;
		//reloadMagazineSound[]={"ADF_Tracked\adfrc_abrams\sounds\weapons\shells\adfrc_abrams_reload.wss",100,100};
		magazineReloadTime = 6;
		//reloadSound[]={"ADF_Tracked\adfrc_abrams\sounds\weapons\shells\adfrc_abrams_reload.wss",100,100};
		reloadTime = 6;
		magazines[]=
		{
			"adfrc_abrams_20Rnd_M829A2_shell",
			"adfrc_abrams_10Rnd_M830A1_shell",
			"adfrc_abrams_7Rnd_M908_shell",
			"adfrc_abrams_5Rnd_M1028_shell",
			"adfrc_abrams_1Rnd_M829A2_shell",
			"adfrc_abrams_1Rnd_M830A1_shell",
			"adfrc_abrams_1Rnd_M908_shell",
			"adfrc_abrams_1Rnd_M1028_shell"
		};
		class GunParticles 
		{
			class effect1
			{
				effectName = "CannonFired";
				positionName = "m256_muzzle_dir";
				directionName = "m256_muzzle";
			};
		};
	};
	class adfrc_abrams_M2HBQCB: HMG_M2_Mounted 
	{
		displayName="12.7mm M2HB QCB MG";
		scope = 2;
		class GunParticles 
{
			class effect1
			{
				positionName = "usti hlavne2";
				directionName = "konec hlavne2";
				effectName = "MachineGunCloud";
			};
			class effect2 
			{
				directionName = "nabojniceend";
				effectName = "MachineGunEject";
				positionName = "nabojnicestart";
			};
			class effect3 
			{
				directionName = "case_eject_dir";
				effectName = "MachineGunCartridge2";
				positionName = "case_eject_pos";
			};
		};
	};
	class adfrc_abrams_M2HBQCB_RWS: ADFRC_abrams_M2HBQCB 
	{
		displayName="Kongsberg RS4LP - M2HB MG";
		scope = 2;
		ballisticsComputer = "2 + 16";
		class GunParticles 
{
			class effect1
			{
				positionName = "usti hlavne2";
				directionName = "konec hlavne2";
				effectName = "MachineGunCloud";
			};
			class effect2 
			{
				directionName = "nabojniceend";
				effectName = "MachineGunEject";
				positionName = "nabojnicestart";
			};
			class effect3 
			{
				directionName = "case_eject_dir";
				effectName = "MachineGunCartridge2";
				positionName = "case_eject_pos";
			};
		};
	};
};
