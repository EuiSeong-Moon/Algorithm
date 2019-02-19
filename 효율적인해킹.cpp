#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<vector<int>> computer;
vector<int> answer;
vector<bool> flag;

int main(void) {
	int N, M;
	flag.push_back(false);
	
	
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		vector<int> v;
		computer.push_back(v);
		flag.push_back(false);
	}
	int buf1, buf2;
	for (int i = 0; i < M; i++) {
		cin >> buf1 >> buf2;
		computer.at(buf2-1).push_back(buf1-1);
	}
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int p = 0; p < N; p++) {
			flag[p] = false;
		}
		int current_count=0;
		flag[i] = true;	//자기자신 체크 깜빡 ㄴㄴ
		for (int j = 0; j < computer.at(i).size(); j++) {
			if (flag[computer.at(i).at(j)] == true)
				continue;
			else {
				flag[computer.at(i).at(j)] = true;
				current_count += 1;
				queue<int> barket;
				barket.push(computer.at(i).at(j));
				while (barket.size() != 0) {
					int data;	data = barket.front();	barket.pop();
					for (int k = 0; k < computer.at(data).size(); k++) {
						if (flag[computer.at(data).at(k)] == true)
							continue;
						else {
							flag[computer.at(data).at(k)] = true;	//왜 j를 박은거? k를 박아야 함. 이런실수 줄이자
							current_count += 1;
							barket.push(computer.at(data).at(k));	//왜 j를 박은거? k를 박아야 함. 이런실수 줄이자
						}
					}
				}
			}
		}
		if (max < current_count)
		{
			max = current_count;
			answer.clear();
			answer.push_back(i);
		}
		else if(max == current_count)
		{
			answer.push_back(i);
		}
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		if (i == answer.size() - 1)
			cout << answer.at(i) + 1;
		else
			cout << answer.at(i)+1 << " ";
	}

	return 0;
}