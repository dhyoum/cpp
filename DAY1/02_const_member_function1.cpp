#include <iostream>
using namespace std;

class Point
{
public:
	int x;
	int y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}
	void set(int a, int b) { x = a; y = b; }

	void print() //const // 상수 멤버 함수
	{
//		x = 10;  // error. 상수 멤버함수에서는
				 // 모든 멤버가 상수취급 된다.
				 // 값을 변경할수 없다.
		cout << x << ", " << y << endl;
	}
};

int main()
{
	const Point p(1, 2); // 상수 객체

	p.x = 10;     // error
	p.set(10, 20);// error
	p.print();    // error.

	// 핵심 : 상수 객체는 상수 멤버 함수만
	//	      호출할수 있습니다 - 17page 위쪽
	//		  위에서 print 멤버 함수는 
	//			반드시 상수 멤버 함수 이어야 합니다
}




