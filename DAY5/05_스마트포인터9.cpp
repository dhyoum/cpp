#include <iostream>
#include <memory>
using namespace std;

class Car
{
public:
	void Go() {}
	~Car() {std::cout << "~Car" << std::endl;	}
};
int main()
{
	shared_ptr<Car> sp;
	weak_ptr<Car>   wp;
//	{
		shared_ptr<Car> p(new Car);
		
		//sp = p; // 참조 계수 증가
		wp = p; //  참조계수 증가 안함

		cout << p.use_count() << endl;  // 2
//	}	
	if (wp.expired())
	{
		cout << "객체 파괴" << endl;
	}
	else
	{
		// wp 를 사용해서 객체 접근
	//	wp->Go(); // error. -> 연산자 없음

		// wp를 가지고 sp를 만들어서 접근
		shared_ptr<Car> sp = wp.lock();

		if (sp)
			sp->Go();
	}

	cout << "------" << endl;
}

