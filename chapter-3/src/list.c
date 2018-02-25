#include "../include/ch3.h"

void initlist(list_t *head, list_t *z) {
    *head = malloc(sizeof **head);
    *z = malloc(sizeof **z);

    (*head)->next = *z;
    (*z)->next = *z;
}

int delnext(list_t foo) {
    list_t bar = foo->next;
    int data = bar->data;

    foo->next = foo->next->next;
    free(bar);
    
    return data;
}

list_t insertafter(list_t foo, int val) {
    list_t bar = malloc(sizeof *bar);

    bar->data = val;
    bar->next = foo->next;
    foo->next = bar;

    return bar;
}

void printlist(list_t head) {
    list_t tmp = head->next;
    unsigned i = 0;

    puts("---------");
    while (tmp != tmp->next) {
	printf("%d position %d\n", i++, tmp->data);
	tmp = tmp->next;	
    }
    puts("---------");
}

void freelist(list_t head) {
    list_t tmp;
    
    while (head) {
	tmp = head;
	head = head->next;

	if (tmp == head) break;
	free(tmp);
    }
}    

