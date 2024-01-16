 @echo off
 ren %1\*.txt *.jpg
if %2=="" goto:eof
if %2=="c" goto copy

:copy
set /p path="Podaj katalog z ktorego skopiowac pliki: "
set /p kiedy="Starsze od jakiej daty? " 
forfiles /p %1 /m *.jpg /c "cmd /c copy @path %path%\@file" /d-%kiedy%
