#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

// STL 핵심
// 1. iterator category 5개 - EMPTY3.cpp 참고
// 2. 알고리즘은 컨테이너를 알지 못한다.

// 3. 알고리즘(일반함수)와 동일 이름의 멤버 함수가 있다면
//    반드시 멤버 함수를 사용하자.!!
//    list 는 remove 알고리즘이 아닌 remove멤버함수사용

/*
int main()
{
	vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };

	// remove는 컨테이너의 크기를 줄이지 않습니다.
	// 단지, 앞으로 당겨놓는 일을 합니다.
	auto p = remove(v.begin(), v.end(), 3);

	for (auto&& n : v) cout << n << ", ";

	// 필요없는 공간 제어
	v.erase(p, v.end());

	cout << endl;
	for (auto&& n : v) cout << n << ", ";
}
*/

int main()
{
//	vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };

	list<int> v = { 1,2,3,1,2,3,1,2,3,1 };

	// list의 경우 절대 아래 3줄 처럼 하지 마세요
	//auto p = remove(v.begin(), v.end(), 3);
	//for (auto&& n : v) cout << n << ", ";
	//v.erase(p, v.end());

	// list는 멤버 함수 remove를 사용하세요
	v.remove(3);

	cout << endl;
	for (auto&& n : v) cout << n << ", ";
}

