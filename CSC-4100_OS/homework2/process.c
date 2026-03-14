#include "process.h"

PCB_Q_t Ready_q_storage;
PCB_Q_t *Ready_q = &Ready_q_storage;
PCB_t *Running = 0;
uint32_t next_pid = 1;

int spawn_process(int (*code_address)()) {
    // code_address is the pointer to the function that contains the process code

    // set stackptr to return value of calling alloc_stack() to allocate a stack that is 1024 uint64_t in size.
    // check to make sure stackptr is not null (if it is, return -1)
    uint64_t *stackptr = alloc_stack(1024);
    if (stackptr == 0) {
        return -1;
    }

    // First, set up the stack, pretend sp is a uint64_t *

    // set sp to stackptr + 1024 to put sp at the bottom of the stack
    // Note that if stackptr is a pointer to a uint64_t, then stackptr+1024 will point to the right place
    uint64_t *sp = stackptr + 1024;

    // create context that will set gen purpose regs to 0
    // loop i from 0 to 32 (inclusive)
    //     decrement sp
    // 	set the uint64_t at which sp points to 0
    for (int i = 0; i <= 32; i++) {
        sp--;
        *sp = 0;
    }

    // set the value at which sp+30 points to code_address
    // type cast code_address to a uint64_t so that the compiler does not complain)
    *(sp + 30) = (uint64_t)code_address;

    // Note: you will have to create the pcb struct for the following code
    // set pcb to the return value of alloc_pcb() to allocate a pcb for the process
    PCB_t *pcb = alloc_pcb();
    // check the pcb and if is null then return -1
    if (pcb == 0) {
        return -1;
    }

    // set the pcb's sp member to sp.
    pcb->sp = (uint64_t)sp;

    // set the pcb's pid member to next_pid  //Note that you can keep track of the next pid using a global variable
    pcb->pid = next_pid++;
    pcb->next = 0;

    // enqueue the pcb onto the Ready_q // Ready_q should be a global
    q_enqueue(Ready_q, pcb);

    /* no errors occured */
    return 0;
}

void dispatch_select(void) {
    Running = q_dequeue(Ready_q);
}

extern void restore_context(void);

void dispatch_restore(void) {
    asm volatile("b restore_context");
    __builtin_unreachable();
}