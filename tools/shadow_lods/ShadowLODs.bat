@echo off
rem One-click launcher for the Shadow LOD Maker window.
start "" powershell -NoProfile -ExecutionPolicy Bypass -STA -WindowStyle Hidden -File "%~dp0ShadowLODs.ps1"
