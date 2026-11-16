@echo off
setlocal

set MSYS2_BIN=C:\msys64\ucrt64\bin;C:\msys64\mingw64\bin;C:\msys64\usr\bin;%PATH%
set PATH=%MSYS2_BIN%

cd /d "%~dp0"
set LOGFILE=%~dp0build.log

echo ====================================================== > "%LOGFILE%" 2>&1
echo HARPU Verilator Build Diagnostic Log >> "%LOGFILE%" 2>&1
echo Date/Time: %DATE% %TIME% >> "%LOGFILE%" 2>&1
echo Working Dir: %CD% >> "%LOGFILE%" 2>&1
echo ====================================================== >> "%LOGFILE%" 2>&1

echo --- Executing Build --- >> "%LOGFILE%" 2>&1
mingw32-make.exe -f Makefile all >> "%LOGFILE%" 2>&1
set BUILD_STATUS=%ERRORLEVEL%
if %BUILD_STATUS% neq 0 (
    make.exe -f Makefile all >> "%LOGFILE%" 2>&1
    set BUILD_STATUS=%ERRORLEVEL%
)

echo --- Build Finished with Code: %BUILD_STATUS% --- >> "%LOGFILE%" 2>&1

if %BUILD_STATUS% neq 0 goto :BUILD_FAIL

echo ======================================================
echo Build Succeeded! Launching Simulator...
echo Controls: WASD/QE: Move, RF: Radius, Space: Carve, ESC: Exit
echo ======================================================

if exist "C:\msys64\ucrt64\bin\SDL2.dll" copy /y "C:\msys64\ucrt64\bin\SDL2.dll" ".\obj_dir\" >nul 2>&1
if exist "C:\msys64\mingw64\bin\SDL2.dll" copy /y "C:\msys64\mingw64\bin\SDL2.dll" ".\obj_dir\" >nul 2>&1
if exist "C:\msys64\ucrt64\bin\libwinpthread-1.dll" copy /y "C:\msys64\ucrt64\bin\libwinpthread-1.dll" ".\obj_dir\" >nul 2>&1
if exist "C:\msys64\ucrt64\bin\libgcc_s_seh-1.dll" copy /y "C:\msys64\ucrt64\bin\libgcc_s_seh-1.dll" ".\obj_dir\" >nul 2>&1

.\obj_dir\Vsim_top.exe
echo.
echo Simulator closed.
pause
exit /b 0

:BUILD_FAIL
echo ======================================================
echo BUILD FAILED. Check build.log:
echo ======================================================
type "%LOGFILE%"
pause
exit /b 1
