@echo off
set/p hex=:"Podaj liczbe w systemie szesnastkowym: "
set /a dec=0x%hex%
echo liczba w systemie dziesietnym wynosi: %dec% 
