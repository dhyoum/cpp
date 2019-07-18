#include <iostream>
#include <type_traits>
using namespace std;

int main()
{
	// r1, r2는 동일 합니다.
	int&& r1 = 0;
	add_rvalue_reference<int>::type r2 = 0;


	void&& r3; // 컴파일에러. void 참조는 만들수 없습니다 

	add_rvalue_reference<void>::type r4; 
					// void r4의 의미.
}
