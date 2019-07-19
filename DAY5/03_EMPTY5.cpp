#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
using namespace std;

int main()
{
	list<int> v = { 1,2,3,4,5 };

	auto p = v.begin();

	advance(p, 3);
}





