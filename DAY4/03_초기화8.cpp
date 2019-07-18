#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

// 209 page
// value initialization vs default
struct Point
{
	int x, y;

	//Point() {}

	Point() = default;
};

int main()
{
	Point p1;
	Point p2{}; // 모든 멤버가 0으로 초기화

	cout << p2.x << endl;

//	int n1;  // 쓰레기값      default 초기화
//	int n2{};// 디폴트 값(0)으로 초기화. value 초기화

//	cout << n1 << endl; 
//	cout << n2 << endl;
}


