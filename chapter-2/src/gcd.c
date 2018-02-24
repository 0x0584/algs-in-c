/* FILE: 	gcd.c
 * AUTHOR: 	ANAS RCHID <rchid.anas@gmail.com>
 * DESCRIPTION:	Great Common Divisor
 * 
 * CREATION:	02/24/2018
 * MODIFIED:	02/24/2018 
 */

#include "../include/ch2.h"

int gcd(int fst, int snd) {
    int tmp = 0;

    while (snd != 0) {
        tmp = (fst % snd);
	fst = snd;
	snd = tmp;
    }
    
    return fst;
}

int __gcd(int fst, int snd) {
    int tmp = 0;

    while (fst != 0) {
	if (fst < snd) {
	    tmp = fst;
	    fst = snd;
	    snd = tmp;
	}

	fst -= snd;
    }
    
    return snd;
}
