#include <iostream>
#include <vector>
using namespace std;
// allocator

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) { std::cout << __FUNCSIG__ << std::endl; }
	
	~Point() { std::cout << __FUNCSIG__ << std::endl; }
};
int main()
{
	// C++ 표준 메모리 할당기
	std::allocator<Point> ax;

	Point* p = ax.allocate(2); // Point 2개할당
	cout << p << endl;

	// 생성자 호출
	ax.construct(p,   1, 2); // new(p) Point(1,2)
	ax.construct(p+1, 1, 2);

	// 소멸자 호출
	ax.destroy(p);
	ax.destroy(p+1);

	// 메모리 해지
	ax.deallocate(p, 2);
	


}


