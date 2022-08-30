#include<iostream>
#include<vector>

using namespace std;

int map[9][9];
bool check(pair<int, int> pos, int number) {
	for (int i = 0; i < 9; i++) {
		if (map[i][pos.second] == number)
			return false;
	}
	for (int j = 0; j < 9; j++) {
		if (map[pos.first][j] == number)
			return false;
	}
	int m, n;
	switch (pos.first / 3) {
	case 0:
		m = 0;
		break;
	case 1:
		m = 3;
		break;
	case 2:
		m = 6;
		break;
	}
	switch (pos.second / 3) {
	case 0:
		n = 0;
		break;
	case 1:
		n = 3;
		break;
	case 2:
		n = 6;
		break;
	}
	for (int i = m; i < m + 3; i++) {
		for (int j = n; j < n + 3; j++) {
			if (map[i][j] == number)
				return false;
		}
	}
	return true;
}
int recur(int index,vector<pair<int,int>> barket) {
	int size = index;
	if (index == barket.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++) {
				if (j != 8)
					cout << map[i][j] << " ";
				else
					cout << map[i][j] << endl;
			}
		}
		return 1;
	}
	for (int i = 1; i <= 9; i++) {
		pair<int, int> pos;	pos = barket.at(size);
		if (check(pos, i)) {
			map[pos.first][pos.second] = i;
			if(recur(size + 1, barket)==1)
				return 1;
			map[pos.first][pos.second] = 0;
		}
	}
	
	return 0;
}

int main(void) {
	vector<pair<int, int>> barket;
	int buf;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> buf;
			map[i][j] = buf;
			if (buf == 0) {
				pair<int, int> s_pos;	s_pos.first = i;	s_pos.second = j;
				barket.push_back(s_pos);
			}
		}
	}
	recur(0, barket);
	return 0;
}