#include <stdio.h>

void print1(int *ptr, int rows);

int main()
{
    int one[] = {0, 1, 2, 3, 4};
    printf("[----- [조수현] [2018038084] -----]\n\n");

    printf("one       = %p\n", one);
    printf("&one      = %p\n", &one);
    printf("&one[0]   = %p\n", &one[0]);
    
    print1(&one[0], 5);

    return 0;
}

void print1(int *ptr, int rows)
{
    int i;
    printf("Address \t Contents\n:");
    for(i = 0; i < rows; i++)
    {
        printf("%p \t %5d\n", ptr+i, *(ptr+i));
    }
    printf("\n");
}