#include <iostream>
using namespace std;

// 99 page
// traits의 종류
// 1. 타입 질의 : is_xxxx<T>::value
// 2. 변형 타입얻기 : xxx<T>::type

// 1. 구조체 템플릿을 만들고
// 2. typedef T type 또는 using type = T 넣기
// 3. 원하는 타입을 얻을수 있도록
//    부분 특수화 버전을 만든다.
//    int* 일때 int와 * 가 분리될수 있게 해야 한다
template<typename T> struct xremove_pointer
{
	//typedef T type;
	using type = T;
};
template<typename T> struct xremove_pointer<T*>
{
	//typedef T type;
	using type = T;
};
int main()
{
	xremove_pointer<int*>::type n; // int
}