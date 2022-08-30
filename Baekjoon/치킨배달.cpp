#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int map[51][51];
class Points {
public:
	int xpos;
	int ypos;
};
void fix_ch(vector<Points> chikens, int M, vector<Points> ch, int i, vector<Points> homes, int& answer);
int minimums(vector<Points> homes, vector<Points> ch);
int main(void)
{
	int N, M,buf;
	vector<Points> homes;
	vector<Points> chikens;
	vector<Points> ch;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> buf;
			if (buf == 1)
			{
				Points pt;
				pt.xpos = i;	pt.ypos = j;
				homes.push_back(pt);
			}
			else if (buf == 2) {
				Points pt;
				pt.xpos = i;	pt.ypos = j;
				chikens.push_back(pt);
			}
		}
	}
	int answer = 1000000;
	fix_ch(chikens, M, ch, 0, homes, answer);
	cout << answer;
	return 0;
}
void fix_ch(vector<Points> chikens,int M,vector<Points> ch,int i,vector<Points> homes,int& answer)
{
	int flags = 0;
	while (flags==0)
	{
		if (ch.size() < M)
		{
			if (i == chikens.size())
				break;
			ch.push_back(chikens.at(i));
			i++;
		}
		else if (ch.size() == M)
		{
			int dis = minimums(homes, ch);
			if (answer > dis)
				answer = dis;
			/*int t = 0;
			for (int j = 1; j <= M; j++)	//마지막체크
			{
				if (ch.at(ch.size() - j).xpos == chikens.at(chikens.size() - j).xpos && ch.at(ch.size() - j).ypos == chikens.at(chikens.size() - j).ypos)
					t += 1;
			}
			if (t == M)
				return 1;*/

			ch.pop_back();

			if (ch.size()!=0 && i == chikens.size())
			{
				int index, flag = 2;
				while (1) {
					for (int j = 0; j < chikens.size(); j++)
					{
						if (chikens.at(j).xpos == ch.at(ch.size() - 1).xpos && chikens.at(j).ypos == ch.at(ch.size() - 1).ypos)
						{
							index = j;
							break;
						}
					}
					if (index == chikens.size() - flag) {
						ch.pop_back();
						flag += 1;
					}
					else
						break;
					if (ch.size() == 0)
					{
						flags = 1;
						break;
					}
				}
				if (flags == 1)
					break;
				ch.pop_back();
				i = index + 1;
			}
		}
	}
}
int minimums(vector<Points> homes, vector<Points> ch)
{
	int sum_dis = 0;
	int distance,re_dis=100000;
	for (int i = 0; i < homes.size(); i++)
	{
		for (int j = 0; j < ch.size(); j++)
		{
			distance = abs(homes.at(i).xpos - ch.at(j).xpos) + abs(homes.at(i).ypos - ch.at(j).ypos);
			if (re_dis > distance)
				re_dis = distance;
		}
		sum_dis += re_dis;
		re_dis = 1000000;
	}
	return sum_dis;
}