#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int map[100][100];
bool b_flag[100][100] = { false, };
bool p_flag[100][100] = { false, };

class Bom {
public:
	pair<int, int> pos;
	int time;
};
class Success {
public:
	pair<int, int> pos;
	int value;
	int time;
};
bool cmp(Bom b1, Bom b2) {
	if (b1.time < b2.time)
		return true;
	else
		return false;
}
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };
int main(void) {
	int N,M,V,buf,xpos,ypos;
	cin >> N >> M >> V;
	cin >> xpos >> ypos;
	xpos -= 1;	ypos -= 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> buf;
			map[i][j] = buf;
		}
	}
	pair<int, int> answer;
	queue<pair<int, int>> person;
	queue<pair<int, int>> bomb;
	vector<Bom> start_bom;
	answer.first = map[xpos][ypos];	answer.second = 0;
	pair<int, int> s_person;	s_person.first = xpos;	s_person.second = ypos;	person.push(s_person);	p_flag[xpos][ypos] = true;
	for (int i = 0; i < V; i++) {
		cin >> xpos >> ypos >> buf;
		xpos -= 1;	ypos -= 1;
		Bom b;	b.pos.first = xpos;	b.pos.second = ypos;	b.time = buf;
		start_bom.push_back(b);
		map[xpos][ypos] = -1;
	}
	sort(start_bom.begin(), start_bom.end(),cmp);
	int time = 0, b_index = 0;
	while (1)
	{
		
		//vector<Success> sucesss;

		int b_size = bomb.size();
		while (b_size > 0) {
			pair<int, int> pos;	pos = bomb.front();	bomb.pop();
			for (int m = 0; m < 4; m++) {
				int nr = dr[m] + pos.first;
				int nc = dc[m] + pos.second;
				if (nr < 0 || nc < 0 || nr >= N || nc >= M)
					continue;
				if (b_flag[nr][nc])
					continue;
				map[nr][nc] = -1;
				pair<int, int> new_pos;	new_pos.first = nr;	new_pos.second = nc;
				b_flag[nr][nc] = true;
				bomb.push(new_pos);
			}
			b_size -= 1;
		}
		while (b_index < start_bom.size() && start_bom.at(b_index).time == time) {
			bomb.push(start_bom.at(b_index).pos);
			b_flag[start_bom.at(b_index).pos.first][start_bom.at(b_index).pos.second] = true;
			map[start_bom.at(b_index).pos.first][start_bom.at(b_index).pos.second] = -1;
			b_index += 1;
		}

		int p_size = person.size();
		while (p_size > 0) {
			pair<int, int> pos;	pos = person.front();	person.pop();
			if (map[pos.first][pos.second] == -1)
			{
				p_size -= 1;
				continue;
			}
			if (map[pos.first][pos.second] > answer.first) {
				answer.first = map[pos.first][pos.second];
				answer.second = time;
			}
			for (int m = 0; m < 4; m++) {
				int nr = dr[m] + pos.first;
				int nc = dc[m] + pos.second;
				if (nr < 0 || nc < 0 || nr >= N || nc >= M)
					continue;
				if (p_flag[nr][nc])
					continue;
				if (map[nr][nc] != -1) {
					pair<int, int> new_pos;	new_pos.first = nr;	new_pos.second = nc;
					p_flag[nr][nc] = true;
					person.push(new_pos);
				}
			}
			p_size -= 1;
		}

		time += 1;
		if (person.size() == 0)
			break;


	}
	cout <<answer.first<<" "<< answer.second << endl;
	return 0;
}