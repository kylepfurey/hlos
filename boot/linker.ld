/**
 * .ld
 * OS Linker Script
 * by Kyle Furey
 */

OUTPUT_FORMAT("elf32-i386")			/** Output as .elf */
ENTRY(kernel_main)					/** Set kernel_main() entry point */

SECTIONS {
	. = 0x10000;					/** Load kernel immediately after bootloader */
	__kernel_start = .;
	.text : { *(.text) }			/** Source code */
	.rodata : { *(.rodata) }		/** Read-only data */
	.data : { *(.data) }			/** Initialized data */
	.bss : {
		__bss_start = .;
		*(.bss)						/** Uninitialized data */
		*(COMMON)
		__bss_end = .;
	}
	__kernel_end = .;
}
