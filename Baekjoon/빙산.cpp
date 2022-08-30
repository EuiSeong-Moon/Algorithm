#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int map[300][300];
int flag[300][300] = { 0, };
int dr[] = { 1,-1,0,0, };
int dc[] = { 0,0,1,-1 };
int main(void) {
	int N, M,buf;
	cin >> N >> M;
	vector<pair<int, int>> ice;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> buf;
			map[i][j] = buf;
			if (buf != 0) {
				pair<int, int> p;	p.first = i;	p.second = j;
				ice.push_back(p);
			}
		}
	}
	int time = 0;
	while (ice.size() != 0) {
		int flaged = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (flag[i][j] != 0)
					continue;
				if (map[i][j] != 0) {
					if (flaged >= 2)
					{
						cout << time << endl;
						return 0;
					}
					queue<pair<int, int>> barket;	pair<int, int> p;	p.first = i;	p.second = j;
					barket.push(p);
					flag[i][j] = flaged;
					while (barket.size() != 0) {
						pair<int, int> pos = barket.front();
						barket.pop();
						for (int m = 0; m < 4; m++) {
							int nr = dr[m] + pos.first;	int nc = dc[m] + pos.second;
							if (nr < 0 || nc < 0 || nr >= N || nc >= M)
								continue;
							if (flag[nr][nc] != 0)
								continue;
							if (map[nr][nc] != 0)
							{
								flag[nr][nc] = flaged;
								pair<int, int> new_pos;	new_pos.first = nr;	new_pos.second = nc;
								barket.push(new_pos);
							}

						}
					}
					flaged += 1;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				flag[i][j] = 0;
		}
		vector<pair<int, int>> erase_buf;
		for (int i = 0; i < ice.size(); i++) {
			int count = 0;
			for (int m = 0; m < 4; m++) {
				int nr = dr[m] + ice.at(i).first;
				int nc = dc[m] + ice.at(i).second;
				if (nr < 0 || nc < 0 || nr >= N || nc >= M)
					continue;
				if (map[nr][nc] == 0)
					count += 1;
			}
			if (map[ice.at(i).first][ice.at(i).second] <= count)
			{
				pair<int, int> p;	p.first = ice.at(i).first;	p.second=ice.at(i).second;
				erase_buf.push_back(p);
				ice.erase(ice.begin() + i);
				i -= 1;
			}
			else
				map[ice.at(i).first][ice.at(i).second] -= count;
		}
		for (int i = 0; i < erase_buf.size(); i++)
			map[erase_buf.at(i).first][erase_buf.at(i).second] = 0;
		time += 1;
	}
	cout << "0" << endl;
	return 0;
}