#include <iostream>
#include <type_traits>
using namespace std;



template<typename T> void printv(T a)
{
	//if ( is_pointer<T>::value ) // if (false)

	if constexpr( is_pointer<T>::value )
		cout << a << " : " << *a << endl;
	else
		cout << a << endl;
}



int main()
{
	int    n = 10;
	printv(n);   // 1
//	printv(&n);  // 2
}
// 왜 에러일까요 ? 1이 문제 일까요 2가 문제일까요?




