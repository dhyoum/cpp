# traits
## T 의 다양한 특성을 조사하는 기술
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
### 대표적인 사용예
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
