#include <iostream>
#include <type_traits>
using namespace std;

// printv 만들기 
// 1. is_pointer, true_type, false_type
// 2. enable_if
// 3. if constexpr
/*
// 방법 3
template<typename T> void printv(T v)
{
	if constexpr ( is_pointer<T>::value )		
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}

// 방법 1. true_type/false_type
template<typename T> void printv_imp(T v, true_type)
{
	cout << v << " : " << *v << endl;
}
template<typename T> void printv_imp(T v, false_type)
{
	cout << v << endl;
}
template<typename T> void printv(T v)
{
	printv_imp(v, is_pointer<T>());
}
*/
// 방법 2. enable_if 를 사용하는 기술
// 구글에서 "android source github"
// platform_system_core 
// libutils/include/utils/type_helpers.h
// 에서 copy_type 찾으세요.. 함수 모양 보세요.

template<typename T> 
//typename enable_if<is_pointer<T>::value>::type
enable_if_t<is_pointer_v<T>>
printv(T v)
{
	cout << v << " : " << *v << endl;
}
template<typename T> 
enable_if_t<!is_pointer_v<T>>
printv(T v)
{
	cout << v << endl;
}
int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}



