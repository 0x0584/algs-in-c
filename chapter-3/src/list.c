#include "../include/ch3.h"

list_t initlist(void) {
    list_t list = malloc(sizeof *list);

    list->head = malloc(sizeof *(list->head));
    list->z = malloc(sizeof *(list->z));

    /* initialize the head */
    list->head->next = list->z;

    /* and also the tail */
    list->z->next = list->z;

    return list;
}

int rmnext(node_t node) {
    node_t next = node->next;
    int data = next->data;	/* get the data */

    node->next = next->next; /* move one further this node */
    
    free(next);			/* free the next node */
    
    return data;		/* return the data */
}

node_t addafter(node_t node, int val) {
    node_t new = malloc(sizeof *new);

    new->data = val;		/* set up the new node */
    
    new->next = node->next;	/* set the new node to point on the next */
    node->next = new;		/* and this one to new node */

    return new;			/* return the new node */
}

void putlist(list_t list) {
    node_t tmp = list->head->next;
    unsigned i = 0;

    puts("---------");
    while (tmp != tmp->next) {
	printf("%d position %d\n", i++, tmp->data);
	tmp = tmp->next;	
    }
    puts("---------");
}

bool_t isemptylist(list_t list) {
    return list->head->next == list->z;
}

void freelist(list_t list) {
    node_t tmp;
    
    while (list->head) {
	tmp = list->head;
	list->head = list->head->next;

	if (tmp == list->head) break;
	free(tmp);
    }
}    

