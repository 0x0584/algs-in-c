/* FILE: 	josephus-problem.c
 * AUTHOR: 	ANAS RCHID
 * DESCRIPTION:	problem mferweh
 * 
 * CREATION:	02/25/2018
 * MODIFIED:	02/25/2018
 */
#include "../include/ch3.h"

/* there would be no easy way without doubly linked lists */
list_t kill(unsigned n, unsigned m) {
    list_t head = malloc(sizeof *head),
	tail = malloc(sizeof *tail);

    head->data = 1;
    head->next = tail;
    for (unsigned i = (n - 1); i > 1; --i) {
	insertafter(head, i);
    }

    tail->next = head;
    tail->data = n;
    head = tail;
    
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
    free(head);
    
    return h;
}
