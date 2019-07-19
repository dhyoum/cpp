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
struct Greater
{
	bool operator()(int a, int b) const
	{
		return (a  / 10) > (b / 10);
	}
};
int main()
{
	set<int, Greater> s;   // RB Tree
	s.insert(15);
	s.insert(20);
	s.insert(35);
	s.insert(45);

	// 아래 2줄을 생각해 보세요
	// 선형 검색 - Tree의 특징을 활용 못함
	// "==" 로 "동등"을 판단
	auto p1 = find(s.begin(), s.end(), 32);

	if (p1 == s.end())
		cout << "검색 실패" << endl;

	// 이진 검색 - Tree의 특징을 활용
	// "조건자 함수객체"로 동등을 판단
	auto p2 = s.find(32);

	if (p2 == s.end())
		cout << "검색 실패" << endl;
	else
		cout << "성공 : " << *p2 << endl; // 35



	for (auto&& n : s) cout << n << ", ";
}







