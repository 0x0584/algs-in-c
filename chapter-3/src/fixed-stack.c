#include "../include/ch3.h"

fstack_t initfstack(unsigned length) {
    fstack_t head;

    head = malloc(sizeof *head);
    head->data.limit = ++length;
    head->data.elem = malloc(length * sizeof(int));
    head->size = 0;

    return head;
}

void pushfstack(int val, fstack_t head) {
    if (head->size < head->data.limit) {
	head->data.elem[head->size++] = val;
    }
}

int popfstack(fstack_t head) {
    return head->size ? head->data.elem[--(head->size)] : INT_MAX;
}

bool_t isemptyfstack(fstack_t head) {
    return !head->size;
}

void freefstack(fstack_t head) {
    free(head->data.elem);
    free(head);
}
