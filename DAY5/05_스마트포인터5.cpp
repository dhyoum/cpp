#include <iostream>
#include <memory>
using namespace std;

void foo(void* p) { free(p); }

int main()
{
	// 삭제자 변경
	shared_ptr<int>  sp1(new int);

	// 생성자의 2번째 인자로 삭제자 함수 전달
	//shared_ptr<void> sp2(malloc(100), foo);

	//shared_ptr<void> sp2(malloc(100), free);

	shared_ptr<void> sp2(malloc(100),
						[](void*p) { free(p); });


//	shared_ptr<int> sp3(new int[10], 
//					[](int *p) { delete[] p; });

	// 배열 할당일 경우 - C++17 부터 아래처럼 사용가능
	shared_ptr<int[]> sp4(new int[10]);
}









