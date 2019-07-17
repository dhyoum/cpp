#include <iostream>
using namespace std;

struct Base { int value = 10; };

struct Derived : public Base
{
	int value = 20;    // C++11은 이렇게 사용가능
};

int main()
{
	Derived d;
	cout << d.value << endl; //  20

	// 동일 이름의 기반 클래스 멤버에 접근하려면
	// 기반클래스 타입으로 캐스팅한다.
	cout << static_cast<Base>(d).value << endl; // 10
	cout << static_cast<Base&>(d).value << endl; // 10

	// 아래 코드의 컴파일 결과를 확인해 보세요
	static_cast<Base>(d).value = 20;  // error
	static_cast<Base&>(d).value = 20; // ok

	// 값 캐스팅은 임시객체를 생성하게 됩니다.
}

// 임시객체
// 1. 사용자가 만들기도 합니다. - 함수 인자로 전달할때

// 2. 컴파일러에 의해 만들어 지기도 합니다.
//     함수가 값으로 반환할때
//     값 타입으로 캐스팅할때
//     람다표현식을 사용할때










