#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<int> getPi(string p) {	//���� getpi�� abbcbba�� ���� ó���� Ʋ�������� �������� üũ����. -����1
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
		b_str = str.substr(i, str.size()-i);	//����1 �ذ��� ���� str���� ���� �ϳ��� ©�󰡸� �ݺ� ����. �ڴ�¥���ʿ���� kmp getpi�� ���ԵǱ� ����
		vector<int> buf = getPi(b_str);
		sort(buf.begin(), buf.end());
		if (answer < buf.at(buf.size() - 1))
			answer = buf.at(buf.size() - 1);
	}
	

	cout << answer << endl;
	return 0;
}