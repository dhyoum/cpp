#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 객체가 자원을 할당하면
// 3개의 함수(소멸자, 복사 생성자, 대입연산자)
// 가 추가로 필요 하다  => rule of 3  ( C++98 시절)

// C++11 부터는 "move 생성자, move 대입연산자" 도
// 만들어라  => rule of 5



// move 계열의 함수 에서는 모든 멤버를 move로 옮겨야 한다.


class Data
{
	int* buff;
	string str;
	int data;
public:
	Data(string s) : str(s) { buff = new int[100]; }

	~Data() { delete[] buff;}

	// 복사 생성자
	Data(const Data& d)
		: str(d.str), data(d.data)
	{
		// 포인터 멤버는 메모리 자체를 복사
		buff = new int[100];
		memcpy(buff, d.buff, sizeof(int) * 100);
	}
	// 대입 연산자
	Data& operator=(const Data& d)
	{
		// 대입연산자는 항상 자신과의 대입을 조사해야 한다
		if (&d == this) return *this;

		str = d.str;
		data = d.data;

		// 기존 버퍼는 제거(메모리 크기가 다를수 있으므로)
		delete[] buff;
		buff = new int[100];
		memcpy(buff, d.buff, sizeof(int) * 100);

		return *this;
	}
	// move 생성자
	Data(Data&& d)
		: str(std::move(d.str)), data(d.data), buff(d.buff)
	{
		d.buff = nullptr;
	}






	// move 대입 연산자
	Data& operator=(Data&& d)
	{
		// 대입연산자는 항상 자신과의 대입을 조사해야 한다
		if (&d == this) return *this;

		str = std::move(d.str);
		data = d.data;

		// 기존 버퍼는 제거(메모리 크기가 다를수 있으므로)
		delete[] buff;

		buff = d.buff;
		d.buff = nullptr;

		return *this;
	}
};
int main()
{
	Data d1("AA");
	//Data d2 = d1; // 복사 생성자

	Data d3("BB");
	d3 = d1;  // 대입 연산자 d3.operator=(d1)

//	d3 = d3;
}

//int n;
//(n = 10) = 20;






