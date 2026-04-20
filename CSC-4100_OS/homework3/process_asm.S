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
    // Pick the next ready process.
    bl dispatch_select

    // x1 = saved process frame pointer from Running->sp.
    adr x0, Running
    ldr x0, [x0]
    cbz x0, restore_halt
    ldr x1, [x0]

    // Restore PSTATE and exception return address.
    ldr x0, [x1, #248]
    msr SPSR_EL1, x0
    ldr x0, [x1, #256]
    msr ELR_EL1, x0

    // SP_EL0 must point to the process stack top after the saved frame.
    mov x0, x1
    add x0, x0, #272
    msr SP_EL0, x0

    // Restore process GPRs except x0/x1 and x29/x30 for now.
    ldp x2, x3, [x1, #16]
    ldp x4, x5, [x1, #32]
    ldp x6, x7, [x1, #48]
    ldp x8, x9, [x1, #64]
    ldp x10, x11, [x1, #80]
    ldp x12, x13, [x1, #96]
    ldp x14, x15, [x1, #112]
    ldp x16, x17, [x1, #128]
    ldp x18, x19, [x1, #144]
    ldp x20, x21, [x1, #160]
    ldp x22, x23, [x1, #176]
    ldp x24, x25, [x1, #192]
    ldp x26, x27, [x1, #208]

    // Re-arm the timer for the next preemption tick.
    sub sp, sp, #16
    stp x0, x1, [sp]
    bl clear_timer
    ldp x0, x1, [sp]
    add sp, sp, #16

    // Restore remaining process registers.
    ldr x28, [x1, #224]
    ldr x29, [x1, #232]
    ldr x30, [x1, #240]
    ldr x0, [x1, #0]
    ldr x1, [x1, #8]

    // Re-enable IRQ and return from exception into EL0.
    msr DAIFClr, #0x2
    eret

restore_halt:
    b restore_halt

.section .rodata
unsupported_msg:
    .asciz "Error: unsupported exception!"