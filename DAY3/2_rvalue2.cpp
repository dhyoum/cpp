// 2_rvalue2.cpp
// rvalue와 참조 문법 - 238

int main()
{
	int n = 10;

	// 규칙 1. non const lvalue reference는 lvalue 만 참조할수 있다.
	int& r1 = n; // ok
	int& r2 = 10;// error

	// 규칙 2. const lvalue reference는는 lvalue 와 rvalue 모두 참조할수 있다.
	const int& r3 = n; // ok
	const int& r4 = 10;// ok

	// 규칙 3. rvalue reference는 rvalue만 가리킬수
	//		  있다
	int&& r5 = n; // error
	int&& r6 = 10;// ok

	//Point&& r = Point(0, 0);
}






