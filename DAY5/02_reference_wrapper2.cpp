#include <iostream>
#include <functional>
using namespace std;

template<typename T> struct xreference_wrapper
{
	T* obj;
	xreference_wrapper(T& t) : obj(&t) {}
	// T& 으로의 암시적 변환을 허용해야 한다.
	// 변환 연산자
	operator T&() { return *obj; }
};

int main()
{
	int n1 = 10;
	int n2 = 20;
//	int& r1 = n1;
//	int& r2 = n2;
	// C++11 이동 가능한 참조
	// 대입연산시 값이 아닌 참조가 이동
	xreference_wrapper<int> r1 = n1;
	xreference_wrapper<int> r2 = n2;

	int& r3 = r1; // reference_wrapper는 
					// 진짜 참조와도 호환됨.
				// r1.operator int&()

	r2 = r1; 

	std::cout << n1 << std::endl; // 10
	std::cout << n2 << std::endl; // 10
	std::cout << r1 << std::endl; // 10
	std::cout << r2 << std::endl; // 10
}



