
#include <iostream>
using namespace std;
// 114 page

// 치환 실패는 에러가 아니다.
// Substitution Failure Is Not An Error
// 114 제일 아래줄

template<typename T> 
typename T::type  foo(T a) { cout << "T" << endl; return 0; }
// int::type foo(int a)

void foo(...) { cout << "..." << endl; }


int main()
{
	foo(10);
}



