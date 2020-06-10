@echo off
set RemoteString=github
set RemotePath=https://github.com/devilreraser/
set ProjectName=tw_TestCSProjToGithub.git
set Module1Name=tw_TestCSSubmoduleToGithub.git
set Module1Path=02_Libraries/TestCSSubmoduleToGithub

git remote remove %RemoteString% >nul 2>nul
if %errorlevel%==0 echo. Old Remote With Same Name Deleted!
echo. Added '%RemoteString%' path '%RemotePath%%ProjectName%'
git remote add %RemoteString% %RemotePath%%ProjectName%
cd %Module1Path%
git remote remove %RemoteString% >nul 2>nul
if %errorlevel%==0 echo. Old Remote With Same Name Deleted!
echo. Added '%RemoteString%' path '%RemotePath%%Module1Name%'
git remote add %RemoteString% %RemotePath%%Module1Name%
cd ..\..
pause