#include <iostream>
using namespace std;

// 핵심 : move 생성자 개념

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* s, int a) : age(a)
	{
		name = new char[strlen(s) + 1];
		strcpy(name, s);
	}
	~Cat() { delete[] name; }
	
	Cat( const Cat& c) : age(c.age)
	{
		cout << "copy" << endl;
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}
	// 임시객체(rvalue)를 복사 할때 사용할 
	// 새로운 생성자 - "move 생성자" 라고 합니다.
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		cout << "move" << endl;
		c.name = nullptr; // 원본객체의 자원 reset
	}
};
Cat foo()
{
	Cat c1("AAA",2);
	return c1;
}
int main()
{
	Cat c = foo(); // 이 한줄을 생각해 봅시다.
					// move 생성자

	Cat c1("NABI", 2);
	Cat c2 = c1;  // 복사 생성자

	Cat c3 = static_cast<Cat&&>(c2); // move

	Cat c4 = std::move(c1); // 위처럼 캐스팅하고 
					// 있습니다.
}







