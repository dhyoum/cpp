### type deduction
```c
// 규칙 1. 인자의 타입이 값이면 함수 인자의 const, volatile, reference는 제거됨
template<typename T> void foo(T a) {
}

int n = 10;        foo(n);  // T:int, a:int
int&r = n;         foo(r);  // T:int, a:int
const int c = n;   foo(c);  // T:int, a:int
const int& cr = c; foo(cr); // T:int, a:int

const char* s = "hello";        foo(s);   // T : const char*
const char* const s2 = "hello"; foo(s2);  // T : const char*

// 규칙 2. 인자의 타입이 참조이면,  함수 인자의 reference는 제거되고, const, volatile 는 유지됨
template<typename T> void foo(T& a) {
}

int n = 10;        foo(n);   // T:int, a:int&
int&r = n;         foo(r);   // T:int, a:int&
const int c = n;   foo(c);   // T:const int, a:const int&
const int& cr = c; foo(cr);  // T:const int, a:const int&
