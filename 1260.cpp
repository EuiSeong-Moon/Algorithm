#include <iostream>
#include <queue>
//#include <stack>
using namespace std;
void DFS(int start,  int N, int& m);
void BFS(int start, int N);

int line[1001][1001];
int point[1001];
int point2[1001];
int main(void)
{
	int N, M, V,buf,buf2;
	scanf("%d %d %d",&N, &M, &V);
	//vector<int> node;
	for (int i = 0; i < M; i++)
	{	
		scanf("%d %d",&buf,&buf2);
		line[buf][buf2] = 1;
		line[buf2][buf] = 1;
	}
	int m = 0;
	DFS(V, N, m);
	cout << endl;
	BFS(V,N);
	cout << endl;
	return 0;
}
void DFS(int start, int N,int& m)
{
	//int buf;
	//buf = start;
	point2[start] = 1;
	//node.push_back(start);
	cout << start << " ";
	for (int i = 1; i < N + 1; i++)
	{
		if (line[start][i] == 1 && point2[i]!=1)
		{
			DFS(i, N, m);
		}
	}
	

}
void BFS(int start,int N)
{
	int m = 0;
	int buf;
	queue<int> box;
	point[start] = 1;
	box.push(start);

	while (box.size() != 0)
	{
		buf = box.front();
		cout << buf << " ";
		box.pop();
		for (int i = 1; i < N + 1; i++)
		{
			if (line[buf][i] == 1 && point[i]!=1)
			{
				line[buf][i] = 0;
				line[i][buf] = 0;
				point[i] = 1;
				box.push(i);
			}
		}
	}
}