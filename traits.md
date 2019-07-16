# Traits
## compile 시점에 template T 다양한 특성을 조사하는 기술
- primary template 만듦 ( enum { value = false } )
- partial specialization 원하는 조건문 만들고, value = true
```c
// T 가 포인터인지 조사하는 기술
template<typename T> struct IsPointer{
    // enum { value = false }; // to caculate compile time before c++11 : data type 이 int
    static constexpr bool value = false; // since c++11 : data type 이 bool
};
template<typename T> struct IsPointer<T*> {
    // enum { value = true };
    static constexpr bool value = true;
};
// T 가 Array 인지 조사하는 기술
template<typename T> struct IsArray {
    static constexpr bool value = false;
};
template<typename T, int N> struct IsArray<T[N]> {
    static constexpr bool value = true;
};
template<typename T> void foo(T a) {
  if ( IsPointer<T>::value )
    cout << "pointer" << endl;
  else
    cout << "not pointer" << endl;
}
```
### [intergal constant](https://en.cppreference.com/w/cpp/types/integral_constant)
```c
// C++11 표준
template<typename T, T N> struct integral_constant {
  static constexpr T value = N;
};
integral_constant<short, 0> s0;
```
### 사용예
1. 타입 질의 : is_xxxx<T>::value
2. 변형 타입얻기 : xxx<T>::type
```c
template<typename T> struct remove_poiner {
  using type = T;
}
template<typename T> struct remove_poiner<T*> {
  using type = T;
}
remove_pointer<int*>::type n; // int
```

#### return type 을 알아내는 기술
```c
#include <iostream>
using namespace std;
int goo(char c, double d) { return 0; }

template<typename T> struct result_type {
    using type = T;
};

template<typename R, typename A1, typename A2> struct result_type<R(A1, A2)> {
    using type = R;
};

template<typename T> void foo(T& a) {
  // 함수 반환타입 조사하기.(단, 함수의 인자가 2개일때만)
  typename result_type<T>::type n = 0;  // int 
  cout << typeid(n).name() << endl;
}

int main() {
  foo(goo);
}
```
#### using 을 활용하는 기법 ( since C++14 )
- value : is_pointer<T>::value,   -> using 버전 is_pointer_v
- type  : remove_pointer<T>::type -> using 버전 remove_pointer_t
```c
template<typename T>
using remove_pointer_t = 
  typename remove_pointer<T>::type;

template<typename T> void foo(T a) {
  // typename remove_pointer<T>::type n1;
  remove_pointer_t<T> n1;
}
```
