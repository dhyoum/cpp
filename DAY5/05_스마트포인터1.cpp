#include <iostream>
using namespace std;

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
	~Car()    { std::cout << "~Car" << std::endl; }
};
// 아래 코드가 핵심입니다.
// 개념 : 임의의 객체가 다른 타입의 포인터 역활을
//        하는 것
// 원리 : -> 와 * 연산자의 재정의
// 장점 : 소멸자에서 자동으로 객체를 해지 할수 있다.

class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}

	~Ptr() { delete obj; }

	Car* operator->() { return obj; }
	Car& operator*() { return *obj; }
};

int main()
{
	Ptr p = new Car; // Ptr p( new Car )

	(*p).Go();

	p->Go(); // (p.operator->())Go() 이지만
			 // (p.operator->())->Go() 로 해석됩니다.
}


