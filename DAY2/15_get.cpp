#include <iostream>
using namespace std;

struct Base 
{
	int value = 10;  // C++11 부터 가능한 초기화
};
struct Derived : public Base 
{
	int value = 20;
};

int main()
{
	Derived d;
	cout << d.value << endl;
	
	// 149
	// 기반 클래스 멤버에 접근하려면
	// 기반 클래스의 참조 타입으로캐스팅합니다.
	cout << static_cast<Base&>(d).value << endl;

	// 값 타입으로 캐스팅하지 마세요 -내일 1교시

}






