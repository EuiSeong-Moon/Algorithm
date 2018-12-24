#include <iostream>
#include <vector>
using namespace std;


int answer;
class Cam {
public:
	int xpos;
	int ypos;
	int status;
	int size;
};
int whatsize(int buf)
{
	if (buf == 2)
		return 2;
	else if (buf == 5)
		return 1;
	else
		return 4;
}
void drawing(Cam c, int state,int** maps,int N,int M)
{
	int i = c.xpos;
	int j = c.ypos;
	switch (c.status)
	{
	//	int i = c.xpos, j=c.ypos;
	case 1:
		switch (state)
		{
		case 1:	//1
		
			j++;
			if (j == M)
				break;
			while (j < M && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j]==1) || (maps[i][j]==2) || (maps[i][j]==3) || (maps[i][j]==4) || (maps[i][j]==5))
			{
				if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{
					j++;
					if (j == M)
						break;
					continue;
				}
				maps[i][j] = 7;
				j++;
				if (j == M)
					break;
			}
			break;
		case 2:	//2
			i++;
			if (i == N)
				break;
			while (i < N && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
			{

				if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{
					i++;
					if (i == N)
						break;
					continue;
				}
				maps[i][j] = 7;
				i++;
				if (i == N)
					break;
			}
			break;
		case 3:	//3
			j--;
			if (j == -1)
				break;
			while (j >= 0 && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
			{

				if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{
					j--;
					if (j == -1)
						break;
					continue;
				}
				maps[i][j] = 7;
				j--;
				if (j == -1)
					break;
			}
			break;
		case 4:	//4
			i--;
			if (i == -1)
				break;
			while (i >= 0 && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
			{

				if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{
					i--;
					if (i == -1)
						break;
					continue;
				}
				maps[i][j] = 7;
				i--;
				if (i == -1)
					break;
			}
			break;
		}
		break;
	case 2:
		switch (state)
		{
		case 1:
			j++;
			if (j != M)
			{
				while (j < M && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{

					if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
					{
						j++;
						if (j == M)
							break;
						continue;
					}
					maps[i][j] = 7;
					j++;
					if (j == M)
						break;
				}
			}
			j = c.ypos;
			j--;
			if (j == -1)
				break;
			while (j >= 0 && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
			{

				if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{
					j--;
					if (j == -1)
						break;
					continue;
				}
				maps[i][j] = 7;
				j--;
				if (j == -1)
					break;
			}
			break;
		case 2:
			i++;
			if (i != N)
			{
				while (i < N && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{

					if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
					{
						i++;
						if (i == N)
							break;
						continue;
					}
					maps[i][j] = 7;
					i++;
					if (i == N)
						break;
				}
			}
			i = c.xpos;
			i--;
			if (i == -1)
				break;
			while (i >= 0 && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
			{

				if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{
					i--;
					if (i == -1)
						break;
					continue;
				}
				maps[i][j] = 7;
				i--;
				if (i == -1)
					break;
			}
			break;
		}
		break;
	case 3:
		switch (state)
		{
		case 1:
			j++;
			if (j != M)
			{
				while (j < M && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{

					if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
					{
						j++;
						if (j == M)
							break;
						continue;
					}
					maps[i][j] = 7;
					j++;
					if (j == M)
						break;
				}
			}
			j = c.ypos;
			i--;
			if (i == -1)
				break;
			while (i >= 0 && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
			{

				if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{
					i--;
					if (i == -1)
						break;
					continue;
				}
				maps[i][j] = 7;
				i--;
				if (i == -1)
					break;
			}
			break;
		case 2:
			j++;
			if (j != M)
			{
				while (j < M && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{

					if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
					{
						j++;
						if (j == M)
							break;
						continue;
					}
					maps[i][j] = 7;
					j++;
					if (j == M)
						break;
				}
			}
			j = c.ypos;
			i++;
			if (i == N)
				break;
			while (i < N && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
			{

				if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{
					i++;
					if (i == N)
						break;
					continue;
				}
				maps[i][j] = 7;
				i++;
				if (i == N)
					break;
			}
			break;
		case 3:
			i++;
			if (i != N)
			{
				while (i < N && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{

					if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
					{
						i++;
						if (i == N)
							break;
						continue;
					}
					maps[i][j] = 7;
					i++;
					if (i == N)
						break;
				}
			}
			i = c.xpos;
			j--;
			if (j == -1)
				break;
			while (j >= 0 && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
			{

				if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{
					j--;
					if (j == -1)
						break;
					continue;
				}
				maps[i][j] = 7;
				j--;
				if (j == -1)
					break;
			}
			break;
		case 4:
			j--;
			if (j != -1)
			{
				while (j >= 0 && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{

					if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
					{
						j--;
						if (j == -1)
							break;
						continue;
					}
					maps[i][j] = 7;
					j--;
					if (j == -1)
						break;
				}
			}
			j = c.ypos;
			i--;
			if (i == -1)
				break;
			while (i >= 0 && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
			{

				if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{
					i--;
					if (i == -1)
						break;
					continue;
				}
				maps[i][j] = 7;
				i--;
				if (i == -1)
					break;
			}
			break;
		}
		break;
	case 4:
		switch (state)
		{
		case 1:
			j++;
			if (j != M)
			{
				while (j < M && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{

					if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
					{
						j++;
						if (j == M)
							break;
						continue;
					}
					maps[i][j] = 7;
					j++;
					if (j == M)
						break;
				}
			}
			j = c.ypos;
			j--;
			if (j != -1)
			{
				while (j >= 0 && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{

					if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
					{
						j--;
						if (j == -1)
							break;
						continue;
					}
					maps[i][j] = 7;
					j--;
					if (j == -1)
						break;
				}
			}
			j = c.ypos;
			i--;
			if (i != -1)
			{
				while (i >= 0 && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{

					if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
					{
						i--;
						if (i == -1)
							break;
						continue;
					}
					maps[i][j] = 7;
					i--;
					if (i == -1)
						break;
				}
			}
			break;
		case 2:
			j++;
			if (j != M)
			{
				while (j < M && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{

					if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
					{
						j++;
						if (j == M)
							break;
						continue;
					}
					maps[i][j] = 7;
					j++;
					if (j == M)
						break;
				}
			}
			j = c.ypos;
			i++;
			if (i != N)
			{
				while (i < N && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{

					if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
					{
						i++;
						if (i == N)
							break;
						continue;
					}
					maps[i][j] = 7;
					i++;
					if (i == N)
						break;
				}
			}
			i = c.xpos;
			i--;
			if (i == -1)
				break;
			while (i >= 0 && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
			{

				if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{
					i--;
					if (i == -1)
						break;
					continue;
				}
				maps[i][j] = 7;
				i--;
				if (i == -1)
					break;
			}
			break;
		case 3:
			j++;
			if (j != M)
			{
				while (j < M && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{

					if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
					{
						j++;
						if (j == M)
							break;
						continue;
					}
					maps[i][j] = 7;
					j++;
					if (j == M)
						break;
				}
			}
			j = c.ypos;
			i++;
			if (i != N)
			{
				while (i < N && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{

					if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
					{
						i++;
						if (i == N)
							break;
						continue;
					}
					maps[i][j] = 7;
					i++;
					if (i == N)
						break;
				}
			}
			i = c.xpos;
			j--;
			if (j != -1)
			{
				while (j >= 0 && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{

					if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
					{
						j--;
						if (j == -1)
							break;
						continue;
					}
					maps[i][j] = 7;
					j--;
					if (j == -1)
						break;
				}
			}
			j = c.ypos;
			break;
		case 4:
			i++;
			if (i != N)
			{
				while (i < N && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{

					if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
					{
						i++;
						if (i == N)
							break;
						continue;
					}
					maps[i][j] = 7;
					i++;
					if (i == N)
						break;
				}
			}
			i = c.xpos;
			j--;
			if (j != -1)
			{
				while (j >= 0 && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{

					if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
					{
						j--;
						if (j == -1)
							break;
						continue;
					}
					maps[i][j] = 7;
					j--;
					if (j == -1)
						break;
				}
			}
			j = c.ypos;
			i--;
			if (i != -1)
			{
				while (i >= 0 && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{

					if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
					{
						i--;
						if (i == -1)
							break;
						continue;
					}
					maps[i][j] = 7;
					i--;
					if (i == -1)
						break;
				}
			}
			break;
		}
		break;
	case 5:
		j++;
		if (j != M)
		{
			while (j < M && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
			{

				if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{
					j++;
					if (j == M)
						break;
					continue;
				}
				maps[i][j] = 7;
				j++;
				if (j == M)
					break;
			}
		}
		j = c.ypos;
		i++;
		if (i != N)
		{
			while (i < N && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
			{

				if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{
					i++;
					if (i == N)
						break;
					continue;
				}
				maps[i][j] = 7;
				i++;
				if (i == N)
					break;
			}
		}
		i = c.xpos;
		j--;
		if (j != -1)
		{
			while (j >= 0 && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
			{

				if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
				{
					j--;
					if (j == -1)
						break;
					continue;
				}
				maps[i][j] = 7;
				j--;
				if (j == -1)
					break;
			}
		}
		j = c.ypos;
		i--;
		if (i == -1)
			break;
		while (i >= 0 && (maps[i][j] == 0) || (maps[i][j] == 7) || (maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
		{

			if ((maps[i][j] == 1) || (maps[i][j] == 2) || (maps[i][j] == 3) || (maps[i][j] == 4) || (maps[i][j] == 5))
			{
				i--;
				if (i == -1)
					break;
				continue;
			}
			maps[i][j] = 7;
			i--;
			if (i == -1)
				break;
		}
		i = c.xpos;
		break;
	}
}
void find_answer(vector<Cam> cams,int flag,int **maps,int N,int M)
{
	for (int i = 0; i < cams.at(flag).size; i++)
	{
		int **n_maps = new int*[N];
		for (int i = 0; i < N; i++)
			n_maps[i] = new int[M];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				n_maps[i][j] = maps[i][j];
		}
		drawing(cams.at(flag), i+1,n_maps,N,M);
		if(flag!=0)
			find_answer(cams, flag - 1,n_maps,N,M);
		else
		{
			int count = 0;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (n_maps[i][j] == 0)
						count++;
				}
			}
			if (count < answer)
				answer = count;
		}
	}
}
int main(void)
{
	int M, N, buf;
	vector<Cam> Cams;
	cin >> N >> M;
	int **maps = new int*[N];
	for (int i = 0; i < N; i++)
	{
		maps[i] = new int[M];
	}
	answer = M*N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) {
			cin >> buf;
			maps[i][j] = buf;
			if (buf != 0 && buf!=6)
			{
				Cam c;
				c.xpos = i;	c.ypos = j;	c.status = buf;	c.size = whatsize(buf);
				Cams.push_back(c);
			}
		}
	}
	if (Cams.size() == 0)
	{
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (maps[i][j] == 0)
					count++;
			}
		}
		cout << count << endl;
	}
	else
	{
		find_answer(Cams, Cams.size() - 1, maps, N, M);
		cout << answer << endl;
	}
	return 0;
}