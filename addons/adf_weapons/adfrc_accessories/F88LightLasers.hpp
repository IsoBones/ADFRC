class ADFRC_F88SA1_laser: ItemCore
	{
		scope=2;
		displayName="Laser Pointer (f88sa1)";
		picture="\ADF_Weapons\adfrc_accessories\LASER_F88SA2\ui\laser_ca.paa";
		model="\ADF_Weapons\adfrc_accessories\LASER_f88sa1\LASER_f88sa1";
		descriptionShort="Ring Mounted accessories";
		author="$STR_ADF_AUTHOR";
		class ItemInfo: InventoryFlashLightItem_Base_F
		{
			mass=4;
			class Pointer
			{
				RMBhint="Laser Pointer";
				irLaserPos="laser_dir";
				irLaserEnd="laser";
				irdistance=750;
			};
			class FlashLight
			{
			};
		};
	};
	class ADFRC_F88SA1_light: ItemCore
	{
		scope=2;
		displayName="Flash-Light (f88sa1)";
		picture="\ADF_Weapons\adfrc_accessories\LIGHT_F88SA2\ui\light_ca.paa";
		model="\ADF_Weapons\adfrc_accessories\LIGHT_f88sa1\LIGHT_f88sa1";
		descriptionShort="Ring Mounted accessories";
		author="$STR_ADF_AUTHOR";
		class ItemInfo: InventoryFlashLightItem_Base_F
		{
			RMBhint="Ring Mount Flash-light";
			mass=4;
			class FlashLight
			{
				color[] = {180,160,130};
				ambient[] = {0.9,0.81,0.7};
				intensity = 100;
				size = 1;
				innerAngle = 5;
				outerAngle = 60;
				coneFadeCoef = 6;
				position = "flashdir";
				direction = "flashpos";
				useFlare = 1;
				flareSize = 1.4;
				flareMaxDistance = 100;
				dayLight = 0;
				class Attenuation
				{
					start = 0;
					constant = 0.5;
					linear = 0.1;
					quadratic = 0.2;
					hardLimitStart = 27;
					hardLimitEnd = 34;
				};
				volumeShape = "a3\data_f\VolumeLightFlashlight.p3d";
				scale[] = {1,1,1};
			};
		};
	};
	class ADFRC_f88sa2_light: ADFRC_F88SA1_light
	{
		scope=2;
		displayName="Flash-Light (F88SA2)";
		picture="\ADF_Weapons\adfrc_accessories\LIGHT_F88SA2\ui\light_ca.paa";
		model="\ADF_Weapons\adfrc_accessories\LIGHT_F88SA2\LIGHT_F88SA2";
		author="$STR_ADF_AUTHOR";
	};
	class ADFRC_f88sa2_light_tan: ADFRC_f88sa2_light
	{
		scope=2;
		displayName="Flash-light Tan (F88SA2)";
		picture="\ADF_Weapons\adfrc_accessories\LIGHT_F88SA2\ui\light_ca.paa";
		model="\ADF_Weapons\adfrc_accessories\LIGHT_F88SA2\LIGHT_TAN_F88SA2";
		author="$STR_ADF_AUTHOR";
	};
	class ADFRC_f88sa2_laser: ItemCore
	{
		scope=2;
		displayName="Laser Pointer (F88SA2)";
		picture="\ADF_Weapons\adfrc_accessories\LASER_F88SA2\ui\laser_ca.paa";
		model="\ADF_Weapons\adfrc_accessories\LASER_F88SA2\LASER_F88SA2";
		author="$STR_ADF_AUTHOR";
		class ItemInfo: InventoryFlashLightItem_Base_F
		{
			mass=4;
			class Pointer
			{
				RMBhint="Laser Pointer";
				irLaserPos="laser_dir";
				irLaserEnd="laser";
				irdistance=750;
			};
			class FlashLight
			{
			};
		};
	};
	class ADFRC_f88sa2_laser_tan: ADFRC_f88sa2_laser
	{
		scope=2;
		displayName="ADF Laser Pointer (Tan)";
		picture="\ADF_Weapons\adfrc_accessories\LASER_F88SA2\ui\laser_ca.paa";
		model="\ADF_Weapons\adfrc_accessories\LASER_F88SA2\LASER_TAN_F88SA2";
		author="$STR_ADF_AUTHOR";
	};