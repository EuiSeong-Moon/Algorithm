#include <iostream>
#include <vector>

using namespace std;
int map[100][100];

int main(void)
{
	int N, L,buf,answer=0;
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> buf;
			map[i][j] = buf;
		}
	}
	pair<int, int> p;
	vector<pair<int, int>> line;

	//За
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j != 0) {
				if (p.first == map[i][j])
				{
					p.second++;
				}
				else
				{
					line.push_back(p);	p.first = map[i][j];	p.second = 1;
				}
				if (j == N - 1)
					line.push_back(p);
			}
			else {
				p.first = map[i][j];
				p.second = 1;
			}
		}
		pair<int, int> before;
		for (int k = 0; k < line.size(); k++)
		{
			if (k == 0) {
				before.first = line.at(k).first;	before.second = line.at(k).second;
			}
			else {
				if (before.first - line.at(k).first == 1)
				{
					if (line.at(k).second >= L) {
						line.at(k).second -= L;
					}
					else
						break;
				}
				else if (line.at(k).first - before.first == 1)
				{
					if (before.second >= L)
						line.at(k - 1).second -= L;
					else
						break;
				}
				else {
					break;
				}
				before.first = line.at(k).first;
				before.second = line.at(k).second;
			}
			if (k == line.size() - 1)
				answer++;
		}
		line.clear();
	}
	//ї­
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i != 0) {
				if (p.first == map[i][j])
				{
					p.second++;
				}
				else
				{
					line.push_back(p);	p.first = map[i][j];	p.second = 1;
				}
				if (i == N - 1)
					line.push_back(p);
			}
			else {
				p.first = map[i][j];
				p.second = 1;
			}
		}
		pair<int, int> before;
		for (int k = 0; k < line.size(); k++)
		{
			if (k == 0) {
				before.first = line.at(k).first;	before.second = line.at(k).second;
			}
			else {
				if (before.first - line.at(k).first == 1)
				{
					if (line.at(k).second >= L) {
						line.at(k).second -= L;
					}
					else
						break;
				}
				else if (line.at(k).first - before.first == 1)
				{
					if (before.second >= L)
						line.at(k - 1).second -= L;
					else
						break;
				}
				else {
					break;
				}
				before.first = line.at(k).first;
				before.second = line.at(k).second;
			}
			if (k == line.size() - 1)
				answer++;
		}
		line.clear();
	}
	cout << answer << endl;
	return 0;
}