// 7_reference_wrapper
#include <iostream>
#include <functional>
using namespace std;

void foo(int& a) { a = 100; }

// 아래 함수가 bind 처럼 인자를 값으로 받고 있습니다.
template<typename F, typename T> 
void valueForwarding(F f, T arg) 
{
	f(arg);
}

// reference_wrapper를 만드는 도움함수
template<typename T>
reference_wrapper<T> xref(T& obj)
{
	return reference_wrappr(obj);
}


int main()
{
	int x = 0;

	//ValueForwarding(&foo, x); // 복사본이므로 안됨

	// 메모리 정보를 보내기 위해 주소를 보내면 어떨까?
	// ValueForwarding의 2번째 인자가 포인터 인데
	// 참조로 변환 될수 없어서 에러
	//ValueForwarding(&foo, &x); 

//	reference_wrapper<int> r = x;
//	valueForwarding(&foo, r);

//	valueForwarding(&foo, reference_wrapper<int>(x));

	valueForwarding(&foo, xref(x));

	std::cout << x << std::endl;
}





