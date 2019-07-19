// 안드로이드 소스에서
// libutils/include/utils/Singleton.h 열어 보세요

template<typename T> class Singleton
{
protected:
	Singleton() = default;

	Singleton(const Singleton&) = delete;
	void operator=(const Singleton&) = delete;
public:
	static T& getInstance()
	{
		static T instance;
		return instance;
	}
};
// Keyboard 도 싱글톤으로 하고 싶다
class Keyboard : public Singleton<Keyboard>
{
};

int main()
{
	Cursor& c1 = Cursor::getInstance();
}