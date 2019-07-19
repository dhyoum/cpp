#include <iostream>
using namespace std;

// new : 메모리 할당 실패시 예외(std::bad_alloc) 전달

void* operator new(size_t sz)
{
	// 아래는 간략한 구현 입니다.
	// cafe.naver.com/cppmaster C++강좌 new 참고.
	void* p = malloc(sz);

	if (p == nullptr)
		throw std::bad_alloc();

	return p;
}

// 오버로딩만을 위한 타입이 필요할때 Empty를 많이 사용
// 합니다.
//struct nothrow_t {};
//nothrow_t nothrow;

// 실패시 0을 반환하는 버전
void* operator new(size_t sz, nothrow_t)
{
	void* p = malloc(sz);
	return p;
}
//#define nothrow 1

int main()
{
	// 아래 코드의 잘못된 점은 ?
	//int* p1 = new int; // 실패시 예외 발생

	int* p1 = new(nothrow) int; // 실패시 0반환
	
	if (p1 == nullptr)
	{
	}
	else
		delete p1;
}


