.global     box
.global _box_check_box_
.global _box_draw_corners_

box:
 
    // standard entry: save link and stack frame registers
    //    load the stack frame with the pointer to current frame
    stp     x29, x30, [sp, -16]!

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

    // You figure out what goes here

    // draw left and right sides

    // You figure out what goes here

    mov     w0, 0
    b       box_exit

box_error:
    mov     w0, 1

box_exit:
    add     sp, sp, 32
    ldp     x29, x30, [sp], 16
    ret


_box_check_box_:
    // Prologue (keep stack 16-byte aligned)
    stp     x29, x30, [sp, -16]!
    mov     x29, sp

    // Save start_row and start_col (w0, w1)
    sub     sp, sp, 16
    stp     x0, x1, [sp]

    bl      term_txtheight
    cmp     w2, w0
    bhs     check_error
    bl      term_txtwidth
    cmp     w3, w0
    bhs     check_error

    // Restore start_row and start_col for next comparisons
    ldp     x0, x1, [sp]

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
    add     sp, sp, 16
    ldp     x29, x30, [sp], 16
    ret

; _box_draw_corners_:
;     stp     x29, x30, [sp, -16]!
;     mov     x29, sp

;     // w0 = start_row
;     // w1 = start_col
;     // w2 = end_row
;     // w3 = end_col
    
;     mov     w4, '+'

;     // top-left
;     mov     w5, w0
;     mov     w6, w1
;     bl      putc_to

;     // top-right
;     mov     w5, w0
;     mov     w6, w3
;     bl      putc_to

;     // bottom-left
;     mov     w5, w2
;     mov     w6, w1
;     bl      putc_to

;     // bottom-right
;     mov     w5, w2
;     mov     w6, w3
;     bl      putc_to

;     ldp     x29, x30, [sp], 16
;     ret