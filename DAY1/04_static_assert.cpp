#include <iostream>
#include <cassert> 
using namespace std;


static_assert(sizeof(void*) == 8,
					"error not 64bit");

//static_assert(sizeof(void*) == 8); // C++17

// 156 page
void foo(int age)
{
	// 함수 인자는 사용하기 전에 유효성 여부를 확인하는 것이 좋다.
	assert(age > 0);

	// C++11 컴파일 시간 assert
//	static_assert(sizeof(void*) == 8,
//				"error not 64bit");
}



int main()
{
	foo(-10);
}




