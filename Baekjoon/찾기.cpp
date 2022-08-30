#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getPi(string p) {
	int m = (int)p.size();
	int j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++)
	{
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}
vector<int> kmp(string s, string p)
{
	vector<int> ans;
	vector<int> pi = getPi(p);
	int n = (int)s.size(), m = (int)p.size(), j = 0;
	for (int i = 0; i < n; i++)
	{
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}
int main(void)
{
	string a, b;
	getline(cin, a);
	getline(cin, b);
	vector<int> answer=kmp(a, b);
	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer.at(i)+1 << " ";
	}
	return 0;
}