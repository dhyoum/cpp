#include <iostream>
using namespace std;

void goo(int a, double d, const char* s)
{
	cout << "goo" << endl;
}

// parameter pack, sizeof..., pack expansion
template<typename ... Types> 
void foo(Types ... args )
{
	// args : parameter pack 이라고 합니다.-128p
	// Types : template paramter pack

	// sizeof...(pack 이름)
	cout << sizeof...(args) << endl;
	cout << sizeof...(Types) << endl;

//	goo(args); // error. args는 pack 이다.

	// pack expansion : 팩안의요소를  , 를 사용해서
	//				나열 - 129
	goo(args...);  // goo(3, 4.5, "hello")
} 

int main()
{
	foo(3, 4.5, "hello");
}





