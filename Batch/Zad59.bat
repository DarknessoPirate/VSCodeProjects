 @echo off
 setlocal EnableDelayedExpansion
for /f "tokens=* delims=" %%i in (%1) do (
    set str=%%i
    echo !str:kot=!
)
 endlocal
