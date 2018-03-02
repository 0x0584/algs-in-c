#include "../include/ch3.h"

queue_t initqueue(void) {
    queue_t que;

    /* allocation of memory */
    que = malloc(sizeof *que);
    que->head = malloc(sizeof *(que->head));
    que->z = malloc(sizeof *(que->z));

    /* initialize the header */
    que->head->next = que->z;	/* initial head pointer */
    que->head->data = -1;	/* non sense data */
    
    /* the tail is always pointing to the last node */
    que->z->next = NULL;
    que->z->data = -1;

    return que;
}

void put(int val, queue_t que) {
    node_t new = malloc(sizeof *new);
    node_t last = que->z->next; /* tail is pointing on the last node */

    /* setup the new node */
    new->data = val;
    new->next = que->z;

    que->z->next = new;		/* set tail to the new node */

    if (!last) que->head->next = new; /* the first insertion */
    else last->next = new;	      /* set new as next node */
}

int get(queue_t que) {
    /* if head points on tail, indeed, initial pointerx
     * then queue is empty */
    if (isemptyqueue(que)) return INT_MAX;

    /* retrieve data from the old head */
    node_t oldhead = que->head;
    int data = oldhead->next->data;

    que->head = oldhead->next;	/* move to the next head */
    free(oldhead);		/* free the memory */
    
    return data;		/* return the data */
}

bool_t isemptyqueue(queue_t que) {
    /* if initial head pointer, it must be false */
    return que->head->next == que->z;
}

void freequeue(queue_t que) {
    while (!isemptyqueue(que)) {
	get(que);		/* get all the elements; classic */
    }

    /* as mama said, always free all of your pointers  */
    free(que->head);
    free(que->z);
    free(que);
}
