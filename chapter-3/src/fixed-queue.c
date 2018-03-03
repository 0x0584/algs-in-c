#include "../include/ch3.h"

fqueue_t initfqueue(unsigned length) {
    fqueue_t que = malloc(sizeof *que);

    que->data.limit = ++length;
    que->data.elem = malloc(length * sizeof(int));
    que->head = 0;
    que->z = 0;
    que->size = 0;

    return que;
}

void putfqueue(int val, fqueue_t que) {
    que->data.elem[que->z++] = val;
    que->size++;
	
    if (que->z == que->data.limit) {
	que->z = que->size = 0;	
    } 
}

int getfqueue(fqueue_t que) {
    int tmp = que->data.elem[que->head++];
    
    if (que->head == que->data.limit) {
	que->head = que->size = 0;
    }

    return tmp;
}

bool_t isemptyfqueue(fqueue_t que) {
    return que->head == que->z;
}

void freefqueue(fqueue_t que) {
    free(que->data.elem);
    free(que);
}
