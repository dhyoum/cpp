#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b) :x(a), y(b) {}
};

template<typename T> class Vector
{
	T* buff;
	int size;
public:
	Vector(int sz) : size(sz)
	{
	}
};

int main()
{
	Vector<int> v(10);
}