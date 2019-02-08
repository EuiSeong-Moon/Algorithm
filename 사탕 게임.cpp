#include <iostream>

using namespace std;
char map[50][50];

int check(int N) {
	int max = 0;
	int size = 1;
	for (int i = 0; i < N; i++) {
		char before = map[i][0];
		for (int j = 1; j < N; j++) {
			if (map[i][j] == before)
				size += 1;
			else {
				if (size > max)
					max = size;
				size = 1;
			}
			before = map[i][j];
		}
		if (size > max)
			max = size;
		size = 1;
	}
	for (int j = 0; j < N; j++) {
		char before = map[0][j];
		for (int i = 1; i < N; i++) {
			if (map[i][j] == before)
				size += 1;
			else {
				if (size > max)
					max = size;
				size = 1;
			}
			before = map[i][j];
		}
		if (size > max)
			max = size;
		size = 1;
	}
	
	return max;
}
int main(void) {
	int N, answer = 0;
	char buf;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> buf;
			map[i][j] = buf;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == N - 1 && j == -1)
				break;
			if (j == N - 1) {//아래
				char temp, temp2;
				temp = map[i][j];	temp2 = map[i + 1][j];
				map[i][j] = temp2;	map[i + 1][j] = temp;
				int a = check(N);
				if (a > answer)
					answer = a;
				map[i][j] = temp;	map[i + 1][j] = temp2;
			}
			else if (i == N - 1) {//위
				char temp, temp2;
				temp = map[i][j];	temp2 = map[i][j+1];
				map[i][j] = temp2;	map[i][j+1] = temp;
				int a = check(N);
				if (a > answer)
					answer = a;
				map[i][j] = temp;	map[i][j+1] = temp2;
			}
			else {//아래 위
				char temp, temp2;
				temp = map[i][j];	temp2 = map[i + 1][j];
				map[i][j] = temp2;	map[i + 1][j] = temp;
				int a = check(N);
				if (a > answer)
					answer = a;
				map[i][j] = temp;	map[i + 1][j] = temp2;
				temp = map[i][j];	temp2 = map[i][j + 1];
				map[i][j] = temp2;	map[i][j + 1] = temp;
				a = check(N);
				if (a > answer)
					answer = a;
				map[i][j] = temp;	map[i][j + 1] = temp2;
			}
			
		}
	}
	cout << answer << endl;
	return 0;
}