@echo off
rem start "" cmd /c "echo Hello world!&echo(&pause"
echo.
echo Process Submodules:
echo.
echo TestCSSubmoduleToGithub:
echo.
cd 02_Libraries\TestCSSubmoduleToGithub
git.exe fetch -v --progress "origin"
git.exe pull --progress -v --no-rebase "origin"
cd ..\..
echo.
echo Process Project:
echo.
git.exe fetch -v --progress "origin"
git.exe pull --progress -v --no-rebase "origin"
echo.
echo Completed!
echo Press Enter to Exit
pause >nul
exit