#include<iostream>
#include<queue>
#include<string>
int map[1000][1000];
int dr[] = { 1,-1,0,0 };
int dc[]={ 0,0,1,-1 };
int flag[1000][1000];
using namespace std;
class P_count {
public:
	pair<int, int> pos;
	int count;
	bool breaks;
};
int BFS(pair<int,int> pos,int N,int M) {
	queue<P_count> barket;
	P_count count;	count.pos = pos;	count.count = 1;	count.breaks = false;
	barket.push(count);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			flag[i][j] = 0;
		}
	}
	flag[pos.first][pos.second] = 1;
	while (barket.size() != 0)
	{
		P_count c;
		c=barket.front();
		barket.pop();
		for (int m = 0; m < 4; m++) {
			int nr = dr[m] + c.pos.first;
			int nc = dc[m] + c.pos.second;
			if (nr < 0 || nc < 0 || nr >= N || nc >= M) {
				continue;
			}
			if (flag[nr][nc] == 1)	//1은 벽을 안부순상태에서 지나간 경우로 더 이상 중복할 이유가 없는 곳
				continue;
			if (flag[nr][nc] == 2 && c.breaks == true)	//벽을 안부섰을땐 부수고 지나간 길을 지나갈 수 있어야함. 벽을 부수지 않은 경우 같은 길을 가더라도 더 거리를 단축할 가능성이 있기 때문이다.(당근 반대는 안됨)
				continue;	//이 부분은 벽을 이미 부순 플레이어가 지나간 곳으로 벽을 부수지 않은 플레이어는 지나갈 수 있음(이미 벽을 부순플레이어는 더 이상 중복 이유가 없어 지나갈 수 없음)
			if (map[nr][nc] == 0) {	//길을 가는 경우
				if (nr == N - 1 && nc == M - 1) {
					return c.count+1;
				}
				pair<int, int> new_pos;	new_pos.first = nr;	new_pos.second = nc;
				P_count new_count;	new_count.pos = new_pos;	new_count.count = c.count + 1;	new_count.breaks = c.breaks;
				barket.push(new_count);
				if (flag[nr][nc] == 0 && c.breaks == true)
					flag[nr][nc] = 2;
				else
					flag[nr][nc] = 1;
			}
			else if (map[nr][nc] == 1 && c.breaks == false) {	//벽을 부수고 가는 경우
				pair<int, int> new_pos;	new_pos.first = nr;	new_pos.second = nc;
				P_count new_count;	new_count.pos = new_pos;	new_count.count = c.count + 1;	new_count.breaks = true;
				flag[nr][nc] = 1;
				barket.push(new_count);
			}
		}
	}
	return -1;
}
int main(void) {
	cin.tie(0);
	int N, M,buf,answer=1000000;
	string str;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
			cin >> str;
			int j = 0;
			while (j < M) {
				map[i][j] = str.at(j)-'0';
				j++;
			}
	}
	pair<int, int> pos;	pos.first = 0;	pos.second = 0;
	answer = BFS(pos, N, M);
	if (N == 1 && M == 1)
	{
		cout << "1" << endl;
		return 0;
	}
/*	for (int i = 0; i < N; i++) {		이렇게 하면 무조건 시간초과 한 번에 하면서 break을 클래스 변수로 사용해서 부수는 걸로 해야 함.!!!
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1)
			{
				map[i][j] = 0;
				pair<int, int> pos;	pos.first = 0;	pos.second = 0;
				int num=BFS(pos,N,M,answer);
				if (num != -1 && num < answer)
					answer = num;
				map[i][j] = 1;
			}
		}
	}*/
	
	cout << answer << "\n";
	return 0;
}
