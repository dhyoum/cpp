#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

// 멀티 스레드 개념을 객체지향으로 설계. - 9 page

/*
DWORD __stdcall threadProc(void* p)
{
	return 0;
}

int main()
{
	CreateThread(0, 0, threadProc, "A", 0, 0);
}
*/


//-------------------------------------------
// 라이브러리 내부 클래스
class Thread
{
public:
	void run()
	{ 
		CreateThread(0, 0, threadProc, this, 0, 0); 
	}
	//핵심 1. 아래 함수가 static 멤버함수 이어야
	//		하는 이유를 알아야 합니다.
	//     2. static 멤버 함수인 스레드 함수에서
	//		  this를 사용할수 있게 하기 위해
	//        인자로 전달하는 기술

	// 구글에서 "android source github"검색
	// 1번째 링크
	// platform_system_core/libutils/include/utils
	// Thread.h 열어 보세요
	// platform_system_core/libutils/threads.cpp

	static DWORD __stdcall threadProc(void* p)
	{
		Thread* self = static_cast<Thread*>(p);

		// self 가 this입니다. self 사용하면
		// 모든 멤버에 접근 가능합니다.
		self->Main(); // Main(self)

		//Main(); // this->Main()으로 호출되어야 한다.
				// Main(this)
		return 0;
	}

	virtual void Main() = 0; // Main(Thread* this)
};



// 라이브러리 사용자 클래스
class MyThread : public Thread
{
	int data;
public:
	MyThread(int d) : data(d) {}
	virtual void Main() 
	{ 
		cout << "MyThread Main" << endl; 
		data = 10;
	}
};

int main()
{
	MyThread t(10);
	t.run(); // 새로운 스레드 생성후, Main 가상함수실행

	_getch();
}
