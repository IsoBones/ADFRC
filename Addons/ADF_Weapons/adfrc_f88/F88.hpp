	class Rifle_Base_F;
	class ADFRC_F88_Base: Rifle_Base_F
    {
		author = "Brucey";
        scope = 1;
		muzzleend = "konec hlavne"; //Muzzle end
		muzzlepos = "usti hlavne";
        maxRecoilSway = 0.0125;
		magazineReloadSwitchPhase = 0.48;
		selectionFireAnim = "zasleh";
		inertia = 0.35;
        swayDecaySpeed = 1.25;
		handAnim[] =
		{
			"OFP2_ManSkeleton",
			"\ADF_Weapons\core\data\anims\EF88_Vg_static.rtm"
			//"\A3\Weapons_F_beta\rifles\mk20\data\Anim\mk20.rtm"
		};
		drySound[] = {"\ADF_Weapons\adfrc_ef88\Data\Sounds\AUG_dry",db-2,1,10};
		ace_overheating_mrbs = 3000; //Mean Rounds Between Stoppages (this will be scaled based on the barrel temp)
        ace_overheating_slowdownFactor = 1; //Slowdown Factor, reduces the velocity of the projectile (this will be scaled based on the barrel temp)
        ace_overheating_allowSwapBarrel = 1; // 1 to enable barrel swap. 0 to disable. Meant for machine guns where you can easily swap the barrel without dismantling the whole weapon.
        ace_overheating_dispersion = 0.25; 
		ace_overheating_closedBolt = 0; 
		ace_overheating_barrelMass = 3;
		ace_railHeightAboveBore = 1.8;  // Distance between center of bore and rail in centimeters
		aimTransitionSpeed = 1.1;
		
		cartridgepos = "nabojnicestart"; //remember this? Make sure it’s named
//right
		cartridgevel = "nabojniceend"; //the “end” is the velocity as I
//mentioned earlier 
		
		class GunParticles
		{
			class FirstEffect
			{
				effectName = "RifleAssaultCloud";
				positionName = "Usti hlavne";
				directionName = "Konec hlavne";
			};
		};
        
        opticsZoomMin = 0.375;
        opticsZoomMax = 1.1;
        opticsZoomInit = 0.75;
        distanceZoomMin = 300;
        distanceZoomMax = 300;
		
		magazines[] =
		{
			"ADFRC_30Rnd_aug"
		};
		magazineWell[] = {"CBA_556x45_STEYR"};


        dexterity = 1.3;
		bullet1[] = {"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_01",0.446684,1,15};
		bullet10[] = {"A3\sounds_f\weapons\shells\7_62\Shellcase_762_Grass_02",0.562341,1,15};
		bullet11[] = {"A3\sounds_f\weapons\shells\7_62\Shellcase_762_Grass_03",0.562341,1,15};
		bullet12[] = {"A3\sounds_f\weapons\shells\7_62\Shellcase_762_Grass_04",0.562341,1,15};
		bullet2[] = {"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_02",0.446684,1,15};
		bullet3[] = {"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_03",0.446684,1,15};
		bullet4[] = {"A3\sounds_f\weapons\shells\5_56\Shellcase_556_Metal_04",0.446684,1,15};
		bullet5[] = {"A3\sounds_f\weapons\shells\7_62\Shellcase_762_Dirt_01",0.562341,1,15};
		bullet6[] = {"A3\sounds_f\weapons\shells\7_62\Shellcase_762_Dirt_02",0.562341,1,15};
		bullet7[] = {"A3\sounds_f\weapons\shells\7_62\Shellcase_762_Dirt_03",0.562341,1,15};
		bullet8[] = {"A3\sounds_f\weapons\shells\7_62\Shellcase_762_Dirt_04",0.562341,1,15};
		bullet9[] = {"A3\sounds_f\weapons\shells\7_62\Shellcase_762_Grass_01",0.562341,1,15};
		changeFiremodeSound[] = {"A3\Sounds_F_Exp\arsenal\weapons\Rifles\SPAR01\SPAR01_firemode",0.177828,1,5};
		soundBullet[] = {"bullet1",0.087,"bullet2",0.083,"bullet3",0.083,"bullet4",0.083,"bullet5",0.083,"bullet6",0.083,"bullet7",0.083,"bullet8",0.083,"bullet9",0.083,"bullet10",0.083,"bullet11",0.083,"bullet12",0.083};
		reloadAction = "GestureReloadAUG";
		reloadMagazineSound[] = {"\ADF_Weapons\adfrc_ef88\Data\Sounds\AUG_reload",db0,1,10};
		soundBipodDeploy[] = {"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_deploy",0.70794576,1,20};
		soundBipodFold[] = {"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_fold",0.70794576,1,20};
		soundBipodDown[] = {"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_down",0.70794576,1,20};
		soundBipodUp[] = {"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_up",0.70794576,1,20};
		modes[] = {"Single","FullAuto","single_medium_optics1","single_medium_optics2","fullauto_medium"};
	
		   class WeaponSlotsInfo {
			mass = 74;
			allowedSlots[] = {901};
            class MuzzleSlot : asdg_MuzzleSlot_556
            {
			iconPinpoint="center";
			iconPosition[] = {0.076,0.328};
			iconScale  = 0.17;
			iconPicture = "\A3\Weapons_F\Data\UI\attachment_muzzle.paa";
			};
        };
		
       class Single : Mode_SemiAuto
{			autofire = 0;
			sounds[] = { "StandardSound", "SilencedSound" };
			
			class BaseSoundModeType { /// I am too lazy to copy this twice into both standard and silenced sounds, that is why there is a base class from which both inherit (and sound of closure stays the same no matter what muzzle accessory is used)
                weaponSoundEffect  = "DefaultRifle";
            };
			class SilencedSound: BaseSoundModeType {
			SoundSetShot[] = 	{ "AUG_silencerShot_SoundSet","AUG_silencerTail_SoundSet","AUG_silencerInteriorTail_SoundSet"};
			};
			class StandardSound: BaseSoundModeType {
			soundSetShot[] = {"AUG_Shot_SoundSet","AUG_Tail_SoundSet","AUG_InteriorTail_SoundSet"};
			};
						
dispersion = 0.000781776;
maxRange = 250;
maxRangeProbab = 0.2;
midRange = 150;
midRangeProbab = 0.7;
minRange = 2;
minRangeProbab = 0.5;
reloadTime = 0.088;
};

class FullAuto: Mode_FullAuto {
aiRateOfFire = 1e-06;
class BaseSoundModeType {
};
dispersion = 0.000781776;
maxRange = 30;
maxRangeProbab = 0.05;
midRange = 15;
midRangeProbab = 0.7;
minRange = 2;
minRangeProbab = 0.9;
reloadTime = 0.088;
class SilencedSound: BaseSoundModeType {
			SoundSetShot[] = 	{ "AUG_silencerShot_SoundSet","AUG_silencerTail_SoundSet","AUG_silencerInteriorTail_SoundSet"};
			};
			class StandardSound: BaseSoundModeType {
			soundSetShot[] = {"AUG_Shot_SoundSet","AUG_Tail_SoundSet","AUG_InteriorTail_SoundSet"};
			};
};
		class fullauto_medium: FullAuto
		{
			showToPlayer = false;
			burst = 3;
			minRange = 2;
			minRangeProbab = 0.5;
			midRange = 75;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.05;
			aiRateOfFire = 2;
		};
		class single_medium_optics1: Single
		{
			requiredOpticType = 1;
			showToPlayer = false;
			minRange = 5;
			minRangeProbab = 0.2;
			midRange = 300;
			midRangeProbab = 0.7;
			maxRange = 450;
			maxRangeProbab = 0.3;
			aiRateOfFire = 5;
			aiRateOfFireDistance = 500;
		};
		class single_medium_optics2: single_medium_optics1
		{
			requiredOpticType = 2;
			minRange = 100;
			minRangeProbab = 0.1;
			midRange = 400;
			midRangeProbab = 0.7;
			maxRange = 600;
			maxRangeProbab = 0.05;
			aiRateOfFire = 6;
			aiRateOfFireDistance = 600;
	  	};
};

