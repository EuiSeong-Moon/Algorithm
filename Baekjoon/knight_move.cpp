#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

//BFS함수
int Navigate(int sx, int sy, int ex, int ey,int line)
{
	int count = 0;
	queue<pair<int, int>>navi;
	int **map = new int*[line];
	//start!=end 이므로 처음 한번쭉넣어줌
	for (int j = 0; j < line; j++)
	{
		map[j] = new int[line];
		memset(map[j], 0, sizeof(int)*line);
	}
	map[sx][sy] = -1;
	pair<int, int> p[8];
	p[0] = make_pair(sx + 2, sy + 1);
	p[1] = make_pair(sx + 2, sy - 1);
	p[2] = make_pair(sx - 2, sy + 1);
	p[3] = make_pair(sx - 2, sy - 1);
	p[4] = make_pair(sx + 1, sy + 2);
	p[5] = make_pair(sx + 1, sy - 2);
	p[6] = make_pair(sx - 1, sy + 2);
	p[7] = make_pair(sx - 1, sy - 2);
	for (int k = 0; k < 8; k++)
	{
		//맵의 범위를 벗어나거나 0이아닌 즉 한 번이라도 지나간 곳은 제외함.
		if ((p[k].first > 0 && p[k].second > 0) && (p[k].first<line && p[k].second<line) && (map[p[k].first][p[k].second] == 0))
		{
			navi.push(p[k]);
			map[p[k].first][p[k].second] = 1;
		}
	}

	while (navi.size() != 0)
	{
		int cx, cy;
		cx = navi.front().first;	cy = navi.front().second;
		navi.pop();
		if (cx == ex && cy == ey)
		{
			count = map[cx][cy];
			break;
		}
		else
		{
			pair<int, int> p[8];
			p[0] = make_pair(cx + 2, cy + 1);
			p[1] = make_pair(cx + 2, cy - 1);
			p[2] = make_pair(cx - 2, cy + 1);
			p[3] = make_pair(cx - 2, cy - 1);
			p[4] = make_pair(cx + 1, cy + 2);
			p[5] = make_pair(cx + 1, cy - 2);
			p[6] = make_pair(cx - 1, cy + 2);
			p[7] = make_pair(cx - 1, cy - 2);
			for (int k = 0; k < 8; k++)
			{
				if ((p[k].first >= 0 && p[k].second >= 0) &&(p[k].first<line && p[k].second<line)&&(map[p[k].first][p[k].second] == 0))
				{
					navi.push(p[k]);
					map[p[k].first][p[k].second] = map[cx][cy] + 1;
				}
			}
		}
	}
	delete map;
	return count;
}
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int line,sx,sy,ex,ey;
		cin >> line;
		cin >> sx >> sy;
		cin >> ex >> ey;
		//start=end이면 0으로 종료
		if (sx == ex && sy == ey)
			cout << "0" << endl;
		else
			cout<<Navigate(sx, sy, ex, ey, line)<<endl;
	}
	return 0;
}