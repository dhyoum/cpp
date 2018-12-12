#include <stdio.h>
class elem
{
    public:
        constexpr elem(int v=0):value{v} {}

    const int value;
};

class Data
{
public:
    int a;
    static int s1;
    // static int s2 = 2; error
    // const int s2 = 2; // warning in C++98
    static const int s2 = 2; // ok in C++98
    // static const int s3(3); // error 
    static const int s4{4}; // error in C++98 , ok in C++11

    // constexpr static elem e1 {1}; // error in C++98 , ok in C++11

    // constexpr static elem e1{1}; // error in C++98 , ok in C++11

    // const static int array[2] = {1,2}; // error in C++98 C++11
    constexpr static int array[] = {1,2}; // ok in C++11

    void test()
    {
        printf("size = %zu\n", sizeof(array));
        printf("size = %zu\n", sizeof(array[0]));
        printf("len  = %zu\n", sizeof(array)/sizeof(array[0]));
    }
};

int main()
{
    const int a = 10;
    constexpr int arr[] = {1,2}; // const doesn't work

    int array[arr[0]];

    static int s1;
    static int s2 = 2;
    // const int c1;
    const int c2 = 2;
    static elem e1{1}; // error in C++98 , ok in C++11

    elem e2{2};
    Data data;
    data.test();

    const elem e3 = 10;
    constexpr elem e4 = 10; // same with e1{10}
    int array2[e4.value]; // error with e3

    return 0;
}
