@echo off
:menu
cls
echo ------------------
echo ------ Menu ------
echo --- 1. Opcja 1 --- 
echo --- 2. Opcja 2 --- 
echo --- 3. Opcja 3 --- 
echo --- 4. Wyjscie --- 
echo ------------------
set /p wybor="Wybierz opcje: "
if %wybor%==1 goto opcja1
if %wybor%==2 goto opcja2
if %wybor%==3 goto opcja3
if %wybor%==4 goto exit

:opcja1
echo wybrano opcje 1
pause
goto menu

:opcja2
echo wybrano opcje 2
pause
goto menu

:opcja3
echo wybrano opcje 3
pause
goto menu

:exit
echo wychodzenie z programu
pause


