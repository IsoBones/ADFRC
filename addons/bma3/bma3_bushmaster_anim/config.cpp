////////////////////////////////////////////////////////////////////
//DeRap: P:\bma3\bma3_bushmaster_anim\config.bin
//Produced from mikero's Dos Tools Dll version 9.36
//https://mikero.bytex.digital/Downloads
//'now' is Sun Jul 14 09:54:40 2024 : 'file' last modified on Sat Jul 13 21:58:43 2024
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class bma3_bushmaster_anim
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[]=
		{
			"A3_Data_F_AoW_Loadorder",
			"A3_Data_F_Mod_Loadorder"
		};
	};
};
class CfgMovesBasic
{
	class ManActions
	{
		bushmaster_driver = "bushmaster_driver";
		bushmaster_gunner = "bushmaster_gunner_settlein";
		bushmaster_ffv_front = "bushmaster_ffv_front_settlein";
		bushmaster_ffv_rearleft = "bushmaster_ffv_left_settlein";
		bushmaster_ffv_rearright = "bushmaster_ffv_right_settlein";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class KIA_passenger_generic01;
		class passenger_generic01_foldhands;
		class passenger_generic01_foldhands_settlein;
		class bushmaster_driver: Crew
		{
			file = "\bma3\bma3_bushmaster_anim\anim\bushmaster_driver.rtm";
			interpolateTo[] = {"KIA_Driver_mid01",1};
			speed = -30;
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1};
		};
		class bushmaster_gunner_settlein: Crew
		{
			file = "\A3\cargoposes_F\Anim\gunner_MRAP_01_settlein.rtm";
			speed = -1.5;
			looped = 0;
			connectTo[] = {"bushmaster_gunner",1};
			interpolateTo[] = {"KIA_gunner_MRAP_01",1};
			variantsAI[] = {"bushmaster_gunner",1};
			variantsPlayer[] = {"bushmaster_gunner",1};
			variantAfter[] = {1.5,1.5,1.5};
			useIdles = 0;
			leftHandIKCurve[] = {0};
			rightHandIKCurve[] = {0};
		};
		class bushmaster_gunner: Crew
		{
			file = "\bma3\bma3_bushmaster_anim\anim\bushmaster_gunner_mocap.rtm";
			speed = -30;
			interpolateTo[] = {"KIA_gunner_MRAP_01",1};
		};
		class bushmaster_ffv_front_settlein: passenger_generic01_foldhands_settlein
		{
			file = "\bma3\bma3_bushmaster_anim\anim\bushmaster_ffv_front_settlein.rtm";
			speed = -1.5;
			looped = 0;
			connectTo[] = {"bushmaster_ffv_front",1};
			interpolateTo[] = {"bushmaster_ffv_front_kia",1};
			variantsAI[] = {"bushmaster_ffv_front",1};
			variantsPlayer[] = {"bushmaster_ffv_front",1};
		};
		class bushmaster_ffv_front_idle: passenger_generic01_foldhands
		{
			file = "\BMA3\bma3_bushmaster_anim\anim\bushmaster_ffv_front_sitting.rtm";
			speed = -30;
			interpolateTo[] = {"bushmaster_ffv_front_kia",1};
		};
		class bushmaster_ffv_front: passenger_generic01_foldhands
		{
			file = "\BMA3\bma3_bushmaster_anim\anim\bushmaster_ffv_front_mocap.rtm";
			speed = -30;
			interpolateTo[] = {"bushmaster_ffv_front_kia",1};
		};
		class bushmaster_ffv_front_kia: KIA_passenger_generic01
		{
			file = "\BMA3\bma3_bushmaster_anim\anim\bushmaster_ffv_front_kia.rtm";
			connectTo[] = {"Unconscious",0.1};
		};
		class bushmaster_ffv_left_settlein: passenger_generic01_foldhands_settlein
		{
			file = "\BMA3\bma3_bushmaster_anim\anim\bushmaster_ffv_left_settlein.rtm";
			speed = -1.5;
			looped = 0;
			connectTo[] = {"bushmaster_ffv_left",1};
			interpolateTo[] = {"bushmaster_ffv_left_kia",1};
			variantsAI[] = {"bushmaster_ffv_left",1};
			variantsPlayer[] = {"bushmaster_ffv_left",1};
		};
		class bushmaster_ffv_left_idle: passenger_generic01_foldhands
		{
			file = "\BMA3\bma3_bushmaster_anim\anim\bushmaster_ffv_left_sitting.rtm";
			speed = -30;
			interpolateTo[] = {"bushmaster_ffv_left_kia",1};
		};
		class bushmaster_ffv_left: passenger_generic01_foldhands
		{
			file = "\BMA3\bma3_bushmaster_anim\anim\bushmaster_ffv_left_mocap.rtm";
			speed = -30;
			interpolateTo[] = {"bushmaster_ffv_left_kia",1};
		};
		class bushmaster_ffv_left_kia: KIA_passenger_generic01
		{
			file = "\BMA3\bma3_bushmaster_anim\anim\bushmaster_ffv_left_kia.rtm";
			connectTo[] = {"Unconscious",0.1};
		};
		class bushmaster_ffv_right_settlein: passenger_generic01_foldhands_settlein
		{
			file = "\BMA3\bma3_bushmaster_anim\anim\bushmaster_ffv_right_settlein.rtm";
			speed = -1.5;
			looped = 0;
			connectTo[] = {"bushmaster_ffv_right",1};
			interpolateTo[] = {"bushmaster_ffv_right_kia",1};
			variantsAI[] = {"bushmaster_ffv_right",1};
			variantsPlayer[] = {"bushmaster_ffv_right",1};
		};
		class bushmaster_ffv_right_idle: passenger_generic01_foldhands
		{
			file = "\BMA3\bma3_bushmaster_anim\anim\bushmaster_ffv_right_sitting.rtm";
			speed = -30;
			interpolateTo[] = {"bushmaster_ffv_right_kia",1};
		};
		class bushmaster_ffv_right: passenger_generic01_foldhands
		{
			file = "\BMA3\bma3_bushmaster_anim\anim\bushmaster_ffv_right_mocap.rtm";
			speed = -30;
			interpolateTo[] = {"bushmaster_ffv_right_kia",1};
		};
		class bushmaster_ffv_right_kia: KIA_passenger_generic01
		{
			file = "\BMA3\bma3_bushmaster_anim\anim\bushmaster_ffv_right_kia.rtm";
			connectTo[] = {"Unconscious",0.1};
		};
	};
};
