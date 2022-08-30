#include<iostream>
#include<queue>

using namespace std;

class Point {
public:
	int pos;
	int time;
};
bool flag[100000] = { false, };
int dr[] = { 1,-1,1 };
int main(void) {
	int N, K;
	cin >> N >> K;
	Point s_p;	s_p.pos = N;	s_p.time = 0;
	queue<Point> barket;
	barket.push(s_p);
	while (barket.size() != 0) {
		Point pt;
		pt = barket.front();	barket.pop();
		if (pt.pos == K)
		{
			cout << pt.time << endl;
			return 0;
		}
		for (int m = 0; m < 3; m++) {
			int nr;
			if (m == 2) {
				nr = pt.pos * 2;
			}
			else {
				nr = dr[m] + pt.pos;
			}
			if (nr < 0 || nr>100000)
				continue;
			if (flag[nr] == true)
				continue;
			flag[nr] = true;
			Point new_pt;	new_pt.pos = nr;	new_pt.time = pt.time + 1;
			barket.push(new_pt);
		}
	}
	return 0;
}