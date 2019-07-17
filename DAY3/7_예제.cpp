// 7_예제
#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};
// STL vector의 원리를 생각해 봅시다.
template<typename T> class Vector
{
	T* buff;
	int size;
	int capacity;
public:
	Vector(int sz, T value = T()) : size(sz), capacity(sz)
	{
	//	buff = new T[size]; // 나쁜 코드 (디폴트 생성자를 요구한다.)

		// 1. 메모리만 할당 한다.
		buff = static_cast<T*>(
			operator new(sizeof(T) * sz));

		// 2. 각 객체의 생성자를 호출
		int cnt = 0;
		try
		{
			for (int i = 0; i < sz; i++)
			{
				//new(&buff[i]) T;  // 디폴트 생성자
				new(&buff[i]) T(value); // 복사 생성자
				cnt = i;
			}
		}
		catch (...)
		{
			// 생성자호출에 성공한 객체는 소멸자 호출
			for (int i = 0; i < cnt; i++)
				buff[i].~T();

			operator delete(buff); // 메모리 해지
		}
	}
	~Vector()
	{
		for (int i = 0; i < size; i++)
			buff[i].~T();

		operator delete(buff); 
	}
};

int main()
{
	Vector<Point> v(5, Point(0,0));
}

