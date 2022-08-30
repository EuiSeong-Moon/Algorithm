#include <iostream>
#include <vector>

using namespace std;
class Points {
public:
	int xpos;
	int ypos;
};
int line[31][11];

int compare(int flag, int H, int N)
{
	for (int i = 1; i <= H; i++)
	{
		if (line[i][flag] == 1)
		{
			flag++;
		}
		else if (flag > 1 && line[i][flag - 1] == 1)
			flag--;
	}
	return flag;
}
void add_line(int i_index, int j_index, int H, int N, int& size, int& answer) {	//1,1~H,N
																				//계산
	for (int i = 1; i <= N; i++)
	{
		int result = compare(i, H, N);
		if (result != i)
			break;
		if (i == N)
		{
			if (size < answer)
				answer = size;
		}
	}
	if (size == 3)
	{
		//size -= 1;
	}
	else {
		for (int i = i_index; i < H+1; i++)
		{
			for (int j = j_index; j < N; j++)
			{
				if (line[i][j] == 0 && line[i][j - 1] == 0 && line[i][j + 1] == 0)
				{
					//라인추가
					line[i][j] = 1;
					size += 1;
					add_line(i, j + 1, H, N, size, answer);
					line[i][j] = 0;
					size -= 1;
				}
			}
			j_index = 1;
		}
	}
}
int main(void)
{
	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			//if (1 <= i && i <= 30 && 1 <= j && j <= 10)
				line[i][j] = 0;
			//else
				//line[i][j] = -1;
		}
	}
	int N, M, H, buf1, buf2, answer = 5;
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		cin >> buf1 >> buf2;
		line[buf1][buf2] = 1;
	}
	int size = 0;
	add_line(1, 1, H, N, size, answer);
	if (answer == 5)
		cout << "-1" << endl;
	else
		cout << answer << endl;
	return 0;
}