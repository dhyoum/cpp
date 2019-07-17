// 242 page :아주 중요합니다. 반드시 이해해야합니다.

// 함수인자로
// int&  : int 타입의 lvalue 만 전달 가능

// int&& : int 타입의 rvalue 만 전달 가능

// T&    : 임의의 타입의 lvalue 만 전달 가능

// T&&   : 임의의 타입의 lvalue와 rvalue 를 
//		   모두 전달가능
//         "forwarding reference"
// 의미 : 모든 것을 받을수 있는데
// int lvalue 를 보내면  T : int&  최종함수 f4(int&)
// int rvalue 를 보내면  T : int   최종함수 f4(int&&)


void f1(int&  a) {}
void f2(int&& a) {}


template<typename T>
void f3(T& t) {}

int main()
{
	int n = 0;

	// 1. 사용자가 타입을 명시적으로 전달하는 경우
	f3<int>(n);  // T : int  T& : int&  f3(int&)
	f3<int&>(n); // T : int& T& : int& &  f3(int&)
	f3<int&&>(n);// T: int&&  T&:int&& & f3(int&)

	// 2. 사용자가 타입을 지정하지 않은 경우
	// 컴파일러가 최대한 노력해서 함수를 만들려고 한다
	f3(10); // error. 함수를 만들수 없다.
	f3(n);  // T: int로 결정
	
}



template<typename T>
void f4(T&& t) {}

int main()
{
	int n = 0;

	// 1. 사용자가 타입을 지정하는 경우
	// 함수인자로 n 또는 0을 넣어보세요
	f4<int>(0);  // T : int   T&& : int&& f4(int&&)
	f4<int&>(n); // T : int&  T&& : int& &&  f4(int&)
	f4<int&&>(0);// T : int&& T&& : int&& &&f4(int&&)

	// 2. 사용자가 타입을 지정하지 않으면
	// 컴파일러가 인자를 보고 결정해야 한다.
	f4(n); // T : int&로 결정  T&&:int& && => f4(int&)
	f4(0); // T : int		T&&:int&&     => f4(int&&)
}