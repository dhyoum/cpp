#include <iostream>
using namespace std;

// SFINAE 를 활용하는 3가지 방법

/*
template<typename T> void foo(T a)
{
	typename T::type n; // SFINAE가 적용될까요 ?
					    // 아니면 에러 일까요 ?
					// 에러
}
*/
// SFINAE 기술을 3가지 위치에서 사용가능합니다.
// 1. 리턴 타입으로..!!
template<typename T>
typename T::type foo(T a) { cout << "T" << endl; return 0; }

// 2. 함수인자에 사용
template<typename T>
void foo(T a, typename T::type n = 0) { }


// 3. 템플릿 인자에 사용
template<typename T, 
		 typename T2 = typename T::type>
void foo(T a) {}


void foo(...) { cout << "..." << endl; }

int main()
{
	foo(10);
}




