#include<iostream>
#include<vector>

using namespace std;

int map[20][20];
int main(void) {
	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int N, X, buf;
		cin >> N >> X;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> buf;
				map[i][j] = buf;
			}
		}
		int answer = 0;
		for (int i = 0; i < N; i++) {
			int count = 1, need = 0;
			int number = map[i][0];
			bool tag = true;
			for (int j = 1; j < N; j++) {
				if (number == map[i][j]) {
					if (need > 0)
						need -= 1;
					else
						count += 1;
				}
				else if (number - map[i][j] == 1) {
					if (need != 0) {
						tag = false;
						break;
					}
					count = 0;
					need = X-1;
					--number;
				}
				else if (number - map[i][j] == -1) {
					if (need != 0 || count < X) {
						tag = false;
						break;
					}
					count = 1;
					number += 1;
				}
				else {
					tag = false;
					break;
				}
			}
			if (tag == true && need == 0) {
				answer += 1;
			}
		}
		for (int j = 0; j < N; j++) {
			int count = 1, need = 0;
			int number = map[0][j];
			bool tag = true;
			for (int i = 1; i < N; i++) {
				if (number == map[i][j]) {
					if (need > 0)
						need -= 1;
					else
						count += 1;
				}
				else if (number - map[i][j] == 1) {
					if (need != 0) {
						tag = false;
						break;
					}
					count = 0;
					need = X-1;
					--number;
				}
				else if (number - map[i][j] == -1) {
					if (need != 0 || count < X) {
						tag = false;
						break;
					}
					count = 1;
					number += 1;
				}
				else {
					tag = false;
					break;
				}
			}
			if (tag == true && need == 0) {
				answer += 1;
			}
		}
		cout << "#" << test + 1 << " " << answer << endl;
	}
	return 0;
}