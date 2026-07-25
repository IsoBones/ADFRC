class adfrc_KAC_PRG : ItemCore
 	{
 		scope = 2;
		displayName="KAC PRG Suppressor";
		author = "Brucey";
 		picture="\ADF_Weapons2\adfrc_SR25\Muzzle\data\ui\Gear_adfrc_PRG_FDE_CA.paa";
 		uipreview="\ADF_Weapons2\adfrc_SR25\Muzzle\data\ui\Gear_adfrc_PRG_FDE_CA.paa";
 		model = "\ADF_Weapons2\adfrc_SR25\Muzzle\adfrc_PRG_FDE";	
		
 		
 		class ItemInfo: InventoryMuzzleItem_Base_F
 		{	
 			soundTypeIndex = 1; // index of sound in sounds[] in weapon modes (inherited 1 from parent class)
			
			class MagazineCoef
			{
				initSpeed = 0.8;
			};
		mass = 16.8;
 
 			class MuzzleCoef
		{
			dispersionCoef = "0.8f";
			artilleryDispersionCoef = "1.0f";
			fireLightCoef = "0.1f";
			recoilCoef = "0.9f";
			recoilProneCoef = "0.85f";
			minRangeCoef = "1.0f";
			minRangeProbabCoef = "1.0f";
			midRangeCoef = "1.0f";
			midRangeProbabCoef = "1.0f";
			maxRangeCoef = "1.0f";
			maxRangeProbabCoef = "1.0f";
		};
		
 			class AmmoCoef
 			{
 				hit=1.05;
 				visibleFire=0.3;
 				audibleFire=0.8;
 				visibleFireTime=0.5;
 				audibleFireTime=1.0;
 				cost = 1.0;
 				typicalSpeed= 1.1;
 				airFriction = 1.0;      
 			};  
 
 			muzzleEnd = "zaslehPoint"; // memory point in muzzle supressor's model
 			alternativeFire = "Zasleh2";  // class in cfgWeapons with model of muzzle flash	
 		};
 	};

