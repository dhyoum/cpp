


#include <iostream>
using namespace std;

template<typename T> class Car
{
	static int cnt;
public:
	Car() { ++cnt; }
	~Car() { --cnt; }
	static int getCount() { return cnt; }
};
template<typename T> int Car<T>::cnt = 0;

// Truckµµ °¹¼ö¸¦ ÆÄ¾ÇÇÏ°í ½Í´Ù.
class Truck : public Car<Truck>
{
};
class Bike : public Car<Bike>
{
};

int main()
{
	Truck t1, t2;
	Bike b1, b2, b3;
	cout << b1.getCount() << endl; // ??

//	Car c1, c2;
//	cout << c1.getCount() << endl;
}


