#include <iostream>
//#include "cppmaster.h"
using namespace std;

#define LOG_VALUE_CATEGORY(...)												\
	if(is_lvalue_reference<decltype((__VA_ARGS__))>::value)					\
		printf(  #__VA_ARGS__ " : lvalue\n" );							\
	else if (is_rvalue_reference<decltype((__VA_ARGS__))>::value)			\
		printf(  #__VA_ARGS__ " : rvalue(xvalue)\n" );		\
	else																	\
		printf(  #__VA_ARGS__ " : rvalue(prvalue)\n" );



// value 개념은 변수가 아닌 표현식에 부여되는
// 개념입니다. 237page
int main()
{
	int n = 0;
	n = 10;      // ok. n은 lvalue
	//n + 1 = 20;  // error. n+1 은 rvalue

	++n = 20; // ok. ++n은 lvalue
	//n++ = 20; // error. n++ 은 rvalue

	LOG_VALUE_CATEGORY(n);   // cppmaster.h에
	LOG_VALUE_CATEGORY(++n); // 있는 매크로 함수
	LOG_VALUE_CATEGORY(n++);

	const int c = 0;
	LOG_VALUE_CATEGORY(c);
}





