#include <iostream>
#include <type_traits>
using namespace std;

/*
class Test
{
public:
	int  foo() &  { return 0; }
	char foo() && { return 0; }
private:
	Test() {}
	~Test() {}
};
template<typename T> typename add_rvalue_reference<T>::type xdeclval();

int main()
{
	int n = sizeof(xdeclval<Test>().foo());

	cout << n << endl;
}
*/

template<typename T> 
add_rvalue_reference_t<T> foo()
{
	cout << __FUNCSIG__ << endl;
}
template<typename T>
T&& goo()
{
	cout << __FUNCSIG__ << endl;
}

int main()
{
	foo<void>();
	//goo<void>();
	foo<int(int)>();
	goo<int(int)>();

	int n = 0;

	//void& r1 = n;

//	add_rvalue_reference_t<void> t0 = 0;
	add_rvalue_reference_t<int> t1 = 0;
	add_rvalue_reference_t<int&> t2 = n;

	cout << is_object<void>::value << endl;
	cout << is_object<int>::value << endl;
	cout << is_object<int[]>::value << endl;
	cout << is_object<int[3]>::value << endl;
	cout << is_object<int&>::value << endl;
	cout << is_object<int&&>::value << endl;
	cout << is_object<int*>::value << endl;
	cout << is_object<decltype(main)>::value << endl;
	cout << is_object<decltype(&main)>::value << endl;
}