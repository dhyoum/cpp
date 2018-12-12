#include <functional>
#include <iostream>
#include <memory>

using namespace std;
using namespace std::placeholders;

struct AA
{
   friend ostream& operator<<(ostream& os, const AA& a)
   {
        os << a.toString();
        return os;
   }
    virtual const char* toString() const = 0;
};

struct Enum1 : public AA
{
    virtual const char* toString() const
    {
        return "ABCDEF--";
    };
};

struct Enum2 : public AA
{
    virtual const char* toString() const
    {
        return "ABCDEF00";
    };
};

struct Foo {
    Foo()
    {
    }
	bool f1() const
    {
        return false;
    }

    bool isOk(void* p)
    {
        return *((char*)p) == 1;
    }

    bool isOkA() const
    {
        return *a == 1;
    }

    bool isOkB() const
    {
        return b == 1;
    }

    std::unique_ptr<AA> getEnum()
    {
        std::unique_ptr<AA> ptr(new Enum1());
        return ptr;
    }

    void test()
    {
        std::function<bool(void)> f2 = std::bind(&Foo::f1, this);
        f2();

        // std::function<bool(void)> f2 = std::bind(&Foo::f1, this);
        // std::function<Enum1(void)> f3 = std::bind(&Foo::getEnum, this);
        /*
        std::function<std::unique_ptr<AA*>(void)> f3 = std::bind(&Foo::getEnum, this);
        AA* a = f3();
        cout << "123" << *a << "345" << endl;
        */
    }

    void print_sum(int n1, int n2)
    {
        std::cout << n1+n2 << '\n';
    }

    char a[1];
    int b;
    /*
    const std::function<bool(void)> isOkA = std::bind(&Foo::isOk, this, a);
    const std::function<bool(void)> isOkB = std::bind(&Foo::isOk, this, &b);
    */
};
void f(int n1, int n2, int n3, const int& n4, int n5)
{
    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}

bool test()
{
    return false;
}

int main()
{
	int n = 7;

	auto f1 = std::bind(f, _2, _1, 42, std::cref(n), n);
	n = 10;
    // f1(1, 2, 1001); 

    Foo foo;
    foo.test();

	// auto f3 = std::bind(&Foo::print_sum, &foo, 95, _1);
	// f3(5);

    cout << "sizeof " << sizeof(Foo) << endl;

    bool a = foo.isOkA();
    bool b = foo.isOkB();

    return 0;
}
