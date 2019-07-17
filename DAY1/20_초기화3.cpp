// braced-init-list
// direct vs copy


struct Point { int x, y; };

class Complex
{
	int re, im;
public:
	Complex(int a, int b) : re(a), im(b) {}
};

int main()
{
	int n1 = 0;
	int n2(0);
	int x[3] = { 1,2,3 };
	Point   p = { 1,1 };
	Complex c(1, 1);

}



