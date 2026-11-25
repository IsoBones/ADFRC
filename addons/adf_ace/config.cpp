// ADF Re-Cut ACE compatibility.
//
// Rules for this patch:
// - Only ADFRC classes are patched. Vanilla (and other mods') classes are only
//   forward-declared as parents, never redefined or given properties.
// - Every ADFRC patch whose classes are touched here is listed in
//   requiredAddons by its exact CfgPatches name, so this always loads after them.
// - Plain ace_* properties that are harmless without ACE can live in the
//   asset's own config. This patch is for anything that needs ACE loaded
//   (ACE item classes) or that we only want applied when ACE is present.
// - skipWhenMissingDependencies = 1: if ANY entry below is misspelled or
//   missing, the whole patch is silently skipped. Check the RPT after edits.

class CfgPatches
{
	class ADFRC_ACE_Compat
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"ace_common",
			"ADFRC_F1_Grenade",
			"adfrc_magazines",
			"adfrc_apache",
			"ADFRC_blackhawk",
			"adfrc_chinook",
			"adfrc_c130",
			"adfrc_aslav",
			"adfrc_bushmaster"
		};
		skipWhenMissingDependencies = 1;
	};
};

class CfgAmmo
{
	class GrenadeHand;

	// F1 frag grenade. ACE's GrenadeHand defaults are the M67; these are the F1's.
	// ace_frag_enabled is not a config property (ACE never reads it), so it isn't set.
	class ADFRC_F1_Ammo: GrenadeHand
	{
		ace_frag_skip = 0;
		ace_frag_force = 1;
		ace_frag_metal = 210;
		ace_frag_charge = 185;
		ace_frag_gurney_c = 2930;
		ace_frag_gurney_k = "3/5"; // getNumber evaluates the string, as the old patch did
		ace_frag_classes[] = {"ace_frag_medium_HD"};
	};
};

class CfgMagazines
{
	class CA_Magazine;

	// Belts that can be linked together (ACE reload / CSW).
	class ADFRC_100Rnd_556_Belt: CA_Magazine
	{
		ACE_isBelt = 1;
	};
	class ADFRC_200Rnd_556_Belt: CA_Magazine
	{
		ACE_isBelt = 1;
	};
	class ADFRC_50Rnd_762_Belt: CA_Magazine
	{
		ACE_isBelt = 1;
	};
};

class CfgVehicles
{
	// Vanilla parents, forward-declared only.
	class Helicopter_Base_H;
	class APC_Wheeled_03_base_F;
	class Car_F;

	// ADFRC parents that aren't patched themselves.
	class adfrc_apache_base;
	class adfrc_c130_inf_base;
	class adfrc_c130_vic_base;
	class ADFRC_blackhawk;

	// AH-64E
	class adfrc_apache: adfrc_apache_base
	{
		ace_cargo_hasCargo = 0;
		ace_hellfire_addLaserDesignator = 1;
	};

	// UH-60 (fastroping is set in the Blackhawk's own config)
	class ADFRC_blackhawk_BASE: Helicopter_Base_H
	{
		ace_cargo_space = 4;
		ace_cargo_hasCargo = 1;
	};
	class ADFRC_blackhawk_cargo: ADFRC_blackhawk
	{
		ace_cargo_space = 8;
	};

	// CH-47 (fastroping is set in the Chinook's own config)
	class ADFRC_chinook_base: Helicopter_Base_H
	{
		ace_cargo_space = 14;
		ace_cargo_hasCargo = 1;
		class TransportItems
		{
			class _xx_ace_rope36
			{
				name = "ACE_rope36";
				count = 4;
			};
		};
	};

	// C-130
	class adfrc_c130_inf: adfrc_c130_inf_base
	{
		ace_cargo_space = 16;
		ace_cargo_hasCargo = 1;
	};
	class adfrc_c130_inf_auscam: adfrc_c130_inf_base
	{
		ace_cargo_space = 16;
		ace_cargo_hasCargo = 1;
	};
	class adfrc_c130_vic: adfrc_c130_vic_base
	{
		ace_cargo_space = 20;
		ace_cargo_hasCargo = 1;
	};
	class adfrc_c130_vic_auscam: adfrc_c130_vic_base
	{
		ace_cargo_space = 20;
		ace_cargo_hasCargo = 1;
	};

	// ASLAV (real parent is APC_Wheeled_03_base_F; this used to say _01_ and
	// re-parented every ASLAV onto the Marshall whenever ACE was loaded)
	class adfrc_aslav_base: APC_Wheeled_03_base_F
	{
		ace_cargo_space = 6;
		ace_vehicle_damage_hullDetonationProb = 0.2;
		ace_vehicle_damage_turretDetonationProb = 0.1;
		ace_vehicle_damage_engineDetonationProb = 0.2;
		ace_vehicle_damage_hullFireProb = 0.2;
		ace_vehicle_damage_turretFireProb = 0.1;
		ace_vehicle_damage_engineFireProb = 0.5;
		ace_vehicle_damage_detonationDuringFireProb = 0.2;
		ace_vehicle_damage_canHaveFireRing = 0;
	};

	// Bushmaster (bma3)
	class adfrc_bushmaster_base_F: Car_F
	{
		ace_cargo_space = 8;
	};
};
