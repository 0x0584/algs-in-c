/* FILE: 	frac.c
 * AUTHOR: 	ANAS RCHID <rchid.anas@gmail.com> 
 * DESCRIPTION:	Fraction reduce
 * 
 * CREATION:	02/24/2018
 * MODIFIED:	02/24/2018 
 */
#include "../include/ch2.h"

frac_t newfrac(int foo, int bar) {
    return (frac_t) {foo, bar};
}

frac_t reduce(frac_t f) {
    int great = gcd(f.numer, f.denom);
    return (frac_t) {f.numer / great, f.denom / great};
}
