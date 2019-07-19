#include <iostream>
#include <memory>
using namespace std;

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
};

int main()
{
	std::shared_ptr<Car> sp1(new Car);
	std::shared_ptr<Car> sp2 = sp1;

	// -> 연산 : 대상체(Car)의 멤버에 접근
	sp1->Go();


	// . 연산 : 스마트 포인터 자체의 멤버에 접근
	int n = sp1.use_count();
	cout << n << endl; // 2

	Car* p = sp1.get(); // raw pointer 꺼내기
	
}





