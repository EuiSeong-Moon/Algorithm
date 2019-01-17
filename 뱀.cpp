#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[102][102];
class Snake {
public:
	pair<int, int> pos;
	int direction;
};
int main(void)
{
	for (int i = 0; i < 102; i++)
	{
		for (int j = 0; j < 102; j++)
			map[i][j] = -1;
	}
	
	int N,K,buf,buf2,L;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			map[i][j] = 0;
	}
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> buf >> buf2;
		map[buf][buf2] = 2;
	}
	cin >> L;
	vector<pair<int, char>> c_directs;
	char t;
	for (int i = 0; i < L; i++)
	{
		cin >> buf >> t;
		pair<int, char> direct;
		direct.first = buf;	direct.second = t;
		c_directs.push_back(direct);
	}
	Snake head;	head.pos.first = 1;	head.pos.second = 1; head.direction = 1;
	vector<Snake> s_body;	s_body.push_back(head);
	int time = 0;
	int flag = 0;
	while (flag==0) {
		time++;
		int apple = 0;
		Snake new_s;
		for (int i = 0; i < s_body.size(); i++)
		{
			if (s_body.size() == 1)
			{
				new_s.pos.first = s_body.at(0).pos.first;
				new_s.pos.second = s_body.at(0).pos.second;
				new_s.direction = s_body.at(0).direction;
			}
			if (apple == 1 && i == s_body.size() - 1)
			{
				new_s.pos.first = s_body.at(i).pos.first;
				new_s.pos.second = s_body.at(i).pos.second;
				new_s.direction = s_body.at(i).direction;
			}
			switch(s_body.at(i).direction) {
				case 1:
					map[s_body.at(i).pos.first][s_body.at(i).pos.second] = 0;
					s_body.at(i).pos.second += 1;
					if (map[s_body.at(i).pos.first][s_body.at(i).pos.second] == 1 || map[s_body.at(i).pos.first][s_body.at(i).pos.second] == -1)
						flag = 1;
					else if (map[s_body.at(i).pos.first][s_body.at(i).pos.second] == 2)
						apple = 1;
					else
						map[s_body.at(i).pos.first][s_body.at(i).pos.second] = 1;
					break;
				case 2:
					map[s_body.at(i).pos.first][s_body.at(i).pos.second] = 0;
					s_body.at(i).pos.first += 1;
					if (map[s_body.at(i).pos.first][s_body.at(i).pos.second] == 1 || map[s_body.at(i).pos.first][s_body.at(i).pos.second] == -1)
						flag = 1;
					else if (map[s_body.at(i).pos.first][s_body.at(i).pos.second] == 2)
						apple = 1;
					else
						map[s_body.at(i).pos.first][s_body.at(i).pos.second] = 1;
					break;
				case 3:
					map[s_body.at(i).pos.first][s_body.at(i).pos.second] = 0;
					s_body.at(i).pos.second -= 1;
					if (map[s_body.at(i).pos.first][s_body.at(i).pos.second] == 1 || map[s_body.at(i).pos.first][s_body.at(i).pos.second] == -1)
						flag = 1;
					else if (map[s_body.at(i).pos.first][s_body.at(i).pos.second] == 2)
						apple = 1;
					else
						map[s_body.at(i).pos.first][s_body.at(i).pos.second] = 1;
					break;
				case 4:
					map[s_body.at(i).pos.first][s_body.at(i).pos.second] = 0;
					s_body.at(i).pos.first -= 1;
					if (map[s_body.at(i).pos.first][s_body.at(i).pos.second] == 1 || map[s_body.at(i).pos.first][s_body.at(i).pos.second] == -1)
						flag = 1;
					else if (map[s_body.at(i).pos.first][s_body.at(i).pos.second] == 2)
						apple = 1;
					else
						map[s_body.at(i).pos.first][s_body.at(i).pos.second] = 1;
					break;
			}
		}
		if (apple == 1)
		{
			s_body.push_back(new_s);
		}
		for (int i = s_body.size()-1; i >=1; i--)
		{
			if (s_body.at(i - 1).direction != s_body.at(i).direction)
				s_body.at(i).direction = s_body.at(i - 1).direction;
		}
		for (int i = 0; i < c_directs.size(); i++)
		{
			if (c_directs.at(i).first > time)
				break;
			else if (c_directs.at(i).first == time)
			{
				if (c_directs.at(i).second == 'D')
				{
					s_body.at(0).direction += 1;
					if (s_body.at(0).direction == 5)
						s_body.at(0).direction = 1;
				}
				else if (c_directs.at(i).second == 'L')
				{
					s_body.at(0).direction -= 1;
					if (s_body.at(0).direction == 0)
						s_body.at(0).direction = 4;
				}
				else
					cout << "error" << endl;
			}
		}
	}
	cout << time << endl;
	return 0;
}