class CfgPatches
{
	class ADFRC_f88sa2
	{
		units[]={};
		weapons[]=
		{
			"ADFRC_f88sa2_base",
			"ADFRC_f88sa2",
			"ADFRC_f88sa2_fg",
			"ADFRC_f88sa2_camo",
			"ADFRC_f88sa2_camo_fg",
			"ADFRC_f88sa2_gl",
			"ADFRC_f88sa2_gl_camo",
			"ADFRC_f88sa2_elcan",
			"ADFRC_f88sa2_gl_elcan",
			"ADFRC_f88sa2_camo_elcan",
			"ADFRC_f88sa2_gl_camo_elcan",
			"ADFRC_f88sa2_ta648",
			"ADFRC_f88sa2_gl_ta648",
			"ADFRC_f88sa2_camo_ta648",
			"ADFRC_f88sa2_gl_camo_ta648",
			"ADFRC_f88sa2_mrco",
			"ADFRC_f88sa2_gl_mrco",
			"ADFRC_f88sa2_camo_mrco",
			"ADFRC_f88sa2_gl_camo_mrco",
			"ADFRC_f88sa2_hamr",
			"ADFRC_f88sa2_gl_hamr",
			"ADFRC_f88sa2_camo_hamr",
			"ADFRC_f88sa2_gl_camo_hamr"
		};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Weapons_F",
			"A3_Weapons_F_Acc",
			"ADF_Core",
			"adfrc_f88"
		};
	};
};
class Mode_SemiAuto;
class Mode_FullAuto;
class SlotInfo;
class CowsSlot;
class PointerSlot;
class CowsSlot_ADFRC_Styer;
//////////////////////////////////class asdg_SlotInfo;
class asdg_FrontSideRail;
class asdg_OpticRail;
class asdg_OpticRail1913;
class asdg_OpticRail1913_short;
class asdg_OpticRail1913_long;
class asdg_MuzzleSlot;
class asdg_MuzzleSlot_762: asdg_MuzzleSlot {};
class asdg_MuzzleSlot_556: asdg_MuzzleSlot {};
class asdg_UnderSlot;
class CfgWeapons
{
	class UGL_F;
	class SlotInfo;
	class ItemCore;
	class InventoryOpticsItem_Base_F;
	class InventoryFlashLightItem_Base_F;
	class InventoryMuzzleItem_Base_F;
	class ADFRC_F88_base;
	class ADFRC_f88sa2_base: ADFRC_F88_base
	{
		scope=1;
		model="ADF_Weapons\adfrc_f88sa2\ADFRC_F88SA2.p3d";
		dexterity=1.6799999;
		picture="\ADF_Weapons\adfrc_f88sa2\UI\gear_ADFRC_f88sa2_x_ca.paa";
		UiPicture="\A3\weapons_f\data\UI\icon_regular_CA.paa";
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
            class CowsSlot : asdg_OpticRail1913 //Top / optic slot
            {
			iconPinpoint="center";
			iconPosition[] = {0.527,0.184};
			iconScale  = 0.15;
			iconPicture = "\A3\Weapons_F\Data\UI\attachment_top.paa";
			};
        };
		class GunParticles
		{
			class FirstEffect
			{
				directionname="Konec hlavne";
				effectname="RifleAssaultCloud";
				positionname="Usti hlavne";
			};
			class SecondEffect
			{
				positionName="Nabojnicestart";
				directionName="Nabojniceend";
				effectName="CaselessAmmoCloud";
			};
		};
		
		
		ACE_barrelTwist = 228.6;
		ACE_barrelLength = 508;
		recoil = "recoil_spar";
		recoilProne = "recoil_spar";
		deployedPivot = "deploypoint";       /// what point should be used to be on surface while unfoldedsoundBipodUp[] = { "A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_AAF_up", db - 3, 1, 20 }; /// sound of folding the bipod
		cursor = "srifle";
		cursorAim = "EmptyCursor";
		inertia = 0.42;
		discretedistance[] = { 100, 200, 300, 400 };
		discretedistanceinitindex = 2;
		opticszoominit = 0.75;
		opticszoommax = 1.1;
		opticszoommin = 0.375;
		aiDispersionCoefY = 10;
		aiDispersionCoefX = 8;
	};
	class ADFRC_f88sa2: ADFRC_f88sa2_base
	{
		scope=2;
		displayName="F88S-A2 Austeyr";
		author="Brucey & Quiggs";
	};
	class ADFRC_f88sa2_camo: ADFRC_f88sa2
	{
		scope=1;
		displayName="F88S-A2 Austeyr (Camo)";
	};
	class ADFRC_f88sa2_gl: ADFRC_f88sa2
	{
		scope=2;
		model="ADF_Weapons\adfrc_f88sa2\ADFRC_F88SA2_M203.p3d";
		dexterity=1.6799999;
		displayName="F88S-A2 Austeyr M203";
		author="Brucey & Quiggs";
		muzzles[]=
		{
			"this",
			"M203"
		};
		ADFRC_weapon_switch=0;
		ADFRC_weapon_alternate="";
		ADFRC_weapon_magazine="";
		weaponInfoType="RscWeaponZeroing";
		handAnim[] =
		{
			"OFP2_ManSkeleton",
			"\ADF_Weapons\adfrc_ef88\Data\Anim\AUG_GL.rtm"
			//"\A3\Weapons_F_beta\rifles\mk20\data\Anim\mk20.rtm"
		};
		class M203: UGL_F
		{
			displayName="M203";
			descriptionShort="$STR_A3_cfgweapons_3gl1";
			useModelOptics=0;
			useExternalOptic=0;
			magazines[]=
			{
				"1Rnd_HE_Grenade_shell",
				"UGL_FlareWhite_F",
				"UGL_FlareGreen_F",
				"UGL_FlareRed_F",
				"UGL_FlareYellow_F",
				"UGL_FlareCIR_F",
				"1Rnd_Smoke_Grenade_shell",
				"1Rnd_SmokeRed_Grenade_shell",
				"1Rnd_SmokeGreen_Grenade_shell",
				"1Rnd_SmokeYellow_Grenade_shell",
				"1Rnd_SmokePurple_Grenade_shell",
				"1Rnd_SmokeBlue_Grenade_shell",
				"1Rnd_SmokeOrange_Grenade_shell"
			};
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				weaponSoundEffect="DefaultRifle";
				begin1[]=
				{
					"ADF_Weapons\adfrc_f88sa1\sound\f88_m203",
					4,
					1,
					250
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			cameraDir="OP_look";
			discreteDistance[]={50,100,150,200,250};
			discreteDistanceCameraPoint[]=
			{
				"OP_eye_50",
				"OP_eye_100",
				"OP_eye_150",
				"OP_eye_200",
				"OP_eye_250"
			};
			discreteDistanceInitIndex=1;
		};
	};
	class ADFRC_f88sa2_gl_camo: ADFRC_f88sa2_gl
	{
		scope=1;
	};
	class ADFRC_f88sa2_elcan: ADFRC_f88sa2
	{
		scope=2;
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="ADFRC_elcan_c79";
			};
		};
	};
	class ADFRC_f88sa2_gl_elcan: ADFRC_f88sa2_gl
	{
		scope=2;
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="ADFRC_elcan_c79";
			};
		};
	};
	class ADFRC_f88sa2_camo_elcan: ADFRC_f88sa2_camo
	{
		scope=1;
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="ADFRC_elcan_c79";
			};
		};
	};
	class ADFRC_f88sa2_gl_camo_elcan: ADFRC_f88sa2_gl_camo
	{
		scope=1;
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="ADFRC_elcan_c79";
			};
		};
	};
	class ADFRC_f88sa2_ta648: ADFRC_f88sa2
	{
		scope=2;
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="ADFRC_acog_ta648_t";
			};
		};
	};
	class ADFRC_f88sa2_gl_ta648: ADFRC_f88sa2_gl
	{
		scope=2;
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="ADFRC_acog_ta648_t";
			};
		};
	};
	class ADFRC_f88sa2_camo_ta648: ADFRC_f88sa2_camo
	{
		scope=1;
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="ADFRC_acog_ta648_t";
			};
		};
	};
	class ADFRC_f88sa2_gl_camo_ta648: ADFRC_f88sa2_gl_camo
	{
		scope=1;
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="ADFRC_acog_ta648_t";
			};
		};
	};
	class ADFRC_f88sa2_mrco: ADFRC_f88sa2
	{
		scope=2;
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="optic_mrco";
			};
		};
	};
	class ADFRC_f88sa2_gl_mrco: ADFRC_f88sa2_gl
	{
		scope=2;
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="optic_mrco";
			};
		};
	};
	class ADFRC_f88sa2_camo_mrco: ADFRC_f88sa2_camo
	{
		scope=1;
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="optic_mrco";
			};
		};
	};
	class ADFRC_f88sa2_gl_camo_mrco: ADFRC_f88sa2_gl_camo
	{
		scope=1;
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="optic_mrco";
			};
		};
	};
	class ADFRC_f88sa2_hamr: ADFRC_f88sa2
	{
		scope=2;
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="optic_hamr";
			};
		};
	};
	class ADFRC_f88sa2_gl_hamr: ADFRC_f88sa2_gl
	{
		scope=2;
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="optic_hamr";
			};
		};
	};
	class ADFRC_f88sa2_camo_hamr: ADFRC_f88sa2_camo
	{
		scope=1;
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="optic_hamr";
			};
		};
	};
	class ADFRC_f88sa2_gl_camo_hamr: ADFRC_f88sa2_gl_camo
	{
		scope=1;
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="optic_hamr";
			};
		};
	};
};
