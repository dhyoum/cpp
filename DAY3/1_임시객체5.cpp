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

// 231 page
// call by value : 복사본을 생성한다.
void goo(Point pt) {}


Point p(0, 0); 

// return by value : 임시객체를 생성해서 반환된다.
//			리턴용 임시객체는 함수호출구문의 끝에서파괴
Point foo()   
{
	return p;
}
// 참조 반환 : 임시객체를 만들지 말라는 의미. 233 p
Point& goo()  
{
	return p;
}

int main()
{
	//foo().x = 10; // error
	goo().x = 10; // ok
	cout << p.x << endl;
}









