#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

// 214 page
// aggregate
// aggregate type : 생성자 없어도 {} 로 초기화 가능한
//			타입. 배열, C구조체등
struct Point
{
	int x, y;

//	Point() {} // 이 요소 때문에 aggreate 아님
	
	Point() = default; // aggregate 

	void foo() {}

	virtual void goo() {}

//	Point() {}
//	Point(int a, int b) {}
};
int main()
{
	Point p1;
	Point p2 = { 0, 0 };

//	Point p2(0,0);
}

