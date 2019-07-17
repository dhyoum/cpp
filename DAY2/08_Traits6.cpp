#include <iostream>
#include <type_traits>
using namespace std;

// 포인터 일때만 사용
template<typename T> void printv_imp(T a, YES)
{
	cout << a << " : " << *a << endl;
}

// 포인터가 아닐때만 사용
template<typename T> void printv_imp(T a, NO)
{
	cout << a << endl;
}

template<typename T> void printv(T a)
{
	// T의 포인터 여부에 따라 다른 함수 호출
	printv_imp(a, is_pointer<T>::value );
					// 
}


int main()
{
	int    n = 10;
	printv(n);
}





