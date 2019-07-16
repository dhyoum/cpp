## SFINAE : Substitution Failure Is Not An Error

### overloading resolution 규칙
* 핵심 : 딱맞는게 있으면 그쪽으로 아니면, template 으로 호출한다.
1. exactly match
2. template match 이 가능하면 template match
3. 암시적 형변환이 가능하면, 호출 ( standard conversion )
4. 가변인자 호출
* overloading 에는 return type 이 관여하지는 않는다.


### 치환실패를 유도하는 3가지 기술
1. return type
```c
template<typename T> 
typename T::type foo(T a) { 
  ...
}
void foo(...) { cout << "..." << endl; }
```
2. 함수인자에 사용
```c
template<typename T> 
void foo(T a, typename T::type n = 0) {
  ...
}
void foo(...) { cout << "..." << endl; }
```
3. 템플릿 인자에 사용
```c
template<typename T,
         typename T2 = typename T::type> 
void foo(T a) {
  ...
}
void foo(...) { cout << "..." << endl; }
```

#### enable_if
- compile 하는 시점에 template 의 치환 실패가 발생한다면, 나는 template 으로부터 instant 하지 않겠다.  
```c
template<bool b, typename T = void>
struct enable_if {
  typedef T type;
};
template<typename T>  // 주의! 부분 특수화 시에는 디폴트 값을 표기하지 않는다.
struct enable_if<false, T> {
};

int main() {
  enable_if<true, int>::type n1;     // int
  enable_if<true, double>::type n2;  // double
  enable_if<true>::type n3;          // error - void 변수는 선언불가
  enable_if<false, int>::type n4;    // error - type 은 미정의
}
```

```c
/*
template<typename T> void foo(T a) {
   static_assert(is_integral<T>::value, "error not integer type");  // 치환 후 compile 시에 error 발생
}
*/
template<typename T>
typename enable_if<is_integral<T>::value>::type
foo(T a) {
}

void foo(double a) {
    cout << "double" << endl;
}
int main() {
	foo(10);
	foo(3.4);
	foo(3.4f);
}
```
### type 에 따라서, 다양한 방식의 함수를 구현
```c
#include <iostream>
#include <type_traits>
using namespace std;

// printv 만들기 
#ifdef METHOD_1
template<typename T> void printv(T v)
{
	if constexpr ( is_pointer<T>::value )		
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}
#endif
#ifdef METHOD_2
template <typename T>
void printv_imp(T v, true_type) {
    cout << v << " : " << *v << endl;
}
template <typename T>
void printv_imp(T v, false_type) {
    cout << v << endl;
}
template<typename T> void printv(T v) {
    printv_imp(v, is_pointer<T>());
}
#endif
#ifdef METHOD_3
template<typename T>
// typename enable_if<is_pointer<T>::value>::type 
enable_if_t<is_pointer_v<T>> printv(T v) {
    cout << v << " : " << *v << endl;
}
template<typename T>
enable_if_t<!is_pointer_v<T>> printv(T v) {
    cout << v << endl;
}
#endif

int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}
```
