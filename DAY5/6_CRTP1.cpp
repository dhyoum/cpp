// 6_CRTP1 - 195 page
#include <iostream>


// libutils/include/utils/singleton.h


// MS의 오픈소스인 WTL(Windows Template Library)
//  라이브러리가 이벤트를 처리하는 방식.
template<typename T> class Window
{
public:
	void msgLoop()  // msgLoop(Window* this)
	{
		//Click(); // this->Click()
		static_cast<T*>(this)->Click();
	}
	void Click() { std::cout << "Window::Click" << std::endl; } // 1
};
class MyWindow : public Window<MyWindow>
{
public:
	void Click() { std::cout << "MyWindow::Click" << std::endl; } // 2
};
int main()
{
	MyWindow w;
	w.msgLoop(); // 1 ? 2
}


