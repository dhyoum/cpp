#include <iostream>
using namespace std;

template<typename T, typename U> struct Test
{
	void print() { cout << "T, U" << endl; }
};
// T*, U*
template<typename T, typename U> struct Test<T*, U*>
{
	void print() { cout << "T*, U*" << endl; }
};
// T, T
// 핵심 : primary template 이 템플릿 인자가 2개라도
//       부분 특수화 할때 인자의 갯수는 바뀔수 있습니다.
//       하지만 Test<T,T> 부분은 반드시 2개로 표기해야합니다.
template<typename T> struct Test<T,T>
{
	void print() { cout << "T, T" << endl; }
};
// short, T
template<typename T> struct Test<short, T>
{
	void print() { cout << "short, T" << endl; }
};
// short, int
template<> struct Test<short, int>
{
	void print() { cout << "short, int" << endl; }
};
// T,Test<U,V>
template<typename T, typename U, typename V> 
struct Test<T, Test<U, V>>
{
	void print() { cout << "T, Test<U, V>" << endl; }
};

int main()
{
	Test<int, double>   t1; t1.print(); // T, U
	Test<int*, double*> t2; t2.print(); // T*, U*
	Test<int, int>      t3; t3.print(); // T, T
	Test<short, char>   t4; t4.print(); // short, T
	Test<short, int>    t5; t5.print(); // short, int

	Test<double, Test<char, int>>  t6; t6.print();
				// T, Test<U,V>
}



