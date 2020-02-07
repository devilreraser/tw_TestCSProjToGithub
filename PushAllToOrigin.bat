@echo off
echo.
SET /P _CommitString= Please enter Commit Message:
IF [%_CommitString%]==[] SET _CommitString=Empty Message
echo Commit Message: "%_CommitString%"
echo.
echo Process Submodules:
echo.
echo TestCSSubmoduleToGithub:
echo.
cd 02_Libraries\TestCSSubmoduleToGithub
git commit --all -m "%_CommitString%"
git push --progress "origin" master:master
cd ..\..
echo.
echo Process Project:
echo.
git commit -a -m "%_CommitString%"
git push --progress "origin" master:master
echo.
echo Completed!
echo Press Enter to Exit
pause >nul
exit