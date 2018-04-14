#include <iostream>
#include <vector>

//k의 깊이가 최대 k로 1부터 k까지 깊이 모두 고려해야 함.
using namespace std;

class Points {
public:
	int xpos;
	int ypos;
};
int DFS(int** map, int x, int y, int direct, vector<Points>& buffer, int& max_size, vector<Points>& max_point);
int main(void)
{
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int max = 0;
		int flag[4] = { 0, };
		int max_size = 0;
		vector<Points> high;
		vector<Points> buffer;
		vector<Points> max_point;
		vector<Points> max_point2;
		int answer = 0;
		int N,k;
		cin >> N>>k;
		int** map = new int*[N + 2];
		for (int i = 0; i < N + 2; i++)
		{
			map[i] = new int[N + 2];
			for (int j = 0; j < N + 2; j++)
				map[i][j] = 100;
		}
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < N + 1; j++)
			{
				int buff;
				cin >> buff;
				map[i][j] = buff;
				if (buff > max)
				{
					max = buff;
					high.clear();
					Points points;
					points.xpos = i;
					points.ypos = j;
					high.push_back(points);
				}
				else if (buff == max)
				{
					Points points;
					points.xpos = i;
					points.ypos = j;
					high.push_back(points);
				}
			}
		}
		for (int i = 0; i < high.size(); i++)
			DFS(map, high.at(i).xpos, high.at(i).ypos, 5, buffer, max_size, max_point);

		if (k != 0)
		{
			for (int m = 0; m < k + 1; m++)
			{
				max_size = 0;
				int ttt = 0;
				for (int i = 1; i < N + 1; i++)
				{
					for (int l = 1; l < N + 1; l++)
					{
						if (map[i][l] < m)
						{
							ttt = map[i][l] - m;
							map[i][l] = 0;
						}
						else
							map[i][l] -= m;
						for (int j = 0; j < high.size(); j++)
						{
							if (i == high.at(j).xpos &&l == high.at(j).ypos)
								continue;
							DFS(map, high.at(j).xpos, high.at(j).ypos, 5, buffer, answer, max_point2);
						}
						if (ttt != 0)
						{
							map[i][l] = ttt + m;
							ttt = 0;
						}
						else
							map[i][l] += m;
					}
				}
			}
			cout << "#" << test_case << " " << answer << endl;
			
		}
		else
			cout << "#" << test_case << " " << max_size << endl;

	}

	return 0;
}
int DFS(int** map, int x, int y,int direct,vector<Points>& buffer,int& max_size,vector<Points>& max_point)
{
	int back = 0;
	int flag[10] = { 0, };
	if (direct == 1)
		flag[0] = 1;
	if (direct==0)
		flag[1] = 1;

	if (direct == 2)
	{
		flag[3] = 1;
	}
	if (direct == 3) {
		flag[4] = 1;
	}
	Points pt;
	pt.xpos = x;
	pt.ypos = y;
	buffer.push_back(pt);
	do
	{
		if (map[x][y] > map[x - 1][y] && flag[0] == 0)
		{
			back = DFS(map, x - 1, y, 0, buffer, max_size, max_point);
			if (back == -1)
				flag[0] = 1;
		}
		else if (map[x][y] > map[x + 1][y] && flag[1] == 0)
		{
			back = DFS(map, x + 1, y, 1, buffer, max_size, max_point);
			if (back == -1)
				flag[1] = 1;
		}
		else if (map[x][y] > map[x][y - 1] && flag[2] == 0)
		{
			back = DFS(map, x, y - 1, 2, buffer, max_size, max_point);
			if (back == -1)
				flag[2] = 1;
		}
		else if (map[x][y] > map[x][y + 1] && flag[3] == 0)
		{
			back = DFS(map, x, y + 1, 3, buffer, max_size, max_point);
			if (back == -1)
				flag[3] = 1;
		}
		else {
			if (buffer.size() > max_size)
			{
				max_size = buffer.size();
				max_point.clear();
				for (int i = 0; i < buffer.size(); i++)
					max_point.push_back(buffer.at(i));
			}
			buffer.pop_back();
			return -1;

		}
	} while (back == -1);

}