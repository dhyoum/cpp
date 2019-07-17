#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

// aggregate
struct Point
{
	int x, y;
	Point() {}
	Point(int a, int b) {}
};

int main()
{
	Point p1;
	Point p2(0,0);
}

