#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
using namespace std;

/*
int main()
{
	std::vector<int> v = { 1,2,3 };
	auto p1 = v.begin();
	++p1;			// 
	--p1;			// 
	p1 = p1 + 3;	// 


	std::list<int> s = { 1,2,3 };
	auto p2 = s.begin();
	++p2;			// ok
	--p2;			// ok
	p2 = p2 + 3;	// 


	std::forward_list<int> fs = { 1,2,3 }; // 싱글리스트
	auto p3 = fs.begin();
	++p3;			// ok
	--p3;			// error
	p3 = p3 + 3;	// 

}
*/


// 입력 (컨테이너에서 꺼내 오는 것)
// 출력 (컨테이너에 넣는것)

// 반복자 카테고리 5가지
// 입력 반복자 : 입력, ++
// 출력 반복자 : 출력, ++
// 전진형 반복자 : 입력, ++, 멀티 패스      싱글리스트 반복자
// 양방형 반복자 : 입력, ++, --, 멀티 패스  더블리스트 반복자
// 임의접근 반복자 : 입력, ++, --, +, -, [], 멀티 패스
//							=> 연속된 메모리와 유사 (vector)

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = std::find(s.begin(), s.end(), 5);
		// find 알고리즘의 1, 2번째 인자는 반복자 입니다.
		// 최소 요구조건은 무엇일까요 ?
		// 5가지 종류중에서 골라 보세요
		// => 입력




	std::reverse(s.begin(), s.end()); 
				// => 양방향 반복자



	std::sort(s.begin(), s.end()); // 퀵 소트 입니다.
				// => 임의접근 반복자


	// 질문!
	std::vector<int> v = { 1,2,3 };
	v.sort(); // 이 멤버 함수가 있을까요 ?
			

}
*/





