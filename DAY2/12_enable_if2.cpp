#include <iostream>
#include <type_traits>
using namespace std;

// 117page
// 모든 정수 타입에 대해서만 코드를 생성하는 
// 템플릿를 만들고 싶다.
/*
template<typename T> void foo(T a)
{
	// 방법 1. static_assert
	// 특징 : 조건을 만족하지 않으면 무조건 에러
	static_assert(is_integral<T>::value,
				"error not integer type");
}
*/
// 방법 2. enable_if 사용 - 117 마지막 코드
// 특징 : 조건을 만족하지 못하면 에러가 아니라!
//        후보군에서 빠진다는 의미.
//        동일 이름의 다른 함수가 있다면 사용가능
template<typename T> 
typename enable_if<is_integral<T>::value>::type
foo(T a)
{
	cout << "T" << endl;
}

void foo(double) { cout << "double" << endl; }

int main()
{
	foo(10);
	foo(3.4);
	foo(3.4f);
}
