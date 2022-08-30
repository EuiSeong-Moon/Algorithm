#include<iostream>

using namespace std;
char map[10][10];

class Points {
public:
	int xpos;
	int ypos;
};
int rotation(char map[10][10], int direct, int count, int& answer, Points red, Points blue, int N, int M);
int main(void)
{
	int M, N;
	cin >> N >> M;
	char buf;
	Points red;
	Points blue;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> buf;	
			if (buf=='B')	//map�� �ϳ��� ����ϵ� �������� �Ķ����� ��ġ�� �����ؼ� ������.
			{
				blue.xpos = i;
				blue.ypos = j;
				map[i][j] = '.';
			}
			else if (buf == 'R')
			{
				red.xpos = i;
				red.ypos = j;
				map[i][j] = '.';
			}
			else
				map[i][j] = buf;
		}
	}//�Ʒ�	2����	3��	4����
	int answer = -1;
	rotation(map, 1,1,answer,red,blue,N,M);
	rotation(map, 2, 1, answer, red, blue, N, M);
	rotation(map, 3, 1, answer, red, blue, N, M);
	rotation(map, 4, 1, answer, red, blue, N, M);
	cout << answer;
	return 0;
}
int rotation(char map[10][10], int direct,int count,int& answer,Points red,Points blue,int N,int M){
	//ȸ��
	Points newred;
	Points newblue;
	newblue.xpos = 0;
	newblue.ypos = 0;
	int collision = 0;
	//int exception = 0;
	switch (direct)
	{
	case 1:	//�Ʒ�
		for (int i = blue.xpos+1; i < N; i++)	//�Ķ����� ���� ��� �浹 �ô� collision�� ���ؼ� ó��
		{
			if (map[i][blue.ypos] == '#')
			{
				newblue.xpos = i - 1;
				newblue.ypos = blue.ypos;
				break;
			}
			else if (map[i][blue.ypos] == 'O')
				return -1;
			else if (i==red.xpos && blue.ypos==red.ypos)
			{
				collision = 1;	//exception = 1;
				break;
			}
		}
		for (int i = red.xpos + 1; i < N; i++)
		{
			if (map[i][red.ypos] == '#')
			{
				newred.xpos = i - 1;
				newred.ypos = red.ypos;
				break;
			}
			else if (map[i][red.ypos] == 'O')
			{
				if (collision == 1)	//�����⵿
					return -1;
				if (answer < 0)
					answer = count;
				else if (answer > count)
					answer = count;
				return 1;
			}
			else if (i==newblue.xpos && red.ypos==newblue.ypos)
			{
				newred.xpos = newblue.xpos - 1;
				newred.ypos = red.ypos;
				break;
			}
		}
		if (collision == 1)
		{
			
			newblue.xpos = newred.xpos - 1;
			newblue.ypos = blue.ypos;
		
		}
		if (newred.xpos == newblue.xpos && newred.ypos == newblue.ypos)
			return -2;
		break;
	case 2:	//����
		for (int i = blue.ypos + 1; i < M; i++)
		{
			if (map[blue.xpos][i] == '#')
			{
				newblue.ypos = i - 1;
				newblue.xpos = blue.xpos;
				break;
			}
			else if (map[blue.xpos][i] == 'O')
				return -1;
			else if (blue.xpos==red.xpos && i == red.ypos)
			{
				collision = 1;	
				break;
			}
		}
		for (int i = red.ypos + 1; i < M; i++)
		{
			if (map[red.xpos][i] == '#')
			{
				newred.ypos = i - 1;
				newred.xpos = red.xpos;
				break;
			}
			else if (map[red.xpos][i] == 'O')
			{
				if (collision == 1)
					return -1;
				if (answer < 0)
					answer = count;
				else if (answer > count)
					answer = count;
				return 1;
			}
			else if (red.xpos==newblue.xpos && i==newblue.ypos)
			{
				newred.xpos = red.xpos;
				newred.ypos = newblue.ypos-1;
				break;
			}
		}
		if (collision == 1)
		{
			newblue.xpos = blue.xpos;
			newblue.ypos = newred.ypos-1;
			
		}
		if (newred.xpos == newblue.xpos && newred.ypos == newblue.ypos)
			return -2;
		break;
	case 3:	//��
		for (int i = blue.xpos - 1; i >= 0; i--)
		{
			if (map[i][blue.ypos] == '#' )
			{
				newblue.xpos = i + 1;
				newblue.ypos = blue.ypos;
				break;
			}
			else if (map[i][blue.ypos] == 'O')
				return -1;
			else if (i==red.xpos && blue.ypos==red.ypos)
			{
				collision = 1;	
				break;
			}
		}
		for (int i = red.xpos - 1; i >= 0; i--)
		{
			if (map[i][red.ypos] == '#')
			{
				newred.xpos = i + 1;
				newred.ypos = red.ypos;
				break;
			}
			else if (map[i][red.ypos] == 'O')
			{
				if (collision == 1)
					return -1;
				if (answer < 0)
					answer = count;
				else if (answer > count)
					answer = count;
				return 1;
			}
			else if (i==newblue.xpos && red.ypos==newblue.ypos)
			{
				newred.xpos = newblue.xpos + 1;
				newred.ypos = red.ypos;
				break;
			}
		}
		if (collision == 1)
		{
			newblue.xpos = newred.xpos + 1;
			newblue.ypos = blue.ypos;
		}
		
		break;
	case 4: //����
		for (int i = blue.ypos -1 ; i >=0; i--)
		{
			if (map[blue.xpos][i] == '#' )
			{
				newblue.xpos = blue.xpos;
				newblue.ypos = i+1;
				break;
			}
			else if (map[blue.xpos][i] == 'O')
				return -1;
			else if (blue.xpos==red.xpos && i==red.ypos)
			{
				collision = 1;	
				break;
			}
		}
		for (int i = red.ypos - 1; i >= 0; i--)
		{
			if (map[red.xpos][i] == '#')
			{
				newred.xpos = red.xpos;
				newred.ypos = i+1;
				break;
			}
			else if (map[red.xpos][i] == 'O')
			{
				if (collision == 1)
					return -1;
				if (answer < 0)
					answer = count;
				else if (answer > count)
					answer = count;
				return 1;
			}
			else if (red.xpos==newblue.xpos && i==newblue.ypos)
			{
				newred.xpos = red.xpos;
				newred.ypos = newblue.ypos + 1;
				break;
			}
		}
		if (collision == 1)
		{
			newblue.xpos = blue.xpos;
			newblue.ypos = newred.ypos + 1;

		}
		
		break;
	}
	
	if (count == 10)
		return -1;
	else	//��͸� ���� count ����
	{
		for (int i = 1; i <= 4; i++)
		{
			if (i != direct)
			{
				if (newblue.xpos < 0)
					int data = 0;
				rotation(map, i, count + 1, answer, newred, newblue, N, M);
			}
		}
	}
	return 0;
}