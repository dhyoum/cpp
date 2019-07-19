#include <iostream>
using namespace std;

template<typename T>
class xunique_ptr
{
	T* obj;
public:
	inline explicit xunique_ptr(T* p = 0) : obj(p) {}
	inline ~xunique_ptr() { delete obj; }
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }

	// 복사와 대입 금지
	xunique_ptr(const xunique_ptr&) = delete;
	xunique_ptr& operator=(const xunique_ptr&) = delete;
};

int main()
{
	xunique_ptr<int> p1( new int);
	//xunique_ptr<int> p2 = p1;

}


