#include <iostream>
using namespace std;

// 204
int x = 10;
class Test
{
public:
	int a = 0; // member initializer
	int b = ++x;

	Test() {}
	Test(int v) : b(v) {}
};
int main()
{
	Test t1;
	Test t2(3);

	cout << x << endl; // 11
}