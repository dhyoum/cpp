#include <iostream>
using namespace std;

// 201 page
struct Point
{
	int x = 0;
	int y = 0;
};
int main()
{
	Point p = { 1,2 };

	int x = p.x;
	int y = p.y;

	// 구조체의 모든 멤버 값을 한번에 꺼내는 문법
	// 1. 반드시 auto 타입만 가능
	// 2. 구조체 뿐 아니라 배열도 가능
	auto[x1, y1] = p;

	int arr[3] = { 1,2,3 };
	
	auto[a, b, c] = arr;

	auto& [r1, r2, r3] = arr; // ok
}