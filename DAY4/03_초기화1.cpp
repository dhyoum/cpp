// 203 page ~
// C++98/03 초기화의 문제점.
struct Point 
{
	int x, y; 
};
class Complex
{
	int re, im;
public:
	Complex(int a, int b) : re(a), im(b) {}
};

int main()
{	
	// 1. 객체의 종류에 따라 초기화 방법이 다르다.
	int n1 = 0;
	int n2(0);
	int x[3] = { 1,2,3 };
	Point   p = { 1,1 };
	Complex c(1, 1);

	// 2. STL의 컨테이너를 효율적으로 초기화 하기 어렵다.
	vector<int> v; // 1~10으로 초기화 된 vector 만들기
	
}

// 3. 클래스 멤버로 있는 배열을 초기화 할수 없다.
class A
{
public:
	int x[10]; // ??? 초기화 할수 있을까 ?
};





