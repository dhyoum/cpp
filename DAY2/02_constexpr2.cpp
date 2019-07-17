#include <iostream>
using namespace std;

// 컴파일 시간 상수와 vs 실행시간 상수

int main()
{
	int s1 = 10;
	int a1[s1]; // C89 문법 : 배열의 크기는 컴파일할때 
				//           알아야 한다.
                // C99 문법 : 배열의 크기로 변수도 가능
				//			g++지원, vc++지원 안함

	const int s2 = 10;
	int a2[s2]; // ok

	const int s3 = s1;
	int a3[s3]; // error
}

void foo(const int s)
{
	int ar[s]; // error
}

//foo(n);

