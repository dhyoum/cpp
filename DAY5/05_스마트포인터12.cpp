#include <iostream>
#include <memory>
using namespace std;


struct Point
{
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

void* operator new(size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}

int main()
{
	// 아래 코드는 동적 메모리 할당을 몇번하게 될까요 ?
	shared_ptr<Point> sp(new Point(1, 2));

	// make_shared<Point>(1,2) 가 좋습니다.
	// 완벽한 전달자 소스 참고

}



