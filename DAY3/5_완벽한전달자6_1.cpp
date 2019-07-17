// 3_완벽한전달자
#include <iostream>
using namespace std;

// cafe.naver.com/cppmaster  stopwatch.cpp 
#include <chrono>
#include <string>

// StopWatch 클래스 복사해오세요.
class stop_watch
{
	std::string message;
	std::chrono::high_resolution_clock::time_point start;
public:
	inline stop_watch(std::string msg = "") : message(msg) { start = std::chrono::high_resolution_clock::now(); }
	inline ~stop_watch()
	{
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
		std::cout << message << " " << time_span.count() << " seconds." << std::endl;;
	}
};


template<typename F, typename ... Types>
decltype(auto) chronometry(F f, Types&& ... args)
{
	stop_watch sw;  // 생성자에서 시간 기록
					// 소멸자에서 수행 시간 출력
	return f(std::forward<Types>(args)...);
}
void foo(int a)
{
	for (int i = 0; i < 10000; i++) rand();
}
int main()
{
	chronometry(foo, 5); // 시간 측정
}



