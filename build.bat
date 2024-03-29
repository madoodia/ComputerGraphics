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

@REM replacing \ character with / character in all inputs
set ROOT=%ROOT:\=/%
set FOLDER=%FOLDER:\=/%
set FILENAME=%FILENAME:\=/%
set BASENAME=%BASENAME:\=/%
set FILEDIRNAME=%FILEDIRNAME:\=/%

@REM tokenize string to get the parent folder containing cmakefile
set nth=1
for /F "tokens=1 delims=/" %%a in ("%BASENAME%") do set CMAKEFOLDER=%%a

@REM setup VS developer mode
call "%VCVARS_LOCATION%/vcvarsall.bat" x64

call %ROOT%/envVars.bat

@REM remove build folder before building the project
if exist "%FILEDIRNAME%/build" (
    rmdir /s /q "%FILEDIRNAME%/build"
    rmdir /s /q "%FILEDIRNAME%/bin"
)

CD %FILEDIRNAME%
MKDIR build
CD build

cmake -G "NMake Makefiles" "%ROOT%/%CMAKEFOLDER%"
@REM cmake -G "Visual Studio 16 2019" ../
cmake --build . --config Debug

if not exist "%ROOT%/%CMAKEFOLDER%/bin/glew32.dll" (
	xcopy /y "%ROOT%\dlls\glew32.dll" "%ROOT%/%BASENAME%\bin\"
)

@REM delete extra files in bin folder for release mode
@REM CD %ROOT%/%CMAKEFOLDER%/bin
@REM del *.ilk && del *.pdb

@REM CALL %ROOT%/%CMAKEFOLDER%/bin/%PROJECT_NAME%.exe