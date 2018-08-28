#include <iostream>

using namespace std;
int TeT5(int** map, int N, int M);
int TeT1(int** map, int N, int M);
int TeT2(int** map, int N, int M);
int TeT3(int** map, int N, int M);
int TeT4(int** map, int N, int M);
int main(void)
{
	int N,M,buf;
	cin >> N >> M;
	int **map = new int*[N];
	for (int i = 0; i < N; i++)
	{
		map[i] = new int[M];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> buf;
			map[i][j] = buf;
		}
	}
	int answer = 0;
	buf = 0;
	buf = TeT1(map, N, M);
	if (buf > answer)
		answer = buf;
	buf = TeT2(map, N, M);
	if (buf > answer)
		answer = buf;
	buf = TeT3(map, N, M);
	if (buf > answer)
		answer = buf;
	buf = TeT4(map, N, M);
	if (buf > answer)
		answer = buf;
	buf = TeT5(map, N, M);
	if (buf > answer)
		answer = buf;
	cout << answer;
	return 0;
}
int TeT5(int** map, int N, int M) //³ë¶û»ö µµÇü
{
	int max = 0;
	int sum = 0;
	for (int i = 0; i < N-1; i++)
	{
		for (int j = 0; j < M-1; j++)
		{
			sum += map[i][j];
			sum += map[i][j + 1];
			sum += map[i + 1][j + 1];
			sum += map[i + 1][j];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	return max;
}
int TeT4(int **map, int N, int M) //ÀÚÁÖ
{
	int max = 0;
	int sum = 0;
	for (int i = 0; i < N-1; i++)
	{
		for (int j = 0; j < M-2; j++)
		{
			sum += map[i][j];
			sum += map[i][j+1];
			sum += map[i + 1][j + 1];
			sum += map[i][j + 2];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			sum += map[i][j];
			sum += map[i][j + 1];
			sum += map[i + 1][j + 1];
			sum += map[i-1][j +1];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			sum += map[i][j];
			sum += map[i+1][j];
			sum += map[i + 1][j + 1];
			sum += map[i+1][j -1];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			sum += map[i][j];
			sum += map[i+1][j];
			sum += map[i + 1][j + 1];
			sum += map[i+2][j];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	return max;
}
int TeT3(int **map, int N, int M) //³ì»ö
{
	int max = 0;
	int sum = 0;
	for (int i = 0; i < N-2; i++)
	{
		for (int j = 0; j < M-1; j++)
		{
			sum += map[i][j];
			sum += map[i + 1][j];
			sum += map[i + 1][j+1];
			sum += map[i + 2][j + 1];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 1; j < M - 1; j++)
		{
			sum += map[i][j];
			sum += map[i + 1][j];
			sum += map[i][j + 1];
			sum += map[i + 1][j-1];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	//´ëÄª
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 1; j < M; j++)
		{
			sum += map[i][j];
			sum += map[i + 1][j];
			sum += map[i+1][j - 1];
			sum += map[i +2][j - 1];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M-2; j++)
		{
			sum += map[i][j];
			sum += map[i][j+1];
			sum += map[i + 1][j + 1];
			sum += map[i + 1][j + 2];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	return max;
}
int TeT2(int **map, int N, int M) //ÁÖÈ²
{
	int max = 0;
	int sum = 0;
	for (int i = 0; i < N-2; i++)
	{
		for (int j = 0; j < M-1; j++)
		{
			sum += map[i][j];
			sum += map[i + 1][j];
			sum += map[i + 2][j];
			sum += map[i + 2][j+1];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			sum += map[i][j];
			sum += map[i + 1][j];
			sum += map[i][j+1];
			sum += map[i][j + 2];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			sum += map[i][j];
			sum += map[i + 1][j+1];
			sum += map[i + 2][j+1];
			sum += map[i][j + 1];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	for (int i = 0; i < N-1; i++)
	{
		for (int j = 2; j < M; j++)
		{
			sum += map[i][j];
			sum += map[i+1][j];
			sum += map[i+1][j-1];
			sum += map[i+1][j-2];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	//´ëÄª
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 1; j < M; j++)
		{
			sum += map[i][j];
			sum += map[i + 1][j];
			sum += map[i + 2][j];
			sum += map[i + 2][j-1];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M-2; j++)
		{
			sum += map[i][j];
			sum += map[i + 1][j];
			sum += map[i + 1][j+1];
			sum += map[i + 1][j+2];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M-1; j++)
		{
			sum += map[i][j];
			sum += map[i + 1][j];
			sum += map[i + 2][j];
			sum += map[i][j + 1];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M-2; j++)
		{
			sum += map[i][j];
			sum += map[i][j+1];
			sum += map[i][j+2];
			sum += map[i + 1][j +2];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	return max;
}
int TeT1(int **map,int N,int M) //ÇÏ´Ã
{
	int max = 0;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M-3; j++)
		{
			sum += map[i][j];
			sum += map[i][j + 1];
			sum += map[i][j + 2];
			sum += map[i][j + 3];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	for (int i = 0; i < N-3; i ++ )
	{
		for (int j = 0; j < M; j++)
		{
			sum += map[i][j];
			sum += map[i+1][j];
			sum += map[i+2][j];
			sum += map[i+3][j];
			if (max < sum)
				max = sum;
			sum = 0;
		}
	}
	return max;
}