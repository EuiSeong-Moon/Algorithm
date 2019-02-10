#include<iostream>
#include<queue>
#include<string>
using namespace std;
class Node {
public:
	pair<int, int> pos;
	int attack;
	int count;
};
int map[1000][1000];
int flag[1000][1000];
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };

int main(void)
{
	int N, M, K;
	string buf;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> buf;
		for (int j = 0; j < M; j++) {
			map[i][j] = buf.at(j) - '0';
			flag[i][j] = -1;
		}
	}
	queue<Node> barket;
	Node s_node;	s_node.pos.first = 0;	s_node.pos.second = 0;	s_node.count = 0;	s_node.attack = K;
	barket.push(s_node);
	flag[0][0] = K;
	while (barket.size() != 0) {
		Node node;	node = barket.front();	barket.pop();
		node.count += 1;
		if (node.pos.first == N - 1 && node.pos.second == M - 1)
		{
			cout << node.count << endl;
			return 0;
		}
		for (int m = 0; m < 4; m++) {
			int nr = dr[m] + node.pos.first;
			int nc = dc[m] + node.pos.second;
			if (nr < 0 || nc < 0 || nr >= N || nc >= M)
				continue;
			if (flag[nr][nc] >= node.attack)
				continue;
			if (map[nr][nc] == 0) {
				Node new_node;	new_node.pos.first = nr;	new_node.pos.second = nc;	new_node.count = node.count;	new_node.attack = node.attack;
				flag[nr][nc] = new_node.attack;
				barket.push(new_node);
			}
			else if (map[nr][nc] == 1 && node.attack>0) {
				Node new_node;	new_node.pos.first = nr;	new_node.pos.second = nc;	new_node.count = node.count;	new_node.attack = node.attack - 1;
				flag[nr][nc] = new_node.attack;
				barket.push(new_node);
			}
		}
	}
	cout << "-1" << endl;
	return 0;
}