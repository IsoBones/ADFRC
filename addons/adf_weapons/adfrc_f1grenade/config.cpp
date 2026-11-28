class CfgPatches
{
	class ADFRC_F1_Grenade
	{
		author = "ADF Re-Cut";
		requiredAddons[] = {"A3_Data_F_Mod_Loadorder", "cba_main", "cba_xeh", "ADF_Core"};
		requiredVersion = 0.1;
		units[] = {};
		weapons[] = {};
		magazines[] = {"ADFRC_F1_Grenade"};
		ammo[] = {"ADFRC_F1_Ammo"};
	};
};

class CfgFunctions
{
	class adfrc_f1grenade
	{
		class functions
		{
			file = "ADF_Weapons\adfrc_f1grenade\functions";
			class spoonFired {};
			class spoonFly {};
			class spoonModel {};
		};
	};
};

class Extended_FiredBIS_EventHandlers
{
	class CAManBase
	{
		class adfrc_f1grenade_spoon
		{
			clientFiredBIS = "_this call adfrc_f1grenade_fnc_spoonFired";
		};
	};
};

class CfgWeapons
{
	class GrenadeLauncher;
	class Throw: GrenadeLauncher
	{
		muzzles[] += {"ADFRC_F1_Muzzle"};
		class ThrowMuzzle;
		class ADFRC_F1_Muzzle: ThrowMuzzle
		{
			magazines[] = {"ADFRC_F1_Grenade"};
			magazineReloadTime = 3;
		};
	};
};

class CfgMagazines
{
	class HandGrenade;
	class ADFRC_F1_Grenade: HandGrenade
	{
		scope = 2;
		author = "$STR_ADFRC_AUTHOR";
		displayName = "F1 Fragmentation Grenade";
		displayNameShort = "F1 Frag";
		descriptionShort = "Australian F1 fragmentation hand grenade";
		picture = "\ADF_Weapons\adfrc_f1grenade\UI\gear_adfrc_f1_grenade_ca.paa";
		model = "\ADF_Weapons\adfrc_f1grenade\adfrc_f1_grenade.p3d";
		ammo = "ADFRC_F1_Ammo";
		initSpeed = 15;
	};
};

class CfgAmmo
{
	class GrenadeHand;
	class ADFRC_F1_Ammo: GrenadeHand
	{
		model = "\ADF_Weapons\adfrc_f1grenade\adfrc_f1_grenade.p3d";
		adfrc_spoonModel = "adf_weapons\adfrc_f1grenade\adfrc_f1_spoon.p3d";
		hit = 20;
		indirectHit = 10;
		indirectHitRange = 7.5;
		explosive = 1;
		explosionTime = 5;
		explosionEffects = "GrenadeExplosion";
		explosionEffectsRadius = 5;
		craterEffects = "GrenadeCrater";
		deflecting = 15;
		coefGravity = 1;
		typicalSpeed = 30;
		shadow = 1;
		cost = 35;
		aiAmmoUsageFlags = 64;
		allowAgainstInfantry = 1;
		shootDistraction = 10;
	};
};
