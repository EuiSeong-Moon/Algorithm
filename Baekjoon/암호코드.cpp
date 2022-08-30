#include<iostream>
#include<string>


using namespace std;
long long dp[2][100000] = { 0, };
long long num[5000];
int main(void)
{	//DP 좇나 어렵 2차원배열로 생각해서 풀자늘 시바
	string str;
	cin >> str;
	long long count;
	if (str.at(0) == '0')
	{
		cout << "0" << endl;
		return 0;
	}

	dp[0][0] = 1;	num[0] = str.at(0) - '0';
	for (int i = 1; i < str.size(); i++) {
		num[i] = str.at(i) - '0';
		if (num[i] == 0)
		{
			dp[1][i] = dp[0][i - 1] % 1000000;
		}
		else {
			dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % 1000000;
			if ((num[i-1]*10+num[i]) <= 26) {
				dp[1][i] = dp[0][i - 1] % 1000000;
			}
		}
	}
	count = (dp[0][str.size()-1]+dp[1][str.size()-1])%1000000;
	cout << count << endl;
	return 0;
}