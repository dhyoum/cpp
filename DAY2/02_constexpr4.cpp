// constexpr의 활용
// 1. constexpr 상수 만들기
// 2. constexpr 함수 만들기
// 3. constexpr if 만들기 - 200page. "템플릿에서 사용"

// constexpr 함수 : 함수 인자가 컴파일 시간에 알수 있는
//		값이면 함수 실행 자체를 컴파일 시간에 수행
constexpr int Add(int a, int b)
{
	return a + b;
}
// cppreference.com 에 와보세요.
// find 검색해보세요
int main()
{
	int a = 1, b = 2;
	int x1[ Add(1, 2) ]; // ok

	int x2[Add(a, b)]; // error. 배열에 크기는 
						// 실행시 결정할수 없다.
	int c = Add(a, b); // ok
}