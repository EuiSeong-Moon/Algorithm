#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(void) {
	int N, M, buf;
	unordered_map<int, int> hashs;
	vector<int> answer;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> buf;
		hashs[buf] = 1;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> buf;
		if (hashs[buf] == 1)
			answer.push_back(1);
		else
			answer.push_back(0);
	}
	for (int i = 0; i < answer.size(); i++) {
		if (i != answer.size() - 1)
			cout << answer.at(i) << " ";
		else
			cout << answer.at(i) << endl;
	}
	return 0;
}