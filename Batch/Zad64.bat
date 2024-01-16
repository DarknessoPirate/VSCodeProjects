@echo off
setlocal EnableDelayedExpansion
set “string=”
echo Przed zamiana:
for /f “tokens=* delims=” %%i in (%1) do (
set string=%%i
echo !string!
)
set “string=”
echo Po zamianie:
for /f “tokens=* delims=” %%i in (%1) do (
set string=%%i
echo !string:kot=pies!
)
endlocal