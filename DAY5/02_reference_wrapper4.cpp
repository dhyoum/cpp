#include <iostream>
#include <functional>
#include <thread> 
using namespace std;

void foo(int a, int& b) { b = 100; }

int main()
{
	int n = 0;
	//thread t(&foo, 1, n); // error

	thread t(&foo, 1, ref(n)); // ok

	t.join();
	cout << n << endl; // ?? 
}



