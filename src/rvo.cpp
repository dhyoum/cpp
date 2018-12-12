#include <iostream>
#include <stdio.h>
using namespace std;

class Klass
{
    public:
        Klass()
        {
            cout << "Klass()" << endl;
        }

        Klass(const Klass& right)
        {
            cout << "Klass(const Klass& right)" << endl;
        }

        Klass& operator= (const Klass& right)
        {
            cout << "operator= (const Klass& right)" << endl;
            return *this;
        }
};

Klass test1()
{
    printf("%s called\n", __PRETTY_FUNCTION__);
    return Klass();
}

Klass test2()
{
    printf("%s called\n", __PRETTY_FUNCTION__);
    Klass a;
    return a;
}

/*
void test3(Klass a)
{
    printf("%s called\n", __PRETTY_FUNCTION__);
}
*/

void test3(Klass& a)
{
    printf("%s called\n", __PRETTY_FUNCTION__);
}

void test3(const Klass& a)
{
    printf("%s called\n", __PRETTY_FUNCTION__);
}

/*
void test3(const Klass&& a)
{
    printf("%s called\n", __PRETTY_FUNCTION__);
}
*/

Klass test5(Klass a)
{
    printf("%s called\n", __PRETTY_FUNCTION__);
    return a;
}


int main()
{
    //Klass result1 = test1();
    // Klass result2 = test2();
    // Klass b = test4(Klass());
    test3(Klass());

    return 0;
}
