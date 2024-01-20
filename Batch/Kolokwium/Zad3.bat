@echo off
setlocal enabledelayedexpansion

set file=%1

set reversed=""
for /f "delims=" %%x in (%file%) do (
    set line=%%x
    set len=!line!

    set /a len-=1

    for /l %%y in (!len!,-1,0) do (
        set reversed=!reversed!!line:~%%y,1!
    )

    set reversed=!reversed!
)

echo !reversed! > %file%
endlocal