#include <iostream>
using namespace std;

// 130 page 아래 코드
template<typename T> void print(T a)
{
	cout << a << endl;
}

template<typename ... Types>
void foo(Types ... args)
{
	//print(args...); // error
	//print(args)...;// print(E1), print(E2), 
					// print(E3)

	// pack 은 함수인자, 배열 초기화 등에서만
	// 확장 가능
	//args...; // error
	int x[] = { args... }; //ok

	int dummy[] = { 0, (print(args), 0)... };
			// { (print(1), 0), print(2), print(3)}
}
   
int main()
{
	foo();
	foo(1, 2, 3);
}
