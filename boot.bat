:: .bat
:: OS Boot Batch Script
:: by Kyle Furey
:: Requires Windows, NASM, i686-elf-tools, and QEMU

@echo off

:: Set build and intermediate directories
set BUILD=bin\x86
set INTERMEDIATE=obj\x86

:: Create build and intermediate directories
if not exist "%BUILD%" mkdir "%BUILD%"
if not exist "%INTERMEDIATE%" mkdir "%INTERMEDIATE%"

:: Assemble boot.asm
"%APPDATA%\..\Local\bin\NASM\nasm.exe" -f bin "boot\boot.asm" -o "%BUILD%\boot.bin"

:: Compile kernel.c and other scripts
set COMPILE="%PROGRAMFILES%\i686-elf-tools-windows\bin\i686-elf-gcc.exe" -ffreestanding -m32
%COMPILE% -c "kernel\kernel.c" -o "%INTERMEDIATE%\kernel.o"
%COMPILE% -c "kernel\string.c" -o "%INTERMEDIATE%\string.o"
%COMPILE% -c "kernel\lib.c" -o "%INTERMEDIATE%\lib.o"
%COMPILE% -c "kernel\init.c" -o "%INTERMEDIATE%\init.o"
%COMPILE% -c "kernel\print.c" -o "%INTERMEDIATE%\print.o"
%COMPILE% -c "kernel\read.c" -o "%INTERMEDIATE%\read.o"
%COMPILE% -c "kernel\file.c" -o "%INTERMEDIATE%\file.o"
%COMPILE% -c "kernel\malloc.c" -o "%INTERMEDIATE%\malloc.o"
%COMPILE% -c "kernel\sleep.c" -o "%INTERMEDIATE%\sleep.o"
%COMPILE% -c "kernel\rand.c" -o "%INTERMEDIATE%\rand.o"
%COMPILE% -c "kernel\beep.c" -o "%INTERMEDIATE%\beep.o"
%COMPILE% -c "kernel\socket.c" -o "%INTERMEDIATE%\socket.o"

:: Link compiled kernel with linker.ld
"%PROGRAMFILES%\i686-elf-tools-windows\bin\i686-elf-ld.exe" -T "boot\linker.ld" -o "%BUILD%\kernel.bin"^
	"%INTERMEDIATE%\kernel.o"^
	"%INTERMEDIATE%\string.o"^
	"%INTERMEDIATE%\lib.o"^
	"%INTERMEDIATE%\init.o"^
	"%INTERMEDIATE%\print.o"^
	"%INTERMEDIATE%\read.o"^
	"%INTERMEDIATE%\file.o"^
	"%INTERMEDIATE%\malloc.o"^
	"%INTERMEDIATE%\sleep.o"^
	"%INTERMEDIATE%\rand.o"^
	"%INTERMEDIATE%\beep.o"^
	"%INTERMEDIATE%\socket.o"

:: Log the size of boot and kernel binaries
echo.
echo -----------------------------------------------------------------
echo Boot Size (MUST EQUAL 512)
echo -----------------------------------------------------------------
echo.
dir "%BUILD%\boot.bin"
echo.
echo -----------------------------------------------------------------
echo Kernel Size
echo -----------------------------------------------------------------
echo.
dir "%BUILD%\kernel.bin"
echo.
echo -----------------------------------------------------------------
echo Divide by 512 and round up. That is the number of sectors loaded.
echo -----------------------------------------------------------------
echo.

:: Append kernel.bin into boot.bin
type "%BUILD%\boot.bin" "%BUILD%\kernel.bin" > "%BUILD%\hlos.img"

:: Boot hlos.img in QEMU
"%PROGRAMFILES%\qemu\qemu-system-i386.exe" -fda "%BUILD%\hlos.img" -drive file="%BUILD%\hlos.img",format=raw
