// 2_EBCO
#include <iostream>
using namespace std;

class Empty {};

class AAA
{
	Empty a;
	int b;
};
class BBB : public Empty
{
	int b;
};
// EBCO : Empty Base Class Optimization
// empty 가 기반 클래스가 되면 크기가 0으로
// 계산된다.
int main()
{
 	cout << sizeof(AAA) << endl; // 8
	cout << sizeof(BBB) << endl; // 4
}

