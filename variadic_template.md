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
