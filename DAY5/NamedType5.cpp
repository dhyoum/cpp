#include <iostream>
#include <string>
using namespace std;
// google 에서 NamedType 검색후 1번째 링크
template<typename T, typename Parameter>
class NamedType
{
	T value;
public:
	NamedType(const T& v) : value(v) {}
	NamedType(T&& v) : value(std::move(v)) {}

	T& get() { return value; }
	const T& get() const { return value; }
};
using FirstName = NamedType<string, struct stringP>;

int main()
{
	const FirstName f1("aaa");
	f1.get();
	FirstName f2(move(f1));

	10_meter
}

