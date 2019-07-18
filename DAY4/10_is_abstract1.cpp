// 10_is_abstract1
#include <iostream>
using namespace std;

// 121 page Step4 개념
int  foo(int);// { return 0; }
char foo(double);// { return 0; }

int main()
{
	int n = 0;

	sizeof(n);		 // 4
	sizeof(foo);     // error. sizeof(함수이름)

	// unevaluated expression : 평가되지 않은 표현식
	decltype(foo(3.4)) c;

	sizeof(foo(3.4));// sizeof(함수호출식)
					//=> 함수 호출 결과(반환타입)크기
}


