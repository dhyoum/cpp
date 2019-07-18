#include <algorithm>
#include <functional>  // less<>, greater<>등의 함수객체가 있습니다
using namespace std;

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// 1. 함수를 사용한 정책 변경
	sort(x, x + 10, cmp1);

	// 2. 함수객체를 사용한 정책 변경
	less<int> f;
	sort(x, x + 10, f);

	sort(x, x + 10, less<int>()); // 임시객체로 전달


	// 3. C++11 부터는 람다 표현식을 사용하면 됩니다.
	sort(x, x + 10,
		[](int a, int b) { return a < b; });

	// 위 한줄을 보고 컴파일러는 아래 코드는 생성합니다.
	// 람다표현식 : 함수객체를 만드는 표현식
	// 클로져(closure) : 람다표현식이 만든 임시객체

	// 289 page
	class ClosureType
	{
	public:
		inline bool operator()(int a, int b) const
		{
			return a < b;
		}
	};
	sort(x, x + 10,	ClosureType());

}






