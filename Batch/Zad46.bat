@echo off
set /p ile="Ile liczb zapisac? "
set /p gdzie="Do ktorego pliku zapisac? "
for /L %%x in (1,1,%ile%) do (echo %%x >> %gdzie%)
