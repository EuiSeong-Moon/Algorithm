#include<iostream>
#include<vector>

using namespace std;
class Node {
public:
	pair<int, int> pos;
	int camera;
	int size;
};
int map[8][8];

int check(int N,int M,vector<Node>& nodes,vector<int>& types) {
	int buf_map[8][8];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			buf_map[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < nodes.size(); i++) {
		int nr = nodes.at(i).pos.first;
		int nc = nodes.at(i).pos.second;
		switch (nodes.at(i).camera) {
			//감시망 체크
		case 1:
			switch (types.at(i)) {
			case 1:
				nc += 1;	//우측
				while (nc < M && buf_map[nr][nc] != 6)
				{
					buf_map[nr][nc] = 10;
					nc += 1;
				}
				break;
			case 2:
				nr += 1;	//아래
				while (nr < N && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nr += 1;
				}
				break;
			case 3:
				nc -= 1;	//좌측
				while (nc >= 0 && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nc -= 1;
				}
				break;
			case 4:
				nr -= 1;	//위
				while (nr >= 0 && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nr -= 1;
				}
				break;
			}
			break;
		case 2:
			switch (types.at(i)) {
			case 1:
				nc += 1;	//우측
				while (nc < M && buf_map[nr][nc] != 6)
				{
					buf_map[nr][nc] = 10;
					nc += 1;
				}
				nc = nodes.at(i).pos.second;
				
				nc -= 1;	//좌측
				while (nc >= 0 && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nc -= 1;
				}
				break;
			case 2:
				nr -= 1;	//위
				while (nr >= 0 && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nr -= 1;
				}
				nr = nodes.at(i).pos.first;
				nr += 1;	//아래
				while (nr < N && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nr += 1;
				}
				break;
			}
			break;
		case 3:
			switch (types.at(i)) {
			case 1:
				nr -= 1;	//위
				while (nr >= 0 && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nr -= 1;
				}
				nr = nodes.at(i).pos.first;
				nc += 1;	//우측
				while (nc < M && buf_map[nr][nc] != 6)
				{
					buf_map[nr][nc] = 10;
					nc += 1;
				}
				break;
			case 2:
				nc += 1;	//우측
				while (nc < M && buf_map[nr][nc] != 6)
				{
					buf_map[nr][nc] = 10;
					nc += 1;
				}
				nc = nodes.at(i).pos.second;
				nr += 1;	//아래
				while (nr < N && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nr += 1;
				}
				break;
			case 3:
				nr += 1;	//아래
				while (nr < N && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nr += 1;
				}
				nr = nodes.at(i).pos.first;
				nc -= 1;	//좌측
				while (nc >= 0 && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nc -= 1;
				}
				break;
			case 4:
				nr -= 1;	//위
				while (nr >= 0 && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nr -= 1;
				}
				nr = nodes.at(i).pos.first;
				nc -= 1;	//좌측
				while (nc >= 0 && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nc -= 1;
				}
				break;
			}
			break;
		case 4:
			switch (types.at(i)) {
			case 1:
				nr -= 1;	//위
				while (nr >= 0 && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nr -= 1;
				}
				nr = nodes.at(i).pos.first;
				nc += 1;	//우측
				while (nc < M && buf_map[nr][nc] != 6)
				{
					buf_map[nr][nc] = 10;
					nc += 1;
				}
				nc = nodes.at(i).pos.second;
				nc -= 1;	//좌측
				while (nc >= 0 && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nc -= 1;
				}
				break;
			case 2:
				nr -= 1;	//위
				while (nr >= 0 && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nr -= 1;
				}
				nr = nodes.at(i).pos.first;
				nc += 1;	//우측
				while (nc < M && buf_map[nr][nc] != 6)
				{
					buf_map[nr][nc] = 10;
					nc += 1;
				}
				nc = nodes.at(i).pos.second;
				nr += 1;	//아래
				while (nr < N && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nr += 1;
				}
				break;
			case 3:
				nc += 1;	//우측
				while (nc < M && buf_map[nr][nc] != 6)
				{
					buf_map[nr][nc] = 10;
					nc += 1;
				}
				nc = nodes.at(i).pos.second;
				nr += 1;	//아래
				while (nr < N && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nr += 1;
				}
				nr = nodes.at(i).pos.first;
				nc -= 1;	//좌측
				while (nc >= 0 && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nc -= 1;
				}
				break;
			case 4:
				nr -= 1;	//위
				while (nr >= 0 && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nr -= 1;
				}
				nr = nodes.at(i).pos.first;
				nr += 1;	//아래
				while (nr < N && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nr += 1;
				}
				nr = nodes.at(i).pos.first;
				nc -= 1;	//좌측
				while (nc >= 0 && buf_map[nr][nc] != 6) {
					buf_map[nr][nc] = 10;
					nc -= 1;
				}
				break;
			}
			break;
		case 5:
			nc += 1;	//우측
			while (nc < M && buf_map[nr][nc] != 6)
			{
				buf_map[nr][nc] = 10;
				nc += 1;
			}
			nc = nodes.at(i).pos.second;
			nr -= 1;	//위
			while (nr >= 0 && buf_map[nr][nc] != 6) {
				buf_map[nr][nc] = 10;
				nr -= 1;
			}
			nr = nodes.at(i).pos.first;
			nr += 1;	//아래
			while (nr < N && buf_map[nr][nc] != 6) {
				buf_map[nr][nc] = 10;
				nr += 1;
			}
			nr = nodes.at(i).pos.first;
			nc -= 1;	//좌측
			while (nc >= 0 && buf_map[nr][nc] != 6) {
				buf_map[nr][nc] = 10;
				nc -= 1;
			}
			break;
		}
	}
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (buf_map[i][j] == 0)
				count += 1;
		}
	}
	return count;
}
void recur(int sz, vector<Node>& nodes, vector<int>& types,int& answer,int N,int M) {
	if (sz == nodes.size())
	{
		int current = check(N,M,nodes,types);
		if (answer > current)
			answer = current;
	}
	else {
		for (int i = 1; i<=nodes.at(sz).size; i++) {
			types.push_back(i);
			recur(sz + 1, nodes, types,answer,N,M);
			types.pop_back();
		}
	}
}
int main(void) {
	int N, M,buf;
	vector<Node> nodes;
	vector<int> types;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> buf;
			Node p;
			switch (buf) {
			case 1:
				p.pos.first = i;	p.pos.second = j;	p.camera = 1;	p.size = 4;
				nodes.push_back(p);
				break;
			case 2:
				
				p.pos.first = i;	p.pos.second = j;	p.camera = 2;	p.size = 2;
				nodes.push_back(p);
				break;
			case 3:
				p.pos.first = i;	p.pos.second = j;	p.camera = 3;	p.size = 4;
				nodes.push_back(p);
				break;
			case 4:
				p.pos.first = i;	p.pos.second = j;	p.camera = 4;	p.size = 4;
				nodes.push_back(p);
				break;
			case 5:
				p.pos.first = i;	p.pos.second = j;	p.camera = 5;	p.size = 1;
				nodes.push_back(p);
				break;
			}
			map[i][j] = buf;
		}
	}
	int answer = 1000;
	if (nodes.size() > 0) {
		for (int i = 1; i <= nodes.at(0).size; i++) {
			types.push_back(i);
			recur(1,nodes,types,answer,N,M);
			types.pop_back();
		}
	}
	else {
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0)
					count += 1;
			}
		}
		answer = count;
	}
	cout << answer << endl;
	return 0;
}