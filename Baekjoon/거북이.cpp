#include<iostream>
#include<string>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		pair<int, int> pos(0, 0);
		int east = 0, west = 0, north = 0, south = 0;
		int direction = 4;
		string commands;
		cin >> commands;
		for (int i = 0; i < commands.size(); i++) {
			if (commands.at(i) == 'F') {
				switch(direction) {
				case 1:
					pos.first += 1;
					if (pos.first > east)
						east = pos.first;
					break;
				case 2:
					pos.second -= 1;
					if (pos.second < south)
						south = pos.second;
					break;
				case 3:
					pos.first -= 1;
					if (pos.first < west)
						west = pos.first;
					break;
				case 4:
					pos.second += 1;
					if (pos.second > north)
						north = pos.second;
					break;
				}
			}
			else if (commands.at(i) == 'B') {
				switch (direction) {
				case 3:
					pos.first += 1;
					if (pos.first > east)
						east = pos.first;
					break;
				case 4:
					pos.second -= 1;
					if (pos.second < south)
						south = pos.second;
					break;
				case 1:
					pos.first -= 1;
					if (pos.first < west)
						west = pos.first;
					break;
				case 2:
					pos.second += 1;
					if (pos.second > north)
						north = pos.second;
					break;
				}
			}
			else if (commands.at(i) == 'L') {
				switch (direction) {
				case 1:
					direction = 4;
					break;
				case 2:
					direction = 1;
					break;
				case 3:
					direction = 2;
					break;
				case 4:
					direction = 3;
					break;
				}
			}
			else if (commands.at(i) == 'R') {
				switch (direction) {
				case 1:
					direction = 2;
					break;
				case 2:
					direction = 3;
					break;
				case 3:
					direction = 4;
					break;
				case 4:
					direction = 1;
					break;
				}
			}
		}
		cout << (east - west)*(north - south) << endl;
	}
	return 0;
}