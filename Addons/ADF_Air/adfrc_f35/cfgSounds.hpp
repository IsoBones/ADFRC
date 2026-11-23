// Sound shaders and sets from Arma 3 Aegis (Plane_Fighter_05), APL-SA, renamed ADFRC_F35_*
class CfgSoundShaders
{
	class ADFRC_F35_EngineExt_Dist_Front_SoundShader
	{
		samples[] =
		{
			{"\ADF_Air\adfrc_f35\Sounds\B_Plane_Fighter_05_engine_front",1}
		};
		frequency = 1;
		volume = 0.6 * machcone*camPos*(rpm factor[0.5, 1]);
		range = 5000;
		rangeCurve[] =
		{
			{0,0},
			{50,1},
			{5000,1}
		};
	};
	class ADFRC_F35_EngineExt_Dist_Rear_SoundShader
	{
		samples[] =
		{
			{"\ADF_Air\adfrc_f35\Sounds\B_Plane_Fighter_05_engine_back",1}
		};
		frequency = 1;
		volume = 0.6 * machcone*camPos*(rpm factor[0.5, 1]);
		range = 5000;
		rangeCurve[] =
		{
			{0,0},
			{50,1},
			{5000,1}
		};
	};
	class ADFRC_F35_EngineExt_Middle_SoundShader
	{
		samples[] =
		{
			{"\ADF_Air\adfrc_f35\Sounds\B_Plane_Fighter_05_engine_middle",1}
		};
		frequency = 1;
		volume = 0.6 * machcone*camPos*(rpm factor[0.5, 1]);
		range = 4000;
		rangeCurve[] =
		{
			{0,1},
			{50,1},
			{4000,1}
		};
	};
	class ADFRC_F35_EngineHighExt_SoundShader
	{
		samples[] =
		{
			{"\ADF_Air\adfrc_f35\Sounds\B_Plane_Fighter_05_engine_high_ext",1}
		};
		frequency = 1 min (rpm + 0.5)*(rpm factor[0.5, 1.1]);
		volume = 0.6 * machcone*engineOn*camPos*(rpm factor[0, 1])*(thrust factor[0, 0.75]);
		range = 1300;
	};
	class ADFRC_F35_EngineHighInt_SoundShader
	{
		samples[] =
		{
			{"\ADF_Air\adfrc_f35\Sounds\B_Plane_Fighter_05_engine_high_int",1}
		};
		frequency = 1 min (rpm + 0.25)*(rpm factor[0.25, 1.1]);
		volume = 1 * engineOn*(1-camPos)*(rpm factor[0, 1]);
	};
	class ADFRC_F35_EngineLowExt_SoundShader
	{
		samples[] =
		{
			{"\ADF_Air\adfrc_f35\Sounds\B_Plane_Fighter_05_engine_low_ext",1}
		};
		frequency = 1 min (rpm + 0.5)*(rpm factor[0, 1]);
		volume = 0.6 * machcone*engineOn*camPos*(rpm factor[0, 1])*(thrust factor[0.75, 0]);
		range = 1200;
	};
	class ADFRC_F35_EngineLowInt_SoundShader
	{
		samples[] =
		{
			{"\ADF_Air\adfrc_f35\Sounds\B_Plane_Fighter_05_engine_low_int",1}
		};
		frequency = 1 min (rpm + 0.5)*(rpm factor[0, 1]);
		volume = 1 * engineOn*(1-camPos)*(rpm factor[0.5, 1]);
	};
	class ADFRC_F35_ForsageExt_SoundShader
	{
		samples[] =
		{
			{"\ADF_Air\adfrc_f35\Sounds\B_Plane_Fighter_05_engine_forsage_ext",1}
		};
		frequency = 1.1;
		volume = 0.6 * machcone*engineOn*camPos*(thrust factor[0.6, 1.0]);
		range = 1500;
		rangeCurve[] =
		{
			{0,1},
			{200,0.75},
			{1000,0.25},
			{1500,0}
		};
	};
	class ADFRC_F35_ForsageInt_SoundShader
	{
		samples[] =
		{
			{"\ADF_Air\adfrc_f35\Sounds\B_Plane_Fighter_05_engine_forsage_int",1}
		};
		frequency = 1 min (rpm + 0.5)*(rpm factor[0, 1]);
		volume = 1 * engineOn*(1-camPos)*(rpm factor[0.5, 1])*(thrust factor[0.5, 1.0]);
	};
	class ADFRC_F35_VelocityInt_SoundShader
	{
		samples[] =
		{
			{"\A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_velocity_int",1}
		};
		frequency = 0.75*(speed factor[1, 150]);
		volume = 1 * (1-camPos)*(gmeterZ factor[1.5, 6])*(speed factor[1, 50]);
	};
	class ADFRC_F35_WindNoiseExt_SoundShader
	{
		samples[] =
		{
			{"\A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_wind_ext",1}
		};
		frequency = 3*(speed factor[1, 200]);
		volume = 0.6 * machcone*4*camPos*(speed factor[1, 200]);
		range = 200;
	};
	class ADFRC_F35_WindNoiseInt_SoundShader
	{
		samples[] =
		{
			{"\A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_wind_int",1}
		};
		frequency = 3*(speed factor[1, 200]);
		volume = 1 * 3*(1-camPos)*(speed factor[1, 200]);
	};
};
class CfgSoundSets
{
	class ADFRC_F35_EngineExt_Dist_Front_SoundSet
	{
		soundShaders[] = {ADFRC_F35_EngineExt_Dist_Front_SoundShader};
		volumeFactor = 1.3;
		spatial = true;
		loop = true;
		volumeCurve = InverseSquare3Curve;
		shape = FrontSemispace60;
		sound3DProcessingType = JetExt_Distant_3DProcessingType;
		occlusionFactor = 0.5;
		obstructionFactor = 0;
	};
	class ADFRC_F35_EngineExt_Dist_Rear_SoundSet
	{
		soundShaders[] = {ADFRC_F35_EngineExt_Dist_Rear_SoundShader};
		volumeFactor = 1.5;
		spatial = true;
		loop = true;
		volumeCurve = InverseSquare1Curve;
		shape = RearSemispace20;
		sound3DProcessingType = JetExt_Distant_3DProcessingType;
		occlusionFactor = 0.5;
		obstructionFactor = 0;
	};
	class ADFRC_F35_EngineExt_Middle_SoundSet
	{
		soundShaders[] = {ADFRC_F35_EngineExt_Middle_SoundShader};
		volumeFactor = 1.4;
		spatial = true;
		loop = true;
		shape = FrontSemispace10;
		volumeCurve = InverseSquare3Curve;
		sound3DProcessingType = JetExt_Middle_3DProcessingType;
		occlusionFactor = 0.5;
		obstructionFactor = 0;
	};
	class ADFRC_F35_EngineHighExt_SoundSet
	{
		soundShaders[] = {ADFRC_F35_EngineHighExt_SoundShader};
		volumeFactor = 1.2;
		spatial = true;
		loop = true;
		sound3DProcessingType = JetExt_Close_3DProcessingType;
		occlusionFactor = 0.45;
		obstructionFactor = 0.35;
	};
	class ADFRC_F35_EngineHighInt_SoundSet
	{
		soundShaders[] = {ADFRC_F35_EngineHighInt_SoundShader};
		volumeFactor = 1.3;
		spatial = false;
		loop = true;
		sound3DProcessingType = VehicleInt_Back_3DProcessingType;
	};
	class ADFRC_F35_EngineLowExt_SoundSet
	{
		soundShaders[] = {ADFRC_F35_EngineLowExt_SoundShader};
		volumeFactor = 1.2;
		spatial = true;
		loop = true;
		sound3DProcessingType = JetExt_Close_3DProcessingType;
	};
	class ADFRC_F35_EngineLowInt_SoundSet
	{
		soundShaders[] = {ADFRC_F35_EngineLowInt_SoundShader};
		volumeFactor = 1.4;
		spatial = false;
		loop = true;
		sound3DProcessingType = VehicleInt_Back_3DProcessingType;
	};
	class ADFRC_F35_ForsageExt_SoundSet
	{
		soundShaders[] = {ADFRC_F35_ForsageExt_SoundShader};
		volumeFactor = 1.25;
		spatial = true;
		loop = true;
		volumeCurve = InverseSquare1Curve;
		sound3DProcessingType = JetExt_Close_3DProcessingType;
		occlusionFactor = 0.45;
		obstructionFactor = 0.35;
	};
	class ADFRC_F35_ForsageInt_SoundSet
	{
		soundShaders[] = {ADFRC_F35_ForsageInt_SoundShader};
		volumeFactor = 1.35;
		spatial = false;
		loop = true;
		sound3DProcessingType = VehicleInt_Back_3DProcessingType;
	};
	class ADFRC_F35_VelocityInt_SoundSet
	{
		soundShaders[] = {ADFRC_F35_VelocityInt_SoundShader};
		volumeFactor = 1.25;
		spatial = false;
		loop = true;
		sound3DProcessingType = VehicleInt_Front_3DProcessingType;
	};
	class ADFRC_F35_WindNoiseExt_SoundSet
	{
		soundShaders[] = {ADFRC_F35_WindNoiseExt_SoundShader};
		volumeFactor = 1;
		spatial = true;
		loop = true;
		sound3DProcessingType = JetExt_Close_3DProcessingType;
	};
	class ADFRC_F35_WindNoiseInt_SoundSet
	{
		soundShaders[] = {ADFRC_F35_WindNoiseInt_SoundShader};
		volumeFactor = 1;
		spatial = false;
		loop = true;
		sound3DProcessingType = VehicleInt_Front_3DProcessingType;
	};
};
