@echo off
setlocal EnableDelayedExpansion
for /f "tokens=* delims=" %%a in (%1) do (
    set string=%%a
    echo !string:"=!
)
endlocal