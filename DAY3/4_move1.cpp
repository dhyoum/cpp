#include <iostream>
using namespace std;

// move 개념
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

	// 깊은 복사로 구현한 복사 생성자
	Cat(const Cat& c) : age(c.age)
	{
		// 메모리 할당후.. 메모리를 통째로 복사
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}
};
int main()
{
	Cat c1("NABI", 2);
	Cat c2 = c1;  // runtime error
			// 깊은 복사의 복사 생성자가 있으면 ok
}




/*
// 깊은 복사로 구현한 복사 생성자
Cat(const Cat& c) : age(c.age)
{
	// 메모리 할당후.. 메모리를 통째로 복사
	name = new char[strlen(c.name) + 1];
	strcpy(name, c.name);
}
*/

