@echo off
setlocal enabledelayedexpansion
cd /d "%~dp0"

set GEN=gen.exe
set STD=std.exe
set DATA_DIR=data
set CASES=20

if not exist "%GEN%" (echo gen.exe missing & pause & exit /b)
if not exist "%STD%" (echo std.exe missing & pause & exit /b)
if not exist "%DATA_DIR%" mkdir "%DATA_DIR%"

echo Generating %CASES% test cases...

for /l %%i in (1,1,%CASES%) do (
    set /a idx=%%i
    if !idx! leq 5 (
        set MAX_N=10 & set MAX_M=10 & set MAX_HP=100 & set MAX_ATK=50
    ) else if !idx! leq 10 (
        set MAX_N=1000 & set MAX_M=1000 & set MAX_HP=100000 & set MAX_ATK=100000
    ) else if !idx! leq 15 (
        set MAX_N=50000 & set MAX_M=50000 & set MAX_HP=100000000 & set MAX_ATK=100000000
    ) else (
        set MAX_N=200000 & set MAX_M=200000 & set MAX_HP=1000000000 & set MAX_ATK=1000000000
    )
    set /a SEED=!idx! %% 1000000
    if !idx! lss 10 (set NUM=0!idx!) else (set NUM=!idx!)

    echo [%%i/%CASES%] Creating data\!NUM!.in
    "%GEN%" !MAX_N! !MAX_M! !MAX_HP! !MAX_ATK! !SEED! > "%DATA_DIR%\!NUM!.in"
    "%STD%" < "%DATA_DIR%\!NUM!.in" > "%DATA_DIR%\!NUM!.out"
)
echo Done.
pause