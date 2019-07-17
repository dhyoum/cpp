// 3_완벽한전달자
#include <iostream>
using namespace std;

void foo(int  n) { n = 10; }
void goo(int& n) { n = 10; }
void hoo(int&& n) {}

// 완벽한 전달을 하려면
// 1. 인자를 "forwarding reference"로 받는다.
// 2. 받은 인자를 다른곳에 보낼때는 std::forward로
//    묶어서 전달한다.

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	// 아래 캐스팅은 lvalue 를 lvalue로 
	//              rvalue 를 rvalue로 캐스팅합니다

	// 10(rvalue) => arg(lvalue) => 다시 rvalue
	// x (lvalue) => arg(lvalue) => 계속 lvalue
	//f(static_cast<T&&>(arg));

	f(std::forward<T>(arg)); // 이 함수가
					// 위처럼 캐스팅하고 있습니다.
}


int main()
{
	int x = 0;

	chronometry(foo, 10);
	chronometry(goo, x);

	cout << x << endl;
}





