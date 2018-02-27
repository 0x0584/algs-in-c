/* FILE: 	main.c
 * AUTHOR: 	ANAS RCHID
 * DESCRIPTION:	testings of chapter 3
 * 
 * CREATION:	02/25/2018
 * MODIFIED:	02/25/2018
 */

#include <stdio.h>
#include <stdlib.h>

#include "../include/ch3.h"
#define LIMIT				(101)
#define PARA_SIZE			(20)
#define FIXED_SIZE			(10)

int main(void) {
    /*
    bool_t numbers[] = {
	[0 ... 1] = false,
	[2 ... LIMIT] = true
    };

    puts("\n----------------- my prime -----------------\n");
    for (unsigned i = 0; i < LIMIT + 1; ++i) {
	printf("%u is %sprime%8c", i,
	       isprime(i) ? "" : "not ",
	       (i+1)%3 ? '\t' : '\n');
    }

    sieve_of_eratosthenes(numbers, LIMIT);

    
    puts("\n----------- Sieve of Eratosthenes -----------\n");
    for (unsigned i = 0; i < LIMIT + 1; ++i) {
	printf("%u is %sprime%8s", i,
	       numbers[i] ? "" : "not ",
	       (i+1)%3? "\t" : "\n");   
    } 

    
    puts("\n-------------- list operations ---------------\n");
    lnode_t lhead, lz;

    initlist(&lhead, &lz);

    insertafter(lhead, 5);
    insertafter(lhead, 9);
    insertafter(lhead, 11);
    printlist(lhead);

    delnext(lhead);
    printlist(lhead);

    freelist(lhead);

    
    puts("\n-------------- josephus problem ---------------\n");
    lnode_t foo = kill(9, 5);
    printlist(foo);
    freelist(foo);

    
    puts("\n-------------- parallel lists ---------------\n");

    para_list para = initpara(PARA_SIZE);
    printpara(para);

    parainsertafter(0, 5, para);
    parainsertafter(para->head, 48, para);
    parainsertafter(para->head, 62, para);
    parainsertafter(para->head, 12, para);
    parainsertafter(para->head, 11, para);
    printpara(para);

    paradelnext(para->next[para->head], para);
    paradelnext(para->head, para);
    printpara(para);

    
    freepara(para);

    puts("\n-------------- pushdown stacks ---------------\n");
    snode_t head, z;

    initstack(&head, &z);

    push(5, head);
    push(5, head);
    push(5, head);
    
    printf("5x5x5 is %d\n", pop(head) * pop(head) * pop(head));
    printf("stack is: %s\n", isemptystack(head, z) ? "t" : "nil");
    
    push(7, head);
    printf("stack is: %s\n", isemptystack(head, z) ? "t" : "nil");
    
    freestack(head, z);

    puts("\n-------------- reverse polish notation ---------------\n");
    char *str = topolish("((1 + 5) * (3 - 2)) + (1 - 2)");
    puts(str);
    free(str);

    puts("\n-------------- fixed size stacks ---------------\n");

    fstack_t fixed = initfstack(50);

    pushfstack(5, fixed);
    pushfstack(3, fixed);
    puts(isemptyfstack(fixed) ? "t":"nil");
    
    printf("%d\n", popfstack(fixed)*popfstack(fixed));
    puts(isemptyfstack(fixed) ? "t":"nil");
    
    freefstack(fixed);
    */

    fqueue_t q = initfqueue(FIXED_SIZE);

    putfqueue(5, q);
    putfqueue(15, q);
    putfqueue(25, q);

    printf("is queue empty? %s\n", isemptyfqueue(q) ? "t" : "nil");
    printf("%d\n", getfqueue(q) + getfqueue(q));
    printf("%d\n", getfqueue(q));
    printf("is queue empty? %s\n", isemptyfqueue(q) ? "t" : "nil");
	
    freefqueue(q);
    
    return 0;
}
