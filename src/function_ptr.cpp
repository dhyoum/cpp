#include <stdio.h>
#include <functional>
#include <memory>

void func_int(int v)
{
    printf("func_int: %d\n", v);
}

void func_char(char v)
{
    printf("func_char: %c\n", v);
}

typedef void (*func_t)(int);
typedef std::function<void (int)> func_t2;

class Base
{
public:
    Base(){}
    virtual ~Base(){}

    typedef void (Base::*Function) (int);

    virtual void func1(int v)
    {
        printf("Base::func1: %d\n", v);
    }
};

class Derived : public Base
{
public:
    Derived () {}
    virtual ~Derived (){}

    virtual void func1(int v) override
    {
        printf("Derived::func1: %d\n", v);
    }
};

int main()
{
    using namespace std::placeholders;

    func_t f1;
    f1 = func_int;
    f1 = (func_t)func_char;

    f1(65);

    Base base;
    Derived derived;

    Base::Function f3 = &Base::func1;
    (base.*f3)(20);
    Base::Function f4 = (Base::Function)(&Derived::func1);
    (derived.*f4)(20);

    auto f5 = std::bind(&Base::func1, &base, _1);
    f5(40);

    auto f6 = std::bind(&Base::func1, &derived, _1);
    f6(50);

    return 0;
}
