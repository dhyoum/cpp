#### T 가 pointer 인지 아닌지를 판단하는 방법

```c
template<typename T> 
void foo_imp(T a, true_type) {
   *a = 10;
}
```
