class CfgPatches
{
	class ADFRC_ACE_Compat {
		units[] =
		{
		};
		weapons[] =
		{
		};
		requiredAddons[] =
		{
			"ace_common",
			"ace_explosives",
			"ace_interact_menu",
			"ace_repair",
			"bma3",
			"adfrc_aslav",
			"ADF_Weapons",
			"ADF_Air",
		
		};
		skipWhenMissingDependencies = 1;
	};
};
class cfgAmmo {
	//Grenades
	class GrenadeHand;
	class SmokeShell;
	class ADFRC_F1_Ammo : GrenadeHand {
		ace_frag_enabled = 1;
		ace_frag_metal = 210;
		ace_frag_charge = 185;
		ace_frag_gurney_c = 2930;
		ace_frag_gurney_k = "3/5";
		ace_frag_classes[] =
		{
			"ACE_frag_medium_HD"
		};
		ace_frag_skip = 0;
		ace_frag_force = 1;
	};

	//Launcher Ammo
	class RocketBase;
	class ADFRC_RR_Ammo_Base : RocketBase {
	};
	class ADFRC_Shell_84mm_adm_401 : ADFRC_RR_Ammo_Base {
	};
	class ADFRC_Shell_84mm_asm_509 : ADFRC_RR_Ammo_Base {
	};
	class ADFRC_Shell_84mm_he_441d : ADFRC_RR_Ammo_Base {
	};
	class ADFRC_Shell_84mm_heat_551c : ADFRC_RR_Ammo_Base {
	};
	class ADFRC_Shell_84mm_heat_751 : ADFRC_RR_Ammo_Base {
	};
	class ADFRC_Shell_84mm_hedp_502 : ADFRC_RR_Ammo_Base {
	};
	class ADFRC_Shell_84mm_illum_545c : ADFRC_RR_Ammo_Base {
	};
	class ADFRC_Shell_84mm_mt_756 : ADFRC_RR_Ammo_Base {
	};
	class ADFRC_Shell_84mm_smk_469c : ADFRC_RR_Ammo_Base {
	};

};
class CfgMagazines {
	class CA_Magazine;
	class ADFRC_100Rnd_556_Belt : CA_Magazine {
		ace_isbelt = 1;
	};
	class ADFRC_200Rnd_556_Belt : CA_Magazine {
		ace_isbelt = 1;
	};
	class ADFRC_50Rnd_762_Belt : CA_Magazine {
		ace_isbelt = 1;
	};
};
class CfgWeapons {
	class Pistol_Base_F;
	class Rifle_Base_F;
	class UGL_F;
	class ADFRC_pistol_base : Pistol_Base_F {};
	class ADFRC_hpII : ADFRC_pistol_base {
		ACE_barrelTwist = 254;
		ACE_barrelLength = 119;
		ACE_overheating_mrbs = 2000;
		ACE_overheating_slowdownFactor = 1.15;
		ACE_overheating_allowSwapBarrel = 0;
		ACE_overheating_dispersion = 0.25;
		ACE_arsenal_hide = 0;
		ACE_twistDirection = 1;
		ace_overheating_closedBolt = 1;
	};
	class hgun_P07_F;
	class ADFRC_pistol_base_f : hgun_P07_F
	{};
	class ADFRC_usp : ADFRC_pistol_base_f {
		ACE_barrelTwist = 250;
		ACE_barrelLength = 108;
		ACE_overheating_mrbs = 2000;
		ACE_overheating_slowdownFactor = 1.15;
		ACE_overheating_allowSwapBarrel = 0;
		ACE_overheating_dispersion = 0.25;
		ACE_arsenal_hide = 0;
		ACE_twistDirection = 1;
		ace_overheating_closedBolt = 1;
	};
	class arifle_AUG_base_F : Rifle_Base_F{
		ACE_barrelTwist = 178.8;
		ACE_barrelLength = 508;
		ACE_overheating_mrbs = 3000;
		ACE_overheating_slowdownFactor = 1.25;
		ACE_overheating_allowSwapBarrel = 0;
		ACE_overheating_dispersion = 0.25;
		ACE_arsenal_hide = 0;
		ACE_twistDirection = 1;
		ace_overheating_closedBolt = 1;
	};
	class arifle_AUG_GL_base_F : arifle_AUG_base_F {
		class EGLM : UGL_F {
			magazines[] += {
				"ACE_HuntIR_M203"
			};
		};
	};
	class arifle_AUG_C_base_F : arifle_AUG_base_F {
		ACE_barrelTwist = 178.8;
		ACE_barrelLength = 406;
		ACE_overheating_mrbs = 3000;
		ACE_overheating_slowdownFactor = 1.25;
		ACE_overheating_allowSwapBarrel = 0;
		ACE_overheating_dispersion = 0.25;
		ACE_arsenal_hide = 0;
		ACE_twistDirection = 1;
		ace_overheating_closedBolt = 1;
	};

