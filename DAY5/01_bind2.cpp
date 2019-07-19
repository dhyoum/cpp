#include <iostream>
#include <functional>
using namespace std::placeholders;
using namespace std;

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}
void goo(int a) {}

int main()
{
	// 일반 함수 포인터
	void(*f1)(int); 

	// C++11 에서 제공하는 함수 포인터의 일반화 버전
	function<void(int)> f;
	
	f = &goo;
	f(10);

	// function 은 bind와 같이 사용하면
	// 다양한 함수를 담을수 있습니다.
	f = bind(&foo, 1,2,3, _1);
	f(10); // foo(1,2,3,10) 
}




