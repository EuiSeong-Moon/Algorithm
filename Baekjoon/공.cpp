#include<iostream>
using namespace std;

int main(void) {
	int M;
	cin >> M;
	int X, Y, ball = 1;
	for (int i = 0; i < M; i++) {
		cin >> X >> Y;
		if (X == ball)
		{
			ball = Y;
		}
		else if (Y == ball) {
			ball = X;
		}
	}
	if (1 <= ball && ball <= 3)
		cout << ball << endl;
	else
		cout << "-1" << endl;
	return 0;
}