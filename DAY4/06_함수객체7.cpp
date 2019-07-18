inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less { inline bool operator()(int a, int b) { return a < b; } };
struct Greater { inline bool operator()(int a, int b) { return a > b; } };

template<typename T> void foo(T f){	int n = f(1, 2);}
int main()
{
	Less    f1;
	Greater f2;
	foo(cmp1);
	foo(cmp2);
	foo(f1);
	foo(f2);
}
// 1. 컴파일 하면 foo 함수가 몇개 생성될까요 ? 3개
// 2. 각 foo 함수의 f(1,2)의 인라인 치환 여부를 생각해 보세요
// 3. foo를 제외하면 몇개의 함수가 남아 있을까요 ?

// linux : g++
// vc++  : cl


// cl 06_함수객체7.cpp   /Ob1  /FAs


// /Ob1 : 인라인 치환 적용해 달라
// /FAs : 어셈블리 코드 생성해 달라.

// notepad 06_함수객체7.asm   으로 열어 보세요






