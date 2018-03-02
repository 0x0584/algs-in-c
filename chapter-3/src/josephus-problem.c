/* FILE: 	josephus-problem.c
 * AUTHOR: 	ANAS RCHID
 * DESCRIPTION:	problem mferweh
 * 
 * CREATION:	02/25/2018
 * MODIFIED:	02/25/2018
 */
#include "../include/ch3.h"

/* there would be no easy way without doubly linked lists */
list_t kill(unsigned npeople, unsigned deathorder) {
    list_t list = initlist(); 

    list->head->data = 1;
    list->head->next = list->z;

    for (unsigned i = (npeople - 1); i > 1; --i) {
        addafter(list->head, i);
    }

    list->z->next = list->head;
    list->z->data = npeople;
    list->head = list->z;
    
    node_t tmp = NULL;
    list_t order = initlist();
    
    while (list->head != list->head->next) {
	for (unsigned i = 0; i < (deathorder - 1); ++i) {
	    list->head = list->head->next;
	}
	
	tmp = list->head->next;
	list->head->next = list->head->next->next;	
	addafter(order->head, tmp->data);
	free(tmp);
    }

    addafter(order->head, list->head->data);
    free(list->head);
    
    return order;
}
