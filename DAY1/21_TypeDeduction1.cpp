#include <iostream>
using namespace std;

// type deduction ÀÌ¶õ ?
template<typename T> void foo(T a)
{
	while (a--) {} 
}
int main()
{
	int n = 5;
	foo(n); //  T ´Â int

	int& r = n;
	foo(r); // T int ? int&

	const int c = n;
	foo(c); // ?

	
}

