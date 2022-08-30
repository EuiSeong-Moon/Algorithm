#include<iostream>
#include<unordered_map>
#include<queue>
#include<string>
using namespace std;

int map[5][5];
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };
class Str {
public:
	string str;
	int size;
	pair<int, int> pos;
};
int main(void) {
	int buf,answer=0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> buf;
			map[i][j] = buf;
		}
	}
	unordered_map<string, int> hash_data;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			queue<Str> barket;
			pair<int, int> s_pos;	s_pos.first = i;	s_pos.second = j;	Str s_str;	s_str.pos = s_pos;	s_str.size = 1;	s_str.str.push_back(map[i][j]);
			barket.push(s_str);
			while (barket.size() != 0) {
				Str c_str;	c_str = barket.front();	barket.pop();
				if (c_str.size == 6) {
					if (hash_data[c_str.str] != 1) {
						hash_data[c_str.str] = 1;
						answer += 1;
					}
				}
				else {
					for (int m = 0; m < 4; m++) {
						int nr = dr[m] + c_str.pos.first;
						int nc = dc[m] + c_str.pos.second;
						if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5)
							continue;
						Str new_str;	new_str.pos.first = nr;	new_str.pos.second = nc;	new_str.size = c_str.size + 1;	new_str.str = c_str.str;
						new_str.str.push_back(map[nr][nc]);
						barket.push(new_str);
					}
				}
			}
		}
	}
	cout << answer << endl;
	return 0;
}