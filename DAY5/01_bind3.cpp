#include <iostream>
#include <functional>
using namespace std::placeholders;
using namespace std;

void foo(int a, int& b) { b = 100; }

int main()
{
	function<void(int)> f;

	int n = 0;
	// 아래 코드는 n을 값으로 고정 합니다.
	//f = bind(&foo, _1, n); // 이순간 n을 참조로 보관?
							// 아니면 n의 값을 보관

	f = bind(&foo, _1, ref(n)); // n을 참조로 고정

	f(0); // foo(0, n)

	cout << n << endl; // 얼마 나올까요 ? 0 ? 100
}




