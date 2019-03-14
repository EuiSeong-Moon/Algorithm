#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int N,buf,M;
		vector<int> barket;
		vector<int> sorting;
		cin >> N>>M;
		for (int i = 0; i < N; i++) {
			cin >> buf;
			barket.push_back(buf);
			sorting.push_back(buf);
		}
		sort(sorting.begin(), sorting.end());
		bool flag = false;
		int i = 0;
		int count = 0;
		int j = sorting.size() - 1;
		while (flag == false) {
			if (barket.at(i) < sorting.at(j)) {
				barket.push_back(barket.at(i));
				if (i == M) {
					M = barket.size()-1;
				}
				i += 1;
			}
			else {
				if (i == M)
				{
					cout << count + 1 << endl;
					flag = true;
				}
				count += 1;
				i += 1;
				j -= 1;
			}
		}
	}
	return 0;
}