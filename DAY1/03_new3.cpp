#include <iostream>
using namespace std;

// 28 page
class Point
{
	int x, y;
public:
	Point()  { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};
// 아래 함수가 중요 합니다.
// 아래 함수의 목표는 메모리 할당이 아니라
// 기존 메모리에 대해 생성자를 호출하기 위한 만든것 입니다
// 아래 함수는 C++ 표준에 있습니다.
// "placement new"라고 합니다.
/*
void* operator new(size_t sz, void* p)
{
	return p;
}
*/
int main()
{
	Point p;

	//new Point; // 인자가 한개인 operator new()사용
	new(&p) Point; // ok. 위에 만든 함수 사용.



	//p.Point(); // 생성자의 명시적 호출 - error
	p.~Point();// 소멸자의 명시적 호출 - ok.
}

// malloc : 메모리 할당
// new    : 객체 생성 ( 메모리 할당 + 생성자호출)

// new Point     : 새로운 메모리에 객체를만들어달라
// new(&p) Point : 이미 존재하는 메모리에 
//					객체를 만들어 달라.

// linux 공유 메모리 할당
Queue* p = (Queue*)mmap(sizeof(Queue));
new(p) Queue; // 생성자만 호출







