#include <iostream>

using namespace std;
char map[50][50];
int main(void)
{
	int M, N,answer=50000;
	char buf;
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> buf;
			map[i][j] = buf;
		}
	}
	for (int i = 0; i <= M - 8; i++) {
		for (int j = 0; j <= N - 8; j++) {
			//처음이 B
			char start = 'B';
			int flag;
			int paint = 0;
			for (int m = i; m < 8 + i; m++) {
				flag = 0;
				for (int n = j; n < 8 + j; n++) {
					if (flag == 0 && map[m][n] != start) {
						paint++;
					}
					else if (flag == 1 && map[m][n] == start)
						paint++;
					if (flag == 0)
						flag = 1;
					else
						flag = 0;
				}
				if (start == 'B')
					start = 'W';
				else
					start = 'B';
			}
			if (paint < answer)
				answer = paint;

			//처음이 W
			start = 'W';
			paint = 0;
			for (int m = i; m < 8 + i; m++) {
				flag = 0;
				for (int n = j; n < 8 + j; n++) {
					if (flag == 0 && map[m][n] != start) {
						paint++;
					}
					else if (flag == 1 && map[m][n] == start)
						paint++;
					if (flag == 0)
						flag = 1;
					else
						flag = 0;
				}
				if (start == 'B')
					start = 'W';
				else
					start = 'B';
			}
			if (paint < answer)
				answer = paint;
		}
	}
	cout << answer << endl;
	return 0;
}