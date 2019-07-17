// decltype 규칙 - 220 page

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	// 규칙 1. () 안에 심볼의 이름만 있는 경우
	//        해당 심볼의 선언과 완전히 동일한 타입
	decltype(n)  d1; // int
	decltype(r)  d2; // int&     초기값 때문에error
	decltype(c)  d3; // const int   ""
	decltype(p)  d4; // int* 

	// 규칙 2. 변수이름에 연산자등을 포함한 표현식이
	//        있는 경우
	// 표현식이 왼쪽에 올수 있으면 : 참조타입
	// 표현식이 왼쪽에 올수 없으면 : 값 타입
	// 이유는 "rvalue 배울때 설명"

	decltype(*p) d5; // int&

	int x[3] = { 1,2,3 };

	decltype(x[0]) d6;  // int&

	decltype(n + n) d7; // (n+n) = 10  error이므로
						// int

	decltype(++n) d8;   // int&

	decltype(n++) d9;   // int

	decltype(n = 20) d10; // (n = 20) = 10; ok
						// int&


	int y[3] = { 1,2,3 };

	// d와 a의 타입은 ?
	decltype( y[0] ) d;  // int& 
	
	auto a = y[0]; // y[0]는 원래 참조 타입인데
				   // auto는 참조를 제거하므로
				   // a는 int


//	int k = 3;
//	int s = ++k * ++k;
//	++k = 20; // ok
//	cout << s << endl; // 25
}





// cafe.naver.com/cppmaster 에서 오늘 소스
// 받으실수 있습니다.