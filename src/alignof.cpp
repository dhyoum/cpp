#include <iostream>

#define SIZEOF_ALIGNOF(T) std::cout<< sizeof(T) << '/' << alignof(T) << std::endl

struct A1
{
	int a;
};

struct A2
{
    char a;
	int b;
};

struct A3
{
	int b;
    char a;
};

struct A4
{
	double a;
    int b;
};

int main()
{
    /*
    Both are operator
    sizeof  : how much memory it takes
    alignof : how many bites a type much be aligned 
    */

	SIZEOF_ALIGNOF(A1);
	SIZEOF_ALIGNOF(A2);
	SIZEOF_ALIGNOF(A3);
	SIZEOF_ALIGNOF(A4);

	return 0;
}
