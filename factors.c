#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void factors(unsigned long long n);

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    unsigned long long n;
    while (fscanf(file, "%llu\n", &n) != EOF) {
        factors(n);
    }

    fclose(file);
    return 0;
}

void factors(unsigned long long n) {
    for(unsigned long long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            printf("%llu=%llu*%llu\n", n, n/i, i);
            break;
        }
    }
}