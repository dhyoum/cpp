# C++11
#### Legacy grammer
- function pointer
```c
void (*f)(int);
```
- member function pointer
```c
void (Class:*f) (int);
Dialog dlg; (dlg.* f)(20);
Dialog* pDlg; (pDlg->* f)(20);
```
### Rvalue reference
- temporary variable
- RVO
- RAII ( ownership )
### Move semantics
- ownership move
- casting
- POD / trivial
### Universal reference
### Perfect forwarding
- what is the concept of forwarding ?
### Smart pointer
- RAII again
- polymophism
- unique_ptr : [how to implement for pImpl idiom?](https://www.fluentcpp.com/2017/09/22/make-pimpl-using-unique_ptr/) 
- shared_ptr : [how to cast?](https://stackoverflow.com/questions/1358143/downcasting-shared-ptrbase-to-shared-ptrderived)
### Lambda function
- review the global function
- how to capture ?
- [closure](https://en.wikipedia.org/wiki/Closure_(computer_programming))
- free variable
### auto
- how to check the type deduction ?
### const / constexpr
- compile time constant
- constexpr constructor
### Uniform initialize 
- [Initialization](https://en.cppreference.com/w/cpp/language/initialization)
### initailzer_list
Initializer lists may be implemented as a pair of pointers or pointer and length. Copying a std::initializer_list does not copy the underlying objects.
### thread
### mutex, condition_variable, atomic
### future, promise, packaged_task
### boost::optional, boost::variant, boost:fibers

### link
- [cpp core guide](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- [cpprefernece](https://en.cppreference.com/w/)
- [modoo](https://modoocode.com/135)
- [soen](http://soen.kr/)
- [mingw](https://nuwen.net/)
