@echo off
set folder=%1
set /p dateInput="Starsze od jakiej daty?(format dd/mm/yyyy): "
forfiles /p %folder% /m *.txt /c "cmd /c copy @path '.\path_copy\@file'" /d -%dateInput%