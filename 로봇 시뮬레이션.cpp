#include<iostream>
#include<vector>

using namespace std;

int map[100][100] = { 0, };

class Robot {
public:
	pair<int, int> pos;
	char direct;
};

int main(void)
{
	int A, B, N, M,buf1,buf2;
	char buf3;
	cin >> A >> B;
	cin >> N >> M;
	vector<Robot> barket;
	for (int i = 0; i < N; i++) {
		Robot r;
		cin >> buf1 >> buf2 >> buf3;
		r.pos.first = B - buf2;
		r.pos.second = buf1 - 1;
		map[B - buf2][buf1 - 1] = 1;
		r.direct = buf3;
		barket.push_back(r);
	}
	//i의 최대는 B-1 j의 최대는 A-1
	for (int i = 0; i < M; i++) {
		cin >> buf1 >> buf3 >> buf2;
		Robot r = barket.at(buf1 - 1);
		if (buf3 == 'F') {
			switch (r.direct) {
			case 'E':
				for (int j = 0; j < buf2; j++) {
					map[r.pos.first][r.pos.second] = 0;
					r.pos.second += 1;
					if (r.pos.second >= A)
					{
						//맵 넘어가기
					
						cout << "Robot " << buf1 << " crashes into the wall" << endl;
						return 0;
					}
					else if (map[r.pos.first][r.pos.second] == 1)
					{
						//충돌
						int count;
						for (int c = 0; c < barket.size(); c++) {
							if (barket.at(c).pos.first == r.pos.first && barket.at(c).pos.second == r.pos.second)
							{
								count = c + 1;
								break;
							}
						}
					
						cout << "Robot " << buf1 << " crashes into robot " << count << endl;
						return 0;
					}
					else {
						map[r.pos.first][r.pos.second] = 1;
						barket.at(buf1 - 1).pos.second += 1;
					}
				}
				break;
			case 'W':
				for (int j = 0; j < buf2; j++) {
					map[r.pos.first][r.pos.second] = 0;
					r.pos.second -= 1;
					if (r.pos.second < 0)
					{
						//맵 넘어가기
						cout << "Robot " << buf1 << " crashes into the wall" << endl;
						return 0;
					}
					else if (map[r.pos.first][r.pos.second] == 1)
					{
						//충돌
						int count;
						for (int c = 0; c < barket.size(); c++) {
							if (barket.at(c).pos.first == r.pos.first && barket.at(c).pos.second == r.pos.second)
							{
								count = c + 1;
								break;
							}
						}
						cout << "Robot " << buf1 << " crashes into robot " << count << endl;
						return 0;
					}
					else {
						map[r.pos.first][r.pos.second] = 1;
						barket.at(buf1 - 1).pos.second -= 1;
					}
				}
				break;
			case 'S':
				for (int j = 0; j < buf2; j++) {
					map[r.pos.first][r.pos.second] = 0;
					r.pos.first += 1;
					if (r.pos.first >= B)
					{
						//맵 넘어가기
						cout << "Robot " << buf1 << " crashes into the wall" << endl;
						return 0;
					}
					else if (map[r.pos.first][r.pos.second] == 1)
					{
						//충돌
						int count;
						for (int c = 0; c < barket.size(); c++) {
							if (barket.at(c).pos.first == r.pos.first && barket.at(c).pos.second == r.pos.second)
							{
								count = c + 1;
								break;
							}
						}
						cout << "Robot " << buf1 << " crashes into robot " << count << endl;
						return 0;
					}
					else {
						map[r.pos.first][r.pos.second] = 1;
						barket.at(buf1 - 1).pos.first += 1;
					}
				}
				break;
			case 'N':
				for (int j = 0; j < buf2; j++) {
					map[r.pos.first][r.pos.second] = 0;
					r.pos.first -= 1;
					if (r.pos.first < 0)
					{
						//맵 넘어가기
						cout << "Robot " << buf1 << " crashes into the wall" << endl;
						return 0;
					}
					else if (map[r.pos.first][r.pos.second] == 1)
					{
						//충돌
						int count;
						for (int c = 0; c < barket.size(); c++) {
							if (barket.at(c).pos.first == r.pos.first && barket.at(c).pos.second == r.pos.second)
							{
								count = c + 1;
								break;
							}
						}
						cout << "Robot " << buf1 << " crashes into robot " << count << endl;
						return 0;
					}
					else {
						map[r.pos.first][r.pos.second] = 1;
						barket.at(buf1 - 1).pos.first -= 1;
					}
				}
				break;
			}
		}
		else if (buf3 == 'L') {
			int count = buf2 % 4;
			for (int k = 0; k < count; k++) {
				switch (r.direct)
				{
				case 'E':
					r.direct = 'N';
					break;
				case 'W':
					r.direct = 'S';
					break;
				case 'S':
					r.direct = 'E';
					break;
				case 'N':
					r.direct = 'W';
					break;
				}
			}
			barket.at(buf1 - 1).direct = r.direct;
		}
		else if (buf3 == 'R') {
			int count = buf2 % 4;
			for (int k = 0; k < count; k++) {
				switch (r.direct)
				{
				case 'E':
					r.direct = 'S';
					break;
				case 'W':
					r.direct = 'N';
					break;
				case 'S':
					r.direct = 'W';
					break;
				case 'N':
					r.direct = 'E';
					break;
				}
			}
			barket.at(buf1 - 1).direct = r.direct;
		}
	}
	cout << "OK" << endl;
	return 0;
}