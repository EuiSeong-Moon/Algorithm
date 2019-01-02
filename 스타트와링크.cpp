#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int map[21][21];
int teams[21] = { 0, };

int calculate(int size)
{
	vector<int> team1;
	vector<int> team2;
	int t1 = 0;
	int t2 = 0;
	for (int i = 0; i < size; i++)
	{
		if (teams[i] == 1) {
			team1.push_back(i);
		}
		else
		{
			team2.push_back(i);
		}
	}
	if (team1.size() != team2.size())
	{
		team1.at(10000000) = -1;
	}
	for (int i = 0; i < team1.size(); i++)
	{
		for (int j = 0; j < team1.size(); j++)
		{
			if (i != j)
			{
				t1 += map[team1.at(i)][team1.at(j)];
				t2 += map[team2.at(i)][team2.at(j)];
			}
		}
	}
	return abs(t1 - t2);
}
void make_team(int sz, int size,  int& answer, int index) {
	if (sz == size/2) {
		int ans=calculate(size);
		if (ans < answer)
			answer = ans;
	}
	else {
		for (int i = index; i < size; i++)
		{
			teams[i] = 1;
			sz++;
			make_team(sz, size, answer, i + 1);
			teams[i] = 0;
			sz--;
		}
	}
}
int main(void)
{
	int S, buf;
	cin >> S;

	int sz = 0;
	int answer = 1000000000;
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < S; j++)
		{
			cin >> buf;
			map[i][j] = buf;
		}
	}
	
	make_team(0, S, answer, 0);
	cout << answer << endl;
	return 0;
}