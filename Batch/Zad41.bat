@echo off
set /p dest="Gdzie zapisac liste plikow?"
dir /A:D /B > %dest%
