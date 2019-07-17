#include <iostream>
#include <vector>
using namespace std;

int x = 10;

int& foo() { return x; }

int main()
{
	auto ret = foo();   // ret 타입은 ? int
	ret = 20;

	// decltype(함수호출식) : 함수호출의 결과로 
	//			나오는타입. 즉 함수 반환 타입
	decltype( foo() ) ret2 = foo(); // int&

	// C++14 에서 나온 표현식
	// 우변으로타입을 결정하는데
	// 규칙은 decltype 규칙으로 해달라!
	decltype(auto) ret3 = foo();

}






