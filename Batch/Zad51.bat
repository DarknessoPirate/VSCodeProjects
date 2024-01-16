 @echo off

set /p a="Podaj pierwsza liczbe: "
set /p b="Podaj druga liczbe: "
set /p op="Podaj dzialanie(+,-,*,/): "

if %op%==+ (set /A wynik=%a%+%b%)
if %op%==- (set /A wynik=%a%-%b%)
if %op%==* (set /A wynik=%a%*%b%)
if %op%==/ (set /A wynik=%a%/%b%)

echo Wynik dzialania %a% %op% %b% = %wynik%