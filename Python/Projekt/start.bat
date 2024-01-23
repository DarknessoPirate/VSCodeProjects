@echo off
setlocal enabledelayedexpansion
:menu
cls
echo #####################################################
echo #                     MENU                          #      
echo #####################################################
echo 1. Uruchom program i utworz raport                  #
echo 2. Utworz kopie zapasowa plikow do folderu Backup   #
echo 3. Wyjscie                                          #
echo #####################################################
set /p choice=Wybierz(1 / 2 / 3): 


if %choice%==1 ( 
    goto ch1 
) else if %choice%==2 (
    goto ch2 
) else if %choice%==3 (
    goto :EOF 
) else (
    goto ch3 
    )
:ch1
echo Uruchamiam aplikacje...
python -u calendarapp.py
echo Tworze raport...
python raport.py
pause
goto menu

:ch2
if not exist Backup\ (
    mkdir Backup\
)
if exist "data.txt" (
echo Kopiuje plik data.txt...
xcopy data.txt Backup\
)
if exist "raport.html" (
echo Kopiuje plik raport.html...
xcopy raport.html Backup\
)
if not exist "data.txt" (
echo plik data.txt nie istnieje utworz go zanim sprobujesz zrobic kopie
)
if not exist "raport.html" (
echo plik raport.html nie istnieje utworz go zanim sprobujesz zrobic kopie   
)
echo Proces kopiowania zakonczony.
pause
goto menu

:ch3
echo Taka opcja nie istnieje...
echo Wracanie do menu...
pause
goto menu
