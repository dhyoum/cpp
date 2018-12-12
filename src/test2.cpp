#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

class Data
{
    public:
    Data(int v=0) : value(v)
    {
        printf("create Data(%d) this : %p\n", v, this);
    }
    Data(const Data& other)
    {
        value = other.value;
        printf("copy create Data(%d) this : %p from %p\n", value, this, &other);
    }
    Data& operator=(const Data& other)
    {
        value = other.value;
        printf("operator= Data this : %p (other:%p)\n", this, &other);
        return *this;
    }

    ~Data()
    {
        printf("delete Data this : %p\n", this);
    }

    int value;
};

Data* test()
{
    static Data tt[5];

    return tt;
}

/*
static int static__initial_int = 0;
static int static_uninitial_int;
int global_initial_int = 0;
int global_uninitial_int;
static Data static_d(0);
*/

// Data global_d(0);
// vector<Data> global_v0 = {Data(0)};

vector<Data> vfunc()
{
    vector<Data> local = {Data(-1)};

    return local;
}

int main()
{
    // Data* a =  new Data(1000);
    // Data b;
    printf("I'm main\n");

    // vector<Data> qlocal = vfunc();
    vfunc();
    /*
    printf("size of Data %d\n", sizeof(Data));
    if (0)
    {
        static Data static_local_d(3);
        Data local_d(4);
    }
    */

    // delete a;

    return 0;
}
