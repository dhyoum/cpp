#include <iostream>
#include <memory>
using namespace std;

int main()
{
	int* p = new int;

	// 아래 코드를 평가해 보세요
	shared_ptr<int> sp1(p);
	shared_ptr<int> sp2(p); // sp1과는 다른
					// 별개의 관리객체 사용
					// 절대 이렇게 사용하면 안됩니다.

	// 자원을 획득하는 것은 꼭! 자원 관리 객체가
	// 초기화 될때 해야 한다.
	// Resouce Acquision Is Initialization
	// RAII IDioms

}

