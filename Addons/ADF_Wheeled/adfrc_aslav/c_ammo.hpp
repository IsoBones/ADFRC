class cfgCloudlets
{
	class MachineGunCartridge;
	class MachineGunEject;
	class adfrc_aslav_mag58_cartridge: MachineGunCartridge 
	{
		moveVelocity[] = { "-directionX * 3", "- directionY * 3", "- directionZ * 3" };
		lifeTime = 10;
		size[] = {1.1};
		bounceOnSurface = 0.25;
		MoveVelocityVar[] = {0.5,0.5,0.5};
		randomDirectionPeriod = 0.1;
	};
	class adfrc_aslav_mag58_eject: MachineGunEject
	{
		moveVelocity[] = { "-directionX * 3", "- directionY * 3", "- directionZ * 3" };
		lifeTime=20;
		size[]={1.1};
		bounceOnSurface=0.25;
		MoveVelocityVar[] = {0.5,0.5,0.5};
		randomDirectionPeriod = 0.1;
	};
	class adfrc_aslav_m252_cartridge: MachineGunCartridge
	{
		particleShape = "\ADF_Core\Vehicle\qav_autocannon_shell.p3d";
		moveVelocity[] = { "-directionX * 4", "- directionY * 4", "- directionZ * 4" };
		animationSpeed[] = {1500};
		MoveVelocityVar[] = {0.25,0.25,0.25};
		randomDirectionPeriod = 0.1;
		randomDirectionIntensity = 0;
		lifeTime = 20;
		size[] = {1.8};
		bounceOnSurface = 0.35;
		bounceOnSurfaceVar = 0.15;
		rotationVelocityVar = 0;
	};
	class adfrc_aslav_m252_eject: MachineGunEject
	{
		moveVelocity[] = { "-directionX * 3", "- directionY * 3", "- directionZ * 3" };
		lifeTime=20;
		size[]={6};
		bounceOnSurface=0.25;
	};
};
class adfrc_aslav_m252_casingeject
{
	class MachineGunEject
	{
		simulation = "particles";
		type = "adfrc_aslav_m252_cartridge";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.05;
	};
};
class adfrc_aslav_m252_linkeject
{
	class MachineGunEject
	{
		simulation = "particles";
		type = "adfrc_aslav_m252_eject";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.05;
	};
};
class adfrc_aslav_mag58_casingeject 
{
	class MachineGunEject 
	{
		simulation = "particles";
		type = "adfrc_aslav_mag58_cartridge";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.05;
	};
};
class adfrc_aslav_mag58_linkeject 
{
	class MachineGunEject 
	{
		simulation = "particles";
		type = "adfrc_aslav_mag58_eject";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.05;
	};
};
class cfgAmmo
{
	class B_30mm_MP_Tracer_Red;
	class adfrc_aslav_m242_25mm_HE: B_30mm_MP_Tracer_Red
	{
		hit = 25;
		caliber = 1.2;
	};
	class B_30mm_APFSDS_Tracer_Red;
	class adfrc_aslav_m242_25mm_AP: B_30mm_APFSDS_Tracer_Red
	{
		hit = 70;
		caliber = 3.8;
	};
};
class cfgMagazines
{
	class 150Rnd_762x51_Box;
	class adfrc_aslav_200Rnd_762x51_Tracer: 150Rnd_762x51_Box
	{
		scope = 2;
		ammo = "B_762x54_Tracer_Red";
		displayName = "200rnd 7.62 B";
		displayNameShort = "M80A1 Ball";
		descriptionShort = "$STR_A3_CfgMagazines_2000Rnd_762x45_Belt1";
		count = 200;
		type = "2* 256";
		tracersEvery = 4;
	};
	class 250Rnd_30mm_HE_shells_Tracer_Red;
	class adfrc_aslav_m242_300rnd_25mm_HE: 250Rnd_30mm_HE_shells_Tracer_Red
	{
		scope = 2;
		displayName = "25MM HE-T";
		displaynameshort = "25MM HE-T";
		ammo = "adfrc_aslav_m242_25mm_HE";
		initSpeed = 1100;
		tracersEvery = 1;
		count = 300;
	};
	class 250Rnd_30mm_APDS_shells_Tracer_Red;
	class adfrc_aslav_m242_120rnd_25mm_AP: 250Rnd_30mm_APDS_shells_Tracer_Red
	{
		scope = 2;
		displayName = "25MM Armor Piercing";
		displayNameShort = "25MM APDS-T";
		ammo = "adfrc_aslav_m242_25mm_AP";
		initSpeed = 1515;
		tracersEvery = 1;
		count = 120;
	};
};

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;

