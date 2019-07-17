#include <iostream>
using namespace std;

// 273 page
void foo(int) {}
void foo(double) {}
void goo(int*) {}

template<typename F, typename ... Types>
decltype(auto) chronometry(F f,Types&& ... args)
{
	return f(std::forward<Types>(args)...);
}
int main()
{
	//printf("%p\n", foo); // error
	printf("%p\n", 
		static_cast<void(*)(int)>(foo)); // ok

	//chronometry(foo, 10);//error. 위처럼 캐스팅필요
	
	//-----------------
	int n = 0;
	int* p1 = 0; // ok
//	int* p2 = n; // error

	goo(0); // ok
	//chronometry(goo, 0); // error

	chronometry(goo, nullptr); // ok
}






