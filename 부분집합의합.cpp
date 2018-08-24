#include<iostream>
#include<vector>
using namespace std;
int part_function(vector<int>& barket, int sz, int S);
int main(void)
{
	int N, S,buf,answer=0;
	cin >> N >> S;
	vector<int> barket;
	for (int i = 0; i < N; i++)
	{
		cin >> buf;
		barket.push_back(buf);
	}
	//int *flag = new int[N];
	for (int sz = 1; sz < N + 1; sz++)
	{
		answer+=part_function(barket, sz,S);
	}
	cout << answer;
	return 0;
}
int part_function(vector<int>& barket, int sz,int S)	//같은 수인경우 배열을 순회하는 방법을 통해서 해당 값의 위치를 찾기 힘듦
{
	int answer = 0,real_answer=0;
	vector<int> part_b;
	vector<int> number;
	int i = 0;
	while (1)
	{
		part_b.push_back(barket.at(i));
		number.push_back(i);
		if (part_b.size() == sz)
		{
			for (int l = 0; l < part_b.size(); l++)
				answer += part_b.at(l);
			if (answer == S)
				real_answer++;
			answer = 0;
			part_b.pop_back();
			number.pop_back();
			if (i == barket.size() - 1)
			{
				int k = 2;
				while (1)
				{
					if (part_b.size() == 0)
						return real_answer;
					if (barket.size() - k == number.at(number.size() - 1))
					{
						k++;
						part_b.pop_back();
						number.pop_back();
					}
					else
					{
						//for (int m = 0; m < barket.size(); m++)
						//{
							//if (part_b.at(part_b.size() - 1) == barket.at(m))
							//{
								i = number.at(number.size()-1);
								part_b.pop_back();
								number.pop_back();
								//break;
							//}
						//}
						break;
					}
				}
			
			}
		}	
		i++;
	}
}