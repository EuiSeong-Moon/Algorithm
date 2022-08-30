#include<iostream>
#include<queue>
#include<string>
using namespace std;

char map[50][50];
int flag[50][50];
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };
class Node {
public:
	pair<int, int> pos;
	int count;
};
int main(void) {
	int N;
	string str;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			flag[i][j] = 2500;
			map[i][j] = str.at(j);
		}
	}
	flag[0][0] = 0;
	Node s_node;	s_node.pos.first = 0;	s_node.pos.second = 0;	s_node.count = 0;
	queue<Node> barket;	barket.push(s_node);
	int answer = 2500;
	while (barket.size() != 0) {
		Node node;	node = barket.front();	barket.pop();
		if (node.pos.first == N - 1 && node.pos.second == N - 1)
		{
			if (answer > node.count)
				answer = node.count;
		}
		for (int m = 0; m < 4; m++) {
			int nr = dr[m] + node.pos.first;
			int nc = dc[m] + node.pos.second;
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				continue;
			if (flag[nr][nc] <= node.count)
				continue;
			if (map[nr][nc] == '1') {
				Node new_node;	new_node.pos.first = nr;	new_node.pos.second = nc;	new_node.count = node.count;
				barket.push(new_node);
				flag[nr][nc] = node.count;
			}
			else {
				Node new_node;	new_node.pos.first = nr;	new_node.pos.second = nc;	new_node.count = node.count+1;
				barket.push(new_node);
				flag[nr][nc] = node.count+1;
			}
		}
	}
	cout << answer << endl;
	return 0;
}