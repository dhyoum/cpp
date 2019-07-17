#include <iostream>
using namespace std;
/*
int mul(int a, int b)
{
	return a * b;
}
*/
/*
template<typename T>
T mul(T a, T b)
{
	return a * b;
}
*/
/*
template<typename T1, typename T2>
//decltype(a*b) mul(T1 a, T2 b)
auto mul(T1 a, T2 b) -> decltype(a*b)
{
	return a * b;
}
*/
// C++14 에서는 auto 만 표기해도 됩니다.
// return 문장을 가지고 리턴 타입을 결정
/*
template<typename T1, typename T2>
auto mul(T1 a, T2 b)
{
	return a * b;
}
*/
// return 문장의 표현이 참조 타입일때
// 참조를 유지하려면 - 223 page에 기록해 두세요
template<typename T1, typename T2>
decltype(auto) mul(T1 a, T2 b)
{
	return a * b;
}


int main()
{
	cout << mul(3, 4.2) << endl;

	
//	a = 10; // error
//	int a;
//	a = 10;
}




