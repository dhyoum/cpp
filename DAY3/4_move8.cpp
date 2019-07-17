#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
using namespace std;


class Object
{
	string data;
public:
	Object() = default;
	~Object() {}

	Object(const Object& o) : data(o.data) { cout << "Copy Ctor" << endl; }

	Object& operator=(const Object& o)
	{
		cout << "Copy =" << endl;
		if (&o == this) return *this;
		data = o.data;
		return *this;
	}

	Object(Object&& o) noexcept : data(move(o.data)) { cout << "Move Ctor" << endl; }

	Object& operator=(Object&& o)noexcept
	{
		cout << "Move =" << endl;
		if (&o == this) return *this;
		data = move(o.data);
		return *this;
	}
};

// 자동생성되는 함수들

// 규칙 1. 
// 복사 계열과 move 계열을 모두 만들지 않으면
// 컴파일러 모두 제공
// 복사 계열에서는 모든 멤버를 복사해주고
// move 계열에서는 모든 멤버를 move해준다.

// 규칙 2.
// 복사 계열을 사용자가 제공하면
// 컴파일러는 move 계열을 제공하지 않는다.
// move 시에도 사용자가 만든 복사 생성자를 사용하게 된다.

// rule of 0 : 자원을 직접 관리하지 말고
//			자원 관리 클래스를 사용하자.!!
// 복사계열과 move계열을 사용자가 만들 필요 없다.
class Data
{
//	string s;
//	vector<int> v;
	Object obj;
public:
	Data() = default;
	Data(const Data& d) : obj(d.obj) {}
};

int main()
{
	Data d1;
	Data d2 = d1;
	Data d3 = move(d1);
}




