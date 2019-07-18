#include <iostream>
using namespace std;

// 276 page 부터 시작
void foo( int(*f)(int, int) )
{
	f(1, 2);
}
int add(int a, int b) { return a + b; }

int main()
{
	foo(add);

	// [] : lambda introducer
	// 람다표현식이 시작됨을 알리는 기호
	// 람다표현식 : 익명의 함수를 만드는 표기법
	foo([](int a, int b) { return a + b; });


	add(1, 2);

	int n = [](int a, int b) { return a + b; }(1, 2);

	// 함수 이름또는 주소가 필요한 곳에
	// 함수 구현 자체를 표기하는 문법.
}
