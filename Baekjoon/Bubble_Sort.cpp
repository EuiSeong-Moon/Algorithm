#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		arr[i] = a;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j + 1];
				arr[j+1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}