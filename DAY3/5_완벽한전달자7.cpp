#include <vector>
#include <memory> // C++ 표준 스마트포인터
#include <memory>
#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a = 0,   int b = 0) : x(a), y(b) { cout << "Point()" << endl; }
	~Point()						         { cout << "~Point()" << endl; }
};

void* operator new(size_t sz)
{
	cout << "new : " << sz << endl;
	return malloc(sz);
}

// C++ 표준의 make_shared 의 원리
template<typename T, typename ... Types>
shared_ptr<T> make_shared(Types&& ... args)
{
	// 1. sizeof(객체) + sizeof(관리객체)를
	//    한번에 할당
	void* p = operator new(sizeof(T) +
							sizeof(관리객체));
	// 2. 메모리 앞부분은 객체 입니다.
	//    생성자를 호출합니다.
	new(p) T (std::forward<Types>(args)...);

	// 3. 관리객체 생성자
	new((char*)p + sizeof(T)) 관리객체타입;

	// 4. shared_ptr만들어서 반환
	shared_ptr<T> sp;
	sp.reset(p, (char*)p + sizeof(T));
	return sp;
}

int main()
{
	// 아래 코드는 new를 몇번 사용할까요 ?
	// shared_ptr<Point> sp(new Point(1, 2));

	// sizeof(객체) + sizeof(관리객체)를 한번에 할당
	shared_ptr<Point> sp =
			make_shared<Point>(1, 2);

}






/*
int main()
{
	vector<Point> v;
	// 271 page
	// vector에 요소넣기 1.

	//Point pt(1, 2);
	//v.push_back(pt);

	// 2. 임시객체로 넣기
	// v.push_back(Point(1, 2));


	// 3. 객체를 전달하지 말고
	//  객체를 만들기 위한 생성자 인자를 전달하자.
	v.emplace_back(1,2);
			// emplace_back이 내부적으로
			// new Point(1,2) 합니다.

	cout << "---------" << endl;
}
*/


