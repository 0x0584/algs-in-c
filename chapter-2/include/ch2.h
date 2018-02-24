/* FILE: 	ch2.h
 * AUTHOR: 	ANAS RCHID
 * DESCRIPTION: Headers of chapter 2
 * 
 * CREATION:	02/24/2018
 * MODIFIED:	02/24/2018 
 */
#ifndef __CHAPTER_2
#define __CHAPTER_2
#define CHECK_MODULUS(a, b)		((a)%(b))

/* ----------- types ----------- */
typedef struct FRACTION {
    int numer, denom;
} frac_t;

/* ----------- prototypes ----------- */
int gcd(int __first, int __second);
int __gcd(int __first, int __second);
frac_t reduce(frac_t __foo);
frac_t newfrac(int __numerator, int __denumirator);
int convert(char *__number);
#endif
