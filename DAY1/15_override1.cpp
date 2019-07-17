// 193 page
class Base
{
public:
	virtual void foo(int) {}
	virtual void goo() const {}
	virtual void hoo() {}
	void koo() {}
};

class Derived : public Base
{
public:
	// override : 컴파일러에게 가상함수를 재정의하고
	//		있다고 알려 주는 것.
	// 기반 클래스의 함수와 다른 경우 에러 발생
	virtual void foo(double)  {}
	virtual void goo() override {}
	virtual void hooo()override {}
	void koo()override {}
};
int main()
{

}