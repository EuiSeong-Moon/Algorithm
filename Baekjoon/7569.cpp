#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Points {
public:
	int x;
	int y;
	int z;
	Points(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Points()
	{}
	void set(Points a)
	{
		x = a.x;
		y = a.y;
		z = a.z;
	}
};

int barket[111][111][111];
int BFS(int arr[111][111][111], vector<Points>& point);

int main(void)
{
	int M, N, H,ins,answer;
	vector<Points>point;
	cin >> M >> N >> H;
	for (int i = 1; i < H + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			for (int k = 1; k < M + 1; k++)
			{
				cin >> ins;
				if (ins == 1)
				{
					Points pp(k, j, i);
					point.push_back(pp);
				}
				if (ins == 0)
					ins = -2;
				barket[k][j][i] = ins;
			}
		}
	}
	answer=BFS(barket, point);
	for (int i = 1; i < H + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			for (int k = 1; k < M + 1; k++)
			{
				if (barket[k][j][i] == -2)
					answer = -1;
			}
		}
	}
	
	cout << answer;

	return 0;
}
int BFS(int arr[111][111][111],vector<Points>& point)
{
	int day = 0;
	int k = 0;
	queue<Points> aa;
	for (int i = 0; i < point.size(); i++)
	{
		aa.push(point.at(i));
	}
	k = aa.size();
	while (aa.size() != 0)
	{
		if (k == 0)
		{
			day += 1;
			k = aa.size();
		}
		k -= 1;
		Points pt;
		pt.set(aa.front());
		aa.pop();
		if (arr[pt.x + 1][pt.y][pt.z] == -2)
		{
			arr[pt.x + 1][pt.y][pt.z] = 1;
			Points newpt(pt.x + 1, pt.y, pt.z);
			aa.push(newpt);
		}
		if (arr[pt.x - 1][pt.y][pt.z] == -2)
		{
			arr[pt.x -1][pt.y][pt.z] = 1;
			Points newpt(pt.x - 1, pt.y, pt.z);
			aa.push(newpt);
		}
		if (arr[pt.x][pt.y+1][pt.z] == -2)
		{
			arr[pt.x][pt.y+1][pt.z] = 1;
			Points newpt(pt.x, pt.y+1, pt.z);
			aa.push(newpt);
		}
		if (arr[pt.x][pt.y-1][pt.z] == -2)
		{
			arr[pt.x][pt.y-1][pt.z] = 1;
			Points newpt(pt.x, pt.y-1, pt.z);
			aa.push(newpt);
		}
		if (arr[pt.x][pt.y][pt.z+1] == -2)
		{
			arr[pt.x][pt.y][pt.z+1] = 1;
			Points newpt(pt.x, pt.y, pt.z+1);
			aa.push(newpt);
		}
		if (arr[pt.x][pt.y][pt.z-1] == -2)
		{
			arr[pt.x][pt.y][pt.z-1] = 1;
			Points newpt(pt.x, pt.y, pt.z-1);
			aa.push(newpt);
		}
	}
	return day;
}