#define USING_GUI
#include "cppmaster.h" // ec_set_timer
#include <iostream>
#include <string>
using namespace std;

/*
void foo(int id)
{
	cout << "foo : " << id << endl;
}

int main()
{
	int n1 = ec_set_timer(500,  foo);
	int n2 = ec_set_timer(1000, foo);

	ec_process_message();
}
*/
// 타이머 개념을 사용하는 클래스를 만들어 봅시다.
// 11 page

#include <map>

class Clock;  // class 전방선언 문법

map<int, Clock*> this_map; // this를 보관하기 위한 
						   // 자료구조

class Clock
{
	string name;
public:
	Clock(string s) : name(s) {}

	void Start(int ms) 
	{
		int id = ec_set_timer(ms, timerRoutine);

		// this 포인터를 자료구조에 보관합니다.
		this_map[id] = this;
	}

	// 핵심 1. 아래 함수는 static 멤버 함수 이어야 합니다.
	static void timerRoutine(int id)
	{
		//cout << name << endl; // error

		Clock* self = this_map[id];

		cout << self->name << endl;
	}

};

int main()
{
	Clock c1("A");
	Clock c2("\tB");

	c1.Start(500); // 500ms 마다 이름 출력
	c2.Start(1000);
	ec_process_message();
}


