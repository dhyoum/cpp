#include <iostream>
#include <initializer_list>
using namespace std;

// 211 page
// initializer_list :  초기화 시에사용하기 위해
//			C++11에서 추가한 도구
void foo(initializer_list<int> e)
{	
}

int main()
{
	initializer_list<int> e = { 1,2,3 }; 

	foo(e);
	foo({ 1,2,3,4,5,6 });

	//e.
}