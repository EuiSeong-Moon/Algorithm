#include<iostream>
#include<queue>

using namespace std;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int map[1000][1000] = { 0, };
int flag[1000][1000] = { 0, };
int main(void)
{
	int M, N, buf;
	cin >> M >> N;
	int max, current = 0;
	queue<pair<int, int>> barket;
	max = N*M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> buf;
			if (buf == -1) {
				max -= 1;
				map[i][j] = -1;
			}
			else if (buf == 1) {
				pair<int, int> buf_pair;
				buf_pair.first = i;	buf_pair.second = j;
				barket.push(buf_pair);
				current += 1;
				flag[i][j] = 1;
				map[i][j] = 1;
			}
		}
	}
	if (current == max)
	{
		cout << 0 << endl;
		return 0;
	}
	int day = 1;
	int one_day = barket.size();
	while (barket.size() != 0) {
		pair<int, int> p_buf;
		p_buf = barket.front();

		barket.pop();
		for (int x = 0; x < 4; x++) {
			int nr = p_buf.first + dr[x];
			int nc = p_buf.second + dc[x];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M)
				continue;
			if (flag[nr][nc] == 1)
				continue;
			if (map[nr][nc] == 0) {
				map[nr][nc] = 1;
				current += 1;
				flag[nr][nc] = 1;
				pair<int, int> new_pair;	new_pair.first = nr;	new_pair.second = nc;
				barket.push(new_pair);
			}
		}
		one_day -= 1;
		if (max == current)
			break;
		if (one_day == 0) {
			day++;
			one_day = barket.size();
		}
	}
	if (current != max)
		cout << -1 << endl;
	else
		cout << day << endl;
	return 0;
}