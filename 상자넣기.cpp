#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[1000];
int main(void) {
	//LIS 혹은 dp이용 LIS 보다 dp가 더 나은듯 이해하기 어렵다 LIS ㅠㅠ
	int N,buf,max = 0;
	vector<int> data;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> buf;
		data.push_back(buf);
	}
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (data.at(i) > data.at(j) && dp[j] + 1 > dp[i]) {	//i번째 자리가 0번째부터 i-1까지 쭉 비교했을 때 더 커지고 있는 값인지(좌측부울), 그 중에서 가장 맥스값인지(우측부울)로 찾음.
				dp[i] = dp[j] + 1;
			}
		}
		if (max < dp[i])
			max = dp[i];
	}
	cout << max << endl;
	return 0;
}