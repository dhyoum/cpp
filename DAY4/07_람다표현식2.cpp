#include <iostream>
using namespace std;

int main()
{
	// 람다표현식 활용

	// 1. 함수의 정책으로 전달
	sort(x, x + 10, [](int a, int b) { return a < b;  });


	// 2. auto  변수에 담아서 함수 처럼 사용가능
	
	auto f = [](int a, int b) { return a + b; };
		// class ClosureType{..};ClosureType();

	int n = f(1, 2);

	// 다음중 에러는 ?  f2 
	auto   f1 = [](int a, int b) { return a + b; };
	auto&  f2 = [](int a, int b) { return a + b; };
	auto&& f3 = [](int a, int b) { return a + b; };
	const auto& f4 = [](int a, int b) { return a + b; };

}



