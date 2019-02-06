#include<iostream>
#include<queue>

using namespace std;
int map[100][100];
int flag[100][100][4] = { 0, };
class Robot {
public:
	pair<int, int> pos;
	int direct;
	int command;
};
int BFS(Robot s_robot,Robot f_robot,int N,int M) {		//좌회전, 우회전, 1칸앞, 2칸앞, 3칸앞(flag를 제외한 맵 벗어나거나 map=1이어서 이동불가능 한 경우에는 그냥 break해야 함!!)
	queue<Robot> barket;
	barket.push(s_robot);
	flag[s_robot.pos.first][s_robot.pos.second][s_robot.direct] = 1;
	while (barket.size() != 0) {
		Robot r_buf;
		r_buf = barket.front();
		barket.pop();
		if (r_buf.pos.first == f_robot.pos.first && r_buf.pos.second == f_robot.pos.second && r_buf.direct == f_robot.direct) {
			return r_buf.command;
		}
		switch (r_buf.direct) {
		case 1:
			for (int k = 1; k <= 3; k++) {
				if (r_buf.pos.second + k < N && flag[r_buf.pos.first][r_buf.pos.second + k][1] == 0 && map[r_buf.pos.first][r_buf.pos.second + k] == 0)
				{
					Robot new_r;	new_r.pos.first = r_buf.pos.first;	new_r.pos.second = r_buf.pos.second + k;	new_r.direct = r_buf.direct;	new_r.command = r_buf.command + 1;
					flag[new_r.pos.first][new_r.pos.second][new_r.direct] = 1;
					barket.push(new_r);
				}
				else if(r_buf.pos.second + k >= N || map[r_buf.pos.first][r_buf.pos.second + k] != 0)
					break;
			}
			if (flag[r_buf.pos.first][r_buf.pos.second][3] == 0)
			{
				Robot new_r;	new_r.pos.first = r_buf.pos.first;	new_r.pos.second = r_buf.pos.second;	new_r.direct = 3;	new_r.command = r_buf.command + 1;
				flag[new_r.pos.first][new_r.pos.second][new_r.direct] = 1;
				barket.push(new_r);
			}
			if (flag[r_buf.pos.first][r_buf.pos.second][4] == 0) {
				Robot new_r;	new_r.pos.first = r_buf.pos.first;	new_r.pos.second = r_buf.pos.second;	new_r.direct = 4;	new_r.command = r_buf.command + 1;
				flag[new_r.pos.first][new_r.pos.second][new_r.direct] = 1;
				barket.push(new_r);
			}
			break;
		case 2:
			for (int k = 1; k <= 3; k++) {
				if (r_buf.pos.second - k >= 0 && flag[r_buf.pos.first][r_buf.pos.second - k][2] == 0 && map[r_buf.pos.first][r_buf.pos.second - k] == 0)
				{
					Robot new_r;	new_r.pos.first = r_buf.pos.first;	new_r.pos.second = r_buf.pos.second - k;	new_r.direct = r_buf.direct;	new_r.command = r_buf.command + 1;
					flag[new_r.pos.first][new_r.pos.second][new_r.direct] = 1;
					barket.push(new_r);
				}
				else if (r_buf.pos.second - k < 0 || map[r_buf.pos.first][r_buf.pos.second - k] != 0)
					break;
			}
			if (flag[r_buf.pos.first][r_buf.pos.second][3] == 0)
			{
				Robot new_r;	new_r.pos.first = r_buf.pos.first;	new_r.pos.second = r_buf.pos.second;	new_r.direct = 3;	new_r.command = r_buf.command + 1;
				flag[new_r.pos.first][new_r.pos.second][new_r.direct] = 1;
				barket.push(new_r);
			}
			if (flag[r_buf.pos.first][r_buf.pos.second][4] == 0) {
				Robot new_r;	new_r.pos.first = r_buf.pos.first;	new_r.pos.second = r_buf.pos.second;	new_r.direct = 4;	new_r.command = r_buf.command + 1;
				flag[new_r.pos.first][new_r.pos.second][new_r.direct] = 1;
				barket.push(new_r);
			}
			break;
		case 3:
			for (int k = 1; k <= 3; k++) {
				if (r_buf.pos.first + k < M && flag[r_buf.pos.first + k][r_buf.pos.second][3] == 0 && map[r_buf.pos.first + k][r_buf.pos.second] == 0)
				{
					Robot new_r;	new_r.pos.first = r_buf.pos.first + k;	new_r.pos.second = r_buf.pos.second;	new_r.direct = r_buf.direct;	new_r.command = r_buf.command + 1;
					flag[new_r.pos.first][new_r.pos.second][new_r.direct] = 1;
					barket.push(new_r);
				}
				else if (r_buf.pos.first + k >= M || map[r_buf.pos.first + k][r_buf.pos.second] != 0)
					break;
			}
			if (flag[r_buf.pos.first][r_buf.pos.second][1] == 0)
			{
				Robot new_r;	new_r.pos.first = r_buf.pos.first;	new_r.pos.second = r_buf.pos.second;	new_r.direct = 1;	new_r.command = r_buf.command + 1;
				flag[new_r.pos.first][new_r.pos.second][new_r.direct] = 1;
				barket.push(new_r);
			}
			if (flag[r_buf.pos.first][r_buf.pos.second][2] == 0) {
				Robot new_r;	new_r.pos.first = r_buf.pos.first;	new_r.pos.second = r_buf.pos.second;	new_r.direct = 2;	new_r.command = r_buf.command + 1;
				flag[new_r.pos.first][new_r.pos.second][new_r.direct] = 1;
				barket.push(new_r);
			}
			break;
		case 4:
			for (int k = 1; k <= 3; k++) {
				if (r_buf.pos.first - k >= 0 && flag[r_buf.pos.first - k][r_buf.pos.second][4] == 0 && map[r_buf.pos.first - k][r_buf.pos.second] == 0)
				{
					Robot new_r;	new_r.pos.first = r_buf.pos.first - k;	new_r.pos.second = r_buf.pos.second;	new_r.direct = r_buf.direct;	new_r.command = r_buf.command + 1;
					flag[new_r.pos.first][new_r.pos.second][new_r.direct] = 1;
					barket.push(new_r);
				}
				else if (r_buf.pos.first - k < 0 || map[r_buf.pos.first - k][r_buf.pos.second] != 0)
					break;
			}
			if (flag[r_buf.pos.first][r_buf.pos.second][1] == 0)
			{
				Robot new_r;	new_r.pos.first = r_buf.pos.first;	new_r.pos.second = r_buf.pos.second;	new_r.direct = 1;	new_r.command = r_buf.command + 1;
				flag[new_r.pos.first][new_r.pos.second][new_r.direct] = 1;
				barket.push(new_r);
			}
			if (flag[r_buf.pos.first][r_buf.pos.second][2] == 0) {
				Robot new_r;	new_r.pos.first = r_buf.pos.first;	new_r.pos.second = r_buf.pos.second;	new_r.direct = 2;	new_r.command = r_buf.command + 1;
				flag[new_r.pos.first][new_r.pos.second][new_r.direct] = 1;
				barket.push(new_r);
			}
			break;
		}
	}
}
int main(void) {
	int N, M,buf;
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> buf;
			map[i][j] = buf;
		}
	}
	Robot s_robot,f_robot;
	int buf1, buf2, buf3;
	cin >> buf1 >> buf2 >> buf3;
	s_robot.pos.first = buf1 - 1;	s_robot.pos.second = buf2 - 1;	s_robot.direct = buf3;	s_robot.command = 0;
	cin >> buf1 >> buf2 >> buf3;
	f_robot.pos.first = buf1 - 1;	f_robot.pos.second = buf2 - 1;	f_robot.direct = buf3;
	int answer = BFS(s_robot, f_robot, N, M);
	cout << answer << endl;
}