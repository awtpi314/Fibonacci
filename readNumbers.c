#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define LEN 100000000

char readLine[LEN];

int main(int argc, char *argv[])
{
    FILE *inFile = fopen("nums", "r");
    fgets(readLine, LEN, inFile);
    int fiboNumber = atoi(readLine);
    fgets(readLine, LEN, inFile);
    fgets(readLine, LEN, inFile);
    int fiboLength = strlen(readLine);
    printf(readLine);
    printf("\nis the %d Fibonacci number, and its length is %d.", fiboNumber, fiboLength);
    return 0;
}