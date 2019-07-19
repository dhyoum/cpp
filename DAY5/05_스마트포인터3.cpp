#include <iostream>
using namespace std;

// C++11의 스마트포인터를 사용하려면 필요한 헤더
#include <memory>

int main()
{
	// 1. explicit 생성자
	shared_ptr<int> p1(new int); // ok
	//shared_ptr<int> p2 = new int; // error

	// 2. 스마트 포인터 오버헤드

	shared_ptr<int> sp1(new int);
	shared_ptr<int> sp2 = sp1;

	cout << sizeof(sp1) << endl;// raw 포인터의 
							// 2배 정도

	// (A) 관리객체가 생성되는 오버헤드
	// (B) 스마트 포인터 자체의 크기가 
	//     raw pointer 2배
}







