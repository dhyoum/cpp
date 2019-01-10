#include <stdio.h>
#include <iostream>
#include <functional>

using namespace std;

class MM
{
public:
    static void hello()
    {
        printf("hello");
    }

    template<typename T>
    static T getValue(const unsigned char* data, int size)
    {
      T value = data[0];
      for(int i = 1; i < size; i++)
      {
        value <<= 8;
        value |= data[i];
      }
      return value;
    }
};

template<typename T>
T getValue(const unsigned char* data, int size)
{
  T value = data[0];
  for(int i = 1; i < size; i++)
  {
    value <<= 8;
    value |= data[i];
  }
  return value;
}

// auto f = getValue<unsigned int>;
function<unsigned int(const unsigned char*, int)> f = MM::getValue<unsigned int>;

unsigned int func()
{
    unsigned char a[2] = {1,2};
    return f(a,2);
}

class AA
{
public:
    AA()
    {
        x = NULL;
    }
    ~AA()
    {
        delete x;
    }
    int a;
    char* x;

    void test()
    {
        x = new char();
    }
};

int main()
{
    AA a;

    printf("a = %lu\n", (char*)(&a.a) - (char*)&a);
    printf("x = %lu\n", (char*)(&a.x) - (char*)&a);
    printf("pointer x = %p\n", (&a.x));

    printf("a.x = %p\n", a.x);
    a.test();
    printf("a.x = %p\n", a.x);

    return 0;
}
