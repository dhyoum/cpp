#include <iostream>
using namespace std;

void foo(int    n) { cout << "int" << endl; }
void foo(double n) { cout << "double" << endl; }
void foo(bool   p) { cout << "bool" << endl; }
void foo(void*  p) { cout << "void*" << endl; }

int main()
{
	foo(0);     // int.    0은 정수형 리터럴
	foo(0.0);   // double. 0.0은 실수형 리터럴
	foo(false); // bool.   false은 bool 형 리터럴

	foo(nullptr);// void*  nullptr은 포인터 리터럴

	// nullptr 은 nullptr_t 라는 타입입니다.
	// nullptr_t는 모든 타입의 포인터로 암시적 형변환
	// 됩니다.

	nullptr_t a = nullptr;

	void* p2 = a;
}






