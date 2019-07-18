#include <iostream>
using namespace std;

int g = 0;

int main()
{
	int v1 = 10;
	int v2 = 10;

	auto f1 = [](int a) { return a + g; };// 전역변수 사용
										  // ok

	//auto f2 = [](int a) { return a + v1 + v2; };// 지역변수 사용 
										// error

	// 지역변수를 사용하려면 캡쳐 해야 한다. ok.
	auto f2 = [v1, v2](int a) { return a + v1 + v2; };

	// error. 캡쳐된 변수는 수정할수 없다.
	//auto f3 = [v1, v2](int a) { v1 = 20;  return a + v1 + v2; };

	// mutable 람다 : () 연산자 함수를 비상수 함수로 
	//				해달라.
	auto f3 = [v1, v2](int a) mutable { v1 = 20;  return a + v1 + v2; };

	f3(0);

	cout << sizeof(f3) << endl; // ????

	cout << v1 << endl; // 10


	/*
	// 위 한줄의 원리는 아래와 같습니다.
	class ClosureType
	{
		int v1;
		int v2;
	public:
		ClosureType(int a, int b) : v1(a), v2(b) {}

		inline bool operator()(int a)  const
		{
			v1 = 20;  
			return a + v1 + v2;
		}
	};
	auto f3 = ClosureType(v1, v2); // 지역변수 v1, v2
	*/
}








