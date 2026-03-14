#include "process.h"

void q_enqueue(PCB_Q_t *q, PCB_t *pcb) {
    // If the queue is empty, set head and tail to the new PCB
    if (q->head == 0) {
        q->head = pcb;
        q->tail = pcb;
    } else {
        // Otherwise, add the new PCB to the end of the queue and update the tail
        q->tail->next = pcb;
        q->tail = pcb;
    }
    // Ensure the new tail's next pointer is 0
    pcb->next = 0;
}

PCB_t *q_dequeue(PCB_Q_t *q) {
    // If the queue is empty, return NULL
    if (q->head == 0) {
        return 0;
    }

    PCB_t *dequeued_pcb = q->head;

    // Move the head pointer to the next PCB in the queue
    q->head = q->head->next;

    // If the queue is now empty, set the tail to NULL as well
    if (q->head == 0) {
        q->tail = 0;
    }

    // Return the dequeued PCB
    return dequeued_pcb;
}