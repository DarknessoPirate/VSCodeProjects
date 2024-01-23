@echo off
set folder=%1
set /p dateInput="Starsze od jakiej daty?(format dd/mm/yyyy): "
forfiles /p %1 /m *.txt /c "cmd /c copy @file .\kopia" /d -%dateInput%