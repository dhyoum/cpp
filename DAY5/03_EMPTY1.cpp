#include <iostream>
using namespace std;
// empty class : non static 멤버 데이타가 없는 클래스
struct AAA
{
};
int main()
{
	AAA aaa;

	cout << sizeof(AAA) << endl; // 1
	// Empty 클래스의 크기는 1바이트 입니다
	
}