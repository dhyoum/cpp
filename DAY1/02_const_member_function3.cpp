// Rect.h
class Rect
{
	int x, y, w, h;
public:
	// 상수 멤버 함수에서 const 키워드는
	// 선언과 구현에 모두 있어야 합니다.
	int getArea() const;
};
// Rect.cpp
int Rect::getArea() const 
{
	return w * h;
}
int main()
{
}

// 식당은 20층입니다.
// 오후 수업은 13:00 ~ 하겠습니다.
