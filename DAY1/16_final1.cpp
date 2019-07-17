// 196 page
class Base
{
public:
	virtual void foo() {}
	virtual void goo() {}
};
class Derived : public Base
{
public:
	// 가상함수뒤에 final : 더이상 재정의 할수 없게
	//					해달라는 의미.
	virtual void foo() override final {}
	virtual void goo() override {}
};
// 클래스 선언시 이름뒤에 final : 더이상 파생클래슬
//				만들수 없다.
class Derived2 final : public Derived
{
public:
	virtual void foo() override {} // error
	virtual void goo() override {} // ok
};

int main()
{

}