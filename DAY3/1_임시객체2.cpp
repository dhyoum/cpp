#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;
	Point(int a, int b) : x(a), y(b) { cout << "Point()" << endl; }
	~Point()                         { cout << "~Point()" << endl; }
};
// 임시객체의 특징 - 228 page
int main()
{
	Point p(1, 2); 
	
	Point* p1 = &p;           // ok
//	Point* p2 = &Point(1, 2); // error
					// 임시객체는 주소를 구할수 없다.


	p.x = 10;           // ok..
//	Point(1, 2).x = 10; // error. 임시객체는
						// lvalue가 될수 없다.
						 
	Point& r1 = p;		// ok
//	Point& r2 = Point(1, 2); // error


	// 핵심 : 임시객체는 상수 참조로 가리킬수 있다.
	const Point& r2 = Point(1, 2);
		// 임시객체의 수명이 r2의 수명으로 연장됩니다.

	r2.x = 10; // error. const 참조 이므로

	// C++11의 새로운 참조는 상수성없이
	// 임시객체를 가리킵니다.
	Point&& r3 = Point(1, 2);
	r3.x = 10; // ok
}






