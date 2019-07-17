#include <iostream>
using namespace std;

// 핵심 : 복사 생성자를 const lvalue reference로 
//			만드는 이유!

class Point
{
	int x = 0;
	int y = 0;
public:
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}

	// 복사 생성자 모양에 대해서
	// 1. call by value
	// 복사 생성자가 무한히 호출되는 표기입니다.
	// 컴파일 에러
	//Point(Point pt) {} // Point pt = p2
	// 2. call by reference
	// 단점 : 임시객체(rvalue)를 받을수 없습니다.
	//       값타입을 반환하는 함수의 리턴값을 받을수
	//		 없다.
	//Point(Point& pt) {}

	// 3. const lvalue reference
	Point(const Point& pt) 
		: x(pt.x), y(pt.y) {}
};

Point foo()
{
	Point pt;
	return pt;
}
int main()
{
	Point p1;
	Point p2(1, 2);
	Point p3(p2); //Point(Point) 모양의 생성자필요
	Point p4 = foo();
}