#include "../include/ch3.h"

bool_t isprime(unsigned foo) {
    if (foo == 0 || foo == 1) return false;
    /* there's no need to keep looping after the sqrt of foo */
    for (unsigned i = 2; i < (unsigned) sqrt(foo); ++i) {
	unless (foo%i) {
	    return false;
	}
    }
    
    return true;
}

/* the main point is that each number who's the result of the multiplication
 * of two numbers is definitly not a prime. so we set the elements via the
 * multiplication of indexes.
 *
 * this method dates to 300 B.C.
 */
void sieve_of_eratosthenes(array_t p) {
    for (unsigned i = 2; i <= (p.limit / 2); ++i) {
	/* if array[i] is false, i's multiples must be already marked */
	if (p.elem[i]) {
	    for (unsigned j = 2; j <= (p.limit / i); ++j) {
		p.elem[i*j] = false;
	    }
	}
    }
}
