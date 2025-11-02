; .asm
; OS Bootloader
; by Kyle Furey


; 16-bit directives
org 0x7C00							; Set origin to BIOS bootloader address
bits 16								; Set instructions to 16-bit real mode


; OS entry point
main:
	cli								; Disable interrupts
	mov [boot_drive], dl			; Store boot drive
	jmp init_stack16				; Initialize 16-bit stack registers


; Boot drive number
boot_drive:
	db 0x0


; Initializes the 16-bit stack registers
init_stack16:
	xor ax, ax						; Initialize 16-bit accumulator to 0
	mov ds, ax						; Initialize data segment
	mov es, ax						; Initialize extra segment
	mov ss, ax						; Initialize stack segment
	mov sp, 0x7C00					; Initialize stack pointer to origin
	jmp load_kernel					; Load kernel from disk


; Loads the kernel from disk
load_kernel:
	mov ah, 0x2						; Set BIOS read sectors function
	mov al, 18						; Set number of sectors (kernel size / 512 rounded up)
	mov ch, 0x0						; Set cylinder 0
	mov cl, 0x2						; Set sector after bootloader
	mov dh, 0x0						; Set head 0
	mov dl, [boot_drive]			; Set boot drive
	mov bx, 0x1000					; Set kernel address (address must match linker)
	int 0x13						; Load kernel with a BIOS interrupt
	jc disk_error					; Jump if loading fails
	xor ax, ax						; Clear accumulator
	mov ds, ax						; Clear data segment
	mov si, msg_boot				; Load string into source index
	call print16					; Print boot message
	call hi_professor				; Print message for professor
	jmp enable_a20					; Enable A20 line


; Called when disk read fails
disk_error:
	xor ax, ax						; Clear accumulator
	mov ds, ax						; Clear data segment
	mov si, msg_error				; Load string into source index
	call print16					; Print disk error message
	jmp pause						; Pause execution


; Boot message string
msg_boot:
	db 'Successfully booted HLOS.', 0xD, 0xA, 0x0


; Prints the string held in the source index register (16-bit)
print16:
	push si							; Push source index into the stack 
	push ax							; Push accumulator into the stack
.loop:
	lodsb							; Load the next character into the lower byte of accumulator
	or al, al						; Check for null-terminator character
	jz .exit						; Exit if null-terminator character
	mov ah, 0xE						; Set BIOS teletype function
	int 0x10						; Print character with a BIOS interrupt
	jmp .loop						; Loop
.exit:
	pop ax							; Pop accumulator from the stack
	pop si							; Pop source index from the stack 
	ret								; Exit function


; Prints a message for the professor
hi_professor:
	xor ax, ax						; Clear accumulator
	mov ds, ax						; Clear data segment
	mov si, msg_professor			; Load string into source index
	call print16					; Print professor message
	ret								; Exit function


; Enables the A20 line
enable_a20:
	in al, 0x92						; Read from control port A
	or al, 0x2						; Enable A20 gate
	out 0x92, al					; Write to control port A
	jmp protected_mode				; Enter 32-bit protected mode


; Disk error message string
msg_error:
	db 'Could not load kernel!', 0xD, 0xA, 0x0


; Pauses execution
pause:
	hlt								; Halt CPU
	jmp pause						; Infinitely loop


; Message for the professor
msg_professor:
	db 0xD, 0xA, 'Hello Professor Sindhu!', 0xD, 0xA, 0x0


; Enters 32-bit protected mode
protected_mode:
	lgdt [gdt_descriptor]			; Load GDT
	mov eax, cr0					; Read from control register 0
	or eax, 0x1						; Enable protected mode
	mov cr0, eax					; Write to control register 0
	jmp 0x8:init_stack32			; Initialize 32-bit stack selectors (32-bit jump)


; GDT descriptor structure
gdt_descriptor:
	dw gdt_end - gdt_start - 1		; Size of GDT
	dd gdt_start					; Address of GDT


; Global descriptor table
gdt_start:
	dq 0x0000000000000000			; Null segment
	dq 0x00CF9A000000FFFF			; Code segment
	dq 0x00CF92000000FFFF			; Data segment
gdt_end:


; 32-bit directives
bits 32								; Set instructions to 32-bit protected mode


; Initializes the 32-bit stack selectors
init_stack32:
	mov ax, 0x10					; Store data segment selector
	mov ds, ax						; Initialize data segment selector
	mov es, ax						; Initialize extra segment selector
	mov fs, ax						; Initialize general purpose segment selector
	mov gs, ax						; Initialize general purpose segment selector
	mov ss, ax						; Initialize stack segment selector
	mov esp, 0x90000				; Initialize stack pointer to top
	mov ebp, esp					; Initialize base pointer
	cld								; Clear direction flag
	xor eax, eax					; Initialize 32-bit accumulator to 0
	xor ebx, ebx					; Initialize base register to 0
	xor ecx, ecx					; Initialize counter to 0
	xor edx, edx					; Initialize data register to 0
	jmp init_floats					; Initialize floating-point operations


; Initializes floating-point operations
init_floats:
	mov eax, cr0					; Read from control register 0
	and eax, 0xFFFFFFFB				; Disable FPU emulation mode
	or eax, 0x22					; Handle FPU errors
	mov cr0, eax					; Write to control register 0
	mov eax, cr4					; Read from control register 4
	or eax, 0x600					; Enable SSE instructions
	mov cr4, eax					; Write to control register 4
	fninit							; Initializes registers for floating-point arithmetic
	xor eax, eax					; Clear accumulator
	jmp start_kernel				; Jump to kernel entry point


; Jumps to kernel entry point
start_kernel:
	jmp 0x1000						; Jump to kernel_main() (address must match linker)


; Boot sector
times 510-($-$$) db 0x0				; Fill boot sector to 512 bytes
dw 0xAA55							; Boot signature
