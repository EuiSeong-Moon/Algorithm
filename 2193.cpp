#include <iostream>

using namespace std;

int main(void)
{
	int N;
	int j;
	cin >> N;
	long long *arr = new long long[N+1];	//int�� size������ �ȵ�.
	
	if (N >= 2)
	{
		arr[0] = 0;
		arr[1] = 1;
	}
	else {
		cout << N;
		return 0;
	}
	for (int i = 2; i <= N; i++)	//n�ڸ� ���϶� ù��°�� �ι�°�ڸ��� 1 �� 0���� ���� �� �������ʹ� 1�϶� ����� ���� 2�� �� ����� ���� ���ϴµ�
	{								// 1�϶��� arr[n-2]�� ���� 0�� ���� ���� �ڸ��� 1�϶��� 0�϶��� ���� ���̴�. �̸� �ݺ��ϸ� �ȴ�.
		j = i;
		arr[i] = arr[j-2];
		j -= 2;
		while (j > 1)
		{
			j -= 1;
			arr[i] += arr[j];
		}
		arr[i] += 1;
	}

	cout << arr[N];
	return 0;
}