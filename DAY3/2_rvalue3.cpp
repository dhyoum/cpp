#include <iostream>
using namespace std;

// 참조와 함수 오버로딩 - 239 page
void foo(int& a)       { cout << "int&" << endl; }       // 1
void foo(const int& a) { cout << "const int&" << endl; } // 2
void foo(int&& a)      { cout << "int&&" << endl; }      // 3

int main()
{
	int n = 10;

	foo(n);  // 1번 호출, 없으면 2번

	foo(10); // 3번 호출, 없으면 2번

	int& r1 = n;
	foo(r1); // 1번호출, 없으면 2번 호출

	int&& r2 = 10; // 10은 rvalue이지만
					// r2는 이름있는 변수 이므로
					// lvalue입니다.

			// "named rvalue reference is lvalue"

	foo(r2); // 핵심.. 1

	foo(static_cast<int&&>(r2)); // 3

}