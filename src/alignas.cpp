#include <stdio.h>

struct alignas(4) sse_t
{
    float sse_data[10];
};

// the array "cacheline" will be aligned to 128-byte boundary
alignas(128) char cacheline[128];

int main()
{
    printf("sizeof  : %lu\n", sizeof(sse_t));
    printf("alignof : %lu\n", alignof(sse_t));

    return 0;
}
