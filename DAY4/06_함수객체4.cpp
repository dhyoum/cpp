#include <algorithm>
using namespace std;

// 라이브러리의 조건
// 1. 성능 : 빨라야 한다.
// 2. 유연성 : 정책 변경이 가능해야 한다.

// 변하지 않은 흐름속에서 변해야 하는 정책은 분리되어야 한다.
// 일반 함수에서는 변하는 것을 인자화 한다.

// 286 page
void Sort(int* x, int sz, bool(*cmp)(int, int) ) 
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			//if (x[i] > x[j])  // 1

			if ( cmp(x[i], x[j]) ) // 2
				swap( x[i], x[j]);
		}
	}
}
//--------------------
inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }




int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Sort(x, 10, cmp1);
}





