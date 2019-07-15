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

int x[3] = { 1,2,3 };
auto  arr1 = x;	// int arr1[3] = x; error
                // int arr1  = x; ok : 우변이 배열이면, pointer
auto& arr2 = x; // int (&arr2[3]) = x; ok 배열의 참조
```
