// 3_완벽한전달자
#include <iostream>
using namespace std;

void foo(int  n) { n = 10; }
void goo(int& n) { n = 10; }

// 해결책
// 1. lvalue 참조, rvalue 참조 2개를 제공한다.
// 264 page
template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}
int main()
{
	int x = 0;
	
	chronometry(foo, 10);
	chronometry(goo, x);

	cout << x << endl;
}


