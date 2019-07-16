```c
// 가변인자 클래스 템플릿
template<typename ... Types> class tuple {};

// 가변인자 함수 템플릿
template<typename ... Types>
void foo(Types ... args) {}
int main()
{
  tuple<> t0;
  tuple<int, double, char> t;
  foo(10, "AA", 4.5); // Types : int, const char*, double
                      // args  : 10, "AA", 4.5
}
```
#### 사용법
```c
#include <iostream>
using namespace std;

void goo(int a, double d, const char* s) {
  cout << "goo" << endl;
}

// parameter pack, sizeof..., pack expansion
template<typename ... Types> void foo(Types ... args ) {
  cout << sizeof... (args) << endl;
  cout << sizeof... (Types) << endl;

  // goo(args);  // error
  goo(args...);
}
int main() {
  foo(3, 4.5, "hello");
}
```
#### pack expansion
- 함수인자 또는 brace-init-list 등에서만 expansion 이 발생한다.
```c
#include <iostream>
using namespace std;

void goo(int a, int d, int s) { }
int hoo(int a) { return -a; }

template<typename T>
void print(T a) {
    cout << a << endl;
}
// parameter pack, sizeof..., pack expansion
template<typename ... Types>
void foo(Types... args) {
    
    // goo(args) - error
    goo(++args...);  // goo(++E1, ++E2, ++E3)
    // goo(hoo(args...))  - error : hoo 는 인자가 한개
    goo(hoo(args)...); // goo(hoo(E1), hoo(E2), hoo(E3))
    
    // 제일 앞에 0 은 args 가 없을 경우를 대비하여 넣음 
    // (print(args),0) -> 결과값이 0
    int dummy[] = { 0, (print(args),0)... }; 
    // int dummy[] = { 0, (print(1),0), (print(2),0), (print(3),0)}; 과 동일함.
}
int main() {
    foo(1, 2, 3);
}
```
