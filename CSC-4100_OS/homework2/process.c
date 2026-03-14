#include "process.h"
#include "libos.h"

PCB_Q_t Ready_q_storage;
PCB_Q_t *Ready_q = &Ready_q_storage;
PCB_t *Running = 0;
uint32_t next_pid = 1;

// Static pool allocators (bare-metal: no malloc)
#define MAX_PROCS 8
#define STACK_WORDS 1024

static uint64_t stack_pool[MAX_PROCS][STACK_WORDS] __attribute__((aligned(16)));
static int next_stack_idx = 0;

uint64_t *alloc_stack(uint64_t count) {
    if (count > STACK_WORDS) {
        return 0;
    }
    if (next_stack_idx >= MAX_PROCS)
        return 0;
    return stack_pool[next_stack_idx++];
}

static PCB_t pcb_pool[MAX_PROCS];
static int next_pcb_idx = 0;

PCB_t *alloc_pcb() {
    if (next_pcb_idx >= MAX_PROCS)
        return 0;
    return &pcb_pool[next_pcb_idx++];
}

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
    if (Running == 0) {
        print_to(7, 0, "P: dispatch null ");
    } else {
        char status[] = "P: dispatch X";
        status[12] = (char)('0' + Running->pid);
        print_to(7, 0, status);
    }
}

extern void restore_context(void);

void dispatch_restore(void) {
    asm volatile("b restore_context");
    __builtin_unreachable();
}

static int is_prime(unsigned long long n) {
    if (n < 2ULL) {
        return 0;
    }

    unsigned long long half = n / 2ULL;
    for (unsigned long long divisor = 2ULL; divisor <= half; divisor++) {
        if ((n % divisor) == 0ULL) {
            return 0;
        }
        dispatch();
    }

    return 1;
}

int p1(void) {
    char message[] = "Process 1: 0";
    unsigned long long num = 1ULL;
    unsigned int count = 0;

    print_to(1, 40, "P1 entered");
    box(9, 23, 11, 39);
    print_to(10, 25, message);

    while (1) {
        if (is_prime(num)) {
            count++;
            if (count > 9U) {
                count = 0;
            }
            message[11] = (char)('0' + count);
            print_to(10, 25, message);
        }

        num++;
        if (num > 4000000000ULL) {
            num = 1ULL;
        }

        dispatch();
    }
}

int p2(void) {
    char message[] = "Process 2: 0";
    unsigned long long num = 1ULL;
    unsigned int count = 0;

    print_to(2, 40, "P2 entered");
    box(13, 23, 15, 39);
    print_to(14, 25, message);

    while (1) {
        if (is_prime(num)) {
            count++;
            if (count > 9U) {
                count = 0;
            }
            message[11] = (char)('0' + count);
            print_to(14, 25, message);
        }

        num++;
        if (num > 4000000000ULL) {
            num = 1ULL;
        }

        dispatch();
    }
}

int p3(void) {
    char message[] = "Process 3: 0";
    unsigned long long num = 1ULL;
    unsigned int count = 0;

    print_to(3, 40, "P3 entered");
    box(9, 49, 11, 65);
    print_to(10, 51, message);

    while (1) {
        if (is_prime(num)) {
            count++;
            if (count > 9U) {
                count = 0;
            }
            message[11] = (char)('0' + count);
            print_to(10, 51, message);
        }

        num++;
        if (num > 4000000000ULL) {
            num = 1ULL;
        }

        dispatch();
    }
}

int p4(void) {
    char message[] = "Process 4: 0";
    unsigned long long num = 1ULL;
    unsigned int count = 0;

    print_to(4, 40, "P4 entered");
    box(13, 49, 15, 65);
    print_to(14, 51, message);

    while (1) {
        if (is_prime(num)) {
            count++;
            if (count > 9U) {
                count = 0;
            }
            message[11] = (char)('0' + count);
            print_to(14, 51, message);
        }

        num++;
        if (num > 4000000000ULL) {
            num = 1ULL;
        }

        dispatch();
    }
}