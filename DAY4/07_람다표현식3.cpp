#include <iostream>
using namespace std;

// 핵심 ) 모든 람다 표현식은 다른 타입이다.
int main()
{
	auto f1 = [](int a, int b) { return a + b; };
	auto f2 = [](int a, int b) { return a + b; };


	// error
	// 람다표현식으로 초기화된 auto 변수에는 다른
	// 람다표현식을 넣을수 없다
	f2 = [](int a, int b) { return a + b; }; // ?


	// f1, f2 는 같은 타입일까요 ? 다른 타입 일까요 ?
	cout << typeid(f1).name() << endl;
	cout << typeid(f2).name() << endl;
}






