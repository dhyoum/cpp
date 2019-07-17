#include <iostream>
using namespace std;


// 아래 코드가 정말 중요한 도구 입니다.
template<int N> struct int2type
{
	enum { value = N };
};


/*
int main()
{
	foo(0);
	foo(1); // 0, 1은 같은 타입
			// foo(0), foo(1)은 같은 함수 호출

	int2type<0> t0;
	int2type<1> t1;

	foo(t0);
	foo(t1); // t0와 t1은 다른 타입 입니다.
			 // foo(t0)와 foo(t1)은 다른 함수 호출
			 // 86page
}
*/


//구글에서 "C++ Idioms"  첫번째 링크

// 포인터 일때만 사용
template<typename T> void printv_imp(T a, int2type<1>)
{
	cout << a << " : " << *a << endl;
}
// 포인터가 아닐때만 사용
template<typename T> void printv_imp(T a, int2type<0>)
{
	cout << a << endl;
}

template<typename T> void printv(T a)
{
	printv_imp(a, 
		int2type<is_pointer<T>::value>() );
		// int2type<0>() 
}




int main()
{
	int    n = 10;
	printv(n);
}



