#include <iostream>
using namespace std;

// 51page.. 아주 중요합니다. 반드시 알아야 합니다.
// primary template
template<typename T> class Stack
{
public:
	void push(T a) { cout << "T" << endl; }
};
// 부분 특수화(partial specialization)
template<typename T> class Stack<T*>
{
public:
	void push(T* a) { cout << "T*" << endl; }
};
// 특수화(specialization)
template<> class Stack<char*>
{
public:
	void push(char* a) { cout << "char*" << endl; }
};

int main()
{
	Stack<int>   s1;  s1.push(0);
	Stack<int*>  s2;  s2.push(0);
	Stack<char*> s3;  s3.push(0);
}




