#include <string>
#include <iostream>
using namespace std;

int main()
{
	string s1 = "C:\\aa\\bb\\cc"; // "\\" 정규 표현식이나 디렉토리 표현에 널리 사용

	// raw string : \ 를 특수 문자로 취급하지 말라
	// "( : 문자열 시작
	// )" : 문자열 종료
	string s2 = R"(C:\aa\bb\cc)"; 
	cout << s2 << endl;

	// " 를 포함하려면 - 그냥 적으면 된다
	string s3 = R"(C:\aa\b"b\cc)";


	// )" 를 표기하려면
	string s4 = R"***(C:\aa\)"b\cc)***";

	cout << s4 << endl;


}







