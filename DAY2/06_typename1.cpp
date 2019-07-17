// 36page
struct Test
{
	// 아래 4개 멤버의 공통의 특징은 ?
	enum { value = 0 };
	static int data;
	typedef int DWORD;
	struct nested {};
};
int Test::data = 0;

int main()
{
	int p = 0;

	// 아래 코드에서 *의 의미를 생각해 보세요
	Test::value * p; // 곱하기 p
	Test::data  * p; // 곱하기 p
	Test::DWORD * p; // 포인터 변수 선언
	Test::nested* p; // 포인터 변수 선언

}



