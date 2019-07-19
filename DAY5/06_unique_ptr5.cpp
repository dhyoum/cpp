#include <iostream>
using namespace std;

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

template<typename T> struct xdefault_delete
{
	inline void operator()(T* obj) { delete obj; }
};



// 삭제자 변경 : 함수객체를 템플릿 인자로 전달
template<typename T,
	typename D = xdefault_delete<T>>
	class xunique_ptr
{
	//T* obj;
	//D del; // 삭제자
	
	PAIR< D , T* > m;

public:
	inline explicit
		xunique_ptr(T* p = 0, D d = D())
		: m(d, p) {}

	inline ~xunique_ptr()
	{
		//del(obj);
		m.getValue1()(m.getValue2());
	}
	inline T* operator->() { return m.getValue2(); }
	inline T& operator*() { return *m.getValue2(); }

	xunique_ptr(const xunique_ptr&) = delete;
	xunique_ptr& operator=(const xunique_ptr&) = delete;
};

int main()
{
	auto f = [](int* p) { free(p); };

	xunique_ptr<int, decltype(f)>
		p1((int*)malloc(100), f);


	cout << sizeof(p1) << endl;

	//------------
	// 아래 2개는 다른 ? 같은 타입
//	unique_ptr<int, MyDel1> p1(new int);
//	unique_ptr<int, MyDel2> p2(new int);

//	shared_ptr<int> p1(new int, foo);
//	shared_ptr<int> p2(new int, goo);

}


