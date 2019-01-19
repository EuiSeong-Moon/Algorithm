#include <iostream>
#include <vector>
using namespace std;

int map[101][101] = { 0, };
bool line[202][102] = {false, };
int main(void)
{
	int N;
	cin >> N;
	pair<int, int> pos;
	int direction;
	int g;
	vector<int> directions;
	for (int i = 0; i < N; i++)
	{
		directions.clear();
		cin >> pos.second >> pos.first >> direction >> g;
		directions.push_back(direction);
		for (int j = 0; j < g; j++)
		{
			for (int k = directions.size()-1; k >=0; k--)
			{
				switch (directions.at(k)) {
				case 0:
					directions.push_back(1);
					break;
				case 1:
					directions.push_back(2);
					break;
				case 2:
					directions.push_back(3);
					break;
				case 3:
					directions.push_back(0);
					break;
				}
			}
		}
		for(int j=0;j<directions.size();j++)
		{
			direction = directions.at(j);
			switch (direction) {
			case 0:
				map[pos.first][pos.second] = 1;
				map[pos.first][pos.second + 1] = 1;
				pos.second += 1;
				break;
			case 1:
				map[pos.first][pos.second] = 1;
				map[pos.first - 1][pos.second]=1;
				pos.first -= 1;
				break;
			case 2:
				map[pos.first][pos.second] = 1;
				map[pos.first][pos.second - 1] = 1;
				pos.second -= 1;
				break;
			case 3:
				map[pos.first][pos.second] = 1;
				map[pos.first + 1][pos.second] = 1;
				pos.first += 1;
				break;
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++) {
			if (map[i][j]==1 && map[i+1][j]==1 && map[i+1][j+1]==1 && map[i][j+1]==1)
				answer+=1;
		}

	}
	cout << answer << endl;
	return 0;
}