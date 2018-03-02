#include "../include/ch3.h"

char *topolish(const char *equ) {
    stack_t stack = initstack();
    unsigned size = 10;
    char *expr = malloc(size * sizeof(char));
    unsigned i = 0;

    while (*equ) {

	unless ((i + 1) % size) {
	    expr = realloc(expr, i + size);
	}
	
	switch (*equ) {
	case '(':
						break;
	case ')':
	    expr[i++] = ' ';
	    expr[i++] = (char) pop(stack);
	    expr[i++] = ' ';
						break;
	case '+': 
	case '-': 
	case '*': 
	case '/':
	    push(*equ, stack);
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
    expr[i] = pop(stack);

    freestack(stack);
    
    return expr;
}
