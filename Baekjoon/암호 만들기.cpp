#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
//x,y,z,w 모두 자음
bool flag[26] = { true,false,false,false,true,false,false,false,true,false,false,false,false,false,true,false,false,false,false,false,true,false,false,false,false,false };
void recur(int index, vector<char>& answer, int size,int L,vector<char> buf) {
	if (size == L) {
		int za = 0, mo = 0;
		bool t_flag = false;
		for (int i = 0; i < answer.size(); i++) {
			if (flag[(int)answer.at(i) - 97] == true)
			{
				mo += 1;
			}
			else {
				za += 1;
			}
			if (za >= 2 && mo >= 1)
			{
				t_flag = true;
				break;
			}
		}
		if (t_flag)
		{
			for (int i = 0; i < answer.size(); i++)
			{
				cout << answer.at(i);
			}
			cout << endl;
		}
	}
	else {
		for (int i = index; i < buf.size(); i++) {
			answer.push_back(buf.at(i));
			recur(i + 1, answer, size + 1, L, buf);
			answer.pop_back();
		}
	}
}
int main(void)
{
	int L, C;
	char data;
	vector<char> answer;
	vector<char> buf;
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> data;
		buf.push_back(data);
	}
	sort(buf.begin(), buf.end());
	for (int i = 0; i <= buf.size() - L; i++) {
		answer.push_back(buf.at(i));
		recur(i + 1, answer, 1, L,buf);
		answer.pop_back();
	}
	return 0;
}