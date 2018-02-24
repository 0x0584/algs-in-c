/* FILE: 	binary.c
 * AUTHOR: 	ANAS RCHID
 * DESCRIPTION:	binary equivalent of a number
 * 
 * CREATION:	02/24/2018
 * MODIFIED:	02/24/2018 
 */

#include "../include/ch2.h"
#include <stdio.h>

#define BYTE			    (8)
#define SIZE			    (4 * BYTE)

unsigned long binary(int num) {
    unsigned long binary = 0;
    unsigned index = 0;
    char two_power[SIZE + 1] = { '\0' };

    /* initialize the binary form */
    /* two_power[0] = '\0'; */

    while (num > 0) {
	index = strlength(two_power);
	two_power[index] = '0' + (num % 2);	
	two_power[index + 1] = '\0';
	num /= 2;
    }

    for (unsigned i = 0; i <= index; ++i) {
	/* printf("(%.0f:%s) %ld - ", power(10, i), */
	/*        (two_power[i] == '1') ? "true" : "false", binary); */
	/* return int as unsigned long in form of binary */
	binary += (two_power[i] == '1') ? power(10, i) : 0;
	/* printf("%ld\n", binary); */
    }
    
    return binary;
}
