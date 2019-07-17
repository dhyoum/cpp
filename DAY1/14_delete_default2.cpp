#include <iostream>
#include <vector>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b) {}


	// 컴파일러가 복사 생성자를 만들지 못하게 한다.
	// 함수 삭제 문법은 주로 "복사생성자" "대입연산자"
	// 를 지울때 사용
	Point(const Point&) = delete;
	void operator=(const Point&) = delete;

	// 예전에 사용했던 복사생성자를 사용하지 못하게
	// 하는 기술. - private에 선언만.
//private:
//	Point(const Point&);



//	Point() {} // 사용자가 만드는 디폴트 생성자

	Point() = default; // 컴파일러에게 디폴트생성자
					   // 를 만들어 달라는 요청
};

int main()
{
	Point p1(1, 2);
//	Point p2 = p1;  // Point p2(p1) error

	Point p3;
}



// github.com/webkit  접속해 보세요
// github.com/tensorflow

// source/wtf/wtf/scope.h  파일 열어 보세요

