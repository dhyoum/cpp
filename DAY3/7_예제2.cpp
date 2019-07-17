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
		try
		{
			// buff ~ buff+sz 까지는 value로 복사 생성해달라
			// 실패시 예외 발생
			// cppreference.com 에서 아래 함수 찾아보세요
			std::uninitialized_fill(buff, buff + sz, 
								value);
		}
		catch (...)
		{	
			operator delete(buff); // 메모리 해지
		}
	}
	~Vector()
	{
		for (int i = 0; i < size; i++)
			buff[i].~T();

		operator delete(buff);
	}
	void resize(int newSize, const T& value = T())
	{
		if (newSize > capacity)
		{
			// 메모리 재할당이 필요한 경우
			// 문제1. 디폴트 생성자 필오
			//    2. 어차피 이전 버퍼에서 복사할것이다.
			//       자원 할당할 필요 없다.
			//T* temp = new T[newSize];

			T* temp = static_cast<T*>(
				operator new(sizeof(T)*newSize));

			// 기존 버퍼의 객체를 새로운 버퍼로 복사
			for (int i = 0; i < size; i++)
			{
				//new(&temp[i]) T; // 디폴트 생성자
				//new(&temp[i]) T(buff[i]); // 복사 생성자
				//new(&temp[i]) T(move(buff[i])); // move 생성자

				new(&temp[i]) T(move_if_noexcept(buff[i]));
			}
			// 새로운 영역은 복사 생성자로 초기화
			for (int i = size; i < newSize; i++)
			{
				new(&temp[i]) T(value);
			}
			// 기존 버퍼 소멸자 호출후 파괴
			for (int i = 0; i < size; i++)
			{
				buff[i].~T();
			}
			operator delete(buff);

			buff = temp;
		}
		else
		{
			// 메모리 재할당이 필요 없는 경우
			// 도전해보세요...
		}
	}
};

int main()
{
	Vector<Point> v(5, Point(0, 0));

	v.resize(10, Point(0,0));
}

