#include<iostream>
using namespace std;
int main(void)
{
	int N;
	cin >> N;
//	long long *number = new long long[N+1];
	unsigned long long number[101];
	long long del[101];
	del[1] = 1;
	del[2] = 2;
	number[1] = 9;
	number[2] = 17;
	number[3] = 32;
	if (N == 1)
		cout << number[1] << endl;
	else if (N == 2)
		cout << number[2] << endl;
	else if (N == 3)
		cout << number[3] << endl;
	else
	{
		for (int i = 4; i <= N; i++)
		{
			del[i - 1] = del[i - 3] * 3;
			number[i] = number[i - 1] * 2 - del[i-1];
		}
		cout << number[N] % 1000000000 << endl;
	}
	return 0;
}