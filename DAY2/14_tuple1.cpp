#include <iostream>
using namespace std;

// 가변인자 템플릿을 사용한 C++11 표준인 튜플 만들기..
// 145 page

// 문제점 : data를 한개만 보관한다.

// primary template
template<typename ... Types>
struct xtuple
{
	static constexpr int N = 0;
};
// 부분 특수화를 사용해서 1번째 인자는 타입의 이름을
// 알수 있도록 한다.
template<typename T, typename ... Types>
struct xtuple<T, Types...>
{
	T value;
	xtuple() = default; // 디폴트 생성자
	xtuple(const T& v) : value(v) {}
	static constexpr int N = 1;
};
int main()
{
	xtuple<short>              t1(1);
	xtuple<double, short>      t2(3.4);
	xtuple<int, double, short> t3(3);
}



