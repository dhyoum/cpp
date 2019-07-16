### type deduction ( auto, template )
    T a <- parameter
    auto a = parameter
- 규칙 1. 인자의 타입이 값이면 함수 인자의 const, volatile, reference는 제거됨    
```c

template<typename T> void foo(T a) {
}

int n = 10;        foo(n);  // T:int, a:int
int&r = n;         foo(r);  // T:int, a:int
const int c = n;   foo(c);  // T:int, a:int
const int& cr = c; foo(cr); // T:int, a:int

const char* s = "hello";        foo(s);   // T : const char*
const char* const s2 = "hello"; foo(s2);  // T : const char*
```
- 규칙 2. 인자의 타입이 참조이면,  함수 인자의 reference는 제거되고, const, volatile 는 유지됨
```
template<typename T> void foo(T& a) {
}

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
  - 표현식이 왼쪽에 올 수 있으면 : 참조 타입
  - 표현식이 왼쪽에 올 수 없으면 : 값  타입
```c
decltype(n+n) d1; // (n+n) = 10 : error -> int
decltype(++n) d2; // ++n = 10 : ok -> int&
decltype(n++) d3; // n++ = 10 : error -> int

int& foo() { return x; }
auto ret = foo(); // int
decltype(foo()) ret2 = foo(); // int&
decltype(auto) ret3 = foo();   // after C++14
```

### suffix return type
```c
template<typename T1, typename T2>
auto mul(T1 a, T2 b) -> decltype(a*b)
{ return a*b; }
// since C++14
template<typename T1, typename T2>
auto mul(T1 a, T2 b) // auto 로 추론하기 때문에, reference type 이 사라질 수 있다.
{ return a*b; }
template<typename T1, typename T2>
delcltype(auto) mul(T1 a, T2 b) // auto 추론시 reference 를 유지
{ return a*b; }
```