	class ADFRC_F88SA1_base : Rifle_Base_F {
	};

	class ADFRC_F88SA1 : ADFRC_F88SA1_base {
		ACE_barrelTwist = 178.8;
		ACE_barrelLength = 508;
		ACE_overheating_mrbs = 3000;
		ACE_overheating_slowdownFactor = 1.25;
		ACE_overheating_allowSwapBarrel = 0;
		ACE_overheating_dispersion = 0.25;
		ACE_arsenal_hide = 0;
		ACE_twistDirection = 1;
		ace_overheating_closedBolt = 1;
	};
	class ADFRC_F88SA1_elcan : ADFRC_F88SA1_base {
	};
	class ADFRC_F88SA1_gl : ADFRC_F88SA1 {
		class M203: UGL_F {
			magazines[]={
				"ACE_HuntIR_M203"
			};
		};
	};
	class ADFRC_F88SA1_gl_elcan : ADFRC_F88SA1_gl {
		class M203 : UGL_F {
			magazines[] = {
				"ACE_HuntIR_M203"
			};
		};
	};
	class  ADFRC_f88sa2_base : ADFRC_F88SA1_base {};
	class ADFRC_f88sa2 : ADFRC_f88sa2_base {
		ACE_barrelTwist = 178.8;
		ACE_barrelLength = 508;
		ACE_overheating_mrbs = 3000;
		ACE_overheating_slowdownFactor = 1.25;
		ACE_overheating_allowSwapBarrel = 0;
		ACE_overheating_dispersion = 0.25;
		ACE_arsenal_hide = 0;
		ACE_twistDirection = 1;
		ace_overheating_closedBolt = 1;
	};
	class ADFRC_f88sa2_gl : ADFRC_f88sa2 {
		class M203: UGL_F {
			magazines[]= {
				"ACE_HuntIR_M203"
			};
		};
	};


