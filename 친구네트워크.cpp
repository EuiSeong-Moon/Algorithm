#include <cstdio>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int friends[100001];
int find(int x);
void adding(int x, int y);
int main(void)
{
	cin.tie(0);	//cin의 입력 속도 늦어지는 것을 막아준다.
	int test_case;
	scanf("%d\n",&test_case);
	for (int test = 0; test < test_case; test++)
	{

		for (int i = 0; i < 100001; i++)
		{
			friends[i] = i;
		}
		int F;
		int n = 1;
		scanf("%d\n",&F);
		unordered_map<string, int> hashs;
		for (int i = 0; i < F; i++)
		{
			string str, str2;
			cin >> str >> str2;
			int number,number2;
			unordered_map<string, int>::const_iterator got = hashs.find(str);	//해시를 통해서 값을 추가하고 key는 string value는 유니온 파인드에 해당하는 인덱스다.
			if (got != hashs.end())
			{
				number = got->second;
			}
			else {
				pair<string, int> data(str, n);
				hashs.insert(data);
				number = n;
				n++;
			}
			got = hashs.find(str2);
			if (got != hashs.end())
			{
				number2 = got->second;
			}
			else {
				pair<string, int> data(str2, n);
				hashs.insert(data);
				number2 = n;
				n++;
			}
			adding(number, number2);
			int count = 0;
			int compare = friends[number];
			int compare2 = friends[number2];
			for (int k = 1; k <n; k++)
			{
				if (find(friends[k]) == compare || find(friends[k])==compare2)	//find를 취해줌으로써 정확한 유니온 파인드가 동작한다.
					count++;
			}
			printf("%d\n", count);
		}
	}
	return 0;
}
int find(int x)
{
	if (x == friends[x])
	{
		return x;
	}
	else
	{
		int y = find(friends[x]);
		friends[x] = y;
		return y;
	}
}
void adding(int x, int y)
{
	x = find(x);
	y = find(y);
	friends[y] = x;
}