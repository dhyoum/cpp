#include <iostream>
using namespace std;

struct Point3D
{
	int x, y, z;

	Point3D(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c) {}
};
int* begin(Point3D& pd) { return &(pd.x); }
int* end(Point3D& pd)   { return &(pd.z) + 1; }

// 주의 : end()는 마지막이 아닌 마지막 다음을 가리키는
//        반복자를 반환해야 합니다.
int main()
{
	Point3D pd(1, 2, 3);

	// 아래 코드가 될까요 ?
	for (auto n : pd)
		cout << n << endl;
	/*
	for (auto p = begin(pd); p != end(pd); ++p)
	{
		int n = *p;
		//-----------------
		cout << n << endl;
	}
	*/
}