/*
    adfrc_lcm_fnc_tieDown

    Ties a vehicle to the LCM using attachTo + simulation freeze.

    The vehicle is attached to the boat at its current relative position, then
    its simulation is disabled globally. attachTo parents the vehicle to the
    boat's frame so it rides along natively (no per-frame catch-up, no
    choppiness). enableSimulationGlobal false freezes physics/anim but leaves
    crew seated - troops stay boarded, they just can't operate the vehicle
    until released.

    Server-authoritative: attachTo and enableSimulationGlobal must run on the
    server to replicate to all machines. The attachment and freeze persist
    across ownership changes (driver leaving, swapping, disconnecting) on their
    own,so no enforcement loop needed.

    Params:
        0: BOAT    <OBJECT>
        1: VEHICLE <OBJECT>

    Returns: nothing
*/
params ["_boat", "_vehicle"];

if (!isServer) exitWith {
    [_boat, _vehicle] remoteExec ["adfrc_lcm_fnc_tieDown", 2];
};

if (isNull _boat || isNull _vehicle) exitWith {};
if (_vehicle getVariable ["adfrc_tiedDown", false]) exitWith {};

// range sanity check
private _maxDist = missionNamespace getVariable ["ADFRC_lcm_tieRange", 12];
if (_vehicle distance _boat > _maxDist) exitWith {};

// capture current position + orientation relative to the boat (model space)
private _relPos = _boat worldToModel (getPosWorld _vehicle);
private _vDir   = _boat vectorWorldToModel (vectorDir _vehicle);
private _vUp    = _boat vectorWorldToModel (vectorUp _vehicle);

_vehicle setVariable ["adfrc_tieBoat", _boat, true];
_vehicle setVariable ["adfrc_tiedDown", true, true];

// attach at the captured offset
_vehicle attachTo [_boat, _relPos];

// attachTo resets orientation to boat-relative default; restore the parked
// heading. For an ATTACHED object, setVectorDirAndUp takes vectors in the
// PARENT's model space - so feed the captured model-space vectors directly
// (do NOT transform back to world).
_vehicle setVectorDirAndUp [_vDir, _vUp];

// freeze physics/animation; crew remain seated
_vehicle enableSimulationGlobal false;
