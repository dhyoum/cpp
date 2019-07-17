// 5_override
#include <iostream>
using namespace std;

/*
int n = 0;

const int* p1 = &n; // p1을 따라가면 const
int* const p2 = &n; // p2가 const
int const* p3 = &n; // p3를 따라 가면 const
*/

//const int c = 10;
//int const c = 10; // 위와 완전히 동일

template<typename T> class Base
{
public:
	// a가 const
	// virtual void foo( T const a)
	virtual void foo(const T a)  {	cout << "Base foo" << endl;	}
};

class Derived : public Base<int*>
{
public:
	// foo 재정의 해서 "Derived foo" 라고 출력해 보세요
	// 아래 표기법은 a를 따라가면 const
	//virtual void foo(const int* a) //override
	virtual void foo(int* const a)
	{ 
		cout << "Derived foo" << endl;
	}
	//virtual void foo(int* const a)

};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0);   // "Derived foo" 나오게 해보세요
}








