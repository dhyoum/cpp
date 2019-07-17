#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 반복자 : 컨테이너의 요소를 가리키는 포인터 같이 동작하는 객체
// 165
int main()
{
//	vector<int> v = { 1,2,3,4,5 };
//	list<int> v = { 1,2,3,4,5 };
	int v[5] = { 1,2,3,4,5 };

//	auto p1 = v.begin();
//	auto p2 = v.end();

	// C++ 98 스타일 : 멤버 함수 begin
	// C++ 11 스타일 : 일반 함수 begin/end 사용 
	auto p1 = begin(v);
	auto p2 = end(v);

	
}


