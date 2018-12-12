#include <stdio.h>

bool isInvalid(unsigned char* data, size_t size)
{
    long invalid = (unsigned long)-1 >> (8*(sizeof(long)-size));
    long *p = (long*)data;
    *p &= invalid;

    printf("0x%lx, 0x%lx\n", *p, invalid);

    return *p == invalid;
}

int main()
{
    unsigned char a[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

    if (isInvalid(a, 5))
        printf("invalid\n");

    return 0;
}
