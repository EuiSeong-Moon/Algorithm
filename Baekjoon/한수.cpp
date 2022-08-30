#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	if (99 <= N && N <= 110)
		cout << "99" << endl;
	else if (N < 99)
		cout << N << endl;
	else
	{
		int n1000 = N / 1000;
		int n100 = (N%1000) / 100;
		int n10 = ((N%1000)%100) / 10;
		int n = (((N%1000)%100)%10) % 10;
		if (n1000 == 1)
			cout << 99 + 9 * 5 << endl;
		else {	//brute force
			int answer = 99 + (n100 - 1) * 5;
			for (int i = 0; i <= n10; i++)
			{
				for (int j = 0; j <= 9; j++)
				{
					if (i == n10 && j > n)
						break;
					if (n100 - i == i - j)
						answer++;	//111 123 135 146 159 999 987 975 963 951
				}
			}
			cout << answer << endl;
		}
	}
	return 0;
}