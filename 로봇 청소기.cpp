#include <iostream>
#include <queue>
using namespace std;

int map[52][52];
int directions[4] = { 3,0,1,2, };
class Nodes {
public:
	pair<int, int> pos;
	int direct;
};
int main(void)
{
	for (int i = 0; i < 52; i++)
	{
		for (int j = 0; j < 52; j++)
		{
			map[i][j] = 1;
		}
	}
	int N, M,buf1,buf2,buf3,answer=0;
	cin >> N >> M;
	cin >> buf1 >> buf2>>buf3;
	queue<Nodes> barket;
	Nodes n;	n.pos.first = buf1 + 1;	n.pos.second = buf2 + 1;	n.direct = buf3;
	barket.push(n);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++) {
			cin >> buf1;
			map[i][j] = buf1;
		}
	}
	while (barket.size() != 0) {
		Nodes n = barket.front();
		barket.pop();
		if (map[n.pos.first][n.pos.second] == 0)
		{
			map[n.pos.first][n.pos.second] = 2;
			answer++;
		}
		int flag = 0;
		while (flag<4) {
			if (directions[n.direct] == 0 && map[n.pos.first - 1][n.pos.second] == 0) {
				n.pos.first -= 1;
				n.direct = directions[n.direct];
				barket.push(n);
				break;
			}
			else if (directions[n.direct] == 1 && map[n.pos.first][n.pos.second + 1] == 0) {
				n.pos.second += 1;
				n.direct = directions[n.direct];
				barket.push(n);
				break;
			}
			else if (directions[n.direct] == 2 && map[n.pos.first + 1][n.pos.second] == 0) {
				n.pos.first += 1;
				n.direct = directions[n.direct];
				barket.push(n);
				break;
			}
			else if (directions[n.direct] == 3 && map[n.pos.first][n.pos.second - 1] == 0) {
				n.pos.second -= 1;
				n.direct = directions[n.direct];
				barket.push(n);
				break;
			}
			else {
				n.direct = directions[n.direct];
				flag++;
			}
		}
		if (flag==4) {
			if (n.direct == 0 && map[n.pos.first + 1][n.pos.second] !=1) {
				n.pos.first += 1;
				barket.push(n);
			}
			else if (n.direct == 1 && map[n.pos.first][n.pos.second - 1] != 1) {
				n.pos.second -= 1;
				barket.push(n);
			}
			else if (n.direct == 2 && map[n.pos.first -1][n.pos.second] != 1) {
				n.pos.first -= 1;
				barket.push(n);
			}
			else if (n.direct == 3 && map[n.pos.first][n.pos.second + 1] != 1) {
				n.pos.second += 1;
				barket.push(n);
			}
			else {
				break;
			}
		}
	}
	cout << answer << endl;
	return 0;
}