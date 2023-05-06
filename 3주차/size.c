#include <stdio.h>
#include <stdlib.h>

void main()
{
    int **x;
    printf("[----- [조수현] [2018038084] -----]\n\n");
    
    printf("sizeof(x) = %lu\n", sizeof(x));
    printf("sizeof(*x) = %lu\n", sizeof(*x));
    printf("sizeof(**x) = %lu\n", sizeof(**x));
}