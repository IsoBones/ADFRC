class CfgPatches
{
	class adfrc_f88sa1
	{
		units[]={};
		weapons[]=
		{
			"ADFRC_F88SA1",
			"ADFRC_F88SA1_gl",
			"ADFRC_F88SA1_elcan",
			"ADFRC_F88SA1_gl_elcan",
			"ADFRC_F88SA1_tag48",
			"ADFRC_F88SA1_gl_ta648",
			"ADFRC_F88SA1_mrco",
			"ADFRC_F88SA1_gl_mrco",
			"ADFRC_F88SA1_hamr",
			"ADFRC_F88SA1_gl_hamr",
			"ADFRC_F88SA1_fg"
		};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Weapons_F",
			"A3_Weapons_F_Acc",
			"ADFRC_magazines",
			"adfrc_accessories",
			"adf_optics",
			"adfrc_f88",
			"adfrc_f88SA2"
		};
	};
};
class Mode_SemiAuto;
class Mode_FullAuto;
class SlotInfo;
class CowsSlot;
class PointerSlot;
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
class ADFRC_f88sa2_base;
class CfgWeapons
{
	class Rifle;
	class UGL_F;
	class Binocular;
	class Pistol;
	class SlotInfo;
	class ItemCore;
	class InventoryOpticsItem_Base_F;
	class InventoryFlashLightItem_Base_F;
	class InventoryMuzzleItem_Base_F;
	class ADFRC_F88SA1: ADFRC_f88sa2_base
	{
		author="Quiggs & Brucey";
		model = "adf_weapons\adfrc_f88SA1\ADFRC_F88SA1";
		ACE_barrelTwist = 228.6;
		ACE_barrelLength = 508;
		recoil = "recoil_spar";
		recoilProne = "recoil_spar";
		displayName="F88S-A1 Austeyr";
		deployedPivot = "deploypoint";       /// what point should be used to be on surface while unfoldedsoundBipodUp[] = { "A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_AAF_up", db - 3, 1, 20 }; /// sound of folding the bipod
		cursor = "srifle";
		cursorAim = "EmptyCursor";
		descriptionShort = "Thales-Lithgow<br/>F88<br/>Caliber: 5.56";
		inertia = 0.42;
		scope=2;
		scopeWeapon=2;
		scopeArsenal = 2;
		picture = "\ADF_Weapons\adfrc_f88sa1\UI\gear_adfrc_F88SA1_x_ca.paa";
		UiPicture = "\ADF_Weapons\adfrc_f88sa1\UI\gear_adfrc_F88SA1_x_ca.paa";
		discretedistance[] = { 100, 200, 300, 400 };
		discretedistanceinitindex = 2;
		opticszoominit = 0.75;
		opticszoommax = 1.1;
		opticszoommin = 0.375;
		aiDispersionCoefY = 10;
		aiDispersionCoefX = 8;
		
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
	};
	class ADFRC_F88SA1_gl: ADFRC_F88SA1
	{
		scope=2;
		model="\adf_weapons\adfrc_f88sa1\ADFRC_F88SA1_M203.p3d";
		author="$STR_ADFRC_AUTHOR";
		dexterity=1.6799999;
		displayName="F88S-A1 Austeyr M203";
		muzzles[]=
		{
			"this",
			"M203"
		};
		adfrc_switch=0;
		adfrc_alternate="";
		adfrc_magazine="";
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
					"adf_weapons\adfrc_f88sa1\sound\f88_m203",
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
	class ADFRC_F88SA1_elcan: ADFRC_F88SA1
	{
		scope=1;
		author="$STR_ADFRC_AUTHOR";
		displayName="THIS IS A BUG!";
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="ADFRC_elcan_c79";
			};
		};
	};
	class ADFRC_F88SA1_gl_elcan: ADFRC_F88SA1_gl
	{
		scope=2;
		author="$STR_ADFRC_AUTHOR";
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="ADFRC_elcan_c79";
			};
		};
	};
	class ADFRC_F88SA1_tag48: ADFRC_F88SA1
	{
		scope=2;
		author="$STR_ADFRC_AUTHOR";
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="ADFRC_acog_ta648";
			};
		};
	};
	class ADFRC_F88SA1_gl_ta648: ADFRC_F88SA1_gl
	{
		scope=2;
		author="$STR_ADFRC_AUTHOR";
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="ADFRC_acog_ta648";
			};
		};
	};
	class ADFRC_F88SA1_mrco: ADFRC_F88SA1
	{
		scope=2;
		author="$STR_ADFRC_AUTHOR";
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="optic_MRCO";
			};
		};
	};
	class ADFRC_F88SA1_gl_mrco: ADFRC_F88SA1_gl
	{
		scope=2;
		author="$STR_ADFRC_AUTHOR";
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="optic_MRCO";
			};
		};
	};
	class ADFRC_F88SA1_hamr: ADFRC_F88SA1
	{
		scope=2;
		author="$STR_ADFRC_AUTHOR";
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="optic_HAMR";
			};
		};
	};
	class ADFRC_F88SA1_gl_hamr: ADFRC_F88SA1_gl
	{
		scope=2;
		author="$STR_ADFRC_AUTHOR";
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="optic_HAMR";
			};
		};
	};
	class ADFRC_F88SA1_swarovski_laser: ADFRC_F88SA1
	{
		scope=1;
		author="$STR_ADFRC_AUTHOR";
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="ADFRC_swarovski_optic";
			};
			class LinkedItemsPointer
			{
				slot="PointerSlot";
				item="ADFRC_F88SA1_laser";
			};
		};
	};
	class ADFRC_F88SA1_gl_eotech_laser: ADFRC_F88SA1_gl
	{
		scope=1;
		author="$STR_ADFRC_AUTHOR";
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="ADFRC_eotech552";
			};
			class LinkedItemsPointer
			{
				slot="PointerSlot";
				item="ADFRC_F88SA1_laser";
			};
		};
	};
	class ADFRC_F88SA1_eotech_laser: ADFRC_F88SA1
	{
		scope=1;
		author="$STR_ADFRC_AUTHOR";
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="ADFRC_eotech552";
			};
			class LinkedItemsPointer
			{
				slot="PointerSlot";
				item="ADFRC_F88SA1_laser";
			};
		};
	};
	class ADFRC_F88SA1_ta648_laser: ADFRC_F88SA1
	{
		scope=1;
		author="$STR_ADFRC_AUTHOR";
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="ADFRC_acog_ta648";
			};
			class LinkedItemsPointer
			{
				slot="PointerSlot";
				item="ADFRC_F88SA1_laser";
			};
		};
	};
};