class cfgWeapons
{
	class MGun;
	class HMG_M2_Mounted;
	class LMG_coax_ext;
	class adfrc_aslav_mag58_coax: LMG_coax_ext
	{
		displayName = "MG 7.62mm Mag58 Coax";
		scope = 2;
		ballisticsComputer = "2 + 16";
		magazines[]=
		{
			"adfrc_aslav_200Rnd_762x51_Tracer",
		};
		class GunParticles 
		{

			class effect1 
			{
				effectName = "MachineGunCloud";
				positionName = "Konec hlavne2";
				directionName = "Usti hlavne2";
			};
			class effect2 
			{
				effectName = "adfrc_aslav_mag58_casingeject";
				positionName = "nabojnicestart2";
				directionName = "nabojniceend2";
			};
			class effect3 
			{
				effectName = "adfrc_aslav_mag58_linkeject";
				positionName = "nabojnicestart2";
				directionName = "nabojniceend2";
			};
			class Effect4
			{
				effectName = "MachineGun1";
				positionName = "nabojniceend2";
				directionName = "nabojnicestart2";
			};
		};
	};
	class adfrc_aslav_mag58_pintle: adfrc_aslav_mag58_coax
	{
		displayName = "MG 7.62mm Mag58 Pintle";
		autoReload = 0;
		magazineReloadTime = 10;
		ballisticsComputer = 2;
		scope = 2;
		class GunParticles 
		{
			class effect1 
			{
				effectName = "MachineGunCloud";
				positionName = "Usti hlavne3";
				directionName = "Konec hlavne3";
			};
			class effect2 
			{
				effectName = "adfrc_aslav_mag58_casingeject";
				positionName = "mag_caseeject_start";
				directionName = "mag_caseeject_end";
			};
			class effect3 
			{
				effectName = "adfrc_aslav_mag58_linkeject";
				positionName = "mag_linkeject_start";
				directionName = "mag_linkeject_end";
			};
			class Effect4
			{
				effectName = "MachineGun1";
				positionName = "mag_linkeject_end";
				directionName = "mag_linkeject_start";
			};
		};
	};
	class autocannon_Base_F;
	class player;
	class adfrc_aslav_M242: autocannon_Base_F
	{
		displayName = "M242 25mm Bushmaster Chain Gun";
		muzzles[] = {"AP","HE"};
		aiDispersioncoefX = 4;
		aiDispersioncoefY = 6;
		airateoffire = 2;
		airateoffiredistance = 1000;
		canlock = 0;
		FCSMaxLeadSpeed = 0;
		class GunParticles
		{
			class Effect1
			{
				effectName = "AutoCannonFired";
				positionName = "m242cloud_dir";
				directionName = "m242cloud_pos";
			};
			class Effect2
			{
				effectName = "MachineGunCloud";
				positionName = "m242cloud_up_dir";
				directionName = "m242cloud_pos";
			};
			class Effect3
			{
				effectName = "MachineGunCloud";
				positionName = "m242cloud_right_dir";
				directionName = "m242cloud_pos";
			};
			class Effect4
			{
				effectName = "MachineGunCloud";
				positionName = "m242cloud_left_dir";
				directionName = "m242cloud_pos";
			};
			class Effect5
			{
				effectName = "adfrc_aslav_m252_casingeject";
				positionName = "nabojnicestart";
				directionName = "nabojniceend";
			};
			class Effect6
			{
				effectName = "adfrc_aslav_m252_linkeject";
				positionName = "nabojnicestart2";
				directionName = "nabojniceend2";
			};
			class Effect7
			{
				effectName = "MachineGun1";
				positionName = "nabojniceend";
				directionName = "nabojnicestart";
			};
			class Effect8
			{
				effectName = "MachineGun1";
				positionName = "nabojniceend2";
				directionName = "nabojnicestart2";
			};
		};
		class HE: autocannon_Base_F 
		{
			displayName = "M242 25mm Bushmaster Chain Gun";
			magazines[] = {"adfrc_aslav_m242_300rnd_25mm_HE","adfrc_aslav_m242_120rnd_25mm_AP",};
			canlock = 0;
			FCSMaxLeadSpeed = 0;
			minZeroing = 0;
			magazineReloadTime = 0.3;
			modes[] = {"player","100rpm","close","short","medium","far"};
			class player: player
			{
				reloadTime=__EVAL(60/215);
				dispersion = 0.0015;
				textureType = "fullAuto";
				sounds[] = {"StandardSound"};
			};
			class 100rpm: player
			{
				reloadTime=__EVAL(60/100);
				textureType = "burst";
			};
		};
		class AP: autocannon_Base_F 
		{
			displayName = "25mm M242 - AP-T";
			magazines[] = {"adfrc_aslav_m242_120rnd_25mm_AP"};
			canlock = 0;
			FCSMaxLeadSpeed = 0;
			minZeroing = 0;
			magazineReloadTime = 0.3;
			class player: player
			{
				showToPlayer = 0;
				reloadTime=__EVAL(60/215);
				dispersion = 0.0015;
				textureType = "fullAuto";
				sounds[] = {"StandardSound"};
			};
			class close: player
			{
				showToPlayer=0;
				reloadTime=__EVAL(60/200);
				aiBurstTerminable=1;
				burst=8;
				burstRangeMax=6;
				aiRateOfFire = 0.35;
				aiRateOfFireDispersion=2;
				aiRateOfFireDistance=200;
				minRange=0;
				minRangeProbab=0.1;
				midRange=400;
				midRangeProbab=0.69999999;
				maxRange=800;
				maxRangeProbab=0.80000001;
			};
			class short: close
			{
				showToPlayer = 0;
				reloadTime=__EVAL(60/200);
			};
			class medium: short
			{
				showToPlayer=0;
				reloadTime=__EVAL(60/200);
			};
			class far: medium
			{
				showToPlayer=0;
				reloadTime=__EVAL(60/100);
			};
		};
	};
	class adfrc_aslav_m2hbqcb: HMG_M2_Mounted 
	{
		displayName="12.7mm M2HB QCB MG";
		class GunParticles 
{
			class effect1
			{
				positionName = "m2_muzzle_end";
				directionName = "m2_muzzle";
				effectName = "MachineGunCloud";
			};
			class effect2 
			{
				effectName = "MachineGunEject";
				directionName = "m2_link_eject_dir";
				positionName = "m2_link_eject_pos";
			};
			class effect3 
			{
				effectName = "MachineGunCartridge2";
				directionName = "m2_case_eject_dir";
				positionName = "m2_case_eject_pos";
			};
		};
	};
	class adfrc_aslav_m2hbqcb_rws: adfrc_aslav_m2hbqcb 
	{
		displayName="Kongsberg RWS - M2HB QCB";
		ballisticsComputer = "2 + 16";
		class GunParticles 
{
			class effect1
			{
				positionName = "m2_rws_muzzle_end";
				directionName = "m2_rws_muzzle";
				effectName = "MachineGunCloud";
			};
			class effect2 
			{
				effectName = "MachineGunEject";
				directionName = "m2_rws_link_eject_dir";
				positionName = "m2_rws_link_eject_pos";
			};
			class effect3 
			{
				effectName = "MachineGunCartridge2";
				directionName = "m2_rws_case_eject_dir";
				positionName = "m2_rws_case_eject_pos";
			};
		};
	};
};