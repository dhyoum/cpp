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
  enable_if<true>::type n3;          // void 변수는 선언불가
  enable_if<false, int>::type n4;    // type 은 미정의
}
```
