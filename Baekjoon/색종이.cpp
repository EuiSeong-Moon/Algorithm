#include <iostream>

using namespace std;
int map[100][100] = { 0, };

int main(void) {
	int N,a,b,answer=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		for (int m = 90 - b; m <= 99 - b; m++) {
			for (int n = a; n <= a + 9; n++) {
				map[m][n]=1;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1)
				answer += 1;
		}
	}
	cout << answer << endl;
	return 0;
}