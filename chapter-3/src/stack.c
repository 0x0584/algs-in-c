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

bool_t isemptystack(snode_t head, snode_t z) {
    return head->next == z;
}

void freestack(snode_t head, snode_t z) {
    while (!isemptystack(head, z)) {
	pop(head);
    }
    free(z);
    free(head);
}

char *topolish(const char *equ) {
    snode_t head, z;
    unsigned size = 10;
    char *expr = malloc(size * sizeof(char));
    unsigned i = 0;

    initstack(&head, &z);
    while (*equ) {

	unless ((i + 1) % size) {
	    expr = realloc(expr, i + size);
	}
	
	switch (*equ) {
	case '(':
						break;
	case ')':
	    expr[i++] = ' ';
	    expr[i++] = (char) pop(head);
	    expr[i++] = ' ';
						break;
	case '+': 
	case '-': 
	case '*': 
	case '/':
	    push(*equ, head);
						break;
	default:
	    if (*equ != ' ') {
		expr[i++] = *equ;
		expr[i++] = ' ';
	    }
						break;
	}
	
	++equ;
    }

    expr[i++] = ' ';
    expr[i] = pop(head);

    freestack(head, z);
    
    return expr;
}
