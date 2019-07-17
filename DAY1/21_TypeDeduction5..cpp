#include <iostream>
using namespace std;

int main()
{
	int n = 10;
	int& r = n;
	const int c = n;

	// auto 타입 추론은 "템플릿 타입 추론" 과 동일합니다.

	// 규칙 1. "auto a = 우변" 인경우 
	//		우변의 const, volatile, reference 모두제거후
	//	    auto 결정
	// T    a = 함수인자
	// auto a = 우변

	auto a1 = n;// auto : int
	auto a2 = r;// auto : int
	auto a3 = c;// auto : int
	a3 = 10; //

	// 규칙 2. "auto& a = 우변". 
	//		우변의 const, volatile 유지. 
	//		reference는 제거하고 auto 결정
	// T&    a = 함수인자
	// auto& a = 우변
	auto& a4 = n; // auto : int    a4 : int&
	auto& a5 = r; // auto : int    a5 : int&
	auto& a6 = c; // auto : const int  a6 : const int&
	a6 = 10; //  error


	// auto 와 배열 문제
	// auto  a1 = 배열 : a1은 포인터
	// auto& a2 = 배열 : a2는 배열를 가리키는 참조
	int x[3] = { 1,2,3 };

	// (A) 처럼 만들면 컴파일 에러
	// 그래서, (B)처럼 만든다.
	auto  a7 = x; // (A) int a7[3] = x; error
				  // (B) int* a7 = x;
	
	auto& a8 = x; // (A) int (&a8)[3] = x;


	cout << typeid(a7).name() << endl;
	cout << typeid(a8).name() << endl;
}

