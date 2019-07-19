#include <iostream>
using namespace std;

template<typename T> class NamedType
{
	T value;
public:
	NamedType(const T& v) : value(v) {}
	T& get() { return value; }
};
using Width  = NamedType<int>;
using Height = NamedType<int>;

int main()
{
	Width  w = 10;
	Height h = 10;
	// 단점. widht와 height 가 동일 타입이다. 
	// 다른 타입이 되게 해보자.
	w = h;
	cout << w.get() << endl;
}

