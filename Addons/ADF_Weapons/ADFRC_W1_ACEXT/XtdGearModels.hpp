class XtdGearModels
{
	class CfgWeapons 
	{
		
		
		class ADFRC_EF88
		{
			label = "EF88";
			author = "Thales / Lithgow";
			options[] = {"camo","type"};
			class camo
			{
				values[] = {"BLK","CAM"};
				class BLK
				{
					label = "BLK";
					image = "ADF_Weapons\ADFRC_W1_ACEXT\Gear_MCC_BLK"; 
				};
				class CAM
				{
					label = "CAM";
					image = "ADF_Weapons\ADFRC_W1_ACEXT\Gear_MCC_CAM"; 
				};
			};
			class type
			{
				label = "Type";
				values[] = {"STD","C","SL40"};
				class STD
				{
					label = "EF88";
				};
				class C
				{
					label = "EF88C";
				};
				class SL40
				{
					label = "EF88-SL40";
				};
			};
		};
		
		
		class ADFRC_M4A5
		{
			label = "M4A5-AU";
			author = "Colt";
			options[] = {"type","gasblock","gl","stock"};
			class type
			{
				label = "Handguard";
				values[] = {"HEAT","RAS"};
				class HEAT
				{
					label = "Heatshield";
				};
				class RAS
				{
					label = "RAS";
				};
			};
			class gasblock
			{
				label = "Type";
				values[] = {"FS","MK12"};
				class FS
				{
					label = "FS";
				};
				class MK12
				{
					label = "MK12";
				};
			};
			class gl
			{
				label = "M203";
				values[] = {"Yes","No"};
				class Yes
				{
					label = "Yes";
				};
				class No
				{
					label = "No";
				};
			};
			class stock
			{
				label = "Stock";
				values[] = {"CTR","M4SS"};
				class CTR
				{
					label = "CTR";
				};
				class M4SS
				{
					label = "GI";
				};
			};
		};
		
		class ADFRC_M4A5_T
		{
			label = "M4A5-AU TROY";
			author = "Colt";
			options[] = {"camo","stock"};
			class camo
			{
				values[] = {"BLK","FDE"};
				class BLK
				{
					label = "BLK";
					image = "ADF_Weapons\ADFRC_W1_ACEXT\Gear_MCC_BLK"; 
				};
				class FDE
				{
					label = "FDE";
					image = "ADF_Weapons\ADFRC_W1_ACEXT\Gear_MCC_FDE"; 
				};
				};
			class stock
			{
				values[] = {"M4SS","CTR"};
				class M4SS
				{
					label = "GI";
				};
				class CTR
				{
					label = "CTR";
				};
			};
		};
		
		class ADFRC_M4A5_C
		{
			label = "M4A5-AU COMBO";
			author = "Colt";
			options[] = {"camo","barrel"};
			class camo
			{
				values[] = {"BLK","FDE"};
				class BLK
				{
					label = "BLK";
					image = "ADF_Weapons\ADFRC_W1_ACEXT\Gear_MCC_BLK"; 
				};
				class FDE
				{
					label = "FDE";
					image = "ADF_Weapons\ADFRC_W1_ACEXT\Gear_MCC_FDE"; 
				};
			};
			class barrel
			{
				values[] = {"11","14"};
				class 11
				{
					label = "11.5";
				};
				class 14
				{
					label = "14.5";
				};
			};
		};
		
		class ADFRC_F89_minimis
		{
			label = "F89 Minimi MK3s";
			author = "FN";
			options[] = {"type","barrel"};
			class type
			{
				label = "Spec";
				values[] = {"CLA","Para","MK3","MOD"};
				class CLA
				{
					label = "CLA";
				};
				class Para
				{
					label = "Para";
				};
				class MK3
				{
					label = "Mk3";
				};class MOD
				{
					label = "MOD";
				};
			};
			class barrel
			{
				label = "Barrel";
				values[] = {"349","465"};
				class 349
				{
					label = "Para";
				};
				class 465
				{
					label = "Standard";
				};
			};
		};
		
		class ADFRC_F89_Maximis
		{
			label = "F89 Maximi";
			author = "FN";
			options[] = {"type","barrel"};
			class type
			{
				label = "Spec";
				values[] = {"Para","MK3","MOD"};
				class Para
				{
					label = "Para";
				};
				class MK3
				{
					label = "Mk3";
				};class MOD
				{
					label = "MOD";
				};
			};
			class barrel
			{
				label = "Barrel";
				values[] = {"349","465"};
				class 349
				{
					label = "Para";
				};
				class 465
				{
					label = "Standard";
				};
			};
		};
		
		
	};
	};