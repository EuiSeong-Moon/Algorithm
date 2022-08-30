#include<iostream>
#include<queue>
#include<string>
using namespace std;

char map[50][50];
bool flag[50][50][7] = { false, };
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };
class Person {
public:
	pair<int, int> pos;
	bool key[6] = { false ,};
	int distnace;
};
queue<Person> barket;
int main(void) {
	string str;
	int N, M;
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			map[i][j] = str.at(j);
			if (str.at(j) == '0') {
				Person s_p;	s_p.pos.first = i;	s_p.pos.second = j;	s_p.distnace = 0;
				barket.push(s_p);
				flag[i][j][6] = true;
			}
		}
	}
	while (barket.size() != 0) {
		Person p;	p = barket.front();	barket.pop();
		for (int m = 0; m < 4; m++) {
			int nr = dr[m] + p.pos.first;
			int nc = dc[m] + p.pos.second;
			if (nr < 0 || nc < 0 || nr >= N || nc >= M)
				continue;
			if (flag[nr][nc][6] == true) {
				bool tag = true;
				for (int k = 0; k < 6; k++) {
					if (flag[nr][nc][k]==false && p.key[k]==true)	//처음 온 곳이거나 키를 더 많이 가지고 온경우만 지나갈 수 있음 그래야 메모리 초과 안남.
					{
						tag = false;
						break;
					}
				}
				if (tag == true) {
					continue;
				}
			}
			if (map[nr][nc] == '1') {
				cout << p.distnace + 1 << endl;
				return 0;
			}
			if (map[nr][nc] == '.' || map[nr][nc]=='0') {
				Person new_p;	new_p.pos.first = nr;	new_p.pos.second = nc;	new_p.distnace = p.distnace + 1;
				for (int k = 0; k < 6; k++) {
					new_p.key[k] = p.key[k];
					flag[nr][nc][k] = p.key[k];
				}
				flag[nr][nc][6] = true;
				barket.push(new_p);
			}
			else if ('a'<=map[nr][nc] && map[nr][nc]<='f') {
				Person new_p;	new_p.pos.first = nr;	new_p.pos.second = nc;	new_p.distnace = p.distnace + 1;
				for (int k = 0; k < 6; k++) {
					new_p.key[k] = p.key[k];
					flag[nr][nc][k] = p.key[k];
				}
				switch (map[nr][nc]) {
				case 'a':
					new_p.key[0] = true;
					break;
				case 'b':
					new_p.key[1] = true;
					break;
				case 'c':
					new_p.key[2] = true;
					break;
				case 'd':
					new_p.key[3] = true;
					break;
				case 'e':
					new_p.key[4] = true;
					break;
				case 'f':
					new_p.key[5] = true;
					break;
				}
				flag[nr][nc][6] = true;
				barket.push(new_p);
			}
			else if ('A' <= map[nr][nc] && map[nr][nc] <= 'F') {
				bool possible = false;
				switch (map[nr][nc]) {
				case 'A':
					if (p.key[0] == true)
						possible = true;
					break;
				case 'B':
					if (p.key[1] == true)
						possible = true;
					break;
				case 'C':
					if (p.key[2])
						possible = true;
					break;
				case 'D':
					if (p.key[3])
						possible = true;
					break;
				case 'E':
					if (p.key[4])
						possible = true;
					break;
				case 'F':
					if (p.key[5])
						possible = true;
					break;
				}
				if (possible == true) {
					Person new_p;	new_p.pos.first = nr;	new_p.pos.second = nc;	new_p.distnace = p.distnace + 1;
					for (int k = 0; k < 6; k++) {
						new_p.key[k] = p.key[k];
						flag[nr][nc][k] = p.key[k];
					}
					flag[nr][nc][6] = true;
					barket.push(new_p);
				}
			}
		}
	}
	cout << "-1" << endl;

	return 0;
}