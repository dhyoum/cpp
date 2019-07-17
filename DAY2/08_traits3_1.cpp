// 08_traits3_1
#include <iostream>
using namespace std;

// C++11에서 다양한 traits 가 표준에 추가되었습니다
#include <type_traits>
template<typename T> void foo(T& a)
{
	if (is_pointer<T>::value)
		cout << "포인터" << endl;
	else
		cout << "포인터아님" << endl;
}
int main()
{
	int n = 0;
	foo(&n);

	cout << is_pointer<int>::value << endl;
}
