/*
int square(int a)
{
	return a * a;
}
double square(double a)
{
	return a * a;
}
*/
// 유사한 코드가 반복되면
// 함수를 만들지 말고 함수를 만드는 틀을 만들자
template<typename T> // 템플릿 파라미터
T square(T a)        // 호출 파라미터
{
	return a * a;
}

int main()
{
	square<int>(3);
	square<double>(3.3);
	
	printf("%p\n", &square); // error
	printf("%p\n", &square<int>); // ok.
	// square : 함수를 만드는 틀(템플릿)
	// square<int> : 함수

	square(3);
	square(3.3);

}





