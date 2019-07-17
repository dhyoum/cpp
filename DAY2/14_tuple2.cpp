#include <iostream>
using namespace std;


template<typename ... Types>
struct xtuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct xtuple<T, Types...> : xtuple<Types...>
{
	using BaseType = xtuple<Types...>;
	
	T value;
	xtuple() = default; 

	xtuple(const T& v, 
		  const Types& ... args) 
			: value(v), BaseType(args...) {}

	static constexpr int N = BaseType::N + 1;
};
int main()
{
	xtuple<>				   t0;
	xtuple<short>              t1(1);
	xtuple<double, short>      t2(3.4);
	xtuple<int, double, short> t3(3, 3.4, 1);
}

