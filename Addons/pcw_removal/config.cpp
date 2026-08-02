class CfgPatches
{
	class adfrc_bushmaster_hide_pcw
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Soft_F",
			"ADF_Core",
			"adfrc_bushmaster"
		};
		magazines[]=
		{};
		ammo[]={};
	};
};

class CfgVehicles
{
	class adfrc_bushmaster_unarmed_F;
	class adfrc_bushmaster_unarmed_ecm_F;
	class adfrc_bushmaster_unarmed_command_F;
	class adfrc_bushmaster_pws127mm_F;
	class adfrc_bushmaster_pws127mm_ecm_F;
	class adfrc_bushmaster_unarmed_mev_F;
	class adfrc_bushmaster_unarmed_F_PCW: adfrc_bushmaster_unarmed_F
	{
		faction = "ADFRC_F_PCW";
		scope=1;
		scopeCurator=1;
	};
	class adfrc_bushmaster_unarmed_ecm_F_PCW: adfrc_bushmaster_unarmed_ecm_F
	{
		faction = "ADFRC_F_PCW";
		scope=1;
		scopeCurator=1;
	};
	class adfrc_bushmaster_unarmed_command_F_PCW: adfrc_bushmaster_unarmed_command_F
	{
		faction = "ADFRC_F_PCW";
		scope=1;
		scopeCurator=1;
	};
	class adfrc_bushmaster_pws127mm_F_PCW: adfrc_bushmaster_pws127mm_F
	{
		faction = "ADFRC_F_PCW";
		scope=1;
		scopeCurator=1;
	};
	class adfrc_bushmaster_pws127mm_ecm_F_PCW: adfrc_bushmaster_pws127mm_ecm_F
	{
		faction = "ADFRC_F_PCW";
		scope=1;
		scopeCurator=1;
	};
	class adfrc_bushmaster_unarmed_mev_F_PCW: adfrc_bushmaster_unarmed_mev_F
	{
		faction = "ADFRC_F_PCW";
		scope=1;
		scopeCurator=1;
	};
};

