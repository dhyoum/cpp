#include <iostream>
#include <string>
#include <complex>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::chrono;

// 표준 literal을 모두 사용하려면 - 184p 에 추가해놓으세요
using namespace std::literals;




void foo(string s) { cout << "string" << endl; }
void foo(const char* s)  { cout << "char*" << endl; }

int main()
{
	foo("hello"); // const char*
	foo("hello"s); // string operator""s(const char*)

	complex<double> c1(3, 0); // 3 + 0i
	complex<double> c2(3);  // 3 + 0i
	complex<double> c3(3i); // 0 + 3i

	seconds sec = 1h + 3min + 20s;

	cout << sec.count() << endl;

	this_thread::sleep_for(10s); // 재우는 함수
	// 10s : seconds operator""s(10)


}









