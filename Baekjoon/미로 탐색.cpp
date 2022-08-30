#include<iostream>
#include<queue>
#include<string>
using namespace std;
class Node {
public:
	pair<int, int> pos;
	int count;
};
int map[100][100];
bool flag[100][100] = { false, };
int dr[] = { 1,-1,0,0 };
int dc[]={ 0,0,1,-1 };
int main(void) {
	int N, M;
	string buf;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
			cin >> buf;
			for (int j = 0; j < M; j++) {
				map[i][j] = buf.at(j)-'0';
			}
		
	}
	pair<int, int> s_pos(0, 0);
	Node s_node;	s_node.pos = s_pos;	s_node.count=0;
	queue<Node> barket;
	barket.push(s_node);
	flag[0][0] = true;

	while (barket.size() != 0) {
		Node node = barket.front();
		barket.pop();
		node.count += 1;
		if (node.pos.first == N-1 && node.pos.second == M-1)
		{
			cout << node.count << endl;
			break;
		}
		for (int m = 0; m < 4; m++) {
			int nr = dr[m] + node.pos.first;
			int nc = dc[m] + node.pos.second;
			if (nr < 0 || nc < 0 || nr >= N || nc >= M)
				continue;
			if (flag[nr][nc] == true)
				continue;
			if (map[nr][nc] == 1) {
				Node new_node;	new_node.pos.first = nr;	new_node.pos.second = nc;	new_node.count = node.count;
				flag[nr][nc] = true;
				barket.push(new_node);
			}
		}
	}
	return 0;
}