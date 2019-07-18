#include <iostream>
using namespace std;

int g = 0;

int main()
{
	int v1 = 10;
	int v2 = 10;

	// capture by value
	auto f1 = [v1, v2](int a) { return a + v1; }; // 
	
	// capture variable by reference
	auto f2 = [&v1, &v2](int a) { v1 = 100; v2 = 200; return a + v1; }; // 


	f2(0); // 람다 표현식 실행

	cout << v1 << endl; // 100
	cout << v2 << endl; // 200

}








