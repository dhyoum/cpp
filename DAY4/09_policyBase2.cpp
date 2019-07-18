#include <iostream>
#include <vector>
using namespace std;
/*
// STL vector를 생각해봅시다
template<typename T, 
		 typename Ax = allocator<T>  > class vector
{
	T* buff;
	int size;
	Ax ax;  // 메모리 할당기
public:
	void push_back(const T& a)
	{
		// 메모리가 부족해서 재할당해야 합니다. 어떻게 할까요 ?
		// new ? malloc ? brk ? HeapAlloc 
		buff = ax.allocate(10);
		ax.deallocate(buff, 10); 

	}
};
*/

int main()
{
	vector<int> v;
}