#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int map[100][100];
bool flag[100][100] = { false, };
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };
int main(void) {
	int N, M, buf;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> buf;
			map[i][j] = buf;
		}
	}
	queue<pair<int, int>> barket;
	pair<int, int> s_pos;	s_pos.first = 0;	s_pos.second = 0;
	barket.push(s_pos);
	flag[0][0] = true;
	vector<pair<int, int>> cheese;
	int count = 0;
	int answer = 0;
	do {
		if (cheese.size() != 0) {
			for (int i = 0; i < cheese.size(); i++) {
				barket.push(cheese.at(i));
			}
		}
		cheese.clear();
		while (barket.size() != 0) {
			pair<int, int> pos;	pos = barket.front();	barket.pop();
			for (int m = 0; m < 4; m++) {
				int nr = dr[m] + pos.first;
				int nc = dc[m] + pos.second;
				if (nr < 0 || nc < 0 || nr >= N || nc >= M)
					continue;
				if (flag[nr][nc] == true)
					continue;
				if (map[nr][nc] == 0) {
					flag[nr][nc] = true;
					pair<int, int> new_pos;	new_pos.first = nr;	new_pos.second = nc;
					barket.push(new_pos);
				}
				if (map[nr][nc] == 1) {
					map[nr][nc] = 1;
					flag[nr][nc] = true;
					pair<int, int> new_pos;	new_pos.first = nr;	new_pos.second = nc;
					cheese.push_back(new_pos);
				}
			}
		}
		if (cheese.size() == 0)
			break;
		count = cheese.size();
		answer += 1;
	} while (cheese.size() != 0);
	cout << answer << endl;
	cout << count << endl;
	return 0;
}