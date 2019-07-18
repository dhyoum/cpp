int main()
{
	int v = 100;
	auto f = [](int a, int b) { return a + b; };
				// class xxx{...}; xxx();

	decltype(f) f1; // error. ClosureType에는
					// 디폴트 생성자가 없다.

	decltype(f) f2(f); // ok.. 
						// 복사 생성자는 있다

	// cppreference.com 에 와보세요.
}