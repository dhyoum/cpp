#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
using namespace std;


// 반복자 카테고리 5가지
// 입력 반복자 : 입력, ++
// 출력 반복자 : 출력, ++
// 전진형 반복자 : 입력, ++, 멀티 패스      싱글리스트 반복자
// 양방형 반복자 : 입력, ++, --, 멀티 패스  더블리스트 반복자
// 임의접근 반복자 : 입력, ++, --, +, -, [], 멀티 패스
//							=> 연속된 메모리와 유사 (vector)

int main()
{
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// 아래 코드에 대해서 생각해 보세요
	// sort : 임의접근 반복자를 요구합니다.
	// list 반복자 : 양방향 반복자 입니다.
	sort(s.begin(), s.end()); // error

	s.sort(); // list는 STL 알고리즘에 보낼수없기 때문에
			// 멤버 함수 sort()가 있다.
			// quick 이 아닌 다른 알고리즘 사용

	//질문 : 아래 멤버 함수가 있을까요?
	vector<int> v = { 1,2,3,4,5 };
	//v.sort(); // ???? 있을까요 ???
			//없다. vector는 임의접근 반복자이므로
			// 모든 알고리즘 사용가능
			// sort()일반함수 사용하면 된다.



	forward_list<int> s2 = { 1,2,3 };
	// reverse : 양방향 반복자를 요구
	// 싱글리스트 : 전진형 반복자
	reverse(s2.begin(), s2.end()); // error





	//sort()
	// cppreference.com 에서 find 검색
}






