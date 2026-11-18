// ADF Re-Cut: JSRS SOUNDMOD 2025 compatibility (hand weapons).
// Same rules as ADF_Ace: only ADFRC classes are patched, vanilla classes are only
// forward-declared. skipWhenMissingDependencies = 1, so if JSRS or any addon listed
// here is missing (or misspelled) this config is silently skipped. Check the RPT.
class CfgPatches
{
	class ADFRC_JSRS_Weapons
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"jsrs2025_config_c", "adfrc_F88", "ADF_EF88", "ADFRC_G19", "ADF_HPIII", "ADF_M4A5", "ADF_USP", "ADFRC_carlgustav", "ADFRC_Minimi", "ADFRC_maximi", "adfrc_mag58", "ADF_HK416", "ADF_HK417", "adfrc_sr25"};
		skipWhenMissingDependencies = 1;
		author = "ADF Re-Cut";
	};
};

class Mode_SemiAuto;
class Mode_FullAuto;
class CfgWeapons
{
	class Rifle_Base_F;
	class Rifle_Long_Base_F;
	class Pistol_Base_F;
	class Launcher_Base_F;
	class UGL_F;
	#include "CarlGustav.hpp"
	#include "EF88.hpp"
	#include "F88.hpp"
	#include "G19.hpp"
	#include "HPIII.hpp"
	#include "M4A5.hpp"
	#include "Minimi.hpp"
	#include "Maximi.hpp"
	#include "Mag58.hpp"
	#include "USP.hpp"
	#include "HK416.hpp"
	#include "HK417.hpp"
	#include "SR25.hpp"
};
