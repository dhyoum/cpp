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

//-----------------
// tuple에서 N번째 요소의 타입구하는 기술

template<int N, typename TP> 
struct xtuple_element_type
{
	// 튜플 TP에서 N번째 요소의 타입은 ?
	// 구할수 없다. 구할수 있게 부분 특수화 한다.
	// typedef ? type;
};

/*
// N==0으로 부분 특수화
template<typename TP>
struct xtuple_element_type<0, TP>
{
	// 아직 0번째 타입을 구할수 없다.
	// typedef ? type;
};
*/
// N==0, 그리고 tuple 모양을 좀더 자세히
template<typename T, typename ... Types>
struct xtuple_element_type<0, xtuple<T, Types...>>
{
	 typedef T type;
	 typedef xtuple<T, Types...> tupleType;
};
// N != 0 일때
template<int N, typename T, typename ... Types>
struct xtuple_element_type<N, xtuple<T, Types...>>
{
	typedef typename xtuple_element_type<N-1, xtuple<Types...>>::type  type;

	typedef typename 
	xtuple_element_type<N - 1, xtuple<Types...>>::tupleType 
		tupleType;
};



template<typename T> void foo(T& tp)  
{
	// T는 임의의 갯수를 가진 xtuple 입니다.
	
	// T: xtuple<int, double, short> 

	typename xtuple_element_type<2, T>::type n;      // 1번째 요소 타입
	
	typename xtuple_element_type<2, T>::tupleType t; // 1번째 요소를 저장하는 tuple타입

	cout << typeid(n).name() << endl;
	cout << typeid(t).name() << endl;
}

int main()
{
	xtuple<int, double, short> t3(3, 3.4, 5);
	
	foo(t3);
}









