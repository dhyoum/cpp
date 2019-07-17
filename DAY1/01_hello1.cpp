#include <iostream>
#include <string>
#include <complex>
#include <chrono>
using namespace std;
using namespace std::chrono;

void foo(string)		{ std::cout << "string" << endl; }
void foo(const char* )	{ cout << "const char*" << endl; }

int main()
{
	int n1 = 0b1;   // 2진수 표기법 가능.
	int n2 = 1'000'000; // digit separator

	int x[3] = { 1,2,3 };

	// auto : 우변의 표현식으로 좌변의 타입 결정
	auto n3 = x[0];

	decltype(n2) n4; // () 안의 타입과 동일타입

	//decltype(x[0]) n5; // int&

	for (int i = 0; i < 3; i++)
		cout << x[i] << endl;

	// C++11 range for
	for (auto&& n : x)
		cout << n << endl;

	foo("hello"); // const char*
	foo("hello"s); // STL string

	seconds sec = 1h + 2min + 30s;
	cout << sec.count() << endl;

}










