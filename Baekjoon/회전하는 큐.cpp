#include<iostream>
#include<iterator>
#include<vector>

using namespace std;

int min_distance(int b, int a,vector<int> queues) {
	int ca;
	int cb;
	if (b >= a) {
		int index_a,index_b;
		for (int k = 0; k < queues.size(); k++) {
			if (queues.at(k) == a)
				index_a = k;
			if (queues.at(k) == b)
			{
				index_b = k;
				break;
			}
		}
		ca = index_b - index_a;
		cb = queues.size() - index_b + index_a;
	}
	else {
		int index_a, index_b;
		for (int k = 0; k < queues.size(); k++) {
			if (queues.at(k) == b)
			{
				index_b = k;
			}
			if (queues.at(k) == a) {
				index_a = k;
				break;
			}
		}
		ca = index_a -index_b;
		cb = queues.size() - index_a + index_b;
	}
	if (ca > cb)
		return cb;
	else
		return ca;
}
int main(void) {
	int N, M,buf;
	vector<int> data;
	vector<int> queues;
	cin >> N >> M;
	for (int k = 1; k <= N; k++) {
		queues.push_back(k);
	}
	for (int i = 0; i < M; i++) {
		cin >> buf;
		data.push_back(buf);
	}
	int before = 1,answer=0;
	for (int i = 0; i < data.size(); i++) {
		answer += min_distance(before, data.at(i),queues);
		int index;
		for (int k = 0; k < queues.size(); k++) {
			if (queues.at(k) == data.at(i))
			{
				index = k;
				break;
			}
		}
		queues.erase(queues.begin()+index);
		if (queues.size() == 0)
			break;
		if (index == queues.size())
			before = queues.at(0);
		else
			before = queues.at(index);
	}
	cout << answer << endl;
	return 0;
}