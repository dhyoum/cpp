// 3_완벽한전달자
#include <iostream>
using namespace std;

void foo(int  n) { n = 10; }
void goo(int& n) { n = 10; }

void hoo(int&& n) {}

template<typename F, typename T> 
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg)); 
}
/*
// 2번째 인자가 10이면  T : int,   T&& : int&&
void chronometry(함수포인터 f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
// x이면  T : int&  T&& : int&
void chronometry(함수포인터 f, int& arg)
{
	f(static_cast<int&>(arg));
}
*/
int main()
{
	int x = 0;
	
	chronometry(foo, 10);
	chronometry(goo, x);

	cout << x << endl;
}





