#include <iostream>
using namespace std;

// 규칙 2. 인자의 타입이 참조 타입이면 
//        함수 인자가 가지고 있는 참조 속성만 제거된다.
//         const, volatile은 유지한다.
template<typename T> void foo(T& a)
{
}
int main()
{
	int n = 10;
	int&r = n;
	const int c = n;
	const int& cr = c;
	foo(n); // T : int    a : int&
	foo(r); // T : int    a : int&
	foo(c); // T : const int  a : const int&
	foo(cr);// T : const int  a : const int&

//	int& r = c;
}





