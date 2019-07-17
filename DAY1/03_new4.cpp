#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b) {}
};

int main()
{
	// 힙에 Point 한개를 만들어 보세요
	Point* p1 = new Point(0, 0);

	// 힙에 Point 10개를 만들어 보세요
	//Point* p2 = new Point[10]; // ?

	// 메모리 할당과 생성자 호출을 분리하면 편리하다
	Point* p3 = static_cast<Point*> (
		operator new(sizeof(Point) * 10));

	// 10개의 메모리에 객체를 생성한다.(생성자 호출)
	for (int i = 0; i < 10; i++)
		new( &p3[i] ) Point(0, 0);

	// 객체파괴
	for (int i = 0; i < 10; i++)
		p3[i].~Point();

	// 메모리 해지
	operator delete(p3);
}







