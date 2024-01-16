@echo off
set /p ile="Ile liczb wypisac? " 
set /p gdzie="Gdzie zapisac? "
for /L %%x in (0,1,%ile%) do (echo %%x>>%gdzie%) 
