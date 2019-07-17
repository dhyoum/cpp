#include "cppmaster.h"
#include <iostream>
using namespace std;

template<typename T> void foo(T a)
{
	LOG_FUNCTION_NAME();
//	LOG_TYPE_NAME(T);
//	LOG_TYPE_NAME(decltype(a));
}
template<typename T> void goo(T& a)
{
	LOG_FUNCTION_NAME();
//	LOG_TYPE_NAME(T);
//	LOG_TYPE_NAME(decltype(a));
}
int main()
{
	int n = 0;
	int& r = n;
	const int c = 10;

	// volatile : 컴파일러에게 해당 변수를
	//     최적화 하지 말라는 의미.
	// int와 volatile int는 다른 타입입니다.
	// 예전에는 많이 사용
	// 요즘 c++ : volatile을 사용하지 말자
	volatile int c2 = 0; 
	foo(n);
	foo(r);
	foo(c);

	goo(n);
	goo(r);
	goo(c);


//	int x[3] = { 1,2,3 };
//	foo(x);
//	goo(x);
}
