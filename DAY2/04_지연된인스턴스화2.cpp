// 다음 코드를 컴파일 하면 에러가 있을까요 ? 없을까요 ?

template<typename T> void foo(T a)
{
	// if : 실행시간 조건문 입니다
	//      조건이 false라도 템플릿에서 
	//      C++ 코드로 생성됩니다.
	//if (false)
	//	*a = 10;

	// if constexpr : 컴파일 시간 조건문
	// 조건이 false 인경우 C++ 코드를 생성하지 
	// 않습니다
	// /std:c++17
	if constexpr (false)
		*a = 10;
}
int main()
{
	foo(0);
}