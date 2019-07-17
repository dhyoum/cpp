#include <iostream>
using namespace std;

class Base
{
public:
	void foo(double d) { cout << "double" << endl; }
	void foo(int, int) { cout << "int,int" << endl; }
};
class Derived : public Base
{
public:
	void foo(int) { cout << "int" << endl; }
};
int main()
{
	Derived d;
	d.foo(3.4); //?
	d.foo(1, 1); // ?
}




