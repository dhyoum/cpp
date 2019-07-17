#include <iostream>
using namespace std;
// 181 page
// C, C++98의 enum : unscoped enum 이라고 부른다.
// 기존 enum 문제점
// 1. COLOR 라는 이름없이 사용가능
// 2. 무조건 int 타입.
//enum COLOR { red = 1, blue = 2 };

// C++11 새로운 enum
// 사용시 반드시 COLOR이름이 필요 하다.
//enum class COLOR { red = 1, blue = 2 };
enum class COLOR : char { red = 1, blue = 2 };

int main()
{
	COLOR c = COLOR::red; // ok
	int n1 = COLOR::red; // error
	int n2 = red; // error
	int red = 3;

	cout << red << endl; // 1 ? 3
}







