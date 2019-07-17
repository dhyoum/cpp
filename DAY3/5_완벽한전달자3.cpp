// 3_완벽한전달자
#include <iostream>
using namespace std;

void foo(int  n) { n = 10; }
void goo(int& n) { n = 10; }

void hoo(int&& n) {}



template<typename F> void chronometry(F f, int& arg)
{
	//f(arg) ;
	f(static_cast<int&>(arg)); // 캐스팅이 필요없지만
						// 해도 문제되지는 않는다
}

// main		     chronometry		hoo(int&)
// 10(rvalue) ========================> ok
// 10(rvalue) ==> int&& arg(lvalue) ==> error
//					캐스팅 필요!
template<typename F> void chronometry(F f, 
								int&& arg)
{
	// int&& arg = 10
	// 10 은 rvalue 이지만 arg는 lvalue 입니다.
	//f(arg); // hoo(int&)를 찾고 있다

	f(static_cast<int&&>(arg)); // ok
}

int main()
{
	int x = 0;

	hoo(10); // ok

	chronometry(hoo, 10);//??

	cout << x << endl;
}





