#include <iostream>
using namespace std;

template<typename T, typename Parameter> 
class NamedType
{
	T value;
public:
	NamedType(const T& v) : value(v) {}
	T& get() { return value; }
};

/*
struct WidthParameter {};
using Width  = NamedType<int, WidthParameter>;
struct HeightParameter {};
using Height = NamedType<int, HeightParameter>;
*/

using Width = NamedType<int, struct WidthParameter>;
using Height = NamedType<int, struct HeightParameter>;
using xPos = NamedType<int, struct xPosParameter>;
using yPos = NamedType<int, struct yPosParameter>;

void foo(Width w, Height h)
{
}
int main()
{
	foo(Width(10), Height(20)); // 이렇게 사용하자는 것

	Width  w = 10;
	Height h = 10;

	w = h;
	cout << w.get() << endl;
}

