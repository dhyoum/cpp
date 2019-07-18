#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

// 아래 코드가 아주 중요 합니다.
class Point
{
public:
	Point(int a, int b)          { cout << "int, int" << endl; }
	Point(initializer_list<int>) { cout << "initializer_list" << endl; }
};
int main()
{
	// 아래 코드가 각각 어떤 생성자를 호출할지 생각해보세요

	Point p0(1, 1);     // 1
	Point p1({ 1, 1 }); // 2

	Point p2{ 1, 1 }; // 핵심. 2번이 우선시됨. 없으면
					//      1번

	Point p3 = (1, 2); // error

	Point p4 = { 1, 1 };  // 2번이 우선. 없으면 1번

	Point p5(1, 1, 1); // error
	Point p6{ 1,1,1 };  // ok
	Point p7 = { 1,1,1 };  // ok

	// C++11 부터 아래처럼 표기가 가능합니다.
	// initializer_list 때문에 가능한 표기법
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };


	// 아래 2줄의 차이점은 ?
	vector<int> v1(10, 2); // 10개가 2로 초기화
	vector<int> v2{10,2};  // 2개가 1,2


	vector<int> v3 = 10;    // error.
	vector<int> v4 = { 10 };// ok
}






