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
"%PROGRAMFILES%\i686-elf-tools-windows\bin\i686-elf-gcc.exe" -ffreestanding -m32 -c "kernel\init.c" -o "%INTERMEDIATE%\init.o"
"%PROGRAMFILES%\i686-elf-tools-windows\bin\i686-elf-gcc.exe" -ffreestanding -m32 -c "kernel\print.c" -o "%INTERMEDIATE%\print.o"
"%PROGRAMFILES%\i686-elf-tools-windows\bin\i686-elf-gcc.exe" -ffreestanding -m32 -c "kernel\sleep.c" -o "%INTERMEDIATE%\sleep.o"
"%PROGRAMFILES%\i686-elf-tools-windows\bin\i686-elf-gcc.exe" -ffreestanding -m32 -c "kernel\random.c" -o "%INTERMEDIATE%\random.o"
"%PROGRAMFILES%\i686-elf-tools-windows\bin\i686-elf-gcc.exe" -ffreestanding -m32 -c "kernel\kernel.c" -o "%INTERMEDIATE%\kernel.o"

:: Link compiled kernel as kernel.elf
"%PROGRAMFILES%\i686-elf-tools-windows\bin\i686-elf-ld.exe" -T "boot\linker.ld" -o "%INTERMEDIATE%\kernel.elf" "%INTERMEDIATE%\init.o" "%INTERMEDIATE%\print.o" "%INTERMEDIATE%\sleep.o" "%INTERMEDIATE%\random.o" "%INTERMEDIATE%\kernel.o"

:: Convert kernel.elf into binary
"%PROGRAMFILES%\i686-elf-tools-windows\bin\i686-elf-objcopy.exe" -O binary "%INTERMEDIATE%\kernel.elf" "%BUILD%\kernel.bin"

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
