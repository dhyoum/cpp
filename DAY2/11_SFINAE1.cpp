#include <iostream>
using namespace std;

// 112 page
// SFINAE1. 오버로딩 resolution

//template<typename T> 
//void foo(T a)   { cout << "T" << endl;}
//void foo(int a) { cout << "int" << endl; }
//void foo(double a) { cout << "double" << endl; }
//void foo(char a)   { cout << "char" << endl; }
void foo(...  ) { cout << "..." << endl; }

int main()
{
	foo(10); // 1. exactly matching - 정확한 타입
			 //    - int
		// 2. template 을 사용해서 foo(int)생성
		// 3. standard conversion
		//		표준 타입끼리의 암시적 형변환
		// 4. 가변인자 함수
}


