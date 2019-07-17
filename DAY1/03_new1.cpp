#include <iostream>
using namespace std;

// 1. new의 정확한 동작 방식 - 23 page

// (A). operator new()라는 함수로 메모리 할당
// (B). (A)가 성공하면 생성자 호출
// (C). 주소를 해당 타입으로 반환

class Point
{
	int x, y;
public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

int main()
{
//	Point* p1 = new Point;
//	delete p1;

	// 생성자 호출없이 메모리만 할당하는 방법
	Point* p2 = static_cast<Point*>(
			operator new(sizeof(Point)));

	// 할당된 메모리에 생성자를 호출 - 이번시간핵심
	new (p2) Point;

	// 소멸자 호출
	p2->~Point();

	operator delete(p2); // 메모리 해지
}













// PC 암호 

// "멀캠" 입니다










