#include "libos.h"
#include "process.h"

int clear_scr(int start_row, int start_col, int width, int height) {
    // Ensure we don't go out of bounds
    if (start_row + height > term_txtheight() || start_col + width > term_txtwidth()) {
        return 1;
    }
    // Fill the area with spaces
    for (int r = start_row; r < start_row + height; r++) {
        for (int c = start_col; c < start_col + width; c++) {
            putc_to(r, c, ' ');
        }
    }
    return 0;
}

int main(void) {
    int width = term_txtwidth();
    int height = term_txtheight();

    // Start from a clean screen and show a simple title.
    clear_scr(0, 0, width, height);
    print_to(0, 0, "Running processes");

    // Initialize the ready queue before any processes are created.
    q_init(Ready_q);

    // Create the four processes and report any startup failure.
    int retval = spawn_process(p1);
    if (retval != 0) {
        print_to(1, 0, "Error spawning process p1");
    }
    retval = spawn_process(p2);
    if (retval != 0) {
        print_to(2, 0, "Error spawning process p2");
    }
    retval = spawn_process(p3);
    if (retval != 0) {
        print_to(3, 0, "Error spawning process p3");
    }
    retval = spawn_process(p4);
    if (retval != 0) {
        print_to(4, 0, "Error spawning process p4");
    }

    // Install the exception vector table and start the virtual timer.
    setup_EVT();
    init_timer();

    // Unmask IRQ interrupts.
    asm volatile("msr DAIFClr, #0x2");

    // Hand off to the assembly restore path, which selects the first ready process, restores its saved context, and begins executing it.
    asm volatile("b restore_context");

    // Note that you never return here
}