#include <iostream>
using namespace std;

template<typename ... Types> struct xtuple 
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types> struct xtuple<T, Types...> : public xtuple<Types...>
{
	typedef xtuple<Types...> baseType;
	T value;
	xtuple() {}
	xtuple(const T& a, const Types& ... args) : value(a), baseType(args...) {}
	static constexpr int N = baseType::N + 1;
};


int main()
{
	// xtuple< short>
	// xtuple< double, short>
	xtuple<int, double, short> t3(3, 3.4, 5);

	cout << t3.value << endl; // 3
	// t3 안에 있는 3.4, 5 나오게 해보세요..

	cout << 
		static_cast<xtuple<double, short>&>(t3).value << endl; // 3

	cout <<
		static_cast<xtuple<short>&>(t3).value << endl; // 3

	// xget을 만들어 봅시다
	double d = xget<1>(t3);
}

template<int N, typename TP>
튜플 TP가 가진 N번재 요소의 타입&
xget(TP& tp)
{
	return static_cast<N번째기반클래스타입&>(tp).value;
}









