#include "../include/ch3.h"

void initstack(snode_t *head, snode_t *z) {
    *head = malloc(sizeof **head);
    *z = malloc(sizeof **z);
    (*head)->next = *z;
    (*head)->data = 0;
    (*z)->next = *z;
}

void push(int val, snode_t head) {
    snode_t bar = malloc(sizeof *bar);

    bar->data = val;
    bar->next = head->next;
    head->next = bar;
}

int pop(snode_t head) {
    snode_t origin = head->next; /* get the node next to the head */
    int bar;
    
    head->next = origin->next;	/* move the head one step */
    bar = origin->data;		/* get the data from the original node */

    free(origin);		/* free the node */
    
    return bar;
}

bool_t isempty(snode_t head, snode_t z) {
    return head->next == z;
}

void freestack(snode_t head, snode_t z) {
    while (!isempty(head, z)) {
	pop(head);
    }
    free(z);
    free(head);
}
