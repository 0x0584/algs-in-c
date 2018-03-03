#include "../include/ch3.h"

stack_t initstack(void) {
    stack_t s;
    s = malloc(sizeof *s);
    s->head = malloc(sizeof *(s->head));
    s->z = malloc(sizeof *(s->z));

    s->head->next = s->z;
    s->head->data = -1;		/* non sense data */
    
    s->z->next = s->z;

    return s;
}

void push(int val, stack_t stack) {
    node_t new = malloc(sizeof *new);

    new->data = val;
    new->next = stack->head->next; /* point to the old one */
    stack->head->next = new;	   /* set the new first node */
}

int pop(stack_t ss) {
    node_t old = ss->head->next; /* get the node next to the head */
    
    ss->head->next = old->next; /* move the head one step */
    int data = old->data;	/* get the data from the old */
    free(old);			/* free the old node */
    
    return data;
}

bool_t isemptystack(stack_t ss) {
    return ss->head->next == ss->z;
}

void freestack(stack_t  ss) {
    while (!isemptystack(ss)) {
	pop(ss);		/* pop out everything */
    }
    
    free(ss->z);
    free(ss->head);
}
