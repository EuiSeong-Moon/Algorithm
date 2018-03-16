#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	int N, M,u,v;
	queue<int>barket;
	cin >> N >> M;
	bool *Nodes = new bool[N + 1];
	bool **line = new bool*[N + 1];
	for (int i = 0; i < N + 1; i++)
		line[i] = new bool[N + 1];

	for (int i = 1; i < N + 1; i++)
		Nodes[i] = false;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			line[i][j] = false;
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		line[u][v] = true;
		line[v][u] = true;
	}

	int fron;
	int answer = 0;
	for (int kk = 1; kk < N + 1; kk++)
	{
		if (Nodes[kk] == true)
			continue;
		barket.push(kk);
		while (barket.size() != 0)
		{
			fron = barket.front();
			barket.pop();
			Nodes[fron] = true;
			for (int i = 1; i < N + 1; i++)
			{
				if (line[fron][i] == true)
				{
					if (Nodes[i] == false)
					{
						barket.push(i);
						Nodes[i] == true;
						line[fron][i] = false;
						line[i][fron] = false;
					}
				}
			}
		}
		answer += 1;
	}
	cout << answer << endl;
	return 0;
}