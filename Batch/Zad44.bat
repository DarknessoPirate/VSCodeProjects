 @echo off
 set /p type="Podaj typ pliku ktory chcesz usunac: "
 if exist *.%type% (
    goto usun
    ) else (goto brakpliku)

:usun
del *.%type%
goto end

:brakpliku
echo "plik o podanym rozszerzeniu nie zostal znaleziony"

:end
pause