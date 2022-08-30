#include <iostream>
#include <vector>

using namespace std;

int diagram[6] = { 0, };
int flag[6]={ 0,1,2,3,4,5 };
int map[22][22];
int main(void)
{
	int N, M, K, x, y,buf;
	cin >> N >> M >> x >> y >> K;
	x++;	y++;
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 22; j++)
			map[i][j] = -1;
	}
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			cin >> buf;
			map[i][j] = buf;
		}
	}

	for (int i = 0; i < K; i++)
	{
		cin >> buf;
		switch (buf)
		{
		case 1:
			if (map[x][y + 1] != -1)
			{
				
				int new_flag[6];
				for (int k = 0; k < 6; k++)
				{
					if (flag[k] == 0)
						new_flag[k] = 5;
					if (flag[k] == 1)
						new_flag[k] = 1;
					if (flag[k] == 2)
						new_flag[k] = 4;
					if (flag[k] == 3)
						new_flag[k] = 3;
					if (flag[k] == 4)
						new_flag[k] = 0;
					if (flag[k] == 5)
						new_flag[k] = 2;
				}
				memcpy(flag, new_flag, sizeof(new_flag));
				int b;
				for (int k = 0; k < 6; k++)
				{
					if (flag[k] == 0)
					{
						b = k;
						break;
					}
				}
				if (map[x][y + 1] != 0) {
					int f;
					for (int k = 0; k < 6; k++)
					{
						if (flag[k] == 2)
						{
							f = k;
							break;
						}
					}
					diagram[f] = map[x][y + 1];
					map[x][y + 1] = 0;
				}
				else {
					int f;
					for (int k = 0; k < 6; k++)
					{
						if (flag[k] == 2)
						{
							f = k;
							break;
						}
					}
					map[x][y + 1] = diagram[f];
				}
				cout << diagram[b] << endl;
				y = y + 1;
			}
			break;
		case 2:
			if (map[x][y - 1] != -1)
			{
				int new_flag[6];
				for (int k = 0; k < 6; k++)
				{
					if (flag[k] == 0)
						new_flag[k] = 4;
					if (flag[k] == 1)
						new_flag[k] = 1;
					if (flag[k] == 2)
						new_flag[k] = 5;
					if (flag[k] == 3)
						new_flag[k] = 3;
					if (flag[k] == 4)
						new_flag[k] = 2;
					if (flag[k] == 5)
						new_flag[k] = 0;
				}
				memcpy(flag, new_flag, sizeof(new_flag));
				int b;
				for (int k = 0; k < 6; k++)
				{
					if (flag[k] == 0)
					{
						b = k;
						break;
					}
				}
				int f;
				for (int k = 0; k < 6; k++)
				{
					if (flag[k] == 2)
					{
						f = k;
						break;
					}
				}
				if (map[x][y - 1] != 0)
				{
					diagram[f] = map[x][y - 1];
					map[x][y - 1] = 0;
				}
				else {
					map[x][y - 1] = diagram[f];
				}
				cout << diagram[b] << endl;
				y = y - 1;
			}
			break;
		case 3:
			if (map[x - 1][y] != -1)
			{
				int new_flag[6];
				for (int k = 0; k < 6; k++)
				{
					if (flag[k] == 0)
						new_flag[k] = 3;
					if (flag[k] == 1)
						new_flag[k] = 0;
					if (flag[k] == 2)
						new_flag[k] = 1;
					if (flag[k] == 3)
						new_flag[k] = 2;
					if (flag[k] == 4)
						new_flag[k] = 4;
					if (flag[k] == 5)
						new_flag[k] = 5;
				}
				memcpy(flag, new_flag, sizeof(new_flag));
				int b;
				for (int k = 0; k < 6; k++)
				{
					if (flag[k] == 0)
					{
						b = k;
						break;
					}
				}
				int f;
				for (int k = 0; k < 6; k++)
				{
					if (flag[k] == 2)
					{
						f = k;
						break;
					}
				}
				if (map[x - 1][y] != 0) {
					diagram[f] = map[x - 1][y];
					map[x - 1][y] = 0;
				}
				else {
					map[x - 1][y] = diagram[f];
				}
				cout << diagram[b] << endl;
				x = x - 1;
			}
			break;
		case 4:
			if (map[x + 1][y] != -1) {
				int new_flag[6];
				for (int k = 0; k < 6; k++)
				{
					if (flag[k] == 0)
						new_flag[k] = 1;
					if (flag[k] == 1)
						new_flag[k] = 2;
					if (flag[k] == 2)
						new_flag[k] = 3;
					if (flag[k] == 3)
						new_flag[k] = 0;
					if (flag[k] == 4)
						new_flag[k] = 4;
					if (flag[k] == 5)
						new_flag[k] = 5;
				}
				memcpy(flag, new_flag, sizeof(new_flag));
				int b;
				for (int k = 0; k < 6; k++)
				{
					if (flag[k] == 0)
					{
						b = k;
						break;
					}
				}
				int f;
				for (int k = 0; k < 6; k++)
				{
					if (flag[k] == 2)
					{
						f = k;
						break;
					}
				}
				if (map[x + 1][y] != 0) {
					diagram[f] = map[x + 1][y];
					map[x + 1][y] = 0;
				}
				else {
					map[x + 1][y] = diagram[f];
				}
				cout << diagram[b] << endl;
				x = x + 1;
			}
			break;
		}
	}
	return 0;
}