class Vector
{
public:
	// explicit : 직접 초기화는 가능하지만
	//			복사 초기화는 사용할수 없다.
	explicit Vector(int sz) {}
};

void foo(Vector v) {} // Vector v = 10

int main()
{
	// direct initialization
	Vector v1(10);
	Vector v2{ 10 };

	// copy initialization
	Vector v3 = 10;
	Vector v4 = (10);
	Vector v5 = { 10 };

	foo(v1);
	foo(10);

}





