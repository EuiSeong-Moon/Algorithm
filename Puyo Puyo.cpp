#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char map[12][6];
bool flag[12][6] = { false, };
int dr[] = { 1,-1,0,0, };
int dc[] = { 0,0,1,-1 };
void BFS(pair<int,int> pos,vector<pair<int,int>>& corrects) {
	queue<pair<int, int>> barket;
	vector<pair<int, int>> f_buf;
	f_buf.push_back(pos);
	barket.push(pos);
	flag[pos.first][pos.second] = true;
	int count = 1;
	
	while (barket.size() != 0) {
		pair<int, int> buf;
		buf = barket.front();
		barket.pop();
		for (int m = 0; m < 4; m++) {
			int nr = dr[m] + buf.first;
			int nc = dc[m] + buf.second;
			if (nr < 0 || nc < 0 || nr>11 || nc>5)
				continue;
			if (flag[nr][nc] == true)
				continue;
			if (map[buf.first][buf.second]!='.' && map[buf.first][buf.second] == map[nr][nc]) {
				count += 1;
				flag[nr][nc] = true;

				pair<int, int> new_pair;	new_pair.first = nr;	new_pair.second = nc;
				f_buf.push_back(new_pair);
				barket.push(new_pair);
			}
		}
	}
	if (count >= 4) {
		for (int k = 0; k < f_buf.size(); k++) {
			corrects.push_back(f_buf.at(k));
		}
	}
}
int main(void) {
	char buf;
	int answer = 0;
	int game_over = 0;
	vector<pair<int, int>> corrects;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> buf;
			map[i][j] = buf;
		}
	}

	while (game_over == 0) {
		corrects.clear();
		game_over = 1;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				pair<int, int> pos;
				pos.first = i;	pos.second = j;
				BFS(pos,corrects);
			}
		}
		for (int k = 0; k < corrects.size(); k++) {
			map[corrects.at(k).first][corrects.at(k).second] = '.';
			game_over = 0;
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++) {
				flag[i][j] = false;
			}
		}
		for (int j = 0; j < 6; j++) {
			for (int i = 11; i >= 0; i--) {
				int k = 1;
				if (map[i][j] == '.') {
					while (i - k >= 0 && map[i - k][j] == '.') {
						k++;
					}
					if (i - k >= 0) {
						map[i][j] = map[i - k][j];
						map[i - k][j] = '.';
					}
				}
			}
		}
		if (game_over == 0)
			answer += 1;
	}
	cout << answer << endl;
	return 0;
}