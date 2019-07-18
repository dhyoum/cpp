// 단위 전략 디자인(Policy Base Design)
// 템플릿 인자로 정책을 담은 클래스를 전달하는
// 기술
// 성능 저하 없이 정책교체를 할수 있다.

// 정책 클래스에는 지켜야 하는 규칙이 있게 된다.
// github.com/webkit
// source/wtf/wtf/nolock.h   열어 보세요

// "modern C++ design"

template<typename T, 
	typename ThreadModel = nolock> class List
{
	ThreadModel tm;
public:
	void push_front(const T& a)
	{
		tm.lock();
		//...
		tm.unlock();
	}
};

// 동기화 정책을 담은 클래스
class nolock
{
public:
	inline void lock()   {}
	inline void unlock() {}
};
class posix_lock
{
public:
	inline void lock() {}
	inline void unlock() {}
};
//-----------------------
List<int, nolock> s;    // 전역변수.   멀티스레드에 안전하지 않다.




int main()
{
	s.push_front(10);
}