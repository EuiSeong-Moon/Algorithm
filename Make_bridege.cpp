#include<iostream>
#include<queue>
using namespace std;

char arr[101][101] = { 0 };
int BFS(char arr[][101],int i, int j)
{
	queue<int> barketi;
	queue<int> barketj;
	int depth;
	int minimum = 1000;
	while (barketi.size() != 0)
	{
		if ((arr[i - 1][j] != 1 && arr[i - 1][j] != 0) || (arr[i + 1][j] != 1 && arr[i + 1][j] != 0) || (arr[i][j + 1] != 1 && arr[i][j + 1] != 0) || (arr[i][j - 1] != 1 && arr[i][j - 1] != 0))
		{
			if (minimum > depth)
				minimum = depth;
		}
		if (arr[i - 1][j] == 0)
		{
			barketi.push(i - 1);
			barketj.push(j);
		}
		else if (arr[i][j - 1] == 0)
		{
			barketi.push(i);
			barketj.push(j - 1);
		}
		else if (arr[i + 1][j] == 0)
		{
			barketi.push(i + 1);
			barketj.push(j);
		}
		else if (arr[i][j + 1] == 0)
		{
			barketi.push(i);
			barketj.push(j + 1);
		}
		else
		{
			depth -= 1;
			continue;
		}
		depth += 1;
	}
	return minimum;
}
int main(void)
{
	//ÃÊ±âÈ­ ¹× ¼¶³¢¸® ±¸ºÐ Áþ±â k-1Àº ¼­·Î´Ù¸¥ ¼¶ÀÇ °³¼ö
	int N,k=1;
	int answer = 10000;
	char garbage;
	cin >> N;

	for (int i = 1; i < N+1; i++)
	{
		for (int j = 1; j < N+ 1; j++)
		{
			scanf("%d", arr[i][j]);
			if (arr[i][j] == 1 && arr[i - 1][j] == 1)
			{
				arr[i][j] = ++k;
				arr[i - 1][j] = k;
			}
			else if (arr[i][j] == 1 && arr[i][j - 1] == 1)
			{
				arr[i][j] = ++k;
				arr[i][j - 1] = k;
			}
			else if (arr[i][j] == 1 && (arr[i - 1][j] == k || arr[i][j - 1] == k))
				arr[i][j] = k;
		}
	}
	//BFS

	//Å½»ö
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			if (arr[i][j] != 0)
			{
				int c;
				c=BFS(arr, i, j);
				if (answer > c)
					answer = c;
			}
		}
	}
	cout << answer;
}