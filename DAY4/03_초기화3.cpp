// braced-init-list
// direct vs copy

// 205 page

struct Point { int x, y; };

class Complex
{
	int re, im;
public:
	Complex(int a, int b) : re(a), im(b) {}
};

int main()
{
	/*
	int n1 = 0;
	int n2(0);
	int x[3] = { 1,2,3 };
	Point   p = { 1,1 };
	Complex c(1, 1);
	*/

	// 일관된 초기화 ( uniform initialization )
	// 중괄호 초기화(brace init )
	// direct initialization
	int n1{ 0 };
	int n2{ 0 };
	int x[3]{ 1,2,3 };
	Point   p{ 1,1 };
	Complex c{ 1, 1 };

	// copy initialization
	int n1 = { 0 };
	int n2 = { 0 };
	int x[3] = { 1,2,3 };
	Point   p = { 1,1 };
	Complex c = { 1, 1 };

	// 205 중간
	int n3 = 3.4; // ok
	int n4 = { 3.4 }; // error

	char c = { 300 }; // error
}





