; .asm
; OS External Assembly Functions
; by Kyle Furey


; 32-bit directives
bits 32								; Set instructions to 32-bit protected mode


; Declare exported functions
global hlt							; void hlt()
global cli							; void cli()
global sti							; void sti()
global in							; byte_t in(ushort_t port)
global out							; void out(ushort_t port, byte_t num)
global timer_interrupt				; void timer_interrupt()


; Declare external functions
extern tick							; void tick()


; Pauses the CPU
hlt:
	hlt								; Halt CPU
	ret								; Exit function


; Disables external interrupts
cli:
	cli								; Disable interrupts
	ret								; Exit function


; Enables external interrupts
sti:
	sti								; Enable interrupts
	ret								; Exit function


; Reads a byte from the given IO port
in:
	push ebp						; Push base pointer to the stack
	mov ebp, esp					; Store the stack pointer
	mov dx, [ebp+8]					; Store <port>
	in al, dx						; Read from <port>
	pop ebp							; Pop base pointer from the stack
	ret								; Exit function


; Writes a byte to the given IO port
out:
	push ebp						; Push base pointer to the stack
	mov ebp, esp					; Store the stack pointer
	mov dx, [ebp+8]					; Store <port>
	mov al, [ebp+12]				; Store <num>
	out dx, al						; Write <num> to <port>
	pop ebp							; Pop base pointer from the stack
	ret								; Exit function


; INTERRUPTS


; The callback for the timer interrupt
timer_interrupt:
	pushad							; Push 32-bit registers to the stack
	push ds							; Push data segment selector to the stack
	push es							; Push extra segment selector to the stack
	push fs							; Push general purpose segment selector to the stack
	push gs							; Push general purpose segment selector to the stack
	call tick						; Call tick() in C
	mov al, 0x20					; Store the end-of-interrupt command
	out 0x20, al					; Send end-of-interrupt command to the master PIC
	pop gs							; Pop general purpose segment selector from the stack
	pop fs							; Pop general purpose segment selector from the stack
	pop es							; Pop extra segment selector from the stack
	pop ds							; Pop data segment from the stack
	popad							; Pop 32-bit registers from the stack
	iret							; Exit interrupt
