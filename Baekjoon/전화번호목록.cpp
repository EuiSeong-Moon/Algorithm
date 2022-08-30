#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
#include <vector>
using namespace std;

bool cmp(string a, string b) {
	return a.size() < b.size();
}
int main(void) {
	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int N;
		string buf;
		cin >> N;
		unordered_map<string,int> data;
		vector<string> str;
		int flag = 1;
		for (int i = 0; i < N; i++) {
			cin >> buf;
			str.push_back(buf);
		}
		sort(str.begin(), str.end(), cmp);	//정렬해야 시가초과 면함 즉 정렬하면 더 빠름.
		for(int i=0;i<str.size();i++){
			string check;
			string buf = str.at(i);
			for (int j = 0; j < buf.size(); j++) {
				string a(1, buf.at(j));
				check += a;
				if (data[check] == 1)
				{
					flag = 0;
					break;
				}
				if (j == buf.size() - 1)
					data[check] = 1;
			}
			if (flag == 0)
				break;
		}
		if (flag == 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}