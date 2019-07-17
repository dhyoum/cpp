#include "cppmaster.h"
#include <iostream>
using namespace std;

template<typename T> void foo(T a)
{
	LOG_FUNCTION_NAME();
}  
void goo(int a, int b)
{
	//cout << "goo" << endl;

	// __FUNCTION__ : 함수이름을 담은 매크로
	//				  C++표준
	// __FUNCSIG__ : 함수이름 + signature
	//					VC++ 전용
	// __PRETTY_FUNCTION__ : g++ 전용

	//cout << __FUNCTION__ << endl;
	//cout << __FUNCSIG__ << endl;

	LOG_FUNCTION_NAME(); // cppmaster.h 있는
						// 매크로
}

int main()
{
	goo(1, 2);

	foo(10);   
	foo(3.4);
}