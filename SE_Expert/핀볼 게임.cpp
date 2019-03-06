#include<iostream>
#include<vector>

using namespace std;
int map[100][100];
class Warm {
public:
	vector<pair<int, int>> pos_vector;
	int value;
};
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };

void recur(int direct,pair<int,int> ball,int N,pair<int,int> s_pos,int& answer,int value,vector<Warm>& warm) {
	while (1) {
	
		switch (direct) {
		case 0:
			if (ball.second + 1 < N) {
				ball.second += 1;
			}
			else {
				direct = 2;
				value += 1;
	
			}
			break;
		case 1:
			if (ball.first + 1 < N) {
				ball.first += 1;
			}
			else {
				direct = 3;
				value += 1;
	
			}
			break;
		case 2:
			if (ball.second - 1 >= 0) {
				ball.second -= 1;
			}
			else {
				direct = 0;
				value += 1;
		
			}
			break;
		case 3:
			if (ball.first - 1 >= 0) {
				ball.first -= 1;
			}
			else {
				direct = 1;
				value += 1;
			
			}
			break;
		}
		
		if (map[ball.first][ball.second] == -1 || (ball.first == s_pos.first && ball.second == s_pos.second)) {
			if (value > answer)
				answer = value;
			return;
		}
		else {
			if (map[ball.first][ball.second] == 0) {

			}
			else if (map[ball.first][ball.second] == 1)
			{
				value += 1;
				if (direct == 0) {
					direct = 2;
				}
				else if (direct == 1) {
					direct = 0;
				}
				else if (direct == 2) {
					direct = 3;
				}
				else if (direct == 3) {
					direct = 1;
				}
			}
			else if (map[ball.first][ball.second] == 2) {
				value += 1;
				if (direct == 0) {
					direct = 2;
				}
				else if (direct == 1) {
					direct = 3;
				}
				else if (direct == 2) {
					direct = 1;
				}
				else if (direct == 3) {
					direct = 0;
				}
			}
			else if (map[ball.first][ball.second] == 3) {
				value += 1;
				if (direct == 0) {
					direct = 1;
				}
				else if (direct == 1) {
					direct = 3;
				}
				else if (direct == 2) {
					direct = 0;
				}
				else if (direct == 3) {
					direct = 2;
				}
			}
			else if (map[ball.first][ball.second] == 4) {
				value += 1;
				if (direct == 0) {
					direct = 3;
				}
				else if (direct == 1) {
					direct = 2;
				}
				else if (direct == 2) {
					direct = 0;
				}
				else if (direct == 3) {
					direct = 1;
				}
			}
			else if (map[ball.first][ball.second] == 5) {
				value += 1;
				if (direct == 0) {
					direct = 2;
				}
				else if (direct == 1) {
					direct = 3;
				}
				else if (direct == 2) {
					direct = 0;
				}
				else if (direct == 3) {
					direct = 1;
				}
			}
			//¿úÈ¦
			else {
				for (int p = 0; p < warm.size(); p++) {
					if (warm.at(p).value == map[ball.first][ball.second]) {
						if (warm.at(p).pos_vector.at(0).first == ball.first && warm.at(p).pos_vector.at(0).second == ball.second) {
							ball.first = warm.at(p).pos_vector.at(1).first;
							ball.second = warm.at(p).pos_vector.at(1).second;
							break;
						}
						else {
							ball.first = warm.at(p).pos_vector.at(0).first;
							ball.second = warm.at(p).pos_vector.at(0).second;
						}
					}
				}
			}
		}
		
	}
}
int main(void) {
	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int N,buf;
		vector<Warm> warm;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> buf;
				map[i][j] = buf;
				if (buf >= 6 && buf <= 10) {
					int f = 0;
					for (int k = 0; k < warm.size(); k++) {
						if (buf == warm.at(k).value)
						{
							pair<int, int> pos;	pos.first = i;	pos.second = j;	warm.at(k).pos_vector.push_back(pos);
							f = 1;
							break;
						}
					}
					if (f == 0) {
						Warm w;	w.value = buf;	pair<int, int> pos;	pos.first = i;	pos.second = j;	w.pos_vector.push_back(pos);
						warm.push_back(w);
					}
				}
			}
		}
		int answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int direct;
				pair<int, int> ball;
				if (map[i][j] == 0) {
					pair<int, int> s_pos;
					s_pos.first = i;	s_pos.second = j;
					ball.first = i;	ball.second = j;
					for (int m = 0; m < 4; m++)
					{
						recur(m, ball, N, s_pos, answer, 0, warm);
					}
				}
			}
		}
		cout << "#" << test + 1 << " " << answer << endl;
	}
	return 0;
}