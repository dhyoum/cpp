void foo(int& n) { n = 100; }

template<typename F, typename ... Types>
decltype(auto) chronometry(F&& f, Types&& ... args)
{

	return invoke(std::forward<F>(f),std::forward<Types>(args)...);
}

int main()
{
	int n = 0;
	chronometry(&foo, n);
}