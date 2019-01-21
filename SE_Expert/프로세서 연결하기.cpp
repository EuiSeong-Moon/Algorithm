#include <iostream>
#include <vector>

using namespace std;
int map[12][12];
class Nodes {
public:
	pair<int, int> pos;
	int direct;
};
void recur(int N, int index, int sz, int line, int core, vector<Nodes> n, int& answer_c, int& answer_l) {
	for (int i = 0; i < 4; i++) {
		int k = 1;
		int flag = 0;
		int bb = answer_c - (n.size() - index);
		if (core < bb)
			break;
		switch (i) {
		case 0:
			while (k + n.at(index).pos.second <= N - 1) {
				if (map[n.at(index).pos.first][n.at(index).pos.second + k] != 0)
				{
					flag = 1;
				}
				k++;
			}
			if (flag == 0) {
				k = 1;
				core += 1;
			}
			while (k + n.at(index).pos.second <= N - 1) {
				map[n.at(index).pos.first][n.at(index).pos.second + k] = 2;
				line += 1;
				k++;
			}
			break;
		case 1:

			while (k + n.at(index).pos.first <= N - 1) {
				if (map[n.at(index).pos.first + k][n.at(index).pos.second] != 0)
					flag = 1;
				k++;
			}
			if (flag == 0)
			{
				k = 1;	core += 1;
			}
			while (k + n.at(index).pos.first <= N - 1) {
				map[n.at(index).pos.first + k][n.at(index).pos.second] = 2;
				line += 1;
				k++;
			}
			break;
		case 2:

			while (n.at(index).pos.second - k >= 0) {
				if (map[n.at(index).pos.first][n.at(index).pos.second - k] != 0)
					flag = 1;
				k++;
			}
			if (flag == 0) {
				k = 1; core += 1;
			}
			while (n.at(index).pos.second - k >= 0) {
				map[n.at(index).pos.first][n.at(index).pos.second - k] = 2;
				line += 1;
				k++;
			}
			break;
		case 3:

			while (n.at(index).pos.first - k >= 0) {
				if (map[n.at(index).pos.first - k][n.at(index).pos.second] != 0)
					flag = 1;
				k++;
			}
			if (flag == 0) {
				k = 1; core += 1;
			}
			while (n.at(index).pos.first - k >= 0) {
				map[n.at(index).pos.first - k][n.at(index).pos.second] = 2;
				line += 1;
				k++;
			}
			break;
		}
		sz++;
		if (n.size() == sz) {
			if (answer_c < core)
			{
				answer_c = core;
				answer_l = line;
			}
			else if (answer_c == core) {
				if (answer_l > line)
					answer_l = line;
			}
		}
		else {
			recur(N, index + 1, sz, line, core, n, answer_c, answer_l);
		}
		sz--;
		if (flag == 0) {
			k = 1;
			switch (i) {
			case 0:
				while (k + n.at(index).pos.second <= N - 1) {
					map[n.at(index).pos.first][n.at(index).pos.second + k] = 0;
					k++;
					line -= 1;
				}
				core -= 1;
				break;
			case 1:
				while (k + n.at(index).pos.first <= N - 1) {
					map[n.at(index).pos.first + k][n.at(index).pos.second] = 0;
					k++;
					line -= 1;
				}
				core -= 1;
				break;
			case 2:
				while (n.at(index).pos.second - k >= 0) {
					map[n.at(index).pos.first][n.at(index).pos.second - k] = 0;
					k++;
					line -= 1;
				}
				core -= 1;
				break;
			case 3:
				while (n.at(index).pos.first - k >= 0) {
					map[n.at(index).pos.first - k][n.at(index).pos.second] = 0;
					k++;
					line -= 1;
				}
				core -= 1;
				break;
			}
		}


	}
}
int main(void)
{
	int T;
	cin >> T;
	for (int test = 1; test <= T; test++)
	{
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++)
				map[i][j] = -1;
		}
		int N, buf;
		vector<Nodes> cores;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> buf;
				if (buf == 1 && i != 0 && i != N - 1 && j != 0 && j != N - 1)
				{
					Nodes n;	n.pos.first = i;	n.pos.second = j;	n.direct = 1;
					cores.push_back(n);
				}
				map[i][j] = buf;
			}
		}
		int core = 0;	int line = 10000;
		recur(N, 0, 0, 0, 0, cores, core, line);
		cout << "#" << test << " " << line << endl;
	}
	return 0;
}