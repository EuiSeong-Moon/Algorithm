#include<iostream>
#include<vector>
using namespace std;

//투포인터 알고리즘 처음 사용해봄 left와 right를 이용해서 진행 함.
int main(void) {
	int N, S,buf;
	vector<int> data;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> buf;
		data.push_back(buf);
	}
	int left = 0;
	int right = 0;
	long long sum = 0;
	long long answer=200000000;
	long long current;
	while (right <= data.size()) {
		if (sum >= S) {
			current = right - left;
			if (current < answer)
				answer = current;
			sum -= data.at(left);
			left += 1;
		}
		else {
			if(right<data.size())	//right가 마지막 인덱스까지 갔을 때 current, answer을 체크하기 위해서.
				sum += data.at(right);
			right += 1;
		}
	}
	if (answer == 200000000)
		answer = 0;
	cout << answer << endl;
	return 0;
}