#include <iostream>
#include <type_traits>
using namespace std;

struct EMPTY {};


// boost 가 가진 compressed pair 라이브러리 입니다.
template<typename T,
	typename U,
	bool b = is_empty<T>::value>
struct PAIR;

// PAIR<int,int>
// PAIR<EMPTY,int>

template<typename T, typename U> 
struct PAIR<T, U, false>
{
	T v1;
	U v2;
	T& getValue1() { return v1; }
	U& getValue2() { return v2; }

	PAIR() = default;


	template<typename A, typename B>
	PAIR(A&& a, B&& b)
		: v1(std::forward<A>(a)),
		  v2(std::forward<B>(b)) {}
};


template<typename T, typename U> 
struct PAIR<T, U, true> : T
{
	U v2;
	T& getValue1() { return *this; }
	U& getValue2() { return v2; }

	PAIR() = default;

	template<typename A, typename B>
	PAIR(A&& a, B&& b)
		: T(std::forward<A>(a)),
		v2(std::forward<B>(b)) {}
};

int main()
{
	//	PAIR<int, int> p(3, 4);

	//PAIR<int, int> p(3, 4);
	PAIR<EMPTY, int> p( EMPTY(), 4);

	cout << sizeof(p) << endl;

}

// EBCO3.cpp 카페에 있습니다. 
// 필요하신 분 받으세요.


