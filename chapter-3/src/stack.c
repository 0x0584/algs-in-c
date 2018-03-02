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
    node_t bar = malloc(sizeof *bar);

    bar->data = val;
    bar->next = stack->head->next;
    stack->head->next = bar;
}

int pop(stack_t ss) {
    node_t origin = ss->head->next; /* get the node next to the head */
    int bar;
    
    ss->head->next = origin->next; /* move the head one step */
    bar = origin->data;	     /* get the data from the original node */

    free(origin);		/* free the node */
    
    return bar;
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
