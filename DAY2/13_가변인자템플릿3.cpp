#include <iostream>
using namespace std;

// Step 3. 재귀로 가변인자 전달된 인자 꺼내기
// 구글에서 C++ variadic template printf
//printf("%d, %d", 10);
//printf("%d, %d", 10, 20,30,40);


void foo() {}


template<typename T, typename ... Types> 
void foo(T value, Types ... args)
{
	static int cnt = 0;
	cout << value << endl;

	if constexpr( sizeof...(args) > 0)
		foo(args...); // foo( 4.5, "hello")
					  // foo("hello")
					  // foo()
}

int main()
{
	foo(3, 4.5, "hello"); // value : 3,    args : 4.5, "hello"

}








