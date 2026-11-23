// Sound config from Arma 3 Aegis (Plane_Fighter_05), APL-SA. Samples in \ADF_Air\adfrc_f35\Sounds\
        attenuationEffectType = PlaneAttenuation;
		soundGetIn[] = {"\ADF_Air\adfrc_f35\Sounds\getin",db0,1,40};
		soundGetOut[] = {"\ADF_Air\adfrc_f35\Sounds\getout",db0,1,40};
		cabinOpenSound[] = {"\A3\Sounds_F\air\noises\Plane_CAS01_CabinOpen",db5,1,40};
		cabinCloseSound[] = {"\A3\Sounds_F\air\noises\Plane_CAS01_CabinClose",db5,1,40};
		cabinOpenSoundInternal[] = {"\A3\Sounds_F\air\noises\Plane_CAS01_CabinOpen",10.0,1,40};
		cabinCloseSoundInternal[] = {"\A3\Sounds_F\air\noises\Plane_CAS01_CabinClose",10.0,1,40};
        soundWaterCollision1[] = {"\A3\Sounds_F\vehicles\crashes\planes\plane_crash_water_1",db3,1,500};
        soundWaterCollision2[] = {"\A3\Sounds_F\vehicles\crashes\planes\plane_crash_water_2",db3,1,500};
        soundWaterCrashes[] =
        {
            soundWaterCollision1,1/2,
            soundWaterCollision2,1/2
        };
        buildCrash0[] = {"\A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",db0,1,900};
        buildCrash1[] = {"\A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",db0,1,900};
        buildCrash2[] = {"\A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",db0,1,900};
        buildCrash3[] = {"\A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",db0,1,900};
        soundBuildingCrash[] =
        {
            buildCrash0,1/4,
            buildCrash1,1/4,
            buildCrash2,1/4,
            buildCrash3,1/4
        };
        WoodCrash0[] = {"\A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1",db10,1,900};
        WoodCrash1[] = {"\A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_2",db10,1,900};
        WoodCrash2[] = {"\A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_6",db10,1,900};
        WoodCrash3[] = {"\A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_8",db10,1,900};
        soundWoodCrash[] =
        {
            woodCrash0,1/4,
            woodCrash1,1/4,
            woodCrash2,1/4,
            woodCrash3,1/4
        };
        armorCrash0[] = {"\A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",db0,1,900};
        armorCrash1[] = {"\A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",db0,1,900};
        armorCrash2[] = {"\A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",db0,1,900};
        armorCrash3[] = {"\A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",db0,1,900};
        soundArmorCrash[] =
        {
            ArmorCrash0,1/4,
            ArmorCrash1,1/4,
            ArmorCrash2,1/4,
            ArmorCrash3,1/4
        };
        Crash0[] = {"\A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",db0,1,900};
        Crash1[] = {"\A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",db0,1,900};
        Crash2[] = {"\A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",db0,1,900};
        Crash3[] = {"\A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",db0,1,900};
        soundCrashes[] =
        {
            Crash0,1/4,
            Crash1,1/4,
            Crash2,1/4,
            Crash3,1/4
        };
        soundDammage[] = {"",0.562341,1};
        soundEngineOnInt[] = {"\ADF_Air\adfrc_f35\Sounds\B_Plane_Fighter_05_engine_start_int",db0,1};
        soundEngineOnExt[] = {"\ADF_Air\adfrc_f35\Sounds\B_Plane_Fighter_05_engine_start_ext",1.75,1,300};
        soundEngineOffInt[] = {"\ADF_Air\adfrc_f35\Sounds\B_Plane_Fighter_05_engine_shut_int",db0,1};
        soundEngineOffExt[] = {"\ADF_Air\adfrc_f35\Sounds\B_Plane_Fighter_05_engine_shut_ext",1.75,1,300};
        soundLocked[] = {"\A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_lockedOn1",db0,1};
        soundIncommingMissile[] = {"\A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_lockedon2",db0,1.5};
        soundGearUp[] = {"\A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_gear_up",2.25,1,250};
        soundGearDown[] = {"\A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_gear_down",2.25,1,250};
        soundFlapsUp[] = {"\A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_Flaps_Up",1.5,1,150};
        soundFlapsDown[] = {"\A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_Flaps_Down",1.5,1,150};
        soundSetSonicBoom[] = {Plane_Fighter_SonicBoom_SoundSet};
        class Sounds
        {
            soundSets[] =
            {
                ADFRC_F35_EngineLowExt_SoundSet,
                ADFRC_F35_EngineHighExt_SoundSet,
                ADFRC_F35_ForsageExt_SoundSet,
                ADFRC_F35_WindNoiseExt_SoundSet,
                ADFRC_F35_EngineExt_Dist_Front_SoundSet,
                ADFRC_F35_EngineExt_Middle_SoundSet,
                ADFRC_F35_EngineExt_Dist_Rear_SoundSet,
                ADFRC_F35_EngineLowInt_SoundSet,
                ADFRC_F35_EngineHighInt_SoundSet,
                ADFRC_F35_ForsageInt_SoundSet,
                ADFRC_F35_WindNoiseInt_SoundSet,
                ADFRC_F35_VelocityInt_SoundSet,
                Plane_Fighter_RainExt_SoundSet,
                Plane_Fighter_RainInt_SoundSet,
                Plane_Fighter_GStress_SoundSet,
                Plane_Fighter_SpeedStress_SoundSet/*,
                Plane_Fighter_GBreathing_SoundSet*/
            };
        };
        class RainExt
        {
            sound[] = {"\A3\Sounds_F\vehicles\noises\rain1_ext",db5,1,100};
            frequency = 1;
            volume = camPos*rain*(speed factor[50,0]);
        };
        class RainInt
        {
            sound[] = {"\A3\Sounds_F\vehicles\noises\rain1_int",db0,1,100};
            frequency = 1;
            volume = (1-camPos)*rain*(speed factor[50,0]);
        };
        class GStress
        {
            sound[] = {"\A3\Sounds_F\vehicles\noises\vehicle_stress2e",db4,1,50};
            frequency = 1;
            volume = engineOn * (1-camPos) * (gmeterZ factor[1, 2.5]);
        };
        class SpeedStress
        {
            sound[] = {"\A3\Sounds_F\vehicles\noises\vehicle_stress3",db-6,1,50};
            frequency = 1;
            volume = (1-camPos)*(speed factor[60,80]);
        };
        /*
        class GBreathing
        {
            sound[] = {"\A3\Sounds_F\characters\human-sfx\diver-breath-4",db-5,1,50};
            frequency = 1;
            volume = engineOn * (1-camPos) * (gmeterZ factor[1, 2.5]);
        };
        */
    
