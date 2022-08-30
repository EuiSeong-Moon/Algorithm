#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int map[50][50];
bool flag[50][50];
int dr[] = { -2,-1,1,2,2,1,-1,-2 };
int dc[] = { 1,2,2,1,-1,-2,-2,-1 };
class Area {
public:
	pair<int, int> pos;
	int count;
};
int main(void){
	int N, M;
	char buf;
	vector<pair<int, int>> hole;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> buf;
			if (isdigit(buf)) {
				int int_buf = buf - '0';
				map[i][j] = int_buf;
				pair<int, int> p;	p.first = i;	p.second = j;
				hole.push_back(p);
			}
			else {
				map[i][j] = 0;
			}
		}
	}
	long long answer = 10000000;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
		
			long long count = 0;
			for (int k = 0; k < hole.size(); k++) {
				for (int p = 0; p < N; p++) {
					for (int q = 0; q < M; q++)
						flag[p][q] = false;
				}
				flag[hole.at(k).first][hole.at(k).second] = true;
				bool destination = false;
				Area area;
				area.pos.first = hole.at(k).first;	area.pos.second = hole.at(k).second;	area.count = 0;
				queue<Area> barket;	barket.push(area);
				while (barket.size() != 0) {
					Area a;	a = barket.front();	barket.pop();
					if (a.pos.first == i && a.pos.second == j) {
						if(a.count % map[hole.at(k).first][hole.at(k).second]==0){
							count += a.count / map[hole.at(k).first][hole.at(k).second];
						}
						else {
							count += a.count / map[hole.at(k).first][hole.at(k).second]+1;
						}
						destination = true;
						break;
					}
					for (int m = 0; m < 8; m++) {
						int nr = dr[m] + a.pos.first;
						int nc = dc[m] + a.pos.second;
						if (nr < 0 || nc < 0 || nr >= N || nc >= M)
							continue;
						if (flag[nr][nc])
							continue;
						flag[nr][nc] = true;
						Area new_a;	new_a.pos.first = nr;	new_a.pos.second = nc;	new_a.count = a.count + 1;
						barket.push(new_a);
					}
				}
				if (destination == false)
					break;
				if (k == hole.size() - 1) {
					if (answer > count)
						answer = count;
				}
			}
		}
	}
	if (answer == 10000000)
		cout << "-1" << endl;
	else
		cout << answer << endl;
	return 0;
}