/* FILE: 	josephus-problem.c
 * AUTHOR: 	ANAS RCHID
 * DESCRIPTION:	problem mferweh
 * 
 * CREATION:	02/25/2018
 * MODIFIED:	02/25/2018
 */
#include "../include/ch3.h"

/* this is implementation is done without the doubly linked list */
list_t kill(unsigned n, unsigned m) {
    list_t head = malloc(sizeof *head),
	z = malloc(sizeof *z);

    head->data = 1;
    head->next = z;
    for (unsigned i = (n - 1); i > 1; --i) {
	insertafter(head, i);
    }

    z->next = z;
    printlist(head);

    z->next = head;
    z->data = n;
    
    list_t tmp = NULL;
    list_t h = malloc(sizeof *h),
	zz = malloc(sizeof *zz);

    h->next = zz;
    zz->next = zz;
    
    while (head != head->next) {
	for (unsigned i = 0; i < (m - 1); ++i) {
	    head = head->next;
	}
	tmp = head->next;
	head->next = head->next->next;	
	insertafter(h, tmp->data);
	free(tmp);
    }
    
    insertafter(h, head->data);
    return h;
}
