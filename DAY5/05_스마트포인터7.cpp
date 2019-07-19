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

	People* bf; // raw pointer. 참조계수 증가 안함.
};
int main()
{
	shared_ptr<People> sp1(new People("kim"));
	{
		shared_ptr<People> sp2(new People("lee"));

		sp1->bf = sp2.get();
		sp2->bf = sp1.get();
	}

	// sp2 가 가리키는 객체는 파괴 되었지만
	// raw pointer 인 bf를 가지고는 확인할 방법이 없다.
	if (sp1->bf != nullptr)
	{
		cout << sp1->bf->name << endl; // 버그!!
	}

}



