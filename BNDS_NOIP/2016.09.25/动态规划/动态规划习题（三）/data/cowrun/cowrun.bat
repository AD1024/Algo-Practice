@echo off
if "%1"=="" goto loop
copy cowrun%1.in cowrun.in >nul
echo Problem Test
echo Data %1
time<enter
cowrun
time<enter
fc cowrun.out cowrun%1.out
del cowrun.in
del cowrun.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
