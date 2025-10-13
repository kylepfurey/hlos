@echo off
if not exist "bin\x86" mkdir "bin\x86"
"%APPDATA%\..\Local\bin\NASM\nasm.exe" -f bin "boot\boot.asm" -o "bin\x86\boot.bin"
"%PROGRAMFILES%\qemu\qemu-system-x86_64.exe" -fda bin\x86\boot.bin
