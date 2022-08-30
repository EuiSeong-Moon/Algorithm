#include <iostream>

using namespace std;

int arr[1000];
int max_value(int a, int b, int c, int d)
{
	if (a < b)
		a = b;
	if (c < d)
		c = d;
	if (a < c)
		a = c;
	return a;
}
int main(void)
{
	for (int test = 0; test < 10; test++) {
		int N,buf,answer=0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> buf;
			arr[i] = buf;
		}
		for (int i = 2; i < N-2; i++) {
			int max=max_value(arr[i - 2], arr[i - 1], arr[i + 1], arr[i + 2]);
			int values = arr[i] - max;
			if (values > 0)
				answer += values;
		}
		cout << "#" << test + 1 << " " << answer << endl;

	}
	return 0;
}