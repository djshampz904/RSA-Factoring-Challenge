#include "rsa.h"

/*
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments
 * @return: 0 on success, 1 on error
*/

int main(int argc, char **argv) {
    char *file_name;

    file_name = argv[1];
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: Can't open file %s\n", file_name);
        return 1;
    }

    unsigned long long n;
    while (fscanf(fp, "%llu\n", &n) != EOF) {
        factorize(n);
    }
    
    fclose(fp);
    return 0;
}