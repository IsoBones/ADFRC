// grad_trenches addition, only matters when that mod is loaded
class CfgDigVehicles
{
    class adfrc_abrams
    {
        type = "animate";              // 'plow' is a door anim, 'animate' command works on doors
        animation = "plow";            // matches the AnimationSource 'plow' (source="door")
        selection = "plow";            // for the digging particle FX position
        plowRaised = 0;
        plowLowered = 1;               // door anim goes 0->1 (rad 20 in model.cfg)
        distanceToTrench = 4.5;        // tune this - distance forward from vehicle origin to trench
    };
    class adfrc_m1a1aim_md:    adfrc_abrams {};
    class adfrc_m1a1aim_gwot:  adfrc_abrams {};
    class adfrc_m1a2sepv3_md:  adfrc_abrams {};
};