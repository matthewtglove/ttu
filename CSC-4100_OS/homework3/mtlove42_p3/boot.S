#define HCR_VALUE			HCR_RW
#define HCR_RW	    			(1 << 31)
#define SCR_RESERVED	    		(3 << 4)
#define SCR_RW				(1 << 10)
#define SCR_NS				(1 << 0)
#define SCR_VALUE	    	    	(SCR_RESERVED | SCR_RW | SCR_NS)
#define SPSR_MASK_ALL 			(7 << 6)
#define SPSR_EL1h			(5 << 0)
#define SPSR_VALUE			(SPSR_MASK_ALL | SPSR_EL1h)
#define SCTLR_RESERVED                  (3 << 28) | (3 << 22) | (1 << 20) | (1 << 11)
#define SCTLR_EE_LITTLE_ENDIAN          (0 << 25)
#define SCTLR_EOE_LITTLE_ENDIAN         (0 << 24)
#define SCTLR_I_CACHE_DISABLED          (0 << 12)
#define SCTLR_D_CACHE_DISABLED          (0 << 2)
#define SCTLR_MMU_DISABLED              (0 << 0)
#define SCTLR_MMU_ENABLED               (1 << 0)

#define SCTLR_VALUE_MMU_DISABLED	(SCTLR_RESERVED | SCTLR_EE_LITTLE_ENDIAN | SCTLR_I_CACHE_DISABLED | SCTLR_D_CACHE_DISABLED | SCTLR_MMU_DISABLED)


.globl _start
_start:
	mrs	x0, mpidr_el1		
	and	x0, x0,#0xFF		// Check processor id
	cbz	x0, master		// Hang for all non-primary CPU
	b	proc_hang

proc_hang: 
	b 	proc_hang

master:
	ldr	x0, =SCTLR_VALUE_MMU_DISABLED
	msr	sctlr_el1, x0		

	ldr	x0, =HCR_VALUE
	msr	hcr_el2, x0

	ldr	x0, =SCR_VALUE
	msr	scr_el3, x0

	ldr	x0, =SPSR_VALUE
	msr	spsr_el3, x0

	adr	x0, el1_entry		
	msr	elr_el3, x0

	eret				

el1_entry:
	mov sp, #0x07FFFFF0
    //ldr x0, =vector_table
    //msr vbar_el1, x0 
    bl uart_init
    bl lfb_init
	bl	main
	b 	proc_hang		// should never come here
