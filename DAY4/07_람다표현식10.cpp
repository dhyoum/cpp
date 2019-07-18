#include <iostream>
using namespace std;

/*
// 함수 인자는 결국 지역변수입니다.
void goo(int a, int b)
{
	int c;
	auto f = [=]() {return a + b +c; }; // ok..

	cout << sizeof(f) << endl; // 12
}
*/

class Test
{
	int data;
public:
	void foo()  
	{
		// 멤버 변수 캡쳐
		auto f = [](int a) { return data + a; };//error
		
		//error. data 는 지역변수 아님
		auto f = [data](int a) { return data + a; };

		// ok.. 멤버 데이타에 접근 하려면 this 캡쳐
		auto f = [this](int a) { data = 10; return data + a; };
		auto f = [=](int a) { return data + a; }; // ok

		// *this 캡쳐 : C++20
		//auto f = [*this](int a) { data = 10; return data + a; };
	}

};

int main()
{
	Test t;
	t.foo(); // foo(&t)
}


