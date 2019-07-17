#include <set>
#include <functional>
#include <iostream>
using namespace std;

typedef set<int> SET;
typedef set<double> SETD;

// typedef 는 타입의 별명만 만들수 있다.
// 템플릿의 별명이 안된다.
//template<typename T>
//typedef set SET;   // error

template<typename T>
using SET = set<T>;

// 위 코드가 있으면 아래 2줄 처럼 사용가능합니다.

// SET<int> => set<int>
// SET<double> => set<double>


int main()
{
	//set<int> s;

	SET s2;


	s.insert(10);
	s.insert(15);
	s.insert(6);

	for (auto n : s)
		cout << n << endl;
}