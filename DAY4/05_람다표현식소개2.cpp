#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool foo(int n) { return n % 3 == 0; }

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// 3검색
	auto p1 = find(v.begin(), v.end(), 3);

	// 첫번째 나오는 3의 배수를 찾고 싶다.
	auto p2 = find_if(v.begin(), v.end(), foo);


	// 람다표현식의 주된 용도
	// 알고리즘 함수에 조건자 함수로 전달하는 경우가
	// 아주 많다.
	auto p3 = find_if(v.begin(), v.end(),
		  [](int n) {return n % 3 == 0;	}	);

}


