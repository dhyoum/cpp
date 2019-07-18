class Point
{
	int x, y;
public:
	Point() = default;
	explicit Point(int a)        : x(a), y(0) {}
	explicit Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point pt1(1);
	Point pt2 = 1;

	pt1 = 1;
	pt1 = (1, 2);
	pt1 = { 1,2 };

	int n;
//	n = pt1;
}