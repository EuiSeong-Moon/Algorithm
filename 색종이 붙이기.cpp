#include<iostream>


using namespace std;

int R[6] = { 0,5,5,5,5,5 };
int map[10][10];
bool flag[10][10] = { false, };
int make_rec(int xpos,int ypos) {
	int line = 1;
	for (int i = 1; i < 5; i++) {
		if (xpos + i > 9 || ypos + i > 9)
			return line;
		for (int p = 0; p <= i; p++) {
			for (int q = 0; q <= i; q++) {
				if (map[xpos + p][ypos + q] == 0)
					return line;
			}
		}
		line += 1;
	}
	return line;
}
bool check_rec(int xpos, int ypos,int size) {
	if (xpos + size > 10 || ypos + size > 10)
		return false;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (flag[i+xpos][j+ypos] == true)
				return false;
		}
	}
	return true;
}
void draw_rec(int xpos, int ypos, int size,bool back) {
	if (back == false) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				flag[i+xpos][j+ypos] = true;
			}
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				flag[i+xpos][j+ypos] = false;
			}
		}
	}
}
void recur(int index_i,int index_j,int count,int& answer)
{
	//i,j가 마지막일 때 answer check
	if (index_j > 9) {
		index_i += 1;
		index_j = 0;
	}
	if (index_i>9) {
		if (answer > count)
			answer = count;
	}
	else {
		if (map[index_i][index_j] == 0 || flag[index_i][index_j] == true)
			recur(index_i, index_j+1, count, answer);
		else {
			for (int k = map[index_i][index_j]; k > 0; k--) {
				if (R[k] == 0)
					continue;
				if (check_rec(index_i, index_j, k) == false)
					continue;
				draw_rec(index_i, index_j, k, false);
				R[k] -= 1;
				recur(index_i, index_j + k, count + 1, answer);
				R[k] += 1;
				draw_rec(index_i, index_j, k, true);
			}
		}
	}
}
int main(void) {
	int buf,answer=250;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> buf;
			map[i][j] = buf;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if(map[i][j]==1)
				map[i][j] = make_rec(i, j);
		}
	}
	recur(0, 0, 0, answer);
	if (answer == 250)
		cout << "-1" << endl;
	else
		cout << answer << endl;
	//answer이 250이면 -1 출력
	return 0;
}