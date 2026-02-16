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
    stp     x29, x30, [sp, -16]!
    mov     x29, sp

    // w0 = start_row
    // w1 = start_col
    // w2 = end_row
    // w3 = end_col
    
    // top-left
    mov     w5, w0
    mov     w6, w1
    mov     w4, '+'
    bl      putc_to

    // top-right
    mov     w5, w0
    mov     w6, w3
    mov     w4, '+'
    bl      putc_to

    // bottom-left
    mov     w5, w2
    mov     w6, w1
    mov     w4, '+'
    bl      putc_to

    // bottom-right
    mov     w5, w2
    mov     w6, w3
    mov     w4, '+'
    bl      putc_to

    ldp     x29, x30, [sp], 16
    ret

// --- Draw the top and bottom lines --- //
_box_draw_top_bottom_:
    stp     x29, x30, [sp, -16]!
    mov     x29, sp

    // w0 = start_row
    // w1 = start_col
    // w2 = end_row
    // w3 = end_col

    // Draw top line
    mov     w5, w0          // row for top line
    add     w6, w1, 1       // starting column for top line (start_col + 1)
    sub     w7, w3, 1       // ending column for top line (end_col - 1)
top_line_loop:
    cmp     w6, w7
    bgt     top_line_done
    mov     w4, '-'
    bl      putc_to
    add     w6, w6, 1       // move to the next column
    b       top_line_loop
top_line_done:
    // Draw bottom line
    mov     w5, w2          // row for bottom line
    add     w6, w1, 1       // starting column for bottom line (start_col + 1)
    sub     w7, w3, 1       // ending column for bottom line (end_col - 1)
bottom_line_loop:
    cmp     w6, w7
    bgt     bottom_line_done
    mov     w4, '-'
    bl      putc_to
    add     w6, w6, 1       // move to the next column
    b       bottom_line_loop
bottom_line_done:
    ldp     x29, x30, [sp], 16
    ret

// --- Draw the left and right lines --- //
_box_draw_right_left_:
    stp     x29, x30, [sp, -16]!
    mov     x29, sp

    // w0 = start_row
    // w1 = start_col
    // w2 = end_row
    // w3 = end_col

    // Draw right line
    add     w5, w0, 1       // starting row for right line (start_row + 1)
    mov     w6, w1          // column for the right line
    sub     w7, w2, 1       // ending row for right line (end_row - 1)
right_line_loop:
    cmp     w5, w7
    bgt     right_line_done
    mov     w4, '|'
    bl      putc_to
    add     w5, w5, 1       // move to the next row
    b       right_line_loop
right_line_done:
    // Draw left line
    add     w5, w0, 1       // starting row for left line (start_row + 1)
    mov     w6, w3          // column for the left line
    sub     w7, w2, 1       // ending row for left line (end_row - 1)
left_line_loop:
    cmp     w5, w7
    bgt     left_line_done
    mov     w4, '|'
    bl      putc_to
    add     w5, w5, 1       // move to the next row
    b       left_line_loop
left_line_done:
    ldp     x29, x30, [sp], 16
    ret