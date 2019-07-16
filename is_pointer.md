#### T 가 pointer 인지 아닌지를 판단하는 방법


```c
#include <type_traits>

template<typename T> 
void foo_imp(T a, true_type) {
   *a = 10;
}
void foo_imp(T a, false_type) {
   *a = 10;
}

// Method. 1  : restrist 
void foo(T a) {
    if ( is_pointer<T>::value)
       ...
    else
       ...
}
// Method. 2  : using intergal constants
void foo(T a) {
    foo_imp(a, is_pointer<T>());
}
// Method.3   : using constexpr
void foo(T a) {
  if constexpr (is_pointer<T>::value) {
     *a = 10;
  }
}
```
