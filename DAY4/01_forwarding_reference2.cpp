#include <vector>
using namespace std;

// 218
int main()
{
	int n = 0;

	auto a1 = n; // ok   int a1 = n
	auto a2 = 0; // ok   int a2 = 0

	auto& a3 = n; // ok     int& a3 = n
	//auto& a4 = 0; // error  int& a4 = 0

	// 아래 코드는 rvalue reference 일까요 ?
	//            forwarding reference 일까요? - 답
	auto&& a5 = n; // n (lvalue) => auto(T) : int&
					// auto&& : int& && => int& a5 = n

	auto&& a6 = 0; // 0(rvalue) => auto(T) : int
				   // auto&& : int&&  int&& a6 = 0

	//vector<int> v(10);

	vector<bool> v(10);

	for (auto&& n : v)
	{
	}
}



