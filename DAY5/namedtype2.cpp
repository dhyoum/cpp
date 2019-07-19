
// int, double 등의 타입이름을 사용하지 말고
// 의미를 가지는 타입을 사용하자.

// Width, Height, xPos, yPos 타입등 : NamedType

class xPos {};
class yPos {}

class Point
{
	int x;
	int y;
public:
	// setter는 따로 만들수 있지만
	// 생성자는 할수 없습니다.(이름이 같으므로)
	//Point(int xx) : x(xx) {}
	//Point(int yy) : y(yy) {}

	Point(xPos xx) : x(xx) {}
	Point(yPos yy) : y(yy) {}

	void setx(int a) { x = a; }
	void sety(int a) { y = a; }
};

int main()
{
	Point p1(10);
	Point p2(20);
}