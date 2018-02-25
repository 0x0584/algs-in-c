/* FILE: 	binary.c
 * AUTHOR: 	ANAS RCHID
 * DESCRIPTION:	binary equivalent of a number
 * 
 * CREATION:	02/24/2018
 * MODIFIED:	02/24/2018 
 */

#include "../include/ch2.h"

#define BYTE			    (8)
#define SIZE			    (4 * BYTE)
#define _ITEM(x)		    [x] = #x

unsigned long binary(unsigned num) {
    unsigned long binary = 0;
    unsigned index = 0;
    char two_power[] = { [0 ... SIZE] = '\0' }; /* gcc feature */
    
    while (num) {
	index = strlength(two_power);
	two_power[index] = '0' + (num % 2);	
	num /= 2;
    }

    for (unsigned i = 0; i <= index; ++i) {
	binary += (two_power[i] == '1') ? power(10, i) : 0;
    }
    
    return binary;
}
