// checked_delete
#include <iostream>
using namespace std;

class Test; // 클래스 전방 선언
			// 완벽한 선언이 없어도 포인터 사용가능
			// 불완전 타입(incomplete)
			// delete 할때 소멸자가 호출되지 않는다.
void foo(Test* p)
{
	//default_delete<int> d;

	// checked delete 
	static_assert(sizeof(Test) > 0,
			"ERROR, incomplete");

	delete p;
}

class Test
{
public:
	Test()  { cout << "Test()" << endl; }
	~Test() { cout << "~Test()" << endl; }
};

int main()
{
	Test* p = new Test;
	foo(p);
}

// C++ 기본문법 
// 객체 지향 디자인 기술들
// template 이나 고급 문법들(IDioms)
// STL  => C++20