	class Rifle_Long_Base_F : Rifle_Base_F{};
	class adfrc_mag58 : Rifle_Long_Base_F {
		ACE_barrelTwist = 304.8;
		ACE_barrelLength = 630;
		ACE_overheating_mrbs = 6000;
		ACE_overheating_slowdownFactor = 1.15;
		ACE_overheating_allowSwapBarrel = 1;
		ACE_overheating_dispersion = 0.25;
		ACE_arsenal_hide = 0;
		ACE_twistDirection = 1;
		ACE_clearJamAction = "GestureReload";
		ACE_checkTemperatureAction = "Gear";
		ace_overheating_closedBolt = 0;
	};
	class ADFRC_minimi_BASE : Rifle_Long_Base_F {};
	class ADFRC_minimi : ADFRC_minimi_BASE {
		ACE_barrelTwist = 178.8;
		ACE_barrelLength = 465;
		ACE_overheating_mrbs = 9600;
		ACE_overheating_slowdownFactor = 1.25;
		ACE_overheating_allowSwapBarrel = 1;
		ACE_overheating_dispersion = 0.25;
		ACE_arsenal_hide = 0;
		ACE_twistDirection = 1;
		ACE_clearJamAction = "GestureReload";
		ACE_checkTemperatureAction = "Gear";
		ace_overheating_closedBolt = 0;
	};
	class ADFRC_minimi_para : ADFRC_minimi {
		ACE_barrelTwist = 178.8;
		ACE_barrelLength = 349;
		ace_overheating_closedBolt = 0;
	};
	class  ADFRC_maximi : ADFRC_minimi_BASE {
		ACE_barrelTwist = 304.8;
		ACE_barrelLength = 502;
		ACE_overheating_mrbs = 7000;
		ACE_overheating_slowdownFactor = 1.25;
		ACE_overheating_allowSwapBarrel = 1;
		ACE_overheating_dispersion = 0.25;
		ACE_arsenal_hide = 0;
		ACE_twistDirection = 1;
		ACE_clearJamAction = "GestureReload";
		ACE_checkTemperatureAction = "Gear";
		ace_overheating_closedBolt = 0;
	};
	class Launcher_Base_F;
	class ADFRC_carlgustav_m3 : Launcher_Base_F {
		ACE_overpressure_angle = 60;
		ACE_overpressure_range = 18;
		ACE_overpressure_damage = 0.7;
		ACE_reloadlaunchers_enabled = 1;
	};
	class ADFRC_carlgustav_m3_mrco : ADFRC_carlgustav_m3{
		ACE_overpressure_angle = 60;
		ACE_overpressure_range = 18;
		ACE_overpressure_damage = 0.7;
		ACE_reloadlaunchers_enabled = 1;
	};
};
class CfgVehicles {
	//Helicopters
	class Helicopter;
	class B_Heli_Light_01_F;
	class Helicopter_Base_F : Helicopter {
	};
	class Helicopter_Base_H : Helicopter_Base_F {
	};
	class Heli_Attack_03_base_F : Helicopter_Base_F {

	};
	class adfrc_apache : Heli_Attack_03_base_F {
		ace_cargo_hasCargo = 0;
		ace_hellfire_addLaserDesignator = 1;
	};
	class ADFRC_blackhawk_BASE : Helicopter_Base_H {
		ace_cargo_space = 4;
		ace_cargo_hasCargo = 1;
		ace_fastroping_enabled = 1;
		ace_fastroping_ropeOrigins[] =
		{
			"ropeOriginLeft",
			"ropeOriginRight"
		};
	};
	class ADFRC_blackhawk : ADFRC_blackhawk_BASE {};
	class ADFRC_blackhawk_cargo : ADFRC_blackhawk {
		ace_cargo_space = 8;
	};
	class ADFRC_chinook_base : Helicopter_Base_H {
		ace_cargo_space = 14;
		ace_cargo_hasCargo = 1;
	};
	class MRH90 : Helicopter_Base_H {
		ace_cargo_space = 8;
		ace_cargo_hasCargo = 1;
		ace_fastroping_enabled = 1;
		ace_fastroping_ropeOrigins[] =
		{
			1.47,1.8099999,-0.0099999998
		};
	};
	//fixed wing
	class Plane_Base_F;
	class Plane_Transport_01_base_F : Plane_Base_F{};
	class Plane_Transport_01_infantry_base_F : Plane_Transport_01_base_F{
		ace_cargo_space = 16;
		ace_cargo_hasCargo = 1;
	};
	class Plane_Transport_01_vehicle_base_F : Plane_Transport_01_base_F{
		ace_cargo_space = 20;
		ace_cargo_hasCargo = 1;
	};

	//land vics
	class Car_F;
	class B_MRAP_01_F;
	class Wheeled_APC_F : Car_F {
	};
	class APC_Wheeled_01_base_F;
	class ADFRC_ASLAV_base : APC_Wheeled_01_base_F {
		ace_cargo_space = 6;
		ace_cookoff_probability = 0.5;
		ace_vehicle_damage_hullDetonationProb = 0.2;
		ace_vehicle_damage_turretDetonationProb = 0.1;
		ace_vehicle_damage_engineDetonationProb = 0.2;
		ace_vehicle_damage_hullFireProb = 0.2;
		ace_vehicle_damage_turretFireProb = 0.1;
		ace_vehicle_damage_engineFireProb = 0.5;
		ace_vehicle_damage_detonationDuringFireProb = 0.2;
		ace_vehicle_damage_canHaveFireRing = 0;
		/*class ACE_Actions: ACE_Actions
        {
            class ADFRC_removeSpareWheel
            {
                displayName = "Remove Spare Wheel";
                distance = 4;
                position = "[-0.40, -3.92, -1.23]";
                condition = "_target animationSourcePhase 'sparewheel' > 0.5";
                statement = "[5, [_player, _target], {(_this select 0) params ['_unit','_veh']; [_veh, ['sparewheel', 0]] remoteExec ['animateSource', 0, _veh]; ['ACE_Wheel', getPosASL _unit, 0] call ace_repair_fnc_spawnObject}, {}, 'Removing spare wheel...'] call ace_common_fnc_progressBar;";
                icon = "\a3\ui_f\data\igui\cfg\actions\repair_ca.paa";
            };
        };*/
		//ace_vehicle_damage_slatHitpoints[] =
		//{
		//	"Slat_armor",
		//	"Slat_armor2"
		//};
	};
	class adfrc_bushmaster_base_F : Car_F {
		ace_cargo_space = 8;
	};
};
