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

	// char 를 대신할 클래스를 만듭니다. - Proxy패턴
	class CharProxy
	{
		String& str;
		int idx;
	public:
		CharProxy(String& s, int i)
			: str(s), idx(i) {}

		// 변환 연산자 함수 : 객체를 char로 변환되게 합니다.
		// Proxy 가 오른쪽에 있을때 호출
		operator char() 
		{
			cout << "Read" << endl;
			return str.buff[idx]; 
		}

		// 대입연산자 : proxy가 왼쪽에 있을때 호출
		CharProxy& operator=(char c)
		{
			cout << "Write. 버퍼 분리" << endl;
			str.buff[idx] = c; 
			return *this;
		}
	};

	CharProxy operator[](int idx)
	{
		return CharProxy(*this, idx);
	}
};

int main()
{
	String s1 = "hello";
	String s2 = s1;

	char c = s1[0]; // read. 자원을 분리할 필요 없습니다

	cout << c << endl;

	s1[0] = 'X'; // write, 이순간 자원을 분리되어야 합니다.
				// COW : Copy On Write
	s1.print();
	s2.print();

}