#include<iostream>
#include<queue>
#include<vector>

using namespace std;
class Apes {
public:
	pair<int, int> pos;
	int size;
};
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };
bool flag[10][10];
bool map[8][10][10] = { false, };
void recur(int& answer,int& sum,int size,int ap,vector<pair<int,int>>& person,vector<int>& power,vector<int>& occupy,int& buf_sum) {
	if (size == 2) {
		if (buf_sum < sum)
			buf_sum = sum;
	}
	else {
		for (int i = 0; i < ap; i++) {
			if (map[i][person.at(1).first][person.at(1).second]) {
				occupy.at(i) += 1;
				if (occupy.at(i) != 2)
					sum += power.at(i);
				recur(answer, sum,2,ap,person,power,occupy,buf_sum);
				if (occupy.at(i) != 2)
					sum -= power.at(i);
				occupy.at(i) -= 1;
			}
			if (i == ap - 1)
				recur(answer, sum, 2, ap, person, power, occupy, buf_sum);
		}
	}
}
int main(void) {
	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int move, ap,buf;
		cin >> move >> ap;
		for (int i = 0; i < ap; i++) {
			for (int p = 0; p < 10; p++) {
				for (int q = 0; q < 10; q++)
					map[i][p][q] = false;
			}
		}
		vector<pair<int, int>> person;
		pair<int, int> p1;	p1.first = 0;	p1.second = 0;	pair<int, int> p2;	p2.first = 9;	p2.second = 9;
		person.push_back(p1);	person.push_back(p2);
		vector<vector<int>> person_move;
		for (int j = 0; j < 2; j++) {
			vector<int> vv;
			for (int i = 0; i < move; i++) {
				cin >> buf;
				vv.push_back(buf);
			}
			person_move.push_back(vv);
		}
		vector<Apes> aps;
		vector<int> power;
		vector<int> occupy;
		for (int i = 0; i < ap; i++) {
			Apes apes;
			cin >> buf;		apes.pos.second = buf-1;
			cin >> buf;		apes.pos.first = buf-1;
			cin >> buf;		apes.size = buf;
			aps.push_back(apes);
			cin >> buf;		power.push_back(buf);
			occupy.push_back(0);
		}
		for (int i = 0; i < aps.size(); i++) {
			pair<int, int> s_pos = aps.at(i).pos;
			int size = aps.at(i).size;
			queue<pair<int, int>> barket;	barket.push(s_pos);
			int distance = 1;
			for (int p = 0; p < 10; p++)
			{
				for (int q = 0; q < 10; q++) {
					flag[p][q] = false;
				}
			}
			flag[s_pos.first][s_pos.second] = true;
			map[i][s_pos.first][s_pos.second] = true;
			while (barket.size() != 0) {
				pair<int, int> pos;	pos = barket.front();	barket.pop();
				distance -= 1;
				for (int m = 0; m < 4; m++) {
					int nr = dr[m] + pos.first;
					int nc = dc[m] + pos.second;
					if (nr < 0 || nc < 0 || nr >= 10 || nc >= 10)
						continue;
					if (flag[nr][nc] == true)
						continue;
					map[i][nr][nc] = true;
					flag[nr][nc] = true;
					pair<int, int> new_pos;	new_pos.first = nr;	new_pos.second = nc;
					barket.push(new_pos);
				}
				if (distance == 0) {
					size -= 1;
					distance = barket.size();
					if (size == 0) {
						break;
					}
				}
			}
		}
		int answer = 0;
		int kk = 0;
		while (move >= 0) {
			int sum = 0;
			int buf_sum = 0;
			for (int i = 0; i < ap; i++) {
				if (map[i][person.at(0).first][person.at(0).second]) {
					occupy.at(i) += 1;
					sum += power.at(i);
					recur(answer, sum, 1, ap, person, power, occupy, buf_sum);
					sum -= power.at(i);
					occupy.at(i) -= 1;
				}
				if (i == ap - 1)
					recur(answer, sum, 1, ap, person, power, occupy, buf_sum);
			}
			answer += buf_sum;
			if (move == 0)
				break;
			switch (person_move.at(0).at(kk)) {
			case 0:
				break;
			case 1:
				if (person.at(0).first - 1 >= 0) {
					person.at(0).first -= 1;
				}
				break;
			case 2:
				if (person.at(0).second + 1 < 10) {
					person.at(0).second += 1;
				}
				break;
			case 3:
				if (person.at(0).first + 1 < 10) {
					person.at(0).first += 1;
				}
				break;
			case 4:
				if (person.at(0).second - 1 >= 0) {
					person.at(0).second -= 1;
				}
				break;
			}
			switch (person_move.at(1).at(kk)) {
			case 0:
				break;
			case 1:
				if (person.at(1).first - 1 >= 0) {
					person.at(1).first -= 1;
				}
				break;
			case 2:
				if (person.at(1).second + 1 < 10) {
					person.at(1).second += 1;
				}
				break;
			case 3:
				if (person.at(1).first + 1 < 10) {
					person.at(1).first += 1;
				}
				break;
			case 4:
				if (person.at(1).second - 1 >= 0) {
					person.at(1).second -= 1;
				}
				break;
			}
			kk += 1;
			move -= 1;
		}
		cout <<"#"<<test+1<<" "<< answer << endl;
	}
	return 0;
}