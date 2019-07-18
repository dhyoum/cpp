#include <iostream>
using namespace std;

template<class _Alloc,
	class = void>
	struct _Has_max_size
	: false_type
{	// determines whether _Alloc has max_size()
};

template<class _Alloc>
struct _Has_max_size<_Alloc, void_t<decltype(_STD declval<const _Alloc&>().max_size())>>
	: true_type
{	// determines whether _Alloc has max_size()
};

int main()
{
	allocator<int> ax;
	int* p = ax.allocate(10);

	allocator_traits<allocator<int>>::construct(ax, p);
}
