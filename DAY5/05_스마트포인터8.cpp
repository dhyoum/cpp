#include <iostream>
#include <memory>
#include <string>
using namespace std;

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }


	//shared_ptr<People> bf;

	//People* bf; // raw pointer. 참조계수 증가 안함.
				  // 객체 파괴 조사 못함

	weak_ptr<People> bf; // 참조계수 증가 안함
						 // 객체 파괴 조사 가능
};

int main()
{
	shared_ptr<People> sp1(new People("kim"));
	{
		shared_ptr<People> sp2(new People("lee"));

		sp1->bf = sp2;
		sp2->bf = sp1;
	}

	// weak 는 자신이 가리키는 곳이 유효 한지 
	// 조사할수 있다.
	if ( sp1->bf.expired() )
	{
		cout << "객체가 파괴됨" << endl;
	}

}



