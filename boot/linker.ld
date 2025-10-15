/**
 * .ld
 * OS Linker Script
 * by Kyle Furey
 */

OUTPUT_FORMAT("binary")			/** Output as binary */
ENTRY(kernel_main)				/** Set kernel_main() entry point */

SECTIONS {
	. = 0x1000;					/** Load kernel immediately after bootloader */
	__kernel_start = .;
	.text : { *(.text) }		/** Source code */
	.rodata : { *(.rodata) }	/** Read-only data */
	.data : { *(.data) }		/** Initialized data */
	.bss : {
		__bss_start = .;
		*(.bss)					/** Uninitialized data */
		*(COMMON)
		__bss_end = .;
	}
	__kernel_end = .;
}
