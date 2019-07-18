#include <iostream>
using namespace std;

// 120p. 추상 클래스인지 조사하는 기술
class Shape
{
public:
	//virtual void Draw() = 0;
};

// 추상 클래스는 배열을 가리키는 포인터를 만들수 
// 없습니다.
template<typename T> int  check( T(*a)[1] );
template<typename T> char check(...);

template<typename T> struct xis_abstract
{
	static constexpr bool value =
		(sizeof(check<T>(0)) == 1);
};

int main()
{
	cout << xis_abstract<Shape>::value << endl;


//	int n = sizeof(check<Shape>(0));
//	cout << n << endl; // 1
}
