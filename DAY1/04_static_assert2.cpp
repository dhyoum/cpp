
#include <iostream>
#include <type_traits>
#include <cassert> 
using namespace std;

//#pragma pack(1)
struct PACKET
{
	char cmd;
	int  data;
};
//static_assert(
//	sizeof(PACKET) == sizeof(char) + sizeof(int),
//	"error unexpected padding");
// sizeof(PACKET) : 


template<typename T> void memset(T* p)
{
	// T 타입에 가상함수가 있는 경우 
	// 컴파일을 멈춘다.
	static_assert(!std::is_polymorphic<T>::value,
		"Error, T has virtual function");

	memset(p, 0, sizeof(T));
}
class A 
{
	//virtual void foo() {}
};
int main()
{
	A a;
	memset(&a);
}









