#include <iostream>
#include <queue>
#include <exception>
using namespace std;

class Points {
public:	
	int x;
	int y;
};
void person(char** map, char color, int N,int x, int y);
void person2(char** map, char color, int N,char color2, int x,int y);
int main (void)
{
	int N,answer=0,answer2=0;
	char color;
	cin >> N;
	char **map = new char*[N];
	char **copy_map = new char*[N];
	for (int i = 0; i < N; i++)
	{
		map[i] = new char[N];
		copy_map[i] = new char[N];
		for (int j = 0; j < N; j++)
		{
			cin >> color;
			map[i][j] = color;
			copy_map[i][j] = color;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] != 'F')
			{
				person(map, map[i][j], N,i,j);
				answer += 1;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (copy_map[i][j] =='B')
			{
				person2(copy_map, copy_map[i][j], N,'B',i,j);
				answer2 += 1;
			}
			else if (copy_map[i][j] == 'R')
			{
				person2(copy_map, copy_map[i][j], N, 'G',i,j);
				answer2 += 1;
			}
			else if (copy_map[i][j] == 'G')
			{
				person2(copy_map, copy_map[i][j], N, 'R',i,j);
				answer2 += 1;
			}
		}
	}

	cout << answer << ' ' << answer2;
	return 0;
}
void person(char** map, char color,int N,int x,int y)
{
	queue<Points> region;
	Points p;
	p.x = x;	p.y = y;
	region.push(p);
	map[0][0] = 'F';
	while (region.size() != 0)
	{
		Points point;
		point = region.front();
		region.pop();

		//try {
		
			if (point.x + 1 == N) {}
			else if(map[point.x + 1][point.y] == color)
			{
				map[point.x + 1][point.y] = 'F';
				Points newp;
				newp.x = point.x + 1;	newp.y = point.y;
				region.push(newp);
			}
			if (point.x - 1 == -1) {}
			else if (map[point.x - 1][point.y] == color)
			{
				map[point.x - 1][point.y] = 'F';
				Points newp;
				newp.x = point.x - 1;	newp.y = point.y;
				region.push(newp);
			}
			if (point.y+ 1 == N) {}
			else if (map[point.x][point.y + 1] == color)
			{
				map[point.x][point.y + 1] = 'F';
				Points newp;
				newp.x = point.x;	newp.y = point.y + 1;
				region.push(newp);
			}
			if (point.y - 1 == -1) {}
			else if (map[point.x][point.y - 1] == color)
			{
				map[point.x][point.y - 1] = 'F';
				Points newp;
				newp.x = point.x;	newp.y = point.y - 1;
				region.push(newp);
			}
		
	}
		//catch (system:IndexOutOfRangeException e) {
	//		continue;
	//	}
		
	//}
}
void person2(char** map, char color, int N,char color2,int x,int y)
{
	queue<Points> region;
	Points p;
	p.x = x;	p.y = y;
	region.push(p);
	map[0][0] = 'F';
	while (region.size() != 0)
	{
		Points point;
		point = region.front();
		region.pop();

		
		
			if (point.x + 1 == N) {}

			else if (map[point.x + 1][point.y] == color || map[point.x + 1][point.y] == color2)
			{
				map[point.x + 1][point.y] = 'F';
				Points newp;
				newp.x = point.x + 1;	newp.y = point.y;
				region.push(newp);
			}
			if (point.x - 1 == -1) {}
			else if (map[point.x - 1][point.y] == color || map[point.x - 1][point.y] == color2)
			{
				map[point.x - 1][point.y] = 'F';
				Points newp;
				newp.x = point.x - 1;	newp.y = point.y;
				region.push(newp);
			}
			if (point.y + 1 == N) {}
			else if (map[point.x][point.y + 1] == color || map[point.x][point.y + 1] == color2)
			{
				map[point.x][point.y + 1] = 'F';
				Points newp;
				newp.x = point.x;	newp.y = point.y + 1;
				region.push(newp);
			}
			if (point.y - 1 == -1) {}
			else if (map[point.x][point.y - 1] == color || map[point.x][point.y - 1] == color2)
			{
				map[point.x][point.y - 1] = 'F';
				Points newp;
				newp.x = point.x;	newp.y = point.y - 1;
				region.push(newp);
			}
		
		

	}
}