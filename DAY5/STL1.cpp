#include <vector>
#include <algorithm>

// STL1.cpp
namespace Video
{
	void foo() {}
	struct Card {};
	void init(Card c) {}
}
int main()
{
	Video::foo(); // Video:: 가 반드시 필요합니다.
	Video::Card c;// Video:: 가 반드시 필요합니다
	init(c);  // Video:: 가 없어도 됩니다.
	// Argument Dependant Lookup (ADL)
	// 인자가 포함된 이름 공간은 자동 검색 됩니다.

	std::vector<int> v(10, 3);
	find(v.begin(), v.end(), 3); // ok
					// std::  가 없어도 됩니다.
}