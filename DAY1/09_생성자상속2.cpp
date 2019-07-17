#include <iostream>
using namespace std;

class Base
{
	int data;
public:
	Base(int a) : data(a) {}
};

class Derived : public Base
{
public:
};

int main()
{ 
	Derived d;
}









