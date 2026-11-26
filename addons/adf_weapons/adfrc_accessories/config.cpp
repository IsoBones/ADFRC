class CfgPatches
{
	class adfrc_accessories
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"ADF_Core"};
	};
};
class SlotInfo;
class PointerSlot;

#include "Muzzle_Acc_JR.hpp"
#include "Rail_Acc_JR.hpp"

class CfgWeapons
{
	class SlotInfo;
	class ItemCore;
	class InventoryOpticsItem_Base_F;
	class InventoryFlashLightItem_Base_F;
	class InventoryMuzzleItem_Base_F;
	class InventoryUnderItem_Base_F;
	
	class Rifle;
    class Rifle_Base_F: Rifle
    {
        class WeaponSlotsInfo;
        class GunParticles;
    };
    class Pistol_Base_F;
	class Zasleh2: ItemCore
	{
		scope = 2;
		model = "A3\weapons_f\data\zaslehsdl_proxy.p3d";
	};
	class Zasleh3: ItemCore
	{
		scope = 2;
		model = "A3\weapons_f\data\zasleh3_proxy.p3d";
	};
	
	
	////MUZZLE DEVICES
	class muzzle_snds_M;
	#include "SUREFIRE_RC\SOCOM_RC.hpp"
	#include "NT4\NT4.hpp"
	#include "Ryder9\Ryder9.hpp"
	#include "Zev\Zev.hpp"
	#include "F88_SILENCER\F88_Silencer.hpp"
	
	////WEAPON LIGHTS
	#include "F88LightLasers.hpp"
	#include "X400\X400.hpp"
	#include "WMLx\WMLx.hpp"
	#include "PEQ15\Peq15.hpp"
	#include "L3Squad\L3Squad.hpp"
	#include "P320\Foxtrot2.hpp"
	
	////Bipods/Grips
	#include "Grip_Pod\grippod.hpp"
	#include "ATLAS\atlas.hpp"
	#include "Harris\Harris.hpp"
	
	
};
