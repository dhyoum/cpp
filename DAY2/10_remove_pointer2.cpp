#include <iostream>
using namespace std;

template<typename T> struct xremove_reference
{
	using type = T;
};
template<typename T> struct xremove_reference<T&>
{
	using type = T;
};

template<typename T> void foo(T a)
{
	// T에 의존적으로 사용하려면 typename 필요
	typename xremove_reference<T>::type n;
}
int main()
{
	// xremove_reference 만들어 보세요.
	xremove_reference<int&>::type n1; // int

	// 만든후 위코드가 에러나오지 않으면 됩니다
}