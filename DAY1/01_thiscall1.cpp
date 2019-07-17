#include <iostream>
using namespace std;

// 교재 6 page ~
// 주제 : 멤버 함수의 호출원리

// 핵심 1. 멤버 함수는 인자로 this 가 추가된다.
//      2. static 멤버 함수는 인자로 this가 추가되지 
//			않는다.
class Point
{
	int x;
	int y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	void set(int a, int b) // set(Point* this , int a, int b)
	{
		x = a; // this->x = a
		y = b; // this->y = b
	}

	static void foo(int a) // foo(int a)
	{
		x = a; // this->x = a로 변경해야 하는데
				//this 가 없다.
		// 그래서, static 멤버함수에서는
		// 멤버 데이타에 접근이 안된다. 
	}
};

int main()
{
	Point::foo(10); // 객체없이 호출가능

	Point p1, p2;

	p1.set(1, 2); // set(&p1, 10, 20) 의 원리입니다
				  // push 20
				  // push 10  진짜 인자는 스택으로
				  // mov ecx, &p1 // 객체는 레지스터에
				  // call Point::set

	getchar();
}
