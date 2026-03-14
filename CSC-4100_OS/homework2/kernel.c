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
    char dims[] = "HW: 00x00";
    int h = term_txtheight();
    int w = term_txtwidth();
    dims[4] = (char)('0' + ((h / 10) % 10));
    dims[5] = (char)('0' + (h % 10));
    dims[7] = (char)('0' + ((w / 10) % 10));
    dims[8] = (char)('0' + (w % 10));

    // Requirements: srow=21, scol=49, erow=27, ecol=79
    unsigned int srow = 21;
    unsigned int scol = 49;
    unsigned int erow = 27;
    unsigned int ecol = 79;
    int width = (ecol - scol) + 1;
    int height = (erow - srow) + 1;
    clear_scr(srow, scol, width, height);
    // box(srow, scol, erow, ecol);
    print_to(0, 0, "Running processes");
    print_to(0, 20, dims);

    // → call q_init(Ready_q)
    // initialize Ready queue data structure. The prototype for q_init is: void q_init(Queue_t *)
    // The first arrow line is "call q_init(Ready_q)" so that your ready queue that will order the execution of the processes is initialized properly.  This function, which you will write in C/C++, will set the head and tail pointers of Ready_q to NULL (or zero).
    q_init(Ready_q);
    print_to(1, 0, "K: q_init done");

    // → set retval to the return value of spawn_process(p1)
    // The second arrow line is a call to spawn_process(p1), which will set up an initial context for the process, allocate its PCB, and put a pointer to the PCB in the ready queue.  The argument p1 is a pointer to a function.  This will be the code that the new process will execute.
    // The prototype of sqawn_process is: int spawn_process(int (*pfun)())
    int retval = spawn_process(p1);
    if (retval != 0) {
        print_to(1, 0, "Error spawning process p1");
    } else {
        print_to(2, 0, "K: spawn p1 ok");
    }
    retval = spawn_process(p2);
    if (retval != 0) {
        print_to(2, 0, "Error spawning process p2");
    } else {
        print_to(3, 0, "K: spawn p2 ok");
    }
    retval = spawn_process(p3);
    if (retval != 0) {
        print_to(3, 0, "Error spawning process p3");
    } else {
        print_to(4, 0, "K: spawn p3 ok");
    }
    retval = spawn_process(p4);
    if (retval != 0) {
        print_to(4, 0, "Error spawning process p4");
    } else {
        print_to(5, 0, "K: spawn p4 ok");
    }

    // → asm volatile("b restore_context");
    // dispatch the current Running process This restores the context of the process at which Running points, and then jumps to its next instruction.
    // Note: retore_context is a label in assembler.  You must declare it as .global in the assembly file to use it here.
    // The next line with an arrow is an inlined assembly language instruction (only use inline assembly this once; all you other assembly code should be in an assembly file). This instruction jumps to assembly code that dispatches the process indicated by the variable Running by restoring the process' context and jumping to its first instruction, which completes system startup. Later in this assignment description, you will be shown exactly what actual code you need to have for spawn_process() and dispatch_select()and restore_context.
    print_to(6, 0, "K: jump restore");
    asm volatile("b restore_context");

    // Question to professor: Should we ever use this safeguard?
    __builtin_unreachable();

    // Note that you never return here
}