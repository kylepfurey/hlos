; .asm
; OS Entry Point
; by Kyle Furey


; Directives
org 0x7C00					; Load at OS address
bits 16						; Set to 16-bit instructions


; OS entry point
main:
	mov [boot_drive], dl	; Save the boot drive number
	mov ax, 0				; Initialize ax to 0
	mov ds, ax				; Set the data segment
	mov ss, ax				; Set the stack segment
	mov sp, 0x7C00			; Set the stack pointer
	mov si, msg_boot		; Load boot message in si
	call print				; Print boot message
	call boot				; Boot kernel
	jmp pause				; Pause


; Pauses execution
pause:
	hlt						; Halt CPU
	jmp pause				; Loop infinitely


; Prints the string currently loaded in si
print:
	push si					; Push si register to the stack
	push ax					; Push ax register to the stack
	push bx					; Push bx register to the stack
.loop:
	lodsb					; Load the next character
	or al, al				; Check for null terminator
	jz .done				; Exit if null terminator
	mov ah, 0x0E			; BIOS interrupt for printing
	int 0x10				; Call BIOS teletype interrupt
	jmp .loop				; Loop
.done:
	pop bx					; Pop bx register from the stack
	pop ax					; Pop ax register from the stack
	pop si					; Pop si register from the stack
	ret						; Exit function


; Loads the kernel and jumps to the entry point
boot:
	mov ah, 0x2				; Read sectors from disk (1 sector = 512 bytes)
	mov al, 3				; Read kernel sectors (kernel size / 512 rounded up)
	mov ch, 0				; Read cylinder 0
	mov cl, 2				; Read the sector after this bootloader
	mov dh, 0				; Read head 0
	mov dl, [boot_drive]	; Load the boot drive number
	mov ax, 0x1000			; Load the kernel in memory at es:bx
	mov es, ax				; Store 0x1000 in es
	mov bx, 0				; Store 0 in bx
	int 0x13				; Call BIOS disk read
	jc disk_error			; Exit if disk failure
	mov ax, 0x1000			; Set segment registers to the kernel
	mov ds, ax				; Set the data segment
	jmp 0x1000:0			; Run kernel_main()
	ret						; Exit function


; Disk error message
disk_error:
	mov si, msg_error		; Load error message in si
	call print				; Print disk error message
	jmp pause				; Pause


; Boot number
boot_drive: db 0


; Boot test message
msg_boot: db 'Successfully booted HLOS.', 0x0D, 0x0A, 0


; Disk error message
msg_error: db 'Could not load kernel!', 0x0D, 0x0A, 0


; Boot sector
times 510-($-$$) db 0		; Fill boot sector to 512 bytes
dw 0xAA55					; Boot signature
