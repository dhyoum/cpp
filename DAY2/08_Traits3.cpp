#include <iostream>
using namespace std;

int a;    // a는 int 타입
double d; // d는 double
int x[3]; // x의 타입 int[3]
			// T[N]


// IsPointer를 참고해서 IsArray 만들어 보세요

template<typename T> struct IsArray
{
	static constexpr bool value = false;
	static constexpr int size   = -1;
};

template<typename T, int N> struct IsArray<T[N]>
{
	static constexpr bool value = true;
	static constexpr int size = N;
};

template<typename T> void foo(T& a)
{
	// T : int[3]
	if (IsArray<T>::value)
		cout << "배열 입니다. 크기는 " << IsArray<T>::size << endl;
	else
		cout << "배열 아님" << endl;
}
int main()
{
	int x[3] = { 1,2,3 };
	foo(x);					
}





