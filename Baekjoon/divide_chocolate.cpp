#include <iostream>

using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;
	cout << (M - 1) + (N - 1)*M << endl;
}
//	1	2	3	4	5	N
//1	0	1	2	3	4
//2	1	3	5	7
//3	2	5	8
//4
//5
//M