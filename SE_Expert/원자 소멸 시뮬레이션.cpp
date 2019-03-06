#include<iostream>
#include<vector>

using namespace std;

int map[2001][2001] = { 0, };

class Node {
public:
	pair<int, int> pos;
	int power;
	int direct;
};
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
int main(void) {
	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int N,buf;
		vector<Node> nodes;
		cin >> N;
		for (int i = 0; i < N; i++) {
			Node n;
			pair<int, int> pos;
			cin >> buf;	pos.second = 1000 + buf;
			cin >> buf;	pos.first = 1000 - buf;
			cin >> buf;	n.direct = buf;
			cin >> buf;	n.power = buf;
			map[pos.first][pos.second] = 1;
			n.pos = pos;
			nodes.push_back(n);
		}
		int finish = 0;
		long long answer = 0;
		int time = 0;
		while (finish != nodes.size())
		{
			time += 1;
			if (time == 500) {
				time = 30;
			}
			finish = 0;
			vector<pair<int, int>> bomb;
			for (int i = 0; i < nodes.size(); i++) {
				if (nodes.at(i).power == 0)
				{
					finish += 1;
					continue;
				}
				int nr = dr[nodes.at(i).direct] + nodes.at(i).pos.first;
				int nc = dc[nodes.at(i).direct] + nodes.at(i).pos.second;
				if (nr < 0 || nc < 0 || nr >= 2001 || nc >= 2001)
				{
					nodes.at(i).power = 0;
					map[nodes.at(i).pos.first][nodes.at(i).pos.second] = 0;
					continue;
				}
				int mid_bomb = 0;
				if (map[nr][nc] != 0) {
					//중간에서 충돌
					for (int k = 0; k < nodes.size(); k++) {
						if (nodes.at(k).power == 0)		//죽은건 꼭 체크해줘야함 이거땜시 테케하나 틀렸었음.
							continue;
						if (nodes.at(k).pos.first == nr && nodes.at(k).pos.second == nc) {
							if (k > i) {
								if ((nodes.at(k).direct == 0 && nodes.at(i).direct == 1) || (nodes.at(k).direct == 1 && nodes.at(i).direct == 0) || (nodes.at(k).direct == 2 && nodes.at(i).direct == 3) || (nodes.at(k).direct == 3 && nodes.at(i).direct == 2)) {
									map[nr][nc] -= 1;
									map[nodes.at(i).pos.first][nodes.at(i).pos.second] -= 1;
									answer += nodes.at(k).power;
									answer += nodes.at(i).power;
									nodes.at(i).power = 0;
									nodes.at(k).power = 0;
									mid_bomb = 1;
								}
							}

						}
					}
				}
				if (mid_bomb == 0) {
					map[nr][nc] += 1;
					map[nodes.at(i).pos.first][nodes.at(i).pos.second] -= 1;
					nodes.at(i).pos.first = nr;	nodes.at(i).pos.second = nc;
					if (map[nr][nc] >= 2) {
						int g = 0;
						for (int k = 0; k < bomb.size(); k++) {
							if (bomb.at(k).first == nr && bomb.at(k).second == nc)
							{
								g = 1;
							}
						}
						if (g == 0) {
							pair<int, int> n_p;	n_p.first = nr;	n_p.second = nc;
							bomb.push_back(n_p);
						}
					}
				}
			}
			for (int p = 0; p < bomb.size(); p++) {
				if (map[bomb.at(p).first][bomb.at(p).second] >= 2) {
					map[bomb.at(p).first][bomb.at(p).second] = 0;
					for (int k = 0; k < nodes.size(); k++) {
						if (nodes.at(k).power == 0)
							continue;
						if (nodes.at(k).pos.first == bomb.at(p).first && nodes.at(k).pos.second == bomb.at(p).second) {
							answer += nodes.at(k).power;
							nodes.at(k).power = 0;
						}
					}
				}
			}
			bomb.clear();
			//bomb pair 지우기
		}
		cout << "#" << test + 1 << " " << answer << endl;
	}
	return 0;
}