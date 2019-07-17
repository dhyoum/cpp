#include <iostream>
using namespace std;

// traits 기술을 사용하기 위한 표준 헤더
#include <type_traits>


template<typename T> void foo_imp(T a, true_type)  
{
	*a = 10; // ok.. 아무 문제 없다.
}

template<typename T> void foo_imp(T a, false_type) {}


template<typename T> void foo(T a)
{
	// T가 포인터 인지 조사하는 3가지 방법. 96
	// 방법 1. is_pointer<T>::value 를 if로 조사
	if (is_pointer<T>::value)
	{
		//*a = 10; // 단, 이런 표기법은 사용할수 없다.
	}
	else
	{
	}

	// 방법 2. true_type/false_type을 사용한
	//         함수 오버로딩
	foo_imp(a, is_pointer<T>());


	// 방법 3. is_pointer<T>::value 를 if constexpr로 조사
	//      C++17 
	if constexpr (is_pointer<T>::value)
	{
		*a = 10; // ok  
	}
}



int main()
{
	int n = 0;
	foo(n);
}




