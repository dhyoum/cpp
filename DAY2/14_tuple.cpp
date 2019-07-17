#include <iostream>
#include <tuple>
using namespace std;

// 가변인자 템플릿을 사용한 C++11 표준인 튜플 만들기..

tuple<int, double> goo() {}

int main()
{
	int x[2] = { 1,2 };

	tuple<int, double> t2(1, 3.4);
	tuple<int, double, short> t3(1, 3.4, 2);

	double d = get<1>(t3);
	int n    = get<0>(t3);
}



