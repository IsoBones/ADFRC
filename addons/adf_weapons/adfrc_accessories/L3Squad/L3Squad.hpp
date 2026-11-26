//// M4A5
///Standard Right
class ADFRC_L3Squad_IRL: ItemCore
	{
		author = "Brucey";
		scope = 2;
		displayName = "L3 SQUAD (IR-Laser)";
		picture = "\ADF_Weapons\adfrc_accessories\L3Squad\ui\L3Squad_ca.paa";
		UiPicture = "\ADF_Weapons\adfrc_accessories\L3Squad\ui\L3Squad_ca.paa";
		model = "ADF_Weapons\adfrc_accessories\L3Squad\ADFRC_L3Squad";
		
		class ItemInfo: InventoryFlashLightItem_Base_F
		{
			mass = 2.5;
			class Pointer
			{
				irLaserPos = "laserpos";
				irLaserEnd = "laserdir";
			};
		};
		inertia = 0.1;
		
		MRT_SwitchItemNextClass = "ADFRC_L3Squad_IRT";
        MRT_SwitchItemPrevClass = "ADFRC_L3Squad_IRT";
        MRT_switchItemHintText = "IR-Laser";
	};
	
class ADFRC_L3Squad_IRT: ItemCore
	{
		author = "Brucey";
		scope = 2;
		displayName = "L3 SQUAD (IR-Light)";
		picture = "\ADF_Weapons\adfrc_accessories\L3Squad\ui\L3Squad_ca.paa";
		UiPicture = "\ADF_Weapons\adfrc_accessories\L3Squad\ui\L3Squad_ca.paa";
		model = "ADF_Weapons\adfrc_accessories\L3Squad\ADFRC_L3Squad";
		
		class ItemInfo: InventoryFlashLightItem_Base_F
		{
			mass = 2.5;
			class FlashLight
			{
				color[] = {180,160,130};
				ambient[] = {0.9,0.81,0.7};
				intensity = 25;
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
				irLight = 1;	
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
		inertia = 0.1;
		
		MRT_SwitchItemNextClass = "ADFRC_L3Squad_IRL";
        MRT_SwitchItemPrevClass = "ADFRC_L3Squad_IRL";
        MRT_switchItemHintText = "IR-Light";
	};
	
	
//// M4A5
///Standard Right
class ADFRC_L3Squad_EF88_Top_IRL: ADFRC_L3Squad_IRL
	{
		author = "Brucey";
		scope = 2;
		displayName = "L3 SQUAD EF88-Top (IR-Laser)";
		picture = "\ADF_Weapons\adfrc_accessories\L3Squad\ui\L3Squad_ca.paa";
		UiPicture = "\ADF_Weapons\adfrc_accessories\L3Squad\ui\L3Squad_ca.paa";
		model = "ADF_Weapons\adfrc_accessories\L3Squad\ADFRC_L3Squad_EF88_Top";
		
		class ItemInfo: InventoryFlashLightItem_Base_F
		{
			mass = 2.5;
			class Pointer
			{
				irLaserPos = "laserpos";
				irLaserEnd = "laserdir";
			};
		};
		inertia = 0.07;
		
		MRT_SwitchItemNextClass = "ADFRC_L3Squad_EF88_Top_IRT";
        MRT_SwitchItemPrevClass = "ADFRC_L3Squad_EF88_Top_IRT";
        MRT_switchItemHintText = "IR-Laser";
	};
	
class ADFRC_L3Squad_EF88_Top_IRT: ADFRC_L3Squad_IRT {
		author = "Brucey";
		scope = 2;
		displayName = "L3 SQUAD EF88-Top(IR-Light)";
		picture = "\ADF_Weapons\adfrc_accessories\L3Squad\ui\L3Squad_ca.paa";
		UiPicture = "\ADF_Weapons\adfrc_accessories\L3Squad\ui\L3Squad_ca.paa";
		model = "ADF_Weapons\adfrc_accessories\L3Squad\ADFRC_L3Squad_EF88_Top";
		
		class ItemInfo: InventoryFlashLightItem_Base_F
		{
			mass = 2.5;
			class FlashLight
			{
				color[] = {180,160,130};
				ambient[] = {0.9,0.81,0.7};
				intensity = 25;
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
				irLight = 1;	
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
		inertia = 0.07;
		
		MRT_SwitchItemNextClass = "ADFRC_L3Squad_EF88_Top_IRL";
        MRT_SwitchItemPrevClass = "ADFRC_L3Squad_EF88_Top_IRL";
        MRT_switchItemHintText = "IR-Light";
	};