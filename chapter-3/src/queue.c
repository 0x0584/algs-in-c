#include "../include/ch3.h"

queue_t initqueue(void) {
    queue_t q = malloc(sizeof *q);

    q->head = malloc(sizeof *(q->head));
    q->z = malloc(sizeof *(q->z));

    q->head->next = q->z;
    q->z = q->z;

    return q;
}

void put(int val, queue_t que) {
    qnode_t new_z = malloc(sizeof *new_z);

    que->z->data = val;
    new_z->next = new_z;
    
}

int get(queue_t que) {
    if (que->head->next == que->z) {
	return INT_MAX;		/* queue is empty */
    }
    
    qnode_t foo = que->head;
    int data = foo->next->data;

    que->head = foo->next;
    free(foo);
    
    return data;
}

bool_t isemptyqueue(queue_t que) {
    return que->head->next == que->z;
}

void freequeue(queue_t que) {
    while (!isemptyqueue(que)) {
	get(que);
    }

    free(que->head);
    free(que->z);
    free(que);
}
