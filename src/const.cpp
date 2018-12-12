#include <stdio.h>

class Data
{
    public:
        void funca() const
        {
            // int& v = a;
            const int& v = a;
        }

        const int& funca1() const
        {
            return a;
        }

        void funcr() const
        {
            const int* p = array;
            const int (&v)[100] = array;
        }

        const int* funcr2() const
        {
            return array;
        }

        /*
        typedef int array_t[100];
        const array_t& funcr3() const
        {
            return array;
        }
        */
        const int (&f())[100]
        {
            return array;
        }
 
    int a;
    int array[100];

};

int main()
{
    int ar[5] = {1,2,3};
    int* p = ar; p[0] = 20;

    // const int* p1 = ar; p1[0] = 20;
    int* const p2 = ar; p2[0] = 20;

    Data d;


    return 0;
}
