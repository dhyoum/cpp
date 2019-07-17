#include <iostream>
using namespace std;
// T가 포인터인지 조사하는 기술

// traits : T의 다양한 특성을 조사하는 기술
// 76 page
// traits 만드는 방법 ( 76 page아래 부분)
// 1. 구조체 템플릿을 만든다.
// 2. value = false 를 넣는다.
// 3. 조건을 만족하는 부분특수화를 만들고
//    value = true 로 변경

template<typename T> struct IsPointer
{
//	enum { value = false };  // 예전 스타일

	// C++11이후에는 아래 처럼 만들게 됩니다.
	static constexpr bool value = false; 
};
template<typename T> struct IsPointer<T*>
{
	//enum { value = true };
	static constexpr bool value = true;
};

template<typename T> void foo(T a)
{
	if ( IsPointer<T>::value )
		cout << "포인터" << endl;
	else
		cout << "포인터 아님" << endl;
}


int main()
{
	int n = 10;
	foo(n);
	foo(&n);
}

