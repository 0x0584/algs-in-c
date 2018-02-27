#include "../include/ch3.h"

queue_t initqueue(void) {
    queue_t q = malloc(sizeof *q);

    q->head = malloc(sizeof *(q->head));
    q->z = malloc(sizeof *(q->z));

    q->head->next = q->z;
    q->head->data = -1;
    
    
    /* the tail is always pointing to the last node */
    q->z->next = NULL;
    q->z->data = -1;

    return q;
}

void put(int val, queue_t que) {
    qnode_t new = malloc(sizeof *new);
    qnode_t last = que->z->next;

    /* setup the new node */
    new->data = val;
    new->next = que->z;
    que->z->next = new;

    if (last) last->next = new;
    else que->head->next = new;
}

int get(queue_t que) {
    if (que->head->next == que->z) {
	return INT_MAX;		/* queue is empty */
    }
    
    qnode_t oldhead = que->head;
    int data = oldhead->next->data;

    que->head = oldhead->next;
    free(oldhead);
    
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
