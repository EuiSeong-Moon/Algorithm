#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
	//아스키코드는 그냥 인트로 출력하면 된다.
	//반대로 숫자를 (char)로 출력하면 아스키코드의 결과들이 나온다 예를들어 (char)97은 a가 출력된다.
	char data;
	cin >> data;
	cout << (int)data << endl;
	return 0;
}