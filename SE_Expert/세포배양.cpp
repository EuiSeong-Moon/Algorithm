#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int map[450][450];
class Cell {
public:
	pair<int, int> pos;
	int current;
	bool flag = false;
	int life;
};
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };
int main(void) {
	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		for (int i = 0; i < 450; i++) {
			for (int j = 0; j < 450; j++)
				map[i][j] = 0;
		}
		vector<Cell> cells;
		int N, M,K,buf;
		cin >> N >> M >> K;
		for(int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> buf;
		
				if (buf != 0) {
					map[i + 200][j + 200] = 20;
					Cell c;	c.current = buf;	c.life = buf;	c.pos.first = i + 200;	c.pos.second=j + 200;
					cells.push_back(c);
				}
			}
		}
		int time = 0;
		int size = cells.size();
		while (time != K) {
			for (int i = 0; i < size; i++) {
				if (cells.at(i).life == 0)
					continue;
				if (cells.at(i).flag == true) {
					if (cells.at(i).current == cells.at(i).life) {
						for (int m = 0; m < 4; m++) {
							int nr = dr[m] + cells.at(i).pos.first;
							int nc = dc[m] + cells.at(i).pos.second;
							if (map[nr][nc] > 10)
								continue;
							if (map[nr][nc] == 0) {
								Cell new_c;	new_c.pos.first = nr;	new_c.pos.second = nc;	new_c.life = cells.at(i).life;	new_c.current = cells.at(i).life;
								map[nr][nc] = new_c.life;
								cells.push_back(new_c);
							}
							else if (map[nr][nc] < cells.at(i).life) {
								Cell new_c;	new_c.pos.first = nr;	new_c.pos.second = nc;	new_c.life = cells.at(i).life;	new_c.current = cells.at(i).life;
								map[nr][nc] = new_c.life;
								cells.push_back(new_c);
								for (int k = cells.size() - 1; k >= 0; k--) {
									if (cells.at(k).pos == new_c.pos) {
										cells.at(k).life = 0;
										break;
									}
								}
							}
						}
					}
					cells.at(i).current -= 1;
					if (cells.at(i).current == 0) {
						cells.at(i).life = 0;
					}
				}
				else {
					if (cells.at(i).life == cells.at(i).current)
						map[cells.at(i).pos.first][cells.at(i).pos.second] = 20;
					cells.at(i).current -= 1;
					if (cells.at(i).current == 0) {
						cells.at(i).flag = true;
						cells.at(i).current = cells.at(i).life;
					}
				}
			}
			time += 1;
			size = cells.size();
		}
		if (time == 0)
			cout <<"#"<<test+1<<" "<< cells.size() << endl;
		else {
			int count = 0;
			for (int k = 0; k < cells.size(); k++) {
				if (cells.at(k).life == 0)
					count += 1;
			}
			cout <<"#"<<test+1<<" "<< cells.size() - count << endl;
		}
	}
	return 0;
}