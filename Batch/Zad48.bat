@echo off
for %%x in (C: D: F:) do(
    cd %%x
    dir %1 /s /b
)
