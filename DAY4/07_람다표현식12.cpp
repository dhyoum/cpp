// 07_람다표현식12
#include <iostream>
using namespace std;

class ClosureType
{
	int v1;
public:
	int operator()(int a, int b) const
	{
		return v1 + a + b;
	}
	// 함수포인터로의 변환 때문에 생성된 함수
	static int helper(int a, int b) 
	{
		return v1 + a + b;
	}
	using FP = int(*)(int, int);

	// 변환 연산자는 반환 타입을 표기하지 않습니다
	operator FP()
	{
		return &ClosureType::helper;
	}
};
int main()
{
	int(*f)(int, int) = ClosureType();

	// 핵심 : 캡쳐 하지 않은 람다표현식만 
	//       함수 포인터로 변환 가능합니다.
	int v1 = 0;
	int(*f2)(int,int) = [](int a,int b){return v1+ a + b;};
			// class ClosureType{...}; ClosureType();



//	Point pt;
//	int n = pt; // pt.operator int()
//	함수포인터 p = pt; // pt.operator 함수포인터()
}