#include <iostream>
using namespace std;


template<typename T, typename ... Types> struct xtuple : public xtuple<Types...>
{
	typedef xtuple<Types...> baseType;
	T value;
	xtuple() {}
	xtuple(const T& a, const Types& ... args) : value(a), baseType(args...) {}
	static constexpr int N = baseType::N + 1;
};
template<typename T> struct xtuple<T>
{
	T value;
	xtuple() {}
	xtuple(const T& a) : value(a) {}
	static constexpr int N = 1;
};

template<int N, typename T> struct xtuple_element_type
{
	typedef T type;
};
template<typename T, typename ... Types>
struct xtuple_element_type<0, xtuple<T, Types...>>
{
	typedef T type; 
	typedef xtuple<T, Types...> tupleType; 
};


template<int N, typename T, typename ... Types>
struct xtuple_element_type<N, xtuple<T, Types...>>
{
	typedef typename xtuple_element_type<N - 1, xtuple<Types...>>::type      type;
	typedef typename xtuple_element_type<N - 1, xtuple<Types...>>::tupleType tupleType;
};

//--------------------------------------------------------------
template<typename T> void foo(T& tp)
{
	typename xtuple_element_type<2, T>::type n;      // 1번째 요소 타입
	typename xtuple_element_type<2, T>::tupleType t; // 1번째 요소를 저장하는 부모타입

	cout << typeid(n).name() << endl;
	cout << typeid(t).name() << endl;
}

template<int N, typename T> 
typename xtuple_element_type<N, T>::type&  
xget(T& tp)
{
	return (static_cast<typename 
		xtuple_element_type<N, T>::tupleType&>(tp)).value;
}

int main()
{
	xtuple<int, double, short> t3(3, 3.4, 5);

	xget<0>(t3) = 20;

	int ret = xget<0>(t3);
	cout << ret << endl;

	cout << xget<1>(t3) << endl; // 3.4
}









