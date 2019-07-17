// 출석(QR) 체크 해주세요 cafe.naver.com/cppmaster 
// 3일차 사전소스 받으시면 됩니다.







#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) { cout << "Point()" << endl; }
	~Point()                         { cout << "~Point()" << endl; }
};
// 226 page

// 핵심 : 1. 임시객체를 만드는 방법
//        2. 임시객체의 수명

int main()
{
	//Point p(1, 2); // 이름 있는 객체.. 블럭({})의 끝에서 파괴 된다.
	
	//Point(1, 2);  // 이름 없는 객체
				  // 임시객체(temporary)
				  // 클래스이름()
				 // 문장의 끝에서 파괴

	Point(1, 2), cout << "X" << endl;

	cout << "---------" << endl;
}








