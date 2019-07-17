#include <iostream>
using namespace std;

/*
// C++11 표준
// int2type을 발전 시켜 만든 도구
template<typename T, T N> struct integral_constant
{
	static constexpr T value = N;
};

integral_constant<short, 0> s0;
integral_constant<short, 1> s1;
integral_constant<int, 0>   n0;

// 아래 코드가 중요합니다.
// true / false : 참거짓을 나타내는 값.  같은타입
// true_type / false_type : 참 거짓을 나타내는 타입.
typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

// 이제 is_pointer를 아래 처럼 만듭니다.
template<typename T> struct is_pointer : false_type {};

template<typename T> struct is_pointer<T*>:true_type {};
*/
// 위 코드가 아래 헤더에 있습니다.
#include <type_traits>

template<typename T> void printv_imp(T a, true_type)
{
	cout << a << " : " << *a << endl;
}
template<typename T> void printv_imp(T a, false_type)
{
	cout << a << endl;
}
template<typename T> void printv(T a)
{
	printv_imp(a, is_pointer<T>()); 
}


int main()
{
	int    n = 10;
	printv(n);
}



