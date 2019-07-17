#include <iostream>
#include <vector>
using namespace std;

/*
int main()
{
	vector<int> v(10, 0); // 10개를 0으로 초기화
	v.resize(7);

	cout << v.size() << endl;     // 7
	cout << v.capacity() << endl; // 10

	v.push_back(0);

	cout << v.size() << endl;     // 8
	cout << v.capacity() << endl; // 10

	v.shrink_to_fit(); // 여분의 메모리 제거

	cout << v.size() << endl;     // 8
	cout << v.capacity() << endl; // 8

	v.push_back(0);

	cout << v.size() << endl;     // 9
	cout << v.capacity() << endl; // 12
}
*/
class DBConnect
{
public:
	DBConnect()  { cout << "DB 연결" << endl; }
	~DBConnect() { cout << "DB 닫기" << endl; }
};
int main()
{
	vector<DBConnect> v(10);
	v.resize(7); // 어떻게 구현되어 있을지 생각해
				 // 보세요.
			// 줄어든 3개는 메모리는 있습니다.
			// 하지만 소멸자를 명시적으로 호출해서
			// DB을 닫아야 합니다.

	v.resize(8); // 8번째 메모리는 이미 있습니다.
		// 생성자만 호출해서 다시 DB에 붙여야 합니다.
}

// 안드로이드 소스
// platform_system_core/libutils
// include/utils/type_helpers.h 열어보세요
// copy_type() 함수 찾아보세요. - 167 line










