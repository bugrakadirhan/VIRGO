@ECHO OFF
CALL FINISH.BAT
SET T=%TIME:~0,2%
SET T=%T%:%TIME:~3,2%
SET T=%T%:%TIME:~6,2%
SET T=%T: =0%
ECHO Shutted the computer down at %T% >> finishes/FAREWELL.LOG
SHUTDOWN -s -f -t 20 -c "Goodnight..."