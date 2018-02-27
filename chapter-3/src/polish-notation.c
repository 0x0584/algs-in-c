#include "../include/ch3.h"

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
