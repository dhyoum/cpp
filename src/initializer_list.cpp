#include <iostream>
#include <vector>
#include <memory>
#include <utility>

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

struct MyArray
{
    MyArray(std::initializer_list<int> arr) : myarray{arr}
    {
    }

    std::vector<int> myarray;
};

struct MyArray2
{
    MyArray2(std::initializer_list<MyType> arr) : myarray{arr}
    {
    }

    std::vector<MyType> myarray;
};

void print_all(std::initializer_list<int> data)
{
    for(auto a : data)
        std::cout << a << std::endl;
}

void print_all(std::initializer_list<MyType> data)
{
    for(const auto& a : data)
        std::cout << a << std::endl;
}

int main()
{
    std::initializer_list<int> arr1 = {1,2,3};
    print_all(arr1);

    std::initializer_list<int*> parr = {new int(1), new int(2)};
    // std::initializer_list<std::unique_ptr<int>> parr2 = {new int(1), new int(2)}; fail why ?

    std::initializer_list<MyType> data = {{1,2}};
    print_all({{1,2},{3,4}});
    //
    // MyArray arr2{1,2,3,4,5};
    MyArray2 arr3= {{1,2}};

    /*
    for(const auto& a : arr2.myarray)
        std::cout << a << std::endl;
        */

    return 0;
}
