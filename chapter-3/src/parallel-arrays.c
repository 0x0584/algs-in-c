#include "../include/ch3.h"

para_list initpara(unsigned length) {
    para_list list = malloc(sizeof *list);

    /* init size plus head and tail */
    list->data.limit = list->next.limit = (length + 2);

    /* allocate the memory */
    list->data.elem = malloc((length + 2) * sizeof(int));
    list->next.elem = malloc((length + 2) * sizeof(unsigned));

    /* init indexes */
    list->head = 0;
    list->z = 1;
    list->size = 2;

    /* init "links" */
    list->next.elem[list->head] = list->z;
    list->next.elem[list->z] = list->z;

    /* init data */
    list->data.elem[list->z] = list->data.elem[list->head] = -1;
    
    return list;
}

void printpara(para_list list) {
    puts("-----------");
    for (unsigned i = 0; i < (list->size); ++i) {
	printf("%u has value of %d\tand points to %d \n", i,
	       list->data.elem[i],
	       list->next.elem[i]);
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
    
    int data = list->next.elem[index];

    /* override the previous link */
    list->next.elem[index] = list->next.elem[list->next.elem[index]];
    list->size--;

    return data;
}

bool_t parainsertafter(unsigned node, int val, para_list list) {
    if (list->size == list->data.limit) {
	puts("list is full");
	return false;
    }
    
    /* insert and edit links */
    list->data.elem[list->size] = val;
    list->next.elem[list->size] = list->next.elem[node];
    list->next.elem[node] = list->size;

    list->size++;		/* increase the size*/

    return true;
}

void freepara(para_list list) {
    free(list->data.elem);
    free(list->next.elem);
    free(list);
}
