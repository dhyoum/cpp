#include <iostream>
using namespace std;

// 참조계수 기반 문자열 클래스
class String
{
	char* buff;
	int*  ref;
public:
	String(const char* s)
	{
		buff = new char[strlen(s) + 1];
		strcpy(buff, s);
		ref = new int(1);
	}
	String(const String& s) : buff(s.buff), ref(s.ref)
	{
		++(*ref);
	}

	// 참조계수 기반의 소멸자
	~String()
	{
		if (--(*ref) == 0)
		{
			delete[] buff;
			delete ref;
		}
	}


	void print()const { cout << buff << endl; }

	// [] 연산자 재정의 
	// 객체를 배열처럼 사용할수 있게 합니다
	// 등호의 왼쪽에 올수 있게 하기 위해
	// 참조 반환해야 합니다.
	char& operator[](int idx)
	{
		return buff[idx];
	}
};

int main()
{
	String s1 = "hello";
	String s2 = s1;

	char c = s1[0]; // s1.operator[](0)

	cout << c << endl;

	s1[0] = 'X';

	s1.print();
	s2.print();

}