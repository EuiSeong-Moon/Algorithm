#include<iostream>
#include<queue>

using namespace std;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };
int map[100][100];
bool flag[100][100] = { false, };
class Node {
public:
	pair<int, int> pos;
	int count;
};
int main(void) {
	int N,buf,answer=1000000;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		{
			cin >> buf;
			map[i][j] = buf;
		}
	}
	//¼¶ ±¸ºÐÁþ±â
	int pt = 11;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && flag[i][j]==false) {
				queue<pair<int, int>> barket;	pair<int, int> p;	p.first = i;	p.second = j;
				barket.push(p);
				flag[i][j] = true;
				map[i][j] = pt;
				while (barket.size() != 0) {
					pair<int, int> c_p;	c_p = barket.front();	barket.pop();
					for (int m = 0; m < 4; m++) {
						int nr = dr[m] + c_p.first;
						int nc = dc[m] + c_p.second;
						if (nr < 0 || nc < 0 || nr >= N || nc >= N)
							continue;
						if (flag[nr][nc])
							continue;
						if (map[nr][nc] == 1) {
							pair<int, int> new_p;	new_p.first = nr;	new_p.second = nc;	map[nr][nc] = pt;
							flag[nr][nc] = true;
							barket.push(new_p);
						}
					}
				}
				pt += 1;
			}
		}
	}
	for (int p = 0; p < N; p++) {
		for (int q = 0; q < N; q++) {
			flag[p][q] = false;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] >= 11) {
				for (int p = 0; p < N; p++) {
					for (int q = 0; q < N; q++) {
						flag[p][q] = false;
					}
				}
				int current_pt = map[i][j];
				queue<Node> barket; pair<int, int> s_p;	s_p.first = i;	s_p.second = j;
				Node ss;	ss.pos = s_p;	ss.count = 0;
				flag[i][j] = true;
				barket.push(ss);
				bool while_flag = true;
				while (barket.size() != 0 && while_flag == true) {
					Node node;	node = barket.front();	barket.pop();
					for (int m = 0; m < 4; m++) {
						int nr = dr[m] + node.pos.first;
						int nc = dc[m] + node.pos.second;
						if (nr < 0 || nc < 0 || nr >= N || nc >= N)
							continue;
						if (flag[nr][nc])
							continue;
						if (map[nr][nc] == 0) {
							Node new_node;	new_node.pos.first = nr;	new_node.pos.second = nc;	new_node.count = node.count + 1;
							flag[nr][nc] = true;
							barket.push(new_node);
						}
						else if (map[nr][nc] != current_pt) {
							if (answer > node.count) {
								answer = node.count;
							}
							while_flag = false;
							break;
						}
					}
				}
			}
		}
	}
	cout << answer << endl;
	return 0;
}