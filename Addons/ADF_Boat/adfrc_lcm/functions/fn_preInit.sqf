/*
    adfrc_lcm_fnc_preInit

    preInit-time runtime setup for the LCM tie-down / boarding system.

    CBA settings are NOT registered here - they live in ADF_Core's
    initSettings.sqf (ADFRC_lcm_tieRange, ADFRC_lcm_boardRange), consistent
    with the rest of the mod's settings.

    With the attachTo + enableSimulationGlobal approach the attachment and
    freeze replicate and persist on their own, so there is no enforcement loop
    or ownership watchdog - this just attaches the tie/release scroll actions
    to all land vehicles.

    Params: none
    Returns: nothing
*/

// attach tie/release actions to every land vehicle (clients only need them)
if (hasInterface) then {
    ["LandVehicle", "InitPost", {
        params ["_veh"];
        [_veh] call adfrc_lcm_fnc_addVehicleActions;
    }, true, [], true] call CBA_fnc_addClassEventHandler;
};
