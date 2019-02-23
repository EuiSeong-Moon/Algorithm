#include<iostream>
#include<vector>
using namespace std;
int map[14][14] = { 0, };
int dr[] = { 1,1,-1,-1 };
int dc[] = { 1,-1,1,-1 };

void recur(int sz,int N,int& answer,int i_index,int j_index) {
	if (sz == N) {
		answer += 1;
	}
	else {
		int i = i_index + 1;
			for (int j = 0; j < N; j++) {
				if (map[i][j]!=1) {
					vector<pair<int, int>> pos;
					for (int p = 0; p < N; p++) {
						if (map[p][j] == 0)
						{
							map[p][j] = 1;
							pair<int, int> pt;	pt.first = p;	pt.second = j;
							pos.push_back(pt);
						}
					}
					for (int q = 0; q < N; q++) {
						if (map[i][q] == 0)
						{
							map[i][q] = 1;
							pair<int, int> p;	p.first = i;	p.second = q;
							pos.push_back(p);
						}
					}
					int nr = i + dr[0];
					int nc = j + dc[0];
					while (nr<N && nc<N) {
						if (map[nr][nc] == 0) {
							map[nr][nc] = 1;
							pair<int, int> p;	p.first = nr;	p.second = nc;
							pos.push_back(p);
						}
						nr += dr[0];
						nc += dc[0];
					}
					nr = i + dr[1];
					nc = j + dc[1];
					while (nr<N && nc >= 0) {
						if (map[nr][nc] == 0) {
							map[nr][nc] = 1;
							pair<int, int> p;	p.first = nr;	p.second = nc;
							pos.push_back(p);
						}
						nr += dr[1];
						nc += dc[1];
					}
					nr = i + dr[2];
					nc = j + dc[2];
					while (nr >= 0 && nc<N) {
						if (map[nr][nc] == 0) {
							map[nr][nc] = 1;
							pair<int, int> p;	p.first = nr;	p.second = nc;
							pos.push_back(p);
						}
						nr += dr[2];
						nc += dc[2];
					}
					nr = i + dr[3];
					nc = j + dc[3];
					while (nr >= 0 && nc >= 0) {
						if (map[nr][nc] == 0) {
							map[nr][nc] = 1;
							pair<int, int> p;	p.first = nr;	p.second = nc;
							pos.push_back(p);
						}
						nr += dr[3];
						nc += dc[3];
					}
					recur(sz+1,N,answer,i,j);
					for (int k = 0; k < pos.size(); k++)
						map[pos.at(k).first][pos.at(k).second] = 0;
				}
			}
		}
	
}
int main(void) {
	int N,answer=0;
	cin >> N;
	int i = 0;
		for (int j = 0; j < N; j++) {
			if (map[i][j]!=1) {
				vector<pair<int, int>> pos;
				for (int p = 0; p < N; p++) {
					if (map[p][j] == 0)
					{
						map[p][j] = 1;
						pair<int, int> pt;	pt.first = p;	pt.second = j;
						pos.push_back(pt);
					}
				}
				for (int q = 0; q < N; q++) {
					if (map[i][q] == 0)
					{
						map[i][q] = 1;
						pair<int, int> p;	p.first = i;	p.second = q;
						pos.push_back(p);
					}
				}
				int nr = i+dr[0];
				int nc = j+dc[0];
				while (nr<N && nc<N) {
					if (map[nr][nc] == 0) {
						map[nr][nc] = 1;
						pair<int, int> p;	p.first = nr;	p.second = nc;
						pos.push_back(p);
					}
					nr += dr[0];
					nc += dc[0];
				}
				nr = i + dr[1];
				nc = j + dc[1];
				while (nr<N && nc>=0) {
					if (map[nr][nc] == 0) {
						map[nr][nc] = 1;
						pair<int, int> p;	p.first = nr;	p.second = nc;
						pos.push_back(p);
					}
					nr += dr[1];
					nc += dc[1];
				}
				nr = i + dr[2];
				nc = j + dc[2];
				while (nr>=0 && nc<N) {
					if (map[nr][nc] == 0) {
						map[nr][nc] = 1;
						pair<int, int> p;	p.first = nr;	p.second = nc;
						pos.push_back(p);
					}
					nr += dr[2];
					nc += dc[2];
				}
				nr = i + dr[3];
				nc = j + dc[3];
				while (nr >= 0 && nc>=0) {
					if (map[nr][nc] == 0) {
						map[nr][nc] = 1;
						pair<int, int> p;	p.first = nr;	p.second = nc;
						pos.push_back(p);
					}
					nr += dr[3];
					nc += dc[3];
				}
				recur(1,N,answer,i,j);
				for (int k = 0; k < pos.size(); k++)
					map[pos.at(k).first][pos.at(k).second] = 0;
			}
		}
	
	cout << answer << endl;
	return 0;
}