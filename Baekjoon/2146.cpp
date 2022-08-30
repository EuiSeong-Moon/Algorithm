#include <iostream>
#include <queue>
using namespace std;
int ids=2;
int minimum = 200;
class Points {
public:
	char xpos;
	char ypos;
};
void detect(int map[105][105], Points pt,  int s_value,int length,bool flag[105][105],int direct);
void group( int map[105][105], Points pt);
int map[105][105] = { 0, };
int main(void)
{
	 int N,buf;
	cin >> N;
	for (int i = 1; i < N+1; i++)
	{
		for (int j = 1; j < N+1; j++)
		{
			cin >> buf;
			if (buf == 0)
				map[i][j] = -1;
			else
			map[i][j] = buf;
		}
	}
	for (char i = 1; i < N+1; i++)
	{
		for (char j = 1; j < N+1; j++)
		{
			if (map[i][j] == 1)
			{
				Points pt;
				pt.xpos = i;	pt.ypos = j;
				group(map, pt);
			}
		}
	}
	for (char i = 1; i < N + 1; i++)
	{
		for (char j = 1; j < N + 1; j++)
		{
			if (map[i][j] >= 2)
			{
				int s_value = map[i][j];
				Points pt;
				pt.xpos = i;	pt.ypos = j;
				bool flag[105][105] = { false, };
				detect(map, pt, s_value,0,flag,0);
			}
		}
	}
	cout << minimum<<endl;
	return 0;
}
void detect(int map[105][105], Points pt, int s_value, int length,bool flag[105][105],int direct)
{
	flag[pt.xpos][pt.ypos] = true;
	if (length >= minimum)
		return;
	if ((map[pt.xpos + 1][pt.ypos] >= 2 && map[pt.xpos + 1][pt.ypos] != s_value) || (map[pt.xpos][pt.ypos+1]>=2 && map[pt.xpos][pt.ypos+1]!=s_value) || (map[pt.xpos-1][pt.ypos]>=2 && map[pt.xpos-1][pt.ypos]!=s_value) || (map[pt.xpos][pt.ypos-1]>=2 && map[pt.xpos][pt.ypos-1]!=s_value))
	{
		if (minimum > length)
		{
			minimum = length;
		}
		return;
	}
	Points new_pt;
	if (map[pt.xpos + 1][pt.ypos] == -1 && flag[pt.xpos+1][pt.ypos]!=true && direct!=4)
	{
		new_pt.xpos = pt.xpos + 1;	new_pt.ypos = pt.ypos;
		detect(map, new_pt, s_value, length + 1,flag,3);
	}
	if (map[pt.xpos][pt.ypos+1] == -1 && flag[pt.xpos][pt.ypos+1] != true && direct!=2)
	{
		new_pt.xpos = pt.xpos;	new_pt.ypos = pt.ypos+1;
		detect(map, new_pt, s_value, length + 1,flag,1);
	}
	if (map[pt.xpos - 1][pt.ypos] == -1 && flag[pt.xpos - 1][pt.ypos] != true && direct!=3)
	{
		new_pt.xpos = pt.xpos - 1;	new_pt.ypos = pt.ypos;
		detect(map, new_pt, s_value, length + 1,flag,4);
	}
	if (map[pt.xpos][pt.ypos-1] == -1 && flag[pt.xpos][pt.ypos-1] != true && direct!=1)
	{
		new_pt.xpos = pt.xpos;	new_pt.ypos = pt.ypos-1;
		detect(map, new_pt, s_value, length + 1,flag,2);
	}
}
void group( int map[105][105],Points pt)
{
	queue<Points> barket;
	Points buf;
	barket.push(pt);
	int id = ids++;
	map[pt.xpos][pt.ypos] = id;
	while (barket.size() != 0)
	{
		buf = barket.front();
		barket.pop();
		Points new_pt;
		if (map[buf.xpos + 1][buf.ypos] == 1)
		{
			new_pt.xpos = buf.xpos + 1;	new_pt.ypos = buf.ypos;
			barket.push(new_pt);
			map[buf.xpos+1][buf.ypos] = id;
		}
		if (map[buf.xpos][buf.ypos + 1] == 1)
		{
			new_pt.xpos = buf.xpos;	new_pt.ypos = buf.ypos+1;
			barket.push(new_pt);
			map[buf.xpos][buf.ypos+1] = id;
		}
		if (map[buf.xpos - 1][buf.ypos] == 1)
		{
			new_pt.xpos = buf.xpos - 1;	new_pt.ypos = buf.ypos;
			barket.push(new_pt);
			map[buf.xpos-1][buf.ypos] = id;
		}
		if (map[buf.xpos][buf.ypos - 1] == 1)
		{
			new_pt.xpos = buf.xpos;	new_pt.ypos = buf.ypos-1;
			barket.push(new_pt);
			map[buf.xpos][buf.ypos-1] = id;
		}
	}
}