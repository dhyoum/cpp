#include <iostream>
using namespace std;
// 핵심 : 템플릿에 의존적으로 타입을 꺼내려면
//       typename을 붙여야 한다.

T::DWORD : DWORD 값으로 해석
typename T::DWORD : DWORD 타입으로 해석

typename AAA::DWORD : typename을 붙일필요 없다.
					AAA라는 타입 이름을 사용하므로



class AAA
{
public:
	enum { value = 10};
	typedef int DWORD;
};
int p = 0;

template<typename T> void foo(T a)
{
	// 컴파일러는 아래 코드를 어떻게 해석해야 할까요 ?
//	T::DWORD * p;      // DWORD를 값으로해석한다.
	typename T::DWORD* p; // DWORD를 타입으로 해석
						  // 해 달라

}

int main()
{
	AAA aaa;
	foo(aaa);
}


