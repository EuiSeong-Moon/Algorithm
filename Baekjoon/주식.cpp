#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second > p2.second;
}
int main(void)
{
	int T;
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		int N, buf = 0,day=1;
		long long answer = 0;
		cin >> N;
		vector<pair<int, int>> values;
		vector<pair<int, int>> pivot;
		for (int i = 1; i <= N; i++) {
			pair<int, int> value;
			value.first=i;
			cin >> value.second;
			values.push_back(value);
			pivot.push_back(value);
		}
		sort(values.begin(), values.end(),cmp);
		int i = 0;
		while(i<values.size() && day<=N) {
			if (day <= values.at(i).first && ((values.at(i).second - pivot.at(day - 1).second)>=0)) {
				answer+= values.at(i).second - pivot.at(day - 1).second;
				day += 1;
			}
			else if (values.at(i).second - pivot.at(day - 1).second<0) {
				day+=1;
			}
			else {
				i += 1;
			}
		}
		cout << answer << endl;
	}
}