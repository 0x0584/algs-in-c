#include "../include/ch3.h"

fstack_t initfstack(unsigned length) {
    fstack_t head;

    head = malloc(sizeof *head);
    head->limit = ++length;
    head->size = 0;
    head->data = malloc(length * sizeof(int));

    return head;
}

void pushfstack(int val, fstack_t head) {
    if (head->size < head->limit) {
	head->data[head->size++] = val;
    }
}

int popfstack(fstack_t head) {
    return head->size ? head->data[--(head->size)] : INT_MAX;
}

bool_t isemptyfstack(fstack_t head) {
    return !head->size;
}

void freefstack(fstack_t head) {
    free(head->data);
    free(head);
}
