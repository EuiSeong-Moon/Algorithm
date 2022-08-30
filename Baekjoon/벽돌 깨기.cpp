#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int map[15][12];
int buf_map[15][12];

int block;
void recur(int& answer,int size,int N,int W,int H,vector<int>& barket) {
	if (size == N) {
		int block_attack = 0;
		queue <pair<int,pair<int, int>>> q_barket;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				buf_map[i][j] = map[i][j];
			}
		}
	
		for (int k = 0; k < barket.size(); k++) {
			int a = 0;
			while (a<H && buf_map[a][barket.at(k)]==0)
				a += 1;
			if (a == H)
				continue;
			
			pair<int, pair<int, int>> pp; pair<int, int> p;	p.first = a;	p.second = barket.at(k);
			pp.first = buf_map[p.first][p.second];	pp.second = p;
			buf_map[p.first][p.second] = 0;
			q_barket.push(pp);
			while (q_barket.size() != 0) {
				pair<int, pair<int, int>> ppos;	ppos = q_barket.front();	q_barket.pop();
				pair<int, int> pos;	pos = ppos.second;
				block_attack+=1;
				int cc = ppos.first;
			
				for (int m = 1; m < cc; m++) {
					int nr = pos.first + m;
					int nr2 = pos.first - m;
					int nc = pos.second + m;
					int nc2 = pos.second - m;
					if (nr2 >= 0 && buf_map[nr2][pos.second] !=0) {
					
							pair<int, pair<int, int>> new_ppos; pair<int, int> new_pos;	new_pos.first = nr2;	new_pos.second = pos.second;
							new_ppos.first = buf_map[nr2][pos.second];	new_ppos.second = new_pos;
							q_barket.push(new_ppos);
							buf_map[nr2][pos.second] = 0;
						
					}
					if (nr < H && buf_map[nr][pos.second]!=0) {
					
							pair<int, pair<int, int>> new_ppos;  pair<int, int> new_pos;	new_pos.first = nr;	new_pos.second = pos.second;
							new_ppos.first = buf_map[nr][pos.second];	new_ppos.second = new_pos;
							q_barket.push(new_ppos);
							buf_map[nr][pos.second] = 0;
						
					}
					if (nc < W && buf_map[pos.first][nc] !=0) {
						
						pair<int, pair<int, int>> new_ppos;  pair<int, int> new_pos;	new_pos.first = pos.first;	new_pos.second = nc;
						new_ppos.first = buf_map[pos.first][nc];	new_ppos.second = new_pos;
						q_barket.push(new_ppos);
						buf_map[pos.first][nc] = 0;
					}
					if (nc2 >= 0 && buf_map[pos.first][nc2]!=0) {
						
						pair<int, pair<int, int>> new_ppos;  pair<int, int> new_pos;	new_pos.first = pos.first;	new_pos.second = nc2;
						new_ppos.first = buf_map[pos.first][nc2];	new_ppos.second = new_pos;
						q_barket.push(new_ppos);
						buf_map[pos.first][nc2] = 0;
					}
				}
			}
			if (block == block_attack)
			{
				answer = 0;
				return;
			}
			for (int i = 0; i < W; i++) {
				
				for (int j = H - 1; j >= 0; j--) {
					if (buf_map[j][i] == 0) {
						int a = 1;
						while (j - a >= 0) {
							if (buf_map[j - a][i] !=0) {
								buf_map[j][i] = buf_map[j-a][i];
								buf_map[j - a][i] = 0;
								break;
							}
							a += 1;
						}
					}
				}
				
			}
		}
		if (block-block_attack < answer)
			answer = block-block_attack;
	}
	else {
		for (int i = 0; i < W; i++) {
			barket.push_back(i);
			recur(answer,size+1,N,W,H,barket);
			barket.pop_back();
		}
	}
}
int main(void) {
	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int W, N, H,buf;
		cin >> N >> W >> H;
		block = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> buf;
				map[i][j] = buf;
				if (buf != 0)
					block += 1;
			}
		}
		int answer = 1000;
		vector<int> barket;
		recur(answer, 0, N, W, H, barket);
		cout << "#" << test + 1 << " " << answer << endl;
	}
	return 0;
}