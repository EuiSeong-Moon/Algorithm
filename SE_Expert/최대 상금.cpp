#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<unordered_map>
using namespace std;

bool flag[1000000][6] = { false, };

void recur(int value,int count,vector<int>& data,int& answer) {
	if (flag[value][count])
		return;
	flag[value][count] = true;
	if (count == 0) {
		if (answer < value)
			answer = value;
	}
	else {
		for (int i = 0; i < data.size(); i++) {
			for (int j = i + 1; j < data.size(); j++) {
				
				int cmp = data.at(i);
				data.at(i) = data.at(j);
				data.at(j) = cmp;
				int vvalue = 0;
				for (int k = 0; k < data.size(); k++)
					vvalue += data.at(k)*pow(10, data.size() - 1 - k);
				recur(vvalue, count - 1,data,answer);
				cmp = data.at(i);
				data.at(i) = data.at(j);
				data.at(j) = cmp;
			}
		}
	}
}
int main(void) {

	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		unordered_map<int, int> hashs;
		vector<int> data;
		bool same = false;
	//	vector<pair<int, int>> sort_data;
		stack<int> data_buf;
		int N;
		cin >> N;
		while (N / 10 != 0) {
			int a = N % 10;
			data_buf.push(a);
			N /= 10;
		}
		int a = N % 10;	data_buf.push(a);
		int sz = data_buf.size();
		for (int i = 0; i < sz; i++)
		{
			
			data.push_back(data_buf.top());
			hashs[data_buf.top()]++;
			if (hashs[data_buf.top()] >= 2)
				same = true;
		//	sort_data.push_back(p);
			data_buf.pop();
		}
		int count;	cin >> count;
		int answer = 0;
	//	sort(sort_data.begin(), sort_data.end(),cmp);
	//	int j = 0,k=0;
		int ans = 0;
		int value = 0;
		value = 0;
		for (int k = 0; k < data.size(); k++)
			value += data.at(k)*pow(10, data.size() - 1 - k);
		recur(value, count, data, answer);
	
		
		cout << "#"<<test+1<<" "<<answer << endl;
	}
	return 0;
}