@echo off
echo path globalne: %path% 
Setlocal
set path = "C:\"
echo path lokalne po zmianie: %path%
Endlocal
echo znowu path globalne: %path%
pause