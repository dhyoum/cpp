// C++17에서 추가된 문법
// 199 page
int foo() { return 0; }

int main()
{
	int ret = foo();
	if (ret == 0)
	{
		//....
	}
	// VC++2017/2019 : C++14가 디폴트
	// g++ 8.x, 9.1  : C++14가 디폴트

	// C++17 을 사용하려면 - 교재 2page
	// VC++ : /std:c++17 또는 /std:c++latest
	// g++  : -std=c++17

	// C++20 : c++2a  => 확정되면   C++20
	// C++23 : c++2b  =>           C++23


	// C++17 의 새로운 if
	// init if 라고 불리는 문법
	if (int ret = foo(); ret == 0)
	{
	}

	switch (int n = foo(); n)
	{
	case 1: break;
	}
}



