// 116 page
template<bool b, typename T = void>
struct enable_if
{
	typedef T type;
};
// 주의! 부분 특수화 시에는 디폴트값을 표기하지 않습니다.
// 하지만 primary의 내용대로 적용됩니다.
template<typename T>
struct enable_if<false, T>
{
};
int main()
{
	// 아래 변수들의 타입을 생각해 보세요
	enable_if<true, int>::type n1;   // int 
	enable_if<true, double>::type n2;// double
	enable_if<true>::type n3;        // void
				// void 타입은 변수를 만들수 없으므로 error
	
	enable_if<false, int>::type n4; // error.
						// type 이 없다.!
}




