#include "../include/ch3.h"

void initlist(lnode_t *head, lnode_t *z) {
    *head = malloc(sizeof **head);
    *z = malloc(sizeof **z);

    (*head)->next = *z;
    (*z)->next = *z;
}

int delnext(lnode_t foo) {
    lnode_t bar = foo->next;
    int data = bar->data;

    foo->next = foo->next->next;
    free(bar);
    
    return data;
}

lnode_t insertafter(lnode_t foo, int val) {
    lnode_t bar = malloc(sizeof *bar);

    bar->data = val;
    bar->next = foo->next;
    foo->next = bar;

    return bar;
}

void printlist(lnode_t head) {
    lnode_t tmp = head->next;
    unsigned i = 0;

    puts("---------");
    while (tmp != tmp->next) {
	printf("%d position %d\n", i++, tmp->data);
	tmp = tmp->next;	
    }
    puts("---------");
}

void freelist(lnode_t head) {
    lnode_t tmp;
    
    while (head) {
	tmp = head;
	head = head->next;

	if (tmp == head) break;
	free(tmp);
    }
}    

