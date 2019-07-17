// cafe.naver.com/cppmaster 에서
// 2일차 사전 소스 받으시면 됩니다.
// 꼭 압축을 풀고 VC++에서 열어 주세요.











#include <iostream>
using namespace std;
// 222 page

//int square(int n)
// C++11 에서 나온 새로운 함수 표기법
// 후위 반환 타입(suffix return type)
// "람다표현식" 과 "템플릿"에서 주로 사용
auto square(int n) -> int
{
	return n * n;
}

int main()
{
	square(3);
}
