#include <iostream>
using namespace std;

// 74 page

// traits : 템플릿 인자 T에 대한 다양한
//			속성(특질,traits)를 조사하는 기술

template<typename T> void printv(T a)
{
	if (T 가 포인터 타입 이면)
		cout << a << " : " << *a << endl;
	else
		cout << a << endl;
}

int main()
{
	int    n = 10;
	double d = 3.3;

	printv(n);
	printv(d);
	printv(&n);
}





