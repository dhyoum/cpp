#include <set>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;

// 핵심 5. Equality vs Equivalency

/*
template<typename T,
		 typename Pred = less<T>, // 요소 비교
		 typename Ax = allocator<T>> //메모리할당기
class set
{
	Pred pred; // 요소 비교를 위한 정책 클래스
public:
	pair<...> insert(const T& newElem)
	{
		//if (rootElem < newElem)
		if ( pred(rootElem, newElem) )
			add 오른쪽;

		//else if (newElem < rootElem)
		else if (pred(newElem, rootElem) )
			add 왼쪽;
		else
			이미존재한다. 실패 반환
	}
};
*/

// set에 정책 클래스 조건은 "이항 함수객체"입니다.
template<typename T> struct less
{
	bool operator()(const T& a, const T& b) const
	{
		return a < b;
	}
};
struct Point
{
	int x, y;
	
	bool operator <(const Point& p) const
	{
		return x < p.x;
	}
};
int main()
{
//	set<
	set<Point> s;   // RB Tree  less<Point>
	s.insert({ 1,2 });
}



// 강의장 오른쪽 앞에 수료증 있습니다


// 찾아 가세요



// square.h
template<typename T> T square(T a);

// square.cpp
template<typename T> T square(T a) { return a * a; }

// 명시적 인스턴스화
template int square<int>(int a);
template double square<double>(double a);

// main.cpp
#include "square.h"

int main()
{
	square(3); // square<int>()
	square(3.3); // square<int>()
}





