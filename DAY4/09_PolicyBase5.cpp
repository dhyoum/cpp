#include <iostream>
#include <vector>
using namespace std;
// custom allocator

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) { std::cout << __FUNCSIG__ << std::endl; }

	~Point() { std::cout << __FUNCSIG__ << std::endl; }
};
template <class T>
struct Mallocator
{
	typedef T value_type;

	Mallocator() = default;

	template <class U> constexpr Mallocator(const Mallocator<U>&) noexcept {}

	T* allocate(std::size_t n)
	{
		cout << "allocate : " << n << endl;

		if (n > std::size_t(-1) / sizeof(T)) throw std::bad_alloc();
		if (auto p = static_cast<T*>(std::malloc(n * sizeof(T)))) return p;
		throw std::bad_alloc();
	}
	void deallocate(T* p, std::size_t) noexcept
	{
		cout << "deallocate" << endl;
		std::free(p);
	}
};


template <class T, class U>
bool operator==(const Mallocator<T>&, const Mallocator<U>&) { return true; }
template <class T, class U>
bool operator!=(const Mallocator<T>&, const Mallocator<U>&) { return false; }

int main()
{
	Mallocator<Point> ax;

	Point* p = ax.allocate(1);

//	ax.construct(p, 1, 2);  // error.

	// C++11 에서 제공하는 도구
	allocator_traits<Mallocator<int>>::construct(ax,
									p, 1, 2);
}


