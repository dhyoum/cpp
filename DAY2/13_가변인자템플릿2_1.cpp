#include <iostream>
// 130 page 코드
void goo(int a, int b, int c) {}
int hoo(int a) { return -a; }

template<typename ... Types> 
void foo(Types ... args)
{
	//goo(args);// error
	goo(args...); // goo(1,2,3)
	goo(++args...); // goo(++E1, ++E2, ++E3)

	//goo(hoo(args...)); // error. hoo는 인자가 한개
	goo(hoo(args)...); // goo(hoo(E1), hoo(E2), hoo(E3))
}

int main()
{
	foo(1, 2, 3);
}
