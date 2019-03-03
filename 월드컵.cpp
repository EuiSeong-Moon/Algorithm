#include<iostream>

using namespace std;

int world[6][3];
int flag[6];

//미리 정해두는 g1,g2가 핵심함수.. 인터넷참조했음 꼭 다시 확인.
int g1[15] = { 0,0,0,0,0,1,1,1,1,2,2,2,3,3,4 };
int g2[15] = { 1,2,3,4,5,2,3,4,5,3,4,5,4,5,5 };

void recur(int current, int round,int& flags) {
	if (flags == 1)
		return;
	if (round == 15)
	{
		cout << "1 ";
		flags = 1;
		return;
	}
	else {
		if (world[g1[current]][0] > 0) {
			if (world[g2[current]][2] > 0)
			{
				world[g1[current]][0] -= 1;
				world[g2[current]][2] -= 1;
				recur(current + 1, round+1, flags);
				world[g1[current]][0] += 1;
				world[g2[current]][2] += 1;
			}
		}
		if (world[g1[current]][1] > 0) {
			if (world[g2[current]][1] > 0) {
				world[g1[current]][1] -= 1;
				world[g2[current]][1] -= 1;
				recur(current + 1, round+1, flags);
				world[g1[current]][1] += 1;
				world[g2[current]][1] += 1;
			}
		}
		if (world[g1[current]][2] > 0) {
			if (world[g2[current]][0] > 0) {
				world[g1[current]][2] -= 1;
				world[g2[current]][0] -= 1;
				recur(current + 1, round+1, flags);
				world[g1[current]][2] += 1;
				world[g2[current]][0] += 1;
			}
		}
	}
}
int main(void) {
	int buf;
	
	for (int test = 0; test < 4; test++) {
		int w = 0, l = 0, b = 0;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> buf;
				world[i][j] = buf;
				switch (j) {
				case 0:
					w += buf;
					break;
				case 1:
					b += buf;
					break;
				case 2:
					l += buf;
					break;
				}
			}
		}
	int current = 0;
	int flags = 0;
	if (w + b + l != 30)
	{
		flags = 0;
	}
	else {
		if (world[g1[current]][0] > 0) {
			if (world[g2[current]][2] > 0)
			{
				world[g1[current]][0] -= 1;
				world[g2[current]][2] -= 1;
				recur(current + 1, 1, flags);
				world[g1[current]][0] += 1;
				world[g2[current]][2] += 1;
			}
		}
		if (world[g1[current]][1] > 0) {
			if (world[g2[current]][1] > 0) {
				world[g1[current]][1] -= 1;
				world[g2[current]][1] -= 1;
				recur(current + 1, 1, flags);
				world[g1[current]][1] += 1;
				world[g2[current]][1] += 1;
			}
		}
		if (world[g1[current]][2] > 0) {
			if (world[g2[current]][0] > 0) {
				world[g1[current]][2] -= 1;
				world[g2[current]][0] -= 1;
				recur(current + 1, 1, flags);
				world[g1[current]][2] += 1;
				world[g2[current]][0] += 1;
			}
		}
	}
	if(flags==0)
		cout << "0 ";
	}
	return 0;
}