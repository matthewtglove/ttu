/*
Create core type definitions in process.h:
1. Add includes for fixed-width types.
2. Define PCB_t with first member sp (uint64_t), second member pid (uint32_t), plus next pointer for queue linking.
3. Define PCB_Q_t with head and tail pointers.
4. Declare globals Ready_q, Running, and next_pid.
5. Declare prototypes for spawn_process, dispatch_select, dispatch, go, q_enqueue, q_dequeue, and process entry functions p1-p4.
6. Declare external APIs expected from libos.a (alloc_stack, alloc_pcb, q_init) and screen helpers used by kernel logic.
*/

#ifndef PROCESS_H
#define PROCESS_H

#include <stdint.h>

// Define the process control block (PCB) structure
typedef struct pcb {
    uint64_t sp;      // Stack pointer
    uint32_t pid;     // Process ID
    struct pcb *next; // Pointer to next PCB in queue
} PCB_t;

// Define the process queue structure
typedef struct PCB_Q_t {
    PCB_t *head;
    PCB_t *tail;
} PCB_Q_t;

// Declare global variables
extern PCB_Q_t *Ready_q;
extern PCB_t *Running;
extern uint32_t next_pid;

// Declare function prototypes
int spawn_process(int (*pfun)());
void dispatch_select(void);
void dispatch_restore(void);
void dispatch(void);

void q_enqueue(PCB_Q_t *q, PCB_t *pcb);
PCB_t *q_dequeue(PCB_Q_t *q);

// Declare process entry functions
int p1(void);
int p2(void);
int p3(void);
int p4(void);

// Declare external APIs from libos.a
uint64_t *alloc_stack(uint64_t stack_size);
PCB_t *alloc_pcb();
void q_init(PCB_Q_t *q);

#endif