#define Grip_Macro(numb,name) \
    handAnim[] = {"OFP2_ManSkeleton",\ADF_Weapons\core\data\anims\##name##.rtm};\
    class LinkedItems\
    {\
        class LinkedItemsUnder\
        {\
            item = rhsusf_acc_grip##numb##;\
            slot = "UnderBarrelSlot";\
        };\
    };
	
class CfgPatches
{
	class ADF_HK417
	{
		units[] = {};
		weapons[] = {""};
		requiredVersion = 0.1;
		requiredAddons[] = {"ADF_Core"};
		fileName = "ADF_HK417.pbo";
	};
};

class ItemCore;
class InventoryUnderItem_Base_F;
class InventoryMuzzleItem_Base_F;
class InventoryItem_Base_F;
class InventoryOpticsItem_Base_F;
class InventoryFlashLightItem_Base_F;
class ACE_ItemCore;
class CBA_MiscItem_ItemInfo;
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
class Mode_FullAuto;
class asdg_SlotInfo;
class recoil_default;
class Mode_SemiAuto;
class adfrc_PIC_grip_slot;
class compatibleItems;
class cfgweapons{
#include "HK417.hpp"
#include "Presets.hpp"
};