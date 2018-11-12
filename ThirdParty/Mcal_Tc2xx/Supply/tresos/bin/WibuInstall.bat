@ECHO OFF


SET BASE_PATH=%~dp0
SET BASE_PATH=%BASE_PATH:\bin\=%
SET BASE_PATH=%BASE_PATH: =" "%

CD %BASE_PATH%\configuration\WibuKey

REN setup.ini setup_auto.ini
REN setup_gui.ini setup.ini
setup32
REN setup.ini setup_gui.ini
REN setup_auto.ini setup.ini
EXIT /B 0
