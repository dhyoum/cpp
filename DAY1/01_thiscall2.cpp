#include <iostream>
using namespace std;

// 주제 : 일반 함수 포인터와 멤버 함수 포인터 - 7page
// 핵심 1. 일반함수 포인터에 멤버 함수의 주소를 담을수 없다.
// 핵심 2. 일반함수 포인터에 static 멤버 함수의 주소를 
//         담을수 있다.
// 3. 멤버 함수 포인터를 만들고 사용하는 방법
//    아래 main 참고, 교재 7~8 page 참고.
class Dialog
{
public:
	void Close(int a) {	cout << "Dialog::Close" << endl; }
	static void Close2(int a) { cout << "Dialog::Close2" << endl; }
};

void foo(int a) { cout << "foo" << endl; }

int main()
{
	void(*f1)(int) = &foo;  // ok
//	void(*f2)(int) = &Dialog::Close; // error
	void(*f2)(int) = &Dialog::Close2; // ok

	// 멤버 함수 포인터를 만드는 방법
	void(Dialog::*f3)(int) = &Dialog::Close; // 

	f3(0); // error. 객체가 없다.

	Dialog dlg;
	//dlg.f3(0); // error. f3이라는 멤버함수를 찾게된다.

	//dlg.*f3(0); // .* : pointer to member operator
				// 연산자 우선순위 문제로 error

	(dlg.*f3)(0);  // ok..  이 표현식이
				// 멤버 함수 포인터를 사용해서 함수를
				// 호출하는 표기법 입니다.  8page
	Dialog* pDlg = &dlg;
	(pDlg->*f3)(0);


}








