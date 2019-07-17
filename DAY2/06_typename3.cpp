#include <list>
#include <vector>
#include <iostream>
using namespace std;

void print_first_element(vector<int>& c)
{
	int n = c.front();

	cout << n << endl;
}

int main()
{
	vector<int> v = { 1,2,3 };
	print_first_element(v);
}

