typedef int& LR;
typedef int&& RR;

// 240 page
int main()
{
	int n = 10;

	LR r1 = n;	// ok
	RR r2 = 10;	// ok

	// reference collapsing 이라고 합니다. && &&의 경우만 && 이다.
	LR& r3 = n ; // int& &   => int&
	RR& r4 = n ; // int&& &  => int&
	LR&& r5 = n ; // int& &&  => int&
	RR&& r6 = 10 ; // int&& && => int&&

	// 주의 직접 레퍼런스의 레퍼런스를 만들수는 
	// 없습니다.
	int& & r7 = n; // error

	// typedef 나 템플릿에서만 허용됩니다.
}

template<typename T> void foo(T& a) {}// int&

foo<int&>(n); // ?





