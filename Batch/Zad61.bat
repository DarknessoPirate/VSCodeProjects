@echo off
setlocal EnableDelayedExpansion
set /p l1="Lokalizacja pliku 1: "
set /p l2="Lokalizacja pliku 2: "
set string=
for /f "tokens=* delims=" %%x in (%l1%) do (
    set string=!string!%%x
)
for /f "tokens=* delims=" %%x in (%l2%) do (
    set string=!string!%%x
)
echo %string%
endlocal
