
// 다른 파일에 있는 변수 접근하기
extern const int c;

int main()
{
	int n = 10;
	const int c1 = n; // ok
	const int c2 = 10;// ok

	// C++11 의 새로운 상수 만드는 키워드
	// 컴파일 시간 상수만 만들수 있다.
	constexpr int c1 = n; // error
	constexpr int c2 = 10;// ok

}