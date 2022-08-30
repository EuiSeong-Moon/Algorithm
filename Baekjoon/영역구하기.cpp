#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class Points {
public:
	int xpos;
	int ypos;
};
int main (void)
{
	vector<int> area_sz;
	int number = 0;
	int M, N, K;
	int lx, ly, rx, ry;
	cin >> M >> N >> K;
	int **map = new int*[M];
	for (int i = 0; i < M; i++)
		map[i] = new int[N];
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			map[i][j] = 0;
	}
	for (int i = 0; i < K; i++)
	{
		cin >> lx >> ly >> rx >> ry;
		ly = M - ly;	ry = M - ry;
		for (int m = ry; m < ly; m++)
		{
			for (int n = lx; n < rx; n++)
			{
				map[m][n] = -1;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 0)
			{
				int sz=0;
				queue<Points> pt;
				Points p;
				p.xpos = i;
				p.ypos = j;
				pt.push(p);
				map[i][j] = ++number;
				while (pt.size() != 0)
				{
					Points pbuf;
					pbuf = pt.front();
					sz++;
					pt.pop();
					
					if (pbuf.ypos != N - 1 && map[pbuf.xpos][pbuf.ypos + 1] == 0)
					{
						map[pbuf.xpos][pbuf.ypos + 1] = number;
						Points pts;
						pts.xpos = pbuf.xpos;	pts.ypos = pbuf.ypos + 1;
						pt.push(pts);
					}
					if (pbuf.ypos != 0 && map[pbuf.xpos][pbuf.ypos - 1] == 0)
					{
						map[pbuf.xpos][pbuf.ypos - 1] = number;
						Points pts;
						pts.xpos = pbuf.xpos;	pts.ypos = pbuf.ypos - 1;
						pt.push(pts);
					}
					if (pbuf.xpos != M - 1 && map[pbuf.xpos+1][pbuf.ypos ] == 0)
					{
						map[pbuf.xpos+1][pbuf.ypos ] = number;
						Points pts;
						pts.xpos = pbuf.xpos+1;	pts.ypos = pbuf.ypos;
						pt.push(pts);
					}
					if (pbuf.xpos != 0 && map[pbuf.xpos-1][pbuf.ypos] == 0 )
					{
						map[pbuf.xpos-1][pbuf.ypos] = number;
						Points pts;
						pts.xpos = pbuf.xpos-1;	pts.ypos = pbuf.ypos;
						pt.push(pts);
					}
				}
				area_sz.push_back(sz);
			}
		}
	}
	sort(area_sz.begin(), area_sz.end());
	cout << number << endl;
	for (int i = 0; i < area_sz.size(); i++)
	{
		if (i != area_sz.size() - 1)
			cout << area_sz.at(i) << " ";
		else
			cout << area_sz.at(i);
	}
	return 0;
}