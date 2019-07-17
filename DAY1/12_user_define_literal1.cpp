#include <iostream>
using namespace std;

// 183 page
// 사용자 정의 Literal 함수
// 정수 Literal : 인자를 unsigned long long 
// 실수         : long double
// 문자열       : const char*, size_t 로 전달..

class Meter
{
	int value;
public:
	Meter(int n = 0) : value(n) {}
};

Meter operator""_m(unsigned long long n)
{
	cout << "operator m" << endl;

	Meter m(n);
	return m;
}
int main()
{
	float f = 3.4f;

	Meter v = 10_m; // operator""m(10) 함수를
					// 찾게 됩니다.

}







