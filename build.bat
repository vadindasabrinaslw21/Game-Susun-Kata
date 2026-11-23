@echo off
g++ main.cpp -o program -lncurses -DNCURSES_STATIC
if %errorLevel% == 0 (
    echo Build berhasil
    program.exe
)
else (
    echo Build gagal
)