// CRTP1
#include <iostream>
using namespace std;
// CRTP ( Curiously Recurring Template Pattern)
// 기반 클래스가 템플릿 인데 파생 클래스를 만들때
// 자신의 이름을 템플릿 인자로 전달하는 기술

class Window
{
	// 윈도우의 모든 기능을 넣으 세요
	void Click() {}
};

template<typename T> 
class MsgWindow : public Window
{
public:
	void msgLoop() // void msgLoop(Window* this)
	{
		//Click(); // this->Click()
		static_cast<T*>(this)->Click();
	}
	void Click() { cout << "1" << endl; }
};

class MyWindow : public MsgWindow< MyWindow  >
{
public:
	void Click() { cout << "2" << endl; }
};

int main()
{
	vector<Window*> v;

	MyWindow w;
	w.msgLoop(); // 1 ? 2





//	Window* p = new MyWindow;
//	p->Click(); // ?


}
