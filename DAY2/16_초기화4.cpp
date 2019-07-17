class Complex
{
	int re, im;
public:
	Complex(int a, int b) : re(a), im(b) {}
};

void foo(int n) {}
void goo(Complex c) {}

int main()
{
	int n = 3;
	Complex c1(1, 2);

	foo(3);

	goo(c1);
}



