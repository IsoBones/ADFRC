class CfgPatches
{
	class ADFRC_hk417_sand
	{
		requiredAddons[] = {"A3_Weapons_F_Exp"};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] = 
		{
			"arifle_SPAR_03_blk_F",
			"ADFRC_hk417_DMR",
		};
	};
};


class compatibleItems;
class arifle_SPAR_03_blk_F;
class CfgWeapons
{
	class ADFRC_hk417_DMR: arifle_SPAR_03_blk_F
	{
		scope=1;
		author="$STR_ADFRC_AUTHOR";
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot="CowsSlot";
				item="ADFRC_acog_ta648_rds";
			};
			class LinkedItemsPointer
			{
				slot="PointerSlot";
				item="acc_pointer_IR";
			};
			class LinkItemsUnder
			{
				slot = "UnderBarrelSlot";
				item = "ADFRC_Atlas_BT10";
			};
		};
	};
};