#include<iostream>
#include<queue>
#include<string>
using namespace std;
char map[1000][1000];
bool flag[1000][1000];
int dr[] = { 1,-1,0,0, };
int dc[] = { 0,0,1,-1 };
int main(void) {
	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int N, M;
		string buf;
		cin >> M >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				flag[i][j] = false;
		}
		queue<pair<int, int>> fires;
		queue<pair<int, int>> man;
	
		for (int i = 0; i < N; i++) {
			cin >> buf;
			for (int j = 0; j < M; j++) {
				if (buf.at(j) == '*')
				{
					pair<int, int> p;	p.first = i;	p.second = j;
					fires.push(p);
				}
				else if (buf.at(j) == '@') {
					pair<int, int> p;	p.first = i;	p.second = j;
					man.push(p);
					flag[i][j] = true;
				}
				map[i][j] = buf.at(j);
			}
		}
		int time = 1;
		int fire_flag = fires.size();
		int man_flag = man.size();
		bool what_the = false;
		while (man.size() != 0) {
			if (fire_flag == 0) {
				while (man_flag != 0) {
					man_flag -= 1;
					pair<int, int> m_pos;	m_pos = man.front();	man.pop();
					for (int m = 0; m < 4; m++) {
						int nr = dr[m] + m_pos.first;
						int nc = dc[m] + m_pos.second;
						if (nr < 0 || nc < 0 || nr >= N || nc >= M)
						{
							cout << time << endl;
 							what_the = true;
							break;
						}
						if (flag[nr][nc] == true)
							continue;
						if (map[nr][nc] == '.') {
							pair<int, int> new_mpos;	new_mpos.first = nr;	new_mpos.second = nc;
							man.push(new_mpos);
							flag[nr][nc] = true;
						}
					}
					if (what_the)
						break;
				}
				if (what_the)
					break;
				time += 1;
				fire_flag = fires.size();
				man_flag = man.size();
			}
			if (fire_flag > 0)
			{
				fire_flag -= 1;
				pair<int, int> f_pos;	f_pos = fires.front();	fires.pop();
				for (int m = 0; m < 4; m++) {
					int nr = dr[m] + f_pos.first;
					int nc = dc[m] + f_pos.second;
					if (nr < 0 || nc < 0 || nr >= N || nc >= M)
						continue;
					if (map[nr][nc] == '.' || map[nr][nc] == '@') {
						map[nr][nc] = '*';
						pair<int, int> new_fpos;	new_fpos.first = nr;	new_fpos.second = nc;
						fires.push(new_fpos);
					}
				}
			}
		}
		if (!what_the)
			cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}