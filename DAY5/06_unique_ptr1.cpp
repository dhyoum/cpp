// 06_unique_ptr1.cpp

#include <iostream>
#include <memory>
using namespace std;

int main()
{
	// shared_ptr : 자원의 공유
	// weak_ptr   : 자원 소유 안함
	// unique_ptr : 자원의 독점
	unique_ptr<int> p1(new int);
	//unique_ptr<int> p2 = p1; // error

	unique_ptr<int> p2 = move(p1); // ok


	shared_ptr<int> sp(new int);
	unique_ptr<int> up(new int);

	// 다음중 에러를 모두 고르세요
	shared_ptr<int> sp1 = up;		// 1.error
	shared_ptr<int> sp2 = move(up);	// 2.ok

	unique_ptr<int> up1 = sp;		// 3.error
	unique_ptr<int> up2 = move(sp);	// 4.error
}

// 함수가 메모리를 할당한후 스마트포인터로 반환하려고 합니다.
// unique 와 shared 중 무엇이 좋을까요 ?
//shared_ptr<int> AllocMemory(int sz)
unique_ptr<int> AllocMemory(int sz)
{
	return ? ;
}
// unque_ptr을 반환하면 반환값을 받는 타입을 아래처럼
// 선택할수 있다.
shared_ptr<int> ret1 = AllocMemory(100);
unique_ptr<int> ret2 = AllocMemory(100);

