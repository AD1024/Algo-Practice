@echo off
if "%1"=="" goto loop
copy zbrka%1.in zbrka.in >nul
echo Problem Test
echo Data %1
time<enter
zbrka.exe
time<enter
fc zbrka.out zbrka%1.out
del zbrka.in
del zbrka.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12) do call %0 %%i
:end
