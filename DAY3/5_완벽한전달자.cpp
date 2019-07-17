// 3_완벽한전달자
#include <iostream>
using namespace std;

void foo(int  n) { n = 10; }
void goo(int& n) { n = 10; }

// 완벽한 전달(perfect forwarding)이란 ?
// 전달 받은 인자를 다른 함수에게 완벽하게 전달하는 
// 기술



// 특정 함수가 수행되는데 걸리는 시간을 측정하는 함수
template<typename F, typename T> 
void chronometry(F f, const T& arg)
{
	// 시간 기록
	f(arg);
	// 걸린 시간 출력
}
int main()
{
	int x = 0;
//	foo(10);
	chronometry(foo, 10);
	chronometry(goo, x); // goo(x)

	cout << x << endl;
}





