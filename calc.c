#include <stdio.h>
#include "gmp.h"
#include <time.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define LEN 100000000

char readLine[LEN];

int main(int argc, char *argv[])
{
    mpz_t addend1;
    mpz_t addend2;
    int iters;
    int itersBefore;
    int num;
    clock_t start, end;
    FILE *file = fopen("nums", "r");
    fgets(readLine, LEN, file);
    num = atoi(readLine);
    fgets(readLine, LEN, file);
    mpz_init_set_str(addend1, readLine, 10);
    fgets(readLine, LEN, file);
    mpz_init_set_str(addend2, readLine, 10);
    fclose(file);

    if (argc == 2)
        iters = (itersBefore = atoi(argv[1])) / 2;
    else
    {
        printf("Use: fibo <number>\n");
        exit(1);
    }

    start = clock();

    for (int i = 0; i < iters; ++i)
    {
        mpz_add(addend1, addend1, addend2);
        mpz_add(addend2, addend2, addend1);
    }

    end = clock();

    printf("%s\n", mpz_get_str(NULL, 10, addend2));

    printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    num += itersBefore;

    file = fopen("nums", "w");
    itoa(num, readLine, 10);
    fwrite(readLine, 1, strlen(readLine), file);
    fwrite("\n", 1, 1, file);
    mpz_get_str(readLine, 10, addend1);
    fwrite(readLine, 1, strlen(readLine), file);
    fwrite("\n", 1, 1, file);
    mpz_get_str(readLine, 10, addend2);
    fwrite(readLine, 1, strlen(readLine), file);
    fwrite("\n", 1, 1, file);
}