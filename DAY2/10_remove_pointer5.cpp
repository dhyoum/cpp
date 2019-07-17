#include <iostream>
#include <type_traits>
using namespace std;

// using 활용 - C++14/17
/*
template<typename T> 
using remove_pointer_t =
		typename remove_pointer<T>::type;
*/

template<typename T> void foo(T a)
{
	// 포인터 여부 조사
	bool b1 = is_pointer<T>::value;
	bool b2 = is_pointer_v<T>; // 위와 동일

	// 포인터를 제거한 타입 얻기
	//typename remove_pointer<T>::type n1;

	remove_pointer_t<T> n1; // 위와 동일한 표기법
				// 106 page 아래 쪽

	// cppreference.com 
}

int main()
{

	int n = 0;
	foo(&n);
}