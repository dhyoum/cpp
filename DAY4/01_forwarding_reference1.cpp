
// 출석 체크 해주세요
// cafe.naver.com/cppmaster 에서
// 4일차 사전 소스 받으시면 됩니다.













template<typename T> class Test
{
public:
	// 아래 함수의 인자는 forwarding reference 일까요 ?
	// 아래 함수는 함수 템플릿이 아닙니다. 일반함수 입니다.
	// 클래스 템플릿의 일반함수
	void foo(T&& arg) {}

	// 아래 처럼해야지 forwarding reference 입니다.
	template<typename U> void goo(U&& arg) {}

	// github.com/webkit
	// source/wtf/wtf/scope.h
};
int main()
{
	Test<int> t;

	int n = 0;
	t.foo(n);
	t.foo(0);
}

