#include <iostream>
using namespace std;

// 함수가 lvalue와 rvalue를 모두받게 하려면
// 1. call by value 
//    특징 : 복사본이 생성된다.
//    primitivate 타입이면 전혀 문제 될거 없다.
//    하지만 int 가 아니라 user type 이면 ?
void foo(int arg) {}

// 2. const lvalue reference
//   특징 : 복사본이 없다. 하지만 원본에 상수성을
//		    추가해서 받게 된다.
void foo(const int& arg) {}

// 3. lvalue 참조와 rvalue 참조 버전으로 2개 제공
// 특징 : 복사본이 없다. 상수성도 추가되지 않는다.
void foo(int&) {}
void foo(int&&) {}

// 4. forwarding reference를 사용하면
//    3번의 함수를 자동생성할수 있다.
// n을  전달 T : int&   T&& : int&
// 10을 전달 T : int    T&& : int&&
template<typename T> void foo(T&& arg) {}

int main()
{
	int n = 0;

	foo(n);
	foo(10);
}

