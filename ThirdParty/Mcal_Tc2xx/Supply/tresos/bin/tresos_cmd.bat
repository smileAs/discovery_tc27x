@ECHO OFF
REM Startup tresos ECU in commandline mode

IF "%os%"=="Windows_NT" goto START
IF "%OS%"=="Windows_NT" goto START
IF "%os%"=="WINDOWS_NT" goto START
IF "%OS%"=="WINDOWS_NT" goto START
IF "%os%"=="Windows" goto START
IF "%OS%"=="Windows" goto START
IF "%os%"=="WINDOWS" goto START
IF "%OS%"=="WINDOWS" goto START

goto NOWINDOWS

:NOJAVA
ECHO ERROR: java not found: %JAVA%
EXIT /B 1
GOTO END

:NOWINDOWS
ECHO ERROR: tresos only runs on Windows2000 and Windows/XP
EXIT 1
GOTO END

:END0
IF DEFINED MAKELEVEL EXIT 0
EXIT /B 0

:END1
IF DEFINED MAKELEVEL EXIT 1
EXIT /B 1

:START


REM TRESOS_BASE
SET TRESOS_BASE=%~dp0
SET BINDIR=%TRESOS_BASE:~-5%
IF NOT "%BINDIR%"=="\bin\" (
  ECHO ERROR: this program must be located in the "bin" directory!
  EXIT /B 1
)
SET TRESOS_BASE=%TRESOS_BASE:~0,-5%

REM JAVA
SET JAVACMD=java.exe
SET JAVA_HOME=%TRESOS_BASE%\jre
SET JAVA=%JAVA_HOME%\bin\%JAVACMD%

REM PATH
IF DEFINED SAVED_PATH PATH=%SAVED_PATH%
SET SAVED_PATH=%PATH%

REM COMMANDLINE
SET CLASSPATH="%TRESOS_BASE%\plugins\org.eclipse.equinox.launcher_1.3.0.v20120522-1813.jar"
SET APPLICATION=dreisoft.tresos.application.launcher2.plugin.ApplicationTresosCmd
SET VMARGS=-Xmx1024M -Xms256M -XX:MaxPermSize=192M -server -Dbase.path="%TRESOS_BASE%"
SET ARGS=-nl en -install "%TRESOS_BASE%"\
SET LAUNCHER=org.eclipse.equinox.launcher.Main
SET CMD="%JAVA%" %VMARGS% -classpath %CLASSPATH% %LAUNCHER% -application %APPLICATION% %ARGS% %*

REM Run java
IF NOT EXIST %JAVA% GOTO NOJAVA
%CMD%

IF %ERRORLEVEL%==0 goto END0
IF %ERRORLEVEL%==1 goto END1

echo Unexpected error-code: %ERRORLEVEL%
