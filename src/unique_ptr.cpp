#include <iostream>
#include <stdio.h>
#include <memory>
#include <vector>

using namespace std;

struct MyType
{
    MyType(int value_, int value2_):value{value_}, value2{value2_}
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    MyType(const MyType& other):value{other.value}, value2{other.value2}
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    MyType& operator=(const MyType& other)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        value = other.value;
        value2 = other.value2;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const MyType& mt)
    {
        os << mt.value << "/" << mt.value2;
        return os;
    }

    ~MyType()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    int value, value2;
};

void func1()
{
    printf("enter func\n");
	unique_ptr<MyType> a(new MyType(10,20));
    printf("exit func\n");
}

unique_ptr<MyType> func2()
{
    printf("enter func\n");
	unique_ptr<MyType> a{new MyType(10,20)};
    printf("exit func\n");

    return a;
}

class MyData
{
    public:
        MyData():m_aa{new MyType(10,20)} {}

    unique_ptr<MyType> m_aa;
    unique_ptr<MyType> m_ab{new MyType(10,20)};
    int i = 20;
};


int main()
{
    printf("enter main\n");
    // unique_ptr<MyType> b; error
	unique_ptr<MyType> a(new MyType(10,20));
	// unique_ptr<MyType> b = std::make_unique<MyType>(10,20); since C++14
    //
	// unique_ptr<MyType> b(a); error
	unique_ptr<MyType> b = std::move(a); // ok

    // func1();
	unique_ptr<MyType> c(func2());

    MyData aa;
    // vector<unique_ptr<MyType>> myvec{{new MyType(10,20)}}; //fail : initializer_lists always perform copies

    vector<unique_ptr<MyType>> myvec;
    myvec.emplace_back(new MyType(10,20));


    printf("exit main\n");

    return 0;
}
