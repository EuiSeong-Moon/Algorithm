#include <iostream>
#include <stack>
using namespace std;
int map[101][101] = { 0, };


class Points {
public:
	int xpos;
	int ypos;
};
int main(void)
{
	//INPUT
	int N,v,max=0,answer=1,answ;
	stack<Points>dfs;
	cin >> N;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			cin >> v;
			map[i][j] = v;
			if (v > max)
				max = v;
		}
	}
	//k is the rain height
	for (int k = 1; k <= max; k++)
	{
		answ = 0;
		bool m_flag[101][101] = {};
		for (int i = 1; i < N+1; i++)
		{
			for (int j = 1; j < N+1; j++)
			{
				int p=i, q=j;
				if (map[p][q] > k && m_flag[p][q] == false)
				{
					Points pt;
					pt.xpos = p;
					pt.ypos = q;
					dfs.push(pt);
					answ += 1;
					m_flag[p][q] = true;
				}
				while(dfs.size()!=0)
				{
					p = dfs.top().xpos;
					q = dfs.top().ypos;
					dfs.pop();
					if (map[p + 1][q] > k && m_flag[p+1][q] == false )
					{
						Points points;
						points.xpos = p + 1;
						points.ypos = q;
						dfs.push(points);
						m_flag[p+1][q] =true;
					}
					if (map[p - 1][q] > k && m_flag[p-1][q] == false)
					{
						Points points2;
						points2.xpos = p - 1;
						points2.ypos = q;
						dfs.push(points2);
						m_flag[p-1][q] = true;
					}
					if (map[p ][q+1] > k && m_flag[p][q+1] == false)
					{
						Points points3;
						points3.xpos = p;
						points3.ypos = q + 1;
						dfs.push(points3);
						m_flag[p][q+1] = true;
					}
					if (map[p ][q-1] > k && m_flag[p][q-1] == false)
					{
						Points points4;
						points4.xpos = p;
						points4.ypos = q - 1;
						dfs.push(points4);
						m_flag[p][q-1] = true;
					}
				}
			}
		}
		//answ is max of the safe area each for k 
		if (answ > answer)
			answer = answ;
	}
	//answer is the largest answ
	cout << answer;
	return 0;
}