#include <iostream>
#include <stack>
#include<vector>
#include <algorithm>
using namespace std;

int left(vector<int> buffer, int i, int j, int N, int** map, int direct, int init_i, int init_j, int& answer,int maxs,int& max_b);
int main(void)
{
	int T;
	cin >> T;
	for (int test_case = 1; test_case < T + 1; test_case++)
	{
		int max = -1;
		int answer;
		int max_b = 0;
		vector<int> buffer;
		int N;
		cin >> N;
		int** map = new int*[N];
		for (int i = 0; i < N; i++)
			map[i] = new int[N];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int buf;
				cin >> buf;
				map[i][j] = buf;
			}
		}
		for (int i = 0; i < N -2; i++)
		{
			for (int j = 1; j < N - 1; j++)
			{
				buffer.push_back(map[i][j]);
				left(buffer, i + 1, j - 1, N, map, 0, i, j, answer, N, max_b);
				buffer.clear();
				if (answer > max)
					max = answer;
				while (max_b != 0)
				{
					int buf_max = max_b;
					max_b = 1;
					buffer.push_back(map[i][j]);
					left(buffer, i + 1, j- 1, N, map, 0, i, j, answer, buf_max, max_b);
					buffer.clear();
					if (answer > max)
						max = answer;
				}
				
			}
		}
		cout << "#" << test_case << " " << max << endl;
	}
	return 0;
}

int left(vector<int> buffer,int i,int j,int N,int** map,int direct,int init_i,int init_j,int& answer,int maxs,int& max_b)
{
	answer = -1;
	if (i == init_i && j  == init_j)
	{
		answer = buffer.size();
		buffer.clear();
		return 0;
	}
	if(i < 0 || j < 0 || i >= N || j >= N)
	{
		if (direct == 0)
			max_b -= 1;
		return -1;
	}
	else
		buffer.push_back(map[i][j]);
	if (find(buffer.begin(), buffer.end()-1, map[i][j]) != buffer.end()-1 || max_b>=maxs)
	{
	//	cout << map[i][j];
		if (direct==0)
			max_b -=1;
		buffer.pop_back();
		return -1;
	}

	if (direct == 0)
	{
		max_b += 1;
		if (left(buffer, i + 1, j - 1, N, map, 0, init_i, init_j, answer,maxs,max_b) == -1)
		{
			if (left(buffer, i + 1, j + 1, N, map, 1, init_i, init_j, answer, maxs, max_b) == -1)
			{
				buffer.pop_back();
				return -1;
			}
		}
	}
	else if (direct == 1)
	{
		if (left(buffer, i + 1, j + 1, N, map, 1, init_i, init_j, answer, maxs, max_b) == -1)
		{
			if (left(buffer, i- 1, j + 1, N, map, 2, init_i, init_j, answer, maxs, max_b) == -1)
			{
				buffer.pop_back();
				return -1;
			}
		}
	}
	else if (direct == 2)
	{
		if (left(buffer, i - 1, j + 1, N, map, 2, init_i, init_j, answer, maxs, max_b) == -1)
		{
			if (left(buffer, i - 1, j - 1, N, map, 3, init_i, init_j, answer, maxs, max_b) == -1)
			{
				buffer.pop_back();
				return -1;
			}
		}
	}
	else if (direct == 3)
	{
		if (left(buffer, i - 1, j - 1, N, map, 3, init_i, init_j, answer, maxs, max_b) == -1)
		{
			buffer.pop_back();
			return -1;
		}
			
	}
	return 0;
}
