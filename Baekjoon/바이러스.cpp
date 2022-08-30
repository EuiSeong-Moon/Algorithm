#include <iostream>

using namespace std;
int computer[101];
int find(int x);	void adding(int x, int y);
int main(void)
{
	int N,buf1,buf2,line;
	cin >> N >> line;
	for (int i = 1; i <= N; i++)
	{
		computer[i] = i;
	}
	for (int i = 0; i < line; i++)
	{
		cin >> buf1 >> buf2;
		adding(buf1, buf2);
	}
	int count = 0;	int compare = computer[1];
	for (int i = 1; i <= N; i++) {
		if (computer[i] == compare)
			count++;
	}
	cout << count-1;
	return 0;
}

int find(int x)
{
	if (x == computer[x])
	{
		return x;
	}
	else
	{
		int y = find(computer[x]);
		computer[x] = y;
		return y;
	}
}
void adding(int x, int y)
{
	x = find(x);
	y = find(y);
	computer[y] = x;
}