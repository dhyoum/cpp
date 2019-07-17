#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v = { 1,2,3,4,5 };

	// 전통적인 for 문
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	// C++11 새로운 for 문 - range for
	for (int n : v)
		cout << n << endl;

	// 위코드는 보고 컴파일러는 아래 코드를 생성합니다.
	// 171 page
	for (auto p = begin(v); p != end(v); ++p)
	{
		int n = *p;
		//-----------------
		cout << n << endl;
	}

}




