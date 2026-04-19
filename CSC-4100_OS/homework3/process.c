#include "process.h"
#include "libos.h"

PCB_Q_t Ready_q_storage;
PCB_Q_t *Ready_q = &Ready_q_storage;
PCB_t *Running = 0;
uint32_t next_pid = 1;

// Fixed-size pools are used because this bare-metal environment has no malloc.
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
    // Allocate a 1024-word stack for the new process.
    uint64_t *stackptr = alloc_stack(1024);
    if (stackptr == 0) {
        return -1;
    }

    // Start at the top of the stack and build the initial saved-register frame.
    uint64_t *sp = stackptr + 1024;

    // Zero x0-x30 plus the saved PSTATE slot expected by restore_context.
    for (int i = 0; i <= 32; i++) {
        sp--;
        *sp = 0;
    }

    // Place the entry function where x30/LR will be restored from.
    *(sp + 30) = (uint64_t)code_address;

    // Allocate and initialize the PCB for this process.
    PCB_t *pcb = alloc_pcb();
    if (pcb == 0) {
        return -1;
    }

    pcb->sp = (uint64_t)sp;
    pcb->pid = next_pid++;
    pcb->next = 0;

    // New processes enter the ready queue in FIFO order.
    q_enqueue(Ready_q, pcb);

    /* no errors occured */
    return 0;
}

void dispatch_select(void) {
    // Pick the next ready process to become Running.
    Running = q_dequeue(Ready_q);
}

extern void restore_context(void);

void dispatch_restore(void) {
    // Convenience wrapper around the assembly restore label.
    asm volatile("b restore_context");
    __builtin_unreachable();
}

static int is_prime(unsigned long long n) {
    // Simple brute-force prime test used by each process.
    if (n < 2ULL) {
        return 0;
    }

    unsigned long long half = n / 2ULL;
    for (unsigned long long divisor = 2ULL; divisor <= half; divisor++) {
        if ((n % divisor) == 0ULL) {
            return 0;
        }
    }

    return 1;
}

// Draw the process window and show its initial value. Then loop forever, updating the value and yielding to other processes.
int p1(void) {
    static char message[] = "Process 1: 0";
    unsigned long long num = 1ULL;
    unsigned int count = 0;

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
    }
}

int p2(void) {
    static char message[] = "Process 2: 0";
    unsigned long long num = 1ULL;
    unsigned int count = 0;

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
    }
}

int p3(void) {
    static char message[] = "Process 3: 0";
    unsigned long long num = 1ULL;
    unsigned int count = 0;

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
    }
}

int p4(void) {
    static char message[] = "Process 4: 0";
    unsigned long long num = 1ULL;
    unsigned int count = 0;

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
    }
}