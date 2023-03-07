@echo off
setlocal

rem If you don't add path for msys2 into %PATH%, enable following line.
rem set PATH=c:\msys64\usr\bin;%PATH%

rem https://stackoverflow.com/a/39776524/8810271
rem source : https://github.com/gitkraken/vscode-gitlens/issues/965

:loop
if "%~1" equ "rev-parse" goto rev_parse
shift
if not "%~1"=="" goto loop

git.exe %*
goto :eof

:rev_parse
git.exe %* | cygpath -w -f -
