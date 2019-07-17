#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;


class Point
{
public:
	Point(int a, int b)          { cout << "int, int" << endl; }
	Point(initializer_list<int>) { cout << "initializer_list" << endl; }
};
int main()
{
	// 아래 코드가 각각 어떤 생성자를 호출할지 생각해보세요

	Point p1(1, 1);  
	Point p2({ 1, 1 });
	Point p3{ 1, 1 };
	Point p4 = (1, 2);
	Point p5 = { 1, 1 }; 
	Point p6(1, 1, 1); 
	Point p7{ 1,1,1 }; 
	Point p8 = { 1,1,1 }; 


	vector<int> v1(1, 2);
	vector<int> v2{1 ,2};
}