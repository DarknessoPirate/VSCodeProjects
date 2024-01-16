@echo off
set /p slowo="Podaj co zamienic: "
set /p zamiana="Podaj na co zamienic: "
setlocal EnableDelayedExpansion
for /f "tokens=* delims=" %%x in (%1) do (
    set string=%%x
    echo !string:%slowo%=%zamiana%!>>%2
)
endlocal
