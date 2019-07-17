#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;
	Point(int a, int b) : x(a), y(b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }

	Point(const Point& p) { cout << "copy ctor" << endl; }
};

// 임시객체와 함수 리턴
// 지역변수는 절대로 참조반환하면 안됩니다.
/*
Point& foo()    // 버그..!
{
	Point p(1, 2);
	return p;  
}
*/
Point foo()
{
	// 요즘에는 아래 처럼 반환해도
	// 최적화 됩니다.
	// Named RVO ( NRVO)
	// cafe.naver.com/cppmaster
//	Point p(1, 2);
//	return p;

	// 만들고 리턴하지 말고
	// 만들면서 리턴하자
	// RVO ( Return Value Optimization ) 232 아래부분  
	return Point(1, 2);
}

int main()
{

	Point p1(0, 0);

	p1 = foo();

	cout << "---------" << endl;
}









