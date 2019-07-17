#include <iostream>
using namespace std;
// 교재에 없는 주제인데.. 200 page가 연관성이 있습니다.

// 컴파일 시간 상수와 vs 실행시간 상수

int main()
{
	//const int c = 10; // 컴파일 시간 상수

	int n = 10;
	const int c = n; // 실행시간 상수

//	int* p = &c; // error. 상수 주소를 
				// 비상수를 가리키는 포인터에 담을수 없다.

//	int* p = static_cast<int*>(&c); // error
	int* p = const_cast<int*>(&c); // ok
					// 상수성을 제거하는 캐스팅
	*p = 20;

	cout << c  << endl; // 10  20
	cout << *p << endl; // 20  20
}

