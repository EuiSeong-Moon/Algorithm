#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

//Brute Force�� �̿��� ���������� �ּҼ� �ĺ��� ���� ������ �߰������� �κ������� ����ؾ� ��.
using namespace std;
vector<vector<int>> answers;
void recur(int index, int i, vector<int> tmp, int* flag, int& answer, vector<vector<string>> relation) {	//�ĺ�Ű�� �� ���ִ� ����(�ּҼ� ����)
	for (int j = index; j<relation.at(0).size(); j++) {
		//if (flag[j] == 0)
			tmp.push_back(j);
		if (tmp.size() == i) {
			int fflag = 0;
			vector<string> strs;
			for (int k = 0; k<relation.size(); k++) {
				string str;
				for (int p = 0; p<tmp.size(); p++)
				{
					str += (string)relation.at(k).at(tmp.at(p));
				}

				for (int q = 0; q<strs.size(); q++)
				{
					if (strs.at(q) == str)
					{
						fflag = 1;
					}
				}
				strs.push_back(str);
			}
			if (fflag == 0)
			{
				answer++;
				/*for (int p = 0; p<tmp.size(); p++)
				{
					flag[tmp.at(p)] = 1;
				}*/
				//tmp.clear();
				answers.push_back(tmp);
			}
		}
		else
			recur(j + 1, i, tmp, flag, answer, relation);
		if(tmp.size()!=0)
			tmp.pop_back();
	}
}
int solution(vector<vector<string>> relation) {
	int answer = 0;
	int *flag = new int[relation.at(0).size()];
	vector<int> tmp;
	for (int i = 0; i<relation.at(0).size(); i++)
		flag[i] = 0;
	for (int i = 1; i <= relation.size(); i++)
		recur(0, i, tmp, flag, answer, relation);
	for (int i = 0; i < answers.size(); i++)	//�ּҼ� üũ������ answer�� ��� answers ���ͳ� ��� �� �� �κ����տ� �ߺ��Ǵ� ū ��(�ּҼ� �������� �ʴ¼�) ����
	{
		for (int j = i+1; j < answers.size(); j++)
		{
			int count = 0;
			for (int k = 0; k < answers.at(i).size();k++)
			{
				if(find(answers.at(j).begin(), answers.at(j).end(), answers.at(i).at(k)) != answers.at(j).end())
				{
					count++;
					continue;
				}
			}
			if (count == answers.at(i).size())
			{
				answers.erase(answers.begin() + j);
				i--;
				break;
			}
		}
	}
	answer = answers.size();
	return answer;
}
int main(void)
{
	vector<vector<string>> str;
	vector<string> st;
	st.push_back("100");	st.push_back("ryan");	st.push_back("music");	st.push_back("2");	str.push_back(st);
	st.clear();
	st.push_back("200");	st.push_back("apeach");	st.push_back("math");	st.push_back("2");	str.push_back(st);
	st.clear();
	st.push_back("300");	st.push_back("tube");	st.push_back("computer");	st.push_back("3");	str.push_back(st);
	st.clear();
	st.push_back("400");	st.push_back("con");	st.push_back("computer");	st.push_back("4");	str.push_back(st);
	st.clear();
	st.push_back("500");	st.push_back("muzi");	st.push_back("music");	st.push_back("3");	str.push_back(st);
	st.clear();
	st.push_back("600");	st.push_back("apeach");	st.push_back("music");	st.push_back("2");	str.push_back(st);
	solution(str);
	return 0;
}