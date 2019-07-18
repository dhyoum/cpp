class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

void foo(Point pt) {}
void goo(int n) {}   // int n = 5

int main()
{
	int n = { 5 };
	goo({ 5 });

	Point pt(1, 2);
	Point pt1 = { 1, 2 };
	foo(pt);
	foo({ 1,2 });
}