#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// move 개념 활용
// 1. swap 등의 알고리즘을 만들때
//    복사가 아닌 move 를 사용하면 성능이 향상된다.

// 2. 클래스를 만들때
//    되도록 이면 move 생성자를 제공하자.
//    제공하지 않으면 복사 생성자를 사용하게 된다.


// move와 알고리즘
// 아래 코드의 문제점을 이야기해 보세요
// 아래 코드는 복사에 의한 Swap 입니다. 느립니다.
/*
template<typename T> void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
*/
template<typename T> void Swap(T& a, T& b)
{
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	string s1 = "hello";
	string s2 = "world";

	Swap(s1, s2);
}


