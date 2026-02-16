//#include "mm.h"

//.section ".text.boot"

/*
.globl _start
_start:
    mrs    x0, mpidr_el1        
    and    x0, x0,#0xFF        // Check processor id
    cbz    x0, master        // Hang for all non-primary CPU
    b    proc_hang

proc_hang: 
    b proc_hang

master:
    adr    x0, bss_begin
    adr    x1, bss_end
    sub    x1, x1, x0
    bl     memzero

    mov    sp, #LOW_MEMORY
    bl    kernel_main

*/

.global _start
_start:
    mrs    x0, mpidr_el1        
    and    x0, x0,#0xFF        // Check processor id
    cbz    x0, master        // Hang for all non-primary CPU

proc_hang:
    b proc_hang
    
master:
	mov sp, #0x07FFFFF0
    bl uart_init
    bl lfb_init
	bl main
boot_forever:
    b boot_forever
