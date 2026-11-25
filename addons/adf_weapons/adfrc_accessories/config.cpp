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
	#include "surefire_rc\SOCOM_RC.hpp"
	#include "nt4\NT4.hpp"
	#include "ryder9\Ryder9.hpp"
	#include "zev\Zev.hpp"
	#include "f88_silencer\F88_Silencer.hpp"
	
	////WEAPON LIGHTS
	#include "F88LightLasers.hpp"
	#include "x400\X400.hpp"
	#include "wmlx\WMLx.hpp"
	#include "peq15\Peq15.hpp"
	#include "l3squad\L3Squad.hpp"
	#include "p320\Foxtrot2.hpp"
	
	////Bipods/Grips
	#include "grip_pod\grippod.hpp"
	#include "atlas\atlas.hpp"
	#include "harris\Harris.hpp"
	
	
};
