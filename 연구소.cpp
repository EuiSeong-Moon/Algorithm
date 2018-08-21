#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Points{
public:
	int xpos;
	int ypos;
};

int sparse(int** map, vector<Points>& dark, int N, int M);

int main(void)
{
	int N, M,answer=0;
	cin >> N >> M;
	int **map = new int*[N+4];
	for (int i = 0; i < N+4; i++)
		map[i] = new int[M+4];
	for (int i = 0; i < N + 2; i++)
	{
		for (int j = 0; j < M + 2; j++)
			map[i][j] = 1;
	}
	vector<Points> dark;
	vector<Points> flag;
	int buf;
	for (int i = 1; i < N+1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			cin >> buf;
			map[i][j] = buf;
			//map_buf[i][j] = buf;
			if (buf == 2)
			{
				Points dpt;
				dpt.xpos = i;	dpt.ypos = j;
				dark.push_back(dpt);
			}
		}
	}
	int i = 1, j = 1;
	Points tag_pt;
	while(1)
	{
		while (1)
		{
			if (map[i][j] == 0)
			{
				Points fpt;
				fpt.xpos = i;	fpt.ypos = j;
				flag.push_back(fpt);
				map[i][j] = 1;
			}
			if (flag.size() == 3)
			{
				int cur_count = sparse(map, dark, N, M);
				if (answer < cur_count)
					answer = cur_count;
				map[flag.at(2).xpos][flag.at(2).ypos] = 0;
				flag.pop_back();
			}
			j++;
			if (j >= M + 1)
				break;
		}
		j = 1;
		i++;
		if (i == N + 1)
		{
			if (flag.size() == 0)
				break;
			i = flag.at(flag.size()-1).xpos;
			j = flag.at(flag.size()-1).ypos+1;
			map[i][j-1] = 0;
			flag.pop_back();
		}
	}
	cout << answer << endl;
	return 0;
}
int sparse(int** map,vector<Points>& dark,int N,int M)
{
	int **map_buf = new int*[N + 2];
	for (int i = 0; i < N + 2; i++)
		map_buf[i] = new int[M + 2];

	for (int i = 0; i < N+2; i++)
	{
		for (int j = 0; j < M + 2; j++)
			map_buf[i][j] = map[i][j];
	}
	queue<Points> darking;
	for (int i = 0; i < dark.size(); i++)
		darking.push(dark.at(i));
	while (darking.size() != 0)
	{
		Points pt;
		pt = darking.front();
		darking.pop();
		if (map_buf[pt.xpos+1][pt.ypos] == 0)
		{
			map_buf[pt.xpos+1][pt.ypos] = 2;
			Points newpt;
			newpt.xpos = pt.xpos+1;
			newpt.ypos = pt.ypos;
			darking.push(newpt);
		}
		if (map_buf[pt.xpos-1][pt.ypos] == 0)
		{
			map_buf[pt.xpos-1][pt.ypos] = 2;
			Points newpt;
			newpt.xpos = pt.xpos-1;
			newpt.ypos = pt.ypos;
			darking.push(newpt);
		}
		if (map_buf[pt.xpos][pt.ypos+1] == 0)
		{
			map_buf[pt.xpos][pt.ypos+1] = 2;
			Points newpt;
			newpt.xpos = pt.xpos;
			newpt.ypos = pt.ypos+1;
			darking.push(newpt);
		}
		if (map_buf[pt.xpos][pt.ypos-1] == 0)
		{
			map_buf[pt.xpos][pt.ypos-1] = 2;
			Points newpt;
			newpt.xpos = pt.xpos;
			newpt.ypos = pt.ypos-1;
			darking.push(newpt);
		}
	}
	int count = 0;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			if (map_buf[i][j] == 0)
				count++;
		}
	}
	
	return count;
}