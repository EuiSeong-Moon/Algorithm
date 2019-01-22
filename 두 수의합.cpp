#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int main(void) {
	int N,buf;
	cin >> N;
	vector<int> data;
	unordered_map<int, bool> map;
	for (int i = 0; i < N; i++) {
		cin >> buf;
		data.push_back(buf);
		map[buf] = true;
	}
	int X;
	long long answer = 0;
	cin >> X;
	for (int i = 0; i < data.size(); i++) {
		int b = X - data.at(i);
		if (b <= 0 || map[data.at(i)]==false)
			continue;
		if (map[b]) {
			answer++;
			//map[data.at(i)] = false;
			//map[b] = false;	//false ����� ���� i=j�� ��� ��Ƽ� Ʋ��. �� ��ƾ� ����! �� �� ���ؼ� 2�γ����°� ����.
		}
	}
	cout << answer/2 << endl;
	return 0;
}