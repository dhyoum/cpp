#include <iostream>
using namespace std;

struct Point 
{
	int x, y; 

	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

int main()
{
	Point p1 = { 1, 3 };

	cout << p1.x << endl;
	cout << p1.y << endl;
}





