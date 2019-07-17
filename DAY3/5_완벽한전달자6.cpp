// 3_완벽한전달자
#include <iostream>
using namespace std;

int x = 0;

int& foo(int a) { return x; }

template<typename F, typename ... Types>
decltype(auto) chronometry(F f, Types&& ... args)
{

	return f(std::forward<Types>(args)...);
}

int main()
{
	int& r = chronometry(foo, 10);

	r = 10;

	cout << x << endl; // 10
}



