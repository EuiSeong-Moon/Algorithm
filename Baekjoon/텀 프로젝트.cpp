#include<iostream>
#include<vector>
using namespace std;

int student[100000];
int flag[100000] = { 0, };	//0�� ���� ����x 1�� ���� �̷���� -1�� ���� ���� �� ����.

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
			while (flag[student[cur]]==0 || flag[student[cur]]==-2) {	//���� �л����� �̾����� ���
				flag[cur] = -2;
				d.push_back(cur);
				if (flag[student[cur]] == -2) {
					int index;
					for (int k = 0; k < d.size(); k++) {
						if(student[cur] == d.at(k))	//���� �̷���� �� 1->2->3->4->2 �ΰ�� 1�� ���� ���������� �ϱ� ������ �ʿ��� ����.
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
			if (flag[cur]!=1)	//�ڽ��� ���� �̷��찡 �ƴ϶�� ���� �ƴϴ�.
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