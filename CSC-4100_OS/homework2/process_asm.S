.text
.align 2

.global dispatch
dispatch:
    // 1)	subtract 16*16 from the stack
    sub sp, sp, #264

    // 2)	copy all registers to the stack the stack (in the order x0,x1,...,x30)
    str x0,  [sp, #0]
    str x1,  [sp, #8]
    str x2,  [sp, #16]
    str x3,  [sp, #24]
    str x4,  [sp, #32]
    str x5,  [sp, #40]
    str x6,  [sp, #48]
    str x7,  [sp, #56]
    str x8,  [sp, #64]
    str x9,  [sp, #72]
    str x10, [sp, #80]
    str x11, [sp, #88]
    str x12, [sp, #96]
    str x13, [sp, #104]
    str x14, [sp, #112]
    str x15, [sp, #120]
    str x16, [sp, #128]
    str x17, [sp, #136]
    str x18, [sp, #144]
    str x19, [sp, #152]
    str x20, [sp, #160]
    str x21, [sp, #168]
    str x22, [sp, #176]
    str x23, [sp, #184]
    str x24, [sp, #192]
    str x25, [sp, #200]
    str x26, [sp, #208]
    str x27, [sp, #216]
    str x28, [sp, #224]
    str x29, [sp, #232]
    str x30, [sp, #240]

    // 3)	put the PSTATE into the stack with the following code:
    mrs x0, SPSR_EL1 // Save PSTATE
    str x0, [sp, 16*15+8]

    // 4)	store the new sp value into the pcb where Running points (note that you cannot move sp into memory directly, you have to do something like: 
    adr x1, Running
    ldr x1, [x1]    // Put the first value in the PCB (sp) into x1
    mov x4, sp      // We can't str sp directly, so put sp into x4
    str x4, [x1]    // Then store the new sp in x4 to the PCB

    // 5) call enqueue passing it address of ReadyQ and the value of Running
    adr x0, Ready_q
    ldr x0, [x0]
    adr x1, Running
    ldr x1, [x1]
    bl q_enqueue

.global restore_context
restore_context:   // Note that this is where the inline assembly in main jumps
    // DEBUG marker: entered restore_context
    mov w0, #0
    mov w1, #70
    mov w2, #'R'
    bl putc_to

    // 6) call dispatch_select()
    bl dispatch_select

    // DEBUG marker: returned from dispatch_select — check Running
    adr x1, Running
    ldr x0, [x1]    // x0 = Running PCB pointer
    mov w1, #71
    cbz x0, .Lnull_running
    mov w2, #'S'       // Running is non-null
    b .Ldebug_s
.Lnull_running:
    mov w2, #'N'       // Running is null (empty queue)
.Ldebug_s:
    mov w0, #0
    bl putc_to

    // 7) read the stack pointer value out of the pcb at which Running points
    adr x1, Running
    ldr x0, [x1]    // x0 = Running PCB pointer
    cbz x0, restore_halt
    ldr x2, [x0]    // x2 now has the value of sp
    mov sp, x2      // sp now has the top of stack for the chosen process

    // 8) restore the PSTATE from the stack
    ldr x0, [sp, 16*15+8] // Load PSTATE into x0
    msr SPSR_EL1, x0       // Restore PSTATE

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

    // DEBUG: about to load x30 and ret — bl is safe here, x30 loaded next
    mov w0, #0
    mov w1, #72
    mov w2, #'U'
    bl putc_to

    // DEBUG marker only; do not keep branch target in caller-saved regs across bl
    mov w0, #0
    mov w1, #73
    mov w2, #'V'
    bl putc_to

    // Restore saved PC/return target after debug calls
    ldr x30, [sp, #240]
    ldr x9,  [sp, #240]

    // DEBUG: identify which process entry address is in x9
    adrp x10, p1
    add  x10, x10, :lo12:p1
    cmp  x9, x10
    beq  .Lpc_p1
    adrp x10, p2
    add  x10, x10, :lo12:p2
    cmp  x9, x10
    beq  .Lpc_p2
    adrp x10, p3
    add  x10, x10, :lo12:p3
    cmp  x9, x10
    beq  .Lpc_p3
    adrp x10, p4
    add  x10, x10, :lo12:p4
    cmp  x9, x10
    beq  .Lpc_p4
    mov  w2, #'X'
    b    .Lpc_mark
.Lpc_p1:
    mov  w2, #'1'
    b    .Lpc_mark
.Lpc_p2:
    mov  w2, #'2'
    b    .Lpc_mark
.Lpc_p3:
    mov  w2, #'3'
    b    .Lpc_mark
.Lpc_p4:
    mov  w2, #'4'
.Lpc_mark:
    mov  w0, #0
    mov  w1, #74
    bl   putc_to

    // Reload in case debug call clobbered caller-saved regs
    ldr x30, [sp, #240]
    ldr x9,  [sp, #240]

    // 10) add 16*16 to sp
    add sp, sp, #264

    // 11) jump to saved PC
    br x9

restore_halt:
    b restore_halt