#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
using namespace std;

// move와 예외

class Object
{
	string data;
public:
	Object() = default;
	~Object() {}

	Object(const Object& o) : data(o.data)      { cout << "Copy Ctor" << endl; }

	Object& operator=(const Object& o)
	{
		cout << "Copy =" << endl;
		if (&o == this) return *this;
		data = o.data;
		return *this;
	}

	// noexcept : 함수가 예외가 없다고 컴파일러에게
	//           알려 주는 것

	// move 계열 함수를 만들때
	// 1. 예외가 없도록 만들고
	// 2. 함수 () 뒤에 noexcept를
	// 붙이는 것이 좋다.
	// noexcept : 예외가 없다.
	// noexcept(true) : 예외가 없다.
	// noexcept(false) : 예외가 있다
	Object(Object&& o)
		noexcept( 
			is_nothrow_move_constructible<string>::value )
		: data(move(o.data))
	{
		cout << "Move Ctor" << endl; 
	}

	Object& operator=(Object&& o) noexcept(
		is_nothrow_move_constructible<string>::value)
	{
		cout << "Move =" << endl;
		if (&o == this) return *this;
		data = move(o.data);
		return *this;
	}

};

int main()
{
	vector<Object> v(5);
	v.resize(10);

	Object o1;
	Object o2 = o1; // 복사생성자
	Object o3 = std::move(o1); // move생성자
	Object o4 = std::move_if_noexcept(o2);
				// 예외가 없으면 move
				// 예외가 있으면 복사 생성자 호출
}




