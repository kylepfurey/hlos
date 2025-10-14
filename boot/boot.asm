; .asm
; OS Bootloader
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
	jmp boot				; Boot kernel


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


; Loads the kernel from the following sector
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
	mov ds, ax				; Set the data segment - TODO: CRASH!
	jmp kernel				; Enter protected mode


; Disk error message
disk_error:
	mov si, msg_error		; Load error message in si
	call print				; Print disk error message
	jmp pause				; Pause


; Enters protected mode
kernel:
	cli						; Disable interrupts
	call a20				; Enable A20 line
	lgdt [gdt_descriptor]	; Load the GDT
	mov eax, cr0			; Read from control register 0
	or eax, 0x1				; Enable protected mode
	mov cr0, eax			; Write to control register 0
	jmp 0x08:protected		; Run kernel in protected mode


; Enables the A20 line
a20:
	in al, 0x92				; Read from system control port
	or al, 00000010b		; Enable A20 line
	out 0x92, al			; Write to system control port
	ret						; Exit function


; Initializes 32-bit stack and jumps to the entry point
bits 32						; Set to 32-bit instructions
protected:
	mov ax, 0x10			; Store the GDT segment selector
	mov ds, ax				; Set the data segment
	mov es, ax				; Set the extra segment
	mov fs, ax				; Set the general purpose segment
	mov gs, ax				; Set the general purpose segment
	mov ss, ax				; Set the stack segment
	mov esp, 0x90000		; Set the stack pointer
	jmp 0x08:0x10000		; Run kernel_main()


; Boot number
boot_drive: db 0


; Boot test message
msg_boot: db 'Successfully booted HLOS.', 0x0D, 0x0A, 0


; Disk error message
msg_error: db 'Could not load kernel!', 0x0D, 0x0A, 0


; Global descriptor table
gdt_start:
	dq 0x0000000000000000	; Null segment
	dq 0x00CF9A000000FFFF	; Code segment
	dq 0x00CF92000000FFFF	; Data segment
gdt_end:


; GDT structure
gdt_descriptor:
	dw gdt_end - gdt_start - 1
	dd gdt_start


; Boot sector
times 510-($-$$) db 0		; Fill boot sector to 512 bytes
dw 0xAA55					; Boot signature
