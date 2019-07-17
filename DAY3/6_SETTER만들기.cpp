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

// setter 만들기 - 251p.
// 중요 합니다. 꼭 알아 두세요
class Data
{
	Object obj;
public:
	// 1. call by value
	//void setObject(Object o) { obj = o; }

	// 2. const lvalue reference
	//void setObject(const Object& o) { obj = o; }   // 항상 copy
	//void setObject(const Object& o) { obj = move(o); } //항상 copy. const object

	// 3. C++11 부터는 2개의 setter를 만드는 것이
	//    좋습니다. -아래 코드는 최고의 코드입니다.
	//void setObject(const Object& o) { obj = o; }
	//void setObject(Object&& o)      { obj = move(o); }





	// 4. call by value는 어떨까요 ?
	// move가 충분히 빠르다면 call by value도
	// 아주 나쁘지는 않다.
	//void setObject(Object o) { obj = move(o); }

	// github.com/webkit
	// source/wtf/wtf/scope.h

	// 5. forwarding reference를 사용하면
	// 3번처럼 만들수 있다 - 256 아래 코드
	template<typename U> 
	typename enable_if< is_same<
		typename decay<U>::type, 
		Object>::value >::type
	setObject(U&& o)
	{
		// 다음중 맞는것은 ?
	//	obj = o; // 1
	//	obj = std::move(o); // 2
		obj = std::forward<U>(o); // 3
	}
};
// modern C++ design => int2type 을 만든 사람의 책
int main()
{
	Data d1;
	Object o1;

	//d1.setObject(3.4);

	d1.setObject(o1);	// 3번 :복사 1회
						// 4번 :복사 1회, move1회
	d1.setObject(move(o1));// Move 1회
						   // Move 2회

	vector<int> v;
	v.push_back(10); 
	v.push_back(move(10));

}







