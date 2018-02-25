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
#define NULL				((void *)0)

/* ----------- types ----------- */
typedef struct FRACTION {
    int numer, denom;
} frac_t;

typedef enum BOOLEAN {
    false = (1 == 0),
    true = !false
} bool_t;

/* ----------- prototypes ----------- */
int gcd(int __first, int __second);
int gcd3(int __first, int __second, int __third);
int __gcd(int __first, int __second);
frac_t reduce(frac_t __fraction);
frac_t newfrac(int __numerator, int __denumirator);
int convert(char *__number);
unsigned absolute(int __number);
unsigned strlength(const char *__string);
double power(int __number, int __to_power);
unsigned long binary(unsigned __number);
#endif
