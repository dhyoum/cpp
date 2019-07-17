#### Template 에서의 reference 사용
- T& : 임의의 타입의 lvalue 만 전달가능
```c
template<typename T>
void f(T& t) {}
int main() {
    int n = 10;
    f<int>(n);     // T : int,   T& : int&,   f(int&)
    f<int&>(n);    // T : int&,  T& : int& &, f(int&)
    f<int&&>(n);   // T : int&&, T& : int&&,  f(int&)
    // f(10); error
    f(n); // T : int
}
```
- T&& : 임의의 타입의 lvalue 와 rlavue 모두 전달가능 : **Forwarding reference**
```c
template<typename T>
void f(T&& t) {}
int main() {
  int n = 10;
  f<int>(10);   // T : int,   T&& : int&&,    f(int&&)
  f<int&>(n);   // T : int&,  T&& : int& &&,  f(int&)
  f<int&&>(10); // T : int&&, T&& : int&& &&, f(int&&)

  f(10); // f(int&&);
  f(n);  // f(int&);
}
```
