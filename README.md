# Modern C++
#### Legacy grammar
- function pointer
```c
void (*f)(int);
```
- member function pointer ( .* , ->* : member access operator )
```c
  void (Class:*f) (int);
  Dialog dlg; (dlg.* f)(20);
  Dialog* pDlg; (pDlg->* f)(20);
```
- [operator new](https://en.cppreference.com/w/cpp/memory/new/operator_new) : 사용자 정의 메모리 할당 방식 사용 가능 - 첫번째 인자는 size_t 로 해야함.
- placement new
  - 생성자만 호출하기 위해서 만든 operator new() 함수이다. 
  - 사실 생성자만을 call 하는 코드를 작성할 수 없으므로, new 를 호출하되    
    operator new 를 overloading 해서 메모리 할당하는 과정을 없앤것
  - 인자가 2개이상이고, 내부에 메모리할당이 없음.
  - 마찬가지로, operator delete operator new[] 등도 같이 고려해야함.
```c
  // void* operator new(size_t sz, void* p) { return p; } c++ 표준에 있음으로 별도로 구현 필요 없음.
  Point* p = static_cast<Point*>(operator new(sizeof(Point))); // allocate memory
  new(p) Point();     // call initializer 
  p->~Point();        // call destructor
  operator delete(p);  // dealloc memory
```
```c
  Point* p1 = new Point(0, 0);
  Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10)); // 1 argument
  for (int i = 0; i < 10; i++)
    new (&p2[i]) Point(0, 0);  // placement new ( 2 arguments )
  for (int i = 0; i < 10; i++)
    p2[i].~Point();
  operator delete(p2);

Point *p3 = new Point[3]{ {0,0}, {1,1}, {2,2} }; // after C++11 using braced-init-list
```
### [Rvalue reference](https://stackoverflow.com/questions/28483250/rvalue-reference-is-treated-as-an-lvalue)
- temporary variable
- RVO / NRVO
- RAII ( ownership )
- referece collapsing
  - An rvalue reference to an rvalue reference becomes (“collapses into”) an rvalue reference.
  - All other references to references (i.e., all combinations involving an lvalue reference) collapse into an lvalue reference.
### Move semantics
- ownership move
- casting
- rule of 5, noexcept
- POD / trivial
```c
static_cast<int&&>() => std::move()
```
- call by value 에 의한 함수동작도 나쁘지 않다. ( 추가비용 : move 1회 )
```c
void setObject(Object o) { obj = move(o); }
```
### [Universal reference](https://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers)
### Perfect forwarding
- what is the concept of forwarding ?
```c
template<typename T>
void func(T&& arg)
{
    // arg 은 lvalue
    static_cast<T&&>(arg); 
    // 10(rvalue) -> arg(lvalue) -> rvalue
    // x (lvalue) -> arg(lvalue) -> lvalue
    // static_cast<T&&>() => std::forward<T>() 와 동일
}
func(10);
func(x);
```
- variadic template 와 return 값도 전달하려면...
```c
template<typename F, typename ... Ts>
decltype(auto) LOG_FUNC(F f, Ts&& ... arg)
{
    return f(std::forward<Ts>(arg)...);   // parameter expansion 의 	
}
```
### Lambda function
- review the global function
- how to capture ?
- [closure](https://en.wikipedia.org/wiki/Closure_(computer_programming))
- free variable
 ```c
int v = 10;
auto f = [&v](int a) { v = a; };
// decltype(f) f1; error  : 캡쳐된 변수가 없는 체로 복사되는 것은 의미가 없음. default 생성자자 없음.
decltype(f) f1(f); // 복사생성만 가능하다.
```
### auto
- how to check the type deduction ?
```c
  std::cout << type_id_with_cvr<T>().pretty_name() << std::endl;
  std::cout << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
```
### const / constexpr
- compile time constant
- constexpr constructor

### Object initialize

- [Initialization](https://en.cppreference.com/w/cpp/language/initialization)
- [direct initialization](https://en.cppreference.com/w/cpp/language/direct_initialization)   
   객체를 초기화할 때, = 없이, () 또는 {}를 사용해서 초기화하는 것
- [copy initialization](https://en.cppreference.com/w/cpp/language/copy_initialization)  
   객체를 초기화할 때, = 를 사용해서 초기화 하는것. 
   의도치 않은 형변환이 발생할 수 있으므로, 이를 막기 위해서, 암묵적 형변환을 막는 explicit 를 변환 생성자에 가한다.
- [default initialization](https://en.cppreference.com/w/cpp/language/default_initialization)   
   초기화 방법을 사용하지 않고, 객체를 생성하는 것
- [value initialization](https://en.cppreference.com/w/cpp/language/value_initialization)   
   비어 있는 brace-init 을 사용해서 객체를 생성하는 것.
```c
int n1{0};    // direct
int n2 = {0}; // copy
int n3;       // dafault
int n4{};     // value
```
- [aggregate](https://en.cppreference.com/w/cpp/language/aggregate_initialization)    
  생성자가 없어도, { } 로 초기화 가능한 타입을 aggregate 라고 함. ( 배열, 구조체 등 )
### Uniform initialize
### initailzer_list
Initializer lists may be implemented as a pair of pointers or pointer and length.    
Copying a std::initializer_list does not copy the underlying objects.

### [user define literal](https://en.cppreference.com/w/cpp/language/user_literal)
```c
Meter operator""m (unsigned long long n) {
	cout << "operator m" << endl;
	Meter m(n);
	return m;
}
Meter v = 10m;	// operator""m(10) 을 호출함. 일반 개발자는 _ 로 시작하는 literal 를 만들어야 한다.
                // 가급적 사용하지 말자.
```
### if init ( since C++17 )
```c
if (int ret = foo(); ret == 0)
  cout << "ret is 0" << endl;
  
switch(int n=foo(); n){
  case 0:break;
  case 1:break;
}
```
### if constexpr ( since C++17 )
```c
template<typename T> void printv(T v) {
  if consexpr (is_pointer<T>::value)
    cout << v << " : " << *v << endl;
  else
    cout << v << " : " << v << endl;
```
### structure binding
```c
Point pt = {1,2};  auto [a,b] = pt;  auto& [rx, ry] = pt;
int x[2] = {1,2}; auto [e1, e2] = x;
tuple<int, short, double> t3(1,2,3.4); auto[a1, a2, a3] = t3;
```
### thread
### mutex, condition_variable, atomic
### future, promise, packaged_task
### boost::optional, boost::variant, boost:fibers

### link
- [cpp core guide](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- [Idioms](https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms)
- [cpprefernece](https://en.cppreference.com/w/)
- [modoo](https://modoocode.com/135)
- [soen](http://soen.kr/)
- [godbolt](https://godbolt.org/)
- [mingw](https://nuwen.net/)
- [Modern C++ Design](http://index-of.co.uk/C++/C++%20Design%20Generic%20Programming%20and%20Design%20Patterns%20Applied.pdf)
- [Effective C++](https://doc.lagout.org/programmation/C/Addison.Wesley.Effective.CPP.3rd.Edition.May.2005.pdf)
- [Effective Modern C++](https://moodle.ufsc.br/pluginfile.php/2377667/mod_resource/content/0/Effective_Modern_C__.pdf)