class ADFRC_F88: ADFRC_F88_Base
	{
		author = "Brucey";
		ACE_barrelTwist = 228.6;
		ACE_barrelLength = 508;
		recoil = "recoil_spar";
		recoilProne = "recoil_spar";
		deployedPivot = "deploypoint";       /// what point should be used to be on surface while unfoldedsoundBipodUp[] = { "A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_AAF_up", db - 3, 1, 20 }; /// sound of folding the bipod
		cursor = "srifle";
		cursorAim = "EmptyCursor";
		model = "adf_weapons\adfrc_f88\ADFRC_F88";
		descriptionShort = "Thales-Lithgow<br/>F88<br/>Caliber: 5.56";
		inertia = 0.42;
		scope=2;
		scopeWeapon=2;
		scopeArsenal = 2;
		picture = "\ADF_Weapons\adfrc_ef88\Data\UI\adfrc_ef88_UI_CA.paa";
		UiPicture = "\ADF_Weapons\adfrc_ef88\Data\UI\adfrc_ef88_UI_CA.paa";
		displayName = "F88 5.56";
		discretedistance[] = { 100, 200, 300, 400 };
		discretedistanceinitindex = 2;
		opticszoominit = 0.75;
		opticszoommax = 1.1;
		opticszoommin = 0.375;
		aiDispersionCoefY = 10;
		aiDispersionCoefX = 8;
		 
		class Library
		{
			libTextDesc = "F88";
		};
	};
