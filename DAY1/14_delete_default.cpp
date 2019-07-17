// 186 page

int add(int a, int b)
{
	return a + b;
}
// 함수를 선언만 제공 : 사용시 링크 에러 발생
//double add(double a, double b);

// 함수 삭제 문법 : 해당 함수 사용시 컴파일 에러
double add(double a, double b) = delete;

// 189 page 표 이해되는지 확인해 보세요.

int main()
{
	add(1, 2);

	add(3.4, 2.3);
}