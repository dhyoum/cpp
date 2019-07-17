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

	Object& operator=(Object&& o ) noexcept
	{
		cout << "Copy =" << endl;
		if (&o == this) return *this;
		data = move(o.data);
		return *this;
	}
};

// move 와 상수 객체

int main()
{
	// 254 page
	const Object o1;

	Object o2 = o1;      // 복사
	Object o3 = move(o1);// move 아니라 복사
				// static_cast<const Object&&>(o1)

	// const object 는 move 될수 없습니다.
}




