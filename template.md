### template compile
1. 템플릿 문법 컴파일
2. C++ 생성후, 다시 컴파일
- 이코드는 error 발생하지 않음. foo 가 호출된적이 없어서, T 가 결정되지 않았으므로, goo 역시 결정되지 않음.
```c
template<typename T>
void foo(T a) {
  goo(a);
}
int main() {
}
```
### type deduction ( auto, template )
    T a <- parameter
    auto a = parameter
- 규칙 1. 인자의 타입이 값이면 함수 인자의 const, volatile, reference는 제거됨    
```c

template<typename T>
void foo(T a) { }

int n = 10;        foo(n);  // T:int, a:int
int&r = n;         foo(r);  // T:int, a:int
const int c = n;   foo(c);  // T:int, a:int
const int& cr = c; foo(cr); // T:int, a:int

const char* s = "hello";        foo(s);   // T : const char*
const char* const s2 = "hello"; foo(s2);  // T : const char*
```
- 규칙 2. 인자의 타입이 참조이면,  함수 인자의 reference는 제거되고, const, volatile 는 유지됨
```
template<typename T>
void foo(T& a) { }

int n = 10;        foo(n);   // T:int, a:int&
int&r = n;         foo(r);   // T:int, a:int&
const int c = n;   foo(c);   // T:const int, a:const int&
const int& cr = c; foo(cr);  // T:const int, a:const int&

int x[3] = { 1,2,3 };
auto  arr1 = x;	// int arr1[3] = x; error
                // int arr1  = x; ok : 우변이 배열이면, pointer
auto& arr2 = x; // int (&arr2[3]) = x; ok 배열의 참조
```

### decltype deduction
- 규칙1. () 안에 심볼의 이름만 있는 경우, 해당 심볼의 선언과 완전히 동일
```c
int n;         decltype(n) d1;  // int
int& r;        decltype(r) d2;  // int&
const int c;   decltype(c) d3;  // const int
const int& cr; decltype(cr) d4; // const int &
```
- 규칙2. 변수이름에 연산자가 붙어 있는 경우,    
  L-value : **참조** 타입
  R-value : **값**  타입
```c
decltype(n+n) d1; // (n+n) = 10 : error -> int
decltype(++n) d2; // ++n = 10 : ok -> int&
decltype(n++) d3; // n++ = 10 : error -> int

int a = 10, b = 20;
int& c = a;
cout << boost::typeindex::type_id_with_cvr<decltype(a+b)>().pretty_name() << endl;
cout << boost::typeindex::type_id_with_cvr<decltype(c)>().pretty_name() << endl;
cout << boost::typeindex::type_id_with_cvr<decltype(++a)>().pretty_name() << endl;
cout << boost::typeindex::type_id_with_cvr<decltype(a++)>().pretty_name() << endl;

int& foo() { return x; }
auto ret = foo(); // int
decltype(foo()) ret2 = foo(); // int&
decltype(auto) ret3 = foo();   // after C++14

```

### suffix return type
```c
template<typename T1, typename T2>
auto mul(T1 a, T2 b) -> decltype(a*b)
{
  return a*b;
}
// since C++14
template<typename T1, typename T2>
auto mul(T1 a, T2 b) // auto 로 추론하기 때문에, reference type 이 사라질 수 있다.
{
  return a*b;
}
template<typename T1, typename T2>
delcltype(auto) mul(T1 a, T2 b) // auto 추론시 reference 를 유지
{
  return a*b;
}
```

### typename
- 클래스안의 내포된 값 : enum 또는 static 멤버데이터 ( class_template::data )
- 클래스안의 내포된 타입 : 내포 클래스 또는 typedef, using 등은 typename class_template::type 으로 명시해야 한다.
- template 에 의존적인 type 을 명시하기 위해서 사용하는 것이므로, class 가 명확한것은 붙이면 안된다.

### specialization
- 클래스 템플릿
  + 부분 특수화(partial specialization) : template parameter 완전히 사라지지 않음.
  + 완전 특수화(full specialization) : primary template 에서 파라미터
- 함수 템플릿 : 완전 특수화(full specialization)만 가능, 
  + 오버로딩을 통해서 부분 특수화와 같은 효과를 얻음.
```c
template<typename T> struct Stack {
    void push(T a) { cout << "T" << endl; }
};
template<typename T> struct Stack<T*> {  // partial specialization
    void push(T* a) { cout << "T*" << endl; }
};
template<> struct Stack<char*> {         // specializaion
    void push(char* a) { cout << "Tchar*" << endl; }
};
// 다른 예
template<typename T, typename U> struct Test {
    void print() { cout << "T, U" << endl; }
};
template<typename T> struct Test<T,T> { // 중요 - 사용하지 않는 type 은 삭제한다.
    void print() { cout << "T, T" << endl; }
};

// 중요 : template 파라미터의 개수는 늘거나, 줄수있지만, 실제 사용되는 부분의 개수는 고정이다.
template<typename T, typename U, typename V> struct Test<T, Test<U, V>> {
    void print() { cout << "T, Test<U,V>" << endl; }
};
Test<int, Test<char, int>>  t6; t6.print(); // T, Test<U,V>
```

- funciton template
```c
template<typename T> void printv(T a) {
	cout << a << endl;
}
// function overloading : 동일한 이름이 파라미터 종류가 다름
template<typename T> void printv(T* a) { 
    cout << a << ":" << *a << endl;
}
template<int N> struct int2type {
    enum { value = N };
};
```
- integer 를 type 으로 만들어서, overloading 하는 방법
```c
template<typename T> void printv_imp(T a, int2type<1>) {
    cout << a << " : " << *a << endl;
}
template<typename T> void printv_imp(T a, int2type<0>) {
    cout << a << endl;
}
template<typename T> void printv(T a) {
    printv_imp(a, int2type<is_pointer<T>::value>());
}
```
- 핵심 ! 특수화를 통해서 base class 를 변경한다.
```c
template<typename T>struct is_pointer : false_type{};
template<typename T>struct is_pointer<T*> : true_type{};

template<typename T> void printv_imp(T a, true_type) {
  cout << a << " : " << *a << endl;
}
template<typename T> void printv_imp(T a, false_type) {
  cout << a << endl;
}
template<typename T> void printv(T a) {
  printv_imp(a, is_pointer<T>());	// T 에 따라서, 기반class 가 바뀐다.!
}
```
