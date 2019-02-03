#include<iostream>
#include <queue>
using namespace std;

int dr[] = { 0,0,-1 };
int dc[] = { -1,1,0 };
int map[100][100];
int flag[100][100] = { 0, };
int main(void) {
	pair<int, int> s_pos;
	int answer;
	for (int test = 0; test < 10; test++) {
		int N,buf;
		cin >> N;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				flag[i][j] = 0;
				cin >> buf;
				map[i][j] = buf;
				if (buf == 2) {
					s_pos.first = i;	s_pos.second = j;
				}
			}
		}
		queue<pair<int,int>> bfs;
		bfs.push(s_pos);
		
		while (bfs.size() != 0) {
			pair<int, int> p_buf;
			p_buf = bfs.front();	bfs.pop();
			flag[p_buf.first][p_buf.second] = 1;
			if (p_buf.first == 0) {
				answer = p_buf.second;
				break;
			}
			for (int x = 0; x < 3; x++) {
				int nr = p_buf.first + dr[x];
				int nc = p_buf.second + dc[x];

				if (nr<0 || nc < 0 || nr >= 100 || nc >= 100)
					continue;
				if (flag[nr][nc] == 1)
					continue;
				
				if (map[nr][nc] == 1)
				{
					pair<int, int> new_pos;	new_pos.first = nr;	new_pos.second = nc;
					bfs.push(new_pos);
					break;
				}
			}
		}
		cout << "#" << N << " " << answer << endl;
	}
	return 0;
}