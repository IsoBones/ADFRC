/*
    adfrc_aslav_fnc_cameraOpticUI

    Drives the ASLAV-S camera operator optic HUD
    (RscInGameUI >> adfrc_RscOptics_ASLAV_S_camera).

    Two callers:
      - display onLoad (DISPLAY): registers a per-frame handler that hides the
        3D icon whenever the operator isn't looking through the optic. The
        hidden map's onDraw stops firing outside the optic, so the hide can't
        live there (same reason the vanilla UGV_02 script uses a per-frame handler).
      - hidden map onDraw (CONTROL): feeds mast height and camera pitch into the
        3D icon and updates the MAST HGT readout.

    Params:
        0: display (onLoad) or map control (onDraw) <DISPLAY/CONTROL>

    Returns: nothing
*/
params ["_target"];

// lens height above the ground at the wheels with the mast stowed (from adfrc_aslav_pc.p3d)
#define CAM_BASE_HEIGHT 3.2
// full mast deploy and camera operator fine elevation (metres, matches model.cfg)
#define MAST_DEPLOY_TRAVEL 10.5
#define MAST_ELEV_TRAVEL 0.5

if (_target isEqualType displayNull) exitWith {
    private _icon = _target displayCtrl 411;
    _icon ctrlShow false;
    uiNamespace setVariable ["adfrc_aslav_cameraOpticIcon", _icon];

    if (isNil {missionNamespace getVariable "adfrc_aslav_cameraOpticEH"}) then {
        adfrc_aslav_cameraOpticEH = addMissionEventHandler ["EachFrame", {
            private _shape = uiNamespace getVariable ["adfrc_aslav_cameraOpticIcon", controlNull];
            if (isNull _shape) exitWith {
                removeMissionEventHandler ["EachFrame", _thisEventHandler];
                adfrc_aslav_cameraOpticEH = nil;
            };
            _shape ctrlShow (cameraView isEqualTo "GUNNER");
        }];
    };
};

private _display = ctrlParent _target;
private _vehicle = cameraOn;
private _icon = _display displayCtrl 411;

private _deploy = _vehicle animationSourcePhase "cameraelevation_deployed";
private _elev = _vehicle animationSourcePhase "cameraelevation";

private _height = CAM_BASE_HEIGHT + (_deploy * MAST_DEPLOY_TRAVEL) + (_elev * MAST_ELEV_TRAVEL);
(_display displayCtrl 5001) ctrlSetText format ["%1 m", _height toFixed 1];

_icon ctrlAnimateModel ["deploy", _deploy];
_icon ctrlAnimateModel ["elev", _elev];
_icon ctrlAnimateModel ["gun", _vehicle animationSourcePhase "cameragun"];
