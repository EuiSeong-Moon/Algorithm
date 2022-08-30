#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<int> getPi(string p) {	//기존 getpi는 abbcbba와 같이 처음이 틀려버리면 나머지는 체크안함. -문제1
	int m = p.size();
	int j = 0;
	int r = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++)
	{
		while (j > 0 && p[i] != p[j])
		{
			j = pi[j - 1];
			//r = 0;
		}
		if (p[i] == p[j])
		{
			pi[i] = ++j;
		}
	}
	return pi;
}
int main(void)
{
	string str,b_str;
	cin >> str;
	int answer = 0;
	for (int i = 0; i < str.size()-1; i++)
	{
		b_str = str.substr(i, str.size()-i);	//문제1 해결을 위해 str에서 앞을 하나씩 짤라가며 반복 진행. 뒤는짜를필요없음 kmp getpi에 포함되기 때문
		vector<int> buf = getPi(b_str);
		sort(buf.begin(), buf.end());
		if (answer < buf.at(buf.size() - 1))
			answer = buf.at(buf.size() - 1);
	}
	

	cout << answer << endl;
	return 0;
}