#include <iostream>
#include <type_traits>
using namespace std;

struct EMPTY {};

/*
template<typename T, typename U> struct PAIR
{
	T v1;
	U v2;
	T& getValue1() { return v1; }
	U& getValue2() { return v2; }

	PAIR() = default;

	// 아래 처럼 한개만 제공하면 move가 지원 안됩니다.
	//PAIR(const T& a, const U& b) : v1(a), v2(b) {}

	//PAIR(T&& a, U&& b) : v1(a), v2(b) {}

	template<typename A, typename B>
	PAIR(A&& a, B&& b) 
		: v1(std::forward<A>(a)), 
		  v2(std::forward<B>(b)) {}
};

*/
template<typename T, typename U> struct PAIR : T
{
	U v2;
	T& getValue1() { return *this; }
	U& getValue2() { return v2; }

	PAIR() = default;

	template<typename A, typename B>
	PAIR(A&& a, B&& b)
		: T(std::forward<A>(a)) ,
		  v2(std::forward<B>(b)) {}
};

int main()
{
//	PAIR<int, int> p(3, 4);

	PAIR<int, int> p(3, 4);

	cout << sizeof(p) << endl;

}




