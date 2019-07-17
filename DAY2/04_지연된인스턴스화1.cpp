// lazy instantiation
/*
class A
{
	int data;
public:
	void foo(int a) { *a = 0; } // error
};
*/
// 인스턴스화 : 템플릿에서 실제 C++ 코드(함수/클래스)
//			   가 생성되는 것
// 지연된 인스턴스화 : 사용된 함수만 실제 C++ 코드로
//				생성됩니다.
template<typename T>
class A
{
	T data;
public:
	void foo(T a) { *a = 0; } // error
};

int main()
{
	A<int> a;
	a.foo(0);
}



