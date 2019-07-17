// 3_완벽한전달자
#include <iostream>
using namespace std;

void foo(int  n, int b, int c) { n = 10; }
void goo(int& n) { n = 10; }
void hoo(int&& n) {}

// 완벽한 전달을 하려면
// 270
template<typename F, typename ... Types>
void chronometry(F f, Types&& ... args)
{

	f(std::forward<Types>(args)...);
}

int main()
{
	int x = 0;

	chronometry(foo, 10, 1, 2);
	chronometry(goo, x);

	cout << x << endl;
}





