#include <iostream>
#include <memory>
#include <string>
using namespace std;

struct People
{
	std::string name;

	People(std::string n) : name(n) {}
	~People() { std::cout << name << " 파괴" << std::endl; }

	
	shared_ptr<People> bf;
};

int main()
{
	shared_ptr<People> sp1(new People("kim"));
	shared_ptr<People> sp2(new People("lee"));

	sp1->bf = sp2;
	sp2->bf = sp1;

	// 이 코드는 상호 참조 현상이 있습니다.
	// 메모리가 해지 되지 않습니다. - 중요!!!
}


