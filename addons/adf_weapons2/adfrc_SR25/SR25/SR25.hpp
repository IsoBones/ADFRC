//BASE
	class adfrc_SR25_Base: Rifle_Base_F
    {
		author = "Brucey";
		magazines[] = {};
		muzzleend = "konec hlavne"; //Muzzle end
		muzzlepos = "usti hlavne";
        maxRecoilSway = 0.0125;
		recoil = "recoil_ebr";
		reloadAction = "GestureReloadSPAR_01";
		magazineReloadSwitchPhase = 0.47999999;
		selectionFireAnim = "zasleh";
        swayDecaySpeed = 1.25;
		maxZeroing = 3000;
		handAnim[] = {"OFP2_ManSkeleton","\ADF_Weapons\core\data\Anims\ar15_10in_cgrip_static.rtm"};
		drySound[] = {"A3\sounds_f\weapons\other\dry1", 0.330957, 1, 80};
		ace_overheating_mrbs = 2000; //Mean Rounds Between Stoppages (this will be scaled based on the barrel temp)
        ace_overheating_slowdownFactor = 1; //Slowdown Factor, reduces the velocity of the projectile (this will be scaled based on the barrel temp)
        ace_overheating_allowSwapBarrel = 1; // 1 to enable barrel swap. 0 to disable. Meant for machine guns where you can easily swap the barrel without dismantling the whole weapon.
        ace_overheating_dispersion = 0.25; 
		ace_overheating_closedBolt = 0; 
		ace_overheating_barrelMass = 3;
		ace_railHeightAboveBore = 3.3;  // Distance between center of bore and rail in centimeters
		
		cartridgepos = "nabojnicestart"; //remember this? Make sure it’s named
//right
		cartridgevel = "nabojniceend"; //the “end” is the velocity as I
//mentioned earlier 
		
		class GunParticles
		{
			class FirstEffect
			{
				effectName = "SniperCloud";
				positionName = "Usti hlavne";
				directionName = "Konec hlavne";
			};
		};
        
        opticsZoomMin = 0.375;
        opticsZoomMax = 1.1;
        opticsZoomInit = 0.75;
        distanceZoomMin = 300;
        distanceZoomMax = 300;


        dexterity = 1.8;
		bullet1[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_01",0.8912509,1,25};
		bullet2[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_02",0.8912509,1,25};
		bullet3[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_03",0.8912509,1,25};
		bullet4[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_04",0.8912509,1,25};
		bullet5[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_01",0.7943282,1,25};
		bullet6[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_02",0.7943282,1,25};
		bullet7[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_03",0.7943282,1,25};
		bullet8[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_04",0.7943282,1,25};
		bullet9[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_01",0.70794576,1,25};
		bullet10[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_02",0.70794576,1,25};
		bullet11[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_03",0.70794576,1,25};
		bullet12[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_04",0.70794576,1,25};
		soundBullet[] = {"bullet1",0.083,"bullet2",0.083,"bullet3",0.083,"bullet4",0.083,"bullet5",0.083,"bullet6",0.083,"bullet7",0.083,"bullet8",0.083,"bullet9",0.083,"bullet10",0.083,"bullet11",0.083,"bullet12",0.083};
		reloadMagazineSound[] = {"A3\Sounds_F\arsenal\weapons\LongRangeRifles\M320\M320_reload",1.0,1,10};
		soundBipodDeploy[] = {"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_deploy",0.70794576,1,20};
		soundBipodFold[] = {"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_fold",0.70794576,1,20};
		soundBipodDown[] = {"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_down",0.70794576,1,20};
		soundBipodUp[] = {"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_up",0.70794576,1,20};
		changeFiremodeSound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_03_MkI_EMR\DMR_03_Safety_02",0.11220184,1,5};
		modes[] = {"single","single_close_optics1","single_far_optics1","single_medium_optics1"};
		inertia = 0.99;
		scope=1;
		scopeWeapon=1;
		deployedPivot = "deploypoint";       /// what point should be used to be on surface while unfoldedsoundBipodUp[] = { "A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_AAF_up", db - 3, 1, 20 }; /// sound of folding the bipod
		scopeArsenal = 1;
		cursor = "srifle";
		cursorAim = "EmptyCursor";
		
		
		discretedistanceinitindex = 0;
		aiDispersionCoefY = 10;
		aiDispersionCoefX = 8;
		discretedistance[] = { 100 };
	
		   class WeaponSlotsInfo {
			mass = 90;
			allowedSlots[] = {901};
            class MuzzleSlot : asdg_MuzzleSlot_762
            {};
            class CowsSlot : asdg_OpticRail1913_long //Top / optic slot
            {};
			 class UnderBarrelSlot : asdg_UnderSlot //bottom / bipod
            {};
            class PointerSlot : asdg_FrontSideRail //side slot
            {};
        };
       class Single : Mode_SemiAuto
{			autofire = 0;
			sounds[] = { "StandardSound", "SilencedSound" };
			
			class BaseSoundModeType { /// I am too lazy to copy this twice into both standard and silenced sounds, that is why there is a base class from which both inherit (and sound of closure stays the same no matter what muzzle accessory is used)
                weaponSoundEffect  = "DefaultRifle";
            };
			class StandardSound : BaseSoundModeType
			{
				soundSetShot[] = {"SPAR_17_Shot_SoundSet","SPAR_17_Tail_SoundSet","SPAR_17_InteriorTail_SoundSet",};
			};
			class SilencedSound : BaseSoundModeType
			{
				soundSetShot[] = {"SPAR_17_silencerShot_SoundSet", "SPAR_17_silencerTail_SoundSet","SPAR_17_silencerInteriorTail_SoundSet"};
			};
			
			canshootinwater = 1;
			aiDispersionCoefY = 10;
			aiDispersionCoefX = 8;
			reloadTime = 0.1;
			dispersion = 0.000436332;
			maxrange = 600;
			maxrangeprobab = 0.05;
			midrange = 300;
			midrangeprobab = 0.7;
			minrange = 1;
			minrangeprobab = 0.3;
            airateoffire = 4;
			};
		
class single_close_optics1: Single {
aiRateOfFire = 2;
aiRateOfFireDistance = 300;
maxRange = 500;
maxRangeProbab = 0.01;
midRange = 300;
midRangeProbab = 0.8;
minRange = 2;
minRangeProbab = 0.05;
requiredOpticType = 1;
showToPlayer = 0;
};
class single_medium_optics1: single_close_optics1 {
aiRateOfFire = 2;
aiRateOfFireDistance = 500;
maxRange = 700;
maxRangeProbab = 0.05;
midRange = 500;
midRangeProbab = 0.7;
minRange = 300;
minRangeProbab = 0.05;
};
class single_far_optics1: single_medium_optics1 {
aiRateOfFire = 4;
aiRateOfFireDistance = 600;
maxRange = 1000;
maxRangeProbab = 0.05;
midRange = 700;
midRangeProbab = 0.5;
minRange = 300;
minRangeProbab = 0.05;
requiredOpticType = 2;
};
						
			
};
//OGs
class adfrc_SR25: adfrc_SR25_Base
	{
		author = "Brucey";
		ACE_barrelTwist = 254;
		ACE_barrelLength = 508;
		scope=2;
		scopeWeapon=2;
		scopeArsenal = 2;
		magazines[] = {
			"ADFRC_20RD_SR25_M"
		};
		magazineWell[] = {"CBA_762x51_AR10"};
		model = "ADF_Weapons2\adfrc_SR25\SR25\adfrc_SR25";
		descriptionShort = "KAC SR25 <br/>FDE<br/>Caliber: 7.62x51";
		inertia = 0.5;
		picture = "\ADF_Weapons2\adfrc_SR25\SR25\data\ui\Gear_mss_SR25_CA.paa";
		UiPicture = "\ADF_Weapons2\adfrc_SR25\SR25\data\ui\Gear_mss_SR25_CA.paa";
		displayName = "SR25";
		recoil = "recoil_spar_dmr";
		
		 class WeaponSlotsInfo {
			mass = 138;
			allowedSlots[] = {901};
            class MuzzleSlot : asdg_MuzzleSlot_762
            {
			iconPinpoint="center";
			iconPosition[] = {-0.051,0.41};
			iconScale  = 0.25;
			iconPicture = "\A3\Weapons_F\Data\UI\attachment_muzzle.paa";
			class compatibleItems: compatibleItems {
			adfrc_KAC_PRG = 1;
			};
			};
            class CowsSlot : asdg_OpticRail1913_long //Top / optic slot
            {	
			iconPinpoint="center";
			iconPosition[] = {0.564,0.273};
			iconScale  = 0.18;
			iconPicture = "\A3\Weapons_F\Data\UI\attachment_top.paa";};
			 class UnderBarrelSlot : asdg_UnderSlot //bottom / bipod
            {
			iconPinpoint="center";
			iconPosition[] = {0.207,0.617};
			iconScale  = 0.16;
			iconPicture = "\A3\weapons_f_mark\data\UI\attachment_under.paa";
			};
            class PointerSlot : asdg_FrontSideRail //side slot
            {
			iconPinpoint="center";
			iconPosition[] = {0.225,0.414};
			iconScale  = 0.25;
			iconPicture = "\A3\Weapons_F\Data\UI\attachment_side.paa";
			};
			class GripodSlot: adfrc_PIC_grip_slot {};
        };
		 
		class Library
		{
			libTextDesc = "SR25";
		};
		
		rhs_grip1_change = "adfrc_SR25_GripPod";
		rhs_grip2_change = "adfrc_SR25_AFG";
		rhs_grip3_change = "adfrc_SR25_VFG";
	};

	class adfrc_SR25_GripPod: adfrc_SR25
	{
		author = "Brucey";
	displayName = "SR25 Grip-Pod";
    Grip_Macro(1,ar15_10in_vg_static)
	};
	
	class adfrc_SR25_AFG: adfrc_SR25
	{
		author = "Brucey";
	displayName = "SR25 AFG";
    Grip_Macro(2,ar15_10in_afg_static)
	};
	
	class adfrc_SR25_VFG: adfrc_SR25
	{
		author = "Brucey";
	displayName = "SR25 VFG";
    Grip_Macro(3,ar15_10in_vg_tb_static)
	};
	
////// 20 inch 762
	class adfrc_SR25E2: adfrc_SR25_Base
	{
		author = "Brucey";
		ACE_barrelTwist = 254;
		ACE_barrelLength = 508;
		scope=2;
		scopeWeapon=2;
		scopeArsenal = 2;
		magazines[] = {
			"ADFRC_20RD_PMAG_M"
		};
		magazineWell[] = {"CBA_762x51_AR10"};
		model = "ADF_Weapons2\adfrc_SR25\SR25\adfrc_SR25e2";
		descriptionShort = "KAC SR-25 URX4 FDE 7.62x51 20in<br/>Black<br/>Caliber: 7.62x51";
		inertia = 0.6;
		picture = "\ADF_Weapons2\adfrc_SR25\SR25\data\ui\Gear_mss_SR25_20_FDE_LMT_CA.paa";
		UiPicture = "\ADF_Weapons2\adfrc_SR25\SR25\data\ui\Gear_mss_SR25_20_FDE_LMT_CA.paa";
		displayName = "SR25E2";
		recoil = "recoil_spar_dmr";
		
		 class WeaponSlotsInfo {
			mass = 110;
			allowedSlots[] = {901};
            class MuzzleSlot : asdg_MuzzleSlot_762
            {
			iconPinpoint="center";
			iconPosition[] = {-0.053,0.426};
			iconScale  = 0.25;
			iconPicture = "\A3\Weapons_F\Data\UI\attachment_muzzle.paa";
			};
            class CowsSlot : asdg_OpticRail1913_long //Top / optic slot
            {
			iconPinpoint="center";
			iconPosition[] = {0.572,0.285};
			iconScale  = 0.17;
			iconPicture = "\A3\Weapons_F\Data\UI\attachment_top.paa";
			};
			 class UnderBarrelSlot : asdg_UnderSlot //bottom / bipod
            {
			iconPinpoint="center";
			iconPosition[] = {0.133,0.68};
			iconScale  = 0.21;
			iconPicture = "\A3\weapons_f_mark\data\UI\attachment_under.paa";
			};
            class PointerSlot : asdg_FrontSideRail //side slot
            {
			iconPinpoint="center";
			iconPosition[] = {0.145,0.418};
			iconScale  = 0.25;
			iconPicture = "\A3\Weapons_F\Data\UI\attachment_side.paa";
			};
			class GripodSlot: adfrc_MLOK_grip_slot {};
        };
		 
		class Library
		{
			libTextDesc = "SR-25 URX4 FDE 7.62x51 LMT 20in";
		};
		rhs_grip1_change = "adfrc_SR25E2_GripPod";
		rhs_grip2_change = "adfrc_SR25E2_AFG";
		rhs_grip3_change = "adfrc_SR25E2_VFG";
	};

	class adfrc_SR25E2_GripPod: adfrc_SR25E2
	{
		author = "Brucey";
	displayName = "SR25E2 Grip-Pod";
    Grip_Macro(1,ar15_10in_vg_static)
	};
	
	class adfrc_SR25E2_AFG: adfrc_SR25E2
	{
		author = "Brucey";
	displayName = "SR25E2 AFG";
    Grip_Macro(2,ar15_10in_afg_static)
	};
	
	class adfrc_SR25E2_VFG: adfrc_SR25E2
	{
		author = "Brucey";
	displayName = "SR25E2 VFG";
    Grip_Macro(3,ar15_10in_vg_tb_static)
	};