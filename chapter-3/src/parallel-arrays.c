#include "../include/ch3.h"

para_list initpara(unsigned sz) {
    para_list list = malloc(sizeof *list);

    /* init size plus head and tail */
    list->limit = (sz + 2);

    /* allocate the memory */
    list->data = malloc((sz + 2) * sizeof(int));
    list->next = malloc((sz + 2) * sizeof(unsigned));

    /* init indexes */
    list->head = 0;
    list->z = 1;
    list->size = 2;

    /* init "links" */
    list->next[list->head] = list->z;
    list->next[list->z] = list->z;

    /* init data */
    list->data[list->z] = list->data[list->head] = -1;
    
    return list;
}

void printpara(para_list list) {
    puts("-----------");
    for (unsigned i = 0; i < (list->size); ++i) {
	printf("%u has value of %d\tand points to %u \n", i,
	       list->data[i],
	       list->next[i]);
    }
    puts("-----------");
}

int paradelnext(unsigned index, para_list list) {
    if (list->size == 2) {
	puts("list if already empty");
	return INT_MAX;
    } else if (index == list->z) {
	puts("cannot delete after tail");
	return INT_MIN;
    }
    
    int data = list->next[index];

    /* override the previous link */
    list->next[index] = list->next[list->next[index]];
    list->size--;

    return data;
}

bool_t parainsertafter(unsigned node, int val, para_list list) {
    if (list->size == list->limit) {
	puts("list is full");
	return false;
    }
    
    /* insert and edit links */
    list->data[list->size] = val;
    list->next[list->size] = list->next[node];
    list->next[node] = list->size;

    /* increase the size*/
    list->size++;

    return true;
}

void freepara(para_list list) {
    free(list->data);
    free(list->next);
    free(list);
}
