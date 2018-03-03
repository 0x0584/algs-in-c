#if !defined __CHAPER_3_H
#define __CHAPTER_3_H
#define unless(x)		if(!(x))
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef enum BOOLEAN {
    false = (1==0),
    true = !false
} bool_t;

typedef struct ARRAY {
    unsigned limit;
    int *elem;
} array_t;

typedef struct NODE {
    struct NODE *next;
    int data;
} *node_t;

/* static structure using arrays */
typedef struct FIXED_SIZE {
    array_t next;		/* used only by parallel arrays */
    array_t data;
    unsigned size, head, z;
} *fixed_t;

typedef fixed_t para_list;	/* parallel arrays: static linked lists */
typedef fixed_t fstack_t;	/* static stack */
typedef fixed_t fqueue_t;	/* static queue */

/* dynamic structure using pointers */
typedef struct LIST {
    node_t head, z;
} *list_t;

typedef list_t stack_t;		/* dynamic-size stack */
typedef list_t queue_t;		/* dynamic-size queues */

/* ----------- prototypes ----------- */
bool_t isprime(unsigned __number);
void sieve_of_eratosthenes(array_t __numbers);
list_t kill(unsigned __npeople, unsigned __deathorder);
char *topolish(const char *__equation);

/* ----------- list operations ----------- */
list_t initlist(void);
node_t addafter(node_t __node, int __value);
int rmnext(node_t __node);
void putlist(list_t __list);
void freelist(list_t __list); 

/* ----------- parallel lists ----------- */
para_list initpara(unsigned __length);
int paradelnext(unsigned __index, para_list __list);
bool_t parainsertafter(unsigned __node, int __val, para_list __list);
void freepara(para_list __list);
void printpara(para_list __list);

/* ----------- pushdown stacks ----------- */
stack_t initstack(void);
void push(int value, stack_t __stack);
int pop(stack_t __stack);
bool_t isemptystack(stack_t __stack);
void freestack(stack_t stack);

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
