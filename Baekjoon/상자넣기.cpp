#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[1000];
int main(void) {
	//LIS Ȥ�� dp�̿� LIS ���� dp�� �� ������ �����ϱ� ��ƴ� LIS �Ф�
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
			if (data.at(i) > data.at(j) && dp[j] + 1 > dp[i]) {	//i��° �ڸ��� 0��°���� i-1���� �� ������ �� �� Ŀ���� �ִ� ������(�����ο�), �� �߿��� ���� �ƽ�������(�����ο�)�� ã��.
				dp[i] = dp[j] + 1;
			}
		}
		if (max < dp[i])
			max = dp[i];
	}
	cout << max << endl;
	return 0;
}