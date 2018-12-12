#include <stdio.h>

// To disable : -Werror=vla

/*
int func(int n)
{
    int array[n];
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        array[i] = i;
        sum += array[i];
    }

    return sum;
}
*/

int main()
{
    int n = 10;
    int array[n];
    // printf("sum = %d\n", func(n));

    return 0;
}
