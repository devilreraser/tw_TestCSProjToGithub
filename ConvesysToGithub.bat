@echo off
echo Process Submodules:
cd 02_Libraries\TestCSSubmoduleToGithub
git.exe fetch --all -v --progress
git.exe pull --progress -v --no-rebase "origin"
git.exe merge --allow-unrelated-histories --strategy=recursive --strategy-option=theirs remotes/convesys/master
git.exe push --progress "origin" master:master
cd ..\..
echo Process Project:
git.exe fetch --all -v --progress
git.exe pull --progress -v --no-rebase "origin"
git.exe merge --allow-unrelated-histories --strategy=recursive --strategy-option=theirs remotes/convesys/master
git.exe push --progress "origin" master:master
echo Completed!
echo Press Enter to Exit
pause >nul
exit