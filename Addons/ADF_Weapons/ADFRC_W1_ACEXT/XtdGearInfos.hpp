#define PATTERN_ADFRC_M4A5_STD(name, m, t, g, s, l) \
	class name          \
	{                   \
		model = #m;     \
		type = #t;      \
		gasblock = #g;      \
		stock = #s;      \
		gl = #l;      \
	}; 
	
#define PATTERN_ADFRC_M4A5_TROY(name, m, p, s) \
	class name          \
	{                   \
		model = #m;     \
		camo = #p;      \
		stock = #s;      \
	}; 
	
#define PATTERN_ADFRC_M4A5_COMBO(name, m, p, b) \
	class name          \
	{                   \
		model = #m;     \
		camo = #p;      \
		barrel = #b;      \
	}; 
	
#define PATTERN_ADFRC_EF88(name, m, p, t) \
	class name          \
	{                   \
		model = #m;     \
		camo = #p;      \
		type = #t;      \
	}; 
	
#define PATTERN_ADFRC_MINIMI(name, m, t, b) \
	class name          \
	{                   \
		model = #m;     \
		type = #t;      \
		barrel = #b;      \
	}; 


	
class XtdGearInfos
{
	class CfgWeapons
	{
		
		
		PATTERN_ADFRC_EF88(ADFRC_EF88_Black,                  ADFRC_EF88,BLK,STD)
		PATTERN_ADFRC_EF88(ADFRC_EF88_Camo,                  ADFRC_EF88,CAM,STD)
		PATTERN_ADFRC_EF88(ADFRC_EF88C_Black,                  ADFRC_EF88,BLK,C)
		PATTERN_ADFRC_EF88(ADFRC_EF88C_Camo,                  ADFRC_EF88,CAM,C)
		PATTERN_ADFRC_EF88(ADFRC_EF88_SL40_Black,                  ADFRC_EF88,BLK,SL40)
		PATTERN_ADFRC_EF88(ADFRC_EF88_SL40_Camo,                  ADFRC_EF88,CAM,SL40)
		
		
		PATTERN_ADFRC_M4A5_STD(ADFRC_M4A5_KAC_M203_556_CTR,                  ADFRC_M4A5,RAS,FS,CTR,YES)
		PATTERN_ADFRC_M4A5_STD(ADFRC_M4A5_KAC_M203_556,                  	 ADFRC_M4A5,RAS,FS,M4SS,YES)
		PATTERN_ADFRC_M4A5_STD(ADFRC_M4A5_KAC_NOFS_556_CTR,                  ADFRC_M4A5,RAS,MK12,CTR,NO)
		PATTERN_ADFRC_M4A5_STD(ADFRC_M4A5_KAC_NOFS_556,                  	 ADFRC_M4A5,RAS,MK12,M4SS,NO)
		PATTERN_ADFRC_M4A5_STD(ADFRC_M4A5_Classic_556,                  	 ADFRC_M4A5,HEAT,FS,M4SS,NO)
		PATTERN_ADFRC_M4A5_STD(ADFRC_M4A5_KAC_556_CTR,                  	 ADFRC_M4A5,RAS,FS,CTR,NO)
		PATTERN_ADFRC_M4A5_STD(ADFRC_M4A5_KAC_556,                  	 	 ADFRC_M4A5,RAS,FS,M4SS,NO)
		
		
		PATTERN_ADFRC_M4A5_TROY(ADFRC_M4A5_Troy_556_14,                  	 	 ADFRC_M4A5_T,FDE,M4SS)
		PATTERN_ADFRC_M4A5_TROY(ADFRC_M4A5_Troy_556_14_BLK,                  	 ADFRC_M4A5_T,BLK,M4SS)
		PATTERN_ADFRC_M4A5_TROY(ADFRC_M4A5_Troy_556_14_FDE_CTR,                  ADFRC_M4A5_T,FDE,CTR)
		PATTERN_ADFRC_M4A5_TROY(ADFRC_M4A5_Troy_556_14_BLK_CTR,                 ADFRC_M4A5_T,BLK,CTR)
		
		
		PATTERN_ADFRC_M4A5_COMBO(ADFRC_M4A5_Combo_556_14_BLK,                  	 	 ADFRC_M4A5_C,BLK,14)
		PATTERN_ADFRC_M4A5_COMBO(ADFRC_M4A5_Combo_556_14_FDE,                  	 	 ADFRC_M4A5_C,FDE,14)
		PATTERN_ADFRC_M4A5_COMBO(ADFRC_M4A5_Combo_556_10_BLK,                  	 	 ADFRC_M4A5_C,BLK,11)
		PATTERN_ADFRC_M4A5_COMBO(ADFRC_M4A5_Combo_556_10_FDE,                  	 	 ADFRC_M4A5_C,FDE,11)
		
		
		PATTERN_ADFRC_MINIMI(ADFRC_F89_Minimi_Classic,                  	 	 ADFRC_F89_minimis,CLA,465)
		PATTERN_ADFRC_MINIMI(ADFRC_F89_Minimi,                  	 	 ADFRC_F89_minimis,MK3,465)
		PATTERN_ADFRC_MINIMI(ADFRC_F89_Minimi_Para,                  	 	 ADFRC_F89_minimis,Para,465)
		PATTERN_ADFRC_MINIMI(ADFRC_F89_Minimi_Para_S,                  	 	 ADFRC_F89_minimis,Para,349)
		PATTERN_ADFRC_MINIMI(ADFRC_F89_Minimi_Mod,                  	 	 ADFRC_F89_minimis,MOD,465)
		PATTERN_ADFRC_MINIMI(ADFRC_F89_Minimi_Mod_S,                  	 	 ADFRC_F89_minimis,MOD,349)
		

		PATTERN_ADFRC_MINIMI(ADFRC_maximi,                  	 		 ADFRC_F89_Maximis,MK3,465)
		PATTERN_ADFRC_MINIMI(ADFRC_maximi_Para,                  	 	 ADFRC_F89_Maximis,Para,465)
		PATTERN_ADFRC_MINIMI(ADFRC_maximi_Para_Short,                  	 ADFRC_F89_Maximis,Para,349)
		PATTERN_ADFRC_MINIMI(ADFRC_maximi_Modern,                  	 	 ADFRC_F89_Maximis,MOD,465)
		PATTERN_ADFRC_MINIMI(ADFRC_maximi_Modern_Short,                  ADFRC_F89_Maximis,MOD,349)
		
		
		
		
		
		
		
				};
		};