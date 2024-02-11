@echo off
ml64 /nologo /c /Zi /Cp /entry:asmMain %1.asm
cl /nologo /O2 /Zi /utf-8 /EHa /Fe:%1.exe c.cpp %1.obj
