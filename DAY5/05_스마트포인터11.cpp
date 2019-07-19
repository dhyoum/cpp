// 1일차 thiscall3.cpp   - 
// cafe.naver.com/cppmaster에서 받아도 됩니다.
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <memory>
using namespace std;

class Thread : public enable_shared_from_this<Thread>
{
	// 스레드를 래핑한 클래스를 스마트포인터로
	// 관리하면 자신의 참조계수를 스레드 함수가
	// 종료 될때까지로 연장시켜야 한다.
	shared_ptr<Thread> holdMe;
public:
	
	//Thread() : holdMe(this) {} // 절때 안됨
				// 주스레드가 만든 sp의 관리객체를 공유
				// 하게 해야 하는데..
				// this는 raw pointer 임.

	Thread()
	{
		// 이미 만들어진 관리객체를 공유할수있게 하는
		// 기술
		// 단, 이미 만들어진 관리객체가 없으면 
		// runtime error
		// 생성자가 호출된 순간은 아직 main 의 
		// sp가 만들어 지기 전입니다.
		//holdMe = shared_from_this();
	}

	~Thread() { cout << "~Thread" << endl; }

	void run()
	{
		holdMe = shared_from_this();

		CreateThread(0, 0, threadProc, this, 0, 0);
	}

	// 구글 android source github
	// platform_system_core
	// libutils/include/utils/thread.h
	// libutils/Threads.cpp

	static DWORD __stdcall threadProc(void* p)
	{
		Thread* self = static_cast<Thread*>(p);

		// 지역 변수로 다시 스마트 포인터 사용
		shared_ptr<Thread> sp(self->holdMe);
		self->holdMe.reset();		
		
		self->Main(); 

		// 스레드가 종료 할때 
		// 스레드 객체의 참조 계수 감소..
		//self->holdMe.reset();
		// 단점 : 위처럼 마지막에 자원을 해지 하면
		// 위쪽에서 예외 발생시 자원누수의 가능성이 있다
		return 0;
	}




	virtual void Main() = 0; 
};

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
	{
		shared_ptr<MyThread> sp(new MyThread(10));
		sp->run();
	}

	_getch();
}
