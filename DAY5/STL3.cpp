#include <set>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;

// 핵심 4. 단위 전략 디자인

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
struct Greater
{
	bool operator()(int a, int b) const
	{
		return a > b;
	}
};
int main()
{
	set<int, Greater> s;   // RB Tree
	s.insert(15);
	s.insert(20);
	s.insert(10);

	for (auto&& n : s) cout << n << ", ";
}







