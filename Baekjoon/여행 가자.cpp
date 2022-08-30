#include<iostream>
#include<vector>

using namespace std;
int area[200];
int find(int x)
{
	if (x == area[x])
	{
		return x;
	}
	else
	{
		int y = find(area[x]);
		area[x] = y;
		return y;
	}
}
void adding(int x, int y)
{
	x = find(x);
	y = find(y);
	area[y] = x;
}
int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		area[i] = i;
	}
	int M,buf;
	cin >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> buf;
			if (buf == 1) {
				if (i < j)
					adding(i, j);
				else
					adding(j, i);
			}
		}
	}
	int before;
	for (int i = 0; i < M; i++) {
		cin >> buf;
		if (i == 0)
			before = find(buf-1);
		if (find(buf-1) == before) {
			
		}
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

	return 0;
}