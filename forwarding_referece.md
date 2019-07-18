#### Template 에서의 reference
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
  * 자동으로 두가지 버전의 함수를 만들어준다. 그것도 reference 가 붙은 형태로..
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

auto&& c = a;
auto&& d = 0;
cout << boost::typeindex::type_id_with_cvr<decltype(c)>().pretty_name() << endl;  // int&
cout << boost::typeindex::type_id_with_cvr<decltype(d)>().pretty_name() << endl;  // int&&

vector<int> v1(32);   auto a1 = v1[0];  // auto& a1 = v1[0] ok    - lvalue return
vector<bool> v2(32);  auto a2 = v2[0];  // auto& a2 = v2[0] error - rvalue return
cout << boost::typeindex::type_id_with_cvr<decltype(a1)>().pretty_name() << endl; // int
cout << boost::typeindex::type_id_with_cvr<decltype(a2)>().pretty_name() << endl; // std::_Bit_reference
```
