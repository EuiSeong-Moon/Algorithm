#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;
// 좌우방향 flag에서 true이고 flag전역변수에서 3차원[0] 그리고 아래 위 우측 좌측 순으로 이동가능한지 체크하고 이동하고있다. continue등 분기문 사이사이에서 잔실수가 많이남.
char map[50][50];
bool flag[50][50][2] = { false, };
int dr[] = {2,-2,0,-1,1,0,-1,1 };
int dc[] = { 0,0,1,1,1,-1,-1,-1 };
int dr2[] = { 1,1,1,-1,-1,-1,0,0 };
int dc2[] = { 0,1,-1,0,1,-1,2,-2 };
class Wood {
public:
	pair<int, int> center;
	int count;
	bool flag;
};
int main(void) {
	int N;
	int t = 0;	int pp = 0;
	Wood s_w;
	string str;
	vector<pair<int, int>> finish;
	bool finish_f;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (t == 0 && str.at(j) == 'B' && (j + 1 >= str.size() || str.at(j + 1) != 'B'))
			{
				t = 3;
				s_w.flag = false;
			}
			if (str.at(j) == 'B')
			{
				if (t != 3)
					t = 1;
				pp += 1;
				if (pp == 2)
				{
					s_w.center.first = i;	s_w.center.second = j;
				}
			}
			if (str.at(j) == 'E')
			{
				pair<int, int> fpos;	fpos.first = i;	fpos.second = j;
				finish.push_back(fpos);
			}
			map[i][j] = str.at(j);
		//	flag[i][j] = 25000;
		}
	}
	if (finish.at(0).first == finish.at(1).first) {
		finish_f = true;
	}
	else {
		finish_f = false;
	}
	if (t == 1)
		s_w.flag = true;
	s_w.count = 0;
	queue<Wood> barket;	barket.push(s_w);
	
	if(s_w.flag)
		flag[s_w.center.first][s_w.center.second][0]= true;
	else
		flag[s_w.center.first][s_w.center.second][1] = true;

	
	while (barket.size() != 0) {
		Wood wd;	wd = barket.front();	barket.pop();
		
		if (wd.center.first == finish.at(1).first && wd.center.second == finish.at(1).second && wd.flag == finish_f) {
			cout << wd.count << endl;
			return 0;
		}
		bool circui = true;
		for (int m = 0; m < 4; m++) {
			if (wd.flag) {
				if (m == 0 || m == 1) {
					bool possible = true;
					for (int p = 0; p < 3; p++) {
						int pr = dr2[p + m * 3] + wd.center.first;
						int pc = dc2[p + m * 3] + wd.center.second;
						if (pr < 0 || pc < 0 || pr >= N || pc >= N || map[pr][pc] == '1') {
							possible = false;
							circui = false;
							break;
						}
					}
					if (possible) {
						if (m == 0 && flag[wd.center.first+1][wd.center.second][0]==false) {
							Wood new_wd;	new_wd.center.first = wd.center.first + 1;	new_wd.center.second = wd.center.second;	new_wd.count = wd.count + 1;	new_wd.flag = wd.flag;
							barket.push(new_wd);
							flag[new_wd.center.first][new_wd.center.second][0] = true;
						}
						else if(m==1 && flag[wd.center.first - 1][wd.center.second][0]==false) {
							Wood new_wd;	new_wd.center.first = wd.center.first - 1;	new_wd.center.second = wd.center.second;	new_wd.count = wd.count + 1;	new_wd.flag = wd.flag;
							barket.push(new_wd);
							flag[new_wd.center.first][new_wd.center.second][0] = true;
						}
					}
				}
				else if(m==2) {
					int nr = dr2[6] + wd.center.first;
					int nc = dc2[6] + wd.center.second;
					if (nr < 0 || nc < 0 || nr >= N || nc >= N || flag[wd.center.first][wd.center.second+1][0]==true || map[nr][nc]=='1')
						continue;
					Wood new_wd;	new_wd.center.first = wd.center.first;	new_wd.center.second = wd.center.second+1;	new_wd.count = wd.count + 1;	new_wd.flag = wd.flag;
					barket.push(new_wd);
					flag[new_wd.center.first][new_wd.center.second][0] = true;

				}
				else {
					int nr = dr2[7] + wd.center.first;
					int nc = dc2[7] + wd.center.second;
					if (nr < 0 || nc < 0 || nr >= N || nc >= N || flag[wd.center.first][wd.center.second - 1][0] == true || map[nr][nc] == '1')
					{
					}
					else {
						Wood new_wd;	new_wd.center.first = wd.center.first;	new_wd.center.second = wd.center.second - 1;	new_wd.count = wd.count + 1;	new_wd.flag = wd.flag;
						barket.push(new_wd);
						flag[new_wd.center.first][new_wd.center.second][0] = true;
					}
					if (circui && flag[wd.center.first][wd.center.second][1]==false) {
						flag[wd.center.first][wd.center.second][1] = true;
						Wood new_wd;	new_wd.center.first = wd.center.first;	new_wd.center.second = wd.center.second;	new_wd.count = wd.count + 1;	new_wd.flag = false;
						barket.push(new_wd);
					}
				}
			}
			else {
				if (m == 2 || m == 3) {
					bool possible = true;
					for (int p = 0; p < 3; p++) {
						int pr = dr[p + (m-2) * 3+2] + wd.center.first;
						int pc = dc[p + (m-2) * 3+2] + wd.center.second;
						if (pr < 0 || pc < 0 || pr >= N || pc >= N || map[pr][pc] == '1') {
							possible = false;
							circui = false;
							break;
						}
					}
					if (possible) {
						if (m == 2 && flag[wd.center.first][wd.center.second+1][1]==false) {
							Wood new_wd;	new_wd.center.first = wd.center.first;	new_wd.center.second = wd.center.second+1;	new_wd.count = wd.count + 1;	new_wd.flag = wd.flag;
							barket.push(new_wd);
							flag[new_wd.center.first][new_wd.center.second][1] = true;
						}
						else if (m==3 && flag[wd.center.first ][wd.center.second-1][1]==false) {
							Wood new_wd;	new_wd.center.first = wd.center.first;  new_wd.center.second = wd.center.second-1;	new_wd.count = wd.count + 1;	new_wd.flag = wd.flag;
							barket.push(new_wd);
							flag[new_wd.center.first][new_wd.center.second][1] = true;
						}
						if (m==3 && circui && flag[wd.center.first][wd.center.second][0]==false) {
							flag[wd.center.first][wd.center.second][0] = true;
							Wood new_wd;	new_wd.center.first = wd.center.first;	new_wd.center.second = wd.center.second;	new_wd.count = wd.count + 1;	new_wd.flag = true;
							barket.push(new_wd);
						}
					}
				}
				else if (m == 0) {
					int nr = dr[0] + wd.center.first;
					int nc = dc[0] + wd.center.second;
					if (nr < 0 || nc < 0 || nr >= N || nc >= N || flag[wd.center.first+1][wd.center.second ][1]==true || map[nr][nc]=='1')
						continue;
					Wood new_wd;	new_wd.center.first = wd.center.first+1;	new_wd.center.second = wd.center.second ;	new_wd.count = wd.count + 1;	new_wd.flag = wd.flag;
					barket.push(new_wd);
					flag[new_wd.center.first][new_wd.center.second][1] = true;

				}
				else {
					int nr = dr[1] + wd.center.first;
					int nc = dc[1] + wd.center.second;
					if (nr < 0 || nc < 0 || nr >= N || nc >= N || flag[wd.center.first-1][wd.center.second ][1]==true || map[nr][nc]=='1')
						continue;
					Wood new_wd;	new_wd.center.first = wd.center.first - 1;	new_wd.center.second = wd.center.second;	new_wd.count = wd.count + 1;	new_wd.flag = wd.flag;
					barket.push(new_wd);
					flag[new_wd.center.first][new_wd.center.second][1] = true;
					
				}
			}
		}

	
	}
	cout << "0" << endl;
	return 0;
}