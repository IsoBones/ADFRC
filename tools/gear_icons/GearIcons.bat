@echo off
rem ADFRC gear icon tool launcher. Usage: GearIcons.bat <step> [options]
rem   steps: select, export, render, fit, apply, all   (see README.md)
rem Build folder: %%ADFRC_ROOT%% if set, else P:\ if it exists, else the current folder.
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
if "%~1"=="" (
  %PY% "%~dp0gear_icons.py" -h
  exit /b 0
)
%PY% "%~dp0gear_icons.py" --root "%ROOT%" %*
