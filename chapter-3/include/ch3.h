#if !defined __CHAPER_3_H
#define __CHAPTER_3_H
#define unless(x)		if(!(x))
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/* ----------- types ----------- */
typedef enum BOOLEAN {
    false = (1==0),
    true = !false
} bool_t;

typedef struct LIST_NODE {
    struct LIST_NODE *next, *prev;
    int data;
} *lnode_t;

typedef struct PARALLEL_ARRAY {
    unsigned size, limit;
    unsigned *next, head, z;
    int *data;
} *para_list;

typedef struct STACK_NODE {
    struct STACK_NODE *next;
    int data;
} *snode_t;

typedef struct FIXED_SIZE_STACK {
    unsigned size, limit;
    int *data;
} *fstack_t;

typedef struct FIXED_SIZE_QUEUE {
    unsigned size, limit;
    unsigned head, z;
    int *data;
} *fqueue_t;

typedef snode_t qnode_t;

typedef struct QUEUE {
    qnode_t head, z;
} *queue_t;

/* ----------- prototypes ----------- */
bool_t isprime(unsigned __number);
void sieve_of_eratosthenes(bool_t *__array, unsigned __sz);
lnode_t kill(unsigned __npeople, unsigned __tour);
char *topolish(const char *__equation);

/* ----------- list operations ----------- */
void initlist(lnode_t *__head, lnode_t *__tail);
lnode_t insertafter(lnode_t __node, int __value);
int delnext(lnode_t __node);
void printlist(lnode_t __head);
void freelist(lnode_t __head); 

/* ----------- parallel lists ----------- */
para_list initpara(unsigned __length);
int paradelnext(unsigned __index, para_list __list);
bool_t parainsertafter(unsigned __node, int __val, para_list __list);
void freepara(para_list __list);
void printpara(para_list __list);

/* ----------- pushdown stacks ----------- */
void initstack(snode_t *__head, snode_t *__tail);
void push(int value, snode_t __head);
int pop(snode_t __head);
bool_t isemptystack(snode_t __head, snode_t __tail);
void freestack(snode_t __head, snode_t __tail);

/* ----------- fixed size stacks ----------- */
fstack_t initfstack(unsigned __length);
void pushfstack(int __value, fstack_t __stack);
int popfstack(fstack_t __stack);
bool_t isemptyfstack(fstack_t __stack);
void freefstack(fstack_t __stack);

/* ----------- queues ----------- */
queue_t initqueue(void);
void put(int value, queue_t __queue);
int get(queue_t __queue);
bool_t isemptyqueue(queue_t __queue);
void freequeue(queue_t __queue);

/* ----------- fixed size queues ----------- */
fqueue_t initfqueue(unsigned __length);
void putfqueue(int __value, fqueue_t __queue);
int getfqueue(fqueue_t __queue);
bool_t isemptyfqueue(fqueue_t __queue);
void freefqueue(fqueue_t __queue);

#endif
