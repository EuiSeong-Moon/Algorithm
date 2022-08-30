#include <iostream>

using namespace std;

void recur(int n,int& answer) {
	if (n == 0)
		answer += 1;
	else {
		for (int i = 1; i <= 3; i++) {
			if (n >= i)
				recur(n - i, answer);
		}
	}
}
int main(void) {
	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int N,answer=0;
		cin >> N;
		for (int i = 1; i <= 3; i++) {
			if (N >= i)
				recur(N-i,answer);
		}
		cout << answer << endl;
	}
	return 0;
}