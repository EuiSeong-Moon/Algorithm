#include<iostream>
#include<vector>
using namespace std;

int student[100000];
int flag[100000] = { 0, };	//0은 아직 진행x 1은 팀이 이루어짐 -1은 팀을 만들 수 없음.

int main(void) {
	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int N,buf;
		int number = 1;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> buf;
			student[i] = buf - 1;
			flag[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			if (student[i] == i) {
				flag[i] = 1;
			}
			int cur=i;
			vector<int>d;
			while (flag[student[cur]]==0 || flag[student[cur]]==-2) {	//다음 학생으로 이어지는 경우
				flag[cur] = -2;
				d.push_back(cur);
				if (flag[student[cur]] == -2) {
					int index;
					for (int k = 0; k < d.size(); k++) {
						if(student[cur] == d.at(k))	//팀이 이루어질 때 1->2->3->4->2 인경우 1을 빼고 팀을만들어야 하기 때문에 필요한 과정.
						{
							index = k;
							break;
						}
					}
					for (int k = 0; k < d.size(); k++) {
						if (k < index)
							flag[d.at(k)] = -1;
						else
							flag[d.at(k)] = 1;
					}
					d.clear();
					break;
				}
				cur = student[cur];
			}
			if (flag[cur]!=1)	//자신이 팀을 이룬경우가 아니라면 팀이 아니다.
			{
				d.push_back(cur);
			}
			for (int k = 0; k < d.size(); k++) {
				flag[d.at(k)] = -1;
			}
			d.clear();
		}
		int answer = 0;
		for (int i = 0; i < N; i++) {
			if (flag[i] == -1)
			{
				answer += 1;
			}
		}
		cout << answer << endl;
	}
	return 0;
}