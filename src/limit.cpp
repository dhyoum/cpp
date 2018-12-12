#include <limits.h>
#include <stdio.h>

int main()
{
    printf("sizeof = %llu\n", sizeof(long long));
    printf("0x%llx\n", ULLONG_MAX);
    printf("0x%llx\n", LLONG_MAX);


    printf("0x%x\n", UCHAR_MAX);
    printf("0x%x\n", CHAR_MAX);

    for( int i=0; i<=255; i++)
    {
        unsigned char val = (unsigned char)i;
        if ( val < CHAR_MAX )
            printf("in  : %u\n", val);
        else
            printf("out : %u\n", val);
    }
 
    return 0;
}
