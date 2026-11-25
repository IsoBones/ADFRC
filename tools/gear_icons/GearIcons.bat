@echo off
rem ADFRC gear icon tool launcher.
rem   Double-click (no arguments): opens the Gear Icon Maker window.
rem   GearIcons.bat <step> [options]: command line. Steps: select, export, render, fit, apply, all, tools (see README.md)
rem Build folder (command line): %%ADFRC_ROOT%% if set, else P:\ if it exists, else the current folder.
if "%~1"=="" (
  start "" powershell -NoProfile -ExecutionPolicy Bypass -STA -WindowStyle Hidden -File "%~dp0GearIcons.ps1"
  exit /b 0
)
setlocal
set "PY=py -3"
where py >nul 2>nul || set "PY=python"
%PY% -c "import numpy, PIL" 2>nul || (
  echo Installing numpy + Pillow for this Python...
  %PY% -m pip install --user -r "%~dp0requirements.txt" || exit /b 1
)
set "ROOT=%ADFRC_ROOT%"
if "%ROOT%"=="" if exist P:\ set "ROOT=P:\"
if "%ROOT%"=="" set "ROOT=%CD%"
if "%ROOT:~-1%"=="\" set "ROOT=%ROOT%."
%PY% "%~dp0gear_icons.py" --root "%ROOT%" %*
