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

typedef struct LINKED_LIST {
    struct LINKED_LIST *next, *prev;
    int data;
} *list_t;

typedef struct PARALLEL_ARRAY {
    unsigned size, limit;
    unsigned *next, head, z;
    int *data;
} *para_list;

typedef struct STACK_NODE {
    struct STACK_NODE *next;
    int data;
} *snode_t;

/* ----------- prototypes ----------- */
bool_t isprime(unsigned __number);
void sieve_of_eratosthenes(bool_t *__array, unsigned __sz);
list_t kill(unsigned __npeople, unsigned __tour);

/* ----------- list operations ----------- */
void initlist(list_t *__head, list_t *__tail);
list_t insertafter(list_t __node, int __value);
int delnext(list_t __node);
void printlist(list_t __head);
void freelist(list_t __head); 

/* ----------- parallel lists ----------- */
para_list initpara(unsigned __size);
int paradelnext(unsigned __index, para_list __list);
bool_t parainsertafter(unsigned __node, int __val, para_list __list);
void freepara(para_list __list);
void printpara(para_list __list);

/* ----------- pushdown stacks ----------- */
void initstack(snode_t *__head, snode_t *__tail);
void push(int value, snode_t __head);
int pop(snode_t __head);
bool_t isempty(snode_t __head, snode_t __tail);
void freestack(snode_t __head, snode_t __tail);
#endif
