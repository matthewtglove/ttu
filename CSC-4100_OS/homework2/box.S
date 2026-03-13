.global     box

box:
    // standard entry: save link and stack frame registers
    // load the stack frame with the pointer to current frame
    stp     x29, x30, [sp, -16]!
    mov     x29, sp

    // Save the arguments.  Called functions may overwrite x0-x3
    sub     sp, sp, 32
    stp     x0, x1, [sp]
    stp     x2, x3, [sp, 16]

    // sr in w0, sc in w1, er int w2, ec in w3
    
    // Make sure the argument are valid

    bl      _box_check_box_
    cmp     w0, 0
    bne     box_error

    // first, draw the corners:
    // +        +
    // +        +
    ldp     x0, x1, [sp]
    ldp     x2, x3, [sp, 16]
    bl      _box_draw_corners_

    // Now, draw the top and bottom:
    // +------+
    // +------+

    ldp     x0, x1, [sp]
    ldp     x2, x3, [sp, 16]
    bl      _box_draw_top_bottom_

    // draw left and right sides

    ldp     x0, x1, [sp]
    ldp     x2, x3, [sp, 16]
    bl      _box_draw_right_left_
    mov     w0, 0
    b       box_exit

box_error:
    mov     w0, 1

box_exit:
    add     sp, sp, 32
    ldp     x29, x30, [sp], 16
    ret

// # HELPER FUNCTIONS

// --- Check the arguments for validity --- //
_box_check_box_:
    // Prologue (keep stack 16-byte aligned)
    stp     x29, x30, [sp, -16]!
    mov     x29, sp

    // Save start/end rows and cols (w0-w3)
    sub     sp, sp, 32
    stp     x0, x1, [sp]
    stp     x2, x3, [sp, 16]

    bl      term_txtheight
    ldp     x2, x3, [sp, 16]
    cmp     w2, w0
    bhs     check_error
    bl      term_txtwidth
    ldp     x2, x3, [sp, 16]
    cmp     w3, w0
    bhs     check_error

    // Restore start/end rows and cols for next comparisons
    ldp     x0, x1, [sp]
    ldp     x2, x3, [sp, 16]

    cmp     w2, w0
    bls     check_error
    cmp     w3, w1
    bls     check_error

    // All checks passed → return 0
    mov     w0, 0
    b       check_exit

check_error:
    mov     w0, 1

check_exit:
    add     sp, sp, 32
    ldp     x29, x30, [sp], 16
    ret

// --- Draw the corners --- //
_box_draw_corners_:
    // Save FP, LR, and callee-saved registers (x19-x22)
    stp     x29, x30, [sp, -48]!
    stp     x19, x20, [sp, 16]
    stp     x21, x22, [sp, 32]
    mov     x29, sp

    // w0 = start_row
    // w1 = start_col
    // w2 = end_row
    // w3 = end_col
    
    // Move arguments to safe registers (w19-w22)
    mov     w19, w0
    mov     w20, w1
    mov     w21, w2
    mov     w22, w3

    // top-left
    mov     w0, w19
    mov     w1, w20
    mov     w2, '+'
    bl      putc_to

    // top-right
    mov     w0, w19
    mov     w1, w22
    mov     w2, '+'
    bl      putc_to

    // bottom-left
    mov     w0, w21
    mov     w1, w20
    mov     w2, '+'
    bl      putc_to

    // bottom-right
    mov     w0, w21
    mov     w1, w22
    mov     w2, '+'
    bl      putc_to

    // Restore registers and return
    ldp     x19, x20, [sp, 16]
    ldp     x21, x22, [sp, 32]
    ldp     x29, x30, [sp], 48
    ret

// --- Draw the top and bottom lines --- //
_box_draw_top_bottom_:
    // Save FP, LR, and callee-saved registers (x19-x24)
    stp     x29, x30, [sp, -64]!
    stp     x19, x20, [sp, 16]
    stp     x21, x22, [sp, 32]
    stp     x23, x24, [sp, 48]
    mov     x29, sp

    // w0 = start_row, w1 = start_col, w2 = end_row, w3 = end_col
    // Save to safe registers
    mov     w19, w0
    mov     w20, w1
    mov     w21, w2
    mov     w22, w3

    // Draw top line
    add     w23, w20, 1       // w23 = current col (start_col + 1)
    sub     w24, w22, 1       // w24 = limit (end_col - 1)
top_line_loop:
    cmp     w23, w24
    bgt     top_line_done
    mov     w0, w19           // row
    mov     w1, w23           // col
    mov     w2, '-'           // char
    bl      putc_to
    add     w23, w23, 1       // move to the next column
    b       top_line_loop
top_line_done:
    // Draw bottom line
    add     w23, w20, 1       // w23 = current col (start_col + 1)
    sub     w24, w22, 1       // w24 = limit (end_col - 1)
bottom_line_loop:
    cmp     w23, w24
    bgt     bottom_line_done
    mov     w0, w21           // row (end_row)
    mov     w1, w23           // col
    mov     w2, '-'           // char
    bl      putc_to
    add     w23, w23, 1       // move to the next column
    b       bottom_line_loop
bottom_line_done:
    ldp     x19, x20, [sp, 16]
    ldp     x21, x22, [sp, 32]
    ldp     x23, x24, [sp, 48]
    ldp     x29, x30, [sp], 64
    ret

// --- Draw the left and right lines --- //
_box_draw_right_left_:
    // Save FP, LR, and callee-saved registers (x19-x24)
    stp     x29, x30, [sp, -64]!
    stp     x19, x20, [sp, 16]
    stp     x21, x22, [sp, 32]
    stp     x23, x24, [sp, 48]
    mov     x29, sp

    // w0 = start_row, w1 = start_col, w2 = end_row, w3 = end_col
    // Save to safe registers
    mov     w19, w0
    mov     w20, w1
    mov     w21, w2
    mov     w22, w3

    // Draw right line
    add     w23, w19, 1       // w23 = current row (start_row + 1)
    sub     w24, w21, 1       // w24 = limit (end_row - 1)
right_line_loop:
    cmp     w23, w24
    bgt     right_line_done
    mov     w0, w23           // row
    mov     w1, w20           // col (start_col)
    mov     w2, '|'           // char
    bl      putc_to
    add     w23, w23, 1       // move to the next row
    b       right_line_loop
right_line_done:
    // Draw left line
    add     w23, w19, 1       // w23 = current row (start_row + 1)
    sub     w24, w21, 1       // w24 = limit (end_row - 1)
left_line_loop:
    cmp     w23, w24
    bgt     left_line_done
    mov     w0, w23           // row
    mov     w1, w22           // col (end_col)
    mov     w2, '|'           // char
    bl      putc_to
    add     w23, w23, 1       // move to the next row
    b       left_line_loop
left_line_done:
    ldp     x19, x20, [sp, 16]
    ldp     x21, x22, [sp, 32]
    ldp     x23, x24, [sp, 48]
    ldp     x29, x30, [sp], 64
    ret