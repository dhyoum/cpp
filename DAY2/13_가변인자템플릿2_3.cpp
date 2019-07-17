#include <tuple>
using namespace std;

template<typename ... Types>
void foo(Types ... args)
{
	// args 안에 있는 요소를 꺼내는 방법

	// args에서 2번째 값을 알고 싶다 - 이렇게 직접
	//			접근할수 없다!!
	// 방법 1. pack expansion
	int arr[] = { args... };

	// 타입이 다르면 tuple
	tuple<Types...> t3(args...);
}

int main()
{
	foo(1, 2, 3);
}
