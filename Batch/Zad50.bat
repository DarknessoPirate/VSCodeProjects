@echo off
if %1=="/a" goto :first
if %1=="/h" goto :help

del "%userprofile%\MenuStart\Programy\Autostart\*.*" /p /first
reg delete HKCU\Software\Microsoft\Windows\CurrentVersion\Run /va
goto:eof

:first
del "%userprofile%\MenuStart\Programy\Autostart\*.*" /p /first
reg delete HKCU\Software\Microsoft\Windows\CurrentVersion\Run /va /f 
goto:eof

:help
echo Program służy do usunięcia wpisów z podmenu Autostart menu MenuStart
echo usuwa także wpisy w rejestrach odpiowiedzialne za automatyczne wlaczanie
echo programow przy starcie komputera
echo /a - program nie pyta o potwierdzenie przed usunieciem
echo /h - wyswietl pomoc