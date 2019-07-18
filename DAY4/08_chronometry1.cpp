#include <iostream>
using namespace std;

class Test
{
public:
	void foo() &  { cout << "foo &" << endl; }
	void foo() && { cout << "foo &&" << endl; }

	void operator()() & { cout << "operator () &" << endl; }
	void operator()() && { cout << "operator ()&&" << endl; }
};

int main()
{
	Test t;
	t.foo(); // foo() &

	Test().foo(); // foo() &&

	t();
	Test()();
}

