@REM # -------------------- #
@REM # (C)2022 madoodia.com #
@REM # -------------------- #


@ECHO OFF

SET ROOT=%1
SET FOLDER=%2
SET FILENAME=%3
SET BASENAME=%4
SET FILEDIRNAME=%5
SET PROJECT_NAME=%FILENAME%

CALL %ROOT%/build.bat %ROOT% %FOLDER% %FILENAME% %BASENAME% %FILEDIRNAME%

echo --------------------------
echo.
CALL "%FILEDIRNAME%\bin\%FILENAME%.exe"
echo.
echo --------------------------