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
#define LIMIT				(1000/2)
#define PARA_SIZE			(20)

int main(void) {
    bool_t numbers[] = {
	[0 ... 1] = false,
	[2 ... LIMIT] = true
    };

    /*
    puts("\n----------------- my prime -----------------\n");
    for (unsigned i = 0; i < LIMIT + 1; ++i) {
	printf("%u is %sprime%8c", i,
	       isprime(i) ? "" : "not ",
	       (i+1)%3 ? '\t' : '\n');
    }
    */

    sieve_of_eratosthenes(numbers, LIMIT);

    /* 
    puts("\n----------- Sieve of Eratosthenes -----------\n");
    for (unsigned i = 0; i < LIMIT + 1; ++i) {
	printf("%u is %sprime%8s", i,
	       numbers[i] ? "" : "not ",
	       (i+1)%3? "\t" : "\n");   
    }
    */ 

    /*
    puts("\n-------------- list operations ---------------\n");
    list_t head, z;

    
    initlist(&head, &z);

    insertafter(head, 5);
    insertafter(head, 9);
    insertafter(head, 11);
    printlist(head);

    delnext(head);
    printlist(head);

    freelist(head);
    */

    /*
    puts("\n-------------- josephus problem ---------------\n");
    list_t foo = kill(9, 5);
    printlist(foo);
    freelist(foo);
    */

    /*
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
    */

    puts("\n-------------- pushdown stacks ---------------\n");
    snode_t head, z;

    initstack(&head, &z);

    push(5, head);
    push(5, head);
    push(5, head);
    
    printf("5x5x5 is %d\n", pop(head) * pop(head) * pop(head));

    push(7, head);
    freestack(head, z);
    
    return 0;
}
