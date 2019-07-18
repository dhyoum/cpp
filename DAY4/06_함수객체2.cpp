#include <iostream>
#include <bitset>
using namespace std;

template<int N> class URandom
{
	bitset<N> bs;
	bool recycle;
public:
	URandom(bool b = false) : recycle(b)
	{
		bs.set(); // 모든 비트를 1로
	}

	int operator()()
	{
		if (bs.none()) // 모두 0이면
		{
			if (recycle)
				bs.set(); // 다시 모든 비트 1로
			else
				return -1;
		}
		int v = -1;		
		while (!bs.test(v = rand() % N));
		bs.reset(v);
		return v;
	}
};
int main()
{
	URandom<20> r;// (true);
	for (int i = 0; i < 15; i++)
		cout << r() << endl;
}






/*
// 0 ~ 9 사이의 중복되지 않은 난수를 구하는 함수
int urand()
{
	return rand() % 10;
}
int main()
{
	for (int i = 0; i < 10; i++)
		cout << urand() << endl;

}
*/