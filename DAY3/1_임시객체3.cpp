#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;
	Point(int a, int b) : x(a), y(b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

// 임시객체와 함수 인자 - 230 page
// 함수인자로 임시객체를 사용하는 경우가 많이 있다.
void foo(const Point& p)
{
}
int main()
{
//	Point pt(1, 2);
//	foo(pt);

	foo(Point(1, 2)); // 임시객체를 사용한 인자 전달

	cout << "---------" << endl;
}









