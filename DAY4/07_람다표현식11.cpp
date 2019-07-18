#include <iostream>
using namespace std;

int main()
{
	// nullary lambda
	auto f1 = [](int a) {return a * a; }; // 인자가 한개인경우

	auto f2 = []() {return 0; };
	auto f3 = [] {return 0; }; // 인자가 없으면() 생략가능


	// 람다인자는 auto가능 - 원리가 무엇일까요..
	// ()연산자를 템플릿으로
	auto f4 = [](auto a, auto b) { return a + b; };
	cout << f4(1, 2.5) << endl;

	class ClosureType
	{
	public:
		template<typename T1, typename T2>
		inline decltype(auto) operator()(T1 a, T2 b) const
		{
			return a + b;
		}
	};
}
//void foo(auto a) {} // error. 함수 인자로 auto 안됨.
