#include "rsa.h"

/* 
 * Factorize n
 * @n: number to factorize
 * @return: void
 */

void factorize(unsigned long long n) {
    unsigned long long prime1 = 0;
    unsigned long long prime2 = 0;
    
    for(unsigned long long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0 && is_prime(i) == 1) {
            prime1 = i;
            prime2 = n / i;
            break;
        }
    }
    
    if (prime1 != 0 && prime2 != 0) {
        printf("%llu=%llu*%llu\n", n, prime2, prime1);
    }
}