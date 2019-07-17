// 핵심 : 상수 멤버 함수는 선택이 아닌 필수 문법입니다.
//       객체의 상태를 변경하지 않는 모든 멤버함수는
//       반드시 상수 멤버 함수로 해야 합니다.
//       getter 는 반드시 상수 멤버함수이어야 합니다.

struct Rect
{
	int xpos, ypos, width, height;
public:
	Rect(int x = 0, int y = 0, int w = 0, int h = 0)
		: xpos(x), ypos(y), width(w), height(h) {}

	int getArea() const { return width * height; }
};

//void foo(Rect r) // call by value
void foo(const Rect& r)
{
	int n = r.getArea(); // ?
}
int main()
{
	Rect r(1, 1, 10, 10); // 상수 객체 아님.

	int n = r.getArea(); // ok

	foo(r);
}

