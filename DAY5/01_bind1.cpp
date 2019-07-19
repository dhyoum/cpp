// 출석 (QR) 체크 해주세요
// cafe.naver.com/cppmaster 에서5일차 사전 소스 받으시면 됩니다.
#include <iostream>
#include <functional> // bind
using namespace std::placeholders; // _1, _2, _3..

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}
int main()
{
	foo(1, 2, 3, 4); // 4항 함수

	// bind : N 항 함수의 특정 인자를 고정한 새로운
	//		 함수 생성
	// 4항 => 단항 함수
	bind(&foo, 5, 3, _1, 2)(7); // 5 3 7 2

	bind(&foo, 5,_2,6,_1)(3, 8); // 5, 8, 6, 3 나오게
					      // ? 채워 보세요

}



