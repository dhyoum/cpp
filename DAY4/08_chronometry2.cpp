#include <iostream>
using namespace std;

class Test
{
public:
	void foo(int a) { cout << "foo" << endl; }
};

int main()
{
	void(Test::*f)(int) = &Test::foo;

	Test test;
	(test.*f)(0); // 멤버 함수 포인터로 호출

	// 일반 함수 포인터라면
	f1(1, 2, 3);

	// 일반함수 포인터와 멤버 함수 포인터 모두 동일한
	// 방식으로 호출되게 하자.
	invoke(f1, 1, 2, 3); // 일반 함수 포인터
	invoke(f, &test, 0); // 멤버 함수 포인터

}

