@echo off
setlocal EnableDelayedExpansion
for %%f in (".\*.txt") do (
    for /f "tokens=* delims=" %%a in (%%f) do (
        set "line=%%a"
        set "line=!line:"=@!"
        echo !line!>"%%f"
    )
)
endlocal    
