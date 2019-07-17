#include <iostream>
using namespace std;
// goo 타입 : int(char, double)
int goo(char c, double d) 
{
	return 0; 
}

// 1. primary template 만들고 type 넣기
template<typename T> struct result_type
{
	using type = T;
};
// 2. 원하는 타입을 얻을수 있도록 부분 특수화 합니다.
// 이 부분이 중요!!
template<typename R, typename A1, typename A2> 
struct result_type<R(A1, A2)>
{
	using type = R;
};

template<typename T> void foo(T& a)
{
	// 함수 반환타입 조사하기.(단, 함수의 인자가 2개일때만)
	// T:int(char, double)
	typename result_type<T>::type n = 0;		  // int 

	cout << typeid(n).name() << endl;
}

int main()
{
	foo(goo);
}



