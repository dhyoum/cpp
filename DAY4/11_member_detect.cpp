#include <iostream>
#include <vector>
using namespace std;

// 11_member detect

class Test
{
public:
	Test(int) {}
	void resize(int n) {}
private:
	~Test() {}
};

//Test xdeclval(); // 핵심. 선언만 하세요,.

// cppreference.com 에서
// declval 찾아 보세요.
//template<typename T> T&& xdeclval();

template<typename T> 
add_rvalue_reference<T>::type xdeclval();

//template<typename T> 
//int  check( decltype( T().resize(1) )*  a );

template<typename T> 
int  check( decltype( xdeclval<Test&&>().resize(1) )*  a );


template<typename T> char check(...);

template<typename T> struct has_resize_function
{
	static constexpr bool value =
		(sizeof(check<T>(0)) == 4);
};

int main()
{
	cout << 
		has_resize_function<Test>::value << endl;

}
