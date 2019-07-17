#include "cppmaster.h"
#include <iostream>
using namespace std;

struct Object
{
	int* resource;

	Object()  {	resource = new int[100];}
	~Object() { delete[] resource; }
	Object(const Object& o)
	{
		// deep copy
		resource = new int[100];
		memcpy(resource, o.resource, sizeof(int) * 100);
	}
};

int main()
{
	Object* buf1 = new Object[2];

	delete[] buf1;
}