/* FILE: 	convert.c
 * AUTHOR: 	ANAS RCHID
 * DESCRIPTION:	converts a string to number
 * 
 * CREATION:	02/24/2018
 * MODIFIED:	02/24/2018 
 */

#include "../include/ch2.h"

int abs(int x) {
    return x > 0 ? x : -x;
}

int power(int x, int y) {
    if (y == 0) return 1;
    int prod = 1;
    for (int i = 0; i < abs(y); ++i) {
	prod *= x;
    }
    
    return y > 0 ? prod : 1/prod;
}

int strlength(char *str) {
    int counter = 0;

    while (*str) {
	++counter, ++str;
    }
    
    return counter;
}

int chartoint(char c) {
    switch (c) {
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    default: 
    case '0': return 0;
    }
}

int convert(char *str) {
    int number = 0;
    int length = strlength(str);
    
    while (*str) {
	number += chartoint(*str++) * power(10, --length);
    }
    
    return number;
}
