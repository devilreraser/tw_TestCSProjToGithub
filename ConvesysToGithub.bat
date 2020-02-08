@echo off
echo Process Submodules:
cd 02_Libraries\TestCSSubmoduleToGithub
git.exe fetch --all -v --progress
git.exe pull --progress -v --no-rebase "origin"
git.exe merge --no-ff --allow-unrelated-histories remotes/convesys/master < ConvesysToGithub.in
rem git.exe merge --no-ff --no-commit --allow-unrelated-histories remotes/convesys/master < ConvesysToGithub.in
rem git reset HEAD gitmodules
rem git checkout -- gitmodules
rem git commit -m "merged Convesys"
git.exe push --progress "origin" master:master
cd ..\..
echo Process Project:
git.exe fetch --all -v --progress
git.exe pull --progress -v --no-rebase "origin"
git.exe merge --no-ff --no-commit --allow-unrelated-histories remotes/convesys/master < ConvesysToGithub.in
git reset HEAD gitmodules
git checkout -- gitmodules
git commit -m "merged Convesys"
git.exe push --progress "origin" master:master
echo Completed!
echo Press Enter to Exit
pause >nul
exit