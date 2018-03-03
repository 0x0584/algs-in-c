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
    puts("\n----------------- my prime -----------------\n");
    for (unsigned i = 0; i < LIMIT + 1; ++i) {
    	printf("%u is %sprime%8c", i,
    	       isprime(i) ? "" : "not ",
    	       (i+1)%3 ? '\t' : '\n');
    }
    */
    

    /*
    bool_t numbers[] = {
	[0 ... 1] = false,
	[2 ... LIMIT] = true
    };
    array_t primes = { LIMIT, (int *) &numbers };
    sieve_of_eratosthenes(primes);
    
    puts("\n----------- Sieve of Eratosthenes -----------\n");
    for (unsigned i = 0; i < LIMIT + 1; ++i) {
	printf("%u is %sprime%8s", i,
	       numbers[i] ? "" : "not ",
	       (i+1)%3? "\t" : "\n");   
    } 
    */
	
    /*
    puts("\n-------------- list operations ---------------\n");
    list_t list = initlist();
    node_t thisone = addafter(list->head, 5);
    addafter(list->head, 9);
    addafter(list->head, 11);
    addafter(thisone, 69);
	
    putlist(list);

    rmnext(list->head);
    rmnext(thisone);
    putlist(list);

    freelist(list);
    */
    
    /*
    puts("\n-------------- josephus problem ---------------\n");
    list_t suicide_order = kill(9, 5);
    putlist(suicide_order);
    freelist(suicide_order);
    */

    puts("\n-------------- parallel lists ---------------\n");

    para_list para = initpara(PARA_SIZE);
    printpara(para);

    parainsertafter(0, 5, para);
    parainsertafter(para->head, 48, para);
    parainsertafter(para->head, 62, para);
    parainsertafter(para->head, 12, para);
    parainsertafter(para->head, 11, para);
    printpara(para);

    paradelnext(para->next.elem[para->head], para);
    paradelnext(para->head, para);
    printpara(para);

    
    freepara(para);

    /*
    puts("\n-------------- pushdown stacks ---------------\n");
    stack_t ss = initstack();

    push(5, ss);
    push(5, ss);
    push(5, ss);
    
    printf("5x5x5 is %d\n", pop(ss) * pop(ss) * pop(ss));
    printf("stack is: %s\n", isemptystack(ss) ? "t" : "nil");
    
    push(7, ss);
    printf("stack is: %s\n", isemptystack(ss) ? "t" : "nil");
    
    freestack(ss);
    */

    /*
    puts("\n-------------- reverse polish notation ---------------\n");
    char *str = topolish("((1 + 5) * (3 - 2)) + (1 - 2)");
    puts(str);
    free(str);
    */

    /*
    puts("\n-------------- fixed size stacks ---------------\n");

    fstack_t fixed = initfstack(50);

    pushfstack(5, fixed);
    pushfstack(3, fixed);
    puts(isemptyfstack(fixed) ? "t":"nil");
    
    printf("%d\n", popfstack(fixed)*popfstack(fixed));
    puts(isemptyfstack(fixed) ? "t":"nil");
    
    freefstack(fixed);
    */

    /*
    puts("\n-------------- fixed size queue ---------------\n");
    fqueue_t q = initfqueue(FIXED_SIZE);

    putfqueue(5, q);
    putfqueue(15, q);
    putfqueue(25, q);

    printf("is queue empty? %s\n", isemptyfqueue(q) ? "t" : "nil");
    printf("%d\n", getfqueue(q) + getfqueue(q));
    printf("%d\n", getfqueue(q));
    printf("is queue empty? %s\n", isemptyfqueue(q) ? "t" : "nil");
	
    freefqueue(q);
    */

    /*
    puts("\n-------------- queue ---------------\n");

    queue_t qu = initqueue();

    put(10, qu);
    put(11, qu);
    put(12, qu);

    printf("%d\n", get(qu) + get(qu));
    puts(isemptyqueue(qu)? "t" : "nil");

    printf("%d\n", get(qu));
    printf("%d\n", get(qu));

    puts(isemptyqueue(qu)? "t" : "nil");
    
    freequeue(qu);
    */
    
    return 0;
}
