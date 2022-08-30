#include <iostream>

using namespace std;

class Node {
public:
	int data;
	bool flag = false;
};
Node map[20][20];

void recur(int sz,int direct,int N,int& max) {
	Node new_map[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		{
			new_map[i][j].data = map[i][j].data;
		}
	}
	switch (direct) {
	case 0:
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >0; j--) {
				int k = 1;
				while (map[i][j].data == 0 && j - k >= 0) {
					if (map[i][j - k].data != 0) {
						map[i][j].data = map[i][j - k].data;
						map[i][j - k].data = 0;
					}
					k++;
				}
			}
			for (int j = N-1; j >0; j--) {
				if (map[i][j].data == map[i][j - 1].data) {
					
					map[i][j].data *= 2;
					map[i][j-1].data = 0;
				}
			
			}
			for (int j = N-1; j >0 ; j--) {
				int k = 1;
				while (map[i][j].data == 0 && j - k >= 0) {
					if (map[i][j - k].data != 0) {
						map[i][j].data = map[i][j - k].data;
						map[i][j - k].data = 0;
					}
					k++;
				}
			}
		}
		break;
	case 1:
		for (int j = 0; j < N; j++) {
			for (int i = N - 1; i > 0; i--) {
				int k = 1;
				while (map[i][j].data == 0 && i - k >= 0) {
					if (map[i - k][j].data != 0) {
						map[i][j].data = map[i - k][j].data;
						map[i - k][j].data = 0;
					}
					k++;
				}
			}
			for (int i = N-1; i >0; i--) {
				if (map[i][j].data == map[i - 1][j].data ) {
					
					map[i][j].data *= 2;
					map[i- 1][j].data =0;
				}

			}
			for (int i = N - 1; i > 0; i--) {
				int k = 1;
				while (map[i][j].data == 0 && i-k >= 0) {
					if (map[i - k][j].data != 0) {
						map[i][j].data = map[i - k][j].data;
						map[i - k][j].data = 0;
					}
					k++;
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - 1; j++) {
				int k = 1;
				while (map[i][j].data == 0 && k + j < N) {
					if (map[i][j + k].data != 0) {
						map[i][j].data = map[i][j + k].data;
						map[i][j + k].data = 0;
					}
					k++;
				}
			}
			for (int j = 0; j < N-1; j++) {
				if (map[i][j].data == map[i][j + 1].data) {
					
					map[i][j].data *= 2;
					map[i][j+1].data = 0;
				}
			}
			for (int j = 0; j < N - 1; j++) {
				int k = 1;
				while (map[i][j].data == 0 && k + j < N) {
					if (map[i][j + k].data != 0) {
						map[i][j].data = map[i][j + k].data;
						map[i][j + k].data = 0;
					}
					k++;
				}
			}
		}
		break;
	case 3:
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N - 1; i++) {
				int k = 1;
				while (map[i][j].data == 0 && k + i < N) {
					if (map[i + k][j].data != 0) {
						map[i][j].data = map[i + k][j].data;
						map[i + k][j].data = 0;
					}
					k++;
				}
			}
			for (int i = 0; i < N-1; i++) {
				if (map[i][j].data == map[i + 1][j].data) {
					map[i][j].data *= 2;
					map[i+1][j].data = 0;
				}
			}
			for (int i = 0; i < N-1; i++) {
				int k = 1;
				while (map[i][j].data == 0 && k+i < N) {
					if (map[i + k][j].data != 0) {
						map[i][j].data = map[i + k][j].data;
						map[i + k][j].data = 0;
					}
					k++;
				}
			}
		}
		break;
	default:
		break;
	}
	int c_max = 0;
	if (sz == 5) {
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++) {
				if (map[i][j].data > c_max)
					c_max = map[i][j].data;
			}
		}
		if (c_max > max)
			max = c_max;
	}
	else {
		for (int m = 0; m < 4; m++) {
			recur(sz + 1, m, N, max);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			map[i][j].data = new_map[i][j].data;
		}
	}
}
int main(void) {
	int N,buf;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> buf;
			map[i][j].data = buf;
		}
	}
	int answer = 0;
	recur(0, -1, N, answer);
	cout << answer << endl;
	return 0;
}