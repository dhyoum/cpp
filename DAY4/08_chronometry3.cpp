#include <iostream>
using namespace std;

class Test
{
public:
	void foo(int) { cout << "Test foo" << endl; }
};

void foo(int a, int b) {}

template<typename F, typename ... Types> 
decltype(auto) chronometry(F&& f, Types&& ... args)
{
	//return std::forward<F>(f)(std::forward<Types>(args)...);
	//return invoke(f, args...);

	// invoke : C++17
	return invoke(std::forward<F>(f), 
				  std::forward<Types>(args)...);
}
int main()
{
	chronometry(&foo, 10, 20);

	Test test;
	chronometry(&Test::foo, &test, 10);
}