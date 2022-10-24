@REM # -------------------- #
@REM # (C)2022 madoodia.com #
@REM # -------------------- #


@ECHO OFF

SET ROOT=%1
SET FOLDER=%2
SET FILE=%3

call "%VCVARS_LOCATION%/vcvarsall.bat" x64

call %ROOT%/envVars.bat

if exist "%ROOT%/%FOLDER%/build" (
    rmdir /s /q "%ROOT%/%FOLDER%/build"
)

CD %ROOT%/%FOLDER%
MKDIR build
CD build

cmake -G "NMake Makefiles" ..
@REM cmake -G "Visual Studio 16 2019" ../
cmake --build . --config Debug

if not exist "%ROOT%/%FOLDER%/bin/glew32.dll" (
	xcopy /y "%ROOT%\dlls\glew32.dll" "%ROOT%\%FOLDER%\bin\"
)

CALL %ROOT%/%FOLDER%/bin/LearningOpenGL.exe