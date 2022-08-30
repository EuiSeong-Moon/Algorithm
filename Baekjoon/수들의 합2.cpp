#include<iostream>


using namespace std;
int map[10000];
int main(void) {
	int N, M,buf;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> buf;
		map[i] = buf;
	}
	int answer = 0;
	int left = 0;
	int right = 0;
	int sum = 0;
	while (right < N || sum>M) {
		if (sum < M) {
			sum += map[right++];
		}
		else if (sum == M) {
			answer += 1;
			sum += map[right++];
		}
		else {
			sum -= map[left++];
		}
	}
	if (sum == M)
		cout << answer + 1 << endl;
	else
		cout << answer << endl;
	return 0;
}