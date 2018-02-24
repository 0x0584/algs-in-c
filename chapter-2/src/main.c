/* FILE: 	main.c
 * AUTHOR: 	ANAS RCHID <rchid.anas@gmail.com>
 * DESCRIPTION:	Testings of chapter 2
 * 
 * CREATION:	02/24/2018
 * MODIFIED:	02/24/2018 
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#include "../include/ch2.h"

int main(int argc, char **argv) {
    putchar('\n');
    srand(time(NULL));

    int x, y;

    if (argc < 3) {
	fprintf(stderr, "Usage: ./%s <num0> <num1>\n", argv[0]);
	y = rand()%INT_MAX;
	x = rand()%INT_MAX;
    } else {
	x = atoi(argv[1]), y = atoi(argv[2]);
    }

    frac_t foo = reduce(newfrac(x,y));
    char *str = "157894";
    
    printf("%d modulus %d is %d\n", -1, -2, CHECK_MODULUS(-1, -2));
    
    printf("gcd of %d and %d is %d\n", x, y, gcd(x,y));
    printf("gcd of %d and %d is %d\n", x, y, __gcd(x,y));
    
    printf("%d/%d is the same as %d/%d\n", x, y, foo.numer, foo.denom);

    printf("\"%s\" %d\n", str, convert(str));
    printf("%d in binary is  %ld\n", 1000 , binary(1000));
	
    return EXIT_SUCCESS;
}
