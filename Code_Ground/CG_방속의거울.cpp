/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;
void going(int **map, int& answer, int& direct, int& i, int& j, bool **flag);
int Answer;
int finish;
//int map[1002][1002] = { 0, };
//bool flag[1002][1002] = { false, };
int main(int argc, char** argv)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N,buf;
		cin >> N;
		int **map = new int*[N + 2];
		bool **flag = new bool*[N + 2];
		for (int i = 0; i < N + 2; i++)
		{
			map[i] = new int[N + 2];
			flag[i] = new bool[N + 2];
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++) {
				scanf("%1d", &buf);
				//cin >> buf;
				if (buf == 0)
					map[i][j] = -1;
				else
					map[i][j] = buf;
			}
		}
		Answer = 0;
		finish = 0;

		int xpos = 1;
		int ypos = 1;
		int init_direct = 3;
		while (finish == 0)
		{
			going(map, Answer, init_direct, xpos, ypos, flag);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
		/*for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				map[i][j] = 0;
				flag[i][j] = false;
			}
		}*/
	}

	return 0;//Your program should return 0 on normal termination.
}
void going(int **map,int& answer,int& direct,int& i,int& j,bool **flag)
{
	switch(direct)
	{
	case 1:
		if (map[i][j] == 1)
		{
			if (flag[i][j] != true)
			{
				answer += 1;
				flag[i][j] = true;
			}
			direct = 4;	i = i + 1;
		}
		else if (map[i][j] == 2)
		{
			if (flag[i][j] != true)
			{
				answer += 1;
				flag[i][j] = true;
			}
			direct = 2;	i = i - 1;
		}
		else if (map[i][j] == -1)
		{
			j = j - 1;
		}
		else
			finish = 1;
		break;
	case 2:
		if (map[i][j] == 1)
		{
			if (flag[i][j] != true)
			{
				answer += 1;
				flag[i][j] = true;
			}
			direct = 3;	j = j + 1;
		}
		else if (map[i][j] == 2)
		{
			if (flag[i][j] != true)
			{
				answer += 1;
				flag[i][j] = true;
			}
			direct = 1;	j =j - 1;
		}
		else if (map[i][j] == -1)
		{
			i = i - 1;
		}
		else
			finish = 1;
		break;
	case 3:
		if (map[i][j] == 1)
		{
			if (flag[i][j] != true)
			{
				answer += 1;
				flag[i][j] = true;
			}
			direct = 2;	i = i - 1;
		}
		else if (map[i][j] == 2)
		{
			if (flag[i][j] != true)
			{
				answer += 1;
				flag[i][j] = true;
			}
			direct = 4;	i = i + 1;
		}
		else if (map[i][j] == -1)
		{
			j = j + 1;
		}
		else
			finish = 1;
		break;
	case 4:
		if (map[i][j] == 1)
		{
			if (flag[i][j] != true)
			{
				answer += 1;
				flag[i][j] = true;
			}
			direct = 1;	j = j - 1;
		}
		else if (map[i][j] == 2)
		{
			if (flag[i][j] != true)
			{
				answer += 1;
				flag[i][j] = true;
			}
			direct = 3;	j = j + 1;
		}
		else if (map[i][j] == -1)
		{
			i = i + 1;
		}
		else
			finish = 1;
		break;
	}
}