#include <iostream>
using namespace std;
// C++ 참조 : 개념적으로 const 입니다.
//            대입 연산시 참조가 이동하지 않고
//			  참조가 가리키는 값이 이동합니다.
int main()
{
	int n1 = 10;
	int n2 = 20;
	int& r1 = n1;
	int& r2 = n2;

	r2 = r1; // 이 한줄의 의미를 잘생각해 보세요

	std::cout << n1 << std::endl; // 10
	std::cout << n2 << std::endl; // 10
	std::cout << r1 << std::endl; // 10
	std::cout << r2 << std::endl; // 10
}

