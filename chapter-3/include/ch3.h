#if !defined __CHAPER_3_H
#define __CHAPTER_3_H
#define unless(x)		if(!(x))
#define NULL			((void *)0)

/* ----------- types ----------- */
typedef enum BOOLEAN {
    false = (1==0),
    true = !false
} bool_t;

typedef struct LINKED_LIST {
    struct LINKED_LIST *next, *prev;
    int data;
} *list_t;

/* ----------- prototypes ----------- */
bool_t isprime(unsigned __number);
void sieve_of_eratosthenes(bool_t *__array, unsigned __sz);

/* ----------- list operations ----------- */
void initlist(list_t *__head, list_t *__tail);
list_t insertafter(list_t __node, int __value);
void delnext(list_t __node);
void printlist(list_t __head);
void freelist(list_t __head); 

#endif
