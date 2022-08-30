#include <iostream>

using namespace std;

long long barket[1001][1001];
int main(void)
{
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N + 1; i++)
	{
		barket[i][0] = 1;
		barket[i][i] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; (j < i && j<=K); j++)
		{
			barket[i][j] = (barket[i-1][j-1]%10007+barket[i-1][j]%10007)%10007; //�߰��� %10007�� ���ϸ� �����÷ο�� ���� �ȳ��� ��, (A+b)%10007=(A%10007+B%10007)%10007�� ����
		}
	}
	cout << barket[N][K]% 10007;
	return 0;
}