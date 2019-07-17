#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;
	
	Point(int a, int b) : x(a), y(b) {}

	Point()
	{
		Point(0, 0); // 생성자에서 다른 생성자 호출?

	}
};

int main()
{
	Point p;

	cout << p.x << endl;
}




