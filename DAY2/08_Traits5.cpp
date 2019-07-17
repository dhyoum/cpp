#include <iostream>
#include <type_traits>
using namespace std;


// 90 page 제일 아래 부분
// 포인터 일때만 사용
template<typename T> void printv_pointer(T a)
{
	cout << a << " : " << *a << endl;
}
// 포인터가 아닐때만 사용
template<typename T> void printv_not_pointer(T a)
{
	cout << a << endl;
}
template<typename T> void printv(T a)
{
	if (is_pointer<T>::value)   
		printv_pointer(a);
	else
		printv_not_pointer(a);
}


int main()
{
	int    n = 10;
	printv(n);  
}





