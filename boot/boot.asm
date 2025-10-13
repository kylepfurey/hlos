; .asm
; OS Entry Point
; by Kyle Furey


; Directives
org 0x7C00				; Load at OS address
bits 16					; Set to 16-bit instructions


; OS entry point
main:
	mov ax, 0			; Initialize ax to 0
	mov ds, ax			; Set the data segment
	mov es, ax			; Set the extra segment
	mov ss, ax			; Set the stack segment
	mov sp, 0x7C00		; Set the stack pointer
	mov si, msg_boot	; Load boot message in si
	call print			; Print boot message
	hlt					; Halt CPU
.stop:
	jmp .stop			; Loop infinitely


; Prints the string currently loaded in si
print:
	push si				; Push si register to the stack
	push ax				; Push ax register to the stack
	push bx				; Push bx register to the stack
.loop:
	lodsb				; Load the next character
	or al, al			; Check for null terminator
	jz .done			; Exit if null terminator
	mov ah, 0x0E		; BIOS interrupt for printing
	int 0x10			; Call BIOS interrupt
	jmp .loop			; Loop
.done:
	pop bx				; Pop bx register from the stack
	pop ax				; Pop ax register from the stack
	pop si				; Pop si register from the stack
	ret					; Exit function


; Boot test message
msg_boot: db 'Successfully booted HLOS.', 0x0D, 0x0A, 0


; Boot sector
times 510-($-$$) db 0	; Fill boot sector to 512 bytes
dw 0xAA55				; Boot signature
