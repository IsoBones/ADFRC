class CfgPatches{
	class ADF_Units{
		name="ADF_Units";
		author="ADFRC Team";
		requiredAddons[]={
			"A3_Data_F",
			"ADF_Core",
			"ADF_Gear"
		};
		units[]={"ADFRC_MD_RAN_Coxswain","ADFRC_MD_RAN_BoardingOfficer","ADFRC_MD_RAN_BoardingRifleman","ADFRC_MD_RAN_BoardingMedic","ADFRC_MD_RAN_BoardingMG","ADFRC_MD_RAN_DeckGunner","ADFRC_MD_RAN_OOW"};
		weapons[]={};
		//fileName = "ADF_Units.pbo";
	};
};

class CfgVehicles{
	#include "modern\rar\Infantry.hpp"
	#include "modern\rar\Recce.hpp"
	#include "modern\cdo\Infantry.hpp"
	//#include "modern\cdo\TAG.hpp"   ## BASE CLASSES DONT EVEN EXIST FOR THESE YET!
	#include "modern\sasr\Infantry.hpp"
	//#include "modern\sasr\TAG.hpp"  ## BASE CLASSES DONT EVEN EXIST FOR THESE YET!
	#include "modern\Backpacks.hpp"
	#include "modern\ran\Crew.hpp"
};

class cfgGroups
{  
  class WEST
  {
    name="BLUFOR";
	#include "modern\rar\Groups.hpp"
	#include "modern\cdo\Groups.hpp"
	#include "modern\sasr\Groups.hpp"
};
};
