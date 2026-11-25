/*
    adfrc_arafura_fnc_rhib

    Deploy or recover one of the Arafura's two davit RHIBs (ADFRC RHIB, adfrc_rhib).
    Called from the ship's UserActions, which only show for the driver or the captain.

    The caller checks there is a boat to recover (so they get the hint), then the
    work is routed to the server: spawn / delete the boat and hide / show the stowed
    RHIB on that side (user sources rhib_p_deployed / rhib_s_deployed).

    Params:
        0: SHIP <OBJECT>
        1: SIDE <STRING>   "p" (port) | "s" (starboard)
        2: MODE <STRING>   "deploy" | "recover"
        3: SERVER SIDE <BOOL> (internal, default false)

    Returns: nothing
*/
params [["_ship", objNull, [objNull]], ["_side", "", [""]], ["_mode", "", [""]], ["_serverSide", false, [false]]];

if (isNull _ship || !(_side in ["p", "s"]) || !(_mode in ["deploy", "recover"])) exitWith {};

private _source = format ["rhib_%1_deployed", _side];
private _launchPoint = format ["rhib_launch_%1", _side];

// nearest empty RHIB within 30 m of that side's launch point
private _fnc_findBoat = {
    params ["_ship", "_launchPoint"];
    private _launch = _ship modelToWorld (_ship selectionPosition [_launchPoint, "Memory"]);
    private _boats = (nearestObjects [_launch, ["adfrc_rhib"], 30]) select {
        alive _x && {(crew _x) findIf {alive _x} == -1}
    };
    if (_boats isEqualTo []) then {objNull} else {_boats select 0}
};

if (!_serverSide) exitWith {
    if (_mode == "recover" && {isNull ([_ship, _launchPoint] call _fnc_findBoat)}) exitWith {
        hint "No empty RHIB within 30 m of the davit to recover.";
    };
    [_ship, _side, _mode, true] remoteExecCall ["adfrc_arafura_fnc_rhib", 2];
};

// ---- server
if (_mode == "deploy") exitWith {
    if (_ship animationSourcePhase _source > 0.5) exitWith {};
    private _launch = _ship modelToWorldWorld (_ship selectionPosition [_launchPoint, "Memory"]);
    private _boat = createVehicle ["adfrc_rhib", [0, 0, 0], [], 0, "CAN_COLLIDE"];
    _boat setDir (getDir _ship);
    _boat setPosASL [_launch select 0, _launch select 1, 0.4];
    _boat setVelocity (velocity _ship);
    _ship animateSource [_source, 1, true];
};

// recover
private _boat = [_ship, _launchPoint] call _fnc_findBoat;
if (isNull _boat) exitWith {};
deleteVehicle _boat;
_ship animateSource [_source, 0, true];
