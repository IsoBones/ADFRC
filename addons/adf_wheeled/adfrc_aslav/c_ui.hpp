// ASLAV-S camera operator optic HUD.
// Standalone copy of the vanilla Contact RscOptics_UGV_02_Demining_gunner (a3\ui_f_enoch), with:
//   - the UGV icon swapped for adfrc_aslav_s_ui.p3d (mast height + camera pitch)
//   - the vanilla UGV script replaced by adfrc_aslav_fnc_cameraOpticUI (no UGV arm/searchlight/sound key handling)
//   - lights and CAM1/2/3 indicators removed, BATTERY readout replaced with camera height (MAST HGT)
class CfgFunctions
{
	class adfrc_aslav
	{
		class ui
		{
			file = "ADF_Wheeled\adfrc_aslav\functions";
			class cameraOpticUI {};
			class mastLock {};
		};
	};
};

class RscText;
class RscPicture;
class RscControlsGroupNoScrollbars;
class RscMapControlEmpty;

class RscInGameUI
{
	class adfrc_RscOptics_ASLAV_S_camera
	{
		idd = 300;
		onLoad = "_this call (missionNamespace getVariable ['adfrc_aslav_fnc_cameraOpticUI', {}])";
		controls[] = {"CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroupNoScrollbars
		{
			idc = 170;
			x = "0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w = "58.5 * 		(0.01875 * SafezoneH)";
			h = "40 * 		(0.025 * SafezoneH)";
			class controls
			{
				class CA_OpticsZoom: RscText
				{
					idc = 180;
					style = 0;
					colorText[] = {0.95,0.95,0.95,1};
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					font = "PuristaMedium";
					x = "10.5 * 		(0.01875 * SafezoneH)";
					y = "12.6 * 		(0.025 * SafezoneH)";
					w = "4.8 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class ZoomText: CA_OpticsZoom
				{
					idc = 1002;
					text = "CAM MAG:       X";
					x = "4.65 * 		(0.01875 * SafezoneH)";
				};
				class CA_Elev: CA_OpticsZoom
				{
					idc = 175;
					x = "10.5 * 		(0.01875 * SafezoneH)";
					y = "13.8 * 		(0.025 * SafezoneH)";
					w = "4.8 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class ElevText: CA_Elev
				{
					idc = -1;
					text = "ELEV";
					x = "4.65 * 		(0.01875 * SafezoneH)";
				};
				class CA_MastHeight: CA_OpticsZoom
				{
					idc = 5001;
					x = "10.5 * 		(0.01875 * SafezoneH)";
					y = "15.0 * 		(0.025 * SafezoneH)";
					w = "4.8 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class MastHeightText: CA_MastHeight
				{
					idc = -1;
					text = "MAST HGT:";
					x = "4.65 * 		(0.01875 * SafezoneH)";
				};
				class CA_Distance: RscText
				{
					idc = 198;
					style = 0;
					sizeEx = "0.024*SafezoneH";
					colorText[] = {0.95,0.95,0.95,1};
					shadow = 0;
					font = "PuristaMedium";
					x = "(1+29.9-1) * 		(0.01875 * SafezoneH)";
					y = "(18.5+3) * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1.5 * 		(0.025 * SafezoneH)";
				};
				class CA_Distance2: RscText
				{
					idc = 183;
					w = 0;
					h = 0;
				};
				class DistanceText: CA_Distance
				{
					idc = 5009;
					text = "RANGE:";
					x = "(1+26.9-1) * 		(0.01875 * SafezoneH)";
				};
				class CA_VisionMode: RscText
				{
					idc = 179;
					style = 0;
					sizeEx = "0.028*SafezoneH";
					colorText[] = {0.95,0.95,0.95,1};
					shadow = 0;
					font = "PuristaMedium";
					x = "(1+29.9-1) * 		(0.01875 * SafezoneH)";
					y = "(19.5+3) * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "1.1 * 		(0.025 * SafezoneH)";
				};
				class VisionModeText: CA_VisionMode
				{
					idc = 5010;
					sizeEx = "0.028*SafezoneH";
					shadow = 0;
					text = "MODE:    ";
					x = "(1+26.9-1) * 		(0.01875 * SafezoneH)";
				};
				class CA_FOVMode: RscText
				{
					idc = 154;
					sizeEx = "0.024*SafezoneH";
					shadow = 0;
					font = "PuristaMedium";
					colorText[] = {0.95,0.95,0.95,1};
					x = "6.5 * 		(0.01875 * SafezoneH)";
					y = "10.6 * 		(0.025 * SafezoneH)";
					w = "0 * 		(0.01875 * SafezoneH)";
					h = "0 * 		(0.025 * SafezoneH)";
				};
				class CA_HorizontalCompass: RscPicture
				{
					IDC = 207;
					type = 105;
					font = "PuristaMedium";
					textSize = "0.02*SafezoneH";
					style = 1;
					color[] = {0.95,0.95,0.95,1};
					x = "(5/2+13.04) * 		(0.01875 * SafezoneH)";
					y = "3.5 * 		(0.025 * SafezoneH)";
					w = "(-5+27.18) * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
					imageHull = "a3\UI_F_Enoch\Data\IGUI\RscIngameUI\horizontalCompassHull_UGV_02.paa";
					imageTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassTurret.paa";
					imageObsTurret = "#(rgb,8,8,3)color(0,0,0,0)";
					imageGun = "#(rgb,8,8,3)color(0,0,0,0)";
				};
				class AzimuthMark: RscPicture
				{
					IDC = 1012;
					style = 1;
					text = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\AzimuthMark.paa";
					x = "26.35 * 		(0.01875 * SafezoneH)";
					y = "3.0 * 		(0.025 * SafezoneH)";
					w = "0.5 * 		(0.01875 * SafezoneH)";
					h = "0.5 * 		(0.025 * SafezoneH)";
					colorText[] = {0.95,0.95,0.95,1};
				};
				class CA_Heading: RscText
				{
					idc = 156;
					style = 2;
					sizeEx = "0.032*SafezoneH";
					shadow = 0;
					font = "PuristaMedium";
					colorText[] = {0.95,0.95,0.95,1};
					text = "015";
					x = "25.15 * 		(0.01875 * SafezoneH)";
					y = "1.75 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_Speed: RscText
				{
					idc = 188;
					style = 1;
					colorText[] = {0.95,0.95,0.95,1};
					font = "PuristaMedium";
					shadow = 0;
					text = "9999";
					x = "(51.0-8) * 		(0.01875 * SafezoneH)";
					y = "29.4 * 		(0.025 * SafezoneH)";
					w = "4 * 		(0.01875 * SafezoneH)";
					h = "2.4 * 		(0.025 * SafezoneH)";
					sizeEx = "0.078*SafezoneH";
				};
				class SpeedText: CA_Speed
				{
					idc = -1;
					text = "km/h";
					x = "(53-8) * 		(0.01875 * SafezoneH)";
					sizeEx = "0.028*SafezoneH";
				};
				class ValueTime: RscText
				{
					idc = 190;
					style = 1;
					sizeEx = "0.028*SafezoneH";
					colorText[] = {0.95,0.95,0.95,1};
					font = "PuristaMedium";
					shadow = 0;
					x = "(2+6) * 		(0.01875 * SafezoneH)";
					y = "(27.5+3.5) * 		(0.025 * SafezoneH)";
					w = "4.8 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class Text_Time: ValueTime
				{
					idc = 1030;
					sizeEx = "0.024*SafezoneH";
					style = 0;
					text = "TIME [UTC]:";
					x = "4.65 * 		(0.01875 * SafezoneH)";
				};
				class CA_Position: RscText
				{
					idc = 171;
					style = 1;
					colorText[] = {0.95,0.95,0.95,1};
					font = "PuristaMedium";
					sizeEx = "0.024*SafezoneH";
					shadow = 0;
					x = "(2+6) * 		(0.01875 * SafezoneH)";
					y = "(28.5+3.5) * 		(0.025 * SafezoneH)";
					w = "4.8 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class Text_Grid: CA_Position
				{
					idc = 1030;
					text = "GRID:";
					style = 0;
					sizeEx = "0.028*SafezoneH";
					x = "4.65 * 		(0.01875 * SafezoneH)";
				};
				class Map: RscMapControlEmpty
				{
					w = 0;
					h = 0;
					onDraw = "_this call (missionNamespace getVariable ['adfrc_aslav_fnc_cameraOpticUI', {}])";
				};
				class CA_Laser: RscText
				{
					idc = 158;
					style = "0x30 + 0x800";
					sizeEx = "0.038*SafezoneH";
					colorText[] = {0.706,0.0745,0.0196,1};
					shadow = 0;
					font = "EtelkaMonospacePro";
					text = "\A3\ui_f\data\igui\rscingameui\rscoptics\laser_designator_iconLaserOn.paa";
					x = "29.2 * 		(0.01875 * SafezoneH)";
					y = "15 * 		(0.025 * SafezoneH)";
					w = "3.5 * 		(0.01875 * SafezoneH)";
					h = "1.5 * 		(0.025 * SafezoneH)";
				};
			};
		};
		class Objects
		{
			class ASLAV_Shape
			{
				idc = 411;
				type = 82;
				model = "\ADF_Wheeled\adfrc_aslav\data\UI\adfrc_aslav_s_ui.p3d";
				scale = "0.05 * (SafeZoneW Min SafeZoneH)";
				direction[] = {0,0,1};
				up[] = {0,1,0};
				x = "(SafezoneX + ((SafezoneW - SafezoneH) / 2)) + (45) * 		(0.01875 * SafezoneH)";
				y = "(SafezoneY) + (21) * 		(0.025 * SafezoneH)";
				z = 0.303;
				xBack = 0.5;
				yBack = 0.5;
				zBack = 0;
				inBack = 0;
				enableZoom = 0;
				zoomDuration = 4.001;
				class AnimationSources
				{
					class deploy
					{
						source = "user";
						initPhase = 0;
						animPeriod = 0.01;
					};
					class elev: deploy {};
					class gun: deploy {};
				};
			};
		};
	};
};
