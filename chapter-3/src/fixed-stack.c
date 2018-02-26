#include "../include/ch3.h"

fstack initfstack(unsigned size) {
    fstack head;

    head = malloc(sizeof *head);
    head->limit = ++size;
    head->size = 0;
    head->data = malloc(size * sizeof(int));

    return head;
}

void pushfstack(int val, fstack head) {
    if (head->size < head->limit) {
	head->data[head->size++] = val;
    }
}

int popfstack(fstack head) {
    return head->size ? head->data[--(head->size)] : INT_MAX;
}

bool_t isemptyfstack(fstack head) {
    return !head->size;
}

void freefstack(fstack head) {
    free(head->data);
    free(head);
}
