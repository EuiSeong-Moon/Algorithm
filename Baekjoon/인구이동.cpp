#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
int map[50][50];
int flag[50][50] = { 0, };
class Points {
public:
	int xpos;
	int ypos;
};
int main(void)
{
	int N, L, R, buf, tag = 0, answer = 0;
	cin >> N >> L >> R;
	vector<vector<Points>> unions;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			cin >> buf;
			map[i][j] = buf;
		}
	}
	while (tag == 0)
	{
		for (int m = 0; m < N; m++)
		{
			for (int n = 0; n < N; n++)
			{
				flag[m][n] = 0;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (flag[i][j] == 0)
				{
					vector<Points> team;
					queue<Points> barket;	Points pt;	pt.xpos = i;	pt.ypos = j;
					barket.push(pt);
					flag[pt.xpos][pt.ypos] = 1;
					while (barket.size() != 0) {
						Points pt;	pt = barket.front();	barket.pop();
						
						team.push_back(pt);
						if (pt.xpos != 0 && flag[pt.xpos - 1][pt.ypos] == 0 && abs(map[pt.xpos][pt.ypos]-map[pt.xpos-1][pt.ypos])>=L && abs(map[pt.xpos][pt.ypos] - map[pt.xpos - 1][pt.ypos]) <= R) {
							Points new_pt;	new_pt.xpos = pt.xpos - 1;	new_pt.ypos = pt.ypos;
							flag[pt.xpos-1][pt.ypos] = 1;
							barket.push(new_pt);
						}
						if (pt.xpos != N - 1 && flag[pt.xpos + 1][pt.ypos] == 0 && abs(map[pt.xpos][pt.ypos] - map[pt.xpos + 1][pt.ypos]) >= L && abs(map[pt.xpos][pt.ypos] - map[pt.xpos + 1][pt.ypos]) <= R) {
							Points new_pt;	new_pt.xpos = pt.xpos + 1;	new_pt.ypos = pt.ypos;
							flag[pt.xpos+1][pt.ypos] = 1;
							barket.push(new_pt);
						}
						if (pt.ypos != 0 && flag[pt.xpos][pt.ypos - 1] == 0 && abs(map[pt.xpos][pt.ypos] - map[pt.xpos][pt.ypos-1]) >= L && abs(map[pt.xpos][pt.ypos] - map[pt.xpos][pt.ypos-1]) <= R) {
							Points new_pt;	new_pt.xpos = pt.xpos;	new_pt.ypos = pt.ypos-1;
							flag[pt.xpos][pt.ypos-1] = 1;
							barket.push(new_pt);
						}
						if (pt.ypos != N - 1 && flag[pt.xpos][pt.ypos + 1] == 0 && abs(map[pt.xpos][pt.ypos] - map[pt.xpos][pt.ypos+1]) >= L && abs(map[pt.xpos][pt.ypos] - map[pt.xpos][pt.ypos+1]) <= R) {
							Points new_pt;	new_pt.xpos = pt.xpos;	new_pt.ypos = pt.ypos+1;
							flag[pt.xpos][pt.ypos+1] = 1;
							barket.push(new_pt);
						}
					}
					if (team.size() > 1) {
						unions.push_back(team);
					}
					team.clear();
				}
			}
		}
		if (unions.size() == 0)
			tag = 1;
		else {
			int value;
			answer+=1;
			for (int i = 0; i < unions.size(); i++)
			{
				int size = unions.at(i).size();
				int sum = 0;
				for (int j = 0; j < size; j++)
				{
					sum += map[unions.at(i).at(j).xpos][unions.at(i).at(j).ypos];
				}
				value = sum / size;
				for (int j = 0; j < size; j++)
				{
					map[unions.at(i).at(j).xpos][unions.at(i).at(j).ypos] = value;
				}
			}
			unions.clear();
		}
	}
	cout << answer << endl;
	return 0;
}