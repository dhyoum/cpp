#include <stdio.h>

class Data
{
    public:
        virtual ~Data(){}

    int a;
    int b;
    int c;
};

int main()
{
    Data a[2];

    printf("%p\n", a);
    printf("%p\n", a+1);

    return 0;
}
