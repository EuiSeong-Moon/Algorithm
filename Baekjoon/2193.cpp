#include <iostream>

using namespace std;

int main(void)
{
	int N;
	int j;
	cin >> N;
	long long *arr = new long long[N+1];	//int는 size문제로 안됨.
	
	if (N >= 2)
	{
		arr[0] = 0;
		arr[1] = 1;
	}
	else {
		cout << N;
		return 0;
	}
	for (int i = 2; i <= N; i++)	//n자리 수일때 첫번째와 두번째자리는 1 과 0으로 고정 그 다음부터는 1일때 경우의 수와 2일 때 경우의 수를 더하는데
	{								// 1일때는 arr[n-2]와 같고 0일 때는 다음 자리수 1일때와 0일때를 더한 값이다. 이를 반복하면 된다.
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