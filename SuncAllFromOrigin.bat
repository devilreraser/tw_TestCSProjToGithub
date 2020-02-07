@echo off
rem start "" cmd /c "echo Hello world!&echo(&pause"
echo.
echo Process Submodules:
echo.
echo TestCSSubmoduleToGithub:
echo.
cd 02_Libraries\TestCSSubmoduleToGithub
git fetch --all
git pull
cd ..\..
echo.
echo Process Project:
echo.
git fetch --all
git pull
echo.
echo Completed!
echo Press Enter to Exit
pause >nul
exit