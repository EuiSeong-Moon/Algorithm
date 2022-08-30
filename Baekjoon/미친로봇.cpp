#include<iostream>
//BFS는 메모리 초과나서 안됨 무조건 DFS 써야함 그리고 nr,nc꼭 다시 확인
using namespace std;
bool flag[30][30] = { false, };
double per[4];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0, };
void recur(double& answer, int size,int N,int xpos,int ypos,double buf) {
	if (size == N) {
		answer += buf;
	
	}
	else {
		for (int m = 0; m < 4; m++) {
			int nr = dr[m] + xpos;
			int nc = dc[m] + ypos;
			if (flag[nr][nc] == true)
				continue;
			flag[nr][nc] = true;
			recur(answer,size+1,N,nr,nc,buf*per[m]);
			flag[nr][nc] = false;
		}
	}
}
int main(void) {
	int N;
	cin >> N;
	int d1, d2, d3, d4;
	cin >> d1 >> d2 >> d3 >> d4;
	per[0] = d1/100.0;	per[1] = d2/100.0;	per[2] = d3/100.0;	per[3] = d4/100.0;

	
	double answer = 0;
	for (int m = 0; m < 4; m++) {
		int nr = dr[m] + 15;
		int nc = dc[m] + 15;
		flag[nr][nc] = true;
		flag[15][15] = true;
		recur(answer,1,N,nr,nc,per[m]);
		flag[nr][nc] = false;
	}
	cout.precision(11);
	cout << answer << endl;
	return 0;
}