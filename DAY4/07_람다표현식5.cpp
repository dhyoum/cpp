
//void foo( int(*f)(int, int) ) {} // 1. 함수 포인터
							     // 치환 안됨

//void foo( auto f ) {} // error. auto는 함수 인자가 
						// 될수 없습니다.

template<typename T>
void foo(T f) {}   // 템플릿. 인라인 치환 가능.

int main()
{
//	foo(1);
//	foo(3.4);
	foo( [](int a, int b) { return a + b; } );
	foo( [](int a, int b) { return a - b; } );
}