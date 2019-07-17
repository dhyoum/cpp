#include <iostream>
using namespace std;

// NULL객체에 대한 함수 호출(NULL Object Design Pattern)

class Test
{
    int data;
public:
    void f1() { cout << "f1" << endl; }
    int  f2() { cout << "f2" << endl; return 0; }

protected:
    int  f3()
    {
        cout << "f3" << endl;
        return data; // return this->data;
    }
public:
    int call_f3() { return this ? f3() : 0; }
};

int main()
{
    Test* p = 0; // 객체를 만들려다가 메모리부족등으로 실패했다.
    p->f1(); // ??? 어떻게 될까요 ? f1(p) => f1(0)
    p->f2(); // f2(p)
    p->call_f3(); // f3(p) => f3(0)
    return 0;
}
