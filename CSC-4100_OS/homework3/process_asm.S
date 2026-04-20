.text
.align 2

.global setup_EVT
setup_EVT:
    adr x0, vector_table
    msr VBAR_EL1, x0
    ret

.global init_timer
init_timer:
    stp x29, x30, [sp, -16]!
    bl clear_timer

    // Route core 0 virtual counter interrupt to core 0 IRQ.
    ldr x0, =0x40000040
    mov x1, #0x08
    str w1, [x0]

    // Enable virtual timer.
    mov x0, #1
    msr CNTV_CTL_EL0, x0

    ldp x29, x30, [sp], 16
    ret

.global clear_timer
clear_timer:
    // Schedule next timer interrupt for 1/20 second.
    mrs x0, CNTFRQ_EL0
    mov x1, #20
    udiv x0, x0, x1
    msr CNTV_TVAL_EL0, x0
    ret

// Exception vector table (16 entries, 128 bytes each).
.align 11
vector_table:
    .balign 128
    b unsupported
    .balign 128
    b dispatch
    .balign 128
    b unsupported
    .balign 128
    b unsupported
    .balign 128
    b unsupported
    .balign 128
    b dispatch
    .balign 128
    b unsupported
    .balign 128
    b unsupported
    .balign 128
    b unsupported
    .balign 128
    b dispatch
    .balign 128
    b unsupported
    .balign 128
    b unsupported
    .balign 128
    b unsupported
    .balign 128
    b dispatch
    .balign 128
    b unsupported
    .balign 128
    b unsupported

.global unsupported
unsupported:
    mov x0, #0
    mov x1, #0
    ldr x2, =unsupported_msg
    bl print_to
unsupported_halt:
    b unsupported_halt

.global dispatch
dispatch:
    // Disable IRQ while we switch processes.
    msr DAIFSet, #0x2

    // Save process x1 on the EL1 stack so x1 can hold SP_EL0.
    sub sp, sp, #16
    str x1, [sp]

    // x1 = current process stack pointer (EL0 stack).
    mrs x1, SP_EL0
    sub x1, x1, #272

    // Save x0 and the original process x1 first.
    str x0, [x1, #0]
    ldr x0, [sp]
    str x0, [x1, #8]

    // Save x2..x30 into the process stack frame.
    stp x2, x3, [x1, #16]
    stp x4, x5, [x1, #32]
    stp x6, x7, [x1, #48]
    stp x8, x9, [x1, #64]
    stp x10, x11, [x1, #80]
    stp x12, x13, [x1, #96]
    stp x14, x15, [x1, #112]
    stp x16, x17, [x1, #128]
    stp x18, x19, [x1, #144]
    stp x20, x21, [x1, #160]
    stp x22, x23, [x1, #176]
    stp x24, x25, [x1, #192]
    stp x26, x27, [x1, #208]
    stp x28, x29, [x1, #224]
    str x30, [x1, #240]

    // Save process PSTATE and exception return address.
    mrs x0, SPSR_EL1
    str x0, [x1, #248]
    mrs x0, ELR_EL1
    str x0, [x1, #256]

    // Save new process stack pointer in Running->sp.
    adr x0, Running
    ldr x0, [x0]
    str x1, [x0]

    // Enqueue the old Running process.
    adr x0, Ready_q
    ldr x0, [x0]
    adr x1, Running
    ldr x1, [x1]
    bl q_enqueue

    // Drop temporary EL1 stack storage for x1.
    add sp, sp, #16

.global restore_context
restore_context:   // Note that this is where the inline assembly in main jumps
    // 6) call dispatch_select()
    bl dispatch_select

    // 7) read the stack pointer value out of the pcb at which Running points
    adr x1, Running
    ldr x0, [x1]    // x0 = Running PCB pointer
    cbz x0, restore_halt
    ldr x2, [x0]    // x2 now has the value of sp
    mov sp, x2      // sp now has the top of stack for the chosen process

    // 8) restore the PSTATE from the stack
    ldr x0, [sp, 16*15+8]
    msr SPSR_EL1, x0

    // 9) copy all register values for x0-x30 from the stack at which sp points into those registers.
    ldr x0, [sp, #0]
    ldr x1, [sp, #8]
    ldr x2, [sp, #16]
    ldr x3, [sp, #24]
    ldr x4, [sp, #32]
    ldr x5, [sp, #40]
    ldr x6, [sp, #48]
    ldr x7, [sp, #56]
    ldr x8, [sp, #64]
    ldr x9, [sp, #72]
    ldr x10, [sp, #80]
    ldr x11, [sp, #88]
    ldr x12, [sp, #96]
    ldr x13, [sp, #104]
    ldr x14, [sp, #112]
    ldr x15, [sp, #120]
    ldr x16, [sp, #128]
    ldr x17, [sp, #136]
    ldr x18, [sp, #144]
    ldr x19, [sp, #152]
    ldr x20, [sp, #160]
    ldr x21, [sp, #168]
    ldr x22, [sp, #176]
    ldr x23, [sp, #184]
    ldr x24, [sp, #192]
    ldr x25, [sp, #200]
    ldr x26, [sp, #208]
    ldr x27, [sp, #216]
    ldr x28, [sp, #224]
    ldr x29, [sp, #232]

    // Restore saved PC/return target
    ldr x30, [sp, #240]

    // 10) add 16*16 to sp
    add sp, sp, #264

    // 11) return into saved process entry
    ret

restore_halt:
    b restore_halt

.section .rodata
unsupported_msg:
    .asciz "Error: unsupported exception!"