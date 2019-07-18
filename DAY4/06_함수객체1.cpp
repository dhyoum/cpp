#include <iostream>
using namespace std;

// 278 page
// 함수 객체(function object, functor)
// 함수 처럼 사용가능한 객체

// 장점 - 279 page
// 1. 상태를 가지는 함수
// 2. 독립된 타입성
// 3. 일반 함수 보다 빠르다.(인라인 치환성)


struct Plus
{
	int operator()(int a, int b) const
	{
		return a + b;
	}
};

int main()
{
	Plus p;
	int n = p(1, 2); // p.operator()(1,2)
	cout << n << endl;

	// a + b;  // a.operator+ (b)
	// a - b;  // a.operator-(b)
	// a();    // a.operator()()
	// a(1,2); // a.operator()(1,2)
}



