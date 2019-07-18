#include <iostream>
#include <functional>
using namespace std;

// 람다표현식을 담는 변수 - 292


int main()
{
	auto f1           = [](int a, int b) { return a + b; };
	
	int(*f2)(int,int) = [](int a, int b) { return a + b; };
	
	function<int(int,int)> f3 = [](int a, int b) { return a + b; };



	// 아래 코드들의 인라인 치환성을 생각해 보세요
	f1(1, 2); //  인라인 치환 됨.
			// 치환 되는 이유..
			// f1이 가진 주소가 아닌 f1의 타입 기반한 호출
		    // f1.operator()(1,2) 로 실행

	f2(1, 2); //  치환 안됨.
				// f2가 가진 주소 기반 호출
				// 실행시 메모리에서 값 꺼내기

	f3(1, 2); //  치환 안됨.
}








